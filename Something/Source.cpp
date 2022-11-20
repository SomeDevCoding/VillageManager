#include <iostream>
#include <time.h>
#include <windows.h>
#include <vector>
#include <string> 
#include <thread> // sleep_for
#include <chrono> // seconds
#include <algorithm>
#include <stdlib.h>
#include <iterator>
#include <typeinfo> 
#include <future>
#include <conio.h>

#include "classPerson.h"
#include "classVillage.h"
#include "classInventory.h"
#include "classBuilding.h"
#include "dataProcessingCharacters.h"
#include "Utility.h"

using namespace std;

// Main Menu
void backgroundThread(vector <classPerson>* vectorPerson, vector <classVillage>* vectorVillage, classInventory* valueInventory);
void doOption(vector <classPerson>* vectorPerson, vector <classVillage>* vectorVillage, classInventory* valueInventory);

// Character Section
void char_MainMenu(vector <classPerson>* vectorPerson, vector <classVillage>* vectorVillage, classInventory* valueInventory);
void char_InvSection(vector <classPerson>* vectorPerson, vector <classVillage>* vectorVillage, int vectorPersonPosition, classInventory* valueInventory);
void char_AssignWorkplace(vector <classPerson>* vectorPerson, vector <classVillage>* vectorVillage, int vectorPersonPosition, classInventory* valueInventory);
void char_EditSection(vector <classPerson>* vectorPerson, vector <classVillage>* vectorVillage, int vectorPersonPosition, classInventory* valueInventory);
void char_OverviewSection(vector <classPerson>* vectorPerson, vector <classVillage>* vectorVillage, int vectorPersonPosition, classInventory* valueInventory);

// Inventory Section
void village_MainMenu(vector <classPerson>* vectorPerson, vector <classVillage>* vectorVillage, classInventory* valueInventory);
void village_InfoMenu(int vectorVillagePosition, vector <classPerson>* vectorPerson, vector <classVillage>* vectorVillage, classInventory* valueInventory);
void village_EditMenu(int vectorVillagePosition, vector <classPerson>* vectorPerson, vector <classVillage>* vectorVillage, classInventory* valueInventory);
void village_BuildMenu(int vectorVillagePosition, vector <classPerson>* vectorPerson, vector <classVillage>* vectorVillage, classInventory* valueInventory);

// Resource Section
void resource_MainMenu(vector <classPerson>* vectorPerson, vector <classVillage>* vectorVillage, classInventory* valueInventory);

// Inventory Section
void inventory_MainMenu(vector <classPerson>* vectorPerson, vector <classVillage>* vectorVillage, classInventory* valueInventory);

// choose Something (Character or Village right now)
int chooseVillage(vector <classVillage>* vectorVillage);
void print_AllVillages(vector <classVillage>* vectorVillage);
int chooseChar(vector <classPerson>* vectorPerson);

// Utility Section Global
int retryOrReturn();
void print_ListVillages(string coloredText, string category);
void print_ListChar(string coloredText, string category);
void print_ListInventory(string coloredText, string category);

string contentListVillage(int position);
string contentListVillageInfo(int position);
string contentListVillageBuild(int position);
string contentListVillageEdit(int position);

string contentListChar(int position);
string contentListCharWorkplace(int position);
string contentListCharInventory(int position);
string contentListCharEdit(int position);
string contentListCharOverview(int position);

string contentListInventory(int position);
string print_CurrentSection(string whichCategory);

// Utility Section Village
int printVillageTextAndPosition(vector <classVillage>* vectorVillage, string textToDisplay);

// Utility Section Character
string get_characterHandle(vector <classPerson>* vectorPerson, int vectorPersonPosition);
void printCharacterList(vector <classPerson>* vectorPerson);

// General Utility
bool areProdBuildingsPresent(vector <classVillage>* vectorVillage_Value, int villagePositon_inVector_value);
string displayProdBuildingName_village(vector <classVillage>* vectorVillage_Value, int villagePositon_inVector_value, int workplacePosition_inVector_Value);
string displayResourceBuildingName_village(vector <classVillage>* vectorVillage_Value, int villagePositon_inVector_value, int workplacePosition_inVector_Value);

// Workplace Utility
int checkUserinput(int userinput_value, vector <classVillage>* vectorVillage_value, int villagePosition_inVector_value);
int chooseBuildingPlotPosition_village(int villagePosition_inVector_value, vector <classVillage>* vectorVillage_value);
int chooseResourcePlotPosition_village(int villagePosition_inVector_value, vector <classVillage>* vectorVillage_value);
void printSuccessProdWorkplaceAssignment(string character_value, string workplace_value);
void printSuccessResourceWorkplaceAssignment(string character_value, string workplace_value);


void setProdBuildingWorker_village(vector <classVillage>* vectorVillage_value, vector <classPerson>* vectorPerson_value, int villagePosition_inVector_value, int workplacePosition_inVector_value, int personPosition_inVector_Value);
void setResourceBuildingWorker_village(vector <classVillage>* vectorVillage_value, vector <classPerson>* vectorPerson_value, int villagePosition_inVector_value, int workplacePosition_inVector_value, int personPosition_inVector_Value);

// Creation Section
void createChars(vector <classPerson>* vectorPersons);
void createVillage(vector <classVillage>* vectorVillage);
void createBuildings(vector <classVillage>* vectorVillage);

/*
		USED COLORS     FG  BG
		Red             31  41	- Errors
		Green           32  42	- Stats
		Yellow          33  43	- Notification
		Bright Magenta  95  105	- Persons
		Magenta			35	45	- Female Gender Colour
		Cyan			36	46	- Male Gender Colour
		Bright Blue     94  104	- Equipment

		UNUSED COLOURS
		Black           30  40
		Blue            34  44
		White           37  47
		Bright Black    90  100
		Bright Red      91  101
		Bright Green    92  102
		Bright Yellow   93  103
		Bright Magenta  95  105
		Bright Cyan     96  106
		Bright White    97  107
	*/
int main() {
	vector <classPerson> vectorChars; // this will hold the information of all objects of classPerson
	vector <classVillage> vectorVillages; // this will hold the information of all objects of classVillage
	classInventory inventoryObj;
	int userInput;
	cout << "Welcome to my game\n(1) Start game\n";
	cin >> userInput;

mainBeginning:

	clearScreen();
	if (userInput == 1) {
		cout << "Starting up your game...";
		cout << "\n\nWe will create your first two Villagers:\n";
	
		createChars(&vectorChars);
		cout << "\nYour first set of Villagers were created, we will now establish a Village.\n";
		createVillage(&vectorVillages);
		createBuildings(&vectorVillages);
		cout << "\n\nYour village will have:\n4 building lots\nA forest\nA Stone Mine\nAn empty farm\n\n";

	} 
	else {
		cout << "Ha! There is no other possibility.. Starting game now\n\n";
		pauseScreen();
		userInput = 1;
		goto mainBeginning;
	}

	pauseScreen();
	
	//For testing: outcomment this section and comment the function-call of doOption();

	thread thread1(backgroundThread, &vectorChars, &vectorVillages, &inventoryObj);			
	thread thread2(doOption, &vectorChars, &vectorVillages, &inventoryObj);

	thread1.join();
	thread2.join();
	

	//doOption(&vectorChars, &vectorVillages, &inventoryObj);

	return 0;
}


//Multithreading testing purpose: "AMEN" will be printed on the screen every 5 seconds if the name of a Person object is "Handgranate"


void backgroundThread(vector <classPerson>* vectorPerson, vector <classVillage>* vectorVillage, classInventory* valueInventory) {
	while (true) {
		this_thread::sleep_for(chrono::seconds(5));
		for (int x = 0; x < vectorPerson->size(); x++) {
			if (vectorPerson->at(x).getName() == "Handgranate") {
				cout << "AMEN!!\n";
				int u; cin >> u;
			}
		}
	}
}



// the main menu
void doOption(vector <classPerson>* vectorPerson, vector <classVillage>* vectorVillage, classInventory* valueInventory) {
	int userInput_Option = 0;

	while (userInput_Option != 4) {
		clearScreen();
		cout << "These are your available options\n\n(1) Go to Village Section\n(2) Go to Character Section\n(3) Go to Inventory Section\n(4) Quit";
		cout << "\n\nInput: ";
		cin >> userInput_Option;
		if (is_Equals1(userInput_Option) == true) { village_MainMenu(vectorPerson, vectorVillage, valueInventory); }
		if (is_Equals2(userInput_Option) == true) { char_MainMenu(vectorPerson, vectorVillage, valueInventory); }
		if (is_Equals3(userInput_Option) == true) { inventory_MainMenu(vectorPerson, vectorVillage, valueInventory); }
	}
	pauseScreen();
}

/*
	VILLAGE SECTION
*/
void village_MainMenu(vector <classPerson>* vectorPerson, vector <classVillage>* vectorVillage, classInventory* valueInventory) {
	int villageSectionDecision = 0;
	int vectorVillagePosition;
	string villageName;

	clearScreen();
	while (villageSectionDecision < 1 || villageSectionDecision > 3) {
		vectorVillagePosition = chooseVillage(vectorVillage);
		villageName = vectorVillage->at(vectorVillagePosition).getVillageName();

		// string coloredText, string category
		print_ListVillages(villageName, "village");
		cin >> villageSectionDecision;

		if (villageSectionDecision == 1) {
			village_BuildMenu(vectorVillagePosition, vectorPerson, vectorVillage, valueInventory);
		}
		if (villageSectionDecision == 2) { 
			village_EditMenu(vectorVillagePosition, vectorPerson, vectorVillage, valueInventory);
		}
		if (villageSectionDecision == 3) { 
			village_InfoMenu(vectorVillagePosition, vectorPerson, vectorVillage, valueInventory);
		}
		// invalid user input
		if (villageSectionDecision < 1 || villageSectionDecision > 3) {
			if (retryOrReturn() == 99) { break; }
		}
	}
}
void village_BuildMenu(int vectorVillagePosition, vector <classPerson>* vectorPerson, vector <classVillage>* vectorVillage, classInventory* valueInventory) {
	string villageName = vectorVillage->at(vectorVillagePosition).getVillageName();
	int villageBuildDecision = 0;
	clearScreen();

	while (villageBuildDecision < 1 || villageBuildDecision > 2) {
		print_ListVillages(villageName, "villageBuild");
		cin >> villageBuildDecision;

		if (villageBuildDecision == 1) {
			vectorVillage->at(vectorVillagePosition).constructBuilding();
			pauseScreen();
		}
		if (villageBuildDecision == 2) {
			vectorVillage->at(vectorVillagePosition).demolishBuilding();
			pauseScreen();
		}

		// invalid user input
		if (villageBuildDecision < 1 || villageBuildDecision > 2) {
			if (retryOrReturn() == 99) { break; }
		}
	}
}

// vectorVillagePosition represents the position in vectorVillage
// will let you edit Information about the selected village (eg. name)
void village_EditMenu(int vectorVillagePosition, vector <classPerson>* vectorPerson, vector <classVillage>* vectorVillage, classInventory* valueInventory) {
	string villageName = vectorVillage->at(vectorVillagePosition).getVillageName();
	int villageEditDecision = 0;
	clearScreen();

	while (villageEditDecision != 1) {
		print_ListVillages(villageName, "villageEdit");
		cin >> villageEditDecision;

		if (villageEditDecision == 1) {
			vectorVillage->at(vectorVillagePosition).setVillageName(vectorVillage);
			pauseScreen();
		}

		// invalid user input
		if (villageEditDecision != 1) {
			if (retryOrReturn() == 99) { break; }
		}
	}
}
void village_InfoMenu(int vectorVillagePosition, vector <classPerson>* vectorPerson, vector <classVillage>* vectorVillage, classInventory* valueInventory) {
	string villageName = vectorVillage->at(vectorVillagePosition).getVillageName();
	int villageInfoDecision = 0;
	clearScreen();

	while (villageInfoDecision < 1 || villageInfoDecision > 3) {
		print_ListVillages(villageName, "villageInfo");
		cin >> villageInfoDecision;

		if (villageInfoDecision == 1) {
			vectorVillage->at(vectorVillagePosition).print_VillageAllBuildingsInformation();
			pauseScreen();
		}
		if (villageInfoDecision == 2) {
			vectorVillage->at(vectorVillagePosition).print_ResourceBuildingsInformation();
			pauseScreen();
		}
		if (villageInfoDecision == 3) {
			vectorVillage->at(vectorVillagePosition).print_buildingPlotsInformation();
			cout << "\n";
			pauseScreen();
		}

		// invalid user input
		if (villageInfoDecision < 1 || villageInfoDecision > 3) {
			if (retryOrReturn() == 99) { break; }
		}
	}
}

/*
	CHARACTER SECTION
*/
void char_MainMenu(vector <classPerson>* vectorPerson, vector <classVillage>* vectorVillage, classInventory* valueInventory) {
	int userInput_charSection = 0;
	int vectorPersonPosition;
	string characterHandle;

	vectorPersonPosition = chooseChar(vectorPerson);
	characterHandle = get_characterHandle(vectorPerson, vectorPersonPosition);
	clearScreen();
	
	while (userInput_charSection < 1 || userInput_charSection > 5) {
		print_ListChar(characterHandle, "charSection");
		cin >> userInput_charSection;

		if (is_Equals1(userInput_charSection) == true) {
			cout << "Scouting is currently not implemented\n";
			pauseScreen();
		}
		if (is_Equals2(userInput_charSection) == true) {
			char_AssignWorkplace(vectorPerson, vectorVillage, vectorPersonPosition, valueInventory);
		}
		if (is_Equals3(userInput_charSection) == true) {
			char_InvSection(vectorPerson, vectorVillage, vectorPersonPosition, valueInventory);
		}
		if (is_Equals4(userInput_charSection) == true) {
			char_EditSection(vectorPerson, vectorVillage, vectorPersonPosition, valueInventory);
		}
		if (is_Equals5(userInput_charSection) == true) {
			char_OverviewSection(vectorPerson, vectorVillage, vectorPersonPosition, valueInventory);
		}

		// invalid user input
		if (userInput_charSection < 1 || userInput_charSection > 5) {
			if (retryOrReturn() == 99) { break; }
		}
	}
}

void char_AssignWorkplace(vector <classPerson>* vectorPerson, vector <classVillage>* vectorVillage, int personPosition_inVector_value, classInventory* valueInventory) {
	string characterHandle = get_characterHandle(vectorPerson, personPosition_inVector_value);

	int userInput_workplaceType;
	int villagePosition_inVector;
	int workplacePosition_inVector;

	int charAssignWorkplaceDecision = 0;
	string workplace;
	
	clearScreen();
	string text = "You've choosen the " + brightBlueText("Assign Workplace Section") + " for " + characterHandle + "\n";
	printText(text);

	villagePosition_inVector = printVillageTextAndPosition(vectorVillage, "Workplace");

	pauseScreen();

	do {
		print_ListChar(characterHandle, "charWorkplace");
		charAssignWorkplaceDecision = get_userInput();

		userInput_workplaceType = checkUserinput(charAssignWorkplaceDecision, vectorVillage, villagePosition_inVector);

		if (is_Equals1(userInput_workplaceType) == true) {
			workplacePosition_inVector = chooseBuildingPlotPosition_village(villagePosition_inVector, vectorVillage);

			setProdBuildingWorker_village(vectorVillage, vectorPerson, villagePosition_inVector, workplacePosition_inVector, personPosition_inVector_value);
			workplace = displayProdBuildingName_village(vectorVillage, villagePosition_inVector, workplacePosition_inVector);

			printSuccessProdWorkplaceAssignment(characterHandle, workplace);
		}
		if (is_Equals2(userInput_workplaceType) == true) {
			workplacePosition_inVector = chooseResourcePlotPosition_village(villagePosition_inVector, vectorVillage);

			setResourceBuildingWorker_village(vectorVillage, vectorPerson, villagePosition_inVector, workplacePosition_inVector, personPosition_inVector_value);
			workplace = displayResourceBuildingName_village(vectorVillage, villagePosition_inVector, workplacePosition_inVector);

			printSuccessResourceWorkplaceAssignment(characterHandle, workplace);
		}
	} while (is_Less1bigger2(charAssignWorkplaceDecision) == true);
}
void char_InvSection(vector <classPerson>* vectorPerson, vector <classVillage>* vectorVillage, int vectorPersonPosition, classInventory* valueInventory) {
	string characterHandle;
	int charInvDecision = 0;
	clearScreen();

	while (charInvDecision < 1 || charInvDecision > 3) {
		characterHandle = get_characterHandle(vectorPerson, vectorPersonPosition);
		print_ListChar(characterHandle, "charInventory");
		cin >> charInvDecision;

		if (charInvDecision == 1) {
			vectorPerson->at(vectorPersonPosition).setProductionEquipment(valueInventory);
		}
		if (charInvDecision == 2) {
			vectorPerson->at(vectorPersonPosition).setFrontWeapon(valueInventory);
		}
		if (charInvDecision == 3) {
			vectorPerson->at(vectorPersonPosition).setBackWeapon(valueInventory);
		}

		// invalid user input
		if (charInvDecision < 1 || charInvDecision > 3) {
			if (retryOrReturn() == 99) { break; }
		}
	}
}
void char_EditSection(vector <classPerson>* vectorPerson, vector <classVillage>* vectorVillage, int vectorPersonPosition, classInventory* valueInventory) {
	string characterHandle = get_characterHandle(vectorPerson, vectorPersonPosition);
	int charEditDecision = 0;
	clearScreen();

	while (charEditDecision != 1) {
		print_ListChar(characterHandle, "charEdit");
		cin >> charEditDecision;

		if (charEditDecision == 1) {
			vectorPerson->at(vectorPersonPosition).setNewName(vectorPerson);
			pauseScreen();
		}

		// invalid user input
		if (charEditDecision != 1) {
			if (retryOrReturn() == 99) { break; }
		}
	}
}
void char_OverviewSection(vector <classPerson>* vectorPerson, vector <classVillage>* vectorVillage, int vectorPersonPosition, classInventory* valueInventory) {
	string charName = vectorPerson->at(vectorPersonPosition).getName();
	int charInfoDecision = 0;
	clearScreen();

	while (charInfoDecision < 1 || charInfoDecision > 3) {
		print_ListChar(charName, "charOverview");
		cin >> charInfoDecision;

		if (charInfoDecision == 1) {
			vectorPerson->at(vectorPersonPosition).getOverview();
			pauseScreen();
		}

		// invalid user input
		if (charInfoDecision < 1 || charInfoDecision > 3) {
			if (retryOrReturn() == 99) { break; }
		}
	}
}



/*
	RESOURCE HARVESTING SECTION
*/

// WIP
void resource_MainMenu(vector <classPerson>* vectorPerson, vector <classVillage>* vectorVillage, classInventory* valueInventory) {
	resourceSectionBegin:
	int resourceSectionDecision;

	clearScreen();
	cout << "Showing available options for the Resource Harvesting";
	cout << "\n\n(1) LEAVE BLANK";
	cout << "\n(2) Show Resources";
	cout << "\n(3) Show Production Equipment"; // Production and Weapon Equipment should always be the last option (when more Sections will be added)
	cout << "\n(4) Show Weapon Equipment\n";

	cin >> resourceSectionDecision;

	if (resourceSectionDecision == 1) {}
	else if (resourceSectionDecision == 2) { valueInventory->showResources(); }
	else if (resourceSectionDecision == 3) { valueInventory->showProductionEquipment(); }
	else if (resourceSectionDecision == 4) { valueInventory->showWeaponEquipment(); }
	else {
	resourceSectionRetry:
		int userInput;

		cout << "\nYou've choosen a non viable option. What do you wanna do?";
		cout << "\n(1) Go the Main Screen\n(2) Try again\n";
		cin >> userInput;
		if (userInput == 1) {
			cout << "\nGoing to the Main Screen\n";
			pauseScreen();
		}
		else if (userInput == 2) {
			cout << "\nGoing to Resource Harvesting Section\n";
			pauseScreen();
			goto resourceSectionBegin;

		}
		else {
			goto resourceSectionRetry;
		}
	}
}

/*
	INVENTORY SECTION
*/

void inventory_MainMenu(vector <classPerson>* vectorPerson, vector <classVillage>* vectorVillage, classInventory* valueInventory) {
	int inventorySectionDecision = 0;

	while (inventorySectionDecision < 1 || inventorySectionDecision > 3) {
		print_ListInventory("Inventory", "inventory");
		cin >> inventorySectionDecision;

		if (inventorySectionDecision == 1) {
			valueInventory->showResources();
		}
		if (inventorySectionDecision == 2) {
			valueInventory->showProductionEquipment();
		}
		if (inventorySectionDecision == 3) {
			valueInventory->showWeaponEquipment();
		}

		// invalid user input
		if (inventorySectionDecision < 1 || inventorySectionDecision > 3) {
			if (retryOrReturn() == 99) { break; }
		}
	}
}


/*
	CHOOSE SOMETHING SECTION
*/

// print out villages and user will decide on a Village (from vector vectorVillages in main())
int chooseVillage(vector <classVillage>* vectorVillage) {
	int userInput;
	while (true) {
		clearScreen();
		cout << "Which Village do you choose?\n";
		print_AllVillages(vectorVillage);

		cin >> userInput;
		if (userInput <= vectorVillage->size() && userInput != 0) {
			userInput -= 1;
			return userInput;
		}
	}
}

void print_AllVillages(vector <classVillage>* vectorVillage) {
	for (int counter = 0; counter < vectorVillage->size(); counter++) {
		cout << print_Counter(counter) << vectorVillage->at(counter).getVillageName();
	}
	cout << "\n\nInput: ";
}

/*
	UTILITY FUNCTIONS
*/

int retryOrReturn() {
	int userInput;
	cout << "\nYour input was not covered in the list.\nWhat do you wann do?";
	cout << "\n(1) Go to the Main Menu\n(press any number) Try again\n";
	cin >> userInput;
	
	// 99 is the global "go back to main menu" code
	return userInput == 1 ? 99 : userInput;
	clearScreen();
}

// will generate a list with "pickable" options
// string category = for which category (Village, Character, Inventory) are you generating a list for
// uses contentListXXX to generate the list with option
void print_ListVillages(string coloredText, string category) {
	string categoryText = print_CurrentSection(category);
	
	clearScreen();
	cout << "Current section: " << yellowText(categoryText) << "\n";
	cout << "Showing available options for village " << darkGreenText(coloredText) << "\n\n";
	
	// Village Lists
	if (category == "village") { for (int counter = 0; counter < 3; counter++) { cout  << print_Counter(counter) << contentListVillage(counter); } }
	if (category == "villageInfo") { for (int counter = 0; counter < 3; counter++) { cout << print_Counter(counter) << contentListVillageInfo(counter); } }
	if (category == "villageBuild") { for (int counter = 0; counter < 2; counter++) { cout << print_Counter(counter) << contentListVillageBuild(counter); } }
	if (category == "villageEdit") { for (int counter = 0; counter < 1; counter++) { cout << print_Counter(counter) << contentListVillageEdit(counter); } }
	
	// Inventory List
	//for (int x = 0; x <= maxSize; x++) { cout << "\n(" << x << ") " << contentListVillage(x); }
	cout << "\n\nInput: ";
}

// content for generating a list referencing the options for a village
string contentListVillage(int position) {
	vector <string> contentVillage;

	contentVillage.push_back("Building Section\n");
	contentVillage.push_back("Edit Village Information\n");
	contentVillage.push_back("Village Information\n");
	
	return contentVillage.at(position);
}
string contentListVillageInfo(int position) {
	vector <string> contentVillageInfo;

	contentVillageInfo.push_back("Show all lots\n");
	contentVillageInfo.push_back("Show Resource lots\n");
	contentVillageInfo.push_back("Show Building lots\n");

	return contentVillageInfo.at(position);
}
string contentListVillageBuild(int position) {
	vector <string> contentVillageBuild;

	contentVillageBuild.push_back("Construct a building\n");
	contentVillageBuild.push_back("Demolish a building\n");

	return contentVillageBuild.at(position);
}
string contentListVillageEdit(int position) {
	vector <string> contentVillageEdit;

	contentVillageEdit.push_back("Edit Name\n");

	return contentVillageEdit.at(position);
}

void print_ListChar(string coloredText, string category) {
	string categoryText = print_CurrentSection(category);

	clearScreen();
	cout << "Current section: " << yellowText(categoryText) << "\n";
	cout << "Showing available options for " << darkGreenText(coloredText) << "\n\n";

	// Character Lists
	if (category == "charSection") { for (int counter = 0; counter < 5; counter++) { cout << print_Counter(counter) << contentListChar(counter); } }
	if (category == "charWorkplace") { for (int counter = 0; counter < 2; counter++) { cout << print_Counter(counter) << contentListCharWorkplace(counter); } }
	if (category == "charInventory") { for (int counter = 0; counter < 3; counter++) { cout << print_Counter(counter) << contentListCharInventory(counter); } }
	if (category == "charEdit") { for (int counter = 0; counter < 1; counter++) { cout << print_Counter(counter) << contentListCharEdit(counter); } }
	if (category == "charOverview") { for (int counter = 0; counter < 1; counter++) { cout << print_Counter(counter) << contentListCharOverview(counter); } }

	cout << "\n\nInput: ";
}

// content for generating a list referencing the options for a character
string contentListChar(int position) {
	vector <string> contentChar;

	contentChar.push_back("Send scouting\n");
	contentChar.push_back("Assign workplace\n");
	contentChar.push_back("Manage inventory\n");
	contentChar.push_back("Edit character\n");
	contentChar.push_back("See character overview\n");

	return contentChar.at(position);
}
string contentListCharWorkplace(int position) {
	vector <string> contentCharWorkplace;

	contentCharWorkplace.push_back("Production\n");
	contentCharWorkplace.push_back("Resource\n");

	return contentCharWorkplace.at(position);
}
string contentListCharEdit(int position) {
	vector <string> contentCharEdit;

	contentCharEdit.push_back("Rename character\n");

	return contentCharEdit.at(position);
}
string contentListCharOverview(int position) {
	vector <string> contentCharOverview;

	contentCharOverview.push_back("Display Overview\n");

	return contentCharOverview.at(position);
}
string contentListCharInventory(int position) {
	vector <string> contentCharInventory;

	/*
	if (!vectorPerson->at(vectorPersonPosition).getHas_frontWeapon()) { // provides if a frontWeapon is assigned
		cout << "\n(2) Assign Frontline Weapon - " << "\x1B[32mNo Frontline Weapon assigned";
	}
	else { cout << "\n(2) Assign a new Frontline Weapon - " << "\x1B[32mFrontline Weapon: " << "\x1B[94m" << vectorPerson->at(vectorPersonPosition).getFrontWeapon(); }
	*/

	contentCharInventory.push_back("Production Tool\n");
	contentCharInventory.push_back("Frontline Weapon\n");
	contentCharInventory.push_back("Backline Weapon\n");

	return contentCharInventory.at(position);
}

void print_ListInventory(string coloredText, string category) {
	string categoryText = print_CurrentSection(category);

	clearScreen();
	cout << "Current section: " << yellowText(categoryText) << "\n";
	cout << "Showing available options for " << darkGreenText(coloredText) << "\n\n";

	// Village Lists
	if (category == "inventory") { for (int counter = 0; counter < 3; counter++) {
		cout << print_Counter(counter) << contentListInventory(counter);
		} 
	}
	cout << "\n\nInput: ";
}

// content for generating a list referencing the options in inventory
string contentListInventory(int position) {
	vector <string> contentInventory;

	contentInventory.push_back("Show Resources\n");
	contentInventory.push_back("Show Production Equipment\n");
	contentInventory.push_back("Show Weapon Equipment\n");

	return contentInventory.at(position);
}

string print_CurrentSection(string whichCategory) {
	while (true) {
		if (whichCategory == "village") { return "Village Section"; };
		if (whichCategory == "villageInfo") { return "Village Information"; };
		if (whichCategory == "villageBuild") { return "Village Build"; };
		if (whichCategory == "villageEdit") { return "Village Edit"; };

		if (whichCategory == "charSection") { return "Character Section"; };
		if (whichCategory == "charWorkplace") { return "Character Workplace"; };
		if (whichCategory == "charEdit") { return "Character Edit"; };
		if (whichCategory == "charOverview") { return "Character Overview"; };
		if (whichCategory == "charInventory") { return "Character Inventory"; };

		if (whichCategory == "inventory") { return "Inventory Section"; };
	}
}

// print out characters and user will decide on a character (from vector vectorPerson in main())
int chooseChar(vector <classPerson>* vectorPerson) {
	int userInput;
	while (true) {
		clearScreen();
		cout << "Which Character do you choose?\n\n";
		printCharacterList(vectorPerson);
		cout << "\n\nInput: ";
		cin >> userInput;
		userInput -= 1;
		if (userInput < vectorPerson->size() && userInput >= 0)	{
			return userInput;
		}
	}
}

// returns an integer of the amount of villages in vectorVillages
// displays text with the desired word (eg. Workplace/Village)
int printVillageTextAndPosition(vector <classVillage>* vectorVillage, string textToDisplay) {
	int vectorVillagePosition;
	if (vectorVillage->size() == 1) {
		cout << "\nSince you only have one Village at the moment we will ask you which " << darkGreenText(textToDisplay)  << " you want to choose\n\n";
		return 0;
	}
	else {
		cout << "\n\nFirstly: we will ask you which " << darkGreenText("Village you want to choose");
		cout << "\nSecondly: we will ask you which " <<  darkGreenText(textToDisplay + " you want to choose\n\n");
		return vectorVillagePosition = chooseVillage(vectorVillage);;
	}
	pauseScreen();
}

string get_characterHandle(vector <classPerson>* vectorPerson, int vectorPersonPosition) {
	string characterHandle;

	string tempGender = vectorPerson->at(vectorPersonPosition).getGender();
	tempGender.resize(1);
	characterHandle = vectorPerson->at(vectorPersonPosition).getName() + "(" + tempGender + ")";

	if (tempGender == "M") { /* Displaying Name in Color 36m for Male */
		characterHandle = cyanText(vectorPerson->at(vectorPersonPosition).getName() + "(" + tempGender + ")");
		return characterHandle;
	}
	else { /* Displaying Name in Color 35m for Female */
		characterHandle = magentaText(vectorPerson->at(vectorPersonPosition).getName() + "(" + tempGender + ")");
		return characterHandle;
	}
}

void printCharacterList(vector <classPerson>* vectorPerson) {
	for (int counter = 0; counter < vectorPerson->size(); counter++) {
		cout << print_Counter(counter) << get_characterHandle(vectorPerson, counter) << "\n";
	}
}

/*
	GENERAL UTILITY
*/

bool areProdBuildingsPresent(vector <classVillage>* vectorVillage_value, int villagePositon_inVector_value) {
	if (vectorVillage_value->at(villagePositon_inVector_value).areProductionBuildingsPresent() == true) {
		return true;
	}
	else {
		return false;
	}
}
string displayProdBuildingName_village(vector <classVillage>* vectorVillage_value, int villagePosition_inVector_value, int workplacePosition_inVector_Value) {
	return vectorVillage_value->at(villagePosition_inVector_value).getProdBuildingName(workplacePosition_inVector_Value);
}
string displayResourceBuildingName_village(vector <classVillage>* vectorVillage_value, int villagePosition_inVector_value, int workplacePosition_inVector_Value) {
	return vectorVillage_value->at(villagePosition_inVector_value).getResourceBuilding(workplacePosition_inVector_Value);
}


/*
	WORKPLACE UTILITY
*/

int checkUserinput(int userinput_value, vector <classVillage>* vectorVillage_value, int villagePosition_inVector_value) {
	if (userinput_value == 1 && areProdBuildingsPresent(vectorVillage_value, villagePosition_inVector_value)) {
		return userinput_value;
	}
	else {
		return userinput_value;
	}
}
int chooseBuildingPlotPosition_village(int villagePosition_inVector_value, vector <classVillage>* vectorVillage_value) {
	int userInput;

	userInput = vectorVillage_value->at(villagePosition_inVector_value).chooseProdBuildingPlotPosition();
	clearScreen();
	return userInput;
}
int chooseResourcePlotPosition_village(int villagePosition_inVector_value, vector <classVillage>* vectorVillage_value) {
	int userInput;

	userInput = vectorVillage_value->at(villagePosition_inVector_value).chooseResourcePlotPosition();
	clearScreen();
	return userInput;
}

void printSuccessProdWorkplaceAssignment(string character_value, string workplace_value) {
	cout << "The Person " << character_value << " was assigned to the Production Workplace " << darkGreenText(workplace_value) << "\n\n";
	pauseScreen();
}
void printSuccessResourceWorkplaceAssignment(string character_value, string workplace_value) {
	cout << "The Person " << character_value << " was assigned to the Resource Workplace " << darkGreenText(workplace_value)  << "\n\n";
	pauseScreen();
}

void setProdBuildingWorker_village(vector <classVillage>* vectorVillage_value, vector <classPerson>* vectorPerson_value, int villagePosition_inVector_value, int workplacePosition_inVector_value, int personPosition_inVector_Value) {
	vectorVillage_value->at(villagePosition_inVector_value).setProdBuildingWorker(workplacePosition_inVector_value, vectorPerson_value->at(personPosition_inVector_Value));
}
void setResourceBuildingWorker_village(vector <classVillage>* vectorVillage_value, vector <classPerson>* vectorPerson_value, int villagePosition_inVector_value, int workplacePosition_inVector_value, int personPosition_inVector_Value) {
	vectorVillage_value->at(villagePosition_inVector_value).setResourceBuildingWorker(workplacePosition_inVector_value, vectorPerson_value->at(personPosition_inVector_Value));
}


/*
	CREATION FUNCTIONS
*/
// will create 2 characters and if the gender is equal between both of them will change the 2nd characters gender and name accordingly
void createChars(vector <classPerson>* vectorPersons) {
	int howManyToCreate = 2;
	for (int x = 0; x < howManyToCreate; x++) {
		if (vectorPersons->size() == 1)	{
			if (vectorPersons->at(0).getGender() == "Male")	{
				this_thread::sleep_for(chrono::milliseconds(1500));
				classPerson objectChar;
				objectChar.setGender_MaleToFemale();
				cout << "\nCreating " << x + 1 << " Character";
				vectorPersons->push_back(objectChar);
				cout << "............." << endl;
			}
			else {
				this_thread::sleep_for(chrono::milliseconds(1500));
				classPerson objectChar;
				objectChar.setGender_MaleToFemale();
				cout << "\nCreating " << x + 1 << " Character";
				vectorPersons->push_back(objectChar);
			}
		}
		else {
			cout << "\nCreating " << x + 1 << " Character";
			this_thread::sleep_for(chrono::milliseconds(1500));
			classPerson objectChar;
			vectorPersons->push_back(objectChar);
		}
	}
}

void createVillage(vector <classVillage>* vectorVillage) {
	/*------Marcel(9/9) begin----------------------------------------------
	string userInput; // will be used for naming the village
	printf("\nPlease type in the name of your Village: \033[0m");
	cin >> userInput;
	classVillage village1(userInput);
	------Marcel(9/9) end------------------------------------------------*/
	classBuilding buildingObj("Empty", "nothing", "");
	classVillage village1("London", buildingObj);
	village1.setResourceBuildings(1);
	//classVillage village2("Essex", buildingObj);
	vectorVillage->push_back(village1);
	//vectorVillage->push_back(village2);
	printf("\nYour village is created\n");
}

// FOR DEBUGING: For faster testing purposes
void createBuildings(vector <classVillage>* vectorVillage) {
	vector <string> prod_buildingNames		= { "Crafter", "Research Hut", "House" };
	vector <string> prod_buildingTypes = { "production", "production", "living" };
	vector <string> prod_buildingsJobName	= { "Craftsman", "Scholar", ""};

	for (int counter = 0; counter < 3; counter++) {
		vectorVillage->at(0).setProdBuilding_Cheat(prod_buildingNames.at(counter), counter, prod_buildingTypes.at(counter), prod_buildingsJobName.at(counter));
	}
}