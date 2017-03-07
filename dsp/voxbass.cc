// generated from file './/voxbass.dsp' by dsp2cc:
// Code generated with Faust 0.9.73 (http://faust.grame.fr)


#include "zita-resampler/resampler.h"

namespace voxbass {

class SimpleResampler {
 private:
    Resampler r_up, r_down;
    int m_fact;
 public:
    SimpleResampler(): r_up(), r_down(), m_fact() {}
    void setup(int sampleRate, unsigned int fact);
    void up(int count, float *input, float *output);
    void down(int count, float *input, float *output);
};

void SimpleResampler::setup(int sampleRate, unsigned int fact)
{
	m_fact = fact;
	const int qual = 16; // resulting in a total delay of 2*qual (0.7ms @44100)
	// upsampler
	r_up.setup(sampleRate, sampleRate*fact, 1, qual);
	// k == inpsize() == 2 * qual
	// pre-fill with k-1 zeros
	r_up.inp_count = r_up.inpsize() - 1;
	r_up.out_count = 1;
	r_up.inp_data = r_up.out_data = 0;
	r_up.process();
	// downsampler
	r_down.setup(sampleRate*fact, sampleRate, 1, qual);
	// k == inpsize() == 2 * qual * fact
	// pre-fill with k-1 zeros
	r_down.inp_count = r_down.inpsize() - 1;
	r_down.out_count = 1;
	r_down.inp_data = r_down.out_data = 0;
	r_down.process();
}

void SimpleResampler::up(int count, float *input, float *output)
{
	r_up.inp_count = count;
	r_up.inp_data = input;
	r_up.out_count = count * m_fact;
	r_up.out_data = output;
	r_up.process();
	assert(r_up.inp_count == 0);
	assert(r_up.out_count == 0);
}

void SimpleResampler::down(int count, float *input, float *output)
{
	r_down.inp_count = count * m_fact;
	r_down.inp_data = input;
	r_down.out_count = count+1; // +1 == trick to drain input
	r_down.out_data = output;
	r_down.process();
	assert(r_down.inp_count == 0);
	assert(r_down.out_count == 1);
}


class Dsp: public PluginLV2 {
private:
	uint32_t fSamplingFreq;
	int 	iConst0;
	double 	fConst1;
	double 	fConst2;
	double 	fConst3;
	double 	fConst4;
	double 	fConst5;
	double 	fConst6;
	double 	fConst7;
	double 	fConst8;
	double 	fConst9;
	FAUSTFLOAT 	fslider0;
	FAUSTFLOAT	*fslider0_;
	double 	fRec0[2];
	double 	fConst10;
	FAUSTFLOAT 	fslider1;
	FAUSTFLOAT	*fslider1_;
	double 	fRec1[2];
	double 	fConst11;
	double 	fConst12;
	double 	fConst13;
	double 	fConst14;
	double 	fConst15;
	double 	fConst16;
	double 	fConst17;
	double 	fConst18;
	double 	fConst19;
	double 	fConst20;
	double 	fConst21;
	double 	fConst22;
	double 	fConst23;
	double 	fConst24;
	double 	fConst25;
	double 	fConst26;
	double 	fConst27;
	double 	fConst28;
	double 	fConst29;
	double 	fConst30;
	double 	fConst31;
	double 	fConst32;
	double 	fConst33;
	double 	fConst34;
	double 	fConst35;
	double 	fConst36;
	double 	fConst37;
	double 	fConst38;
	double 	fConst39;
	double 	fConst40;
	double 	fConst41;
	double 	fConst42;
	double 	fConst43;
	double 	fConst44;
	double 	fConst45;
	double 	fConst46;
	double 	fConst47;
	double 	fConst48;
	double 	fConst49;
	double 	fConst50;
	double 	fConst51;
	double 	fConst52;
	double 	fConst53;
	double 	fConst54;
	double 	fConst55;
	double 	fConst56;
	double 	fConst57;
	double 	fConst58;
	double 	fConst59;
	double 	fConst60;
	double 	fConst61;
	double 	fConst62;
	double 	fConst63;
	double 	fConst64;
	double 	fConst65;
	double 	fConst66;
	double 	fConst67;
	double 	fConst68;
	double 	fConst69;
	double 	fConst70;
	double 	fConst71;
	double 	fConst72;
	double 	fConst73;
	double 	fConst74;
	double 	fConst75;
	double 	fConst76;
	double 	fConst77;
	double 	fConst78;
	double 	fConst79;
	double 	fConst80;
	double 	fConst81;
	double 	fConst82;
	double 	fConst83;
	double 	fConst84;
	double 	fConst85;
	double 	fConst86;
	double 	fConst87;
	double 	fConst88;
	double 	fConst89;
	double 	fConst90;
	double 	fConst91;
	double 	fConst92;
	double 	fConst93;
	double 	fConst94;
	double 	fConst95;
	double 	fConst96;
	double 	fConst97;
	double 	fConst98;
	double 	fConst99;
	double 	fConst100;
	double 	fConst101;
	double 	fConst102;
	double 	fConst103;
	double 	fConst104;
	double 	fConst105;
	double 	fConst106;
	double 	fConst107;
	FAUSTFLOAT 	fslider2;
	FAUSTFLOAT	*fslider2_;
	double 	fRec6[2];
	double 	fConst108;
	double 	fConst109;
	double 	fConst110;
	double 	fConst111;
	double 	fConst112;
	double 	fConst113;
	double 	fConst114;
	double 	fConst115;
	double 	fConst116;
	double 	fConst117;
	FAUSTFLOAT 	fslider3;
	FAUSTFLOAT	*fslider3_;
	double 	fRec7[2];
	double 	fConst118;
	double 	fConst119;
	double 	fConst120;
	double 	fConst121;
	double 	fConst122;
	double 	fConst123;
	double 	fConst124;
	double 	fConst125;
	double 	fConst126;
	double 	fConst127;
	double 	fConst128;
	double 	fConst129;
	double 	fConst130;
	double 	fConst131;
	double 	fConst132;
	double 	fConst133;
	double 	fConst134;
	double 	fConst135;
	double 	fConst136;
	double 	fConst137;
	double 	fConst138;
	double 	fConst139;
	double 	fConst140;
	double 	fConst141;
	double 	fConst142;
	double 	fConst143;
	double 	fConst144;
	double 	fConst145;
	double 	fConst146;
	double 	fConst147;
	double 	fConst148;
	double 	fConst149;
	double 	fConst150;
	double 	fConst151;
	double 	fConst152;
	double 	fConst153;
	double 	fConst154;
	double 	fConst155;
	double 	fConst156;
	double 	fConst157;
	double 	fConst158;
	double 	fConst159;
	double 	fConst160;
	double 	fConst161;
	double 	fConst162;
	double 	fConst163;
	double 	fConst164;
	double 	fConst165;
	double 	fConst166;
	double 	fConst167;
	double 	fConst168;
	double 	fConst169;
	double 	fConst170;
	double 	fConst171;
	double 	fConst172;
	double 	fConst173;
	double 	fConst174;
	double 	fConst175;
	double 	fConst176;
	double 	fConst177;
	double 	fConst178;
	double 	fConst179;
	double 	fConst180;
	double 	fConst181;
	double 	fConst182;
	double 	fConst183;
	double 	fConst184;
	double 	fConst185;
	double 	fConst186;
	double 	fConst187;
	double 	fConst188;
	double 	fConst189;
	double 	fConst190;
	double 	fConst191;
	double 	fConst192;
	double 	fConst193;
	double 	fConst194;
	double 	fConst195;
	double 	fConst196;
	double 	fConst197;
	double 	fVec0[2];
	double 	fConst198;
	double 	fRec9[2];
	double 	fRec8[9];
	double 	fConst199;
	double 	fConst200;
	double 	fConst201;
	double 	fConst202;
	double 	fConst203;
	double 	fConst204;
	double 	fConst205;
	double 	fConst206;
	double 	fConst207;
	double 	fConst208;
	double 	fConst209;
	double 	fConst210;
	double 	fConst211;
	double 	fConst212;
	double 	fConst213;
	double 	fConst214;
	double 	fConst215;
	double 	fConst216;
	double 	fConst217;
	double 	fConst218;
	double 	fConst219;
	double 	fConst220;
	double 	fConst221;
	double 	fConst222;
	double 	fConst223;
	double 	fConst224;
	double 	fConst225;
	double 	fConst226;
	double 	fConst227;
	double 	fConst228;
	double 	fConst229;
	double 	fConst230;
	double 	fConst231;
	double 	fConst232;
	double 	fConst233;
	double 	fConst234;
	double 	fConst235;
	double 	fConst236;
	double 	fConst237;
	double 	fConst238;
	double 	fConst239;
	double 	fConst240;
	double 	fConst241;
	double 	fConst242;
	double 	fConst243;
	double 	fConst244;
	double 	fConst245;
	double 	fConst246;
	double 	fConst247;
	double 	fConst248;
	double 	fConst249;
	double 	fConst250;
	double 	fConst251;
	double 	fConst252;
	double 	fConst253;
	double 	fConst254;
	double 	fConst255;
	double 	fConst256;
	double 	fConst257;
	double 	fConst258;
	double 	fConst259;
	double 	fConst260;
	double 	fConst261;
	double 	fConst262;
	double 	fConst263;
	double 	fConst264;
	double 	fConst265;
	double 	fConst266;
	double 	fConst267;
	double 	fConst268;
	double 	fConst269;
	double 	fConst270;
	double 	fVec1[2];
	double 	fRec5[2];
	double 	fRec4[3];
	double 	fConst271;
	double 	fConst272;
	double 	fConst273;
	double 	fConst274;
	double 	fVec2[2];
	double 	fRec3[2];
	double 	fRec2[7];
	double 	fConst275;
	double 	fConst276;
	double 	fConst277;
	double 	fConst278;
	double 	fConst279;
	double 	fConst280;
	double 	fConst281;
	double 	fConst282;
	double 	fConst283;
	double 	fConst284;
	double 	fConst285;
	double 	fConst286;
	double 	fConst287;
	double 	fConst288;
	double 	fConst289;
	double 	fConst290;
	double 	fConst291;
	double 	fConst292;
	double 	fConst293;
	double 	fConst294;
	double 	fConst295;
	double 	fConst296;
	double 	fConst297;
	double 	fConst298;
	double 	fConst299;
	double 	fConst300;
	double 	fConst301;
	double 	fConst302;
	double 	fConst303;
	double 	fConst304;
	double 	fConst305;
	double 	fConst306;
	double 	fConst307;
	double 	fConst308;
	double 	fConst309;
	double 	fConst310;
	double 	fConst311;
	double 	fConst312;
	double 	fConst313;
	double 	fConst314;
	double 	fConst315;
	double 	fConst316;
	double 	fConst317;
	double 	fConst318;
	double 	fConst319;
	double 	fConst320;
	double 	fConst321;
	double 	fConst322;
	double 	fConst323;
	double 	fConst324;
	double 	fConst325;
	double 	fConst326;
	double 	fConst327;
	double 	fConst328;
	double 	fConst329;
	double 	fConst330;
	double 	fConst331;
	double 	fConst332;
	double 	fConst333;
	double 	fConst334;
	double 	fConst335;
	double 	fConst336;
	double 	fConst337;
	double 	fConst338;
	double 	fConst339;
	double 	fConst340;
	double 	fConst341;
	double 	fConst342;
	double 	fConst343;
	double 	fVec3[2];
	double 	fConst344;
	double 	fConst345;
	double 	fConst346;
	double 	fConst347;
	double 	fConst348;
	double 	fConst349;
	double 	fConst350;
	double 	fConst351;
	double 	fConst352;
	double 	fConst353;
	double 	fConst354;
	double 	fConst355;
	double 	fConst356;
	double 	fConst357;
	double 	fConst358;
	double 	fConst359;
	double 	fConst360;
	double 	fConst361;
	double 	fConst362;
	double 	fConst363;
	double 	fRec13[2];
	double 	fRec12[3];
	double 	fConst364;
	double 	fConst365;
	double 	fVec4[2];
	double 	fRec11[2];
	double 	fRec10[10];
	double 	fConst366;
	double 	fConst367;
	double 	fConst368;
	double 	fConst369;
	double 	fConst370;
	double 	fConst371;
	double 	fConst372;
	double 	fConst373;
	double 	fConst374;
	double 	fConst375;
	double 	fConst376;
	double 	fConst377;
	double 	fConst378;
	double 	fConst379;
	double 	fConst380;
	double 	fConst381;
	FAUSTFLOAT 	fslider4;
	FAUSTFLOAT	*fslider4_;
	SimpleResampler smp;
	unsigned int sru;
	unsigned int fact;
	void connect(uint32_t port,void* data);
	void clear_state_f();
	void init(uint32_t samplingFreq);
	void compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0);

	static void clear_state_f_static(PluginLV2*);
	static void init_static(uint32_t samplingFreq, PluginLV2*);
	static void compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0, PluginLV2*);
	static void del_instance(PluginLV2 *p);
	static void connect_static(uint32_t port,void* data, PluginLV2 *p);
public:
	Dsp();
	~Dsp();
};



Dsp::Dsp()
	: PluginLV2() {
	version = PLUGINLV2_VERSION;
	id = "voxbass";
	name = N_("VoxBass100");
	mono_audio = compute_static;
	stereo_audio = 0;
	set_samplerate = init_static;
	activate_plugin = 0;
	connect_ports = connect_static;
	clear_state = clear_state_f_static;
	delete_instance = del_instance;
}

Dsp::~Dsp() {
}

inline void Dsp::clear_state_f()
{
	for (int i=0; i<2; i++) fRec0[i] = 0;
	for (int i=0; i<2; i++) fRec1[i] = 0;
	for (int i=0; i<2; i++) fRec6[i] = 0;
	for (int i=0; i<2; i++) fRec7[i] = 0;
	for (int i=0; i<2; i++) fVec0[i] = 0;
	for (int i=0; i<2; i++) fRec9[i] = 0;
	for (int i=0; i<9; i++) fRec8[i] = 0;
	for (int i=0; i<2; i++) fVec1[i] = 0;
	for (int i=0; i<2; i++) fRec5[i] = 0;
	for (int i=0; i<3; i++) fRec4[i] = 0;
	for (int i=0; i<2; i++) fVec2[i] = 0;
	for (int i=0; i<2; i++) fRec3[i] = 0;
	for (int i=0; i<7; i++) fRec2[i] = 0;
	for (int i=0; i<2; i++) fVec3[i] = 0;
	for (int i=0; i<2; i++) fRec13[i] = 0;
	for (int i=0; i<3; i++) fRec12[i] = 0;
	for (int i=0; i<2; i++) fVec4[i] = 0;
	for (int i=0; i<2; i++) fRec11[i] = 0;
	for (int i=0; i<10; i++) fRec10[i] = 0;
}

void Dsp::clear_state_f_static(PluginLV2 *p)
{
	static_cast<Dsp*>(p)->clear_state_f();
}

inline void Dsp::init(uint32_t samplingFreq)
{
	fSamplingFreq = samplingFreq;
	fact = fSamplingFreq/48000;
	if (fact>1) {
		smp.setup(fSamplingFreq, fact);
		fSamplingFreq = 48000;
	}
	iConst0 = min(192000, max(1, fSamplingFreq));
	fConst1 = double(iConst0);
	fConst2 = (4.13654174012593e-30 * fConst1);
	fConst3 = (4.25671964279894e-15 + (fConst1 * (1.62143829384899e-15 + (fConst1 * (1.57495110277109e-16 + (fConst1 * (2.83422952091004e-18 + (fConst1 * (8.04682095406084e-21 + (fConst1 * (1.84047124153706e-24 + fConst2)))))))))));
	fConst4 = (1.64748694327623e-29 * fConst1);
	fConst5 = (1.93838135905185e-29 + (fConst1 * (6.19874196009298e-30 + (fConst1 * (1.02263452098685e-18 + (fConst1 * (8.26211810398552e-20 + (fConst1 * ((fConst1 * (2.43443628230356e-24 + fConst4)) - 6.41956885041712e-22)))))))));
	fConst6 = (1.64754329517958e-29 * fConst1);
	fConst7 = ((fConst1 * ((fConst1 * ((fConst1 * ((fConst1 * ((fConst1 * (0 - (3.94157555569494e-24 + fConst6))) - 2.47433918579296e-21)) - 1.10043592848188e-19)) - 1.2128956454365e-18)) - 1.83296173313311e-18)) - 9.05605605123541e-30);
	fConst8 = (7.52535091341887e-30 * fConst1);
	fConst9 = (2.1029195738757e-44 + (fConst1 * (2.93687897741885e-31 + (fConst1 * (5.68584729614914e-20 + (fConst1 * ((fConst1 * ((fConst1 * (0 - (5.75543287332428e-25 + fConst8))) - 1.07355870433937e-20)) - 2.53456501824145e-20)))))));
	fConst10 = ((fConst1 * ((fConst1 * (1.22867306335763e-31 + (fConst1 * (2.53712740879898e-20 + (fConst1 * (9.35027604152672e-22 + (fConst1 * (5.75539622882997e-25 + fConst8)))))))) - 3.28759431682425e-44)) - 3.02594805935471e-57);
	fConst11 = (7.52307748899192e-30 * fConst1);
	fConst12 = (3.37361991212906e-45 + (fConst1 * (3.66592346625486e-18 + (fConst1 * (4.16659939650413e-19 + (fConst1 * (8.02851459470618e-20 + (fConst1 * (9.38675917848623e-22 + (fConst1 * (fConst11 - 5.50471129659625e-24)))))))))));
	fConst13 = ((fConst1 * ((fConst1 * ((fConst1 * ((fConst1 * (8.86551593801736e-21 + (fConst1 * (5.5047311176716e-24 - fConst11)))) - 2.54321729902389e-20)) - 5.68584729617373e-20)) - 2.9368789774182e-31)) - 2.1029195738751e-44);
	fConst14 = (1.54021551480516e-29 * fConst1);
	fConst15 = ((fConst1 * ((fConst1 * (3.33165699705571e-17 + (fConst1 * (1.19787046162065e-17 + (fConst1 * (1.2281094597269e-20 + (fConst1 * (7.01851102025914e-24 + fConst14)))))))) - 2.57394626354898e-18)) - 1.92682043654639e-31);
	fConst16 = ((fConst1 * ((fConst1 * ((fConst1 * ((fConst1 * ((fConst1 * (0 - (7.01851901894622e-24 + fConst14))) - 1.20699475502693e-20)) - 1.13635242699938e-18)) - 3.35545548862763e-17)) - 6.23206989263251e-17)) - 4.52802802586484e-30);
	fConst17 = (1.10594233205335e-32 * fConst1);
	fConst18 = ((fConst1 * (6.74323393056229e-18 + (fConst1 * (1.01590675843658e-17 + (fConst1 * ((fConst1 * (8.34173258781271e-26 + fConst17)) - 3.19297153668685e-21)))))) - 1.32043443319639e-16);
	fConst19 = (3.47652350176459e-32 * fConst1);
	fConst20 = ((fConst1 * (1.44672836825812e-32 + (fConst1 * ((fConst1 * ((fConst1 * (3.97246076242424e-24 + fConst19)) - 1.18943271263314e-20)) - 6.26466655045784e-22)))) - 2.80918858709381e-31);
	fConst21 = (1.62267527611309e-32 * fConst1);
	fConst22 = ((fConst1 * (4.02488573615741e-35 + (fConst1 * (8.5702219164734e-21 + (fConst1 * (0 - (5.31828810650215e-24 + fConst21))))))) - 2.88197472972382e-48);
	fConst23 = (1.13716945923229e-19 + (fConst1 * ((fConst1 * (1.08787157512025e-23 + (fConst1 * (5.31827418146769e-24 + fConst21)))) - 4.58203856389025e-21)));
	fConst24 = (1.60918962936167e-32 * fConst1);
	fConst25 = (2.88197472972382e-48 + (fConst1 * ((fConst1 * (7.79224675454785e-24 + (fConst1 * (fConst24 - 3.51166299427547e-27)))) - 4.02488573615741e-35)));
	fConst26 = ((fConst1 * (4.24213720780592e-32 + (fConst1 * ((fConst1 * (3.51144562408283e-27 - fConst24)) - 8.5858064099825e-21)))) - 2.88197472972382e-48);
	fConst27 = (3.47318078294216e-32 * fConst1);
	fConst28 = (2.80918858709381e-31 + (fConst1 * ((fConst1 * (2.9174859369697e-21 + (fConst1 * (9.16680826374599e-21 + (fConst1 * (0 - (2.653326742278e-24 + fConst27))))))) - 5.68584729616292e-20)));
	fConst29 = (3.73094665895005e-32 * fConst1);
	fConst30 = (1.40459429362355e-31 + (fConst1 * ((fConst1 * (1.32402223523449e-20 + (fConst1 * (1.64401341395932e-22 + (fConst1 * (0 - (1.05060592945849e-25 + fConst29))))))) - 1.93318808069491e-18)));
	fConst31 = ((fConst1 * (1.87632960773329e-18 + (fConst1 * ((fConst1 * (2.04493341455609e-23 + (fConst1 * (1.05067668871474e-25 + fConst29)))) - 9.5248173334047e-18)))) - 1.40459429362355e-31);
	fConst32 = (4.25671964279894e-15 + (fConst1 * ((fConst1 * (1.57495110277109e-16 + (fConst1 * ((fConst1 * (8.04682095406084e-21 + (fConst1 * (fConst2 - 1.84047124153706e-24)))) - 2.83422952091004e-18)))) - 1.62143829384899e-15)));
	fConst33 = (1.93838135905185e-29 + (fConst1 * ((fConst1 * (1.02263452098685e-18 + (fConst1 * ((fConst1 * ((fConst1 * (fConst4 - 2.43443628230356e-24)) - 6.41956885041712e-22)) - 8.26211810398552e-20)))) - 6.19874196009298e-30)));
	fConst34 = ((fConst1 * (1.83296173313311e-18 + (fConst1 * ((fConst1 * (1.10043592848188e-19 + (fConst1 * ((fConst1 * (3.94157555569494e-24 - fConst6)) - 2.47433918579296e-21)))) - 1.2128956454365e-18)))) - 9.05605605123541e-30);
	fConst35 = (2.1029195738757e-44 + (fConst1 * ((fConst1 * (5.68584729614914e-20 + (fConst1 * (2.53456501824145e-20 + (fConst1 * ((fConst1 * (5.75543287332428e-25 - fConst8)) - 1.07355870433937e-20)))))) - 2.93687897741885e-31)));
	fConst36 = ((fConst1 * (3.28759431682425e-44 + (fConst1 * (1.22867306335763e-31 + (fConst1 * ((fConst1 * (9.35027604152672e-22 + (fConst1 * (fConst8 - 5.75539622882997e-25)))) - 2.53712740879898e-20)))))) - 3.02594805935471e-57);
	fConst37 = (3.37361991212906e-45 + (fConst1 * ((fConst1 * (4.16659939650413e-19 + (fConst1 * ((fConst1 * (9.38675917848623e-22 + (fConst1 * (5.50471129659625e-24 + fConst11)))) - 8.02851459470618e-20)))) - 3.66592346625486e-18)));
	fConst38 = ((fConst1 * (2.9368789774182e-31 + (fConst1 * ((fConst1 * (2.54321729902389e-20 + (fConst1 * (8.86551593801736e-21 + (fConst1 * (0 - (5.5047311176716e-24 + fConst11))))))) - 5.68584729617373e-20)))) - 2.1029195738751e-44);
	fConst39 = ((fConst1 * (2.57394626354898e-18 + (fConst1 * (3.33165699705571e-17 + (fConst1 * ((fConst1 * (1.2281094597269e-20 + (fConst1 * (fConst14 - 7.01851102025914e-24)))) - 1.19787046162065e-17)))))) - 1.92682043654639e-31);
	fConst40 = ((fConst1 * (6.23206989263251e-17 + (fConst1 * ((fConst1 * (1.13635242699938e-18 + (fConst1 * ((fConst1 * (7.01851901894622e-24 - fConst14)) - 1.20699475502693e-20)))) - 3.35545548862763e-17)))) - 4.52802802586484e-30);
	fConst41 = (2.48192504407556e-29 * fConst1);
	fConst42 = faustpower<2>(fConst1);
	fConst43 = (2.55403178567936e-14 + (fConst1 * ((fConst1 * (3.14990220554218e-16 + (fConst42 * ((fConst1 * (7.36188496614825e-24 - fConst41)) - 1.60936419081217e-20)))) - 6.48575317539595e-15)));
	fConst44 = (9.88492165965738e-29 * fConst1);
	fConst45 = (1.16302881543111e-28 + (fConst1 * ((fConst1 * (2.04526904197369e-18 + (fConst42 * (1.28391377008342e-21 + (fConst1 * (9.73774512921423e-24 - fConst44)))))) - 2.47949678403719e-29)));
	fConst46 = (9.88525977107748e-29 * fConst1);
	fConst47 = ((fConst1 * (7.33184693253246e-18 + (fConst1 * ((fConst42 * (4.94867837158591e-21 + (fConst1 * (fConst46 - 1.57663022227797e-23)))) - 2.425791290873e-18)))) - 5.43363363074125e-29);
	fConst48 = (4.51521054805133e-29 * fConst1);
	fConst49 = (1.26175174432542e-43 + (fConst1 * ((fConst1 * (1.13716945922983e-19 + (fConst42 * (2.14711740867875e-20 + (fConst1 * (fConst48 - 2.30217314932971e-24)))))) - 1.17475159096754e-30)));
	fConst50 = ((fConst1 * (1.3150377267297e-43 + (fConst1 * (2.45734612671525e-31 + (fConst42 * ((fConst1 * (2.30215849153199e-24 - fConst48)) - 1.87005520830534e-21)))))) - 1.81556883561283e-56);
	fConst51 = (4.51384649339515e-29 * fConst1);
	fConst52 = (2.02417194727744e-44 + (fConst1 * ((fConst1 * (8.33319879300826e-19 + (fConst42 * ((fConst1 * (0 - (2.2018845186385e-23 + fConst51))) - 1.87735183569725e-21)))) - 1.46636938650194e-17)));
	fConst53 = ((fConst1 * (1.17475159096728e-30 + (fConst1 * ((fConst42 * ((fConst1 * (2.20189244706864e-23 + fConst51)) - 1.77310318760347e-20)) - 1.13716945923475e-19)))) - 1.26175174432506e-43);
	fConst54 = (9.24129308883096e-29 * fConst1);
	fConst55 = ((fConst1 * (1.02957850541959e-17 + (fConst1 * (6.66331399411141e-17 + (fConst42 * ((fConst1 * (2.80740440810366e-23 - fConst54)) - 2.45621891945381e-20)))))) - 1.15609226192783e-30);
	fConst56 = ((fConst1 * (2.49282795705301e-16 + (fConst1 * ((fConst42 * (2.41398951005385e-20 + (fConst1 * (fConst54 - 2.80740760757849e-23)))) - 6.71091097725527e-17)))) - 2.71681681551891e-29);
	fConst57 = (6.20481261018889e-29 * fConst1);
	fConst58 = (6.38507946419841e-14 + (fConst1 * ((fConst1 * ((fConst1 * (8.50268856273012e-18 + (fConst1 * ((fConst1 * (fConst57 - 9.20235620768531e-24)) - 8.04682095406084e-21)))) - 1.57495110277109e-16)) - 8.10719146924494e-15)));
	fConst59 = (2.47123041491435e-28 * fConst1);
	fConst60 = (2.90757203857778e-28 + (fConst1 * ((fConst1 * ((fConst1 * (2.47863543119566e-19 + (fConst1 * (6.41956885041712e-22 + (fConst1 * (fConst59 - 1.21721814115178e-23)))))) - 1.02263452098685e-18)) - 3.09937098004649e-29)));
	fConst61 = (2.47131494276937e-28 * fConst1);
	fConst62 = ((fConst1 * (9.16480866566557e-18 + (fConst1 * (1.2128956454365e-18 + (fConst1 * ((fConst1 * (2.47433918579296e-21 + (fConst1 * (1.97078777784747e-23 - fConst61)))) - 3.30130778544565e-19)))))) - 1.35840840768531e-28);
	fConst63 = (1.12880263701283e-28 * fConst1);
	fConst64 = (3.15437936081355e-43 + (fConst1 * ((fConst1 * ((fConst1 * ((fConst1 * (1.07355870433937e-20 + (fConst1 * (2.87771643666214e-24 - fConst63)))) - 7.60369505472436e-20)) - 5.68584729614914e-20)) - 1.46843948870943e-30)));
	fConst65 = ((fConst1 * (1.64379715841212e-43 + (fConst1 * ((fConst1 * (7.61138222639695e-20 + (fConst1 * ((fConst1 * (fConst63 - 2.87769811441498e-24)) - 9.35027604152672e-22)))) - 1.22867306335763e-31)))) - 4.53892208903206e-56);
	fConst66 = (1.12846162334879e-28 * fConst1);
	fConst67 = (5.06042986819359e-44 + (fConst1 * ((fConst1 * ((fConst1 * (2.40855437841186e-19 + (fConst1 * ((fConst1 * (2.75235564829812e-23 + fConst66)) - 9.38675917848623e-22)))) - 4.16659939650413e-19)) - 1.83296173312743e-17)));
	fConst68 = ((fConst1 * (1.4684394887091e-30 + (fConst1 * (5.68584729617373e-20 + (fConst1 * ((fConst1 * ((fConst1 * (0 - (2.7523655588358e-23 + fConst66))) - 8.86551593801736e-21)) - 7.62965189707167e-20)))))) - 3.15437936081265e-43);
	fConst69 = (2.31032327220774e-28 * fConst1);
	fConst70 = ((fConst1 * (1.28697313177449e-17 + (fConst1 * ((fConst1 * (3.59361138486196e-17 + (fConst1 * ((fConst1 * (fConst69 - 3.50925551012957e-23)) - 1.2281094597269e-20)))) - 3.33165699705571e-17)))) - 2.89023065481959e-30);
	fConst71 = ((fConst1 * (3.11603494631626e-16 + (fConst1 * (3.35545548862763e-17 + (fConst1 * ((fConst1 * (1.20699475502693e-20 + (fConst1 * (3.50925950947311e-23 - fConst69)))) - 3.40905728099815e-18)))))) - 6.79204203879726e-29);
	fConst72 = (8.51343928559787e-14 + (fConst42 * ((fConst42 * (3.21872838162433e-20 - (8.27308348025186e-29 * fConst42))) - 6.29980441108435e-16)));
	fConst73 = (3.87676271810371e-28 + (fConst42 * ((fConst42 * (0 - (2.56782754016685e-21 + (3.29497388655246e-28 * fConst42)))) - 4.09053808394738e-18)));
	fConst74 = ((fConst42 * (4.85158258174599e-18 + (fConst42 * ((3.29508659035916e-28 * fConst42) - 9.89735674317183e-21)))) - 1.81121121024708e-28);
	fConst75 = (1.50507018268377e-28 * fConst42);
	fConst76 = (4.2058391477514e-43 + (fConst42 * ((fConst42 * (fConst75 - 4.2942348173575e-20)) - 2.27433891845966e-19)));
	fConst77 = ((fConst42 * ((fConst42 * (3.74011041661069e-21 - fConst75)) - 4.9146922534305e-31)) - 6.05189611870942e-56);
	fConst78 = (1.50461549779838e-28 * fConst42);
	fConst79 = (6.74723982425812e-44 + (fConst42 * ((fConst42 * (3.75470367139449e-21 - fConst78)) - 1.66663975860165e-18)));
	fConst80 = ((fConst42 * (2.27433891846949e-19 + (fConst42 * (3.54620637520694e-20 + fConst78)))) - 4.20583914775019e-43);
	fConst81 = (3.08043102961032e-28 * fConst42);
	fConst82 = ((fConst42 * ((fConst42 * (4.91243783890761e-20 - fConst81)) - 1.33266279882228e-16)) - 3.85364087309278e-30);
	fConst83 = ((fConst42 * (1.34218219545105e-16 + (fConst42 * (fConst81 - 4.82797902010771e-20)))) - 9.05605605172968e-29);
	fConst84 = (6.38507946419841e-14 + (fConst1 * (8.10719146924494e-15 + (fConst1 * ((fConst1 * ((fConst1 * ((fConst1 * (9.20235620768531e-24 + fConst57)) - 8.04682095406084e-21)) - 8.50268856273012e-18)) - 1.57495110277109e-16)))));
	fConst85 = (2.90757203857778e-28 + (fConst1 * (3.09937098004649e-29 + (fConst1 * ((fConst1 * ((fConst1 * (6.41956885041712e-22 + (fConst1 * (1.21721814115178e-23 + fConst59)))) - 2.47863543119566e-19)) - 1.02263452098685e-18)))));
	fConst86 = ((fConst1 * ((fConst1 * (1.2128956454365e-18 + (fConst1 * (3.30130778544565e-19 + (fConst1 * (2.47433918579296e-21 + (fConst1 * (0 - (1.97078777784747e-23 + fConst61))))))))) - 9.16480866566557e-18)) - 1.35840840768531e-28);
	fConst87 = (3.15437936081355e-43 + (fConst1 * (1.46843948870943e-30 + (fConst1 * ((fConst1 * (7.60369505472436e-20 + (fConst1 * (1.07355870433937e-20 + (fConst1 * (0 - (2.87771643666214e-24 + fConst63))))))) - 5.68584729614914e-20)))));
	fConst88 = ((fConst1 * ((fConst1 * ((fConst1 * ((fConst1 * ((fConst1 * (2.87769811441498e-24 + fConst63)) - 9.35027604152672e-22)) - 7.61138222639695e-20)) - 1.22867306335763e-31)) - 1.64379715841212e-43)) - 4.53892208903206e-56);
	fConst89 = (5.06042986819359e-44 + (fConst1 * (1.83296173312743e-17 + (fConst1 * ((fConst1 * ((fConst1 * ((fConst1 * (fConst66 - 2.75235564829812e-23)) - 9.38675917848623e-22)) - 2.40855437841186e-19)) - 4.16659939650413e-19)))));
	fConst90 = ((fConst1 * ((fConst1 * (5.68584729617373e-20 + (fConst1 * (7.62965189707167e-20 + (fConst1 * ((fConst1 * (2.7523655588358e-23 - fConst66)) - 8.86551593801736e-21)))))) - 1.4684394887091e-30)) - 3.15437936081265e-43);
	fConst91 = ((fConst1 * ((fConst1 * ((fConst1 * ((fConst1 * ((fConst1 * (3.50925551012957e-23 + fConst69)) - 1.2281094597269e-20)) - 3.59361138486196e-17)) - 3.33165699705571e-17)) - 1.28697313177449e-17)) - 2.89023065481959e-30);
	fConst92 = ((fConst1 * ((fConst1 * (3.35545548862763e-17 + (fConst1 * (3.40905728099815e-18 + (fConst1 * (1.20699475502693e-20 + (fConst1 * (0 - (3.50925950947311e-23 + fConst69))))))))) - 3.11603494631626e-16)) - 6.79204203879726e-29);
	fConst93 = (2.55403178567936e-14 + (fConst1 * (6.48575317539595e-15 + (fConst1 * (3.14990220554218e-16 + (fConst42 * ((fConst1 * (0 - (7.36188496614825e-24 + fConst41))) - 1.60936419081217e-20)))))));
	fConst94 = (1.16302881543111e-28 + (fConst1 * (2.47949678403719e-29 + (fConst1 * (2.04526904197369e-18 + (fConst42 * (1.28391377008342e-21 + (fConst1 * (0 - (9.73774512921423e-24 + fConst44))))))))));
	fConst95 = ((fConst1 * ((fConst1 * ((fConst42 * (4.94867837158591e-21 + (fConst1 * (1.57663022227797e-23 + fConst46)))) - 2.425791290873e-18)) - 7.33184693253246e-18)) - 5.43363363074125e-29);
	fConst96 = (1.26175174432542e-43 + (fConst1 * (1.17475159096754e-30 + (fConst1 * (1.13716945922983e-19 + (fConst42 * (2.14711740867875e-20 + (fConst1 * (2.30217314932971e-24 + fConst48)))))))));
	fConst97 = ((fConst1 * ((fConst1 * (2.45734612671525e-31 + (fConst42 * ((fConst1 * (0 - (2.30215849153199e-24 + fConst48))) - 1.87005520830534e-21)))) - 1.3150377267297e-43)) - 1.81556883561283e-56);
	fConst98 = (2.02417194727744e-44 + (fConst1 * (1.46636938650194e-17 + (fConst1 * (8.33319879300826e-19 + (fConst42 * ((fConst1 * (2.2018845186385e-23 - fConst51)) - 1.87735183569725e-21)))))));
	fConst99 = ((fConst1 * ((fConst1 * ((fConst42 * ((fConst1 * (fConst51 - 2.20189244706864e-23)) - 1.77310318760347e-20)) - 1.13716945923475e-19)) - 1.17475159096728e-30)) - 1.26175174432506e-43);
	fConst100 = ((fConst1 * ((fConst1 * (6.66331399411141e-17 + (fConst42 * ((fConst1 * (0 - (2.80740440810366e-23 + fConst54))) - 2.45621891945381e-20)))) - 1.02957850541959e-17)) - 1.15609226192783e-30);
	fConst101 = ((fConst1 * ((fConst1 * ((fConst42 * (2.41398951005385e-20 + (fConst1 * (2.80740760757849e-23 + fConst54)))) - 6.71091097725527e-17)) - 2.49282795705301e-16)) - 2.71681681551891e-29);
	fConst102 = (2.36301137905642e-10 * fConst1);
	fConst103 = (0.00024035936046162 + (fConst1 * (fConst102 - 9.48587122718622e-06)));
	fConst104 = (0.00048071872092324 - (4.72602275811285e-10 * fConst42));
	fConst105 = (1.0 / (0.00024035936046162 + (fConst1 * (9.48587122718622e-06 + fConst102))));
	fConst106 = (1.92529627659134e-39 * fConst1);
	fConst107 = (3.23357227133522e-16 + (fConst1 * (1.13510423198382e-17 + (fConst1 * (9.51573004877601e-20 + (fConst1 * (1.23489756547062e-22 + (fConst1 * (5.3338333519646e-26 + (fConst1 * (7.06820551701561e-30 + (fConst1 * (2.75588927932986e-34 + fConst106)))))))))))));
	fConst108 = (1.63288633577099e-38 * fConst1);
	fConst109 = (fConst1 * ((fConst1 * ((fConst1 * ((fConst1 * ((fConst1 * ((fConst1 * (0 - (2.8886681393884e-33 + fConst108))) - 1.22380298287253e-28)) - 5.97891285045565e-25)) - 6.57559879124984e-22)) - 2.70493592383428e-20)) - 1.10503345585892e-19));
	fConst110 = (1.90156498997068e-38 * fConst1);
	fConst111 = (1.95892294447717e-17 + (fConst1 * (5.09420379958945e-18 + (fConst1 * (1.88951592676649e-19 + (fConst1 * (1.70315358798795e-21 + (fConst1 * (1.27197539082944e-24 + (fConst1 * (1.6275988249883e-28 + (fConst1 * (3.4993097780779e-33 + fConst110)))))))))))));
	fConst112 = (1.45022424488616e-38 * fConst1);
	fConst113 = (fConst1 * (2.28520918671624e-21 + (fConst1 * (4.99352622765038e-22 + (fConst1 * (4.83309951544608e-25 + (fConst1 * (1.07525226870021e-28 + (fConst1 * (2.55893259997086e-33 + fConst112))))))))));
	fConst114 = (1.70915998273057e-38 * fConst1);
	fConst115 = ((fConst1 * ((fConst1 * ((fConst1 * ((fConst1 * ((fConst1 * (0 - (3.14082755831951e-33 + fConst114))) - 1.45514899806723e-28)) - 1.11126344104395e-24)) - 1.43632728325539e-21)) - 9.47067849160929e-20)) - 4.05105264917879e-19);
	fConst116 = (1.72896220329133e-39 * fConst1);
	fConst117 = ((fConst1 * ((fConst1 * ((fConst1 * ((fConst1 * ((fConst1 * ((fConst1 * (0 - (2.47057060517596e-34 + fConst116))) - 6.28852429480213e-30)) - 4.66623845928268e-26)) - 1.05878053917009e-22)) - 7.78363208113535e-20)) - 6.00488965844066e-18)) - 2.59682862126846e-17);
	fConst118 = (1.17470552663686e-35 * fConst1);
	fConst119 = (1.16377254046491e-18 + (fConst1 * ((fConst1 * (3.55031486822181e-22 + (fConst1 * ((fConst1 * (6.55885525437233e-29 + fConst118)) - 3.16419726163444e-25)))) - 4.0494025208599e-20)));
	fConst120 = (1.09988351857082e-35 * fConst1);
	fConst121 = (2.40668161368143e-20 + (fConst1 * ((fConst1 * (3.06797455387272e-25 + (fConst1 * (0 - (6.14090528477483e-29 + fConst120))))) - 3.39714683604509e-22)));
	fConst122 = (9.3823923360494e-35 * fConst1);
	fConst123 = (fConst1 * (4.81336322736286e-22 + (fConst1 * ((fConst1 * (5.32017237321892e-28 + fConst122)) - 1.95218079151343e-24))));
	fConst124 = (8.28250881747858e-35 * fConst1);
	fConst125 = ((fConst1 * ((fConst1 * (1.64538333612616e-24 + (fConst1 * (0 - (4.70608184474143e-28 + fConst124))))) - 1.41621639131778e-22)) - 2.40668161368143e-20);
	fConst126 = (1.00206503180936e-34 * fConst1);
	fConst127 = (fConst1 * (2.32754508092981e-20 + (fConst1 * ((fConst1 * (1.98753368998566e-24 + (fConst1 * (0 - (5.6822605863427e-28 + fConst126))))) - 5.75735780739837e-22))));
	fConst128 = (8.84594479145671e-35 * fConst1);
	fConst129 = ((fConst1 * (1.72185743993009e-20 + (fConst1 * (2.20704293917657e-22 + (fConst1 * ((fConst1 * (5.02637506090546e-28 + fConst128)) - 1.67111396382221e-24)))))) - 1.16377254046491e-18);
	fConst130 = ((fConst1 * (1.13510423198382e-17 + (fConst1 * ((fConst1 * (1.23489756547062e-22 + (fConst1 * ((fConst1 * (7.06820551701561e-30 + (fConst1 * (fConst106 - 2.75588927932986e-34)))) - 5.3338333519646e-26)))) - 9.51573004877601e-20)))) - 3.23357227133522e-16);
	fConst131 = (fConst1 * ((fConst1 * (2.70493592383428e-20 + (fConst1 * ((fConst1 * (5.97891285045565e-25 + (fConst1 * ((fConst1 * (2.8886681393884e-33 - fConst108)) - 1.22380298287253e-28)))) - 6.57559879124984e-22)))) - 1.10503345585892e-19));
	fConst132 = ((fConst1 * (5.09420379958945e-18 + (fConst1 * ((fConst1 * (1.70315358798795e-21 + (fConst1 * ((fConst1 * (1.6275988249883e-28 + (fConst1 * (fConst110 - 3.4993097780779e-33)))) - 1.27197539082944e-24)))) - 1.88951592676649e-19)))) - 1.95892294447717e-17);
	fConst133 = (fConst1 * ((fConst1 * (4.99352622765038e-22 + (fConst1 * ((fConst1 * (1.07525226870021e-28 + (fConst1 * (fConst112 - 2.55893259997086e-33)))) - 4.83309951544608e-25)))) - 2.28520918671624e-21));
	fConst134 = ((fConst1 * (9.47067849160929e-20 + (fConst1 * ((fConst1 * (1.11126344104395e-24 + (fConst1 * ((fConst1 * (3.14082755831951e-33 - fConst114)) - 1.45514899806723e-28)))) - 1.43632728325539e-21)))) - 4.05105264917879e-19);
	fConst135 = (2.59682862126846e-17 + (fConst1 * ((fConst1 * (7.78363208113535e-20 + (fConst1 * ((fConst1 * (4.66623845928268e-26 + (fConst1 * ((fConst1 * (2.47057060517596e-34 - fConst116)) - 6.28852429480213e-30)))) - 1.05878053917009e-22)))) - 6.00488965844066e-18)));
	fConst136 = (1.54023702127307e-38 * fConst1);
	fConst137 = ((fConst1 * (4.54041692793529e-17 + (fConst1 * ((fConst42 * (1.06676667039292e-25 + (fConst1 * ((fConst1 * (1.65353356759792e-33 - fConst136)) - 2.82728220680625e-29)))) - 1.9031460097552e-19)))) - 1.94014336280113e-15);
	fConst138 = (1.3063090686168e-37 * fConst1);
	fConst139 = (fConst1 * ((fConst1 * (5.40987184766855e-20 + (fConst42 * ((fConst1 * (4.89521193149012e-28 + (fConst1 * (fConst138 - 1.73320088363304e-32)))) - 1.19578257009113e-24)))) - 4.42013382343566e-19));
	fConst140 = (1.52125199197655e-37 * fConst1);
	fConst141 = ((fConst1 * (2.03768151983578e-17 + (fConst1 * ((fConst42 * (2.54395078165888e-24 + (fConst1 * ((fConst1 * (2.09958586684674e-32 - fConst140)) - 6.5103952999532e-28)))) - 3.77903185353297e-19)))) - 1.1753537666863e-16);
	fConst142 = (1.16017939590893e-37 * fConst1);
	fConst143 = (fConst1 * ((fConst42 * (9.66619903089217e-25 + (fConst1 * ((fConst1 * (1.53535955998251e-32 - fConst142)) - 4.30100907480083e-28)))) - 4.57041837343248e-21));
	fConst144 = (1.36732798618446e-37 * fConst1);
	fConst145 = ((fConst1 * (1.89413569832186e-19 + (fConst42 * ((fConst1 * (5.82059599226893e-28 + (fConst1 * (fConst144 - 1.88449653499171e-32)))) - 2.2225268820879e-24)))) - 1.62042105967152e-18);
	fConst146 = (1.38316976263306e-38 * fConst1);
	fConst147 = (1.55809717276107e-16 + (fConst1 * ((fConst1 * (1.55672641622707e-19 + (fConst42 * ((fConst1 * (2.51540971792085e-29 + (fConst1 * (fConst146 - 1.48234236310557e-33)))) - 9.33247691856536e-26)))) - 2.40195586337626e-17)));
	fConst148 = (5.39082957445574e-38 * fConst1);
	fConst149 = ((fConst1 * (4.54041692793529e-17 + (fConst1 * (1.9031460097552e-19 + (fConst1 * ((fConst1 * (1.06676667039292e-25 + (fConst1 * (2.82728220680625e-29 + (fConst1 * (fConst148 - 3.85824499106181e-33)))))) - 4.93959026188247e-22)))))) - 4.52700117986931e-15);
	fConst150 = (4.57208174015878e-37 * fConst1);
	fConst151 = (fConst1 * ((fConst1 * ((fConst1 * (2.63023951649994e-21 + (fConst1 * ((fConst1 * ((fConst1 * (4.04413539514376e-32 - fConst150)) - 4.89521193149012e-28)) - 1.19578257009113e-24)))) - 5.40987184766855e-20)) - 4.42013382343566e-19));
	fConst152 = (5.32438197191791e-37 * fConst1);
	fConst153 = ((fConst1 * (2.03768151983578e-17 + (fConst1 * (3.77903185353297e-19 + (fConst1 * ((fConst1 * (2.54395078165888e-24 + (fConst1 * (6.5103952999532e-28 + (fConst1 * (fConst152 - 4.89903368930905e-32)))))) - 6.81261435195178e-21)))))) - 2.74249212226804e-16);
	fConst154 = (4.06062788568125e-37 * fConst1);
	fConst155 = (fConst1 * (4.57041837343248e-21 + (fConst1 * ((fConst1 * (9.66619903089217e-25 + (fConst1 * (4.30100907480083e-28 + (fConst1 * (fConst154 - 3.5825056399592e-32)))))) - 1.99741049106015e-21))));
	fConst156 = (4.7856479516456e-37 * fConst1);
	fConst157 = ((fConst1 * ((fConst1 * (5.74530913302157e-21 + (fConst1 * ((fConst1 * ((fConst1 * (4.39715858164732e-32 - fConst156)) - 5.82059599226893e-28)) - 2.2225268820879e-24)))) - 1.89413569832186e-19)) - 1.62042105967152e-18);
	fConst158 = (4.84109416921572e-38 * fConst1);
	fConst159 = (3.63556006977584e-16 + (fConst1 * ((fConst1 * ((fConst1 * (4.23512215668038e-22 + (fConst1 * ((fConst1 * ((fConst1 * (3.45879884724634e-33 - fConst158)) - 2.51540971792085e-29)) - 9.33247691856536e-26)))) - 1.55672641622707e-19)) - 2.40195586337626e-17)));
	fConst160 = (1.07816591489115e-37 * fConst1);
	fConst161 = ((fConst1 * ((fConst1 * (5.7094380292656e-19 + (fConst42 * ((fConst1 * (2.82728220680625e-29 + (fConst1 * (3.85824499106181e-33 - fConst160)))) - 3.20030001117876e-25)))) - 4.54041692793529e-17)) - 4.52700117986931e-15);
	fConst162 = (9.14416348031757e-37 * fConst1);
	fConst163 = (fConst1 * (4.42013382343566e-19 + (fConst1 * ((fConst42 * (3.58734771027339e-24 + (fConst1 * ((fConst1 * (fConst162 - 4.04413539514376e-32)) - 4.89521193149012e-28)))) - 1.62296155430057e-19))));
	fConst164 = (1.06487639438358e-36 * fConst1);
	fConst165 = ((fConst1 * ((fConst1 * (1.13370955605989e-18 + (fConst42 * ((fConst1 * (6.5103952999532e-28 + (fConst1 * (4.89903368930905e-32 - fConst164)))) - 7.63185234497663e-24)))) - 2.03768151983578e-17)) - 2.74249212226804e-16);
	fConst166 = (8.12125577136249e-37 * fConst1);
	fConst167 = (fConst1 * (1.37112551202975e-20 + (fConst42 * ((fConst1 * (4.30100907480083e-28 + (fConst1 * (3.5825056399592e-32 - fConst166)))) - 2.89985970926765e-24))));
	fConst168 = (9.57129590329121e-37 * fConst1);
	fConst169 = (1.62042105967152e-18 + (fConst1 * ((fConst42 * (6.66758064626369e-24 + (fConst1 * ((fConst1 * (fConst168 - 4.39715858164732e-32)) - 5.82059599226893e-28)))) - 5.68240709496558e-19)));
	fConst170 = (9.68218833843144e-38 * fConst1);
	fConst171 = (3.63556006977584e-16 + (fConst1 * (2.40195586337626e-17 + (fConst1 * ((fConst42 * (2.79974307556961e-25 + (fConst1 * ((fConst1 * (fConst170 - 3.45879884724634e-33)) - 2.51540971792085e-29)))) - 4.67017924868121e-19)))));
	fConst172 = ((fConst42 * (7.40938539282371e-22 + (fConst42 * ((1.34770739361393e-37 * fConst42) - 7.06820551701561e-29)))) - 1.13510423198382e-16);
	fConst173 = (1.10503345585892e-18 + (fConst42 * ((fConst42 * (1.22380298287253e-27 - (1.1430204350397e-36 * fConst42))) - 3.9453592747499e-21)));
	fConst174 = ((fConst42 * (1.02189215279277e-20 + (fConst42 * ((1.33109549297948e-36 * fConst42) - 1.6275988249883e-27)))) - 5.09420379958945e-17);
	fConst175 = (6.00488965844066e-17 + (fConst42 * ((fConst42 * (6.28852429480213e-29 - (1.21027354230393e-37 * fConst42))) - 6.35268323502056e-22)));
	fConst176 = (fConst42 * (2.99611573659023e-21 + (fConst42 * ((1.01515697142031e-36 * fConst42) - 1.07525226870021e-27))));
	fConst177 = (4.05105264917879e-18 + (fConst42 * ((fConst42 * (1.45514899806723e-27 - (1.1964119879114e-36 * fConst42))) - 8.61796369953236e-21)));
	fConst178 = (4.52700117986931e-15 + (fConst1 * ((fConst1 * ((fConst42 * (3.20030001117876e-25 + (fConst1 * (2.82728220680625e-29 + (fConst1 * (0 - (3.85824499106181e-33 + fConst160))))))) - 5.7094380292656e-19)) - 4.54041692793529e-17)));
	fConst179 = (fConst1 * (4.42013382343566e-19 + (fConst1 * (1.62296155430057e-19 + (fConst42 * ((fConst1 * ((fConst1 * (4.04413539514376e-32 + fConst162)) - 4.89521193149012e-28)) - 3.58734771027339e-24))))));
	fConst180 = (2.74249212226804e-16 + (fConst1 * ((fConst1 * ((fConst42 * (7.63185234497663e-24 + (fConst1 * (6.5103952999532e-28 + (fConst1 * (0 - (4.89903368930905e-32 + fConst164))))))) - 1.13370955605989e-18)) - 2.03768151983578e-17)));
	fConst181 = (fConst1 * ((fConst42 * (2.89985970926765e-24 + (fConst1 * (4.30100907480083e-28 + (fConst1 * (0 - (3.5825056399592e-32 + fConst166))))))) - 1.37112551202975e-20));
	fConst182 = (1.62042105967152e-18 + (fConst1 * (5.68240709496558e-19 + (fConst42 * ((fConst1 * ((fConst1 * (4.39715858164732e-32 + fConst168)) - 5.82059599226893e-28)) - 6.66758064626369e-24)))));
	fConst183 = ((fConst1 * (2.40195586337626e-17 + (fConst1 * (4.67017924868121e-19 + (fConst42 * ((fConst1 * ((fConst1 * (3.45879884724634e-33 + fConst170)) - 2.51540971792085e-29)) - 2.79974307556961e-25)))))) - 3.63556006977584e-16);
	fConst184 = (4.52700117986931e-15 + (fConst1 * (4.54041692793529e-17 + (fConst1 * ((fConst1 * ((fConst1 * ((fConst1 * (2.82728220680625e-29 + (fConst1 * (3.85824499106181e-33 + fConst148)))) - 1.06676667039292e-25)) - 4.93959026188247e-22)) - 1.9031460097552e-19)))));
	fConst185 = (fConst1 * ((fConst1 * (5.40987184766855e-20 + (fConst1 * (2.63023951649994e-21 + (fConst1 * (1.19578257009113e-24 + (fConst1 * ((fConst1 * (0 - (4.04413539514376e-32 + fConst150))) - 4.89521193149012e-28)))))))) - 4.42013382343566e-19));
	fConst186 = (2.74249212226804e-16 + (fConst1 * (2.03768151983578e-17 + (fConst1 * ((fConst1 * ((fConst1 * ((fConst1 * (6.5103952999532e-28 + (fConst1 * (4.89903368930905e-32 + fConst152)))) - 2.54395078165888e-24)) - 6.81261435195178e-21)) - 3.77903185353297e-19)))));
	fConst187 = (fConst1 * ((fConst1 * ((fConst1 * ((fConst1 * (4.30100907480083e-28 + (fConst1 * (3.5825056399592e-32 + fConst154)))) - 9.66619903089217e-25)) - 1.99741049106015e-21)) - 4.57041837343248e-21));
	fConst188 = ((fConst1 * (1.89413569832186e-19 + (fConst1 * (5.74530913302157e-21 + (fConst1 * (2.2225268820879e-24 + (fConst1 * ((fConst1 * (0 - (4.39715858164732e-32 + fConst156))) - 5.82059599226893e-28)))))))) - 1.62042105967152e-18);
	fConst189 = ((fConst1 * ((fConst1 * (1.55672641622707e-19 + (fConst1 * (4.23512215668038e-22 + (fConst1 * (9.33247691856536e-26 + (fConst1 * ((fConst1 * (0 - (3.45879884724634e-33 + fConst158))) - 2.51540971792085e-29)))))))) - 2.40195586337626e-17)) - 3.63556006977584e-16);
	fConst190 = (1.94014336280113e-15 + (fConst1 * (4.54041692793529e-17 + (fConst1 * (1.9031460097552e-19 + (fConst42 * ((fConst1 * ((fConst1 * (0 - (1.65353356759792e-33 + fConst136))) - 2.82728220680625e-29)) - 1.06676667039292e-25)))))));
	fConst191 = (fConst1 * ((fConst1 * ((fConst42 * (1.19578257009113e-24 + (fConst1 * (4.89521193149012e-28 + (fConst1 * (1.73320088363304e-32 + fConst138)))))) - 5.40987184766855e-20)) - 4.42013382343566e-19));
	fConst192 = (1.1753537666863e-16 + (fConst1 * (2.03768151983578e-17 + (fConst1 * (3.77903185353297e-19 + (fConst42 * ((fConst1 * ((fConst1 * (0 - (2.09958586684674e-32 + fConst140))) - 6.5103952999532e-28)) - 2.54395078165888e-24)))))));
	fConst193 = (fConst1 * (4.57041837343248e-21 + (fConst42 * ((fConst1 * ((fConst1 * (0 - (1.53535955998251e-32 + fConst142))) - 4.30100907480083e-28)) - 9.66619903089217e-25))));
	fConst194 = ((fConst1 * ((fConst42 * (2.2225268820879e-24 + (fConst1 * (5.82059599226893e-28 + (fConst1 * (1.88449653499171e-32 + fConst144)))))) - 1.89413569832186e-19)) - 1.62042105967152e-18);
	fConst195 = ((fConst1 * ((fConst1 * ((fConst42 * (9.33247691856536e-26 + (fConst1 * (2.51540971792085e-29 + (fConst1 * (1.48234236310557e-33 + fConst146)))))) - 1.55672641622707e-19)) - 2.40195586337626e-17)) - 1.55809717276107e-16);
	fConst196 = (470.33999466970965 / double(iConst0));
	fConst197 = (1 - fConst196);
	fConst198 = (1.0 / (1 + fConst196));
	fConst199 = (7.04823315982115e-35 * fConst1);
	fConst200 = (4.65509016185963e-18 + (fConst1 * ((fConst42 * (6.32839452326887e-25 + (fConst1 * (0 - (2.62354210174893e-28 + fConst199))))) - 8.09880504171981e-20)));
	fConst201 = (6.5993011114249e-35 * fConst1);
	fConst202 = (4.81336322736286e-20 + (fConst42 * ((fConst1 * (2.45636211390993e-28 + fConst201)) - 6.13594910774543e-25)));
	fConst203 = (5.62943540162964e-34 * fConst1);
	fConst204 = (fConst42 * (3.90436158302686e-24 + (fConst1 * (0 - (2.12806894928757e-27 + fConst203)))));
	fConst205 = (4.96950529048715e-34 * fConst1);
	fConst206 = ((fConst42 * ((fConst1 * (1.88243273789657e-27 + fConst205)) - 3.29076667225232e-24)) - 4.81336322736286e-20);
	fConst207 = (6.01239019085614e-34 * fConst1);
	fConst208 = (fConst1 * (4.65509016185963e-20 + (fConst42 * ((fConst1 * (2.27290423453708e-27 + fConst207)) - 3.97506737997131e-24))));
	fConst209 = (5.30756687487403e-34 * fConst1);
	fConst210 = ((fConst1 * (3.44371487986018e-20 + (fConst42 * (3.34222792764443e-24 + (fConst1 * (0 - (2.01055002436219e-27 + fConst209))))))) - 4.65509016185963e-18);
	fConst211 = (1.6445877372916e-34 * fConst1);
	fConst212 = (fConst1 * (2.62354210174893e-28 + fConst211));
	fConst213 = (4.65509016185963e-18 + (fConst1 * (8.09880504171981e-20 + (fConst1 * ((fConst1 * (6.32839452326887e-25 + fConst212)) - 1.42012594728872e-21)))));
	fConst214 = (1.53983692599914e-34 * fConst1);
	fConst215 = (fConst1 * (0 - (2.45636211390993e-28 + fConst214)));
	fConst216 = ((fConst1 * (1.35885873441803e-21 + (fConst1 * (fConst215 - 6.13594910774543e-25)))) - 4.81336322736286e-20);
	fConst217 = (1.31353492704692e-33 * fConst1);
	fConst218 = (fConst1 * (2.12806894928757e-27 + fConst217));
	fConst219 = (fConst1 * ((fConst1 * (3.90436158302686e-24 + fConst218)) - 1.92534529094515e-21));
	fConst220 = (1.159551234447e-33 * fConst1);
	fConst221 = (fConst1 * (0 - (1.88243273789657e-27 + fConst220)));
	fConst222 = (4.81336322736286e-20 + (fConst1 * (5.66486556527112e-22 + (fConst1 * (fConst221 - 3.29076667225232e-24)))));
	fConst223 = (1.4028910445331e-33 * fConst1);
	fConst224 = (fConst1 * (0 - (2.27290423453708e-27 + fConst223)));
	fConst225 = (fConst1 * ((fConst1 * (2.30294312295935e-21 + (fConst1 * (fConst224 - 3.97506737997131e-24)))) - 4.65509016185963e-20));
	fConst226 = (1.23843227080394e-33 * fConst1);
	fConst227 = (fConst1 * (2.01055002436219e-27 + fConst226));
	fConst228 = ((fConst1 * ((fConst1 * ((fConst1 * (3.34222792764443e-24 + fConst227)) - 8.82817175670626e-22)) - 3.44371487986018e-20)) - 4.65509016185963e-18);
	fConst229 = (fConst1 * (2.62354210174893e-28 - fConst211));
	fConst230 = ((fConst1 * (2.42964151251594e-19 + (fConst42 * (fConst229 - 1.89851835698066e-24)))) - 4.65509016185963e-18);
	fConst231 = (fConst1 * (fConst214 - 2.45636211390993e-28));
	fConst232 = ((fConst42 * (1.84078473232363e-24 + fConst231)) - 1.44400896820886e-19);
	fConst233 = (fConst1 * (2.12806894928757e-27 - fConst217));
	fConst234 = (fConst42 * (fConst233 - 1.17130847490806e-23));
	fConst235 = (fConst1 * (fConst220 - 1.88243273789657e-27));
	fConst236 = (1.44400896820886e-19 + (fConst42 * (9.87230001675696e-24 + fConst235)));
	fConst237 = (fConst1 * (fConst223 - 2.27290423453708e-27));
	fConst238 = (fConst1 * ((fConst42 * (1.19252021399139e-23 + fConst237)) - 1.39652704855789e-19));
	fConst239 = (fConst1 * (2.01055002436219e-27 - fConst226));
	fConst240 = (4.65509016185963e-18 + (fConst1 * ((fConst42 * (fConst239 - 1.00266837829333e-23)) - 1.03311446395805e-19)));
	fConst241 = ((fConst42 * (2.13018892093308e-21 - (6.55885525437233e-28 * fConst42))) - 1.16377254046491e-17);
	fConst242 = (2.88801793641772e-21 - (5.32017237321892e-27 * fConst42));
	fConst243 = ((4.70608184474144e-27 * fConst42) - 8.49729834790668e-22);
	fConst244 = ((6.14090528477483e-28 * fConst42) - 2.03828810162705e-21);
	fConst245 = (fConst42 * ((5.6822605863427e-27 * fConst42) - 3.45441468443902e-21));
	fConst246 = (1.16377254046491e-17 + (fConst42 * (1.32422576350594e-21 - (5.02637506090546e-27 * fConst42))));
	fConst247 = ((fConst1 * ((fConst42 * (1.89851835698066e-24 + fConst212)) - 2.42964151251594e-19)) - 4.65509016185963e-18);
	fConst248 = (1.44400896820886e-19 + (fConst42 * (fConst215 - 1.84078473232363e-24)));
	fConst249 = (fConst42 * (1.17130847490806e-23 + fConst218));
	fConst250 = ((fConst42 * (fConst221 - 9.87230001675696e-24)) - 1.44400896820886e-19);
	fConst251 = (fConst1 * (1.39652704855789e-19 + (fConst42 * (fConst224 - 1.19252021399139e-23))));
	fConst252 = (4.65509016185963e-18 + (fConst1 * (1.03311446395805e-19 + (fConst42 * (1.00266837829333e-23 + fConst227)))));
	fConst253 = (4.65509016185963e-18 + (fConst1 * ((fConst1 * ((fConst1 * (fConst229 - 6.32839452326887e-25)) - 1.42012594728872e-21)) - 8.09880504171981e-20)));
	fConst254 = (4.81336322736286e-20 + (fConst1 * (1.35885873441803e-21 + (fConst1 * (6.13594910774543e-25 + fConst231)))));
	fConst255 = (fConst1 * ((fConst1 * (fConst233 - 3.90436158302686e-24)) - 1.92534529094515e-21));
	fConst256 = ((fConst1 * (5.66486556527112e-22 + (fConst1 * (3.29076667225232e-24 + fConst235)))) - 4.81336322736286e-20);
	fConst257 = (fConst1 * (4.65509016185963e-20 + (fConst1 * (2.30294312295935e-21 + (fConst1 * (3.97506737997131e-24 + fConst237))))));
	fConst258 = ((fConst1 * (3.44371487986018e-20 + (fConst1 * ((fConst1 * (fConst239 - 3.34222792764443e-24)) - 8.82817175670626e-22)))) - 4.65509016185963e-18);
	fConst259 = (4.65509016185963e-18 + (fConst1 * (8.09880504171981e-20 + (fConst42 * ((fConst1 * (fConst199 - 2.62354210174893e-28)) - 6.32839452326887e-25)))));
	fConst260 = ((fConst42 * (6.13594910774543e-25 + (fConst1 * (2.45636211390993e-28 - fConst201)))) - 4.81336322736286e-20);
	fConst261 = (fConst42 * ((fConst1 * (fConst203 - 2.12806894928757e-27)) - 3.90436158302686e-24));
	fConst262 = (4.81336322736286e-20 + (fConst42 * (3.29076667225232e-24 + (fConst1 * (1.88243273789657e-27 - fConst205)))));
	fConst263 = (fConst1 * ((fConst42 * (3.97506737997131e-24 + (fConst1 * (2.27290423453708e-27 - fConst207)))) - 4.65509016185963e-20));
	fConst264 = ((fConst1 * ((fConst42 * ((fConst1 * (fConst209 - 2.01055002436219e-27)) - 3.34222792764443e-24)) - 3.44371487986018e-20)) - 4.65509016185963e-18);
	fConst265 = (1.16377254046491e-18 + (fConst1 * (4.0494025208599e-20 + (fConst1 * (3.55031486822181e-22 + (fConst1 * (3.16419726163444e-25 + (fConst1 * (6.55885525437233e-29 - fConst118)))))))));
	fConst266 = (fConst1 * (4.81336322736286e-22 + (fConst1 * (1.95218079151343e-24 + (fConst1 * (5.32017237321892e-28 - fConst122))))));
	fConst267 = (2.40668161368143e-20 + (fConst1 * ((fConst1 * ((fConst1 * (fConst124 - 4.70608184474143e-28)) - 1.64538333612616e-24)) - 1.41621639131778e-22)));
	fConst268 = ((fConst1 * ((fConst1 * ((fConst1 * (fConst120 - 6.14090528477483e-29)) - 3.06797455387272e-25)) - 3.39714683604509e-22)) - 2.40668161368143e-20);
	fConst269 = (fConst1 * ((fConst1 * ((fConst1 * ((fConst1 * (fConst126 - 5.6822605863427e-28)) - 1.98753368998566e-24)) - 5.75735780739837e-22)) - 2.32754508092981e-20));
	fConst270 = ((fConst1 * ((fConst1 * (2.20704293917657e-22 + (fConst1 * (1.67111396382221e-24 + (fConst1 * (5.02637506090546e-28 - fConst128)))))) - 1.72185743993009e-20)) - 1.16377254046491e-18);
	fConst271 = (2.35432599805571e-10 * fConst1);
	fConst272 = (fConst1 * (3.95835848142153e-05 + fConst271));
	fConst273 = (0 - (4.70865199611141e-10 * fConst42));
	fConst274 = (fConst1 * (fConst271 - 3.95835848142153e-05));
	fConst275 = (6.63565399232007e-32 * fConst1);
	fConst276 = ((fConst1 * (1.34864678611246e-17 + (fConst42 * (6.38594307337371e-21 + (fConst1 * (0 - (3.33669303512509e-25 + fConst275))))))) - 5.28173773278557e-16);
	fConst277 = (2.08591410105875e-31 * fConst1);
	fConst278 = ((fConst1 * (2.89345673651624e-32 + (fConst42 * (2.37886542526628e-20 + (fConst1 * (0 - (1.5889843049697e-23 + fConst277))))))) - 1.12367543483752e-30);
	fConst279 = (9.73605165667852e-32 * fConst1);
	fConst280 = ((fConst42 * ((fConst1 * (2.12731524260086e-23 + fConst279)) - 1.71404438329468e-20)) - 5.76394945944764e-48);
	fConst281 = (2.27433891846459e-19 + (fConst42 * ((fConst1 * (0 - (2.12730967258708e-23 + fConst279))) - 2.17574315024051e-23)));
	fConst282 = (9.65513777617002e-32 * fConst1);
	fConst283 = (5.76394945944764e-48 + (fConst42 * ((fConst1 * (1.40466519771019e-26 - fConst282)) - 1.55844935090957e-23)));
	fConst284 = ((fConst42 * (1.7171612819965e-20 + (fConst1 * (fConst282 - 1.40457824963313e-26)))) - 5.76394945944764e-48);
	fConst285 = (2.0839084697653e-31 * fConst1);
	fConst286 = (1.12367543483752e-30 + (fConst1 * ((fConst42 * ((fConst1 * (1.0613306969112e-23 + fConst285)) - 1.8333616527492e-20)) - 1.13716945923258e-19)));
	fConst287 = (2.23856799537003e-31 * fConst1);
	fConst288 = (5.61837717449419e-31 + (fConst1 * ((fConst42 * ((fConst1 * (4.20242371783395e-25 + fConst287)) - 3.28802682791864e-22)) - 3.86637616138982e-18)));
	fConst289 = ((fConst1 * (3.75265921546659e-18 + (fConst42 * ((fConst1 * (0 - (4.20270675485896e-25 + fConst287))) - 4.08986682911218e-23)))) - 5.61837717449419e-31);
	fConst290 = (1.65891349808002e-31 * fConst1);
	fConst291 = ((fConst1 * ((fConst1 * ((fConst1 * (3.19297153668685e-21 + (fConst1 * (4.17086629390636e-25 + fConst290)))) - 3.04772027530973e-17)) - 6.74323393056229e-18)) - 6.60217216598196e-16);
	fConst292 = (5.21478525264688e-31 * fConst1);
	fConst293 = ((fConst1 * ((fConst1 * (1.87939996513735e-21 + (fConst1 * (1.18943271263314e-20 + (fConst1 * (1.98623038121212e-23 + fConst292)))))) - 1.44672836825812e-32)) - 1.4045942935469e-30);
	fConst294 = (2.43401291416963e-31 * fConst1);
	fConst295 = (2.88197472972382e-48 + (fConst1 * ((fConst1 * ((fConst1 * (0 - (2.65914405325108e-23 + fConst294))) - 8.5702219164734e-21)) - 1.20746572084722e-34)));
	fConst296 = ((fConst1 * (1.37461156916708e-20 + (fConst1 * ((fConst1 * (2.65913709073385e-23 + fConst294)) - 1.08787157512025e-23)))) - 1.13716945923229e-19);
	fConst297 = (2.4137844440425e-31 * fConst1);
	fConst298 = ((fConst1 * (1.20746572084722e-34 + (fConst1 * ((fConst1 * (fConst297 - 1.75583149713774e-26)) - 7.79224675454785e-24)))) - 2.88197472972382e-48);
	fConst299 = (2.88197472972382e-48 + (fConst1 * ((fConst1 * (8.5858064099825e-21 + (fConst1 * (1.75572281204141e-26 - fConst297)))) - 1.27264116234178e-31)));
	fConst300 = (5.20977117441325e-31 * fConst1);
	fConst301 = (1.4045942935469e-30 + (fConst1 * (5.68584729616292e-20 + (fConst1 * ((fConst1 * ((fConst1 * (0 - (1.326663371139e-23 + fConst300))) - 9.16680826374599e-21)) - 8.7524578109091e-21)))));
	fConst302 = (5.59641998842507e-31 * fConst1);
	fConst303 = (7.02297146811774e-31 + (fConst1 * (1.93318808069491e-18 + (fConst1 * ((fConst1 * ((fConst1 * (0 - (5.25302964729244e-25 + fConst302))) - 1.64401341395932e-22)) - 3.97206670570346e-20)))));
	fConst304 = ((fConst1 * ((fConst1 * (2.85744520002141e-17 + (fConst1 * ((fConst1 * (5.25338344357369e-25 + fConst302)) - 2.04493341455609e-23)))) - 1.87632960773329e-18)) - 7.02297146811774e-31);
	fConst305 = ((fConst42 * (0 - (1.27718861467474e-20 + (2.21188466410669e-31 * fConst42)))) - 2.69729357222491e-17);
	fConst306 = ((fConst42 * (0 - (4.75773085053256e-20 + (6.95304700352918e-31 * fConst42)))) - 5.78691347303248e-32);
	fConst307 = (2.27433891846517e-19 + (fConst42 * (3.6667233054984e-20 + (6.94636156588433e-31 * fConst42))));
	fConst308 = (3.21837925872334e-31 * fConst42);
	fConst309 = ((fConst42 * (3.11689870181914e-23 - fConst308)) - 1.15278989188953e-47);
	fConst310 = (1.15278989188953e-47 + (fConst42 * (fConst308 - 3.434322563993e-20)));
	fConst311 = (3.24535055222617e-31 * fConst42);
	fConst312 = (1.15278989188953e-47 + (fConst42 * (3.42808876658936e-20 + fConst311)));
	fConst313 = ((fConst42 * (4.35148630048101e-23 - fConst311)) - 4.54867783692918e-19);
	fConst314 = (7.4618933179001e-31 * fConst42);
	fConst315 = (7.73275232277964e-18 + (fConst42 * (6.57605365583729e-22 + fConst314)));
	fConst316 = ((fConst42 * (8.17973365822436e-23 - fConst314)) - 7.50531843093318e-18);
	fConst317 = (6.60217216598196e-16 + (fConst1 * ((fConst1 * (3.04772027530973e-17 + (fConst1 * (3.19297153668685e-21 + (fConst1 * (fConst290 - 4.17086629390636e-25)))))) - 6.74323393056229e-18)));
	fConst318 = (1.4045942935469e-30 + (fConst1 * ((fConst1 * ((fConst1 * (1.18943271263314e-20 + (fConst1 * (fConst292 - 1.98623038121212e-23)))) - 1.87939996513735e-21)) - 1.44672836825812e-32)));
	fConst319 = (2.88197472972382e-48 + (fConst1 * (1.20746572084722e-34 + (fConst1 * ((fConst1 * (2.65914405325108e-23 - fConst294)) - 8.5702219164734e-21)))));
	fConst320 = ((fConst1 * ((fConst1 * ((fConst1 * (fConst294 - 2.65913709073385e-23)) - 1.08787157512025e-23)) - 1.37461156916708e-20)) - 1.13716945923229e-19);
	fConst321 = ((fConst1 * ((fConst1 * ((fConst1 * (1.75583149713774e-26 + fConst297)) - 7.79224675454785e-24)) - 1.20746572084722e-34)) - 2.88197472972382e-48);
	fConst322 = (2.88197472972382e-48 + (fConst1 * (1.27264116234178e-31 + (fConst1 * (8.5858064099825e-21 + (fConst1 * (0 - (1.75572281204141e-26 + fConst297))))))));
	fConst323 = ((fConst1 * (5.68584729616292e-20 + (fConst1 * (8.7524578109091e-21 + (fConst1 * ((fConst1 * (1.326663371139e-23 - fConst300)) - 9.16680826374599e-21)))))) - 1.4045942935469e-30);
	fConst324 = ((fConst1 * (1.93318808069491e-18 + (fConst1 * (3.97206670570346e-20 + (fConst1 * ((fConst1 * (5.25302964729244e-25 - fConst302)) - 1.64401341395932e-22)))))) - 7.02297146811774e-31);
	fConst325 = (7.02297146811774e-31 + (fConst1 * ((fConst1 * ((fConst1 * ((fConst1 * (fConst302 - 5.25338344357369e-25)) - 2.04493341455609e-23)) - 2.85744520002141e-17)) - 1.87632960773329e-18)));
	fConst326 = (5.28173773278557e-16 + (fConst1 * (1.34864678611246e-17 + (fConst42 * (6.38594307337371e-21 + (fConst1 * (3.33669303512509e-25 - fConst275)))))));
	fConst327 = (1.12367543483752e-30 + (fConst1 * (2.89345673651624e-32 + (fConst42 * (2.37886542526628e-20 + (fConst1 * (1.5889843049697e-23 - fConst277)))))));
	fConst328 = ((fConst42 * ((fConst1 * (fConst279 - 2.12731524260086e-23)) - 1.71404438329468e-20)) - 5.76394945944764e-48);
	fConst329 = (2.27433891846459e-19 + (fConst42 * ((fConst1 * (2.12730967258708e-23 - fConst279)) - 2.17574315024051e-23)));
	fConst330 = (5.76394945944764e-48 + (fConst42 * ((fConst1 * (0 - (1.40466519771019e-26 + fConst282))) - 1.55844935090957e-23)));
	fConst331 = ((fConst42 * (1.7171612819965e-20 + (fConst1 * (1.40457824963313e-26 + fConst282)))) - 5.76394945944764e-48);
	fConst332 = ((fConst1 * ((fConst42 * ((fConst1 * (fConst285 - 1.0613306969112e-23)) - 1.8333616527492e-20)) - 1.13716945923258e-19)) - 1.12367543483752e-30);
	fConst333 = ((fConst1 * ((fConst42 * ((fConst1 * (fConst287 - 4.20242371783395e-25)) - 3.28802682791864e-22)) - 3.86637616138982e-18)) - 5.61837717449419e-31);
	fConst334 = (5.61837717449419e-31 + (fConst1 * (3.75265921546659e-18 + (fConst42 * ((fConst1 * (4.20270675485896e-25 - fConst287)) - 4.08986682911218e-23)))));
	fConst335 = (1.32043443319639e-16 + (fConst1 * (6.74323393056229e-18 + (fConst1 * ((fConst1 * ((fConst1 * (fConst17 - 8.34173258781271e-26)) - 3.19297153668685e-21)) - 1.01590675843658e-17)))));
	fConst336 = (2.80918858709381e-31 + (fConst1 * (1.44672836825812e-32 + (fConst1 * (6.26466655045784e-22 + (fConst1 * ((fConst1 * (fConst19 - 3.97246076242424e-24)) - 1.18943271263314e-20)))))));
	fConst337 = ((fConst1 * ((fConst1 * (8.5702219164734e-21 + (fConst1 * (5.31828810650215e-24 - fConst21)))) - 4.02488573615741e-35)) - 2.88197472972382e-48);
	fConst338 = (1.13716945923229e-19 + (fConst1 * (4.58203856389025e-21 + (fConst1 * (1.08787157512025e-23 + (fConst1 * (fConst21 - 5.31827418146769e-24)))))));
	fConst339 = (2.88197472972382e-48 + (fConst1 * (4.02488573615741e-35 + (fConst1 * (7.79224675454785e-24 + (fConst1 * (3.51166299427547e-27 + fConst24)))))));
	fConst340 = ((fConst1 * ((fConst1 * ((fConst1 * (0 - (3.51144562408283e-27 + fConst24))) - 8.5858064099825e-21)) - 4.24213720780592e-32)) - 2.88197472972382e-48);
	fConst341 = ((fConst1 * ((fConst1 * ((fConst1 * (9.16680826374599e-21 + (fConst1 * (2.653326742278e-24 - fConst27)))) - 2.9174859369697e-21)) - 5.68584729616292e-20)) - 2.80918858709381e-31);
	fConst342 = ((fConst1 * ((fConst1 * ((fConst1 * (1.64401341395932e-22 + (fConst1 * (1.05060592945849e-25 - fConst29)))) - 1.32402223523449e-20)) - 1.93318808069491e-18)) - 1.40459429362355e-31);
	fConst343 = (1.40459429362355e-31 + (fConst1 * (1.87632960773329e-18 + (fConst1 * (9.5248173334047e-18 + (fConst1 * (2.04493341455609e-23 + (fConst1 * (fConst29 - 1.05067668871474e-25)))))))));
	fConst344 = (3.2994570111895e-44 * fConst1);
	fConst345 = (1.965162575555e-11 + (fConst1 * ((fConst1 * (1.56820141332437e-15 + (fConst1 * ((fConst1 * (7.24921220605453e-22 + (fConst1 * ((fConst1 * (2.92933985676268e-29 + (fConst1 * ((fConst1 * (5.53932651773327e-39 - fConst344)) - 5.39943887051256e-34)))) - 4.71020790798528e-25)))) - 1.33662641707101e-18)))) - 4.54965157083591e-13)));
	fConst346 = (2.96951131007055e-43 * fConst1);
	fConst347 = (1.7686463179995e-10 + (fConst1 * ((fConst1 * (7.84100706662183e-15 + (fConst1 * ((fConst1 * (7.24921220605453e-22 + (fConst1 * (4.71020790798528e-25 + (fConst1 * ((fConst1 * (2.69971943525628e-33 + (fConst1 * (fConst346 - 3.87752856241329e-38)))) - 8.78801957028804e-29)))))) - 4.00987925121303e-18)))) - 3.18475609958514e-12)));
	fConst348 = (1.18780452402822e-42 * fConst1);
	fConst349 = (7.07458527199799e-10 + (fConst1 * ((fConst1 * (1.25456113065949e-14 + (fConst42 * ((fConst1 * (1.88408316319411e-24 + (fConst42 * ((fConst1 * (1.10786530354665e-37 - fConst348)) - 4.31955109641004e-33)))) - 2.89968488242181e-21)))) - 9.09930314167182e-12)));
	fConst350 = (2.77154388939918e-42 * fConst1);
	fConst351 = (1.6507365634662e-09 + (fConst1 * ((fConst42 * (1.06930113365681e-17 + (fConst1 * ((fConst1 * ((fConst1 * (2.34347188541014e-28 + (fConst42 * (fConst350 - 1.55101142496532e-37)))) - 1.88408316319411e-24)) - 2.89968488242181e-21)))) - 1.27390243983405e-11)));
	fConst352 = (4.15731583409877e-42 * fConst1);
	fConst353 = (2.4761048451993e-09 + (fConst1 * ((fConst1 * ((fConst1 * (8.01975850242606e-18 + (fConst1 * (4.34952732363272e-21 + (fConst1 * ((fConst1 * ((fConst1 * (7.55921441871758e-33 + (fConst1 * (7.75505712482658e-38 - fConst352)))) - 1.75760391405761e-28)) - 2.82612474479117e-24)))))) - 2.19548197865411e-14)) - 6.36951219917027e-12)));
	fConst354 = (2.4761048451993e-09 + (fConst1 * (6.36951219917027e-12 + (fConst1 * ((fConst1 * ((fConst1 * (4.34952732363272e-21 + (fConst1 * (2.82612474479117e-24 + (fConst1 * ((fConst1 * ((fConst1 * (7.75505712482658e-38 + fConst352)) - 7.55921441871758e-33)) - 1.75760391405761e-28)))))) - 8.01975850242606e-18)) - 2.19548197865411e-14)))));
	fConst355 = (1.6507365634662e-09 + (fConst1 * (1.27390243983405e-11 + (fConst42 * ((fConst1 * ((fConst1 * (1.88408316319411e-24 + (fConst1 * (2.34347188541014e-28 + (fConst42 * (0 - (1.55101142496532e-37 + fConst350))))))) - 2.89968488242181e-21)) - 1.06930113365681e-17)))));
	fConst356 = (7.07458527199799e-10 + (fConst1 * (9.09930314167182e-12 + (fConst1 * (1.25456113065949e-14 + (fConst42 * ((fConst1 * ((fConst42 * (4.31955109641004e-33 + (fConst1 * (1.10786530354665e-37 + fConst348)))) - 1.88408316319411e-24)) - 2.89968488242181e-21)))))));
	fConst357 = (1.7686463179995e-10 + (fConst1 * (3.18475609958514e-12 + (fConst1 * (7.84100706662183e-15 + (fConst1 * (4.00987925121303e-18 + (fConst1 * (7.24921220605453e-22 + (fConst1 * ((fConst1 * ((fConst1 * ((fConst1 * (0 - (3.87752856241329e-38 + fConst346))) - 2.69971943525628e-33)) - 8.78801957028804e-29)) - 4.71020790798528e-25)))))))))));
	fConst358 = (1.965162575555e-11 + (fConst1 * (4.54965157083591e-13 + (fConst1 * (1.56820141332437e-15 + (fConst1 * (1.33662641707101e-18 + (fConst1 * (7.24921220605453e-22 + (fConst1 * (4.71020790798528e-25 + (fConst1 * (2.92933985676268e-29 + (fConst1 * (5.39943887051256e-34 + (fConst1 * (5.53932651773327e-39 + fConst344)))))))))))))))));
	fConst359 = (1.0 / fConst358);
	fConst360 = (4.33054407650898e-10 * fConst1);
	fConst361 = (1.22474303201741e-06 + (fConst1 * (fConst360 - 4.66962506103765e-08)));
	fConst362 = (2.44948606403482e-06 - (8.66108815301797e-10 * fConst42));
	fConst363 = (1.0 / (1.22474303201741e-06 + (fConst1 * (4.66962506103765e-08 + fConst360))));
	fConst364 = (0 - (1.8228725842454359e-09 * fConst42));
	fConst365 = (3.6457451684908805e-09 * fConst42);
	fConst366 = (2.57842436032791e-36 * fConst1);
	fConst367 = ((fConst1 * (5.04502665280667e-16 + (fConst1 * ((fConst1 * (2.08441605187173e-22 + (fConst1 * ((fConst1 * (8.60892005839271e-32 - fConst366)) - 9.79448180087853e-27)))) - 9.76565695300569e-20)))) - 1.67475323755367e-13);
	fConst368 = (1.28921218016396e-35 * fConst1);
	fConst369 = ((fConst1 * (2.52251332640334e-15 + (fConst1 * ((fConst1 * (2.08441605187173e-22 + (fConst1 * (9.79448180087853e-27 + (fConst1 * (fConst368 - 2.58267601751781e-31)))))) - 2.92969708590171e-19)))) - 1.17232726628757e-12);
	fConst370 = (2.06273948826233e-35 * fConst42);
	fConst371 = ((fConst1 * (4.03602132224534e-15 + (fConst42 * ((fConst1 * (3.91779272035141e-26 - fConst370)) - 8.33766420748692e-22)))) - 3.34950647510734e-12);
	fConst372 = (6.88713604671417e-31 * fConst1);
	fConst373 = ((fConst42 * (7.81252556240455e-19 + (fConst1 * ((fConst1 * (fConst372 - 3.91779272035141e-26)) - 8.33766420748692e-22)))) - 4.68930906515027e-12);
	fConst374 = (3.60979410445908e-35 * fConst1);
	fConst375 = ((fConst1 * ((fConst1 * (5.85939417180341e-19 + (fConst1 * (1.25064963112304e-21 + (fConst1 * ((fConst1 * (fConst374 - 5.16535203503562e-31)) - 5.87668908052712e-26)))))) - 7.06303731392934e-15)) - 2.34465453257514e-12);
	fConst376 = (2.34465453257514e-12 + (fConst1 * ((fConst1 * ((fConst1 * (1.25064963112304e-21 + (fConst1 * (5.87668908052712e-26 + (fConst1 * (0 - (5.16535203503562e-31 + fConst374))))))) - 5.85939417180341e-19)) - 7.06303731392934e-15)));
	fConst377 = (4.68930906515027e-12 + (fConst42 * ((fConst1 * ((fConst1 * (3.91779272035141e-26 + fConst372)) - 8.33766420748692e-22)) - 7.81252556240455e-19)));
	fConst378 = (3.34950647510734e-12 + (fConst1 * (4.03602132224534e-15 + (fConst42 * ((fConst1 * (fConst370 - 3.91779272035141e-26)) - 8.33766420748692e-22)))));
	fConst379 = (1.17232726628757e-12 + (fConst1 * (2.52251332640334e-15 + (fConst1 * (2.92969708590171e-19 + (fConst1 * (2.08441605187173e-22 + (fConst1 * ((fConst1 * (0 - (2.58267601751781e-31 + fConst368))) - 9.79448180087853e-27)))))))));
	fConst380 = (1.67475323755367e-13 + (fConst1 * (5.04502665280667e-16 + (fConst1 * (9.76565695300569e-20 + (fConst1 * (2.08441605187173e-22 + (fConst1 * (9.79448180087853e-27 + (fConst1 * (8.60892005839271e-32 + fConst366)))))))))));
	fConst381 = (fConst1 / fConst358);
	clear_state_f();
}

void Dsp::init_static(uint32_t samplingFreq, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->init(samplingFreq);
}

void always_inline Dsp::compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0)
{
#define fslider0 (*fslider0_)
#define fslider1 (*fslider1_)
#define fslider2 (*fslider2_)
#define fslider3 (*fslider3_)
#define fslider4 (*fslider4_)
	double 	fSlow0 = (0.007000000000000006 * (1 - double(fslider0)));
	double 	fSlow1 = (0.007000000000000006 * double(fslider1));
	double 	fSlow2 = (0.007000000000000006 * (1 - double(fslider2)));
	double 	fSlow3 = (0.007000000000000006 * (1 - double(fslider3)));
	int 	iSlow4 = int(double(fslider4));
	int ReCount = count;
	if (fact>1) {
		ReCount = count/fact ;
	}
	FAUSTFLOAT buf[ReCount];
	if (fact>1) {
		smp.down(ReCount, input0, buf);
	} else {
		memcpy(buf, input0, count*sizeof(float));
	}
	for (int i=0; i<ReCount; i++) {
		fRec0[0] = ((0.993 * fRec0[1]) + fSlow0);
		fRec1[0] = ((0.993 * fRec1[1]) + fSlow1);
		double fTemp0 = (((fRec0[0] * ((fConst16 * fRec0[0]) + fConst15)) + (fRec1[0] * (((fRec0[0] * ((fConst13 * fRec0[0]) + fConst12)) + (fRec1[0] * ((fRec0[0] * ((fConst10 * fRec0[0]) + fConst9)) + fConst7))) + fConst5))) + fConst3);
		fRec6[0] = ((0.993 * fRec6[1]) + fSlow2);
		fRec7[0] = ((0.993 * fRec7[1]) + fSlow3);
		double fTemp1 = (1.25571983620331e-15 + (fConst1 * (((fRec7[0] * (fConst117 + (fConst1 * (fRec6[0] * (fConst115 + (fConst113 * fRec6[0])))))) + (fRec6[0] * (fConst111 + (fConst109 * fRec6[0])))) + fConst107)));
		double fTemp2 = (double)buf[i];
		fVec0[0] = fTemp2;
		fRec9[0] = (fConst198 * ((fVec0[0] - fVec0[1]) + (fConst197 * fRec9[1])));
		fRec8[0] = (fRec9[0] - (((((((((fRec8[1] * (1.00457586896265e-14 + (fConst1 * (((fRec7[0] * (fConst195 + (fConst1 * (fRec6[0] * (fConst194 + (fConst193 * fRec6[0])))))) + (fRec6[0] * (fConst192 + (fConst191 * fRec6[0])))) + fConst190)))) + (fRec8[2] * (3.51601554136928e-14 + (fConst1 * (((fRec7[0] * (fConst189 + (fConst1 * (fRec6[0] * (fConst188 + (fConst187 * fRec6[0])))))) + (fRec6[0] * (fConst186 + (fConst185 * fRec6[0])))) + fConst184))))) + (fRec8[3] * (7.03203108273855e-14 + (fConst1 * (((fRec7[0] * (fConst183 + (fConst1 * (fRec6[0] * (fConst182 + (fConst181 * fRec6[0])))))) + (fRec6[0] * (fConst180 + (fConst179 * fRec6[0])))) + fConst178))))) + (fRec8[4] * (8.79003885342319e-14 + (fConst42 * (((fRec7[0] * ((fRec6[0] * (fConst177 + (fConst176 * fRec6[0]))) + fConst175)) + (fRec6[0] * (fConst174 + (fConst173 * fRec6[0])))) + fConst172))))) + (fRec8[5] * (7.03203108273855e-14 + (fConst1 * (((fRec7[0] * (fConst171 + (fConst1 * (fRec6[0] * (fConst169 + (fConst167 * fRec6[0])))))) + (fRec6[0] * (fConst165 + (fConst163 * fRec6[0])))) + fConst161))))) + (fRec8[6] * (3.51601554136928e-14 + (fConst1 * (((fRec7[0] * (fConst159 + (fConst1 * (fRec6[0] * (fConst157 + (fConst155 * fRec6[0])))))) + (fRec6[0] * (fConst153 + (fConst151 * fRec6[0])))) + fConst149))))) + (fRec8[7] * (1.00457586896265e-14 + (fConst1 * (((fRec7[0] * (fConst147 + (fConst1 * (fRec6[0] * (fConst145 + (fConst143 * fRec6[0])))))) + (fRec6[0] * (fConst141 + (fConst139 * fRec6[0])))) + fConst137))))) + (fRec8[8] * (1.25571983620331e-15 + (fConst1 * (((fRec7[0] * (fConst135 + (fConst1 * (fRec6[0] * (fConst134 + (fConst133 * fRec6[0])))))) + (fRec6[0] * (fConst132 + (fConst131 * fRec6[0])))) + fConst130))))) / fTemp1));
		double fTemp3 = ((((((((((fRec8[0] * (((fRec6[0] * (fConst270 + (fConst269 * fRec6[0]))) + (fConst1 * (fRec7[0] * (fConst268 + (fRec6[0] * (fConst267 + (fConst266 * fRec6[0]))))))) + fConst265)) + (fRec8[1] * (((fRec6[0] * (fConst264 + (fConst263 * fRec6[0]))) + (fConst1 * (fRec7[0] * ((fRec6[0] * (fConst262 + (fConst261 * fRec6[0]))) + fConst260)))) + fConst259))) + (fRec8[2] * (((fRec6[0] * (fConst258 + (fConst257 * fRec6[0]))) + (fConst1 * (fRec7[0] * ((fRec6[0] * (fConst256 + (fConst255 * fRec6[0]))) + fConst254)))) + fConst253))) + (fRec8[3] * (((fRec6[0] * (fConst252 + (fConst251 * fRec6[0]))) + (fConst1 * (fRec7[0] * ((fRec6[0] * (fConst250 + (fConst249 * fRec6[0]))) + fConst248)))) + fConst247))) + (fRec8[4] * (((fRec6[0] * (fConst246 + (fConst245 * fRec6[0]))) + (fConst42 * (fRec7[0] * (fConst244 + (fRec6[0] * (fConst243 + (fConst242 * fRec6[0]))))))) + fConst241))) + (fRec8[5] * (((fRec6[0] * (fConst240 + (fConst238 * fRec6[0]))) + (fConst1 * (fRec7[0] * ((fRec6[0] * (fConst236 + (fConst234 * fRec6[0]))) + fConst232)))) + fConst230))) + (fRec8[6] * (((fRec6[0] * (fConst228 + (fConst225 * fRec6[0]))) + (fConst1 * (fRec7[0] * ((fRec6[0] * (fConst222 + (fConst219 * fRec6[0]))) + fConst216)))) + fConst213))) + (fRec8[7] * (((fRec6[0] * (fConst210 + (fConst208 * fRec6[0]))) + (fConst1 * (fRec7[0] * ((fRec6[0] * (fConst206 + (fConst204 * fRec6[0]))) + fConst202)))) + fConst200))) + (fRec8[8] * (((fRec6[0] * (fConst129 + (fConst127 * fRec6[0]))) + (fConst1 * (fRec7[0] * ((fRec6[0] * (fConst125 + (fConst123 * fRec6[0]))) + fConst121)))) + fConst119))) / fTemp1);
		fVec1[0] = fTemp3;
		fRec5[0] = (fConst198 * ((fConst197 * fRec5[1]) + (fConst42 * (fVec1[0] - fVec1[1]))));
		fRec4[0] = (fRec5[0] - (fConst105 * ((fConst104 * fRec4[1]) + (fConst103 * fRec4[2]))));
		double fTemp4 = (((fConst274 * fRec4[0]) + (fConst273 * fRec4[1])) + (fConst272 * fRec4[2]));
		fVec2[0] = fTemp4;
		fRec3[0] = (fConst198 * ((fConst197 * fRec3[1]) + (fConst105 * (fVec2[0] - fVec2[1]))));
		fRec2[0] = (fRec3[0] - (((((((fRec2[1] * (((fRec0[0] * ((fConst101 * fRec0[0]) + fConst100)) + (fRec1[0] * (((fRec0[0] * ((fConst99 * fRec0[0]) + fConst98)) + (fRec1[0] * ((fRec0[0] * ((fConst97 * fRec0[0]) + fConst96)) + fConst95))) + fConst94))) + fConst93)) + (fRec2[2] * (((fRec0[0] * ((fConst92 * fRec0[0]) + fConst91)) + (fRec1[0] * (((fRec0[0] * ((fConst90 * fRec0[0]) + fConst89)) + (fRec1[0] * ((fRec0[0] * ((fConst88 * fRec0[0]) + fConst87)) + fConst86))) + fConst85))) + fConst84))) + (fRec2[3] * (((fRec0[0] * ((fConst83 * fRec0[0]) + fConst82)) + (fRec1[0] * (((fRec0[0] * ((fConst80 * fRec0[0]) + fConst79)) + (fRec1[0] * ((fRec0[0] * ((fConst77 * fRec0[0]) + fConst76)) + fConst74))) + fConst73))) + fConst72))) + (fRec2[4] * (((fRec0[0] * ((fConst71 * fRec0[0]) + fConst70)) + (fRec1[0] * (((fRec0[0] * ((fConst68 * fRec0[0]) + fConst67)) + (fRec1[0] * ((fRec0[0] * ((fConst65 * fRec0[0]) + fConst64)) + fConst62))) + fConst60))) + fConst58))) + (fRec2[5] * (((fRec0[0] * ((fConst56 * fRec0[0]) + fConst55)) + (fRec1[0] * (((fRec0[0] * ((fConst53 * fRec0[0]) + fConst52)) + (fRec1[0] * ((fRec0[0] * ((fConst50 * fRec0[0]) + fConst49)) + fConst47))) + fConst45))) + fConst43))) + (fRec2[6] * (((fRec0[0] * ((fConst40 * fRec0[0]) + fConst39)) + (fRec1[0] * (((fRec0[0] * ((fConst38 * fRec0[0]) + fConst37)) + (fRec1[0] * ((fRec0[0] * ((fConst36 * fRec0[0]) + fConst35)) + fConst34))) + fConst33))) + fConst32))) / fTemp0));
		double fTemp5 = ((((((((fRec2[0] * (((fRec0[0] * (fConst343 + (fConst342 * fRec0[0]))) + (fRec1[0] * (((fRec1[0] * (fConst341 + (fConst1 * (fRec0[0] * (fConst340 + (fConst339 * fRec0[0])))))) + (fConst1 * (fRec0[0] * (fConst338 + (fConst337 * fRec0[0]))))) + fConst336))) + fConst335)) + (fRec2[1] * (((fRec0[0] * (fConst334 + (fConst333 * fRec0[0]))) + (fRec1[0] * (((fRec1[0] * (fConst332 + (fConst1 * (fRec0[0] * (fConst331 + (fConst330 * fRec0[0])))))) + (fConst1 * (fRec0[0] * (fConst329 + (fConst328 * fRec0[0]))))) + fConst327))) + fConst326))) + (fRec2[2] * (((fRec0[0] * (fConst325 + (fConst324 * fRec0[0]))) + (fRec1[0] * (((fRec1[0] * (fConst323 + (fConst1 * (fRec0[0] * (fConst322 + (fConst321 * fRec0[0])))))) + (fConst1 * (fRec0[0] * (fConst320 + (fConst319 * fRec0[0]))))) + fConst318))) + fConst317))) + (fConst1 * (fRec2[3] * (((fRec0[0] * (fConst316 + (fConst315 * fRec0[0]))) + (fRec1[0] * (((fRec0[0] * (fConst313 + (fConst312 * fRec0[0]))) + (fRec1[0] * ((fRec0[0] * (fConst310 + (fConst309 * fRec0[0]))) + fConst307))) + fConst306))) + fConst305)))) + (fRec2[4] * (((fRec0[0] * (fConst304 + (fConst303 * fRec0[0]))) + (fRec1[0] * (((fRec1[0] * (fConst301 + (fConst1 * (fRec0[0] * (fConst299 + (fConst298 * fRec0[0])))))) + (fConst1 * (fRec0[0] * (fConst296 + (fConst295 * fRec0[0]))))) + fConst293))) + fConst291))) + (fRec2[5] * (((fRec0[0] * (fConst289 + (fConst288 * fRec0[0]))) + (fRec1[0] * (((fRec1[0] * (fConst286 + (fConst1 * (fRec0[0] * (fConst284 + (fConst283 * fRec0[0])))))) + (fConst1 * (fRec0[0] * (fConst281 + (fConst280 * fRec0[0]))))) + fConst278))) + fConst276))) + (fRec2[6] * (((fRec0[0] * (fConst31 + (fConst30 * fRec0[0]))) + (fRec1[0] * (((fRec1[0] * (fConst28 + (fConst1 * (fRec0[0] * (fConst26 + (fConst25 * fRec0[0])))))) + (fConst1 * (fRec0[0] * (fConst23 + (fConst22 * fRec0[0]))))) + fConst20))) + fConst18))) / fTemp0);
		fVec3[0] = fTemp5;
		fRec13[0] = (fConst198 * ((fConst197 * fRec13[1]) + (fConst1 * (fVec3[0] - fVec3[1]))));
		fRec12[0] = (fRec13[0] - (fConst363 * ((fConst362 * fRec12[1]) + (fConst361 * fRec12[2]))));
		double fTemp6 = (((fConst364 * fRec12[0]) + (fConst365 * fRec12[1])) + (fConst364 * fRec12[2]));
		fVec4[0] = fTemp6;
		fRec11[0] = (fConst198 * ((fConst197 * fRec11[1]) + (fConst363 * (fVec4[0] - fVec4[1]))));
		fRec10[0] = (fRec11[0] - (fConst359 * (((((((((fConst357 * fRec10[1]) + (fConst356 * fRec10[2])) + (fConst355 * fRec10[3])) + (fConst354 * fRec10[4])) + (fConst353 * fRec10[5])) + (fConst351 * fRec10[6])) + (fConst349 * fRec10[7])) + (fConst347 * fRec10[8])) + (fConst345 * fRec10[9]))));
		buf[i] = (FAUSTFLOAT)((iSlow4)?(fConst381 * ((((((((((fConst380 * fRec10[0]) + (fConst379 * fRec10[1])) + (fConst378 * fRec10[2])) + (fConst377 * fRec10[3])) + (fConst376 * fRec10[4])) + (fConst375 * fRec10[5])) + (fConst373 * fRec10[6])) + (fConst371 * fRec10[7])) + (fConst369 * fRec10[8])) + (fConst367 * fRec10[9]))):(fConst1 * fVec3[0]));
		// post processing
		for (int i=9; i>0; i--) fRec10[i] = fRec10[i-1];
		fRec11[1] = fRec11[0];
		fVec4[1] = fVec4[0];
		fRec12[2] = fRec12[1]; fRec12[1] = fRec12[0];
		fRec13[1] = fRec13[0];
		fVec3[1] = fVec3[0];
		for (int i=6; i>0; i--) fRec2[i] = fRec2[i-1];
		fRec3[1] = fRec3[0];
		fVec2[1] = fVec2[0];
		fRec4[2] = fRec4[1]; fRec4[1] = fRec4[0];
		fRec5[1] = fRec5[0];
		fVec1[1] = fVec1[0];
		for (int i=8; i>0; i--) fRec8[i] = fRec8[i-1];
		fRec9[1] = fRec9[0];
		fVec0[1] = fVec0[0];
		fRec7[1] = fRec7[0];
		fRec6[1] = fRec6[0];
		fRec1[1] = fRec1[0];
		fRec0[1] = fRec0[0];
	}
	if (fact>1) {
		smp.up(ReCount, buf, output0);
	} else {
		memcpy(output0, buf, count*sizeof(float));
	}
#undef fslider0
#undef fslider1
#undef fslider2
#undef fslider3
#undef fslider4
}
		
void __rt_func Dsp::compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->compute(count, input0, output0);
}


void Dsp::connect(uint32_t port,void* data)
{
	switch ((PortIndex)port)
	{
	case BASS: 
		fslider0_ = (float*)data; // , 0.5, 0.0, 1.0, 0.01 
		break;
	// static const value_pair fslider4_values[] = {{"ON"},{"OFF"},{0}};
	case CAB: 
		fslider4_ = (float*)data; // , 0.0, 0.0, 1.0, 1.0 
		break;
	case MID: 
		fslider3_ = (float*)data; // , 0.5, 0.0, 1.0, 0.01 
		break;
	case TREBLE: 
		fslider1_ = (float*)data; // , 0.5, 0.0, 1.0, 0.01 
		break;
	case VOLUME: 
		fslider2_ = (float*)data; // , 0.5, 0.0, 1.0, 0.01 
		break;
	default:
		break;
	}
}

void Dsp::connect_static(uint32_t port,void* data, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->connect(port, data);
}


PluginLV2 *plugin() {
	return new Dsp();
}

void Dsp::del_instance(PluginLV2 *p)
{
	delete static_cast<Dsp*>(p);
}

/*
typedef enum
{
   BASS, 
   CAB, 
   MID, 
   TREBLE, 
   VOLUME, 
} PortIndex;
*/

} // end namespace voxbass
