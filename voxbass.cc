// generated from file './/voxbass.dsp' by dsp2cc:
// Code generated with Faust 0.9.73 (http://faust.grame.fr)


namespace voxbass {

class Dsp: public PluginLV2 {
private:
	uint32_t fSamplingFreq;
	double 	fConst0;
	double 	fConst1;
	double 	fConst2;
	double 	fConst3;
	double 	fConst4;
	double 	fConst5;
	double 	fConst6;
	double 	fConst7;
	double 	fConst8;
	FAUSTFLOAT 	fslider0;
	FAUSTFLOAT	*fslider0_;
	double 	fRec0[2];
	double 	fConst9;
	FAUSTFLOAT 	fslider1;
	FAUSTFLOAT	*fslider1_;
	double 	fRec1[2];
	double 	fConst10;
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
	FAUSTFLOAT 	fslider2;
	FAUSTFLOAT	*fslider2_;
	double 	fRec4[2];
	double 	fConst107;
	double 	fConst108;
	double 	fConst109;
	double 	fConst110;
	double 	fConst111;
	double 	fConst112;
	double 	fConst113;
	double 	fConst114;
	double 	fConst115;
	double 	fConst116;
	FAUSTFLOAT 	fslider3;
	FAUSTFLOAT	*fslider3_;
	double 	fRec5[2];
	double 	fConst117;
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
	double 	fRec6[9];
	double 	fConst195;
	double 	fConst196;
	double 	fConst197;
	double 	fConst198;
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
	double 	fRec3[3];
	double 	fConst267;
	double 	fConst268;
	double 	fConst269;
	double 	fConst270;
	double 	fRec2[7];
	double 	fConst271;
	double 	fConst272;
	double 	fConst273;
	double 	fConst274;
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
	for (int i=0; i<2; i++) fRec4[i] = 0;
	for (int i=0; i<2; i++) fRec5[i] = 0;
	for (int i=0; i<9; i++) fRec6[i] = 0;
	for (int i=0; i<3; i++) fRec3[i] = 0;
	for (int i=0; i<7; i++) fRec2[i] = 0;
}

void Dsp::clear_state_f_static(PluginLV2 *p)
{
	static_cast<Dsp*>(p)->clear_state_f();
}

inline void Dsp::init(uint32_t samplingFreq)
{
	fSamplingFreq = samplingFreq;
	fConst0 = double(min(192000, max(1, fSamplingFreq)));
	fConst1 = (4.13550981986041e-30 * fConst0);
	fConst2 = ((fConst0 * (3.13551886117859e-16 + (fConst0 * (1.06164545413707e-16 + (fConst0 * (2.77441101009661e-18 + (fConst0 * (8.04822170327264e-21 + (fConst0 * (1.84390744000983e-24 + fConst1)))))))))) - 1.24923251917087e-28);
	fConst3 = (1.64707043831756e-29 * fConst0);
	fConst4 = ((fConst0 * (6.44448897772097e-31 + (fConst0 * (2.95508605733656e-31 + (fConst0 * (3.66244113144402e-20 + (fConst0 * ((fConst0 * (2.42868964613229e-24 + fConst3)) - 6.97773515189924e-22)))))))) - 3.40368577629377e-43);
	fConst5 = (1.64712701789358e-29 * fConst0);
	fConst6 = (2.6915808669567e-43 + (fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * (0 - (3.94190757723752e-24 + fConst5))) - 2.43109507427627e-21)) - 6.41244703591706e-20)) - 1.35016786829611e-19)) - 6.13280679578764e-31)));
	fConst7 = (7.52344369779261e-30 * fConst0);
	fConst8 = ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * (0 - (5.70763123290691e-25 + fConst7))) - 1.07517633440933e-20)) - 4.93626014624563e-32)) - 3.82718419752065e-34)) - 1.97683409833458e-45)) - 1.41549010076907e-58);
	fConst9 = (5.54344948298749e-71 + (fConst0 * (4.93534556811339e-58 + (fConst0 * ((fConst0 * (3.95021554381384e-33 + (fConst0 * (9.11675875431262e-22 + (fConst0 * (5.70759444036171e-25 + fConst7)))))) - 3.43238652759687e-45)))));
	fConst10 = (7.52116108828788e-30 * fConst0);
	fConst11 = (3.38724285425653e-45 + (fConst0 * ((fConst0 * (2.70033573658755e-19 + (fConst0 * (5.50001180895154e-20 + (fConst0 * (9.15322513733459e-22 + (fConst0 * (fConst10 - 5.53401459960655e-24)))))))) - 6.23364363866714e-32)));
	fConst12 = (1.41549010076796e-58 + (fConst0 * (1.97683409833359e-45 + (fConst0 * (3.82718419774764e-34 + (fConst0 * ((fConst0 * (8.92841159323076e-21 + (fConst0 * (5.53403450077627e-24 - fConst10)))) - 7.14983179413217e-33)))))));
	fConst13 = (1.53982942201209e-29 * fConst0);
	fConst14 = ((fConst0 * ((fConst0 * (4.30444062429748e-18 + (fConst0 * (1.19612956111896e-17 + (fConst0 * (1.2277712835055e-20 + (fConst0 * (7.03225420365346e-24 + fConst13)))))))) - 1.062391389923e-30)) - 1.03650419311251e-43);
	fConst15 = (1.33732232641662e-43 + (fConst0 * (1.51803227830183e-30 + (fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * (0 - (7.03226223466348e-24 + fConst13))) - 1.2065713966488e-20)) - 1.0751631223747e-18)) - 4.43945741113035e-18)))));
	fConst16 = (1.26856097503084e-32 * fConst0);
	fConst17 = ((fConst0 * (7.73476124064158e-18 + (fConst0 * (1.16527744088298e-17 + (fConst0 * ((fConst0 * (9.56823113983053e-26 + fConst16)) - 3.66244007061449e-21)))))) - 1.51458773356024e-16);
	fConst18 = (3.98771402617878e-32 * fConst0);
	fConst19 = ((fConst0 * (1.65945574304514e-32 + (fConst0 * ((fConst0 * ((fConst0 * (4.55653915380135e-24 + fConst18)) - 1.36431725582145e-20)) - 7.18580709017103e-22)))) - 3.22224448886125e-31);
	fConst20 = (1.86127341409698e-32 * fConst0);
	fConst21 = ((fConst0 * (4.61669463602886e-35 + (fConst0 * (9.83031789875016e-21 + (fConst0 * (0 - (6.10024609084207e-24 + fConst20))))))) - 3.30573291966029e-48);
	fConst22 = (1.30437594675812e-19 + (fConst0 * ((fConst0 * (1.24783053865278e-23 + (fConst0 * (6.10023011825936e-24 + fConst20)))) - 5.25578653814051e-21)));
	fConst23 = (1.84580482701108e-32 * fConst0);
	fConst24 = (3.30573291966029e-48 + (fConst0 * ((fConst0 * (8.93799877873786e-24 + (fConst0 * (fConst23 - 4.02801865237622e-27)))) - 4.61669463602886e-35)));
	fConst25 = ((fConst0 * (4.86586673057942e-32 + (fConst0 * ((fConst0 * (4.02776931989579e-27 - fConst23)) - 9.84819389630763e-21)))) - 3.30573291966029e-48);
	fConst26 = (3.98387979129472e-32 * fConst0);
	fConst27 = (3.22224448886125e-31 + (fConst0 * ((fConst0 * (3.34647397806303e-21 + (fConst0 * (1.05146213965329e-20 + (fConst0 * (0 - (3.04345035015622e-24 + fConst26))))))) - 6.52187973379226e-20)));
	fConst28 = (4.27954802453434e-32 * fConst0);
	fConst29 = (1.61112224451854e-31 + (fConst0 * ((fConst0 * (1.51870414821984e-20 + (fConst0 * (1.88573421366408e-22 + (fConst0 * (0 - (1.20507777142541e-25 + fConst28))))))) - 2.21743910948881e-18)));
	fConst30 = ((fConst0 * (2.15222031215091e-18 + (fConst0 * ((fConst0 * (2.34561864056598e-23 + (fConst0 * (1.20515893517956e-25 + fConst28)))) - 1.09252694012443e-17)))) - 1.61112224451854e-31);
	fConst31 = ((fConst0 * ((fConst0 * (1.06164545413707e-16 + (fConst0 * ((fConst0 * (8.04822170327264e-21 + (fConst0 * (fConst1 - 1.84390744000983e-24)))) - 2.77441101009661e-18)))) - 3.13551886117859e-16)) - 1.24923251917087e-28);
	fConst32 = ((fConst0 * ((fConst0 * (2.95508605733656e-31 + (fConst0 * ((fConst0 * ((fConst0 * (fConst3 - 2.42868964613229e-24)) - 6.97773515189924e-22)) - 3.66244113144402e-20)))) - 6.44448897772097e-31)) - 3.40368577629377e-43);
	fConst33 = (2.6915808669567e-43 + (fConst0 * (6.13280679578764e-31 + (fConst0 * ((fConst0 * (6.41244703591706e-20 + (fConst0 * ((fConst0 * (3.94190757723752e-24 - fConst5)) - 2.43109507427627e-21)))) - 1.35016786829611e-19)))));
	fConst34 = ((fConst0 * (1.97683409833458e-45 + (fConst0 * ((fConst0 * (4.93626014624563e-32 + (fConst0 * ((fConst0 * (5.70763123290691e-25 - fConst7)) - 1.07517633440933e-20)))) - 3.82718419752065e-34)))) - 1.41549010076907e-58);
	fConst35 = (5.54344948298749e-71 + (fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * (9.11675875431262e-22 + (fConst0 * (fConst7 - 5.70759444036171e-25)))) - 3.95021554381384e-33)) - 3.43238652759687e-45)) - 4.93534556811339e-58)));
	fConst36 = (3.38724285425653e-45 + (fConst0 * (6.23364363866714e-32 + (fConst0 * (2.70033573658755e-19 + (fConst0 * ((fConst0 * (9.15322513733459e-22 + (fConst0 * (5.53401459960655e-24 + fConst10)))) - 5.50001180895154e-20)))))));
	fConst37 = (1.41549010076796e-58 + (fConst0 * ((fConst0 * (3.82718419774764e-34 + (fConst0 * (7.14983179413217e-33 + (fConst0 * (8.92841159323076e-21 + (fConst0 * (0 - (5.53403450077627e-24 + fConst10))))))))) - 1.97683409833359e-45)));
	fConst38 = ((fConst0 * (1.062391389923e-30 + (fConst0 * (4.30444062429748e-18 + (fConst0 * ((fConst0 * (1.2277712835055e-20 + (fConst0 * (fConst13 - 7.03225420365346e-24)))) - 1.19612956111896e-17)))))) - 1.03650419311251e-43);
	fConst39 = (1.33732232641662e-43 + (fConst0 * ((fConst0 * ((fConst0 * (1.0751631223747e-18 + (fConst0 * ((fConst0 * (7.03226223466348e-24 - fConst13)) - 1.2065713966488e-20)))) - 4.43945741113035e-18)) - 1.51803227830183e-30)));
	fConst40 = (2.48130589191624e-29 * fConst0);
	fConst41 = faustpower<2>(fConst0);
	fConst42 = ((fConst0 * ((fConst0 * (2.12329090827415e-16 + (fConst41 * ((fConst0 * (7.37562976003933e-24 - fConst40)) - 1.60964434065453e-20)))) - 1.25420754447144e-15)) - 7.49539511502524e-28);
	fConst43 = (9.88242262990536e-29 * fConst0);
	fConst44 = ((fConst0 * ((fConst0 * (5.91017211467311e-31 + (fConst41 * (1.39554703037985e-21 + (fConst0 * (9.71475858452917e-24 - fConst43)))))) - 2.57779559108839e-30)) - 2.04221146577626e-42);
	fConst45 = (9.88276210736149e-29 * fConst0);
	fConst46 = (1.61494852017402e-42 + (fConst0 * (2.45312271831506e-30 + (fConst0 * ((fConst41 * (4.86219014855253e-21 + (fConst0 * (fConst45 - 1.57676303089501e-23)))) - 2.70033573659221e-19)))));
	fConst47 = (4.51406621867556e-29 * fConst0);
	fConst48 = ((fConst0 * (7.90733639333831e-45 + (fConst0 * ((fConst41 * (2.15035266881866e-20 + (fConst0 * (fConst47 - 2.28305249316277e-24)))) - 7.65436839504129e-34)))) - 8.4929406046144e-58);
	fConst49 = (3.32606968979249e-70 + (fConst0 * ((fConst0 * ((fConst41 * ((fConst0 * (2.28303777614468e-24 - fConst47)) - 1.82335175086252e-21)) - 6.86477305519374e-45)) - 1.97413822724536e-57)));
	fConst50 = (4.51269665297273e-29 * fConst0);
	fConst51 = (2.03234571255392e-44 + (fConst0 * (2.49345745546686e-31 + (fConst0 * (5.4006714731751e-19 + (fConst41 * ((fConst0 * (0 - (2.21360583984262e-23 + fConst50))) - 1.83064502746692e-21)))))));
	fConst52 = (8.49294060460775e-58 + (fConst0 * ((fConst0 * (7.65436839549527e-34 + (fConst41 * ((fConst0 * (2.21361380031051e-23 + fConst50)) - 1.78568231864615e-20)))) - 7.90733639333436e-45)));
	fConst53 = (9.23897653207256e-29 * fConst0);
	fConst54 = ((fConst0 * (4.24956555969201e-30 + (fConst0 * (8.60888124859496e-18 + (fConst41 * ((fConst0 * (2.81290168146139e-23 - fConst53)) - 2.455542567011e-20)))))) - 6.21902515867503e-43);
	fConst55 = (8.02393395849971e-43 + (fConst0 * ((fConst0 * ((fConst41 * (2.4131427932976e-20 + (fConst0 * (fConst53 - 2.81290489386539e-23)))) - 8.87891482226071e-18)) - 6.07212911320732e-30)));
	fConst56 = (6.20326472979061e-29 * fConst0);
	fConst57 = ((fConst0 * ((fConst0 * ((fConst0 * (8.32323303028982e-18 + (fConst0 * ((fConst0 * (fConst56 - 9.21953720004917e-24)) - 8.04822170327264e-21)))) - 1.06164545413707e-16)) - 1.56775943058929e-15)) - 1.87384877875631e-27);
	fConst58 = (2.47060565747634e-28 * fConst0);
	fConst59 = ((fConst0 * ((fConst0 * ((fConst0 * (1.09873233943321e-19 + (fConst0 * (6.97773515189924e-22 + (fConst0 * (fConst58 - 1.21434482306615e-23)))))) - 2.95508605733656e-31)) - 3.22224448886048e-30)) - 5.10552866444065e-42);
	fConst60 = (2.47069052684037e-28 * fConst0);
	fConst61 = (4.03737130043505e-42 + (fConst0 * (3.06640339789382e-30 + (fConst0 * (1.35016786829611e-19 + (fConst0 * ((fConst0 * (2.43109507427627e-21 + (fConst0 * (1.97095378861876e-23 - fConst60)))) - 1.92373411077512e-19)))))));
	fConst62 = (1.12851655466889e-28 * fConst0);
	fConst63 = ((fConst0 * (9.88417049167289e-45 + (fConst0 * (3.82718419752065e-34 + (fConst0 * ((fConst0 * (1.07517633440933e-20 + (fConst0 * (2.85381561645346e-24 - fConst62)))) - 1.48087804387369e-31)))))) - 2.1232351511536e-57);
	fConst64 = (8.31517422448124e-70 + (fConst0 * ((fConst0 * (3.43238652759687e-45 + (fConst0 * (1.18506466314415e-32 + (fConst0 * ((fConst0 * (fConst62 - 2.85379722018085e-24)) - 9.11675875431262e-22)))))) - 2.46767278405669e-57)));
	fConst65 = (1.12817416324318e-28 * fConst0);
	fConst66 = (5.08086428138479e-44 + (fConst0 * (3.11682181933357e-31 + (fConst0 * ((fConst0 * (1.65000354268546e-19 + (fConst0 * ((fConst0 * (2.76700729980328e-23 + fConst65)) - 9.15322513733459e-22)))) - 2.70033573658755e-19)))));
	fConst67 = (2.12323515115194e-57 + (fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * (0 - (2.76701725038813e-23 + fConst65))) - 8.92841159323076e-21)) - 2.14494953823965e-32)) - 3.82718419774764e-34)) - 9.88417049166796e-45)));
	fConst68 = (2.30974413301814e-28 * fConst0);
	fConst69 = ((fConst0 * (5.31195694961502e-30 + (fConst0 * ((fConst0 * (3.58838868335688e-17 + (fConst0 * ((fConst0 * (fConst68 - 3.51612710182673e-23)) - 1.2277712835055e-20)))) - 4.30444062429748e-18)))) - 1.55475628966876e-42);
	fConst70 = (2.00598348962493e-42 + (fConst0 * ((fConst0 * (4.43945741113035e-18 + (fConst0 * ((fConst0 * (1.2065713966488e-20 + (fConst0 * (3.51613111733174e-23 - fConst68)))) - 3.2254893671241e-18)))) - 7.59016139150915e-30)));
	fConst71 = ((fConst41 * ((fConst41 * (3.21928868130906e-20 - (8.27101963972082e-29 * fConst41))) - 4.24658181654829e-16)) - 2.49846503834175e-27);
	fConst72 = ((fConst41 * ((fConst41 * (0 - (2.7910940607597e-21 + (3.29414087663512e-28 * fConst41)))) - 1.18203442293462e-30)) - 6.80737155258754e-42);
	fConst73 = (5.3831617339134e-42 + (fConst41 * (5.40067147318442e-19 + (fConst41 * ((3.29425403578716e-28 * fConst41) - 9.72438029710506e-21)))));
	fConst74 = (1.50468873955852e-28 * fConst41);
	fConst75 = ((fConst41 * (1.53087367900826e-33 + (fConst41 * (fConst74 - 4.30070533763731e-20)))) - 2.83098020153813e-57);
	fConst76 = (1.1086898965975e-69 + (fConst41 * (1.37295461103875e-44 + (fConst41 * (3.64670350172505e-21 - fConst74)))));
	fConst77 = (1.50423221765758e-28 * fConst41);
	fConst78 = (6.77448570851306e-44 + (fConst41 * ((fConst41 * (3.66129005493384e-21 - fConst77)) - 1.08013429463502e-18)));
	fConst79 = (2.83098020153591e-57 + (fConst41 * ((fConst41 * (3.5713646372923e-20 + fConst77)) - 1.53087367909905e-33)));
	fConst80 = (3.07965884402419e-28 * fConst41);
	fConst81 = ((fConst41 * ((fConst41 * (4.91108513402201e-20 - fConst80)) - 1.72177624971899e-17)) - 2.07300838622501e-42);
	fConst82 = (2.67464465283324e-42 + (fConst41 * (1.77578296445214e-17 + (fConst41 * (fConst80 - 4.8262855865952e-20)))));
	fConst83 = ((fConst0 * (1.56775943058929e-15 + (fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * (9.21953720004917e-24 + fConst56)) - 8.04822170327264e-21)) - 8.32323303028982e-18)) - 1.06164545413707e-16)))) - 1.87384877875631e-27);
	fConst84 = ((fConst0 * (3.22224448886048e-30 + (fConst0 * ((fConst0 * ((fConst0 * (6.97773515189924e-22 + (fConst0 * (1.21434482306615e-23 + fConst58)))) - 1.09873233943321e-19)) - 2.95508605733656e-31)))) - 5.10552866444065e-42);
	fConst85 = (4.03737130043505e-42 + (fConst0 * ((fConst0 * (1.35016786829611e-19 + (fConst0 * (1.92373411077512e-19 + (fConst0 * (2.43109507427627e-21 + (fConst0 * (0 - (1.97095378861876e-23 + fConst60))))))))) - 3.06640339789382e-30)));
	fConst86 = ((fConst0 * ((fConst0 * (3.82718419752065e-34 + (fConst0 * (1.48087804387369e-31 + (fConst0 * (1.07517633440933e-20 + (fConst0 * (0 - (2.85381561645346e-24 + fConst62))))))))) - 9.88417049167289e-45)) - 2.1232351511536e-57);
	fConst87 = (8.31517422448124e-70 + (fConst0 * (2.46767278405669e-57 + (fConst0 * (3.43238652759687e-45 + (fConst0 * ((fConst0 * ((fConst0 * (2.85379722018085e-24 + fConst62)) - 9.11675875431262e-22)) - 1.18506466314415e-32)))))));
	fConst88 = (5.08086428138479e-44 + (fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * (fConst65 - 2.76700729980328e-23)) - 9.15322513733459e-22)) - 1.65000354268546e-19)) - 2.70033573658755e-19)) - 3.11682181933357e-31)));
	fConst89 = (2.12323515115194e-57 + (fConst0 * (9.88417049166796e-45 + (fConst0 * ((fConst0 * (2.14494953823965e-32 + (fConst0 * ((fConst0 * (2.76701725038813e-23 - fConst65)) - 8.92841159323076e-21)))) - 3.82718419774764e-34)))));
	fConst90 = ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * (3.51612710182673e-23 + fConst68)) - 1.2277712835055e-20)) - 3.58838868335688e-17)) - 4.30444062429748e-18)) - 5.31195694961502e-30)) - 1.55475628966876e-42);
	fConst91 = (2.00598348962493e-42 + (fConst0 * (7.59016139150915e-30 + (fConst0 * (4.43945741113035e-18 + (fConst0 * (3.2254893671241e-18 + (fConst0 * (1.2065713966488e-20 + (fConst0 * (0 - (3.51613111733174e-23 + fConst68))))))))))));
	fConst92 = ((fConst0 * (1.25420754447144e-15 + (fConst0 * (2.12329090827415e-16 + (fConst41 * ((fConst0 * (0 - (7.37562976003933e-24 + fConst40))) - 1.60964434065453e-20)))))) - 7.49539511502524e-28);
	fConst93 = ((fConst0 * (2.57779559108839e-30 + (fConst0 * (5.91017211467311e-31 + (fConst41 * (1.39554703037985e-21 + (fConst0 * (0 - (9.71475858452917e-24 + fConst43))))))))) - 2.04221146577626e-42);
	fConst94 = (1.61494852017402e-42 + (fConst0 * ((fConst0 * ((fConst41 * (4.86219014855253e-21 + (fConst0 * (1.57676303089501e-23 + fConst45)))) - 2.70033573659221e-19)) - 2.45312271831506e-30)));
	fConst95 = ((fConst0 * ((fConst0 * ((fConst41 * (2.15035266881866e-20 + (fConst0 * (2.28305249316277e-24 + fConst47)))) - 7.65436839504129e-34)) - 7.90733639333831e-45)) - 8.4929406046144e-58);
	fConst96 = (3.32606968979249e-70 + (fConst0 * (1.97413822724536e-57 + (fConst0 * ((fConst41 * ((fConst0 * (0 - (2.28303777614468e-24 + fConst47))) - 1.82335175086252e-21)) - 6.86477305519374e-45)))));
	fConst97 = (2.03234571255392e-44 + (fConst0 * ((fConst0 * (5.4006714731751e-19 + (fConst41 * ((fConst0 * (2.21360583984262e-23 - fConst50)) - 1.83064502746692e-21)))) - 2.49345745546686e-31)));
	fConst98 = (8.49294060460775e-58 + (fConst0 * (7.90733639333436e-45 + (fConst0 * (7.65436839549527e-34 + (fConst41 * ((fConst0 * (fConst50 - 2.21361380031051e-23)) - 1.78568231864615e-20)))))));
	fConst99 = ((fConst0 * ((fConst0 * (8.60888124859496e-18 + (fConst41 * ((fConst0 * (0 - (2.81290168146139e-23 + fConst53))) - 2.455542567011e-20)))) - 4.24956555969201e-30)) - 6.21902515867503e-43);
	fConst100 = (8.02393395849971e-43 + (fConst0 * (6.07212911320732e-30 + (fConst0 * ((fConst41 * (2.4131427932976e-20 + (fConst0 * (2.81290489386539e-23 + fConst53)))) - 8.87891482226071e-18)))));
	fConst101 = (2.36301137905642e-10 * fConst0);
	fConst102 = (0.00024035936046162 + (fConst0 * (fConst101 - 9.48587122718622e-06)));
	fConst103 = (0.00048071872092324 - (4.72602275811285e-10 * fConst41));
	fConst104 = (1.0 / (0.00024035936046162 + (fConst0 * (9.48587122718622e-06 + fConst101))));
	fConst105 = (1.92529627659134e-39 * fConst0);
	fConst106 = (3.23357227133522e-16 + (fConst0 * (1.13510423198382e-17 + (fConst0 * (9.51573004877601e-20 + (fConst0 * (1.23489756547062e-22 + (fConst0 * (5.3338333519646e-26 + (fConst0 * (7.06820551701561e-30 + (fConst0 * (2.75588927932986e-34 + fConst105)))))))))))));
	fConst107 = (1.63288633577099e-38 * fConst0);
	fConst108 = (fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * (0 - (2.8886681393884e-33 + fConst107))) - 1.22380298287253e-28)) - 5.97891285045565e-25)) - 6.57559879124984e-22)) - 2.70493592383428e-20)) - 1.10503345585892e-19));
	fConst109 = (1.90156498997068e-38 * fConst0);
	fConst110 = (1.95892294447717e-17 + (fConst0 * (5.09420379958945e-18 + (fConst0 * (1.88951592676649e-19 + (fConst0 * (1.70315358798795e-21 + (fConst0 * (1.27197539082944e-24 + (fConst0 * (1.6275988249883e-28 + (fConst0 * (3.4993097780779e-33 + fConst109)))))))))))));
	fConst111 = (1.45022424488616e-38 * fConst0);
	fConst112 = (fConst0 * (2.28520918671624e-21 + (fConst0 * (4.99352622765038e-22 + (fConst0 * (4.83309951544608e-25 + (fConst0 * (1.07525226870021e-28 + (fConst0 * (2.55893259997086e-33 + fConst111))))))))));
	fConst113 = (1.70915998273057e-38 * fConst0);
	fConst114 = ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * (0 - (3.14082755831951e-33 + fConst113))) - 1.45514899806723e-28)) - 1.11126344104395e-24)) - 1.43632728325539e-21)) - 9.47067849160929e-20)) - 4.05105264917879e-19);
	fConst115 = (1.72896220329133e-39 * fConst0);
	fConst116 = ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * (0 - (2.47057060517596e-34 + fConst115))) - 6.28852429480213e-30)) - 4.66623845928268e-26)) - 1.05878053917009e-22)) - 7.78363208113535e-20)) - 6.00488965844066e-18)) - 2.59682862126846e-17);
	fConst117 = (1.17470552663686e-35 * fConst0);
	fConst118 = (1.16377254046491e-18 + (fConst0 * ((fConst0 * (3.55031486822181e-22 + (fConst0 * ((fConst0 * (6.55885525437233e-29 + fConst117)) - 3.16419726163444e-25)))) - 4.0494025208599e-20)));
	fConst119 = (1.09988351857082e-35 * fConst0);
	fConst120 = (2.40668161368143e-20 + (fConst0 * ((fConst0 * (3.06797455387272e-25 + (fConst0 * (0 - (6.14090528477483e-29 + fConst119))))) - 3.39714683604509e-22)));
	fConst121 = (9.3823923360494e-35 * fConst0);
	fConst122 = (fConst0 * (4.81336322736286e-22 + (fConst0 * ((fConst0 * (5.32017237321892e-28 + fConst121)) - 1.95218079151343e-24))));
	fConst123 = (8.28250881747858e-35 * fConst0);
	fConst124 = ((fConst0 * ((fConst0 * (1.64538333612616e-24 + (fConst0 * (0 - (4.70608184474143e-28 + fConst123))))) - 1.41621639131778e-22)) - 2.40668161368143e-20);
	fConst125 = (1.00206503180936e-34 * fConst0);
	fConst126 = (fConst0 * (2.32754508092981e-20 + (fConst0 * ((fConst0 * (1.98753368998566e-24 + (fConst0 * (0 - (5.6822605863427e-28 + fConst125))))) - 5.75735780739837e-22))));
	fConst127 = (8.84594479145671e-35 * fConst0);
	fConst128 = ((fConst0 * (1.72185743993009e-20 + (fConst0 * (2.20704293917657e-22 + (fConst0 * ((fConst0 * (5.02637506090546e-28 + fConst127)) - 1.67111396382221e-24)))))) - 1.16377254046491e-18);
	fConst129 = ((fConst0 * (1.13510423198382e-17 + (fConst0 * ((fConst0 * (1.23489756547062e-22 + (fConst0 * ((fConst0 * (7.06820551701561e-30 + (fConst0 * (fConst105 - 2.75588927932986e-34)))) - 5.3338333519646e-26)))) - 9.51573004877601e-20)))) - 3.23357227133522e-16);
	fConst130 = (fConst0 * ((fConst0 * (2.70493592383428e-20 + (fConst0 * ((fConst0 * (5.97891285045565e-25 + (fConst0 * ((fConst0 * (2.8886681393884e-33 - fConst107)) - 1.22380298287253e-28)))) - 6.57559879124984e-22)))) - 1.10503345585892e-19));
	fConst131 = ((fConst0 * (5.09420379958945e-18 + (fConst0 * ((fConst0 * (1.70315358798795e-21 + (fConst0 * ((fConst0 * (1.6275988249883e-28 + (fConst0 * (fConst109 - 3.4993097780779e-33)))) - 1.27197539082944e-24)))) - 1.88951592676649e-19)))) - 1.95892294447717e-17);
	fConst132 = (fConst0 * ((fConst0 * (4.99352622765038e-22 + (fConst0 * ((fConst0 * (1.07525226870021e-28 + (fConst0 * (fConst111 - 2.55893259997086e-33)))) - 4.83309951544608e-25)))) - 2.28520918671624e-21));
	fConst133 = ((fConst0 * (9.47067849160929e-20 + (fConst0 * ((fConst0 * (1.11126344104395e-24 + (fConst0 * ((fConst0 * (3.14082755831951e-33 - fConst113)) - 1.45514899806723e-28)))) - 1.43632728325539e-21)))) - 4.05105264917879e-19);
	fConst134 = (2.59682862126846e-17 + (fConst0 * ((fConst0 * (7.78363208113535e-20 + (fConst0 * ((fConst0 * (4.66623845928268e-26 + (fConst0 * ((fConst0 * (2.47057060517596e-34 - fConst115)) - 6.28852429480213e-30)))) - 1.05878053917009e-22)))) - 6.00488965844066e-18)));
	fConst135 = (1.54023702127307e-38 * fConst0);
	fConst136 = ((fConst0 * (4.54041692793529e-17 + (fConst0 * ((fConst41 * (1.06676667039292e-25 + (fConst0 * ((fConst0 * (1.65353356759792e-33 - fConst135)) - 2.82728220680625e-29)))) - 1.9031460097552e-19)))) - 1.94014336280113e-15);
	fConst137 = (1.3063090686168e-37 * fConst0);
	fConst138 = (fConst0 * ((fConst0 * (5.40987184766855e-20 + (fConst41 * ((fConst0 * (4.89521193149012e-28 + (fConst0 * (fConst137 - 1.73320088363304e-32)))) - 1.19578257009113e-24)))) - 4.42013382343566e-19));
	fConst139 = (1.52125199197655e-37 * fConst0);
	fConst140 = ((fConst0 * (2.03768151983578e-17 + (fConst0 * ((fConst41 * (2.54395078165888e-24 + (fConst0 * ((fConst0 * (2.09958586684674e-32 - fConst139)) - 6.5103952999532e-28)))) - 3.77903185353297e-19)))) - 1.1753537666863e-16);
	fConst141 = (1.16017939590893e-37 * fConst0);
	fConst142 = (fConst0 * ((fConst41 * (9.66619903089217e-25 + (fConst0 * ((fConst0 * (1.53535955998251e-32 - fConst141)) - 4.30100907480083e-28)))) - 4.57041837343248e-21));
	fConst143 = (1.36732798618446e-37 * fConst0);
	fConst144 = ((fConst0 * (1.89413569832186e-19 + (fConst41 * ((fConst0 * (5.82059599226893e-28 + (fConst0 * (fConst143 - 1.88449653499171e-32)))) - 2.2225268820879e-24)))) - 1.62042105967152e-18);
	fConst145 = (1.38316976263306e-38 * fConst0);
	fConst146 = (1.55809717276107e-16 + (fConst0 * ((fConst0 * (1.55672641622707e-19 + (fConst41 * ((fConst0 * (2.51540971792085e-29 + (fConst0 * (fConst145 - 1.48234236310557e-33)))) - 9.33247691856536e-26)))) - 2.40195586337626e-17)));
	fConst147 = (5.39082957445574e-38 * fConst0);
	fConst148 = ((fConst0 * (4.54041692793529e-17 + (fConst0 * (1.9031460097552e-19 + (fConst0 * ((fConst0 * (1.06676667039292e-25 + (fConst0 * (2.82728220680625e-29 + (fConst0 * (fConst147 - 3.85824499106181e-33)))))) - 4.93959026188247e-22)))))) - 4.52700117986931e-15);
	fConst149 = (4.57208174015878e-37 * fConst0);
	fConst150 = (fConst0 * ((fConst0 * ((fConst0 * (2.63023951649994e-21 + (fConst0 * ((fConst0 * ((fConst0 * (4.04413539514376e-32 - fConst149)) - 4.89521193149012e-28)) - 1.19578257009113e-24)))) - 5.40987184766855e-20)) - 4.42013382343566e-19));
	fConst151 = (5.32438197191791e-37 * fConst0);
	fConst152 = ((fConst0 * (2.03768151983578e-17 + (fConst0 * (3.77903185353297e-19 + (fConst0 * ((fConst0 * (2.54395078165888e-24 + (fConst0 * (6.5103952999532e-28 + (fConst0 * (fConst151 - 4.89903368930905e-32)))))) - 6.81261435195178e-21)))))) - 2.74249212226804e-16);
	fConst153 = (4.06062788568125e-37 * fConst0);
	fConst154 = (fConst0 * (4.57041837343248e-21 + (fConst0 * ((fConst0 * (9.66619903089217e-25 + (fConst0 * (4.30100907480083e-28 + (fConst0 * (fConst153 - 3.5825056399592e-32)))))) - 1.99741049106015e-21))));
	fConst155 = (4.7856479516456e-37 * fConst0);
	fConst156 = ((fConst0 * ((fConst0 * (5.74530913302157e-21 + (fConst0 * ((fConst0 * ((fConst0 * (4.39715858164732e-32 - fConst155)) - 5.82059599226893e-28)) - 2.2225268820879e-24)))) - 1.89413569832186e-19)) - 1.62042105967152e-18);
	fConst157 = (4.84109416921572e-38 * fConst0);
	fConst158 = (3.63556006977584e-16 + (fConst0 * ((fConst0 * ((fConst0 * (4.23512215668038e-22 + (fConst0 * ((fConst0 * ((fConst0 * (3.45879884724634e-33 - fConst157)) - 2.51540971792085e-29)) - 9.33247691856536e-26)))) - 1.55672641622707e-19)) - 2.40195586337626e-17)));
	fConst159 = (1.07816591489115e-37 * fConst0);
	fConst160 = ((fConst0 * ((fConst0 * (5.7094380292656e-19 + (fConst41 * ((fConst0 * (2.82728220680625e-29 + (fConst0 * (3.85824499106181e-33 - fConst159)))) - 3.20030001117876e-25)))) - 4.54041692793529e-17)) - 4.52700117986931e-15);
	fConst161 = (9.14416348031757e-37 * fConst0);
	fConst162 = (fConst0 * (4.42013382343566e-19 + (fConst0 * ((fConst41 * (3.58734771027339e-24 + (fConst0 * ((fConst0 * (fConst161 - 4.04413539514376e-32)) - 4.89521193149012e-28)))) - 1.62296155430057e-19))));
	fConst163 = (1.06487639438358e-36 * fConst0);
	fConst164 = ((fConst0 * ((fConst0 * (1.13370955605989e-18 + (fConst41 * ((fConst0 * (6.5103952999532e-28 + (fConst0 * (4.89903368930905e-32 - fConst163)))) - 7.63185234497663e-24)))) - 2.03768151983578e-17)) - 2.74249212226804e-16);
	fConst165 = (8.12125577136249e-37 * fConst0);
	fConst166 = (fConst0 * (1.37112551202975e-20 + (fConst41 * ((fConst0 * (4.30100907480083e-28 + (fConst0 * (3.5825056399592e-32 - fConst165)))) - 2.89985970926765e-24))));
	fConst167 = (9.57129590329121e-37 * fConst0);
	fConst168 = (1.62042105967152e-18 + (fConst0 * ((fConst41 * (6.66758064626369e-24 + (fConst0 * ((fConst0 * (fConst167 - 4.39715858164732e-32)) - 5.82059599226893e-28)))) - 5.68240709496558e-19)));
	fConst169 = (9.68218833843144e-38 * fConst0);
	fConst170 = (3.63556006977584e-16 + (fConst0 * (2.40195586337626e-17 + (fConst0 * ((fConst41 * (2.79974307556961e-25 + (fConst0 * ((fConst0 * (fConst169 - 3.45879884724634e-33)) - 2.51540971792085e-29)))) - 4.67017924868121e-19)))));
	fConst171 = ((fConst41 * (7.40938539282371e-22 + (fConst41 * ((1.34770739361393e-37 * fConst41) - 7.06820551701561e-29)))) - 1.13510423198382e-16);
	fConst172 = (1.10503345585892e-18 + (fConst41 * ((fConst41 * (1.22380298287253e-27 - (1.1430204350397e-36 * fConst41))) - 3.9453592747499e-21)));
	fConst173 = ((fConst41 * (1.02189215279277e-20 + (fConst41 * ((1.33109549297948e-36 * fConst41) - 1.6275988249883e-27)))) - 5.09420379958945e-17);
	fConst174 = (6.00488965844066e-17 + (fConst41 * ((fConst41 * (6.28852429480213e-29 - (1.21027354230393e-37 * fConst41))) - 6.35268323502056e-22)));
	fConst175 = (fConst41 * (2.99611573659023e-21 + (fConst41 * ((1.01515697142031e-36 * fConst41) - 1.07525226870021e-27))));
	fConst176 = (4.05105264917879e-18 + (fConst41 * ((fConst41 * (1.45514899806723e-27 - (1.1964119879114e-36 * fConst41))) - 8.61796369953236e-21)));
	fConst177 = (4.52700117986931e-15 + (fConst0 * ((fConst0 * ((fConst41 * (3.20030001117876e-25 + (fConst0 * (2.82728220680625e-29 + (fConst0 * (0 - (3.85824499106181e-33 + fConst159))))))) - 5.7094380292656e-19)) - 4.54041692793529e-17)));
	fConst178 = (fConst0 * (4.42013382343566e-19 + (fConst0 * (1.62296155430057e-19 + (fConst41 * ((fConst0 * ((fConst0 * (4.04413539514376e-32 + fConst161)) - 4.89521193149012e-28)) - 3.58734771027339e-24))))));
	fConst179 = (2.74249212226804e-16 + (fConst0 * ((fConst0 * ((fConst41 * (7.63185234497663e-24 + (fConst0 * (6.5103952999532e-28 + (fConst0 * (0 - (4.89903368930905e-32 + fConst163))))))) - 1.13370955605989e-18)) - 2.03768151983578e-17)));
	fConst180 = (fConst0 * ((fConst41 * (2.89985970926765e-24 + (fConst0 * (4.30100907480083e-28 + (fConst0 * (0 - (3.5825056399592e-32 + fConst165))))))) - 1.37112551202975e-20));
	fConst181 = (1.62042105967152e-18 + (fConst0 * (5.68240709496558e-19 + (fConst41 * ((fConst0 * ((fConst0 * (4.39715858164732e-32 + fConst167)) - 5.82059599226893e-28)) - 6.66758064626369e-24)))));
	fConst182 = ((fConst0 * (2.40195586337626e-17 + (fConst0 * (4.67017924868121e-19 + (fConst41 * ((fConst0 * ((fConst0 * (3.45879884724634e-33 + fConst169)) - 2.51540971792085e-29)) - 2.79974307556961e-25)))))) - 3.63556006977584e-16);
	fConst183 = (4.52700117986931e-15 + (fConst0 * (4.54041692793529e-17 + (fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * (2.82728220680625e-29 + (fConst0 * (3.85824499106181e-33 + fConst147)))) - 1.06676667039292e-25)) - 4.93959026188247e-22)) - 1.9031460097552e-19)))));
	fConst184 = (fConst0 * ((fConst0 * (5.40987184766855e-20 + (fConst0 * (2.63023951649994e-21 + (fConst0 * (1.19578257009113e-24 + (fConst0 * ((fConst0 * (0 - (4.04413539514376e-32 + fConst149))) - 4.89521193149012e-28)))))))) - 4.42013382343566e-19));
	fConst185 = (2.74249212226804e-16 + (fConst0 * (2.03768151983578e-17 + (fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * (6.5103952999532e-28 + (fConst0 * (4.89903368930905e-32 + fConst151)))) - 2.54395078165888e-24)) - 6.81261435195178e-21)) - 3.77903185353297e-19)))));
	fConst186 = (fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * (4.30100907480083e-28 + (fConst0 * (3.5825056399592e-32 + fConst153)))) - 9.66619903089217e-25)) - 1.99741049106015e-21)) - 4.57041837343248e-21));
	fConst187 = ((fConst0 * (1.89413569832186e-19 + (fConst0 * (5.74530913302157e-21 + (fConst0 * (2.2225268820879e-24 + (fConst0 * ((fConst0 * (0 - (4.39715858164732e-32 + fConst155))) - 5.82059599226893e-28)))))))) - 1.62042105967152e-18);
	fConst188 = ((fConst0 * ((fConst0 * (1.55672641622707e-19 + (fConst0 * (4.23512215668038e-22 + (fConst0 * (9.33247691856536e-26 + (fConst0 * ((fConst0 * (0 - (3.45879884724634e-33 + fConst157))) - 2.51540971792085e-29)))))))) - 2.40195586337626e-17)) - 3.63556006977584e-16);
	fConst189 = (1.94014336280113e-15 + (fConst0 * (4.54041692793529e-17 + (fConst0 * (1.9031460097552e-19 + (fConst41 * ((fConst0 * ((fConst0 * (0 - (1.65353356759792e-33 + fConst135))) - 2.82728220680625e-29)) - 1.06676667039292e-25)))))));
	fConst190 = (fConst0 * ((fConst0 * ((fConst41 * (1.19578257009113e-24 + (fConst0 * (4.89521193149012e-28 + (fConst0 * (1.73320088363304e-32 + fConst137)))))) - 5.40987184766855e-20)) - 4.42013382343566e-19));
	fConst191 = (1.1753537666863e-16 + (fConst0 * (2.03768151983578e-17 + (fConst0 * (3.77903185353297e-19 + (fConst41 * ((fConst0 * ((fConst0 * (0 - (2.09958586684674e-32 + fConst139))) - 6.5103952999532e-28)) - 2.54395078165888e-24)))))));
	fConst192 = (fConst0 * (4.57041837343248e-21 + (fConst41 * ((fConst0 * ((fConst0 * (0 - (1.53535955998251e-32 + fConst141))) - 4.30100907480083e-28)) - 9.66619903089217e-25))));
	fConst193 = ((fConst0 * ((fConst41 * (2.2225268820879e-24 + (fConst0 * (5.82059599226893e-28 + (fConst0 * (1.88449653499171e-32 + fConst143)))))) - 1.89413569832186e-19)) - 1.62042105967152e-18);
	fConst194 = ((fConst0 * ((fConst0 * ((fConst41 * (9.33247691856536e-26 + (fConst0 * (2.51540971792085e-29 + (fConst0 * (1.48234236310557e-33 + fConst145)))))) - 1.55672641622707e-19)) - 2.40195586337626e-17)) - 1.55809717276107e-16);
	fConst195 = (7.04823315982115e-35 * fConst0);
	fConst196 = (4.65509016185963e-18 + (fConst0 * ((fConst41 * (6.32839452326887e-25 + (fConst0 * (0 - (2.62354210174893e-28 + fConst195))))) - 8.09880504171981e-20)));
	fConst197 = (6.5993011114249e-35 * fConst0);
	fConst198 = (4.81336322736286e-20 + (fConst41 * ((fConst0 * (2.45636211390993e-28 + fConst197)) - 6.13594910774543e-25)));
	fConst199 = (5.62943540162964e-34 * fConst0);
	fConst200 = (fConst41 * (3.90436158302686e-24 + (fConst0 * (0 - (2.12806894928757e-27 + fConst199)))));
	fConst201 = (4.96950529048715e-34 * fConst0);
	fConst202 = ((fConst41 * ((fConst0 * (1.88243273789657e-27 + fConst201)) - 3.29076667225232e-24)) - 4.81336322736286e-20);
	fConst203 = (6.01239019085614e-34 * fConst0);
	fConst204 = (fConst0 * (4.65509016185963e-20 + (fConst41 * ((fConst0 * (2.27290423453708e-27 + fConst203)) - 3.97506737997131e-24))));
	fConst205 = (5.30756687487403e-34 * fConst0);
	fConst206 = ((fConst0 * (3.44371487986018e-20 + (fConst41 * (3.34222792764443e-24 + (fConst0 * (0 - (2.01055002436219e-27 + fConst205))))))) - 4.65509016185963e-18);
	fConst207 = (1.6445877372916e-34 * fConst0);
	fConst208 = (fConst0 * (2.62354210174893e-28 + fConst207));
	fConst209 = (4.65509016185963e-18 + (fConst0 * (8.09880504171981e-20 + (fConst0 * ((fConst0 * (6.32839452326887e-25 + fConst208)) - 1.42012594728872e-21)))));
	fConst210 = (1.53983692599914e-34 * fConst0);
	fConst211 = (fConst0 * (0 - (2.45636211390993e-28 + fConst210)));
	fConst212 = ((fConst0 * (1.35885873441803e-21 + (fConst0 * (fConst211 - 6.13594910774543e-25)))) - 4.81336322736286e-20);
	fConst213 = (1.31353492704692e-33 * fConst0);
	fConst214 = (fConst0 * (2.12806894928757e-27 + fConst213));
	fConst215 = (fConst0 * ((fConst0 * (3.90436158302686e-24 + fConst214)) - 1.92534529094515e-21));
	fConst216 = (1.159551234447e-33 * fConst0);
	fConst217 = (fConst0 * (0 - (1.88243273789657e-27 + fConst216)));
	fConst218 = (4.81336322736286e-20 + (fConst0 * (5.66486556527112e-22 + (fConst0 * (fConst217 - 3.29076667225232e-24)))));
	fConst219 = (1.4028910445331e-33 * fConst0);
	fConst220 = (fConst0 * (0 - (2.27290423453708e-27 + fConst219)));
	fConst221 = (fConst0 * ((fConst0 * (2.30294312295935e-21 + (fConst0 * (fConst220 - 3.97506737997131e-24)))) - 4.65509016185963e-20));
	fConst222 = (1.23843227080394e-33 * fConst0);
	fConst223 = (fConst0 * (2.01055002436219e-27 + fConst222));
	fConst224 = ((fConst0 * ((fConst0 * ((fConst0 * (3.34222792764443e-24 + fConst223)) - 8.82817175670626e-22)) - 3.44371487986018e-20)) - 4.65509016185963e-18);
	fConst225 = (fConst0 * (2.62354210174893e-28 - fConst207));
	fConst226 = ((fConst0 * (2.42964151251594e-19 + (fConst41 * (fConst225 - 1.89851835698066e-24)))) - 4.65509016185963e-18);
	fConst227 = (fConst0 * (fConst210 - 2.45636211390993e-28));
	fConst228 = ((fConst41 * (1.84078473232363e-24 + fConst227)) - 1.44400896820886e-19);
	fConst229 = (fConst0 * (2.12806894928757e-27 - fConst213));
	fConst230 = (fConst41 * (fConst229 - 1.17130847490806e-23));
	fConst231 = (fConst0 * (fConst216 - 1.88243273789657e-27));
	fConst232 = (1.44400896820886e-19 + (fConst41 * (9.87230001675696e-24 + fConst231)));
	fConst233 = (fConst0 * (fConst219 - 2.27290423453708e-27));
	fConst234 = (fConst0 * ((fConst41 * (1.19252021399139e-23 + fConst233)) - 1.39652704855789e-19));
	fConst235 = (fConst0 * (2.01055002436219e-27 - fConst222));
	fConst236 = (4.65509016185963e-18 + (fConst0 * ((fConst41 * (fConst235 - 1.00266837829333e-23)) - 1.03311446395805e-19)));
	fConst237 = ((fConst41 * (2.13018892093308e-21 - (6.55885525437233e-28 * fConst41))) - 1.16377254046491e-17);
	fConst238 = (2.88801793641772e-21 - (5.32017237321892e-27 * fConst41));
	fConst239 = ((4.70608184474144e-27 * fConst41) - 8.49729834790668e-22);
	fConst240 = ((6.14090528477483e-28 * fConst41) - 2.03828810162705e-21);
	fConst241 = (fConst41 * ((5.6822605863427e-27 * fConst41) - 3.45441468443902e-21));
	fConst242 = (1.16377254046491e-17 + (fConst41 * (1.32422576350594e-21 - (5.02637506090546e-27 * fConst41))));
	fConst243 = ((fConst0 * ((fConst41 * (1.89851835698066e-24 + fConst208)) - 2.42964151251594e-19)) - 4.65509016185963e-18);
	fConst244 = (1.44400896820886e-19 + (fConst41 * (fConst211 - 1.84078473232363e-24)));
	fConst245 = (fConst41 * (1.17130847490806e-23 + fConst214));
	fConst246 = ((fConst41 * (fConst217 - 9.87230001675696e-24)) - 1.44400896820886e-19);
	fConst247 = (fConst0 * (1.39652704855789e-19 + (fConst41 * (fConst220 - 1.19252021399139e-23))));
	fConst248 = (4.65509016185963e-18 + (fConst0 * (1.03311446395805e-19 + (fConst41 * (1.00266837829333e-23 + fConst223)))));
	fConst249 = (4.65509016185963e-18 + (fConst0 * ((fConst0 * ((fConst0 * (fConst225 - 6.32839452326887e-25)) - 1.42012594728872e-21)) - 8.09880504171981e-20)));
	fConst250 = (4.81336322736286e-20 + (fConst0 * (1.35885873441803e-21 + (fConst0 * (6.13594910774543e-25 + fConst227)))));
	fConst251 = (fConst0 * ((fConst0 * (fConst229 - 3.90436158302686e-24)) - 1.92534529094515e-21));
	fConst252 = ((fConst0 * (5.66486556527112e-22 + (fConst0 * (3.29076667225232e-24 + fConst231)))) - 4.81336322736286e-20);
	fConst253 = (fConst0 * (4.65509016185963e-20 + (fConst0 * (2.30294312295935e-21 + (fConst0 * (3.97506737997131e-24 + fConst233))))));
	fConst254 = ((fConst0 * (3.44371487986018e-20 + (fConst0 * ((fConst0 * (fConst235 - 3.34222792764443e-24)) - 8.82817175670626e-22)))) - 4.65509016185963e-18);
	fConst255 = (4.65509016185963e-18 + (fConst0 * (8.09880504171981e-20 + (fConst41 * ((fConst0 * (fConst195 - 2.62354210174893e-28)) - 6.32839452326887e-25)))));
	fConst256 = ((fConst41 * (6.13594910774543e-25 + (fConst0 * (2.45636211390993e-28 - fConst197)))) - 4.81336322736286e-20);
	fConst257 = (fConst41 * ((fConst0 * (fConst199 - 2.12806894928757e-27)) - 3.90436158302686e-24));
	fConst258 = (4.81336322736286e-20 + (fConst41 * (3.29076667225232e-24 + (fConst0 * (1.88243273789657e-27 - fConst201)))));
	fConst259 = (fConst0 * ((fConst41 * (3.97506737997131e-24 + (fConst0 * (2.27290423453708e-27 - fConst203)))) - 4.65509016185963e-20));
	fConst260 = ((fConst0 * ((fConst41 * ((fConst0 * (fConst205 - 2.01055002436219e-27)) - 3.34222792764443e-24)) - 3.44371487986018e-20)) - 4.65509016185963e-18);
	fConst261 = (1.16377254046491e-18 + (fConst0 * (4.0494025208599e-20 + (fConst0 * (3.55031486822181e-22 + (fConst0 * (3.16419726163444e-25 + (fConst0 * (6.55885525437233e-29 - fConst117)))))))));
	fConst262 = (fConst0 * (4.81336322736286e-22 + (fConst0 * (1.95218079151343e-24 + (fConst0 * (5.32017237321892e-28 - fConst121))))));
	fConst263 = (2.40668161368143e-20 + (fConst0 * ((fConst0 * ((fConst0 * (fConst123 - 4.70608184474143e-28)) - 1.64538333612616e-24)) - 1.41621639131778e-22)));
	fConst264 = ((fConst0 * ((fConst0 * ((fConst0 * (fConst119 - 6.14090528477483e-29)) - 3.06797455387272e-25)) - 3.39714683604509e-22)) - 2.40668161368143e-20);
	fConst265 = (fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * (fConst125 - 5.6822605863427e-28)) - 1.98753368998566e-24)) - 5.75735780739837e-22)) - 2.32754508092981e-20));
	fConst266 = ((fConst0 * ((fConst0 * (2.20704293917657e-22 + (fConst0 * (1.67111396382221e-24 + (fConst0 * (5.02637506090546e-28 - fConst127)))))) - 1.72185743993009e-20)) - 1.16377254046491e-18);
	fConst267 = (2.35432599805571e-10 * fConst0);
	fConst268 = (fConst0 * (3.95835848142153e-05 + fConst267));
	fConst269 = (0 - (4.70865199611141e-10 * fConst41));
	fConst270 = (fConst0 * (fConst267 - 3.95835848142153e-05));
	fConst271 = (7.61136585018504e-32 * fConst0);
	fConst272 = ((fConst0 * (1.54695224812832e-17 + (fConst41 * (7.32488014122897e-21 + (fConst0 * (0 - (3.82729245593221e-25 + fConst271))))))) - 6.05835093424096e-16);
	fConst273 = (2.39262841570727e-31 * fConst0);
	fConst274 = ((fConst0 * (3.31891148609028e-32 + (fConst41 * (2.7286345116429e-20 + (fConst0 * (0 - (1.82261566152054e-23 + fConst273))))))) - 1.2888977955445e-30);
	fConst275 = (1.11676404845819e-31 * fConst0);
	fConst276 = ((fConst41 * ((fConst0 * (2.44009843633683e-23 + fConst275)) - 1.96606357975003e-20)) - 6.61146583932057e-48);
	fConst277 = (2.60875189351624e-19 + (fConst41 * ((fConst0 * (0 - (2.44009204730374e-23 + fConst275))) - 2.49566107730556e-23)));
	fConst278 = (1.10748289620665e-31 * fConst0);
	fConst279 = (6.61146583932057e-48 + (fConst41 * ((fConst0 * (1.61120746095049e-26 - fConst278)) - 1.78759975574757e-23)));
	fConst280 = ((fConst41 * (1.96963877926153e-20 + (fConst0 * (fConst278 - 1.61110772795832e-26)))) - 6.61146583932057e-48);
	fConst281 = (2.39032787477683e-31 * fConst0);
	fConst282 = (1.2888977955445e-30 + (fConst0 * ((fConst41 * ((fConst0 * (1.21738014006249e-23 + fConst281)) - 2.10292427930658e-20)) - 1.30437594675845e-19)));
	fConst283 = (2.5677288147206e-31 * fConst0);
	fConst284 = (6.44448897807416e-31 + (fConst0 * ((fConst41 * ((fConst0 * (4.82031108570165e-25 + fConst283)) - 3.77146842732817e-22)) - 4.43487821897763e-18)));
	fConst285 = ((fConst0 * (4.30444062430181e-18 + (fConst41 * ((fConst0 * (0 - (4.82063574071825e-25 + fConst283))) - 4.69123728113195e-23)))) - 6.44448897807416e-31);
	fConst286 = (1.90284146254626e-31 * fConst0);
	fConst287 = ((fConst0 * ((fConst0 * ((fConst0 * (3.66244007061449e-21 + (fConst0 * (4.78411556991526e-25 + fConst286)))) - 3.49583232264895e-17)) - 7.73476124064158e-18)) - 7.5729386678012e-16);
	fConst288 = (5.98157103926817e-31 * fConst0);
	fConst289 = ((fConst0 * ((fConst0 * (2.15574212705131e-21 + (fConst0 * (1.36431725582145e-20 + (fConst0 * (2.27826957690067e-23 + fConst288)))))) - 1.65945574304514e-32)) - 1.61112224443063e-30);
	fConst290 = (2.79191012114547e-31 * fConst0);
	fConst291 = (3.30573291966029e-48 + (fConst0 * ((fConst0 * ((fConst0 * (0 - (3.05012304542104e-23 + fConst290))) - 9.83031789875016e-21)) - 1.38500839080866e-34)));
	fConst292 = ((fConst0 * (1.57673596144215e-20 + (fConst0 * ((fConst0 * (3.05011505912968e-23 + fConst290)) - 1.24783053865278e-23)))) - 1.30437594675812e-19);
	fConst293 = (2.76870724051662e-31 * fConst0);
	fConst294 = ((fConst0 * (1.38500839080866e-34 + (fConst0 * ((fConst0 * (fConst293 - 2.01400932618811e-26)) - 8.93799877873786e-24)))) - 3.30573291966029e-48);
	fConst295 = (3.30573291966029e-48 + (fConst0 * ((fConst0 * (9.84819389630763e-21 + (fConst0 * (2.01388465994789e-26 - fConst293)))) - 1.45976001917383e-31)));
	fConst296 = (5.97581968694209e-31 * fConst0);
	fConst297 = (1.61112224443063e-30 + (fConst0 * (6.52187973379226e-20 + (fConst0 * ((fConst0 * ((fConst0 * (0 - (1.52172517507811e-23 + fConst296))) - 1.05146213965329e-20)) - 1.00394219341891e-20)))));
	fConst298 = (6.41932203680151e-31 * fConst0);
	fConst299 = (8.0556112225927e-31 + (fConst0 * (2.21743910948881e-18 + (fConst0 * ((fConst0 * ((fConst0 * (0 - (6.02538885712707e-25 + fConst298))) - 1.88573421366408e-22)) - 4.55611244465951e-20)))));
	fConst300 = ((fConst0 * ((fConst0 * (3.27758082037328e-17 + (fConst0 * ((fConst0 * (6.02579467589781e-25 + fConst298)) - 2.34561864056598e-23)))) - 2.15222031215091e-18)) - 8.0556112225927e-31);
	fConst301 = ((fConst41 * (0 - (1.46497602824579e-20 + (2.53712195006168e-31 * fConst41)))) - 3.09390449625663e-17);
	fConst302 = ((fConst41 * (0 - (5.45726902328579e-20 + (7.97542805235757e-31 * fConst41)))) - 6.63782297218055e-32);
	fConst303 = (2.60875189351691e-19 + (fConst41 * (4.20584855861316e-20 + (7.96775958258945e-31 * fConst41))));
	fConst304 = (3.69160965402215e-31 * fConst41);
	fConst305 = ((fConst41 * (3.57519951149514e-23 - fConst304)) - 1.32229316786411e-47);
	fConst306 = (1.32229316786411e-47 + (fConst41 * (fConst304 - 3.93927755852305e-20)));
	fConst307 = (3.72254682819396e-31 * fConst41);
	fConst308 = (1.32229316786411e-47 + (fConst41 * (3.93212715950006e-20 + fConst307)));
	fConst309 = ((fConst41 * (4.99132215461111e-23 - fConst307)) - 5.21750378703248e-19);
	fConst310 = (8.55909604906868e-31 * fConst41);
	fConst311 = (8.86975643795525e-18 + (fConst41 * (7.54293685465634e-22 + fConst310)));
	fConst312 = ((fConst41 * (9.3824745622639e-23 - fConst310)) - 8.60888124860363e-18);
	fConst313 = (7.5729386678012e-16 + (fConst0 * ((fConst0 * (3.49583232264895e-17 + (fConst0 * (3.66244007061449e-21 + (fConst0 * (fConst286 - 4.78411556991526e-25)))))) - 7.73476124064158e-18)));
	fConst314 = (1.61112224443063e-30 + (fConst0 * ((fConst0 * ((fConst0 * (1.36431725582145e-20 + (fConst0 * (fConst288 - 2.27826957690067e-23)))) - 2.15574212705131e-21)) - 1.65945574304514e-32)));
	fConst315 = (3.30573291966029e-48 + (fConst0 * (1.38500839080866e-34 + (fConst0 * ((fConst0 * (3.05012304542104e-23 - fConst290)) - 9.83031789875016e-21)))));
	fConst316 = ((fConst0 * ((fConst0 * ((fConst0 * (fConst290 - 3.05011505912968e-23)) - 1.24783053865278e-23)) - 1.57673596144215e-20)) - 1.30437594675812e-19);
	fConst317 = ((fConst0 * ((fConst0 * ((fConst0 * (2.01400932618811e-26 + fConst293)) - 8.93799877873786e-24)) - 1.38500839080866e-34)) - 3.30573291966029e-48);
	fConst318 = (3.30573291966029e-48 + (fConst0 * (1.45976001917383e-31 + (fConst0 * (9.84819389630763e-21 + (fConst0 * (0 - (2.01388465994789e-26 + fConst293))))))));
	fConst319 = ((fConst0 * (6.52187973379226e-20 + (fConst0 * (1.00394219341891e-20 + (fConst0 * ((fConst0 * (1.52172517507811e-23 - fConst296)) - 1.05146213965329e-20)))))) - 1.61112224443063e-30);
	fConst320 = ((fConst0 * (2.21743910948881e-18 + (fConst0 * (4.55611244465951e-20 + (fConst0 * ((fConst0 * (6.02538885712707e-25 - fConst298)) - 1.88573421366408e-22)))))) - 8.0556112225927e-31);
	fConst321 = (8.0556112225927e-31 + (fConst0 * ((fConst0 * ((fConst0 * ((fConst0 * (fConst298 - 6.02579467589781e-25)) - 2.34561864056598e-23)) - 3.27758082037328e-17)) - 2.15222031215091e-18)));
	fConst322 = (6.05835093424096e-16 + (fConst0 * (1.54695224812832e-17 + (fConst41 * (7.32488014122897e-21 + (fConst0 * (3.82729245593221e-25 - fConst271)))))));
	fConst323 = (1.2888977955445e-30 + (fConst0 * (3.31891148609028e-32 + (fConst41 * (2.7286345116429e-20 + (fConst0 * (1.82261566152054e-23 - fConst273)))))));
	fConst324 = ((fConst41 * ((fConst0 * (fConst275 - 2.44009843633683e-23)) - 1.96606357975003e-20)) - 6.61146583932057e-48);
	fConst325 = (2.60875189351624e-19 + (fConst41 * ((fConst0 * (2.44009204730374e-23 - fConst275)) - 2.49566107730556e-23)));
	fConst326 = (6.61146583932057e-48 + (fConst41 * ((fConst0 * (0 - (1.61120746095049e-26 + fConst278))) - 1.78759975574757e-23)));
	fConst327 = ((fConst41 * (1.96963877926153e-20 + (fConst0 * (1.61110772795832e-26 + fConst278)))) - 6.61146583932057e-48);
	fConst328 = ((fConst0 * ((fConst41 * ((fConst0 * (fConst281 - 1.21738014006249e-23)) - 2.10292427930658e-20)) - 1.30437594675845e-19)) - 1.2888977955445e-30);
	fConst329 = ((fConst0 * ((fConst41 * ((fConst0 * (fConst283 - 4.82031108570165e-25)) - 3.77146842732817e-22)) - 4.43487821897763e-18)) - 6.44448897807416e-31);
	fConst330 = (6.44448897807416e-31 + (fConst0 * (4.30444062430181e-18 + (fConst41 * ((fConst0 * (4.82063574071825e-25 - fConst283)) - 4.69123728113195e-23)))));
	fConst331 = (1.51458773356024e-16 + (fConst0 * (7.73476124064158e-18 + (fConst0 * ((fConst0 * ((fConst0 * (fConst16 - 9.56823113983053e-26)) - 3.66244007061449e-21)) - 1.16527744088298e-17)))));
	fConst332 = (3.22224448886125e-31 + (fConst0 * (1.65945574304514e-32 + (fConst0 * (7.18580709017103e-22 + (fConst0 * ((fConst0 * (fConst18 - 4.55653915380135e-24)) - 1.36431725582145e-20)))))));
	fConst333 = ((fConst0 * ((fConst0 * (9.83031789875016e-21 + (fConst0 * (6.10024609084207e-24 - fConst20)))) - 4.61669463602886e-35)) - 3.30573291966029e-48);
	fConst334 = (1.30437594675812e-19 + (fConst0 * (5.25578653814051e-21 + (fConst0 * (1.24783053865278e-23 + (fConst0 * (fConst20 - 6.10023011825936e-24)))))));
	fConst335 = (3.30573291966029e-48 + (fConst0 * (4.61669463602886e-35 + (fConst0 * (8.93799877873786e-24 + (fConst0 * (4.02801865237622e-27 + fConst23)))))));
	fConst336 = ((fConst0 * ((fConst0 * ((fConst0 * (0 - (4.02776931989579e-27 + fConst23))) - 9.84819389630763e-21)) - 4.86586673057942e-32)) - 3.30573291966029e-48);
	fConst337 = ((fConst0 * ((fConst0 * ((fConst0 * (1.05146213965329e-20 + (fConst0 * (3.04345035015622e-24 - fConst26)))) - 3.34647397806303e-21)) - 6.52187973379226e-20)) - 3.22224448886125e-31);
	fConst338 = ((fConst0 * ((fConst0 * ((fConst0 * (1.88573421366408e-22 + (fConst0 * (1.20507777142541e-25 - fConst28)))) - 1.51870414821984e-20)) - 2.21743910948881e-18)) - 1.61112224451854e-31);
	fConst339 = (1.61112224451854e-31 + (fConst0 * (2.15222031215091e-18 + (fConst0 * (1.09252694012443e-17 + (fConst0 * (2.34561864056598e-23 + (fConst0 * (fConst28 - 1.20515893517956e-25)))))))));
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
	double 	fSlow0 = (0.007000000000000006 * (1 - double(fslider0)));
	double 	fSlow1 = (0.007000000000000006 * double(fslider1));
	double 	fSlow2 = (0.007000000000000006 * (1 - double(fslider2)));
	double 	fSlow3 = (0.007000000000000006 * (1 - double(fslider3)));
	for (int i=0; i<count; i++) {
		fRec0[0] = ((0.993 * fRec0[1]) + fSlow0);
		fRec1[0] = ((0.993 * fRec1[1]) + fSlow1);
		double fTemp0 = (((fRec0[0] * ((fConst15 * fRec0[0]) + fConst14)) + (fRec1[0] * (((fRec0[0] * ((fConst12 * fRec0[0]) + fConst11)) + (fRec1[0] * ((fRec0[0] * ((fConst9 * fRec0[0]) + fConst8)) + fConst6))) + fConst4))) + fConst2);
		fRec4[0] = ((0.993 * fRec4[1]) + fSlow2);
		fRec5[0] = ((0.993 * fRec5[1]) + fSlow3);
		double fTemp1 = (1.25571983620331e-15 + (fConst0 * (((fRec5[0] * (fConst116 + (fConst0 * (fRec4[0] * (fConst114 + (fConst112 * fRec4[0])))))) + (fRec4[0] * (fConst110 + (fConst108 * fRec4[0])))) + fConst106)));
		fRec6[0] = ((double)input0[i] - (((((((((fRec6[1] * (1.00457586896265e-14 + (fConst0 * (((fRec5[0] * (fConst194 + (fConst0 * (fRec4[0] * (fConst193 + (fConst192 * fRec4[0])))))) + (fRec4[0] * (fConst191 + (fConst190 * fRec4[0])))) + fConst189)))) + (fRec6[2] * (3.51601554136928e-14 + (fConst0 * (((fRec5[0] * (fConst188 + (fConst0 * (fRec4[0] * (fConst187 + (fConst186 * fRec4[0])))))) + (fRec4[0] * (fConst185 + (fConst184 * fRec4[0])))) + fConst183))))) + (fRec6[3] * (7.03203108273855e-14 + (fConst0 * (((fRec5[0] * (fConst182 + (fConst0 * (fRec4[0] * (fConst181 + (fConst180 * fRec4[0])))))) + (fRec4[0] * (fConst179 + (fConst178 * fRec4[0])))) + fConst177))))) + (fRec6[4] * (8.79003885342319e-14 + (fConst41 * (((fRec5[0] * ((fRec4[0] * (fConst176 + (fConst175 * fRec4[0]))) + fConst174)) + (fRec4[0] * (fConst173 + (fConst172 * fRec4[0])))) + fConst171))))) + (fRec6[5] * (7.03203108273855e-14 + (fConst0 * (((fRec5[0] * (fConst170 + (fConst0 * (fRec4[0] * (fConst168 + (fConst166 * fRec4[0])))))) + (fRec4[0] * (fConst164 + (fConst162 * fRec4[0])))) + fConst160))))) + (fRec6[6] * (3.51601554136928e-14 + (fConst0 * (((fRec5[0] * (fConst158 + (fConst0 * (fRec4[0] * (fConst156 + (fConst154 * fRec4[0])))))) + (fRec4[0] * (fConst152 + (fConst150 * fRec4[0])))) + fConst148))))) + (fRec6[7] * (1.00457586896265e-14 + (fConst0 * (((fRec5[0] * (fConst146 + (fConst0 * (fRec4[0] * (fConst144 + (fConst142 * fRec4[0])))))) + (fRec4[0] * (fConst140 + (fConst138 * fRec4[0])))) + fConst136))))) + (fRec6[8] * (1.25571983620331e-15 + (fConst0 * (((fRec5[0] * (fConst134 + (fConst0 * (fRec4[0] * (fConst133 + (fConst132 * fRec4[0])))))) + (fRec4[0] * (fConst131 + (fConst130 * fRec4[0])))) + fConst129))))) / fTemp1));
		fRec3[0] = ((fConst41 * ((((((((((fRec6[0] * (((fRec4[0] * (fConst266 + (fConst265 * fRec4[0]))) + (fConst0 * (fRec5[0] * (fConst264 + (fRec4[0] * (fConst263 + (fConst262 * fRec4[0]))))))) + fConst261)) + (fRec6[1] * (((fRec4[0] * (fConst260 + (fConst259 * fRec4[0]))) + (fConst0 * (fRec5[0] * ((fRec4[0] * (fConst258 + (fConst257 * fRec4[0]))) + fConst256)))) + fConst255))) + (fRec6[2] * (((fRec4[0] * (fConst254 + (fConst253 * fRec4[0]))) + (fConst0 * (fRec5[0] * ((fRec4[0] * (fConst252 + (fConst251 * fRec4[0]))) + fConst250)))) + fConst249))) + (fRec6[3] * (((fRec4[0] * (fConst248 + (fConst247 * fRec4[0]))) + (fConst0 * (fRec5[0] * ((fRec4[0] * (fConst246 + (fConst245 * fRec4[0]))) + fConst244)))) + fConst243))) + (fRec6[4] * (((fRec4[0] * (fConst242 + (fConst241 * fRec4[0]))) + (fConst41 * (fRec5[0] * (fConst240 + (fRec4[0] * (fConst239 + (fConst238 * fRec4[0]))))))) + fConst237))) + (fRec6[5] * (((fRec4[0] * (fConst236 + (fConst234 * fRec4[0]))) + (fConst0 * (fRec5[0] * ((fRec4[0] * (fConst232 + (fConst230 * fRec4[0]))) + fConst228)))) + fConst226))) + (fRec6[6] * (((fRec4[0] * (fConst224 + (fConst221 * fRec4[0]))) + (fConst0 * (fRec5[0] * ((fRec4[0] * (fConst218 + (fConst215 * fRec4[0]))) + fConst212)))) + fConst209))) + (fRec6[7] * (((fRec4[0] * (fConst206 + (fConst204 * fRec4[0]))) + (fConst0 * (fRec5[0] * ((fRec4[0] * (fConst202 + (fConst200 * fRec4[0]))) + fConst198)))) + fConst196))) + (fRec6[8] * (((fRec4[0] * (fConst128 + (fConst126 * fRec4[0]))) + (fConst0 * (fRec5[0] * ((fRec4[0] * (fConst124 + (fConst122 * fRec4[0]))) + fConst120)))) + fConst118))) / fTemp1)) - (fConst104 * ((fConst103 * fRec3[1]) + (fConst102 * fRec3[2]))));
		fRec2[0] = ((fConst104 * (((fConst270 * fRec3[0]) + (fConst269 * fRec3[1])) + (fConst268 * fRec3[2]))) - (((((((fRec2[1] * (((fRec0[0] * ((fConst100 * fRec0[0]) + fConst99)) + (fRec1[0] * (((fRec0[0] * ((fConst98 * fRec0[0]) + fConst97)) + (fRec1[0] * ((fRec0[0] * ((fConst96 * fRec0[0]) + fConst95)) + fConst94))) + fConst93))) + fConst92)) + (fRec2[2] * (((fRec0[0] * ((fConst91 * fRec0[0]) + fConst90)) + (fRec1[0] * (((fRec0[0] * ((fConst89 * fRec0[0]) + fConst88)) + (fRec1[0] * ((fRec0[0] * ((fConst87 * fRec0[0]) + fConst86)) + fConst85))) + fConst84))) + fConst83))) + (fRec2[3] * (((fRec0[0] * ((fConst82 * fRec0[0]) + fConst81)) + (fRec1[0] * (((fRec0[0] * ((fConst79 * fRec0[0]) + fConst78)) + (fRec1[0] * ((fRec0[0] * ((fConst76 * fRec0[0]) + fConst75)) + fConst73))) + fConst72))) + fConst71))) + (fRec2[4] * (((fRec0[0] * ((fConst70 * fRec0[0]) + fConst69)) + (fRec1[0] * (((fRec0[0] * ((fConst67 * fRec0[0]) + fConst66)) + (fRec1[0] * ((fRec0[0] * ((fConst64 * fRec0[0]) + fConst63)) + fConst61))) + fConst59))) + fConst57))) + (fRec2[5] * (((fRec0[0] * ((fConst55 * fRec0[0]) + fConst54)) + (fRec1[0] * (((fRec0[0] * ((fConst52 * fRec0[0]) + fConst51)) + (fRec1[0] * ((fRec0[0] * ((fConst49 * fRec0[0]) + fConst48)) + fConst46))) + fConst44))) + fConst42))) + (fRec2[6] * (((fRec0[0] * ((fConst39 * fRec0[0]) + fConst38)) + (fRec1[0] * (((fRec0[0] * ((fConst37 * fRec0[0]) + fConst36)) + (fRec1[0] * ((fRec0[0] * ((fConst35 * fRec0[0]) + fConst34)) + fConst33))) + fConst32))) + fConst31))) / fTemp0));
		output0[i] = (FAUSTFLOAT)(fConst0 * ((((((((fRec2[0] * (((fRec0[0] * (fConst339 + (fConst338 * fRec0[0]))) + (fRec1[0] * (((fRec1[0] * (fConst337 + (fConst0 * (fRec0[0] * (fConst336 + (fConst335 * fRec0[0])))))) + (fConst0 * (fRec0[0] * (fConst334 + (fConst333 * fRec0[0]))))) + fConst332))) + fConst331)) + (fRec2[1] * (((fRec0[0] * (fConst330 + (fConst329 * fRec0[0]))) + (fRec1[0] * (((fRec1[0] * (fConst328 + (fConst0 * (fRec0[0] * (fConst327 + (fConst326 * fRec0[0])))))) + (fConst0 * (fRec0[0] * (fConst325 + (fConst324 * fRec0[0]))))) + fConst323))) + fConst322))) + (fRec2[2] * (((fRec0[0] * (fConst321 + (fConst320 * fRec0[0]))) + (fRec1[0] * (((fRec1[0] * (fConst319 + (fConst0 * (fRec0[0] * (fConst318 + (fConst317 * fRec0[0])))))) + (fConst0 * (fRec0[0] * (fConst316 + (fConst315 * fRec0[0]))))) + fConst314))) + fConst313))) + (fConst0 * (fRec2[3] * (((fRec0[0] * (fConst312 + (fConst311 * fRec0[0]))) + (fRec1[0] * (((fRec0[0] * (fConst309 + (fConst308 * fRec0[0]))) + (fRec1[0] * ((fRec0[0] * (fConst306 + (fConst305 * fRec0[0]))) + fConst303))) + fConst302))) + fConst301)))) + (fRec2[4] * (((fRec0[0] * (fConst300 + (fConst299 * fRec0[0]))) + (fRec1[0] * (((fRec1[0] * (fConst297 + (fConst0 * (fRec0[0] * (fConst295 + (fConst294 * fRec0[0])))))) + (fConst0 * (fRec0[0] * (fConst292 + (fConst291 * fRec0[0]))))) + fConst289))) + fConst287))) + (fRec2[5] * (((fRec0[0] * (fConst285 + (fConst284 * fRec0[0]))) + (fRec1[0] * (((fRec1[0] * (fConst282 + (fConst0 * (fRec0[0] * (fConst280 + (fConst279 * fRec0[0])))))) + (fConst0 * (fRec0[0] * (fConst277 + (fConst276 * fRec0[0]))))) + fConst274))) + fConst272))) + (fRec2[6] * (((fRec0[0] * (fConst30 + (fConst29 * fRec0[0]))) + (fRec1[0] * (((fRec1[0] * (fConst27 + (fConst0 * (fRec0[0] * (fConst25 + (fConst24 * fRec0[0])))))) + (fConst0 * (fRec0[0] * (fConst22 + (fConst21 * fRec0[0]))))) + fConst19))) + fConst17))) / fTemp0));
		// post processing
		for (int i=6; i>0; i--) fRec2[i] = fRec2[i-1];
		fRec3[2] = fRec3[1]; fRec3[1] = fRec3[0];
		for (int i=8; i>0; i--) fRec6[i] = fRec6[i-1];
		fRec5[1] = fRec5[0];
		fRec4[1] = fRec4[0];
		fRec1[1] = fRec1[0];
		fRec0[1] = fRec0[0];
	}
#undef fslider0
#undef fslider1
#undef fslider2
#undef fslider3
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
   MID, 
   TREBLE, 
   VOLUME, 
} PortIndex;
*/

} // end namespace voxbass
