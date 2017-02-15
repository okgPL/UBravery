//Ultimate Bravery: UBravery.h
//(C) 2017 Oskar Kaczmarek

#ifndef UBRAVERY_H
#define UBRAVERY_H  //Include guard

#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
using namespace std; 

/* Class UBravery
 * This class consits of all code needed to play Ultimate Bravery, rules and credits*/
class UBravery
{
	//string arrays
	string *sChampionsMelee;
	string *sChampionsRanged;
	string *sBoots;
	string *sItemsSR;
	string *sItemsTT;
	string *sItemsARAM;
	string *sMasteries;
	string *sAdjectives;
	string sPatch;
	string sSelectedChamp;
	string sSpells [7] = { "Barrier", "Cleanse", "Exhaust", "Flash", "Ghost", "Heal", "Ignite" };
	string sSpellsARAM[2] = {"Clarity", "Mark"};
	string sSpellsNORMAL[2] = {"Teleport", "Smite"};

	//arrays' sizes
	int iChampsMelee;
	int iChampsRanged;
	int iBoots;
	int iItemsSR;
	int iItemsTT;
	int iItemsARAM;
	int iMasteries;
	int iAdjectives;

	//other
	string appversion = "1.0 RC2";			//Program version (shown in showVersion())
	string sDataVersion;					//Data version got from file
	enum ChampionType { MELEE, RANGED };	//type of League champion's basic attack
	int loadData(string, int);				//loads data, used only by constructor
public:
	int error = 0;		//loading error variable
	UBravery();			//constructor
	void rules();		//prints UB rules
	void showVersion();	//shows current version
	void play(int);		//randomize all what needed
	void credits();		//prints Credits
	~UBravery();		//destructor
};
void clear(); //Clears the screen
#endif //UBRAVERY_H