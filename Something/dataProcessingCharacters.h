#pragma once
#include <string>
#include <iostream>
#include <vector>

#include "classPerson.h"

using namespace std;

class dataProcessingCharacters {
private:
	// All Characters will be in here
	vector <classPerson> vectorChars;

public:
	// Constructor declaration
	dataProcessingCharacters();

	void addObject(classPerson valueObject);

	void getVectorContentsList();
	classPerson getObjectAtPosition(int vectorPosition);
	int getVectorPosition();

	string printCharacterHandle(int vectorPersonPosition);
	string getObjectGender(classPerson valueObject);
};
