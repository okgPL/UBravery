//Ultimate Bravery: main.cpp
//(C) 2017 Oskar Kaczmarek

//Include class header
#include "UBravery.h"

int main()
{
	//Setting up console
	setlocale(LC_ALL, ""); //To correctly print characters in console (especially in Credits)
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //makes text white. REALLY white

	srand(GetTickCount()); //As a seed I used GetTickCount()

	//Initialization
	UBravery ub;	//Creates a class object
	/* If UBravery::error has a value other than 0, something went wrong durning initialization
	 * This if() checks that value and if it's other than 0 terminates the program */
	if (ub.error != 0) return ub.error; 

	/* Menu service code
	 * In infinite loop, prints the menu, waits for user pick and do it(or contniue loop if none of cases are correct) */
	for (;;)
	{
		clear();
		ub.showVersion();
		//Prints menu
		cout << "Select map:" << endl;
		cout << "Summoner's Rift: 1" << endl;
		cout << "The Twisted Treeline: 2" << endl;
		cout << "Howling Abyss: 3" << endl;
		cout << endl;
		cout << "Rules: 8" << endl;
		cout << "Credits: 9" << endl;
		cout << "Exit: 0" << endl << ">";
		//User pick
		char pick;
		cin >> pick;
		switch (pick)
		{
		case '1': ub.play(0); break; //SR
		case '2': ub.play(1); break; //TT
		case '3': ub.play(2); break; //HW (ARAM)
		case '8': ub.rules(); break; //Rules
		case '9': ub.credits(); break; //Credits
		case '0': return 0; break; //End the program
		}
		cin.get(); //This is need to prevent double-randomizing or fast quitting from rules/credits
	}
	return 0;
}