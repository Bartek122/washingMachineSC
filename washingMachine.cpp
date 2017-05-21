#ifndef WASHING_MACHINE
#define WASHING_MACHINE

#include <systemc.h>


SC_MODULE(washingMachineModule)
{
	sc_in<int> keyMask;
	sc_out<int> program;
	sc_inout<bool> errFlag;

	void handleInput()
	{
		switch (keyMask)
		{
		case 0:
			program.write(0);
			break;
		case 1:
			program.write(1);
			break;
		case 2:
			program.write(2);
			break;
		case 4:
			program.write(3);
			break;
		case 8:
			program.write(4);
			break;
		default:
			errFlag.write(!errFlag.read());
			break;
		}
	}

	SC_CTOR(washingMachineModule)
	{
		SC_METHOD(handleInput);
		dont_initialize();
		sensitive << keyMask;
	}
};
#endif //WASHING_MACHINE
