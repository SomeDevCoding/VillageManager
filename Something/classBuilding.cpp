#include <string>
#include <time.h>
#include <iostream>
#include <vector>

#include "classBuilding.h"
#include "classPerson.h"

using namespace std;

// Calling constructor
classBuilding::classBuilding(string valueBuildingName, string whatBuildingType, string valueJobName) {
	buildingName = valueBuildingName;
	jobName = valueJobName;

	if (whatBuildingType == "production") {
		isProductionBuilding = true;
	}
	else if (whatBuildingType == "living") {
		isLivingSpace = true;
	}
	else if (whatBuildingType == "resource") {
		isResourceBuilding = true;
	}
}

// Calling set methods for Building
void classBuilding::setBuildingName(string value) { buildingName = value; }

// Calling get methods for Building
string classBuilding::getBuildingName() { return buildingName; }
bool classBuilding::getProductionBuilding() { return isProductionBuilding; }
bool classBuilding::getLivingSpace() { return isLivingSpace; }
bool classBuilding::getResourceBuilding() { return isResourceBuilding; }

// Calling set methods for Worker
void classBuilding::setWorkerObj(classPerson workerObjValue) {
	workerObj = workerObjValue;
	setWorkerName(workerObj.getName());
	workerObj.setCurrentJob(jobName);
}
void classBuilding::setWorkerName(string workerNameValue) { workerName = workerNameValue; }

// Calling get methods for Worker
string classBuilding::getWorkerName() { return workerName; }