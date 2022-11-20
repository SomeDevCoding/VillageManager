#include <string>
#include <time.h>
#include <iostream>
#include <vector>

#include "classVillage.h"
#include "Utility.h"

using namespace std;

// Calling constructor
classVillage::classVillage(string value, classBuilding buildingObj) {
	buildingPlots.assign(4, buildingObj);
	villageName			= value;
	storageLevel		= 1;
	storageCap			= 10;
}

// Calling set methods
void classVillage::setResourceBuildings(int value) {
	vector <string> firstVillage	= { "Forest", "Stone Mine", "Farm" };
	vector <string> secondVillage	= { "Copper Mine", "Tin Mine" };

	if (value == 1) {
		for (int x = 0; x < firstVillage.size(); x++) {
			string jobName = getBuildingJobName(firstVillage.at(x));
			classBuilding buildingObj(firstVillage.at(x), "resource", jobName);
			resourcePlots.push_back(buildingObj);
		}
	}
	else if (value == 2) {
		for (int x = 0; x < secondVillage.size(); x++) {
			string jobName = getBuildingJobName(secondVillage.at(x));
			classBuilding buildingObj(secondVillage.at(x), "resource", jobName);
			resourcePlots.push_back(buildingObj);
		}
	}
}

void classVillage::setProdBuildingWorker(int buildingPlotPosition, classPerson workerObjValue) {
	buildingPlots.at(buildingPlotPosition).setWorkerObj(workerObjValue);
}
void classVillage::setResourceBuildingWorker(int resourcePlotPosition, classPerson workerObjValue) {
	resourcePlots.at(resourcePlotPosition).setWorkerObj(workerObjValue);
}

void classVillage::setVillageName(vector <classVillage>* valueVector) {
	string newVillageName;
	bool isVillageName = true;

	clearScreen();
	cout << "You've chosen to rename " << darkGreenText(villageName);
	cout << "\nType in a new name for your village:\n";
	cin >> newVillageName;

	for (int x = 0; x < valueVector->size(); x++) {
		if (newVillageName == valueVector->at(x).getVillageName()) {
			cout << "\nYou've chosen the name " << darkGreenText(newVillageName) << " which is already the current name of " << "(" << x + 1 << ") " << darkGreenText(valueVector->at(x).getVillageName());
			cout << "\nGoing to the Main Screen\n\n";
			break;
		}
		else { isVillageName = false; }
	}
	if (!isVillageName) {
		string confirmationText = redText("Rename") + " " + darkGreenText(villageName) + " to " + darkGreenText(newVillageName) + " ?";
		if (userConfirmation(confirmationText) == 1) {
			villageName = newVillageName;
			cout << "\nYour village was successfully renamed to " << darkGreenText(villageName) << "\n";
		}
		else { cout << "\nGoing to the Main Screen\n"; }
	}
}

void classVillage::setProdBuilding_Cheat(string para_Buildingname, int para_Position_inVector, string para_BuildingType, string para_Jobname) {
	classBuilding buildingObj(para_Buildingname, para_BuildingType, para_Jobname);
	buildingPlots.at(para_Position_inVector) = buildingObj;
}

void classVillage::setResourceBuilding_Cheat(string para_Buildingname, int para_Position_inVector, string para_BuildingType, string para_Jobname) {
	classBuilding buildingObj(para_Buildingname, para_BuildingType, para_Jobname);
	resourcePlots.at(para_Position_inVector) = buildingObj;
}

// Calling add and sub methods
void classVillage::addStorageLevel() {
	storageLevel	+= 1;
	storageCap		+= 5;
}
void classVillage::subStorageLevel() {
	storageLevel	-= 1;
	storageCap		-= 5;
}

// Calling build/destroy methods
void classVillage::constructBuilding() {
	clearScreen();

	string intro_1stLine = magentaText("Firstly:") + " we will ask you what " + brightBlueText("Building") + " you want to " + brightBlueText("build");
	string intro_2ndLine = magentaText("Secondly") + " we will ask you which " + brightBlueText("Lot") + " you want to build on";
	printText(intro_1stLine);
	printText(intro_2ndLine);

	pauseScreen();
	string buildingType		= chooseProdBuildingType();
	string buildingName		= chooseProdBuilding(buildingType);
	string buildingJobName	= getBuildingJobName(buildingName);
	
	int vectorPosition = chooseProdBuildingPlotPositionConstruct(); // user will choose plot position here
	string confirmationText = redText("Build") + " " + darkGreenText(buildingName) + " on Lot " + darkGreenText(vectorPosition + 1) + " in " + darkGreenText(villageName) + "?";

	pauseScreen();
	if (buildingPlots.at(vectorPosition).getBuildingName() == "Empty") {
		if (userConfirmation(confirmationText) == 1) {
			classBuilding buildingObj(buildingName, buildingType, buildingJobName); /* creating building object */
			buildingPlots.at(vectorPosition) = buildingObj; /* move object into vector */
		}
		else {
			cout << "\nYou've chosen to not to build the structure\n";
		}
	}
	else {
		clearScreen();
		string current_buildingName = getProdBuildingName(vectorPosition);
		invalidChoice_build(vectorPosition, current_buildingName);
	}
}
void classVillage::demolishBuilding() {
	clearScreen();
	cout << "You have decided to destroy a structure in " << darkGreenText(getVillageName());
	cout << "\n\nNow we will ask you to choose a" << darkGreenText("Lot") << " where the structure shall be destroyed\n";
	pauseScreen();

	int vectorPosition		= chooseProdBuildingPlotPosition(); // user will choose plot position here
	string buildingName		= buildingPlots.at(vectorPosition).getBuildingName();
	string confirmationText	= redText("Destroy") + " " + darkGreenText(buildingName) + " on Lot " + darkGreenText(vectorPosition + 1) + " in " + darkGreenText(villageName) + "?";

	if (buildingPlots.at(vectorPosition).getBuildingName() != "Empty") {
		if (userConfirmation(confirmationText) == 1) {
			print_destroyedBuilding(&buildingPlots, vectorPosition);
		}
		else {
			cout << "\nYou've chosen to not destroy the structure\n";
		}
	}
	else {
		clearScreen();
		invalidChoice_destroy(vectorPosition);
	}
}

void classVillage::print_destroyedBuilding(vector<classBuilding>* valueVector, int vectorPosition) {
	classBuilding destroyedBuildingObj("Empty", "nothing", "");
	cout << "Destroyed the " << darkGreenText(buildingPlots.at(vectorPosition).getBuildingName()) << " from Lot " << darkGreenText(vectorPosition + 1) << " in " << darkGreenText(getVillageName()) << "\n";
	valueVector->at(vectorPosition) = destroyedBuildingObj;
}

// Calling building choose methods
int classVillage::chooseProdBuildingPlotPositionConstruct() {
	int vectorSize = buildingPlots.size();
	clearScreen();
	print_buildingPlotsInformation();
	cout << "\nPlease choose one of the displayed Lots:\n";
	
	int position_userInput = get_userInput();
	position_userInput -= 1;

	// if you see this M.. yes I know you can do "!get_InputInRange" Amen
	// comment can be deleted when read by M :)
	if(get_if_InputInRange(vectorSize, position_userInput) == true) {
		if (get_EmptyPlot(position_userInput) == true) {
			return position_userInput;
		}
	}	

}
int classVillage::chooseProdBuildingPlotPosition() {
	int userInputPosition = 0;
	while (userInputPosition <= 0 || userInputPosition > buildingPlots.size()) {
		clearScreen();
		print_buildingPlotsInformation();
		cout << "\nPlease choose one of the displayed Lots:\n";
		cin >> userInputPosition;
	}
	return userInputPosition - 1;
}

string classVillage::chooseProdBuilding(string temp_userInput_buildingType) {
	clearScreen();
	vector <string> vectorProductionBuildingsGen1 = { "Crafter", "Research Hut" };
	vector <string> vectorLivingSpaceGen1 = { "House", "Kitchen" };

	string text = "Which " + brightBlueText(temp_userInput_buildingType) + brightBlueText(" Building") + " do you want to build?";
	int ifTemp_userInput;

	if (get_BuildingType(temp_userInput_buildingType, "production") == true) {
		do {
			clearScreen();
			printText(text);
			print_stringVector_Elements(vectorProductionBuildingsGen1);
			ifTemp_userInput = get_userInput();
		} while (ifTemp_userInput < 1 || ifTemp_userInput > 2);
		
		return vectorProductionBuildingsGen1.at(ifTemp_userInput - 1);
	}
	else if (get_BuildingType(temp_userInput_buildingType, "living") == true) {
		do {
			clearScreen();
			printText(text);
			print_stringVector_Elements(vectorProductionBuildingsGen1);
			ifTemp_userInput = get_userInput();
		} while (ifTemp_userInput < 1 || ifTemp_userInput > 2);
		
		return vectorLivingSpaceGen1.at(ifTemp_userInput - 1);
	}
}
string classVillage::chooseProdBuildingType() {
	int chooseBuildingDecision = 0;

	while (chooseBuildingDecision < 1 || chooseBuildingDecision > 2) {
		clearScreen();
		cout << "What do you want to build?\n\n";
		cout << "(1) Production Building\n";
		cout << "(2) Living Space\033[0m\n";
		cin >> chooseBuildingDecision;
		if (chooseBuildingDecision == 1) { return "production"; }
		else if (chooseBuildingDecision == 2) { return "living"; }
	}
}

// Calling resource choose methods
int classVillage::chooseResourcePlotPosition() {
	int userInputPosition;
	clearScreen();
	print_ResourceBuildingsInformation();
	cout << "\nPlease choose one of the displayed Lots:\033[0m\n";
	cin >> userInputPosition;
	while (true) {
		if (userInputPosition > 0 && userInputPosition <= resourcePlots.size()) {
			return userInputPosition - 1;
		}
	}
}

// Calling get methods
string classVillage::getVillageName() { return villageName; }
string classVillage::getProdBuildingName(int vectorPosition) {
	string value = buildingPlots.at(vectorPosition).getBuildingName();
	return value;
}
string classVillage::getResourceBuilding(int vectorPosition) {
	string value = resourcePlots.at(vectorPosition).getBuildingName();
	return value;
}
string classVillage::getIndividualPlot(int vectorPosition) { return buildingPlots.at(vectorPosition).getBuildingName(); }

// calls getBuildingPlotsInformation & getResourceBuildings
void classVillage::print_VillageAllBuildingsInformation() {
	print_buildingPlotsInformation();
	cout << "\n\n";
	print_ResourceBuildingsInformation();
}
void classVillage::print_ResourceBuildingsInformation() {
	cout << "Showing Resource Buildings of " << "\x1B[32m" << getVillageName() << "\033[0m\n";
	for (int x = 0; x < resourcePlots.size(); x++) {
		cout << "\n(" << x + 1 << ") Lot - \x1B[32m" << resourcePlots.at(x).getBuildingName() << "\n" << "\033[0m";
		cout << "Current Worker: \x1B[95m" << resourcePlots.at(x).getWorkerName() << "\033[0m";
	}
	cout << "\n";
}
void classVillage::print_buildingPlotsInformation() {
	cout << "Showing Production Buildings of " << "\x1B[32m" << getVillageName() << "\033[0m\n";
	for (int x = 0; x < buildingPlots.size(); x++) {
		if (buildingPlots.at(x).getBuildingName() == "Empty") {
			/* Text when there is no building constructed on the specific plot */
			cout << "\n(" << x + 1 << ") Lot - " << buildingPlots.at(x).getBuildingName() << "\033[0m";
		}
		else {
			/* Text when there is a building constructed on the specific plot */
			cout << "\n(" << x + 1 << ") Lot - \x1B[32m" << buildingPlots.at(x).getBuildingName() << "\n" << "\033[0m";
			cout << "Current Worker: \x1B[95m" << buildingPlots.at(x).getWorkerName() << "\033[0m";
		}
	}
	cout << "\n";
}

/* 
	UTILITY SECTION
*/

int classVillage::getDecision() {
	cout << "\nYour input was wrong, what do you wanna do?";
	cout << "\n(1) Go to the Main Menu\n(press any number) Try again\n";
	int userInput;
	cin >> userInput;
	return userInput == 1 ? 1 : 2;
	clearScreen();
}

string classVillage::getBuildingJobName(string para_Building) {
	/* Production Buildings */
	if (para_Building == "Crafter") {
		return "Craftsman";
	}
	else if (para_Building == "Research Hut") {
		return "Scholar";
	}

	/* Resource Buildings */
	else if (para_Building == "Forest") {
		return "Woodsman";
	}
	else if (para_Building == "Stone Mine") {
		return "Miner";
	}
	else if (para_Building == "Farm") {
		return "Farmer";
	}
	else {
		return "";
	}
}

bool classVillage::areProductionBuildingsPresent() {
	for (int x = 0; x < buildingPlots.size(); x++) {
		if (buildingPlots.at(x).getProductionBuilding() == true) {
			return true; /* at least one production building has been built */
		}
	}
	return false; /* no production building has been built */
}

void classVillage::invalidChoice_destroy(int position) {
	cout << "You've decided to destroy an " << darkGreenText("Empty") << " place" << " on Lot " << darkGreenText(position + 1);
	cout << "\n\nThere is no structure present on this lot";
	cout << "\nGoing back to the main menu\n";
}
void classVillage::invalidChoice_build(int position, string current_buildingname) {
	cout << "There is already a building (" << redText(current_buildingname) << ") present" << " on Lot " << darkGreenText(position + 1);
	cout << "\n\nGoing back to the main menu\n";
}

inline bool classVillage::get_EmptyPlot(int temp_userInput) {
	if (buildingPlots.at(temp_userInput).getBuildingName() == "Empty") {
		return true;
	}
	else {
		return false;
	}
}
inline bool classVillage::get_BuildingType(string temp_userInput, string temp_type) {
	if (temp_userInput == temp_type) {
		return true;
	}
	else {
		return false;
	}
}
inline void classVillage::print_stringVector_Elements(vector <string> temp_vector) {
	for (int loop_counter = 0; loop_counter < temp_vector.size(); loop_counter++) {
		//cout << "\n(" << x + 1 << ") " << vectorProductionBuildingsGen1.at(x);
		cout << print_Counter(loop_counter) << temp_vector.at(loop_counter) << "\n";
	}
	cout << "\n\n";
}
