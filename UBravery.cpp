//Ultimate Bravery: UBravery.cpp
//(C) 2017 Oskar Kaczmarek
//Methods description is avaliable in UBravery.h file

#include "UBravery.h"
#include <conio.h>
UBravery::UBravery()
{	
	//////////Version//////////
	clog << "Checking data version...";
	cout << "Checking data version" << endl;
	if (loadData("Data\\patch", 0) == 1) return;
	if (sDataVersion != "1.0")
	{
		cerr << "Invalid version of \"Data\" folder! Please re-download it (It will be in the same place as generator)";
		clog << endl << "Invalid data version: " << sDataVersion << " != 1.0" << endl;
		error = 1;
		cin.get();
		return;
	}
	clog << " Done!" << endl;
	//////////Champions//////////
	clog << "Loading champions...";
	cout << "Loading champions" << endl;
	if (loadData("Data\\Champions\\melee", 1) == 1) return;
	if (loadData("Data\\Champions\\ranged", 7) == 1) return;
	//////////Boots//////////
	clog << "Loading items: boots...";
	cout << "Loading items: boots" << endl;
	if (loadData("Data\\Items\\boots", 2) == 1) return;
	//////////Items: SR//////////
	clog << "Loading items: SR...";
	cout << "Loading items: SR" << endl;
	if (loadData("Data\\Items\\SR", 3) == 1) return;
	//////////Items: TT//////////
	clog << "Loading items: TT...";
	cout << "Loading items: TT" << endl;
	if (loadData("Data\\Items\\TT", 4) == 1) return;
	 //////////Items: ARAM//////////
	clog << "Loading items: ARAM...";
	cout << "Loading items: ARAM" << endl;
	if (loadData("Data\\Items\\ARAM", 5) == 1) return;
	 //////////Masteries//////////
	clog << "Loading masteries...";
	cout << "Loading masteries" << endl;
	if (loadData("Data\\masteries", 6) == 1) return;
	//////////Adjectives//////////
	clog << "Loading adjectives...";
	cout << "Loading adjectives" << endl;
	if (loadData("Data\\adjectives", 8) == 1) return;
}

int UBravery::loadData(string filename, int element)
{
	string line; //bufor
	int iCounter = 0; //lines counter
	clog << endl << "Opening file: " << filename << endl;
	ifstream ifFile(filename); //opens a file on specifed path
	if (ifFile.is_open()) //This if checks if file is open
	{
		clog << "Checking records... ";
		while (getline(ifFile, line)) iCounter++; //counting lines
		clog << iCounter << " records found." << endl;
		ifFile.close();
		ifFile.open(filename); //re-open the file to be in the beginning of them (ios::beg doesn't work ): )
		switch (element) //elements are described in cases
		{
		case 0: //Data Version
		{
			clog << "Reading data...";
			getline(ifFile, sPatch); 
			getline(ifFile, sDataVersion); 
			break;
		}
		case 1: //Melee Champions
		{
			clog << "Allocating memory." << endl;
			sChampionsMelee = new string[iCounter];	//dynamicaly creates the array
			clog << "Reading data...";
			for (int i = 0; i < iCounter; i++) getline(ifFile, sChampionsMelee[i]); //filling array
			iChampsMelee = iCounter; //sets the array size to int
			clog << " Done!";
			break; 
		}						//all next cases does the same as case 1, but uses diffrent variables
		case 2: //Boots
		{
			clog << "Allocating memory." << endl;
			sBoots = new string[iCounter];
			clog << "Reading data...";
			for (int i = 0; i < iCounter; i++) getline(ifFile, sBoots[i]);
			iBoots = iCounter;
			clog << " Done!" << endl;
			break;
		}
		case 3: //SR items
		{
			clog << "Allocating memory." << endl;
			sItemsSR = new string[iCounter];
			clog << "Reading data...";
			for (int i = 0; i < iCounter; i++) getline(ifFile, sItemsSR[i]);
			iItemsSR = iCounter;
			clog << " Done!" << endl;
			break;
		}
		case 4: //TT items
		{
			clog << "Allocating memory." << endl;
			sItemsTT = new string[iCounter];
			clog << "Reading data...";
			for (int i = 0; i < iCounter; i++) getline(ifFile, sItemsTT[i]);
			iItemsTT = iCounter;
			clog << " Done!" << endl;
			break;
		}
		case 5: //HW items
		{
			clog << "Allocating memory." << endl;
			sItemsARAM = new string[iCounter];
			clog << "Reading data...";
			for (int i = 0; i < iCounter; i++) getline(ifFile, sItemsARAM[i]);
			iItemsARAM = iCounter;
			clog << " Done!" << endl;
			break;
		}
		case 6: //Masteries
		{
			clog << "Allocating memory." << endl;
			sMasteries = new string[iCounter];
			clog << "Reading data...";
			for (int i = 0; i < iCounter; i++) getline(ifFile, sMasteries[i]);
			iMasteries = iCounter;
			clog << " Done!" << endl;
			break;
		}
		case 7: //Ranged champions
		{
			clog << "Allocating memory." << endl;
			sChampionsRanged = new string[iCounter];
			clog << "Reading data...";
			for (int i = 0; i < iCounter; i++) getline(ifFile, sChampionsRanged[i]);
			iChampsRanged = iCounter;
			clog << " Done!" << endl;
			break;
		}
		case 8: //Adjectives (like Feeder Yasuo)
		{
			clog << "Allocating memory." << endl;
			sAdjectives = new string[iCounter];
			clog << "Reading data...";
			for (int i = 0; i < iCounter; i++) getline(ifFile, sAdjectives[i]);
			iAdjectives = iCounter;
			clog << " Done!" << endl;
			break;
		}
		}
		ifFile.close();
		return 0;
	}
	else //if (ifFile.is_open())
	{
		cerr << "Cannot open file: " <<filename<< endl;
		clog << "ERROR: Cannot open file: " << filename << endl;
		error = 1;
		ifFile.close();
		cin.get();
		return error;
	}
}

void UBravery::showVersion()
{	//this text is shown always on top of the window (except credits, which owns extended version)
	cout << "Ultimate Bravery" << endl;
	cout << "v. "<<appversion << endl;
	cout << "League Patch: " << sPatch << endl << endl;
}

void UBravery::credits()
{
	clear();
	cout << "Ultimate Bravery" << endl;
	cout << "v. " << appversion << endl;
	cout << "For League patch: " << sPatch << endl;
	cout << "Based on: http://www.ultimate-bravery.com/?lang=en" << endl << endl;
	cout << "Main developer: Oskar 'okg' Kaczmarek" << endl;
	cout << "Community manager: Rados³aw 'Fradzio' Go³ecki" << endl;
	cout << "Testers:\nKacper 'Wymiatacz' Dziubkowski" << endl;
	cout << "Marcin 'Atom' Dziubkowski" << endl;
	cout << "Rados³aw 'Fradzio' Go³ecki" << endl;
	cout << "Jan 'Pinjesz' Jeschke" << endl;
	cout << "Szymon 'Mnieciu' Podgórzec" << endl;
	cout << "Remigiusz 'Dorthion' W³oszczyñski" << endl;
	cout << endl << "Press ENTER to back. \n>";
	cin.get();
}

void UBravery::rules()
{
	clear();
	showVersion();
	cout << " RULES" << endl;
	cout << " 1. Love your champion, you will" << endl;
	cout << " Once you press the button to start your Ultimate Bravery, you cannot go back !" << endl;
	cout << " You have to choose the champion displayed on your screen, even if an atomic bomb is detonating next to you!" << endl << endl;
	cout << " 2. Activate your summoner spells, you will" << endl;
	cout << " Even if you fall on Clarity/Barrier, it is your duty to make good use throughout the game." << endl;
	cout << " In addition, it is a favor you did the God of Courage : the more your summoners are bad, the more victory will be rewarding." << endl << endl;
	cout << " 3. Max your main ability first, you will" << endl;
	cout << " If you want to prove that you've got balls (or ovaries if you're a girl), put all your skill points into the spell that you were assigned (Q,W or E)." << endl;
	cout << " Dishonor to your family if you choose another spell while your selection is available !" << endl << endl;
	cout << " 4. Buy items in the right order, you will" << endl;
	cout << " Having boots in the early game roxx ! " << endl << " Doran's are for weaklings. You must run quickly to rush into the crowd! Being first in line is your goal." << endl;
	cout << " Then you must purchase the items in the order listed, always starting from the number 1. " << endl << " If you have a stack item to last, that's even better: you will not surrender at 20 minutes." << endl << endl;
	cout << " 5. Forget wards, you will" << endl;
	cout << " What is the advantage of seeing the enemy arrive?" << endl << " I imagine that at night, you do not turn on the light in your home to see the obstacles. Do the same on the Fields of Justice! " << endl;
	cout << " If you have doubts about facechecking a bush, charge into it. You'll be set!" << endl << endl;
	cout << " Source: http://www.ultimate-bravery.com/rules.php?lang=en" << endl;
	cout << " Press ENTER to back.\n>";
	cin.get();
}

UBravery::~UBravery()
{
	//Deletes all dynamically allocated memory
	delete[] sChampionsMelee;
	delete[] sChampionsRanged;
	delete[] sBoots; 
	delete[] sItemsSR;
	delete[] sItemsTT;
	delete[] sItemsARAM;
	delete[] sMasteries;
	delete[] sAdjectives;
}

void clear()
{
	COORD topLeft = { 0, 0 };
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen;
	DWORD written;

	GetConsoleScreenBufferInfo(console, &screen);
	FillConsoleOutputCharacterA(
		console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	FillConsoleOutputAttribute(
		console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
		screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	SetConsoleCursorPosition(console, topLeft);
}

void UBravery::extras()
{
	int a = 1;
	while (true)
	{
		system("cls");
		showVersion();
		cout << "Extras menu" << endl << endl;
		cout << "Champion blacklist [";
		if (a == 1) cout << "*]" << endl; else cout << " ]" << endl;
		cout << "Rules              [";
		if (a == 2) cout << "*]" << endl; else cout << " ]" << endl;
		cout << "Extras             [";
		if (a == 3) cout << "*]" << endl; else cout << " ]" << endl;
		cout << endl;
		cout << "Exit               [";
		if (a == 0) cout << "*]" << endl; else cout << " ]" << endl;
		int y = _getch();
		switch (y)
		{
		case 72: //ARROW UP
			if (a == 0) a = 3;
			else if (a != 1) a--;
			break;
		case 80: //ARROW DOWN
			if (a == 3) a = 0;
			else if (a != 0) a++;
			break;
		case 13: //ENTER
			switch (a)
			{
			case 1: blacklist(); break;
			case 2: rules(); break;
			case 3: credits(); break;
			case 0: return;
			}
		}
	}
}

void UBravery::blacklist()
{
	clog << "BCS opened" << endl;
	while (true)
	{
		bool isDone = false;
		ifstream blacklist("Data\\Champions\\blacklist");
		string line; int lines = 0;
		while (getline(blacklist, line)) ++lines;
		blacklist.close();
		blacklist.open("Data\\Champions\\blacklist");
		string *list = new string[lines];
		for (int i = 0; i < lines; i++)
		{
			getline(blacklist, line);
			list[i] = line;
		}
		blacklist.close();
		clear();
		showVersion();
		cout << "Banned champions:" << endl;
		for (int i = 0; i < lines; i++) cout << list[i] << endl;
		cout << endl << "Enter a champion name to block/unblock, or 'E' to back." << endl;
		string pick;
		cout << ">";
		getline(cin, pick);
		if (pick == "E" || pick == "e")
		{
			delete[] list;
			clog << "BCS closed" << endl;
			return;
		}
		for (int i = 0; i < lines; i++)
			if (list[i] == pick)
			{
				list[i] = "";
				ofstream ofBlacklist("Data\\Champions\\blacklist");
				for (int j = 0; j < lines; j++)
					if (list[j] != "") ofBlacklist << list[j] << endl;
				ofBlacklist.close();
				isDone = true;
				clog << "Champion " << pick << " removed from blacklist" << endl;
			}
		if (isDone) continue;
		for (int i = 0; i < iChampsMelee; i++)
			if (pick == sChampionsMelee[i])
			{
				ofstream ofBlacklist("Data\\Champions\\blacklist");
				for (int j = 0; j < lines; j++) ofBlacklist << list[j] << endl;
				ofBlacklist << pick << endl;
				ofBlacklist.close();
				isDone = true;
				clog << "Champion " << pick << " added to blacklist" << endl;
			}
		if (isDone) continue;
		for (int i = 0; i < iChampsRanged; i++)
			if (pick == sChampionsRanged[i])
			{
				ofstream ofBlacklist("Data\\Champions\\blacklist");
				for (int j = 0; j < lines; j++) ofBlacklist << list[j] << endl;
				ofBlacklist << pick << endl;
				ofBlacklist.close();
				clog << "Champion " << pick << " added to blacklist" << endl;
				isDone = true;
			}
		continue;
	}
}