//Ultimate Bravery: UBravery.h
//(C) 2017 Oskar Kaczmarek

#ifndef UBRAVERY_H
#define UBRAVERY_H  //Include guard

#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
using namespace std; 

///<summary>
///Main Ultimate Bravery class.
///Contains all methods and variables to properly run program
///</summary>
class UBravery
{
	///<summary>List of melee champions</summary>
	string *sChampionsMelee;
	///<summary>List of ranged champions</summary>
	string *sChampionsRanged;
	///<summary>List of boots</summary>
	string *sBoots;
	///<summary>List of items that's possible to buy on Summoner's Rift</summary>
	string *sItemsSR;
	///<summary>List of items that's possible to buy on The Twisted Treeline</summary>
	string *sItemsTT;
	///<summary>List of items that's possible to buy on Howling Abyss (excluding Snowdown Showdown)</summary>
	string *sItemsARAM;
	///<summary>List of masteries</summary>
	string *sMasteries;
	///<summary>List of adjectives (like Feeder Yasuo)</summary>
	string *sAdjectives;
	///<summary>Actual League patch</summary>
	string sPatch;

	///<summary>List of spells: All maps</summary>
	string sSpells [7] = { "Barrier", "Cleanse", "Exhaust", "Flash", "Ghost", "Heal", "Ignite" };
	///<summary>List of spells: Howling Abyss</summary>
	string sSpellsARAM[2] = {"Clarity", "Mark"};
	///<summary>List of spells: Summoner's Rift and The Twisted Treeline</summary>
	string sSpellsNORMAL[2] = {"Teleport", "Smite"};

	///<summary>Melee champions qty</summary>
	int iChampsMelee;
	///<summary>Ranged champions qty</summary>
	int iChampsRanged;
	///<summary>Boots qty</summary>
	int iBoots;
	///<summary>SR items qty</summary>
	int iItemsSR;
	///<summary>TT items qty</summary>
	int iItemsTT;
	///<summary>HW items qty</summary>
	int iItemsARAM;
	///<summary>Masteries qty</summary>
	int iMasteries;
	///<summary>Adjectives qty</summary>
	int iAdjectives;

	///<summary>Program version (shown in showVersion())</summary>
	string appversion = "1.1.1";
	///<summary>Data version (got from file)</summary>
	string sDataVersion;
	///<summary>
	///Type of League champion's basic attack:
	///</summary>
	enum ChampionType
	{
		///<summary>Melee AA</summary>
		MELEE,
		///<summary>Ranged AA</summary>
		RANGED
	};
	///<summary>
	///Loads data from file
	///<param name="filename">Path to file to load.</param>
	///<param name="element">Indicates the specified element to load.</param>
	///</summary>
	int loadData(string filename, int element);				//loads data, used only by constructor
public:
	///<summary>Error status, 0 = OK</summary>
	int error = 0;
	UBravery();
	///<summary>Shows rules</summary>
	void rules();
	///<summary>Shows current version</summary>
	void showVersion();

	///<summary>
	///Runs a UBravery Randomizer
	///<param name="map"> Describes a map </param>
	///</summary>
	void play(int map);	
	///<summary>Extras menu</summary>
	void extras();
	///<summary>Credits</summary>
	void credits();		
	///<summary>Blacklist Control System</summary>
	void blacklist();
	~UBravery();		//destructor
};
///<summary>Clears the console</summary>
void clear();


#endif //UBRAVERY_H