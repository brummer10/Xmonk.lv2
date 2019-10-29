// generated from file './/stereodelay.dsp' by dsp2cc:
// Code generated with Faust 2.15.11 (https://faust.grame.fr)


namespace stereodelay {

class Dsp {
private:
	uint32_t fSamplingFreq;
	int IOTA;
	double fVec0[65536];
	double fConst0;
	double fRec0[2];
	double fRec1[2];
	double fRec2[2];
	double fRec3[2];
	double fVec1[65536];

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
	for (int l0 = 0; (l0 < 65536); l0 = (l0 + 1)) fVec0[l0] = 0.0;
	for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) fRec0[l1] = 0.0;
	for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) fRec1[l2] = 0.0;
	for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) fRec2[l3] = 0.0;
	for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) fRec3[l4] = 0.0;
	for (int l5 = 0; (l5 < 65536); l5 = (l5 + 1)) fVec1[l5] = 0.0;
}

void Dsp::clear_state_f_static(Dsp *p)
{
	p->clear_state_f();
}

inline void Dsp::init(uint32_t samplingFreq)
{
	fSamplingFreq = samplingFreq;
	fConst0 = (0.14999999999999999 * std::min<double>(192000.0, std::max<double>(1.0, double(fSamplingFreq))));
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
		fVec0[(IOTA & 65535)] = fTemp0;
		double fTemp1 = ((fRec0[1] != 0.0)?(((fRec1[1] > 0.0) & (fRec1[1] < 1.0))?fRec0[1]:0.0):(((fRec1[1] == 0.0) & (fConst0 != fRec2[1]))?0.0009765625:(((fRec1[1] == 1.0) & (fConst0 != fRec3[1]))?-0.0009765625:0.0)));
		fRec0[0] = fTemp1;
		fRec1[0] = std::max<double>(0.0, std::min<double>(1.0, (fRec1[1] + fTemp1)));
		fRec2[0] = (((fRec1[1] >= 1.0) & (fRec3[1] != fConst0))?fConst0:fRec2[1]);
		fRec3[0] = (((fRec1[1] <= 0.0) & (fRec2[1] != fConst0))?fConst0:fRec3[1]);
		int iTemp2 = int(std::min<double>(62144.0, std::max<double>(0.0, fRec2[0])));
		double fTemp3 = (1.0 - fRec1[0]);
		int iTemp4 = int(std::min<double>(62144.0, std::max<double>(0.0, fRec3[0])));
		output0[i] = FAUSTFLOAT((((fVec0[((IOTA - iTemp2) & 65535)] * fTemp3) + (fRec1[0] * fVec0[((IOTA - iTemp4) & 65535)])) + fTemp0));
		double fTemp5 = double(input1[i]);
		fVec1[(IOTA & 65535)] = fTemp5;
		output1[i] = FAUSTFLOAT((((fTemp3 * fVec1[((IOTA - iTemp2) & 65535)]) + (fRec1[0] * fVec1[((IOTA - iTemp4) & 65535)])) + fTemp5));
		IOTA = (IOTA + 1);
		fRec0[1] = fRec0[0];
		fRec1[1] = fRec1[0];
		fRec2[1] = fRec2[0];
		fRec3[1] = fRec3[0];
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

} // end namespace stereodelay
