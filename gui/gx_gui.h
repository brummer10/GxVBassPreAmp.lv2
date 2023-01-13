// vim:ts=4:sw=4:noet:
#ifndef __GX_GUI_H__
#define __GX_GUI_H__ 1

#include "gui/gx_platform.h"
#include "./gx_voxbass.h"

/*---------------------------------------------------------------------
-----------------------------------------------------------------------	
				define controller numbers
-----------------------------------------------------------------------
----------------------------------------------------------------------*/

#define CONTROLS 6

/*---------------------------------------------------------------------
-----------------------------------------------------------------------	
				define min/max if not defined already
-----------------------------------------------------------------------
----------------------------------------------------------------------*/

#ifndef min
#define min(x, y) ((x) < (y) ? (x) : (y))
#endif
#ifndef max
#define max(x, y) ((x) < (y) ? (y) : (x))
#endif

/*---------------------------------------------------------------------
-----------------------------------------------------------------------	
					define needed structs
-----------------------------------------------------------------------
----------------------------------------------------------------------*/

// struct definition to read binary data into cairo surface 
typedef struct  {
	const unsigned char * data;
	long int position;
} binary_stream;

// define controller type
typedef enum {
	KNOB,
	SWITCH,
	BSWITCH,
	ENUM,
} ctype;

// define controller position in window
typedef struct {
	int x;
	int y;
	int width;
	int height;
} gx_alinment;

// define controller adjustment
typedef struct {
	float std_value;
	float value;
	float min_value;
	float max_value;
	float step;
} gx_adjustment;

// controller struct
typedef struct {
	gx_adjustment adj;
	gx_alinment al;
	bool is_active;
	const char* label;
	ctype type;
	PortIndex port;
} gx_controller;

// resize window
typedef struct {
	double x;
	double y;
	double x1;
	double y1;
	double x2;
	double y2;
	double c;
	double xc;
} gx_scale;

/*---------------------------------------------------------------------
-----------------------------------------------------------------------	
				the main LV2 handle->XWindow
-----------------------------------------------------------------------
----------------------------------------------------------------------*/

// main window struct
typedef struct {
	platform_ui_members // platform specific; see gx_Platform.h

	int width;
	int height;
	int init_width;
	int init_height;
	int pos_x;
	int pos_y;

	binary_stream png_stream;
	cairo_surface_t *pedal;
	cairo_surface_t *pswitch_on;
	cairo_surface_t *pswitch_off;
	cairo_surface_t *frame;
	cairo_surface_t *frame1;
	cairo_t *crf;
	cairo_t *cr;
	cairo_surface_t *surface;

	gx_controller controls[CONTROLS];
	int block_event;
	gx_scale rescale;

	void *controller;
	LV2UI_Write_Function write_function;
	LV2UI_Resize* resize;
} gx_voxbassUI;

// forward declarations (internal)
void resize_event(gx_voxbassUI *ui);
void event_handler(gx_voxbassUI *ui);
void _expose(gx_voxbassUI *ui);
void controller_expose(gx_voxbassUI *ui, gx_controller * control);
void button1_event(gx_voxbassUI *ui, double* start_value);
void scroll_event(gx_voxbassUI *ui, int direction);
void set_previous_controller_active(gx_voxbassUI *ui);
void set_next_controller_active(gx_voxbassUI *ui);
void key_event(gx_voxbassUI *ui, int direction);
void set_key_value(gx_voxbassUI *ui, int set_value);
void get_last_active_controller(gx_voxbassUI *ui, bool set);
void motion_event(gx_voxbassUI *ui, double start_value, int m_y);

/*---------------------------------------------------------------------
-----------------------------------------------------------------------
			forward declaration of compatibility functions
			(have to be implemented in gx_platform_*.c)
-----------------------------------------------------------------------
----------------------------------------------------------------------*/

bool gx_gui_open_display(gx_voxbassUI *ui);
void gx_gui_create_window_and_surface(gx_voxbassUI *ui);
void gx_gui_register_controller_message(gx_voxbassUI *ui);
void gx_gui_destroy_main_window(gx_voxbassUI *ui);
void gx_gui_resize_surface(gx_voxbassUI *ui);
void gx_gui_send_controller_event(gx_voxbassUI *ui, int controller);

#endif /* __GX_GUI_H__ */
