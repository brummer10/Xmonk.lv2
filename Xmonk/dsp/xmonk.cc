
//-------`SFFormantModelBP` from physmodels.lib --------------
// Simple formant/vocal synthesizer based on a source/filter model. The source
// is just a sawtooth wave and the "filter" is a bank of resonant bandpass filters.
// Formant parameters are linearly interpolated allowing to go smoothly from
// one vowel to another. Voice type can be selected but must correspond to
// the frequency range of the synthesized voice to be realistic.
//
// The formant data used here come from the CSOUND manual
// <http://www.csounds.com/manual/html/>.
//
//---------------------------------------
// Author: Mike Olsen, CCRMA (Stanford University)

// generated from file './/xmonk.dsp' by dsp2cc:
// Code generated with Faust 2.15.11 (https://faust.grame.fr)


namespace xmonk {
class mydspSIG0 {
	
  private:
	
	int iRec0[2];
	
  public:
	
	int getNumInputsmydspSIG0() {
		return 0;
		
	}
	int getNumOutputsmydspSIG0() {
		return 1;
		
	}
	int getInputRatemydspSIG0(int channel) {
		int rate;
		switch (channel) {
			default: {
				rate = -1;
				break;
			}
			
		}
		return rate;
		
	}
	int getOutputRatemydspSIG0(int channel) {
		int rate;
		switch (channel) {
			case 0: {
				rate = 0;
				break;
			}
			default: {
				rate = -1;
				break;
			}
			
		}
		return rate;
		
	}
	
	void instanceInitmydspSIG0(int samplingFreq) {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			iRec0[l0] = 0;
			
		}
		
	}
	
	void fillmydspSIG0(int count, double* output) {
		for (int i = 0; (i < count); i = (i + 1)) {
			iRec0[0] = (iRec0[1] + 1);
			output[i] = std::sin((9.5873799242852573e-05 * double((iRec0[0] + -1))));
			iRec0[1] = iRec0[0];
			
		}
		
	}

};

mydspSIG0* newmydspSIG0() { return (mydspSIG0*)new mydspSIG0(); }
void deletemydspSIG0(mydspSIG0* dsp) { delete dsp; }

class Dsp {
private:
	uint32_t fSamplingFreq;
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT	*fHslider0_;
	double fConst0;
	double fConst1;
	double fRec1[2];
	double fConst2;
	double fConst3;
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT	*fHslider1_;
	FAUSTFLOAT fCheckbox0;
	FAUSTFLOAT	*fCheckbox0_;
	FAUSTFLOAT fCheckbox1;
	FAUSTFLOAT	*fCheckbox1_;
	FAUSTFLOAT fCheckbox2;
	FAUSTFLOAT	*fCheckbox2_;
	FAUSTFLOAT fCheckbox3;
	FAUSTFLOAT	*fCheckbox3_;
	double fRec3[2];
	double fConst4;
	double fRec4[2];
	double fConst5;
	FAUSTFLOAT fHslider2;
	FAUSTFLOAT	*fHslider2_;
	double fRec6[2];
	double fRec2[3];
	double fRec7[3];
	double fRec8[3];
	double fRec9[3];
	double fRec10[3];
	double fRec11[3];
	double TET;
	double ref_freq;
	double ref_note;
	mydspSIG0* sig0;
	double ftbl0mydspSIG0[65536];

	void connect(uint32_t port,void* data);
	void clear_state_f();
	void init(uint32_t samplingFreq);
	void compute(int count, FAUSTFLOAT *output0, FAUSTFLOAT *output1);
public:
	static void clear_state_f_static(Dsp*);
	static void init_static(uint32_t samplingFreq, Dsp*);
	static void compute_static(int count, FAUSTFLOAT *output0, FAUSTFLOAT *output1, Dsp*);
	static void del_instance(Dsp *p);
	static void connect_static(uint32_t port,void* data, Dsp *p);
	Dsp();
	~Dsp();
};


Dsp::Dsp() :
sig0(newmydspSIG0())
{

}

Dsp::~Dsp() 
{

}

inline void Dsp::clear_state_f()
{
	for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) fRec1[l1] = 0.0;
	for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) fRec3[l2] = 0.0;
	for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) fRec4[l3] = 0.0;
	for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) fRec6[l4] = 0.0;
	for (int l5 = 0; (l5 < 3); l5 = (l5 + 1)) fRec2[l5] = 0.0;
	for (int l6 = 0; (l6 < 3); l6 = (l6 + 1)) fRec7[l6] = 0.0;
	for (int l7 = 0; (l7 < 3); l7 = (l7 + 1)) fRec8[l7] = 0.0;
	for (int l8 = 0; (l8 < 3); l8 = (l8 + 1)) fRec9[l8] = 0.0;
	for (int l9 = 0; (l9 < 3); l9 = (l9 + 1)) fRec10[l9] = 0.0;
	for (int l10 = 0; (l10 < 3); l10 = (l10 + 1)) fRec11[l10] = 0.0;
}

void Dsp::clear_state_f_static(Dsp *p)
{
	p->clear_state_f();
}

inline void Dsp::init(uint32_t samplingFreq)
{
	sig0->instanceInitmydspSIG0(samplingFreq);
	sig0->fillmydspSIG0(65536, ftbl0mydspSIG0);
	deletemydspSIG0(sig0);
	fSamplingFreq = samplingFreq;
	fConst0 = std::min<double>(192000.0, std::max<double>(1.0, double(fSamplingFreq)));
	fConst1 = (6.0 / fConst0);
	fConst2 = std::exp((0.0 - (100.0 / fConst0)));
	fConst3 = (1.0 - fConst2);
	fConst4 = (1.0 / fConst0);
	fConst5 = (3.1415926535897931 / fConst0);
	fHslider0 = FAUSTFLOAT(80.0);
	fHslider1 = FAUSTFLOAT(0.90000000000000002);
	fCheckbox0 = FAUSTFLOAT(0.0);
	fHslider2 = FAUSTFLOAT(0.0);
	TET = 12.0;
	ref_freq = 440.0;
	ref_note = 69.0;
	clear_state_f();
}

void Dsp::init_static(uint32_t samplingFreq, Dsp *p)
{
	p->init(samplingFreq);
}

void always_inline Dsp::compute(int count, FAUSTFLOAT *output0, FAUSTFLOAT *output1)
{
#define fHslider0 (*fHslider0_)
#define fHslider1 (*fHslider1_)
#define fCheckbox0 (*fCheckbox0_)
#define fCheckbox1 (*fCheckbox1_)
#define fCheckbox2 (*fCheckbox2_)
#define fCheckbox3 (*fCheckbox3_)
#define fHslider2 (*fHslider2_)

	switch(int(fCheckbox1)) {
		case(0):
		TET = 12.0;
		ref_freq = 440.0;
		ref_note = 69.0;
		break;
		case(1):
		TET = 12.0;
		ref_freq = 440.0;
		ref_note = 69.0;
		break;
		case(2):
		TET = 19.0;
		ref_freq = 329.63;
		ref_note = 60.0;
		break;
		case(3):
		TET = 24.0;
		ref_freq = 220.0;
		ref_note = 57.0;
		break;
		case(4):
		TET = 31.0;
		ref_freq = 196.0;
		ref_note = 55.0;
		break;
		case(5):
		TET = 41.0;
		ref_freq = 164.81;
		ref_note = 52.0;
		break;
		case(6):
		TET = 53.0;
		ref_freq = 146.83;
		ref_note = 50.0;
		break;
		default:
		TET = 12.0;
		ref_freq = 440.0;
		ref_note = 69.0;
		break;
	}

	double fSlow0 = int(fCheckbox1) ? double(ref_freq * pow(2.0, (double(int(fHslider0- ref_note))/TET))) :
		double(ref_freq * pow(2.0, (fHslider0- ref_note)/TET));

	int panic_gate = int(fCheckbox0 * fCheckbox3);
	double gate = panic_gate ?  1.0 : std::max<double>(0.0,std::min<double>(1.0, double(fCheckbox0)+fRec11[2]))* fCheckbox3;
	double fSlow1 = (fConst3 * (double(fHslider1)*0.1 *gate));
	double fSlow2 = (0.0010000000000000009 * double(fHslider2));
	for (int i = 0; (i < count); i = (i + 1)) {
		fRec11[0] = panic_gate ? 1.0 : (fRec11[2] - (0.0002 - fCheckbox2*0.0002));
		fRec1[0] = (fConst1 + (fRec1[1] - std::floor((fConst1 + fRec1[1]))));
		double fTemp0 = (fSlow0 * ((0.013000000000000001 * ftbl0mydspSIG0[int((65536.0 * fRec1[0]))]) + 1.0));
		double fTemp1 = ((0.003666666666666667 * (400.0 - fTemp0)) + 3.0);
		fRec3[0] = (fSlow1 + (fConst2 * fRec3[1]));
		double fTemp2 = std::max<double>(9.9999999999999995e-08, std::fabs(fTemp0));
		double fTemp3 = (fRec4[1] + (fConst4 * fTemp2));
		double fTemp4 = (fTemp3 + -1.0);
		int iTemp5 = (fTemp4 < 0.0);
		fRec4[0] = (iTemp5?fTemp3:fTemp4);
		double fRec5 = (iTemp5?fTemp3:(fTemp3 + (fTemp4 * (1.0 - (fConst0 / fTemp2)))));
		double fTemp6 = (fRec3[0] * ((2.0 * fRec5) + -1.0));
		fRec6[0] = (fSlow2 + (0.999 * fRec6[1]));
		double fTemp7 = (fRec6[0] + 10.0);
		int iTemp8 = (fTemp7 < 23.0);
		int iTemp9 = (fTemp7 < 24.0);
		double fTemp10 = (fRec6[0] + -13.0);
		int iTemp11 = (fTemp7 < 22.0);
		double fTemp12 = (fRec6[0] + -12.0);
		int iTemp13 = (fTemp7 < 21.0);
		double fTemp14 = (fRec6[0] + -11.0);
		int iTemp15 = (fTemp7 < 20.0);
		double fTemp16 = (fRec6[0] + -10.0);
		int iTemp17 = (fTemp7 < 19.0);
		double fTemp18 = (fRec6[0] + -9.0);
		int iTemp19 = (fTemp7 < 18.0);
		double fTemp20 = (fRec6[0] + -8.0);
		int iTemp21 = (fTemp7 < 17.0);
		double fTemp22 = (fRec6[0] + -7.0);
		int iTemp23 = (fTemp7 < 16.0);
		double fTemp24 = (fRec6[0] + -6.0);
		double fTemp25 = (80.0 * fTemp24);
		int iTemp26 = (fTemp7 < 15.0);
		double fTemp27 = (fRec6[0] + -5.0);
		int iTemp28 = (fTemp7 < 14.0);
		double fTemp29 = (fRec6[0] + -4.0);
		int iTemp30 = (fTemp7 < 13.0);
		double fTemp31 = (fRec6[0] + -3.0);
		int iTemp32 = (fTemp7 < 12.0);
		double fTemp33 = (fRec6[0] + -2.0);
		int iTemp34 = (fTemp7 < 11.0);
		double fTemp35 = (fRec6[0] + -1.0);
		int iTemp36 = (fTemp7 < 10.0);
		int iTemp37 = (fTemp7 < 9.0);
		double fTemp38 = (fRec6[0] + 1.0);
		int iTemp39 = (fTemp7 < 8.0);
		double fTemp40 = (fRec6[0] + 2.0);
		double fTemp41 = (50.0 * fTemp40);
		int iTemp42 = (fTemp7 < 7.0);
		double fTemp43 = (fRec6[0] + 3.0);
		int iTemp44 = (fTemp7 < 6.0);
		double fTemp45 = (fRec6[0] + 4.0);
		int iTemp46 = (fTemp7 < 5.0);
		double fTemp47 = (fRec6[0] + 5.0);
		int iTemp48 = (fTemp7 < 4.0);
		double fTemp49 = (fRec6[0] + 6.0);
		int iTemp50 = (fTemp7 < 3.0);
		double fTemp51 = (fRec6[0] + 7.0);
		int iTemp52 = (fTemp7 < 2.0);
		double fTemp53 = (fRec6[0] + 8.0);
		int iTemp54 = (fTemp7 < 1.0);
		double fTemp55 = (fRec6[0] + 9.0);
		int iTemp56 = (fTemp7 < 0.0);
		double fTemp57 = (iTemp8?(iTemp11?(iTemp13?(iTemp15?(iTemp17?(iTemp19?(iTemp21?(iTemp23?(iTemp26?(iTemp28?(iTemp30?(iTemp32?(iTemp34?(iTemp36?(iTemp37?(iTemp39?(iTemp42?(iTemp44?(iTemp46?(iTemp48?(iTemp50?(iTemp52?(iTemp54?(iTemp56?800.0:(iTemp54?(800.0 - (400.0 * fTemp7)):400.0)):(iTemp52?(400.0 - (50.0 * fTemp55)):350.0)):(iTemp50?((100.0 * fTemp53) + 350.0):450.0)):(iTemp48?(450.0 - (125.0 * fTemp51)):325.0)):(iTemp46?((275.0 * fTemp49) + 325.0):600.0)):(iTemp44?(600.0 - (200.0 * fTemp47)):400.0)):(iTemp42?(400.0 - (150.0 * fTemp45)):250.0)):(iTemp39?((150.0 * fTemp43) + 250.0):400.0)):(iTemp37?(400.0 - fTemp41):350.0)):(iTemp36?((310.0 * fTemp38) + 350.0):660.0)):(iTemp34?(660.0 - (220.0 * fRec6[0])):440.0)):(iTemp32?(440.0 - (170.0 * fTemp35)):270.0)):(iTemp30?((160.0 * fTemp33) + 270.0):430.0)):(iTemp28?(430.0 - (60.0 * fTemp31)):370.0)):(iTemp26?((430.0 * fTemp29) + 370.0):800.0)):(iTemp23?(800.0 - (450.0 * fTemp27)):350.0)):(iTemp21?(350.0 - fTemp25):270.0)):(iTemp19?((180.0 * fTemp22) + 270.0):450.0)):(iTemp17?(450.0 - (125.0 * fTemp20)):325.0)):(iTemp15?(325.0 * (fTemp18 + 1.0)):650.0)):(iTemp13?(650.0 - (250.0 * fTemp16)):400.0)):(iTemp11?(400.0 - (110.0 * fTemp14)):290.0)):(iTemp8?((110.0 * fTemp12) + 290.0):400.0)):(iTemp9?(400.0 - (50.0 * fTemp10)):350.0));
		double fTemp58 = ((fTemp57 <= fTemp0)?fTemp0:fTemp57);
		double fTemp59 = std::tan((fConst5 * fTemp58));
		double fTemp60 = (1.0 / fTemp59);
		double fTemp61 = (20.0 * fTemp16);
		double fTemp62 = (20.0 * fTemp27);
		double fTemp63 = (10.0 * fRec6[0]);
		double fTemp64 = (10.0 * fTemp49);
		double fTemp65 = (20.0 * fTemp51);
		double fTemp66 = (20.0 * fTemp53);
		double fTemp67 = (20.0 * fTemp7);
		double fTemp68 = ((iTemp8?(iTemp11?(iTemp13?(iTemp15?(iTemp17?(iTemp19?(iTemp21?(iTemp23?(iTemp26?(iTemp28?(iTemp30?(iTemp32?(iTemp34?(iTemp36?(iTemp37?(iTemp39?(iTemp42?(iTemp44?(iTemp46?(iTemp48?(iTemp50?(iTemp52?(iTemp54?(iTemp56?80.0:(iTemp54?(80.0 - fTemp67):60.0)):(iTemp52?(60.0 - (10.0 * fTemp55)):50.0)):(iTemp50?(fTemp66 + 50.0):70.0)):(iTemp48?(70.0 - fTemp65):50.0)):(iTemp46?(fTemp64 + 50.0):60.0)):(iTemp44?(60.0 - (20.0 * fTemp47)):40.0)):(iTemp42?((20.0 * fTemp45) + 40.0):60.0)):(iTemp39?(60.0 - (20.0 * fTemp43)):40.0)):40.0):(iTemp36?(40.0 * (fTemp38 + 1.0)):80.0)):(iTemp34?(80.0 - fTemp63):70.0)):(iTemp32?(70.0 - (30.0 * fTemp35)):40.0)):40.0):40.0):(iTemp26?(40.0 * (fTemp29 + 1.0)):80.0)):(iTemp23?(80.0 - fTemp62):60.0)):60.0):(iTemp19?(60.0 - (20.0 * fTemp22)):40.0)):(iTemp17?((10.0 * fTemp20) + 40.0):50.0)):50.0):(iTemp13?(fTemp61 + 50.0):70.0)):(iTemp11?(70.0 - (30.0 * fTemp14)):40.0)):(iTemp8?((30.0 * fTemp12) + 40.0):70.0)):(iTemp9?(70.0 - (30.0 * fTemp10)):40.0)) / fTemp58);
		double fTemp69 = (((fTemp60 + fTemp68) / fTemp59) + 1.0);
		fRec2[0] = (fTemp6 - (((fRec2[2] * (((fTemp60 - fTemp68) / fTemp59) + 1.0)) + (2.0 * (fRec2[1] * (1.0 - (1.0 / mydsp_faustpower2_f(fTemp59)))))) / fTemp69));
		double fTemp70 = (fTemp59 * fTemp69);
		double fTemp71 = (iTemp8?(iTemp11?(iTemp13?(iTemp15?(iTemp17?(iTemp19?(iTemp21?(iTemp23?(iTemp26?(iTemp28?(iTemp30?(iTemp32?(iTemp34?(iTemp36?(iTemp37?(iTemp39?(iTemp42?(iTemp44?(iTemp46?(iTemp48?(iTemp50?(iTemp52?(iTemp54?(iTemp56?1150.0:(iTemp54?((450.0 * fTemp7) + 1150.0):1600.0)):(iTemp52?((100.0 * fTemp55) + 1600.0):1700.0)):(iTemp50?(1700.0 - (900.0 * fTemp53)):800.0)):(iTemp48?(800.0 - (100.0 * fTemp51)):700.0)):(iTemp46?((340.0 * fTemp49) + 700.0):1040.0)):(iTemp44?((580.0 * fTemp47) + 1040.0):1620.0)):(iTemp42?((130.0 * fTemp45) + 1620.0):1750.0)):(iTemp39?(1750.0 - (1000.0 * fTemp43)):750.0)):(iTemp37?(750.0 - (150.0 * fTemp40)):600.0)):(iTemp36?((520.0 * fTemp38) + 600.0):1120.0)):(iTemp34?((680.0 * fRec6[0]) + 1120.0):1800.0)):(iTemp32?((50.0 * fTemp35) + 1800.0):1850.0)):(iTemp30?(1850.0 - (1030.0 * fTemp33)):820.0)):(iTemp28?(820.0 - (190.0 * fTemp31)):630.0)):(iTemp26?((520.0 * fTemp29) + 630.0):1150.0)):(iTemp23?((850.0 * fTemp27) + 1150.0):2000.0)):(iTemp21?((140.0 * fTemp24) + 2000.0):2140.0)):(iTemp19?(2140.0 - (1340.0 * fTemp22)):800.0)):(iTemp17?(800.0 - (100.0 * fTemp20)):700.0)):(iTemp15?((380.0 * fTemp18) + 700.0):1080.0)):(iTemp13?((620.0 * fTemp16) + 1080.0):1700.0)):(iTemp11?((170.0 * fTemp14) + 1700.0):1870.0)):(iTemp8?(1870.0 - (1070.0 * fTemp12)):800.0)):(iTemp9?(800.0 - (200.0 * fTemp10)):600.0));
		double fTemp72 = std::tan((fConst5 * fTemp71));
		double fTemp73 = (1.0 / fTemp72);
		double fTemp74 = (10.0 * fTemp12);
		double fTemp75 = (10.0 * fTemp16);
		double fTemp76 = (10.0 * fTemp38);
		double fTemp77 = (10.0 * fTemp47);
		double fTemp78 = ((iTemp8?(iTemp11?(iTemp13?(iTemp15?(iTemp17?(iTemp19?(iTemp21?(iTemp23?(iTemp26?(iTemp28?(iTemp30?(iTemp32?(iTemp34?(iTemp36?(iTemp37?(iTemp39?(iTemp42?(iTemp44?(iTemp46?(iTemp48?(iTemp50?(iTemp52?(iTemp54?(iTemp56?90.0:(iTemp54?(90.0 - (10.0 * fTemp7)):80.0)):(iTemp52?((20.0 * fTemp55) + 80.0):100.0)):(iTemp50?(100.0 - fTemp66):80.0)):(iTemp48?(80.0 - fTemp65):60.0)):(iTemp46?(fTemp64 + 60.0):70.0)):(iTemp44?(fTemp77 + 70.0):80.0)):(iTemp42?((10.0 * fTemp45) + 80.0):90.0)):(iTemp39?(90.0 - (10.0 * fTemp43)):80.0)):80.0):(iTemp36?(fTemp76 + 80.0):90.0)):(iTemp34?(90.0 - fTemp63):80.0)):(iTemp32?((10.0 * fTemp35) + 80.0):90.0)):(iTemp30?(90.0 - (10.0 * fTemp33)):80.0)):(iTemp28?(80.0 - (20.0 * fTemp31)):60.0)):(iTemp26?((30.0 * fTemp29) + 60.0):90.0)):(iTemp23?((10.0 * fTemp27) + 90.0):100.0)):(iTemp21?(100.0 - (10.0 * fTemp24)):90.0)):(iTemp19?(90.0 - (10.0 * fTemp22)):80.0)):(iTemp17?(80.0 - (20.0 * fTemp20)):60.0)):(iTemp15?((30.0 * fTemp18) + 60.0):90.0)):(iTemp13?(90.0 - fTemp75):80.0)):(iTemp11?((10.0 * fTemp14) + 80.0):90.0)):(iTemp8?(90.0 - fTemp74):80.0)):(iTemp9?(80.0 - (20.0 * fTemp10)):60.0)) / fTemp71);
		double fTemp79 = (((fTemp73 + fTemp78) / fTemp72) + 1.0);
		fRec7[0] = (fTemp6 - (((fRec7[2] * (((fTemp73 - fTemp78) / fTemp72) + 1.0)) + (2.0 * (fRec7[1] * (1.0 - (1.0 / mydsp_faustpower2_f(fTemp72)))))) / fTemp79));
		double fTemp80 = (iTemp8?(iTemp11?(iTemp13?(iTemp15?(iTemp17?(iTemp19?(iTemp21?(iTemp23?(iTemp26?(iTemp28?(iTemp30?(iTemp32?(iTemp34?(iTemp36?(iTemp37?(iTemp39?(iTemp42?(iTemp44?(iTemp46?(iTemp48?(iTemp50?(iTemp52?(iTemp54?(iTemp56?0.63095699999999999:(iTemp54?(0.63095699999999999 - (0.56786099999999995 * fTemp7)):0.063095999999999999)):(iTemp52?((0.036904000000000006 * fTemp55) + 0.063095999999999999):0.10000000000000001)):(iTemp50?((0.25481299999999996 * fTemp53) + 0.10000000000000001):0.35481299999999999)):(iTemp48?(0.35481299999999999 - (0.10362399999999999 * fTemp51)):0.251189)):(iTemp46?((0.19549500000000003 * fTemp49) + 0.251189):0.44668400000000003)):(iTemp44?(0.44668400000000003 - (0.19549500000000003 * fTemp47)):0.251189)):(iTemp42?(0.251189 - (0.21956599999999998 * fTemp45)):0.031622999999999998)):(iTemp39?((0.25021499999999997 * fTemp43) + 0.031622999999999998):0.28183799999999998)):(iTemp37?(0.28183799999999998 - (0.18183799999999997 * fTemp40)):0.10000000000000001)):(iTemp36?((0.40118700000000007 * fTemp38) + 0.10000000000000001):0.50118700000000005)):(iTemp34?(0.50118700000000005 - (0.30166100000000007 * fRec6[0])):0.19952600000000001)):(iTemp32?(0.19952600000000001 - (0.13643 * fTemp35)):0.063095999999999999)):(iTemp30?((0.25313200000000002 * fTemp33) + 0.063095999999999999):0.31622800000000001)):(iTemp28?(0.31622800000000001 - (0.216228 * fTemp31)):0.10000000000000001)):(iTemp26?((0.40118700000000007 * fTemp29) + 0.10000000000000001):0.50118700000000005)):(iTemp23?(0.50118700000000005 - (0.40118700000000007 * fTemp27)):0.10000000000000001)):(iTemp21?((0.15118899999999999 * fTemp24) + 0.10000000000000001):0.251189)):(iTemp19?((0.030648999999999982 * fTemp22) + 0.251189):0.28183799999999998)):(iTemp17?(0.28183799999999998 - (0.12334899999999999 * fTemp20)):0.15848899999999999)):(iTemp15?((0.34269800000000006 * fTemp18) + 0.15848899999999999):0.50118700000000005)):(iTemp13?(0.50118700000000005 - (0.30166100000000007 * fTemp16)):0.19952600000000001)):(iTemp11?(0.19952600000000001 - (0.021697999999999995 * fTemp14)):0.17782800000000001)):(iTemp8?((0.1384 * fTemp12) + 0.17782800000000001):0.31622800000000001)):(iTemp9?(0.31622800000000001 - (0.216228 * fTemp10)):0.10000000000000001));
		double fTemp81 = (fTemp72 * fTemp79);
		double fTemp82 = (100.0 * fTemp10);
		double fTemp83 = (50.0 * fTemp18);
		double fTemp84 = (50.0 * fRec6[0]);
		double fTemp85 = (iTemp8?(iTemp11?(iTemp13?(iTemp15?(iTemp17?(iTemp19?(iTemp21?(iTemp23?(iTemp26?(iTemp28?(iTemp30?(iTemp32?(iTemp34?(iTemp36?(iTemp37?(iTemp39?(iTemp42?(iTemp44?(iTemp46?(iTemp48?(iTemp50?(iTemp52?(iTemp54?(iTemp56?2800.0:(iTemp54?(2800.0 - (100.0 * fTemp7)):2700.0)):2700.0):(iTemp50?((130.0 * fTemp53) + 2700.0):2830.0)):(iTemp48?(2830.0 - (300.0 * fTemp51)):2530.0)):(iTemp46?(2530.0 - (280.0 * fTemp49)):2250.0)):(iTemp44?((150.0 * fTemp47) + 2250.0):2400.0)):(iTemp42?((200.0 * fTemp45) + 2400.0):2600.0)):(iTemp39?(2600.0 - (200.0 * fTemp43)):2400.0)):2400.0):(iTemp36?((350.0 * fTemp38) + 2400.0):2750.0)):(iTemp34?(2750.0 - fTemp84):2700.0)):(iTemp32?((200.0 * fTemp35) + 2700.0):2900.0)):(iTemp30?(2900.0 - (200.0 * fTemp33)):2700.0)):(iTemp28?((50.0 * fTemp31) + 2700.0):2750.0)):(iTemp26?((150.0 * fTemp29) + 2750.0):2900.0)):(iTemp23?(2900.0 - (100.0 * fTemp27)):2800.0)):(iTemp21?((150.0 * fTemp24) + 2800.0):2950.0)):(iTemp19?(2950.0 - (120.0 * fTemp22)):2830.0)):(iTemp17?(2830.0 - (130.0 * fTemp20)):2700.0)):(iTemp15?(2700.0 - fTemp83):2650.0)):(iTemp13?(2650.0 - (50.0 * fTemp16)):2600.0)):(iTemp11?((200.0 * fTemp14) + 2600.0):2800.0)):(iTemp8?(2800.0 - (200.0 * fTemp12)):2600.0)):(iTemp9?(fTemp82 + 2600.0):2700.0));
		double fTemp86 = std::tan((fConst5 * fTemp85));
		double fTemp87 = (1.0 / fTemp86);
		double fTemp88 = (20.0 * fTemp29);
		double fTemp89 = (20.0 * fRec6[0]);
		double fTemp90 = (20.0 * fTemp38);
		double fTemp91 = (60.0 * fTemp49);
		double fTemp92 = ((iTemp8?(iTemp11?(iTemp13?(iTemp15?(iTemp17?(iTemp19?(iTemp21?(iTemp23?(iTemp26?(iTemp28?(iTemp30?(iTemp32?(iTemp34?(iTemp36?(iTemp37?(iTemp39?(iTemp42?(iTemp44?(iTemp46?(iTemp48?(iTemp50?(iTemp52?120.0:(iTemp50?(120.0 - fTemp66):100.0)):(iTemp48?((70.0 * fTemp51) + 100.0):170.0)):(iTemp46?(170.0 - fTemp91):110.0)):(iTemp44?(110.0 - fTemp77):100.0)):100.0):100.0):100.0):(iTemp36?(fTemp90 + 100.0):120.0)):(iTemp34?(120.0 - fTemp89):100.0)):100.0):100.0):100.0):(iTemp26?(fTemp88 + 100.0):120.0)):120.0):(iTemp21?(120.0 - (20.0 * fTemp24)):100.0)):100.0):(iTemp17?((70.0 * fTemp20) + 100.0):170.0)):(iTemp15?(170.0 - fTemp83):120.0)):(iTemp13?(120.0 - fTemp61):100.0)):100.0):100.0):100.0) / fTemp85);
		double fTemp93 = (((fTemp87 + fTemp92) / fTemp86) + 1.0);
		fRec8[0] = (fTemp6 - (((fRec8[2] * (((fTemp87 - fTemp92) / fTemp86) + 1.0)) + (2.0 * (fRec8[1] * (1.0 - (1.0 / mydsp_faustpower2_f(fTemp86)))))) / fTemp93));
		double fTemp94 = (iTemp19?((0.029314000000000007 * fTemp22) + 0.050118999999999997):0.079433000000000004);
		double fTemp95 = (iTemp8?(iTemp11?(iTemp13?(iTemp15?(iTemp17?(iTemp19?(iTemp21?(iTemp23?(iTemp26?(iTemp28?(iTemp30?(iTemp32?(iTemp34?(iTemp36?(iTemp37?(iTemp39?(iTemp42?(iTemp44?(iTemp46?(iTemp48?(iTemp50?(iTemp52?(iTemp54?(iTemp56?0.10000000000000001:(iTemp54?(0.10000000000000001 - (0.068377000000000007 * fTemp7)):0.031622999999999998)):0.031622999999999998):(iTemp50?((0.12686599999999998 * fTemp53) + 0.031622999999999998):0.15848899999999999)):(iTemp48?(0.15848899999999999 - (0.12686599999999998 * fTemp51)):0.031622999999999998)):(iTemp46?((0.32318999999999998 * fTemp49) + 0.031622999999999998):0.35481299999999999)):0.35481299999999999):(iTemp42?(0.35481299999999999 - (0.196324 * fTemp45)):0.15848899999999999)):(iTemp39?(0.15848899999999999 - (0.069363999999999995 * fTemp43)):0.089124999999999996)):(iTemp37?(0.089124999999999996 - (0.064005999999999993 * fTemp40)):0.025118999999999999)):(iTemp36?((0.045675999999999994 * fTemp38) + 0.025118999999999999):0.070794999999999997)):(iTemp34?((0.055098000000000008 * fRec6[0]) + 0.070794999999999997):0.125893)):(iTemp32?(0.125893 - (0.062797000000000006 * fTemp35)):0.063095999999999999)):(iTemp30?(0.063095999999999999 - (0.012977000000000002 * fTemp33)):0.050118999999999997)):(iTemp28?((0.020676 * fTemp31) + 0.050118999999999997):0.070794999999999997)):(iTemp26?(0.070794999999999997 - (0.045675999999999994 * fTemp29)):0.025118999999999999)):(iTemp23?((0.15270900000000001 * fTemp27) + 0.025118999999999999):0.17782800000000001)):(iTemp21?(0.17782800000000001 - (0.12770900000000002 * fTemp24)):0.050118999999999997)):fTemp94):(iTemp17?(0.079433000000000004 - (0.061650000000000003 * fTemp20)):0.017783)):(iTemp15?((0.42890100000000003 * fTemp18) + 0.017783):0.44668400000000003)):(iTemp13?(0.44668400000000003 - (0.19549500000000003 * fTemp16)):0.251189)):(iTemp11?(0.251189 - (0.12529599999999999 * fTemp14)):0.125893)):(iTemp8?((0.12529599999999999 * fTemp12) + 0.125893):0.251189)):(iTemp9?(0.251189 - (0.109935 * fTemp10)):0.14125399999999999));
		double fTemp96 = (fTemp86 * fTemp93);
		double fTemp97 = (350.0 * fTemp47);
		double fTemp98 = (iTemp8?(iTemp11?(iTemp13?(iTemp15?(iTemp17?(iTemp19?(iTemp21?(iTemp23?(iTemp26?(iTemp28?(iTemp30?(iTemp32?(iTemp34?(iTemp36?(iTemp37?(iTemp39?(iTemp42?(iTemp44?(iTemp46?(iTemp48?(iTemp50?(iTemp52?(iTemp54?(iTemp56?3500.0:(iTemp54?(3500.0 - (200.0 * fTemp7)):3300.0)):(iTemp52?((400.0 * fTemp55) + 3300.0):3700.0)):(iTemp50?(3700.0 - (200.0 * fTemp53)):3500.0)):3500.0):(iTemp46?(3500.0 - (1050.0 * fTemp49)):2450.0)):(iTemp44?(fTemp97 + 2450.0):2800.0)):(iTemp42?((250.0 * fTemp45) + 2800.0):3050.0)):(iTemp39?(3050.0 - (450.0 * fTemp43)):2600.0)):(iTemp37?((75.0 * fTemp40) + 2600.0):2675.0)):(iTemp36?((325.0 * fTemp38) + 2675.0):3000.0)):3000.0):(iTemp32?((350.0 * fTemp35) + 3000.0):3350.0)):(iTemp30?(3350.0 - (350.0 * fTemp33)):3000.0)):3000.0):(iTemp26?((900.0 * fTemp29) + 3000.0):3900.0)):(iTemp23?(3900.0 - (300.0 * fTemp27)):3600.0)):(iTemp21?((300.0 * fTemp24) + 3600.0):3900.0)):(iTemp19?(3900.0 - (100.0 * fTemp22)):3800.0)):3800.0):(iTemp15?(3800.0 - (900.0 * fTemp18)):2900.0)):(iTemp13?((300.0 * fTemp16) + 2900.0):3200.0)):(iTemp11?((50.0 * fTemp14) + 3200.0):3250.0)):(iTemp8?(3250.0 - (450.0 * fTemp12)):2800.0)):(iTemp9?(fTemp82 + 2800.0):2900.0));
		double fTemp99 = std::tan((fConst5 * fTemp98));
		double fTemp100 = (1.0 / fTemp99);
		double fTemp101 = ((iTemp8?(iTemp11?(iTemp13?(iTemp15?(iTemp17?(iTemp19?(iTemp21?(iTemp23?(iTemp26?(iTemp28?(iTemp30?(iTemp32?(iTemp34?(iTemp36?(iTemp37?(iTemp39?(iTemp42?(iTemp44?(iTemp46?(iTemp48?(iTemp50?(iTemp52?(iTemp54?(iTemp56?130.0:(iTemp54?(fTemp67 + 130.0):150.0)):150.0):(iTemp50?(150.0 - fTemp66):130.0)):(iTemp48?((50.0 * fTemp51) + 130.0):180.0)):(iTemp46?(180.0 - fTemp91):120.0)):120.0):120.0):120.0):120.0):(iTemp36?(fTemp76 + 120.0):130.0)):(iTemp34?(130.0 - fTemp63):120.0)):120.0):120.0):120.0):(iTemp26?((10.0 * fTemp29) + 120.0):130.0)):(iTemp23?(fTemp62 + 130.0):150.0)):(iTemp21?(150.0 - (30.0 * fTemp24)):120.0)):120.0):(iTemp17?((60.0 * fTemp20) + 120.0):180.0)):(iTemp15?(180.0 - fTemp83):130.0)):(iTemp13?(130.0 - fTemp75):120.0)):120.0):(iTemp8?(fTemp74 + 120.0):130.0)):(iTemp9?(130.0 - (10.0 * fTemp10)):120.0)) / fTemp98);
		double fTemp102 = (((fTemp100 + fTemp101) / fTemp99) + 1.0);
		fRec9[0] = (fTemp6 - (((fRec9[2] * (((fTemp100 - fTemp101) / fTemp99) + 1.0)) + (2.0 * (fRec9[1] * (1.0 - (1.0 / mydsp_faustpower2_f(fTemp99)))))) / fTemp102));
		double fTemp103 = (iTemp32?(0.10000000000000001 - (0.084151000000000004 * fTemp35)):0.015848999999999999);
		double fTemp104 = (iTemp8?(iTemp11?(iTemp13?(iTemp15?(iTemp17?(iTemp19?(iTemp21?(iTemp23?(iTemp26?(iTemp28?(iTemp30?(iTemp32?(iTemp34?(iTemp36?(iTemp37?(iTemp39?(iTemp42?(iTemp44?(iTemp46?(iTemp48?(iTemp50?(iTemp52?(iTemp54?(iTemp56?0.015848999999999999:(iTemp54?((0.0019340000000000017 * fTemp7) + 0.015848999999999999):0.017783)):(iTemp52?(0.017783 - (0.0019340000000000017 * fTemp55)):0.015848999999999999)):(iTemp50?((0.023962000000000001 * fTemp53) + 0.015848999999999999):0.039810999999999999)):(iTemp48?(0.039810999999999999 - (0.029810999999999997 * fTemp51)):0.01)):(iTemp46?((0.34481299999999998 * fTemp49) + 0.01):0.35481299999999999)):(iTemp44?(0.35481299999999999 - (0.10362399999999999 * fTemp47)):0.251189)):(iTemp42?(0.251189 - (0.17175599999999999 * fTemp45)):0.079433000000000004)):(iTemp39?((0.020567000000000002 * fTemp43) + 0.079433000000000004):0.10000000000000001)):(iTemp37?(0.10000000000000001 - (0.060189000000000006 * fTemp40)):0.039810999999999999)):(iTemp36?((0.023285 * fTemp38) + 0.039810999999999999):0.063095999999999999)):(iTemp34?((0.036904000000000006 * fRec6[0]) + 0.063095999999999999):0.10000000000000001)):fTemp103):(iTemp30?((0.063584000000000002 * fTemp33) + 0.015848999999999999):0.079433000000000004)):(iTemp28?(0.079433000000000004 - (0.047810000000000005 * fTemp31)):0.031622999999999998)):(iTemp26?((0.068377000000000007 * fTemp29) + 0.031622999999999998):0.10000000000000001)):(iTemp23?(0.10000000000000001 - (0.090000000000000011 * fTemp27)):0.01)):(iTemp21?((0.040118999999999995 * fTemp24) + 0.01):0.050118999999999997)):fTemp94):(iTemp17?(0.079433000000000004 - (0.069433000000000009 * fTemp20)):0.01)):(iTemp15?((0.38810699999999998 * fTemp18) + 0.01):0.39810699999999999)):(iTemp13?(0.39810699999999999 - (0.19858099999999998 * fTemp16)):0.19952600000000001)):(iTemp11?(0.19952600000000001 - (0.099526000000000003 * fTemp14)):0.10000000000000001)):(iTemp8?((0.15118899999999999 * fTemp12) + 0.10000000000000001):0.251189)):(iTemp9?(0.251189 - (0.051662999999999987 * fTemp10)):0.19952600000000001));
		double fTemp105 = (fTemp99 * fTemp102);
		double fTemp106 = (iTemp8?(iTemp11?(iTemp13?(iTemp15?(iTemp17?(iTemp19?(iTemp21?(iTemp23?(iTemp26?(iTemp28?(iTemp30?(iTemp32?(iTemp34?(iTemp36?(iTemp37?(iTemp39?(iTemp42?(iTemp44?(iTemp46?(iTemp48?4950.0:(iTemp46?(4950.0 - (2200.0 * fTemp49)):2750.0)):(iTemp44?(fTemp97 + 2750.0):3100.0)):(iTemp42?((240.0 * fTemp45) + 3100.0):3340.0)):(iTemp39?(3340.0 - (440.0 * fTemp43)):2900.0)):(iTemp37?(fTemp41 + 2900.0):2950.0)):(iTemp36?((400.0 * fTemp38) + 2950.0):3350.0)):(iTemp34?(3350.0 - fTemp84):3300.0)):(iTemp32?((290.0 * fTemp35) + 3300.0):3590.0)):(iTemp30?(3590.0 - (290.0 * fTemp33)):3300.0)):(iTemp28?((100.0 * fTemp31) + 3300.0):3400.0)):(iTemp26?((1550.0 * fTemp29) + 3400.0):4950.0)):4950.0):4950.0):4950.0):4950.0):(iTemp15?(4950.0 - (1700.0 * fTemp18)):3250.0)):(iTemp13?((330.0 * fTemp16) + 3250.0):3580.0)):(iTemp11?(3580.0 - (40.0 * fTemp14)):3540.0)):(iTemp8?(3540.0 - (540.0 * fTemp12)):3000.0)):(iTemp9?((300.0 * fTemp10) + 3000.0):3300.0));
		double fTemp107 = std::tan((fConst5 * fTemp106));
		double fTemp108 = (1.0 / fTemp107);
		double fTemp109 = ((iTemp8?(iTemp11?(iTemp13?(iTemp15?(iTemp17?(iTemp19?(iTemp21?(iTemp23?(iTemp26?(iTemp28?(iTemp30?(iTemp32?(iTemp34?(iTemp36?(iTemp37?(iTemp39?(iTemp42?(iTemp44?(iTemp46?(iTemp48?(iTemp50?(iTemp52?(iTemp54?(iTemp56?140.0:(iTemp54?((60.0 * fTemp7) + 140.0):200.0)):200.0):(iTemp50?(200.0 - (65.0 * fTemp53)):135.0)):(iTemp48?((65.0 * fTemp51) + 135.0):200.0)):(iTemp46?(200.0 - (70.0 * fTemp49)):130.0)):(iTemp44?(130.0 - fTemp77):120.0)):120.0):120.0):120.0):(iTemp36?(fTemp90 + 120.0):140.0)):(iTemp34?(140.0 - fTemp89):120.0)):120.0):120.0):120.0):(iTemp26?(fTemp88 + 120.0):140.0)):(iTemp23?((60.0 * fTemp27) + 140.0):200.0)):(iTemp21?(200.0 - fTemp25):120.0)):120.0):(iTemp17?((80.0 * fTemp20) + 120.0):200.0)):(iTemp15?(200.0 - (60.0 * fTemp18)):140.0)):(iTemp13?(140.0 - fTemp61):120.0)):120.0):(iTemp8?((15.0 * fTemp12) + 120.0):135.0)):(iTemp9?(135.0 - (15.0 * fTemp10)):120.0)) / fTemp106);
		double fTemp110 = (((fTemp108 + fTemp109) / fTemp107) + 1.0);
		fRec10[0] = (fTemp6 - (((fRec10[2] * (((fTemp108 - fTemp109) / fTemp107) + 1.0)) + (2.0 * (fRec10[1] * (1.0 - (1.0 / mydsp_faustpower2_f(fTemp107)))))) / fTemp110));
		double fTemp111 = (iTemp8?(iTemp11?(iTemp13?(iTemp15?(iTemp17?(iTemp19?(iTemp21?(iTemp23?(iTemp26?(iTemp28?(iTemp30?(iTemp32?(iTemp34?(iTemp36?(iTemp37?(iTemp39?(iTemp42?(iTemp44?(iTemp46?(iTemp48?(iTemp50?(iTemp52?0.001:(iTemp50?((0.00077800000000000005 * fTemp53) + 0.001):0.0017780000000000001)):(iTemp48?(0.0017780000000000001 - (0.001147 * fTemp51)):0.00063100000000000005)):(iTemp46?((0.099368999999999999 * fTemp49) + 0.00063100000000000005):0.10000000000000001)):(iTemp44?((0.025892999999999999 * fTemp47) + 0.10000000000000001):0.125893)):(iTemp42?(0.125893 - (0.086082000000000006 * fTemp45)):0.039810999999999999)):(iTemp39?(0.039810999999999999 - (0.029810999999999997 * fTemp43)):0.01)):(iTemp37?((0.0058489999999999983 * fTemp40) + 0.01):0.015848999999999999)):(iTemp36?(0.015848999999999999 - (0.003259999999999999 * fTemp38)):0.012588999999999999)):(iTemp34?((0.087411000000000003 * fRec6[0]) + 0.012588999999999999):0.10000000000000001)):fTemp103):(iTemp30?((0.004104 * fTemp33) + 0.015848999999999999):0.019952999999999999)):0.019952999999999999):(iTemp26?(0.019952999999999999 - (0.016791 * fTemp29)):0.0031619999999999999)):(iTemp23?(0.0031619999999999999 - (0.0015769999999999998 * fTemp27)):0.001585)):(iTemp21?((0.004725 * fTemp24) + 0.001585):0.0063099999999999996)):(iTemp19?(0.0063099999999999996 - (0.0031479999999999998 * fTemp22)):0.0031619999999999999)):(iTemp17?(0.0031619999999999999 - (0.0021619999999999999 * fTemp20)):0.001)):(iTemp15?((0.078433000000000003 * fTemp18) + 0.001):0.079433000000000004)):(iTemp13?((0.020567000000000002 * fTemp16) + 0.079433000000000004):0.10000000000000001)):(iTemp11?(0.10000000000000001 - (0.068377000000000007 * fTemp14)):0.031622999999999998)):(iTemp8?((0.018495999999999999 * fTemp12) + 0.031622999999999998):0.050118999999999997)):0.050118999999999997);
		double fTemp112 = (fTemp107 * fTemp110);
		double fTemp113 = ((fTemp1 * (((((fRec2[0] / fTemp70) + ((fRec7[0] * fTemp80) / fTemp81)) + ((fRec8[0] * fTemp95) / fTemp96)) + ((fRec9[0] * fTemp104) / fTemp105)) + ((fRec10[0] * fTemp111) / fTemp112))) + (((((fRec2[2] * (0.0 - (fTemp1 / fTemp70))) + (fRec7[2] * (0.0 - ((fTemp1 * fTemp80) / fTemp81)))) + (fRec8[2] * (0.0 - ((fTemp1 * fTemp95) / fTemp96)))) + (fRec9[2] * (0.0 - ((fTemp1 * fTemp104) / fTemp105)))) + (fRec10[2] * (0.0 - ((fTemp1 * fTemp111) / fTemp112)))));
		output0[i] = FAUSTFLOAT(fTemp113);
		output1[i] = FAUSTFLOAT(fTemp113);
		fRec1[1] = fRec1[0];
		fRec3[1] = fRec3[0];
		fRec4[1] = fRec4[0];
		fRec6[1] = fRec6[0];
		fRec2[2] = fRec2[1];
		fRec2[1] = fRec2[0];
		fRec7[2] = fRec7[1];
		fRec7[1] = fRec7[0];
		fRec8[2] = fRec8[1];
		fRec8[1] = fRec8[0];
		fRec9[2] = fRec9[1];
		fRec9[1] = fRec9[0];
		fRec10[2] = fRec10[1];
		fRec10[1] = fRec10[0];
		fRec11[2] = fRec11[1];
		fRec11[1] = fRec11[0];
	}
#undef fHslider0
#undef fHslider1
#undef fCheckbox0
#undef fCheckbox1
#undef fCheckbox2
#undef fCheckbox3
#undef fHslider2
}

void __rt_func Dsp::compute_static(int count, FAUSTFLOAT *output0, FAUSTFLOAT *output1, Dsp *p)
{
	p->compute(count, output0, output1);
}


void Dsp::connect(uint32_t port,void* data)
{
	switch ((PortIndex)port)
	{
	case NOTE: 
		fHslider0_ = (float*)data; // , 80.0, 20.0, 220.0, 1.01 
		break;
	case GAIN: 
		fHslider1_ = (float*)data; // , 0.2, 0.0, 1.0, 0.01 
		break;
	case GATE: 
		fCheckbox0_ = (float*)data; // , 0.0, 0.0, 1.0, 1.0 
		break;
	case VOWEL: 
		fHslider2_ = (float*)data; // , 0.0, 0.0, 4.0, 0.01 
		break;
	case SCALE: 
		fCheckbox1_ = (float*)data; // , 0.0, 0.0, 6.0, 1.0 
		break;
	case SUSTAIN: 
		fCheckbox2_ = (float*)data; // , 0.0, 0.0, 6.0, 1.0 
	case PANIC: 
		fCheckbox3_ = (float*)data; // , 0.0, 0.0, 6.0, 1.0 
		break;
		break;
	default:
		break;
	}
}

void Dsp::connect_static(uint32_t port,void* data, Dsp *p)
{
	p->connect(port, data);
}


Dsp *plugin() {
	return new Dsp();
}

void Dsp::del_instance(Dsp *p)
{
	delete p;
}

/*
typedef enum
{
   NOTE, 
   GAIN, 
   GATE, 
   VOWEL, 
} PortIndex;
*/

} // end namespace xmonk
