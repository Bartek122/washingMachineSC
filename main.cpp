#include <systemc.h>
#include "userInput.cpp"
#include "userInterface.cpp"
#include "washingMachine.cpp"

int sc_main(int argc, char* argv[])
{
	sc_clock clk;
	sc_signal<int> keyMask, program;
	sc_signal<bool> errFlag;

	userInputModule userInput("userInput");
	userInterfaceModule userInterface("userInterface");
	washingMachineModule waschingMachine("waschingMachine");

	userInput(clk, keyMask);
	userInterface(program, errFlag);
	waschingMachine(keyMask, program, errFlag);
	userInterface.renderProgram();
	sc_start();

	system("pause");
	return(0);
}