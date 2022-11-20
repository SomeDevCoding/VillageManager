#pragma once
#include <string>
#include <time.h>
#include <iostream>
#include <vector>

#include "classPerson.h"

using namespace std;

class classBuilding {
private:
	// Building Information
	string buildingName;
	string jobDescription;
	string jobName;

	// Worker Information
	string workerName;
	classPerson workerObj;

	// Checking Values
	bool isProductionBuilding	= false;
	bool isLivingSpace			= false;
	bool isResourceBuilding		= false;

	void setWorkerName(string workerNameValue);

public:
	// Constructor declaration
	classBuilding(string valueBuildingName, string whatBuildingType, string valueJobName);

	// Set methods
	void setBuildingName(string value);

	// Get building methods
	string getBuildingName();
	bool getProductionBuilding();
	bool getLivingSpace();
	bool getResourceBuilding();


	// Set methods for Worker
	void setWorkerObj(classPerson workerObjValue);

	// Get methods for Worker
	string getWorkerName();
};