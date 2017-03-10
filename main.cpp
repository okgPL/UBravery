//Ultimate Bravery: main.cpp
//(C) 2017 Oskar Kaczmarek

//Include class header
#include "UBravery.h"
#include <time.h>
#pragma warning(disable : 4996)
int main()
{
	//log startup
	ofstream log( "log.txt");
	auto old_rdbuf = clog.rdbuf();
	clog.rdbuf(log.rdbuf());
	//First line of log: Time and date when created
	time_t czas;
	struct tm * ptr;
	time(&czas);
	ptr = localtime(&czas);
	char * data = asctime(ptr);

	clog <<"Log created on: "<< data << endl;
	clog << "Setting up console...";
	//Setting up console
	setlocale(LC_ALL, ""); //To correctly print characters in console (especially in Credits)
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //makes text white. REALLY white

	srand(GetTickCount()); //As a seed I used GetTickCount(). It's milisecnods after boot
	clog << " Done!" << endl << "Creating UB object:" << endl;
	//Initialization
	UBravery ub;	//Creates a class object
	/* If UBravery::error has a value other than 0, something went wrong durning initialization
	 * This instruction checks that value and if it's other than 0 terminates the program */
	if (ub.error != 0)
	{
		clog << "Initialization failed" << endl;
		return ub.error;
	}
	else clog << "Initialization done!" << endl;

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
		cout << "Extras: 4" << endl;
		cout << "Exit: 0" << endl << ">";
		//User pick
		char pick;
		cin >> pick;
		clog << "User select: " << pick << endl;
		switch (pick)
		{
		case '1': ub.play(0); break; //SR
		case '2': ub.play(1); break; //TT
		case '3': ub.play(2); break; //HW (ARAM)
		case '4': ub.extras(); break;
		case '0':
		{
			clog.rdbuf(old_rdbuf);
			return 0; //End the program
		}
		}
		cin.get(); //This is required to prevent double-randomizing or fast quitting from rules/credits
	}
	return 0;
}