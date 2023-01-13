
#include <math.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "lv2/lv2plug.in/ns/lv2core/lv2.h"
#include "lv2/lv2plug.in/ns/extensions/ui/ui.h"

#include <cairo.h>

#include "./gx_voxbass.h"
#include "gui/gx_gui.h"

/*---------------------------------------------------------------------
-----------------------------------------------------------------------	
		load png data from binary blob into cairo surface
-----------------------------------------------------------------------
----------------------------------------------------------------------*/

// png's linked in as binarys
EXTLD(pedal_png)
EXTLD(pswitch_on_png)
EXTLD(pswitch_off_png)
EXTLD(frame_png)

// read png data from binary blob
cairo_status_t png_stream_reader (void *_stream, unsigned char *data, unsigned int length) {
	binary_stream * stream = (binary_stream *) _stream;
	unsigned int i;
	for (i = 0; i < length; i++) {
		data[i] = stream->data[stream->position++];
	}
	return CAIRO_STATUS_SUCCESS;
}

cairo_surface_t *cairo_image_surface_create_from_stream (gx_voxbassUI* ui, const unsigned char* name) {
	ui->png_stream.data = name;
	ui->png_stream.position = 0;
	return cairo_image_surface_create_from_png_stream(&png_stream_reader, (void *)&ui->png_stream);
}

/*---------------------------------------------------------------------
-----------------------------------------------------------------------	
				XWindow init the LV2 handle
-----------------------------------------------------------------------
----------------------------------------------------------------------*/

// init the xwindow and return the LV2UI handle
static LV2UI_Handle instantiate(const LV2UI_Descriptor * descriptor,
			const char * plugin_uri, const char * bundle_path,
			LV2UI_Write_Function write_function,
			LV2UI_Controller controller, LV2UI_Widget * widget,
			const LV2_Feature * const * features) {

	gx_voxbassUI* ui = (gx_voxbassUI*)malloc(sizeof(gx_voxbassUI));

	if (!ui) {
		fprintf(stderr,"ERROR: failed to instantiate plugin with URI %s\n", plugin_uri);
		return NULL;
	}

	ui->parentWindow = 0;
	LV2UI_Resize* resize = NULL;

	for (int i = 0; features[i]; ++i) {
		if (!strcmp(features[i]->URI, LV2_UI__parent)) {
			ui->parentWindow = features[i]->data;
		} else if (!strcmp(features[i]->URI, LV2_UI__resize)) {
			resize = (LV2UI_Resize*)features[i]->data;
		}
	}

	if (ui->parentWindow == NULL)  {
		fprintf(stderr, "ERROR: Failed to open parentWindow for %s\n", plugin_uri);
		free(ui);
		return NULL;
	}

	if (!gx_gui_open_display(ui)) { // sets ui->dpy (only used by Linux)
		fprintf(stderr, "ERROR: Failed to open display for %s\n", plugin_uri);
		free(ui);
		return NULL;
	}

	ui->controls[0] = (gx_controller) {{ 0.5, 0.5, 0.0, 1.0, 0.01}, { 50, 60, 61, 61}, false,"VOLUME", KNOB, VOLUME};
	ui->controls[1] = (gx_controller) {{ 0.5, 0.5, 0.0, 1.0, 0.01}, { 120, 60, 61, 61}, false,"BASS", KNOB, BASS};
	ui->controls[2] = (gx_controller) {{ 0.5, 0.5, 0.0, 1.0, 0.01}, { 190, 60, 61, 61}, false,"MID", KNOB, MID};
	ui->controls[3] = (gx_controller) {{ 0.5, 0.5, 0.0, 1.0, 0.01}, { 260, 60, 61, 61}, false,"TREBLE", KNOB, TREBLE};
	ui->controls[4] = (gx_controller) {{ 0.0, 0.0, 0.0, 1.0, 1.0},  { 370, 60, 61, 61}, false,"CABINET", SWITCH, CAB};
	ui->controls[5] = (gx_controller) {{ 1.0, 1.0, 0.0, 1.0, 1.0},  { 550, 60, 61, 61}, false,"POWER", BSWITCH, BYPASS};
	ui->block_event = -1;


	ui->pedal = cairo_image_surface_create_from_stream(ui, LDVAR(pedal_png));
	ui->init_width = cairo_image_surface_get_width(ui->pedal);
	ui->height = ui->init_height = cairo_image_surface_get_height(ui->pedal);
	ui->width = ui->init_width -140 + (10 * CONTROLS);

	gx_gui_create_window_and_surface(ui); // sets ui->win and ui->surface
	ui->cr = cairo_create(ui->surface);

	ui->frame = cairo_image_surface_create (CAIRO_FORMAT_ARGB32, 61, 81);
	ui->crf = cairo_create (ui->frame);

	ui->pswitch_on = cairo_image_surface_create_from_stream(ui, LDVAR(pswitch_on_png));
	ui->pswitch_off = cairo_image_surface_create_from_stream(ui, LDVAR(pswitch_off_png));
	ui->frame1 = cairo_image_surface_create_from_stream(ui, LDVAR(frame_png));

	*widget = (void*)ui->win;

	if (resize){
		ui->resize = resize;
		resize->ui_resize(resize->handle, ui->width, ui->height);
	}

	ui->rescale.x  = (double)ui->width/ui->init_width;
	ui->rescale.y  = (double)ui->height/ui->init_height;
	ui->rescale.x1 = (double)ui->init_width/ui->width;
	ui->rescale.y1 = (double)ui->init_height/ui->height;
	ui->rescale.xc = (double)ui->width/(ui->init_width-140 + (10 * CONTROLS));
	ui->rescale.c = (ui->rescale.xc < ui->rescale.y) ? ui->rescale.xc : ui->rescale.y;
	ui->rescale.x2 =  ui->rescale.xc / ui->rescale.c;
	ui->rescale.y2 = ui->rescale.y / ui->rescale.c;

	gx_gui_register_controller_message(ui); // message for redrawing a controller (only used by Linux)

	ui->controller = controller;
	ui->write_function = write_function;
	resize_event(ui);

	return (LV2UI_Handle)ui;
}

// cleanup after usage
static void cleanup(LV2UI_Handle handle) {
	gx_voxbassUI* ui = (gx_voxbassUI*)handle;
	cairo_destroy(ui->cr);
	cairo_destroy(ui->crf);
	cairo_surface_destroy(ui->pedal);
	cairo_surface_destroy(ui->pswitch_on);
	cairo_surface_destroy(ui->pswitch_off);
	cairo_surface_destroy(ui->surface);
	cairo_surface_destroy(ui->frame);
	cairo_surface_destroy(ui->frame1);
	gx_gui_destroy_main_window(ui);
	free(ui);
}

/*---------------------------------------------------------------------
-----------------------------------------------------------------------	
				XWindow drawing expose handling
-----------------------------------------------------------------------
----------------------------------------------------------------------*/

// draw knobs and simple switches
static void knob_expose(gx_voxbassUI *ui,gx_controller* knob) {
	cairo_set_operator(ui->crf,CAIRO_OPERATOR_CLEAR);
	cairo_paint(ui->crf);
	cairo_set_operator(ui->crf,CAIRO_OPERATOR_OVER);
	static const double scale_zero = 20 * (M_PI/180); // defines "dead zone" for knobs
	int arc_offset = 0;
	int knob_x = 0;
	int knob_y = 0;
	int w = cairo_image_surface_get_width(ui->frame);
	int h = cairo_image_surface_get_height(ui->frame)-20;
	int grow = (w > h) ? h:w;
	if (knob->type == SWITCH) {
		knob_x = grow-20;
		knob_y = grow-20; 
	} else {
		knob_x = grow-1;
		knob_y = grow-1;
	}
	/** get values for the knob **/

	int knobx = (w - knob_x) * 0.5;
	int knobx1 = w* 0.5;

	int knoby = (h - knob_y) * 0.5;
	int knoby1 = h * 0.5;

	double knobstate = (knob->adj.value - knob->adj.min_value) / (knob->adj.max_value - knob->adj.min_value);
	double angle = scale_zero + knobstate * 2 * (M_PI - scale_zero);

	double pointer_off =knob_x/6;
	double radius = min(knob_x-pointer_off, knob_y-pointer_off) / 2;
	double lengh_x = (knobx+radius+pointer_off/2) - radius * sin(angle);
	double lengh_y = (knoby+radius+pointer_off/2) + radius * cos(angle);
	double radius_x = (knobx+radius+pointer_off/2) - radius/ 1.18 * sin(angle);
	double radius_y = (knoby+radius+pointer_off/2) + radius/ 1.18 * cos(angle);

	cairo_arc(ui->crf,knobx1+arc_offset, knoby1+arc_offset, knob_x/2.1, 0, 2 * M_PI );
	cairo_pattern_t*pat =
	cairo_pattern_create_radial (knobx1+arc_offset-knob_x/6,knoby1+arc_offset-knob_x/6, 1,knobx1+arc_offset,knoby1+arc_offset,knob_x/2.1 );
	cairo_pattern_add_color_stop_rgb (pat, 0.5, 0.15, 0.15, 0.15);
	cairo_pattern_add_color_stop_rgb (pat, 0.7, 0.2, 0.2, 0.2);
	cairo_pattern_add_color_stop_rgb (pat, 0.9, 0.1, 0.1,0.1);
	cairo_pattern_add_color_stop_rgb (pat, 1, 0.1, 0.1,0.1);

	cairo_set_source (ui->crf, pat);
	cairo_fill_preserve (ui->crf);
	cairo_set_source_rgb (ui->crf, 0., 0., 0.);
	cairo_set_line_width(ui->crf, 1.0);
	cairo_stroke(ui->crf);
	cairo_new_path (ui->crf);

	cairo_arc(ui->crf,knobx1+arc_offset, knoby1+arc_offset, knob_x/3.1, 0, 2 * M_PI );
	pat =
	cairo_pattern_create_radial (knobx1+arc_offset-knob_x/6,knoby1+arc_offset-knob_x/6, 1,knobx1+arc_offset,knoby1+arc_offset,knob_x/2.1 );
	if (knob->type == SWITCH) {
		if (knobstate) {
			cairo_pattern_add_color_stop_rgb (pat, 0, 0.2, 0.2, 0.2);
			cairo_pattern_add_color_stop_rgb (pat, 0.7, 0.3, 0.3, 0.3);
			cairo_pattern_add_color_stop_rgb (pat, 1, 0.2, 0.2,0.2);  
		} else {
			cairo_pattern_add_color_stop_rgb (pat, 0, 0.1, 0.1, 0.1);
			cairo_pattern_add_color_stop_rgb (pat, 0.7, 0.2, 0.2, 0.2);
			cairo_pattern_add_color_stop_rgb (pat, 1, 0.1, 0.1,0.1); 
		}
	} else {
		cairo_pattern_add_color_stop_rgb (pat, 0, 0.1, 0.1, 0.1);
		cairo_pattern_add_color_stop_rgb (pat, 0.7, 0.2, 0.2, 0.2);
		cairo_pattern_add_color_stop_rgb (pat, 1, 0.1, 0.1,0.1);
	}

	cairo_set_source (ui->crf, pat);
	cairo_fill_preserve (ui->crf);
	cairo_set_source_rgb (ui->crf, 0.1, 0.1, 0.1);
	cairo_set_line_width(ui->crf, 4.0);
	cairo_stroke_preserve(ui->crf);
	cairo_new_path (ui->crf);
	cairo_arc(ui->crf,knobx1+arc_offset, knoby1+arc_offset, knob_x/3.1, 0, 2 * M_PI );
	cairo_set_source_rgb (ui->crf, 0., 0., 0.);
	cairo_set_line_width(ui->crf, 1.0);
	cairo_stroke(ui->crf);
	cairo_new_path (ui->crf);

	/** create a rotating pointer on the kob**/
	cairo_set_line_cap(ui->crf, CAIRO_LINE_CAP_ROUND); 
	cairo_set_line_join(ui->crf, CAIRO_LINE_JOIN_BEVEL);
	cairo_move_to(ui->crf, radius_x, radius_y);
	cairo_line_to(ui->crf,lengh_x,lengh_y);
	cairo_set_line_width(ui->crf,min(5, max(2,knob_x/30)));
	cairo_set_source_rgb (ui->crf,0.63,0.63,0.63);
	cairo_stroke(ui->crf);
	cairo_new_path (ui->crf);

	cairo_text_extents_t extents;
	/** show value on the kob**/
	if (knob->type == KNOB && knob->is_active == true) {
		char s[64];
		const char* format[] = {"%.1f", "%.2f", "%.3f"};
		snprintf(s, 63, format[2-1], knob->adj.value);
		cairo_set_source_rgba (ui->crf, 0.6, 0.6, 0.6,0.6);
		cairo_set_font_size (ui->crf, 11.0);
		cairo_select_font_face (ui->crf, "Sans", CAIRO_FONT_SLANT_NORMAL,
								   CAIRO_FONT_WEIGHT_BOLD);
		cairo_text_extents(ui->crf, "0.00", &extents);
		cairo_move_to (ui->crf, knobx1-extents.width/2, knoby1+extents.height/2);
		cairo_show_text(ui->crf, s);
		cairo_new_path (ui->crf);
	} else if (knob->type == SWITCH) {
		cairo_set_source_rgba (ui->crf, 0.6, 0.6, 0.6,0.6);
		cairo_text_extents(ui->crf,"Off", &extents);
		cairo_move_to (ui->crf, knobx1-knob_x/2.4-extents.width/1.6, knoby1+knob_y/2+extents.height/1.4);
		cairo_show_text(ui->crf, "Off");
		cairo_new_path (ui->crf);

		cairo_text_extents(ui->crf,"On", &extents);
		cairo_move_to (ui->crf, knobx1+knob_x/2.6-extents.width/2.3, knoby1+knob_y/2+extents.height/1.4);
		cairo_show_text(ui->crf, "On");
		cairo_new_path (ui->crf);
	}
	cairo_pattern_destroy (pat);

	/** show label below the knob**/
	if (knob->is_active == true) {
		cairo_set_source_rgba (ui->crf, 0.8, 0.8, 0.8,0.8);
	} else {
		cairo_set_source_rgba (ui->crf, 0.6, 0.6, 0.6,0.6);
	}
	cairo_set_font_size (ui->crf, 12.0);
	cairo_select_font_face (ui->crf, "Sans", CAIRO_FONT_SLANT_NORMAL,
							   CAIRO_FONT_WEIGHT_BOLD);
	cairo_text_extents(ui->crf,knob->label , &extents);

	cairo_move_to (ui->crf, knobx1-extents.width/2, grow+6+extents.height);
	cairo_show_text(ui->crf, knob->label);
	cairo_new_path (ui->crf);
}

// draw the power switch (bypass)
static void bypass_expose(gx_voxbassUI *ui, gx_controller* switch_) {
	cairo_set_operator(ui->crf,CAIRO_OPERATOR_CLEAR);
	cairo_paint(ui->crf);
	cairo_set_operator(ui->crf,CAIRO_OPERATOR_OVER);
	if(switch_->adj.value > 0.9)
		cairo_set_source_surface (ui->crf, ui->pswitch_on, 0, 0);
	else
		cairo_set_source_surface (ui->crf, ui->pswitch_off, 0, 0);
	cairo_paint (ui->crf);
	/** show label below the switch**/
	cairo_text_extents_t extents;
	if (switch_->is_active == true) {
		cairo_set_source_rgba (ui->crf, 0.8, 0.8, 0.8,0.8);
	} else {
		cairo_set_source_rgba (ui->crf, 0.6, 0.6, 0.6,0.6);
	}
	cairo_set_font_size (ui->crf, 12.0);
	cairo_select_font_face (ui->crf, "Sans", CAIRO_FONT_SLANT_NORMAL,
							   CAIRO_FONT_WEIGHT_BOLD);
	cairo_text_extents(ui->crf,switch_->label , &extents);

	cairo_move_to (ui->crf, 30.0-extents.width/2, 67.0+extents.height);
	cairo_show_text(ui->crf, switch_->label);
	cairo_new_path (ui->crf);
}

// select draw methode by controller type
static void draw_controller(gx_voxbassUI *ui, gx_controller* controller) {
	if (controller->type == KNOB) knob_expose(ui, controller);
	else if (controller->type == SWITCH) knob_expose(ui, controller);
	else if (controller->type == BSWITCH) bypass_expose(ui, controller);
}

// general expose callback, 
void _expose(gx_voxbassUI *ui) {
	static const char* plug_name = "GxVBass";
	static const char* plug_name2 = "PreAmp" ;
	cairo_push_group (ui->cr);

	cairo_scale (ui->cr, ui->rescale.x, ui->rescale.y);

	cairo_set_source_surface (ui->cr, ui->pedal, 0, 0);
	cairo_paint (ui->cr);

	cairo_text_extents_t extents;
	cairo_set_source_rgba (ui->cr, 0.6, 0.6, 0.6,0.6);
	cairo_set_font_size (ui->cr, 14.0);
	cairo_select_font_face (ui->cr, "Sans", CAIRO_FONT_SLANT_NORMAL,
							   CAIRO_FONT_WEIGHT_BOLD);
	cairo_text_extents(ui->cr, plug_name, &extents);
	cairo_move_to (ui->cr, ((double)(550)-(extents.width)/2.0),
	  (double)(80)-extents.height);
	cairo_show_text(ui->cr, plug_name);
	cairo_move_to (ui->cr, ((double)(550)-(extents.width)/2.0),
	  (double)(100)-extents.height);
	cairo_show_text(ui->cr, plug_name2);

	cairo_scale (ui->cr, 3.5, 3.0);
	cairo_set_source_surface (ui->cr, ui->frame1, 10, 12);
	cairo_paint (ui->cr);
	cairo_scale (ui->cr, 1/3.5, 1/3.0);
	cairo_scale (ui->cr, 0.95, 3.0);
	cairo_set_source_surface (ui->cr, ui->frame1, 420, 12);
	cairo_paint (ui->cr);
	cairo_set_source_surface (ui->cr, ui->frame1, 530, 12);
	cairo_paint (ui->cr);
	cairo_set_source_surface (ui->cr, ui->frame1, 640, 12);
	cairo_paint (ui->cr);
	cairo_scale (ui->cr, 1/0.95, 1/3.0);


	cairo_scale (ui->cr, ui->rescale.x1, ui->rescale.y1);
	cairo_scale (ui->cr, ui->rescale.c, ui->rescale.c);

	for (int i=0;i<CONTROLS;i++) {
		draw_controller(ui, &ui->controls[i]);
		cairo_set_source_surface (ui->cr, ui->frame, 
		  (double)ui->controls[i].al.x * ui->rescale.x2,
		  (double)ui->controls[i].al.y * ui->rescale.y2);
		cairo_paint (ui->cr);
	}

	cairo_pop_group_to_source (ui->cr);
	cairo_paint (ui->cr);
}

// redraw a single controllermemset(&m, sizeof(m), 0);
void controller_expose(gx_voxbassUI *ui, gx_controller * control) {
	cairo_push_group (ui->cr);
	cairo_scale (ui->cr, ui->rescale.x, ui->rescale.y);

	cairo_set_source_surface (ui->cr, ui->pedal, 0, 0);
	//cairo_scale (ui->cr, 1.95, 3.0);
	//cairo_set_source_surface (ui->cr, ui->frame1, 10, 12);
	
	//cairo_scale (ui->cr, 1/1.95, 1/3.0);

	cairo_scale (ui->cr, ui->rescale.x1, ui->rescale.y1);
	cairo_scale (ui->cr, ui->rescale.c, ui->rescale.c);
	cairo_rectangle (ui->cr,(double)control->al.x * ui->rescale.x2,
	  (double)control->al.y * ui->rescale.y2,
	  (double)control->al.width, (double)control->al.height+20.0);
	cairo_fill(ui->cr);
	cairo_stroke(ui->cr);

	draw_controller(ui, control);
	cairo_set_source_surface (ui->cr, ui->frame, 
	  (double)control->al.x * ui->rescale.x2,
	  (double)control->al.y * ui->rescale.y2);
	cairo_paint (ui->cr);

	cairo_pop_group_to_source (ui->cr);
	cairo_paint (ui->cr);
}

/*---------------------------------------------------------------------
-----------------------------------------------------------------------	
				XWindow event handling
-----------------------------------------------------------------------
----------------------------------------------------------------------*/

// send event when active controller changed
static void send_controller_event(gx_voxbassUI *ui, int controller) {
	gx_gui_send_controller_event(ui, controller);
}

static void check_value_changed(gx_voxbassUI *ui, int i, float* value) {
	if(fabs(*(value) - ui->controls[i].adj.value)>=0.00001) {
		ui->controls[i].adj.value = *(value);
		if (ui->block_event != ui->controls[i].port)
			ui->write_function(ui->controller,ui->controls[i].port,sizeof(float),0,value);
		send_controller_event(ui, i);
	}
}

static void check_is_active(gx_voxbassUI *ui, int i, bool set) {
	if (ui->controls[i].is_active != set) {
		ui->controls[i].is_active = set;
		send_controller_event(ui, i);
	}
}

// check which controller is active
bool aligned(int x, int y, gx_controller *control, gx_voxbassUI *ui) {
	double ax = (control->al.x * ui->rescale.x2)* ui->rescale.c;
	double ay = (control->al.y  * ui->rescale.y2)* ui->rescale.c;
	double aw = ax + (control->al.width * ui->rescale.c);
	double ah = ay + (control->al.height * ui->rescale.c);
	return ((x >= ax ) && (x <= aw)
	  && (y >= ay ) && (y <= ah)) ? true : false;
}

// recive port changes from host
static void port_event(LV2UI_Handle handle, uint32_t port_index,
						uint32_t buffer_size, uint32_t format,
						const void * buffer) {
	gx_voxbassUI* ui = (gx_voxbassUI*)handle;
	float value = *(float*)buffer;
	for (int i=0;i<CONTROLS;i++) {
		if (port_index == ui->controls[i].port) {
			ui->block_event = (int)port_index;
			check_value_changed(ui, i, &value);
			ui->block_event = -1;
		}
	}
}

// resize the xwindow and the cairo xlib surface
void resize_event(gx_voxbassUI *ui) {
	gx_gui_resize_surface(ui);
	ui->rescale.x  = (double)ui->width/ui->init_width;
	ui->rescale.y  = (double)ui->height/ui->init_height;
	ui->rescale.x1 = (double)ui->init_width/ui->width;
	ui->rescale.y1 = (double)ui->init_height/ui->height;
	ui->rescale.xc = (double)ui->width/(ui->init_width-140 + (10 * CONTROLS));
	ui->rescale.c = (ui->rescale.xc < ui->rescale.y) ? ui->rescale.xc : ui->rescale.y;
	ui->rescale.x2 =  ui->rescale.xc / ui->rescale.c;
	ui->rescale.y2 = ui->rescale.y / ui->rescale.c;
}

// mouse wheel scroll event
void scroll_event(gx_voxbassUI *ui, int direction) {
	float value;
	for (int i=0;i<CONTROLS;i++) {
		if (aligned(ui->pos_x, ui->pos_y, &ui->controls[i], ui)) {
			value = min(ui->controls[i].adj.max_value,max(ui->controls[i].adj.min_value, 
			  ui->controls[i].adj.value + (ui->controls[i].adj.step * direction)));
			check_is_active(ui, i, true);
			check_value_changed(ui, i, &value);
		} else {
			check_is_active(ui, i, false);
		}
	}
}

// controll is switch, so switch value
static void switch_event(gx_voxbassUI *ui, int i) {
	float value = ui->controls[i].adj.value ? 0.0 : 1.0;
	check_value_changed(ui, i, &value);
}

// left mouse button is pressed, generate a switch event, or set controller active
void button1_event(gx_voxbassUI *ui, double* start_value) {
	for (int i=0;i<CONTROLS;i++) {
		if (aligned(ui->pos_x, ui->pos_y, &ui->controls[i], ui)) {
			if (ui->controls[i].type == BSWITCH ||ui->controls[i].type == SWITCH) {
				switch_event(ui, i);
				check_is_active(ui, i, true);
			} else {
				check_is_active(ui, i, true);
				*(start_value) = ui->controls[i].adj.value;
			}
		} else {
			check_is_active(ui, i, false);
		}
	}
}

// set min std or max value, depending on which key is pressed
void set_key_value(gx_voxbassUI *ui, int set_value) {
	float value = 0.0;
	for (int i=0;i<CONTROLS;i++) {
		if (ui->controls[i].is_active) {
			if (set_value == 1) value = ui->controls[i].adj.min_value;
			else if (set_value == 2) value = ui->controls[i].adj.std_value;
			else if (set_value == 3) value = ui->controls[i].adj.max_value;
			check_value_changed(ui, i, &value);
		}
	}
}

// scroll up/down on key's up/right down/left
void key_event(gx_voxbassUI *ui, int direction) {
	float value;
	for (int i=0;i<CONTROLS;i++) {
		if (ui->controls[i].is_active) {
			value = min(ui->controls[i].adj.max_value,max(ui->controls[i].adj.min_value, 
			  ui->controls[i].adj.value + (ui->controls[i].adj.step * direction)));
			check_value_changed(ui, i, &value);
		}
	}
}

// set previous controller active on shift+tab key's
void set_previous_controller_active(gx_voxbassUI *ui) {
	for (int i=0;i<CONTROLS;i++) {
		if(ui->controls[i].is_active == true) {
			ui->controls[i].is_active = false;
			send_controller_event(ui, i);
			if(i>0) {
				if (ui->controls[i-1].is_active != true) {
					ui->controls[i-1].is_active = true;
					send_controller_event(ui, i-1);
				}
				return;
			} else {
				if (ui->controls[CONTROLS-1].is_active != true) {
					ui->controls[CONTROLS-1].is_active = true;
					send_controller_event(ui, CONTROLS-1);
				}
				return;
			}
		}
	}
	check_is_active(ui, CONTROLS-1, true);
}

// set next controller active on tab key
void set_next_controller_active(gx_voxbassUI *ui) {
	for (int i=0;i<CONTROLS;i++) {
		if(ui->controls[i].is_active == true) {
			ui->controls[i].is_active = false;
			send_controller_event(ui, i);
			if(i<CONTROLS-1) {
				
				if (ui->controls[i+1].is_active != true) {
					ui->controls[i+1].is_active = true;
					send_controller_event(ui, i+1);
				}
				return;
			} else {
				if (ui->controls[0].is_active != true) {
					ui->controls[0].is_active = true;
					send_controller_event(ui, 0);
				}
				return;
			}
		}
	}
	check_is_active(ui, 0, true);
}

// get/set active controller on enter and leave notify
void get_last_active_controller(gx_voxbassUI *ui, bool set) {
	static gx_controller *sc = NULL;
	static int s = 0;
	for (int i=0;i<CONTROLS;i++) {
		if(ui->controls[i].is_active == true) {
			sc = &ui->controls[i];
			s = i;
			ui->controls[i].is_active = set;
			send_controller_event(ui, i);
			return;
		} else if (!set) {
			sc =  NULL;
		}
	}
	if (sc != NULL) {
		sc->is_active = true;
		send_controller_event(ui, s);
	}
}

// mouse move while left button is pressed
void motion_event(gx_voxbassUI *ui, double start_value, int m_y) {
	static const double scaling = 0.5;
	float value = 0.0;
	for (int i=0;i<CONTROLS;i++) {
		if (ui->controls[i].is_active && ui->controls[i].type != BSWITCH && ui->controls[i].type != SWITCH) {
			value = min(ui->controls[i].adj.max_value,max(ui->controls[i].adj.min_value,start_value + 
			  (((double)(ui->pos_y - m_y)*scaling*ui->controls[i].adj.step)*
			  (ui->controls[i].adj.max_value-ui->controls[i].adj.min_value))));
			check_value_changed(ui, i, &value);
		}
	}
	
}

/*---------------------------------------------------------------------
-----------------------------------------------------------------------	
						LV2 interface
-----------------------------------------------------------------------
----------------------------------------------------------------------*/

static int ui_idle(LV2UI_Handle handle) {
	gx_voxbassUI* ui = (gx_voxbassUI*)handle;
	event_handler(ui);
	return 0;
}

static int ui_resize(LV2UI_Feature_Handle handle, int w, int h) {
	gx_voxbassUI* ui = (gx_voxbassUI*)handle;
	if (ui) resize_event(ui);
	return 0;
}

static const void* extension_data(const char* uri) {
	static const LV2UI_Idle_Interface idle = { ui_idle };
	static const LV2UI_Resize resize = { 0 ,ui_resize };
	if (!strcmp(uri, LV2_UI__idleInterface)) {
		return &idle;
	}
	if (!strcmp(uri, LV2_UI__resize)) {
		return &resize;
	}
	return NULL;
}

static const LV2UI_Descriptor descriptor = {
	GXPLUGIN_UI_URI,
	instantiate,
	cleanup,
	port_event,
	extension_data
};

LV2_SYMBOL_EXPORT
const LV2UI_Descriptor* lv2ui_descriptor(uint32_t index) {
	switch (index) {
		case 0:
			return &descriptor;
		default:
		return NULL;
	}
}

