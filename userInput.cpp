#ifndef USER_INPUT
#define USER_INPUT

#include <systemc.h>
#include <conio.h>

#define KEYCODE_OFFSET 49

SC_MODULE(userInputModule)
{
	sc_in_clk clk;
	sc_inout<int> keyMask;

	void handleInput()
	{
		const int key = getch() - KEYCODE_OFFSET;
		if (key >= 0 && key < 4)
			keyMask.write(keyMask.read() ^ (1 << key));
	}

	SC_CTOR(userInputModule)
	{
		SC_METHOD(handleInput);
		dont_initialize();
		sensitive << clk;
	}
};
#endif //USER_INPUT
