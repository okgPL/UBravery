//Ultimate Bravery: UBravery.cpp
//(C) 2017 Oskar Kaczmarek
//Methods description is avaliable in UBravery.h file

#include "UBravery.h"

UBravery::UBravery()
{	
	//////////Version//////////
	cout << "Checking data version" << endl;
	if (loadData("Data\\patch", 0) == 1) return;
	if (sDataVersion != "1.0")
	{
		cerr << "Invalid version of \"Data\" folder! Please re-download it (It will be in the same place as generator)";
		error = 1;
		cin.get();
		return;
	}
	//////////Champions//////////
	cout << "Loading champions" << endl;
	if (loadData("Data\\Champions\\Melee", 1) == 1) return;
	if (loadData("Data\\Champions\\Ranged", 7) == 1) return;
	//////////Boots//////////
	cout << "Loading items: boots" << endl;
	if (loadData("Data\\Items\\boots", 2) == 1) return;
	//////////Items: SR//////////
	cout << "Loading items: SR" << endl;
	if (loadData("Data\\Items\\SR", 3) == 1) return;
	//////////Items: TT//////////
	cout << "Loading items: TT" << endl;
	if (loadData("Data\\Items\\TT", 4) == 1) return;
	 //////////Items: ARAM//////////
	cout << "Loading items: ARAM" << endl;
	if (loadData("Data\\Items\\ARAM", 5) == 1) return;
	 //////////Masteries//////////
	cout << "Loading masteries" << endl;
	if (loadData("Data\\masteries", 6) == 1) return;
	//////////Adjectives//////////
	cout << "Loading adjectives" << endl;
	if (loadData("Data\\adjectives", 8) == 1) return;
}

int UBravery::loadData(string filename, int element)
{
	string line; //bufor
	int iCounter = 0; //lines counter
	ifstream ifFile(filename); //opens a file on specifed path
	if (ifFile.is_open()) //This if checks if file is open
	{
		while (getline(ifFile, line)) iCounter++; //counting lines
		ifFile.close();
		ifFile.open(filename); //re-open the file to be in the beginning of them (ios::beg doesn't work ): )
		switch (element) //elements are described in cases
		{
		case 0: //Data Version
		{
			getline(ifFile, sPatch); 
			getline(ifFile, sDataVersion); 
			break;
		}
		case 1: //Melee Champions
		{
			sChampionsMelee = new string[iCounter];	//dynamicaly creates the array
			for (int i = 0; i < iCounter; i++) getline(ifFile, sChampionsMelee[i]); //filling array
			iChampsMelee = iCounter; //sets the array size to int
			break; 
		}						//all next cases does the same as case 1, but uses diffrent variables
		case 2: //Boots
		{
			sBoots = new string[iCounter];
			for (int i = 0; i < iCounter; i++) getline(ifFile, sBoots[i]);
			iBoots = iCounter;
			break;
		}
		case 3: //SR items
		{
			sItemsSR = new string[iCounter];
			for (int i = 0; i < iCounter; i++) getline(ifFile, sItemsSR[i]);
			iItemsSR = iCounter;
			break;
		}
		case 4: //TT items
		{
			sItemsTT = new string[iCounter];
			for (int i = 0; i < iCounter; i++) getline(ifFile, sItemsTT[i]);
			iItemsTT = iCounter;
			break;
		}
		case 5: //HW items
		{
			sItemsARAM = new string[iCounter];
			for (int i = 0; i < iCounter; i++) getline(ifFile, sItemsARAM[i]);
			iItemsARAM = iCounter;
			break;
		}
		case 6: //Masteries
		{
			sMasteries = new string[iCounter];
			for (int i = 0; i < iCounter; i++) getline(ifFile, sMasteries[i]);
			iMasteries = iCounter;
			break;
		}
		case 7: //Ranged champions
		{
			sChampionsRanged = new string[iCounter];
			for (int i = 0; i < iCounter; i++) getline(ifFile, sChampionsRanged[i]);
			iChampsRanged = iCounter;
			break;
		}
		case 8: //Adjectives (like Feeder Yasuo)
		{
			sAdjectives = new string[iCounter];
			for (int i = 0; i < iCounter; i++) getline(ifFile, sAdjectives[i]);
			iAdjectives = iCounter;
			break;
		}
		}
		ifFile.close();
		return 0;
	}
	else //if (ifFile.is_open())
	{
		cerr << "Cannot open file: " <<filename<< endl;
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

void UBravery::play(int map)
{
	//An infinite loop (because you can randomize not only once)
	while (true)
	{
		clear();
		showVersion();
		switch (map)	//Shows the current map
		{
		case 0: cout << "Map: Summoner's Rift" << endl << endl; break;
		case 1: cout << "Map: The Twisted Treeline" << endl << endl; break;
		case 2: cout << "Map: Howling Abyss" << endl << endl; break;
		}
		ChampionType champtype;
		//////////Champion//////////
		int xadj = rand() % iAdjectives; //Randomizes adjective to champion 
		int number = rand() % (iChampsMelee+iChampsRanged); //Randomizes champion
		//RANGED
		if (number >= iChampsMelee)
		{
			number -= iChampsMelee;
			//Some "Special adjectives"
			if (sChampionsRanged[number] == "Teemo") cout << "Satan " << sChampionsRanged[number] << endl;
			else if (sChampionsRanged[number] == "Ryze") cout << "Chopin " << sChampionsRanged[number] << endl;

			else cout <<sAdjectives[xadj]<<" "<< sChampionsRanged[number] << endl; //prints adjective and ranged champion
			sSelectedChamp = sChampionsRanged[number];
			 champtype = RANGED;
		}
		else 
		{
			cout <<sAdjectives[xadj]<<" "<< sChampionsMelee[number] << endl; //prints adjective and ranged champion
			sSelectedChamp = sChampionsMelee[number];
			champtype = MELEE;
		}		

		//////////First ability//////////
		if (sSelectedChamp == "Udyr") number = rand() % 4;	//Udyr exception - he's able to max R
		else number = rand() % 3;
		switch (number)
		{
		case 0: cout << "Max: Q" << endl; break;
		case 1: cout << "Max: W" << endl; break;
		case 2: cout << "Max: E" << endl; break;
		case 3: cout << "Max: R" << endl; break;
		}
		if (sSelectedChamp == "Kha'Zix")				//Kha'Zix can upgrade his abilities
		{
			number = rand() % 4;
			switch (number)
			{
			case 0: cout << "First upgrade: Q" << endl; break;
			case 1: cout << "First upgrade: W" << endl; break;
			case 2: cout << "First upgrade: E" << endl; break;
			case 3: cout << "First upgrade: R" << endl; break;
			}
		}
		if (sSelectedChamp == "Gangplank")				//Gangplank can upgrade his R
		{
			number = rand() % 3;
			switch (number)
			{
			case 0: cout << "First upgrade: Death's Daughter" << endl; break;
			case 1: cout << "First upgrade: Raise Morale" << endl; break;
			case 2: cout << "First upgrade: Fire at Will" << endl; break;
			}
		}
		//////////Spells//////////
		//First spell
		number = rand() % 9;
		if (map == 2) //Howling Abyss
			if (number >= 7)
			{
				number -= 7;
				cout << sSpellsARAM[number];
			}
			else cout << sSpells[number];
		else //SR and TT
		{
			if (number >= 7)
			{
				number -= 7;
				cout << sSpellsNORMAL[number];
			}
			else cout << sSpells[number];
		}
		//Second spell
		while (true)
		{
			int number2 = rand() % 9;

			if (map == 2) //Howling Abyss
				if (number2 >= 7)
				{
					number2 -= 7;
					if (number == number2) continue;		//Cannot set two the same spells
					else
					{
						cout << ", " << sSpellsARAM[number2] << endl;
						break;
					}
				}
				else if (number == number2) continue;		//Cannot set two the same spells
				else
				{
					cout << ", " << sSpells[number2] << endl;
					break;
				}
			else //SR and TT
				if (number2 >= 7)
				{
					number2 -= 7;
					if (number == number2) continue;		//Cannot set two the same spells
					else
					{
						cout << ", " << sSpellsNORMAL[number2] << endl;
						break;
					}
				}
				else if (number == number2) continue;		//Cannot set two the same spells
				else
				{
					cout << ", " << sSpells[number2] << endl;
					break;
				}
		}
		//////////Keystone//////////
		number = rand() % 9;
		cout << "Keystone: " << sMasteries[number] << endl;

		/////////Items//////////
		int NumOfItems = 5;
		cout << "Items: " << endl;
		if (sSelectedChamp == "Viktor")				//Viktor - Hex core instead of boots
		{
			cout << "1. " << "Perfect Hex Core";
			switch (rand() % 4)		//He can upgrade abilities with that item
			{
			case 0: cout << " (first upgrade: Q)" << endl; break;
			case 1: cout << " (first upgrade: W)" << endl; break;
			case 2: cout << " (first upgrade: E)" << endl; break;
			case 3: cout << " (first upgrade: R)" << endl; break;
			}
		}
		else if (sSelectedChamp == "Cassiopeia") NumOfItems = 6; //Cassiopeia - no boots, 6th item instead
		else					// boots
		{
			int number = rand() % iBoots;
			cout << "1. " << sBoots[number] << endl;;
		}
		int items[6];
		bool isSupportItem = false;
		for (int i = 0; i < NumOfItems; i++) //rest of items
		{
			if (map == 0) items[i] = rand() % (iItemsSR);
			if (map == 1) items[i] = rand() % (iItemsTT);
			if (map == 2) items[i] = rand() % (iItemsARAM);
			switch (i) //cases 5-1 checks if item is already used
			{
			case 5:			//Cassiopeia only
				if (items[i] == items[4])
				{
					i--;
					continue;
				}
			case 4:
				if (items[i] == items[3])
				{
					i--;
					continue;
				}
			case 3:
				if (items[i] == items[2])
				{
					i--;
					continue;
				}
			case 2:
				if (items[i] == items[1])
				{
					i--;
					continue;
				}
			case 1:
				if (items[i] == items[0])
				{
					i--;
					continue;
				}
			case 0:
				switch (map)
				{
				case 0:
				{
					if (champtype == MELEE && sItemsSR[items[i]] == "Runaan's Hurricane") //Runaan cannot be set to melee champs
					{
						--i;
						continue;
					}
					//Hydras cannot be set to ranged champs
					if (champtype == RANGED && (sItemsSR[items[i]] == "Ravenous Hydra" || sItemsSR[items[i]] == "Titanic Hydra"))
					{
						--i;
						continue;
					}
					//Only one support item can be set: SR
					if(    sItemsSR[items[i]] == "Eye of the Equinox" 
						|| sItemsSR[items[i]] == "Eye of the Oasis"
						|| sItemsSR[items[i]] == "Eye of the Watchers"
						|| sItemsSR[items[i]] == "Face of the Mountain"
						|| sItemsSR[items[i]] == "Frost Queen's Claim"
						|| sItemsSR[items[i]] == "Talisman of Ascension")
						if (isSupportItem)
						{
							--i;
							continue;
						}
						else isSupportItem = true;
					if (sSelectedChamp == "Cassiopeia") cout << i + 1 << ". " << sItemsSR[items[i]] << endl;
					else cout << i + 2 << ". " << sItemsSR[items[i]] << endl;
					break;
				}
				case 1:
				{
					//Only one support item can be set: TT
					if(	   sItemsTT[items[i]] == "Face of the Mountain"
						|| sItemsTT[items[i]] == "Frost Queen's Claim"
						|| sItemsTT[items[i]] == "Talisman of Ascension")
						if (isSupportItem)
						{
							--i;
							continue;
						}
						else isSupportItem = true;
					if (champtype == MELEE && sItemsTT[items[i]] == "Runaan's Hurricane")//Runaan cannot be set to melee champs
					{
						--i;
						continue;
					}
					//Hydras cannot be set to ranged champs
					if (champtype == RANGED && (sItemsTT[items[i]] == "Ravenous Hydra" || sItemsTT[items[i]] == "Titanic Hydra"))
					{
						--i;
						continue;
					}
					if (sSelectedChamp == "Cassiopeia") cout << i + 1 << ". " << sItemsTT[items[i]] << endl;
					else cout << i + 2 << ". " << sItemsTT[items[i]] << endl;
					break;
				}
				case 2:
				{
					//Only one support item can be set: HW
					if (   sItemsARAM[items[i]] == "Face of the Mountain"
						|| sItemsARAM[items[i]] == "Frost Queen's Claim"
						|| sItemsARAM[items[i]] == "Talisman of Ascension")
						if (isSupportItem)
						{
							--i;
							continue;
						}
						else isSupportItem = true; 
					if (champtype == MELEE && sItemsARAM[items[i]] == "Runaan's Hurricane")
					{
						--i;
						continue;
					}
					//Hydras cannot be set to ranged champs
					if (champtype == RANGED && (sItemsARAM[items[i]] == "Ravenous Hydra" || sItemsARAM[items[i]] == "Titanic Hydra"))
					{
						--i;
						continue;
					}
					if (sSelectedChamp == "Cassiopeia") cout << i + 1 << ". " << sItemsARAM[items[i]] << endl;
					else cout << i + 2 << ". " << sItemsARAM[items[i]] << endl;
					break;
				}
				}
			}
		}
		cout << endl;
		cout << "Press:" << endl;
		cout << "-\"E\" to back to main menu" << endl;
		cout << "-ENTER to reroll" << endl<<">";
		char x = cin.get();
		if ((x == 'E') || (x == 'e')) break;
	}
}

void UBravery::credits()
{
	clear();
	cout << "Ultimate Bravery" << endl;
	cout << "v. " << appversion << endl;
	cout << "For League patch: " << sPatch << endl;
	cout << "Based on: http://www.ultimate-bravery.com/?lang=en" << endl << endl;
	cout << "Code:\nOskar 'okg' Kaczmarek" << endl;
	cout << "Data:\nRados³aw 'Fradzio' Go³ecki\nOskar 'okg' Kaczmarek" << endl;
	cout << "Testers:\nKacper 'Wymiatacz' Dziubkowski" << endl;
	cout << "Marcin 'Atom' Dziubkowski" << endl;
	cout << "Rados³aw 'Fradzio' Go³ecki" << endl;
	cout << "Jan 'Pinjesz' Jeschke" << endl;
	cout << "Szymon 'Mnieciu' Podgórzec" << endl;
	cout << "Remigiusz 'Dorthion' W³oszczyñski" << endl;
	cout << endl << "Press any key to back. \n>";
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
	cout << " Then you must purchase the items in the order listed, always starting from the left. " << endl << " If you have a stack item to last, that's even better: you will not surrender at 20 minutes." << endl << endl;
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