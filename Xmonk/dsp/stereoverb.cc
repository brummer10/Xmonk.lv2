// generated from file './/stereoverb.dsp' by dsp2cc:
// Code generated with Faust 2.15.11 (https://faust.grame.fr)


namespace stereoverb {

class Dsp {
private:
	uint32_t fSamplingFreq;
	double fRec9[2];
	int IOTA;
	double fVec0[2048];
	double fRec8[2];
	double fRec11[2];
	double fVec1[2048];
	double fRec10[2];
	double fRec13[2];
	double fVec2[2048];
	double fRec12[2];
	double fRec15[2];
	double fVec3[2048];
	double fRec14[2];
	double fRec17[2];
	double fVec4[2048];
	double fRec16[2];
	double fRec19[2];
	double fVec5[2048];
	double fRec18[2];
	double fRec21[2];
	double fVec6[2048];
	double fRec20[2];
	double fRec23[2];
	double fVec7[2048];
	double fRec22[2];
	double fVec8[1024];
	double fRec6[2];
	double fVec9[512];
	double fRec4[2];
	double fVec10[512];
	double fRec2[2];
	double fVec11[256];
	double fRec0[2];
	double fRec33[2];
	double fVec12[2048];
	double fRec32[2];
	double fRec35[2];
	double fVec13[2048];
	double fRec34[2];
	double fRec37[2];
	double fVec14[2048];
	double fRec36[2];
	double fRec39[2];
	double fVec15[2048];
	double fRec38[2];
	double fRec41[2];
	double fVec16[2048];
	double fRec40[2];
	double fRec43[2];
	double fVec17[2048];
	double fRec42[2];
	double fRec45[2];
	double fVec18[2048];
	double fRec44[2];
	double fRec47[2];
	double fVec19[2048];
	double fRec46[2];
	double fVec20[1024];
	double fRec30[2];
	double fVec21[512];
	double fRec28[2];
	double fVec22[512];
	double fRec26[2];
	double fVec23[256];
	double fRec24[2];

	void connect(uint32_t port,void* data);
	void clear_state_f();
	void init(uint32_t samplingFreq);
	void compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *input1, FAUSTFLOAT *output0, FAUSTFLOAT *output1);
public:
	static void clear_state_f_static(Dsp*);
	static void init_static(uint32_t samplingFreq, Dsp*);
	static void compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *input1, FAUSTFLOAT *output0, FAUSTFLOAT *output1, Dsp*);
	static void del_instance(Dsp *p);
	static void connect_static(uint32_t port,void* data, Dsp *p);
	Dsp() {};
	~Dsp() {};
};

inline void Dsp::clear_state_f()
{
	for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) fRec9[l0] = 0.0;
	for (int l1 = 0; (l1 < 2048); l1 = (l1 + 1)) fVec0[l1] = 0.0;
	for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) fRec8[l2] = 0.0;
	for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) fRec11[l3] = 0.0;
	for (int l4 = 0; (l4 < 2048); l4 = (l4 + 1)) fVec1[l4] = 0.0;
	for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) fRec10[l5] = 0.0;
	for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) fRec13[l6] = 0.0;
	for (int l7 = 0; (l7 < 2048); l7 = (l7 + 1)) fVec2[l7] = 0.0;
	for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) fRec12[l8] = 0.0;
	for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) fRec15[l9] = 0.0;
	for (int l10 = 0; (l10 < 2048); l10 = (l10 + 1)) fVec3[l10] = 0.0;
	for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) fRec14[l11] = 0.0;
	for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) fRec17[l12] = 0.0;
	for (int l13 = 0; (l13 < 2048); l13 = (l13 + 1)) fVec4[l13] = 0.0;
	for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) fRec16[l14] = 0.0;
	for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) fRec19[l15] = 0.0;
	for (int l16 = 0; (l16 < 2048); l16 = (l16 + 1)) fVec5[l16] = 0.0;
	for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) fRec18[l17] = 0.0;
	for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) fRec21[l18] = 0.0;
	for (int l19 = 0; (l19 < 2048); l19 = (l19 + 1)) fVec6[l19] = 0.0;
	for (int l20 = 0; (l20 < 2); l20 = (l20 + 1)) fRec20[l20] = 0.0;
	for (int l21 = 0; (l21 < 2); l21 = (l21 + 1)) fRec23[l21] = 0.0;
	for (int l22 = 0; (l22 < 2048); l22 = (l22 + 1)) fVec7[l22] = 0.0;
	for (int l23 = 0; (l23 < 2); l23 = (l23 + 1)) fRec22[l23] = 0.0;
	for (int l24 = 0; (l24 < 1024); l24 = (l24 + 1)) fVec8[l24] = 0.0;
	for (int l25 = 0; (l25 < 2); l25 = (l25 + 1)) fRec6[l25] = 0.0;
	for (int l26 = 0; (l26 < 512); l26 = (l26 + 1)) fVec9[l26] = 0.0;
	for (int l27 = 0; (l27 < 2); l27 = (l27 + 1)) fRec4[l27] = 0.0;
	for (int l28 = 0; (l28 < 512); l28 = (l28 + 1)) fVec10[l28] = 0.0;
	for (int l29 = 0; (l29 < 2); l29 = (l29 + 1)) fRec2[l29] = 0.0;
	for (int l30 = 0; (l30 < 256); l30 = (l30 + 1)) fVec11[l30] = 0.0;
	for (int l31 = 0; (l31 < 2); l31 = (l31 + 1)) fRec0[l31] = 0.0;
	for (int l32 = 0; (l32 < 2); l32 = (l32 + 1)) fRec33[l32] = 0.0;
	for (int l33 = 0; (l33 < 2048); l33 = (l33 + 1)) fVec12[l33] = 0.0;
	for (int l34 = 0; (l34 < 2); l34 = (l34 + 1)) fRec32[l34] = 0.0;
	for (int l35 = 0; (l35 < 2); l35 = (l35 + 1)) fRec35[l35] = 0.0;
	for (int l36 = 0; (l36 < 2048); l36 = (l36 + 1)) fVec13[l36] = 0.0;
	for (int l37 = 0; (l37 < 2); l37 = (l37 + 1)) fRec34[l37] = 0.0;
	for (int l38 = 0; (l38 < 2); l38 = (l38 + 1)) fRec37[l38] = 0.0;
	for (int l39 = 0; (l39 < 2048); l39 = (l39 + 1)) fVec14[l39] = 0.0;
	for (int l40 = 0; (l40 < 2); l40 = (l40 + 1)) fRec36[l40] = 0.0;
	for (int l41 = 0; (l41 < 2); l41 = (l41 + 1)) fRec39[l41] = 0.0;
	for (int l42 = 0; (l42 < 2048); l42 = (l42 + 1)) fVec15[l42] = 0.0;
	for (int l43 = 0; (l43 < 2); l43 = (l43 + 1)) fRec38[l43] = 0.0;
	for (int l44 = 0; (l44 < 2); l44 = (l44 + 1)) fRec41[l44] = 0.0;
	for (int l45 = 0; (l45 < 2048); l45 = (l45 + 1)) fVec16[l45] = 0.0;
	for (int l46 = 0; (l46 < 2); l46 = (l46 + 1)) fRec40[l46] = 0.0;
	for (int l47 = 0; (l47 < 2); l47 = (l47 + 1)) fRec43[l47] = 0.0;
	for (int l48 = 0; (l48 < 2048); l48 = (l48 + 1)) fVec17[l48] = 0.0;
	for (int l49 = 0; (l49 < 2); l49 = (l49 + 1)) fRec42[l49] = 0.0;
	for (int l50 = 0; (l50 < 2); l50 = (l50 + 1)) fRec45[l50] = 0.0;
	for (int l51 = 0; (l51 < 2048); l51 = (l51 + 1)) fVec18[l51] = 0.0;
	for (int l52 = 0; (l52 < 2); l52 = (l52 + 1)) fRec44[l52] = 0.0;
	for (int l53 = 0; (l53 < 2); l53 = (l53 + 1)) fRec47[l53] = 0.0;
	for (int l54 = 0; (l54 < 2048); l54 = (l54 + 1)) fVec19[l54] = 0.0;
	for (int l55 = 0; (l55 < 2); l55 = (l55 + 1)) fRec46[l55] = 0.0;
	for (int l56 = 0; (l56 < 1024); l56 = (l56 + 1)) fVec20[l56] = 0.0;
	for (int l57 = 0; (l57 < 2); l57 = (l57 + 1)) fRec30[l57] = 0.0;
	for (int l58 = 0; (l58 < 512); l58 = (l58 + 1)) fVec21[l58] = 0.0;
	for (int l59 = 0; (l59 < 2); l59 = (l59 + 1)) fRec28[l59] = 0.0;
	for (int l60 = 0; (l60 < 512); l60 = (l60 + 1)) fVec22[l60] = 0.0;
	for (int l61 = 0; (l61 < 2); l61 = (l61 + 1)) fRec26[l61] = 0.0;
	for (int l62 = 0; (l62 < 256); l62 = (l62 + 1)) fVec23[l62] = 0.0;
	for (int l63 = 0; (l63 < 2); l63 = (l63 + 1)) fRec24[l63] = 0.0;
}

void Dsp::clear_state_f_static(Dsp *p)
{
	p->clear_state_f();
}

inline void Dsp::init(uint32_t samplingFreq)
{
	fSamplingFreq = samplingFreq;
			IOTA = 0;
	clear_state_f();
}

void Dsp::init_static(uint32_t samplingFreq, Dsp *p)
{
	p->init(samplingFreq);
}

void always_inline Dsp::compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *input1, FAUSTFLOAT *output0, FAUSTFLOAT *output1)
{
	for (int i = 0; (i < count); i = (i + 1)) {
		double fTemp0 = double(input0[i]);
		double fTemp1 = (0.0089999999999999993 * fTemp0);
		fRec9[0] = ((0.25 * fRec9[1]) + (0.75 * fRec8[1]));
		fVec0[(IOTA & 2047)] = (fTemp1 + (0.88200000000000001 * fRec9[0]));
		fRec8[0] = fVec0[((IOTA - 1139) & 2047)];
		fRec11[0] = ((0.25 * fRec11[1]) + (0.75 * fRec10[1]));
		fVec1[(IOTA & 2047)] = (fTemp1 + (0.88200000000000001 * fRec11[0]));
		fRec10[0] = fVec1[((IOTA - 1211) & 2047)];
		fRec13[0] = ((0.25 * fRec13[1]) + (0.75 * fRec12[1]));
		fVec2[(IOTA & 2047)] = (fTemp1 + (0.88200000000000001 * fRec13[0]));
		fRec12[0] = fVec2[((IOTA - 1300) & 2047)];
		fRec15[0] = ((0.25 * fRec15[1]) + (0.75 * fRec14[1]));
		fVec3[(IOTA & 2047)] = (fTemp1 + (0.88200000000000001 * fRec15[0]));
		fRec14[0] = fVec3[((IOTA - 1379) & 2047)];
		fRec17[0] = ((0.25 * fRec17[1]) + (0.75 * fRec16[1]));
		fVec4[(IOTA & 2047)] = (fTemp1 + (0.88200000000000001 * fRec17[0]));
		fRec16[0] = fVec4[((IOTA - 1445) & 2047)];
		fRec19[0] = ((0.25 * fRec19[1]) + (0.75 * fRec18[1]));
		fVec5[(IOTA & 2047)] = (fTemp1 + (0.88200000000000001 * fRec19[0]));
		fRec18[0] = fVec5[((IOTA - 1514) & 2047)];
		fRec21[0] = ((0.25 * fRec21[1]) + (0.75 * fRec20[1]));
		fVec6[(IOTA & 2047)] = (fTemp1 + (0.88200000000000001 * fRec21[0]));
		fRec20[0] = fVec6[((IOTA - 1580) & 2047)];
		fRec23[0] = ((0.25 * fRec23[1]) + (0.75 * fRec22[1]));
		fVec7[(IOTA & 2047)] = (fTemp1 + (0.88200000000000001 * fRec23[0]));
		fRec22[0] = fVec7[((IOTA - 1640) & 2047)];
		double fTemp2 = ((((((((fRec8[0] + fRec10[0]) + fRec12[0]) + fRec14[0]) + fRec16[0]) + fRec18[0]) + fRec20[0]) + fRec22[0]) - (0.5 * fRec6[1]));
		fVec8[(IOTA & 1023)] = fTemp2;
		fRec6[0] = fVec8[((IOTA - 579) & 1023)];
		double fRec7 = (0.5 * fTemp2);
		double fTemp3 = ((fRec7 + fRec6[1]) - (0.5 * fRec4[1]));
		fVec9[(IOTA & 511)] = fTemp3;
		fRec4[0] = fVec9[((IOTA - 464) & 511)];
		double fRec5 = (0.5 * fTemp3);
		double fTemp4 = ((fRec5 + fRec4[1]) - (0.5 * fRec2[1]));
		fVec10[(IOTA & 511)] = fTemp4;
		fRec2[0] = fVec10[((IOTA - 364) & 511)];
		double fRec3 = (0.5 * fTemp4);
		double fTemp5 = ((fRec3 + fRec2[1]) - (0.5 * fRec0[1]));
		fVec11[(IOTA & 255)] = fTemp5;
		fRec0[0] = fVec11[((IOTA - 248) & 255)];
		double fRec1 = (0.5 * fTemp5);
		output0[i] = FAUSTFLOAT(((fRec1 + fRec0[1]) + (0.64900000000000002 * fTemp0)));
		double fTemp6 = double(input1[i]);
		double fTemp7 = (0.0089999999999999993 * fTemp6);
		fRec33[0] = ((0.25 * fRec33[1]) + (0.75 * fRec32[1]));
		fVec12[(IOTA & 2047)] = (fTemp7 + (0.88200000000000001 * fRec33[0]));
		fRec32[0] = fVec12[((IOTA - 1139) & 2047)];
		fRec35[0] = ((0.25 * fRec35[1]) + (0.75 * fRec34[1]));
		fVec13[(IOTA & 2047)] = (fTemp7 + (0.88200000000000001 * fRec35[0]));
		fRec34[0] = fVec13[((IOTA - 1211) & 2047)];
		fRec37[0] = ((0.25 * fRec37[1]) + (0.75 * fRec36[1]));
		fVec14[(IOTA & 2047)] = (fTemp7 + (0.88200000000000001 * fRec37[0]));
		fRec36[0] = fVec14[((IOTA - 1300) & 2047)];
		fRec39[0] = ((0.25 * fRec39[1]) + (0.75 * fRec38[1]));
		fVec15[(IOTA & 2047)] = (fTemp7 + (0.88200000000000001 * fRec39[0]));
		fRec38[0] = fVec15[((IOTA - 1379) & 2047)];
		fRec41[0] = ((0.25 * fRec41[1]) + (0.75 * fRec40[1]));
		fVec16[(IOTA & 2047)] = (fTemp7 + (0.88200000000000001 * fRec41[0]));
		fRec40[0] = fVec16[((IOTA - 1445) & 2047)];
		fRec43[0] = ((0.25 * fRec43[1]) + (0.75 * fRec42[1]));
		fVec17[(IOTA & 2047)] = (fTemp7 + (0.88200000000000001 * fRec43[0]));
		fRec42[0] = fVec17[((IOTA - 1514) & 2047)];
		fRec45[0] = ((0.25 * fRec45[1]) + (0.75 * fRec44[1]));
		fVec18[(IOTA & 2047)] = (fTemp7 + (0.88200000000000001 * fRec45[0]));
		fRec44[0] = fVec18[((IOTA - 1580) & 2047)];
		fRec47[0] = ((0.25 * fRec47[1]) + (0.75 * fRec46[1]));
		fVec19[(IOTA & 2047)] = (fTemp7 + (0.88200000000000001 * fRec47[0]));
		fRec46[0] = fVec19[((IOTA - 1640) & 2047)];
		double fTemp8 = ((((((((fRec32[0] + fRec34[0]) + fRec36[0]) + fRec38[0]) + fRec40[0]) + fRec42[0]) + fRec44[0]) + fRec46[0]) - (0.5 * fRec30[1]));
		fVec20[(IOTA & 1023)] = fTemp8;
		fRec30[0] = fVec20[((IOTA - 579) & 1023)];
		double fRec31 = (0.5 * fTemp8);
		double fTemp9 = ((fRec31 + fRec30[1]) - (0.5 * fRec28[1]));
		fVec21[(IOTA & 511)] = fTemp9;
		fRec28[0] = fVec21[((IOTA - 464) & 511)];
		double fRec29 = (0.5 * fTemp9);
		double fTemp10 = ((fRec29 + fRec28[1]) - (0.5 * fRec26[1]));
		fVec22[(IOTA & 511)] = fTemp10;
		fRec26[0] = fVec22[((IOTA - 364) & 511)];
		double fRec27 = (0.5 * fTemp10);
		double fTemp11 = ((fRec27 + fRec26[1]) - (0.5 * fRec24[1]));
		fVec23[(IOTA & 255)] = fTemp11;
		fRec24[0] = fVec23[((IOTA - 248) & 255)];
		double fRec25 = (0.5 * fTemp11);
		output1[i] = FAUSTFLOAT(((fRec25 + fRec24[1]) + (0.64900000000000002 * fTemp6)));
		fRec9[1] = fRec9[0];
		IOTA = (IOTA + 1);
		fRec8[1] = fRec8[0];
		fRec11[1] = fRec11[0];
		fRec10[1] = fRec10[0];
		fRec13[1] = fRec13[0];
		fRec12[1] = fRec12[0];
		fRec15[1] = fRec15[0];
		fRec14[1] = fRec14[0];
		fRec17[1] = fRec17[0];
		fRec16[1] = fRec16[0];
		fRec19[1] = fRec19[0];
		fRec18[1] = fRec18[0];
		fRec21[1] = fRec21[0];
		fRec20[1] = fRec20[0];
		fRec23[1] = fRec23[0];
		fRec22[1] = fRec22[0];
		fRec6[1] = fRec6[0];
		fRec4[1] = fRec4[0];
		fRec2[1] = fRec2[0];
		fRec0[1] = fRec0[0];
		fRec33[1] = fRec33[0];
		fRec32[1] = fRec32[0];
		fRec35[1] = fRec35[0];
		fRec34[1] = fRec34[0];
		fRec37[1] = fRec37[0];
		fRec36[1] = fRec36[0];
		fRec39[1] = fRec39[0];
		fRec38[1] = fRec38[0];
		fRec41[1] = fRec41[0];
		fRec40[1] = fRec40[0];
		fRec43[1] = fRec43[0];
		fRec42[1] = fRec42[0];
		fRec45[1] = fRec45[0];
		fRec44[1] = fRec44[0];
		fRec47[1] = fRec47[0];
		fRec46[1] = fRec46[0];
		fRec30[1] = fRec30[0];
		fRec28[1] = fRec28[0];
		fRec26[1] = fRec26[0];
		fRec24[1] = fRec24[0];
	}
}

void __rt_func Dsp::compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *input1, FAUSTFLOAT *output0, FAUSTFLOAT *output1, Dsp *p)
{
	p->compute(count, input0, input1, output0, output1);
}


void Dsp::connect(uint32_t port,void* data)
{
	switch ((PortIndex)port)
	{
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
} PortIndex;
*/

} // end namespace stereoverb
