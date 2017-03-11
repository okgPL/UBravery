#include "UBravery.h"

void UBravery::play(int map)
{
	//An infinite loop (because you can randomize not only once)
	while (true)
	{
		string sSelectedChamp;
		clear();
		showVersion();
		switch (map)	//Shows the current map
		{
		case 0: cout << "Map: Summoner's Rift" << endl << endl; break;
		case 1: cout << "Map: The Twisted Treeline" << endl << endl; break;
		case 2: cout << "Map: Howling Abyss" << endl << endl; break;
		}
		clog << "Map: " << map << endl;
		ChampionType champtype;
		//////////Champion//////////
		int xadj = rand() % iAdjectives; //Randomizes an adjective to champion 
		ifstream ignore("Data\\Champions\\blacklist");
		string linia;
		int number;
		while (true)
		{
			number = rand() % (iChampsMelee + iChampsRanged); //Randomizes champion
			if (number >= iChampsMelee)
			{
				number -= iChampsMelee;
				while (getline(ignore, linia))
				{
					if (linia == sChampionsRanged[number])
						error = 2;
				}
				if (error == 2)
				{
					error = 0;
					clog << "Randomized champion: " << sChampionsRanged[number] << " is on blacklist. Rerolling..." << endl;
					continue;
				}
				ignore.close();
				//Some "Special adjectives"
				if (sChampionsRanged[number] == "Teemo") cout << "Satan " << sChampionsRanged[number] << endl;
				else if (sChampionsRanged[number] == "Ryze") cout << "Chopin " << sChampionsRanged[number] << endl;

				else cout << sAdjectives[xadj] << " " << sChampionsRanged[number] << endl; //prints adjective and ranged champion
				sSelectedChamp = sChampionsRanged[number];
				champtype = RANGED;
			}
			else
			{
				while (getline(ignore, linia))
				{
					if (linia == sChampionsMelee[number])
						error = 2;
				}
				if (error == 2)
				{
					error = 0;
					clog << "Randomized champion: " << sChampionsMelee[number] << " is on blacklist. Rerolling..." << endl;
					continue;
				}
				ignore.close();
				cout << sAdjectives[xadj] << " " << sChampionsMelee[number] << endl; //prints adjective and ranged champion
				sSelectedChamp = sChampionsMelee[number];
				champtype = MELEE;
			}
			clog << "Champion: " << sSelectedChamp << endl;;
			break;
		}

		//////////First ability//////////
		if (sSelectedChamp == "Udyr") number = rand() % 4;	//Udyr exception - he's able to max R
		else number = rand() % 3;
		switch (number)
		{
		case 0:
		{
			cout << "Max: Q" << endl;
			clog << "Max: Q" << endl;	break;
		}
		case 1:
		{
			cout << "Max: W" << endl;
			clog << "Max: W" << endl;	break;
		}
		case 2:
		{
			cout << "Max: E" << endl;
			clog << "Max: E" << endl;	break;
		}
		case 4:
		{
			cout << "Max: R" << endl;
			clog << "Max: R" << endl;	break;
		}
		}
		if (sSelectedChamp == "Kha'Zix")				//Kha'Zix can upgrade his abilities
		{
			number = rand() % 4;
			switch (number)
			{
			case 0:
			{
				cout << "First upgrade: Q" << endl;
				clog << "First upgrade: Q" << endl;	break;
			}
			case 1:
			{
				cout << "First upgrade: W" << endl;
				clog << "First upgrade: W" << endl;	break;
			}
			case 2:
			{
				cout << "First upgrade: E" << endl;
				clog << "First upgrade: R" << endl;	break;
			}
			case 3:
			{
				cout << "First upgrade: R" << endl;
				clog << "First upgrade: R" << endl;	break;
			}
			}
		}
		if (sSelectedChamp == "Gangplank")				//Gangplank can upgrade his R
		{
			number = rand() % 3;
			switch (number)
			{
			case 0:
			{
				cout << "First upgrade: Death's Daughter" << endl;
				clog << "First upgrade: Death's Daughter" << endl;
				break;
			}
			case 1:
			{
				cout << "First upgrade: Raise Morale" << endl;
				clog << "First upgrade: Raise Morale" << endl;  break;
			}
			case 2:
			{
				cout << "First upgrade: Fire at Will" << endl;
				clog << "First upgrade: Fire at Will" << endl; break;
			}
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
				clog << "Spell 1: " << sSpellsARAM[number] << endl;
			}
			else
			{
				cout << sSpells[number];
				clog << "Spell 1: " << sSpells[number] << endl;
			}
		else //SR and TT
		{
			if (number >= 7)
			{
				number -= 7;
				cout << sSpellsNORMAL[number];
				clog << "Spell 1:" << sSpellsNORMAL[number] << endl;
			}
			else
			{
				cout << sSpells[number];
				clog << "Spell 1: " << sSpells[number] << endl;
			}
		}
		//Second spell
		while (true)
		{
			int number2 = rand() % 9;
			if (number2 >= 7)
			{
				number2 -= 7;
				if (number == number2) continue;		//Cannot set two the same spells
				else
				{
					if (map == 2)
					{
						cout << ", " << sSpellsARAM[number2] << endl;
						clog << "Spell 2: " << sSpellsARAM[number2] << endl;
					}
					else
					{
						cout << ", " << sSpellsNORMAL[number2] << endl;
						clog << "Spell 2:" << sSpellsNORMAL[number2] << endl;
					}
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
		clog << "Keystone: " << sMasteries[number] << endl;

		/////////Items//////////
		int NumOfItems = 5;
		cout << "Items: " << endl;
		if (sSelectedChamp == "Viktor")				//Viktor - Hex core instead of boots
		{
			cout << "1. " << "Perfect Hex Core";
			clog << "Item 1: Perfect Hex Core" << endl;
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
			cout << "1. " << sBoots[number] << endl;
			clog << "Item 1: " << sBoots[number] << endl;
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
			case 4:
			case 3:
			case 2:
			case 1:
				if (items[i] == items[i - 1])
				{
					i--;
					continue;
				}
			case 0:
				switch (map)
				{
				case 0:
				{
					if ((champtype == MELEE && sItemsSR[items[i]] == "Runaan's Hurricane")
						|| (champtype == RANGED && (sItemsSR[items[i]] == "Ravenous Hydra" || sItemsSR[items[i]] == "Titanic Hydra")))
					{
						--i;
						continue;
					}
					//Only one support item can be set: SR
					if (sItemsSR[items[i]] == "Eye of the Equinox"
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
						if (sSelectedChamp == "Cassiopeia")
						{
							cout << i + 1 << ". " << sItemsSR[items[i]] << endl;
							clog << "Item " << i + 1 << ": " << sItemsSR[items[i]] << endl;
						}
						else
						{
							cout << i + 2 << ". " << sItemsSR[items[i]] << endl;
							clog << "Item " << i + 2 << ": " << sItemsSR[items[i]] << endl;
						}
						break;
				}
				case 1:
				{
					//Only one support item can be set: TT
					if (sItemsTT[items[i]] == "Face of the Mountain"
						|| sItemsTT[items[i]] == "Frost Queen's Claim"
						|| sItemsTT[items[i]] == "Talisman of Ascension")
						if (isSupportItem)
						{
							--i;
							continue;
						}
						else isSupportItem = true;

						if ((champtype == MELEE && sItemsTT[items[i]] == "Runaan's Hurricane")
							|| (champtype == RANGED && (sItemsTT[items[i]] == "Ravenous Hydra" || sItemsTT[items[i]] == "Titanic Hydra")))
						{
							--i;
							continue;
						}
						if (sSelectedChamp == "Cassiopeia")
						{
							cout << i + 1 << ". " << sItemsTT[items[i]] << endl;
							clog << "Item " << i + 1 << ": " << sItemsTT[items[i]] << endl;
						}
						else
						{
							cout << i + 2 << ". " << sItemsTT[items[i]] << endl;
							clog << "Item " << i + 2 << ": " << sItemsTT[items[i]] << endl;
						}
						break;
				}
				case 2:
				{
					//Only one support item can be set: HW
					if (sItemsARAM[items[i]] == "Face of the Mountain"
						|| sItemsARAM[items[i]] == "Frost Queen's Claim"
						|| sItemsARAM[items[i]] == "Talisman of Ascension")
						if (isSupportItem)
						{
							--i;
							continue;
						}
						else isSupportItem = true;

						if ((champtype == MELEE && sItemsARAM[items[i]] == "Runaan's Hurricane")
							|| (champtype == RANGED && (sItemsARAM[items[i]] == "Ravenous Hydra" || sItemsARAM[items[i]] == "Titanic Hydra")))
						{
							--i;
							continue;
						}
						if (sSelectedChamp == "Cassiopeia")
						{
							cout << i + 1 << ". " << sItemsARAM[items[i]] << endl;
							clog << "Item " << i + 1 << ": " << sItemsARAM[items[i]] << endl;
						}
						else
						{
							cout << i + 2 << ". " << sItemsARAM[items[i]] << endl;
							clog << "Item " << i + 2 << ": " << sItemsARAM[items[i]] << endl;
						}
						break;
				}
				}
			}
		}
		cout << endl;
		cout << "Press:" << endl;
		cout << "-\"E\" to back to main menu" << endl;
		cout << "-ENTER to reroll" << endl << ">";
		char x = cin.get();
		if ((x == 'E') || (x == 'e'))
		{
			clog << "Back to main menu" << endl;
			break;
		}
	}
}