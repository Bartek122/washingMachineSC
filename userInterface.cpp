#ifndef USER_INTERFACE
#define USER_INTERFACE

#include <systemc.h>

SC_MODULE(userInterfaceModule)
{
	sc_in<int> program;
	sc_in<bool> errFlag;

	const char* prgLine[5] = { "| 1  2  3  4 |",
							"|[1] 2  3  4 |",
							"| 1 [2] 3  4 |",
							"| 1  2 [3] 4 |",
							"| 1  2  3 [4]|" };

	const char* topLine = " ____________ ";
	const char* errLine = "|  [ERROR!]  |";
	const char* spcLine = "|            |";
	const char* wmtLine = "|    ____    |";
	const char* wmmLine = "|   /    \\   |";
	const char* wmbLine = "|   \\____/   |";
	const char* botLine = "|____________|";

	void renderProgram()
	{
		system("cls");
		cout << topLine << endl;
		cout << prgLine[program.read()] << endl;
		cout << spcLine << endl;
		cout << wmtLine << endl;
		cout << wmmLine << endl;
		cout << wmbLine << endl;
		cout << botLine << endl;
	}

	void renderError()
	{
		system("cls");
		cout << topLine << endl;
		cout << errLine << endl;
		cout << spcLine << endl;
		cout << wmtLine << endl;
		cout << wmmLine << endl;
		cout << wmbLine << endl;
		cout << botLine << endl;
	}

	SC_CTOR(userInterfaceModule)
	{
		SC_METHOD(renderProgram);
		dont_initialize();
		sensitive << program;
		SC_METHOD(renderError);
		dont_initialize();
		sensitive << errFlag;
	}
};
#endif //USER_INTERFACE
