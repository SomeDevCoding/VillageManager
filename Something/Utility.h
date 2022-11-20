#pragma once
#include <string>
#include <sstream>

using namespace std;

/*Colored Text for Strings*/
inline string redText(string value) { return "\x1B[91m" + value + "\033[0m"; }

inline string blueText(string value) { return "\x1B[34m" + value + "\033[0m"; }

inline string darkGreenText(string value) { return "\x1B[32m" + value + "\033[0m"; }

inline string magentaText(string value) { return "\x1B[35m" + value + "\033[0m"; }

inline string cyanText(string value) { return "\x1B[36m" + value + "\033[0m"; }

inline string yellowText(string value) { return "\x1B[33m" + value + "\033[0m"; }

inline string brightBlueText(string value) { return "\x1B[94m" + value + "\033[0m"; }

/*Colored Text for Integers*/
inline string redText(int value) {
	stringstream convert;
	convert << value;
	string text;
	convert >> text;
	return "\x1B[91m" + text + "\033[0m";
}

inline string blueText(int value) {
	stringstream convert;
	convert << value;
	string text;
	convert >> text;
	return "\x1B[34m" + text + "\033[0m";
}

inline string darkGreenText(int value) {
	stringstream convert;
	convert << value;
	string text;
	convert >> text;
	return "\x1B[32m" + text + "\033[0m";
}

inline string magentaText(int value) {
	stringstream convert;
	convert << value;
	string text;
	convert >> text;
	return "\x1B[35m" + text + "\033[0m";
}

inline string cyanText(int value) {
	stringstream convert;
	convert << value;
	string text;
	convert >> text;
	return "\x1B[36m" + text + "\033[0m";
}

inline string yellowText(int value) {
	stringstream convert;
	convert << value;
	string text;
	convert >> text;
	return "\x1B[33m" + text + "\033[0m";
}

inline string brightBlueText(int value) {
	stringstream convert;
	convert << value;
	string text;
	convert >> text;
	return "\x1B[94m" + text + "\033[0m";
}

/*Confirm user's decision from various things*/
inline int userConfirmation(string confirmationText) {
	cout << "\n" << confirmationText;
	cout << "\n\n(1) Yes";
	cout << "\n(2) No\n";
	int input;
	cin >> input;
	return input;
}

// ask for user input and returns it
inline int get_userInput() {
	int temp_userInput;
	cin >> temp_userInput;
	return temp_userInput;
}

inline bool is_Less1bigger2(int temp_userInput) {
	if (temp_userInput < 1 || temp_userInput > 2) {
		return true;
	}
	else {
		return false;
	}
}


inline bool is_Equals1(int temp_userInput) {
	if (temp_userInput == 1) {
		return true;
	}
	else {
		return false;
	}
}
inline bool is_Equals2(int temp_userInput) {
	if (temp_userInput == 2) {
		return true;
	}
	else {
		return false;
	}
}
inline bool is_Equals3(int temp_userInput) {
	if (temp_userInput == 3) {
		return true;
	}
	else {
		return false;
	}
}
inline bool is_Equals4(int temp_userInput) {
	if (temp_userInput == 4) {
		return true;
	}
	else {
		return false;
	}
}
inline bool is_Equals5(int temp_userInput) {
	if (temp_userInput == 5) {
		return true;
	}
	else {
		return false;
	}
}

/*
	Used in: if with size - vector.size()
	Returns: true if userInput is in size range
	Breakdown: userInput > 0 && userInput <= size
*/
inline bool get_if_InputInRange(int temp_size, int temp_userInput) {
	if (temp_userInput > 0 && temp_userInput <= temp_size) {
		return true;
	}
	else {
		return false;
	}
}

inline void printText(string text) {
	cout << text << "\n";
}
inline void clearScreen() {
	system("cls");
}
inline void pauseScreen() {
	system("pause");
}

// adds plus one to the "counter" and displays it
inline string print_Counter(int value) {
	value += 1;
	cout << "(" << value << ") ";
	return "";
}

