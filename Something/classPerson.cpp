#include <string>
#include <time.h>
#include <iostream>
#include <thread>
#include <chrono>

#include "classPerson.h"
#include "Utility.h"

using namespace std;

// Calling default constructor
classPerson::classPerson() {
	string characterMaleNames[8] = { "Jake", "Max", "Oscar", "Sam", "Harvey", "Richard", "Tristan", "Brian" };
	string characterFemaleNames[8] = { "Lillian", "Haley", "Scarlet", "Monica", "Carla", "Cassie", "Connie", "Robbie" };

	//this_thread::sleep_for(chrono::seconds(2));
	srand(time(NULL));
	int randomGender = rand() % 2 + 1;
	if (randomGender == 1) {
		setName(characterMaleNames[rand() % 8]);
		gender = "Male";
	}
	else if (randomGender == 2) {
		setName(characterFemaleNames[rand() % 8]);
		gender = "Female";
	}

	// Definition of Character Skills
	// Value in the range 1 to 5
	srand(time(NULL));
	str		= rand() % 5 + 1;
	con		= rand() % 5 + 1;
	intel	= rand() % 5 + 1;
	chr		= rand() % 5 + 1;
	dex		= rand() % 5 + 1;

	dmgOutput		= 10 + (str * 4); // base 10; plus 4; 
	health			= 100 + (con * 10); // base 100; plus 10;
	criticalChance	= 5 + dex; // base 5; plus 1;
	speed			= 10 + (dex * 3) + (con * 2) - str; // base 10; plus 3 Dex; plus 2 Con; minus 1 Str;
	exp				= 0;

	// Inventory Slots
	has_productionTool	= false;
	has_frontWeapon		= false;
	has_backWeapon		= false;

	productionTool	= "None";
	frontWeapon		= "None";
	backWeapon		= "None";
}
// Calling parameterized constructor 
classPerson::classPerson(string nameValue, string genderValue) {
	name	= nameValue;
	gender	= genderValue;
	
	// Definition of Character Skills
	// Value in the range 1 to 5
	srand(time(NULL));
	str		= rand() % 5 + 1;
	con		= rand() % 5 + 1;
	intel	= rand() % 5 + 1;
	chr		= rand() % 5 + 1;
	dex		= rand() % 5 + 1;

	dmgOutput		= 10 + (str * 4); // base 10; plus 4; 
	health			= 100 + (con * 10); // base 100; plus 10;
	criticalChance	= 5 + dex; // base 5; plus 1;
	speed			= 10 + (dex * 3) + (con * 2) - str; // base 10; plus 3 Dex; plus 2 Con; minus 1 Str;
	exp				= 0;

	// Inventory Slots
	has_productionTool	= false;
	has_frontWeapon		= false;
	has_backWeapon		= false;

	productionTool	= "None";
	frontWeapon		= "None";
	backWeapon		= "None";
}

//Calling set methods for the name and reversing gender
void classPerson::setName(string value) { name = value; }
void classPerson::setNewName(vector <classPerson>* valueVector) {
	string newCharacterName;
	int renameCharacterDecision;
	bool isCharacterName{};
	cout << "\nType in a new name for your character:\n";
	cin >> newCharacterName;

	for (int x = 0; x < valueVector->size(); x++) {
		if (newCharacterName == valueVector->at(x).getName()) {
			cout << "\nYou've chosen the name " << darkGreenText(newCharacterName)<< ", which is already the current name of " << "(" << x + 1 << ") " << darkGreenText(valueVector->at(x).getName());
			cout << "\nGoing to the Main Screen\n\n";
			pauseScreen();
			isCharacterName = true;
			break;
		}
		else { isCharacterName = false; }
	}
	if (!isCharacterName) {
		string confirmationText = redText("Rename") + " " + darkGreenText(name) + " to " + darkGreenText(newCharacterName) + " ?";
		if (userConfirmation(confirmationText) == 1) {
			name = newCharacterName;
			cout << "\nYour character was successfully renamed to " << darkGreenText(name) << "\n";
		}
		else {
			cout << "\nGoing to the Main Screen\n";
		}
	}
}
void classPerson::setGender_MaleToFemale() {
	if (gender == "Male") {
		gender = "Female";
		string characterFemaleNames[8] = { "Lillian", "Haley", "Scarlet", "Monica", "Carla", "Cassie", "Connie", "Robbie" };
		setName(characterFemaleNames[rand() % 8]); 
	}
	else {
		string characterMaleNames[8] = { "Jake", "Max", "Oscar", "Sam", "Harvey", "Richard", "Tristan", "Brian" };
		setName(characterMaleNames[rand() % 8]);
		gender = "Male";
	}
}

// Calling set methods for skills
void classPerson::setSpd(int value) { speed		= value; calcStats(); }
void classPerson::setStr(int value) { str		= value; calcStats(); }
void classPerson::setCon(int value) { con		= value; calcStats(); }
void classPerson::setIntel(int value) { intel	= value; calcStats(); }
void classPerson::setChr(int value) { chr		= value; calcStats(); }
void classPerson::setDex(int value) { dex		= value; calcStats(); }

//Calling set method for person stats
void classPerson::setProfession(string value) { profession = value; }
void classPerson::setCurrentJob(string value) { currentJob = value; }

//Calling set methods for Weapon/Inventory slots
void classPerson::setHas_productionTool(bool value) { has_productionTool	= value; }
void classPerson::setHas_frontWeapon(bool value) { has_frontWeapon			= value; }
void classPerson::setHas_backWeapon(bool value) { has_backWeapon			= value; }

void classPerson::setProductionEquipment(classInventory* valueInventory) {
	cout << "Tool: " << getHas_productionTool();

	int productionEquipmentAmount = valueInventory->getStoneHoeAmount();
	if (productionEquipmentAmount > 0) {
		valueInventory->subStoneHoeAmount(1);
		setHas_productionTool(true);
		productionTool = "Stone Hoe";
		cout << "Successfully assigned: " << brightBlueText(productionTool);
		cout << "\n";
		pauseScreen();
	}
	else {
		cout << "\nThere were no Stone Hoes available, your Character has not been assigned a Production Tool\n";
		pauseScreen();
	}
}
void classPerson::setFrontWeapon(classInventory* valueInventory) {
	int weaponAmount = valueInventory->getWoodenClubAmount();
	if (weaponAmount > 0) {
		valueInventory->subWoodenClubAmount(1);
		setHas_frontWeapon(true);
		frontWeapon = "Wooden Club";
		cout << "Successfully assigned: " << brightBlueText(frontWeapon);
		cout << "\n";
		pauseScreen();
	}
	else {
		cout << "\nThere were no Wooden Clubs available, your Character has not been assigned a Frontline Weapon\n";
		pauseScreen();
	}
}
void classPerson::setBackWeapon(classInventory* valueInventory) {
	int weaponAmount = valueInventory->getStoneSpearAmount();
	if (weaponAmount > 0) {
		valueInventory->subStoneSpearAmount(1);
		setHas_backWeapon(true);
		backWeapon = "Stone Spear";
		cout << "Successfully assigned: " << brightBlueText(backWeapon);
		cout << "\n";
		pauseScreen();
	}
	else {
		cout << "\nThere were no Stone Spears available, your Character has not been assigned a Backline Weapon\n";
		pauseScreen();
	}
}

//Calling get methods for skills
int classPerson::getStr() { return str; }
int classPerson::getCon() { return con; }
int classPerson::getInt() { return intel; }
int classPerson::getChr() { return chr; }
int classPerson::getDex() { return dex; }
int classPerson::getSpd() { return speed; }

//Calling get methods for person stats
string classPerson::getGender() { return gender; }
string classPerson::getName() { return name; }
string classPerson::getProfession() { return profession; }
string classPerson::getCurrentJob() { return currentJob; }

// Calling get methods for Weapon/Inventory slots
bool classPerson::getHas_productionTool() { return has_productionTool; }
bool classPerson::getHas_frontWeapon() { return has_frontWeapon; }
bool classPerson::getHas_backWeapon() { return has_backWeapon; }

string classPerson::getProductionTool() { return productionTool; }
string classPerson::getFrontWeapon() { return frontWeapon; }
string classPerson::getBackWeapon() { return backWeapon; }

// Used for re-calculating the stats when skills change
void classPerson::calcStats() {
	dmgOutput		= 10 + (getStr() * 4); // base 10; plus 4; 
	health			= 100 + (getCon() * 10); // base 100; plus 10;
	criticalChance	= 5 + getDex(); // base 5; plus 1;
	speed			= 10 + (getDex() * 3) + (getCon() * 2) - getStr(); // base 10; plus 3 Dex; plus 2 Con; minus 1 Str;
}

// Get overview of skills & stats of Person/Character
void classPerson::getOverview() {
	clearScreen();
	cout << "Information Overview of " << darkGreenText(getName());

	// Stats
	cout << "\n\nName: "		<< yellowText(name);
	cout << "\nGender: "		<< yellowText(gender);
	cout << "\nProfession: "	<< yellowText(profession);
	cout << "\nCurrent Job: "	<< yellowText(currentJob);

	cout << "\n\nStats";

	cout << darkGreenText("\n\nDamageoutput: ")		<< yellowText(dmgOutput);
	cout << darkGreenText("\nHealth: ")				<< yellowText(health);
	cout << darkGreenText("\nCritical Chance: ")	<< yellowText(criticalChance);
	cout << darkGreenText("\nSpeed: ")				<< yellowText(speed);
	cout << darkGreenText("\nExpierence: ")			<< yellowText(exp);

	// Skills
	cout << "\n\nSkills";

	cout << darkGreenText("\n\nStrength: ")		<< yellowText(str);
	cout << darkGreenText("\nCondition: ")		<< yellowText(con);
	cout << darkGreenText("\nIntelligence: ")	<< yellowText(intel);
	cout << darkGreenText("\nCharisma: ")		<< yellowText(chr);
	cout << darkGreenText("\nDexerity: ")		<< yellowText(dex);
	
	// Equipment
	cout << "\n\nEquipment";

	cout << darkGreenText("\n\nProduction Tool: ")	<< yellowText(productionTool);
	cout << darkGreenText("\nFrontline Weapon: ")	<< yellowText(frontWeapon);
	cout << darkGreenText("\nBackline Weapon: ")	<< yellowText(backWeapon);

	cout << "\n\n";
}