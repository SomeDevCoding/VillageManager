#pragma once
#include <string>
#include <time.h>
#include <iostream>

#include "classInventory.h"

using namespace std;


class classPerson {
private:
	// Initialization of skills
	int str; // Strength - Contributes to Damageoutput
	int con; // Condition - Contributes to Health 
	int intel; // Intelligence - Contributes to Research, Expierence-gain
	int chr; // Charisma - Contributes to Leadership Buffs
	int dex; // Dexerity - Contributes to Critical Damageoutput
	string name; // Name of the Person
	string gender; // Gender of the Person
	string profession; // Profession gives a bonus to specific work tasks
	string currentJob; // Will give the information about the current Job assignment

	// Initialization of stats
	int dmgOutput; // Base Damageoutput
	int health; // Base Health
	int criticalChance; //Base Critical Chance
	int exp; // Base Experience 
	int speed; // Base Speed

	// Inventory slots
	bool has_productionTool;
	string productionTool;

	bool has_frontWeapon; // Frontline
	string frontWeapon;

	bool has_backWeapon; // Backline
	string backWeapon;


public:
	// Constructor declaration
	classPerson();
	classPerson(string nameValue, string genderValue);

	void setName(string value);
	void setNewName(vector <classPerson>* valueVector);
	void setGender_MaleToFemale();

	// set methods for skills
	void setSpd(int value);
	void setStr(int value);
	void setCon(int value);
	void setIntel(int value);
	void setChr(int value);
	void setDex(int value);

	// set method for person stats
	void setProfession(string value);
	void setCurrentJob(string value);

	// set methods for Weapon/Inventory slots
	void setHas_productionTool(bool value);
	void setHas_frontWeapon(bool value);
	void setHas_backWeapon(bool value);

	void setProductionEquipment(classInventory* valueInventory);
	void setFrontWeapon(classInventory* valueInventory);
	void setBackWeapon(classInventory* valueInventory);

	// get methods for skills
	int getStr();
	int getCon();
	int getInt();
	int getChr();
	int getDex();
	int getSpd();

	//get methods for person stats
	string getGender();
	string getName();
	string getProfession();
	string getCurrentJob();

	// get methods for Weapon/Inventory slots
	bool getHas_productionTool();
	bool getHas_frontWeapon();
	bool getHas_backWeapon();

	string getProductionTool();
	string getFrontWeapon();
	string getBackWeapon();

	void calcStats();
	void getOverview();
};