#include <string>
#include <iostream>
#include <vector>

#include "dataProcessingCharacters.h"
#include "Utility.h"

using namespace std;

// Constructor Definition
dataProcessingCharacters::dataProcessingCharacters() {}

void dataProcessingCharacters::getVectorContentsList() {
	for (int position = 0; position < vectorChars.size(); position++) {
		cout << "(" << position + 1 << ") " << printCharacterHandle(position) << "\n";
	}
}

void dataProcessingCharacters::addObject(classPerson valueObject) {
	vectorChars.push_back(valueObject);
}

classPerson dataProcessingCharacters::getObjectAtPosition(int vectorPosition) {
	return vectorChars.at(vectorPosition);
}

int dataProcessingCharacters::getVectorPosition() {
	int userInput;

	clearScreen();
	cout << "Choose your Character: \n";
	getVectorContentsList();
	cin >> userInput;
	return userInput;
}

string dataProcessingCharacters::printCharacterHandle(/*vector <classPerson> valueVectorPerson,*/int vectorPersonPosition) {
	string characterHandle;

	string tempGender = vectorChars.at(vectorPersonPosition).getGender();
	tempGender.resize(1);
	characterHandle = vectorChars.at(vectorPersonPosition).getName() + "(" + tempGender + ")";

	if (tempGender == "M") { /* Displaying Name in Color 36m for Male */
		characterHandle = cyanText(vectorChars.at(vectorPersonPosition).getName() + "(" + tempGender + ")");
		return characterHandle;
	}
	else { /* Displaying Name in Color 35m for Female */
		characterHandle = magentaText(vectorChars.at(vectorPersonPosition).getName() + "(" + tempGender + ")");
		return characterHandle;
	}
}
string dataProcessingCharacters::getObjectGender(classPerson valueObject) {
	return valueObject.getGender();
}