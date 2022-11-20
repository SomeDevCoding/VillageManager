#pragma once
#include <string>
#include <time.h>
#include <iostream>
#include <vector>

#include "classBuilding.h"
#include "Utility.h"

using namespace std;

class classVillage {
private:
	string villageName;

	vector <classBuilding> resourcePlots;
	vector <classBuilding> buildingPlots;

	int storageLevel; // Standard storage level = 1
	int storageCap; // Standard storage Capacity = 10 + 5 each for every additional storageLevel


public:
	// Constructor declaration of Class "classVillage"
	classVillage(string value, classBuilding buildingObj);

	// set methods
	void setResourceBuildings(int value);

	void setProdBuildingWorker(int buildingSpacesPosition, classPerson workerObjValue);
	void setResourceBuildingWorker(int buildingSpacesPosition, classPerson workerObjValue);

	void setVillageName(vector <classVillage>* valueVector);

	// DEBUGING / CHEATING
	void setProdBuilding_Cheat(string para_Buildingname, int para_Position_inVector, string para_BuildingType, string para_Jobname);
	void setResourceBuilding_Cheat(string para_Buildingname, int para_Position_inVector, string para_BuildingType, string para_Jobname);

	// add and sub methods
	void addStorageLevel();	// Not in use for now
	void subStorageLevel();	// Not in use for now

	// build/destroy methods
	void constructBuilding();
	void demolishBuilding();
	void print_destroyedBuilding(vector<classBuilding>* destroyedBuilding, int vectorPosition);

	// choose building methods
	int chooseProdBuildingPlotPosition();
	string chooseProdBuilding(string buildingTypeValue);
	string chooseProdBuildingType();

	// Calling resource choose methods
	int chooseProdBuildingPlotPositionConstruct();
	int chooseResourcePlotPosition();

	// get methods
	string getVillageName();

	string getProdBuildingName(int vectorPosition);
	string getResourceBuilding(int vectorPosition);
	string getIndividualPlot(int vectorPosition);

	void print_VillageAllBuildingsInformation(); // calls getBuildingPlotsInformation & getResourceBuildings
	void print_ResourceBuildingsInformation();
	void print_buildingPlotsInformation();

	int getDecision();

	string getBuildingJobName(string valueBuilding);

	bool areProductionBuildingsPresent();

	void invalidChoice_destroy(int position);
	void invalidChoice_build(int position, string current_buildingname);

	inline bool get_EmptyPlot(int temp_userInput);
	inline bool get_BuildingType(string temp_userInput, string temp_type);
	inline void print_stringVector_Elements(vector <string> temp_vector);

	// Iterator
	vector<classBuilding>::iterator chooseBuildingPlotIterator() {
		vector<classBuilding>::iterator vectorPosition;
		int numberPosition;
		clearScreen();
		print_VillageAllBuildingsInformation();
		cout << "\x1B[31m\nPlease choose one of the displayed Lots.\033[0m\n";
		cin >> numberPosition;
		vectorPosition = buildingPlots.begin() + numberPosition - 1;

		return vectorPosition;
		//it = myvector.begin();
		//myvector.erase(it);

		//iterator = vector.insert(vector.begin() + i, 7);
		//vector_name.insert (position, val)
	}
};