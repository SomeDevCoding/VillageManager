#include <iostream>
#include <vector>
#include <string>
#include<algorithm>

using namespace std;

void choose();
void sortAscending();
void sortDescending();
void factorial();
void highestNumber();
void lowestNumber();
void addUpAll();
void average();
void prime();
void checkIfEvenOrOdd();
void leastCommonMultiple();

int main()
{
    choose();
}

void choose() {
    system("cls");
    int decision;
    cout << "What do you want to do?\n\n";
    cout << "(1) Sort in ascending order\n";
    cout << "(2) Sort in descending order\n";
    cout << "(3) Factorial\n";
    cout << "(4) Get highest number\n";
    cout << "(5) Get lowest number\n";
    cout << "(6) Add up all numbers between two numbers\n";
    cout << "(7) Calculate the average\n";
    cout << "(8) Prime numbers\n";
    cout << "(9) Check if the enteretd number is even or odd\n";
    cout << "(10) Least common muliple of two numbers\n\n";
    cin >> decision;
    if (decision == 1) {
        sortAscending();
    }
    if (decision == 2) {
        sortDescending();
    }
    if (decision == 3) {
        factorial();
    }
    if (decision == 4) {
        highestNumber();
    }
    if (decision == 5) {
        lowestNumber();
    }
    if (decision == 6) {
        addUpAll();
    }
    if (decision == 7) {
        average();
    }
    if (decision == 8) {
        prime();
    }
    if (decision == 9) {
        checkIfEvenOrOdd();
    }
    if (decision == 10) {
        leastCommonMultiple();
    }
    else {
        choose();
    }
}
void sortAscending() {
    system("cls");
    cout << "Sort 10 random numbers in ascending order\n";
    cout << "Type in 10 random numbers\n\n";
    vector<int> vector;
    int number;
    for (int x = 0; x < 10; x++) {
        cout << "Number " << x + 1 << ": ";
        cin >> number;
        vector.push_back(number);
    }

    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            if (vector.at(x) < vector.at(y)) {
                swap(vector.at(x), vector.at(y));
            }
        }
    }
    /*---------------------------PRINTING RESULT----------------------------------------------------*/
    cout << "\nSORTED:\n\n";
    for (int x = 0; x < 10; x++) {
        cout << "Number " << x + 1 << ": " << vector.at(x) << "\n";
    }
    cout << "\n";
    system("pause");
    choose();
}

void sortDescending() {
    system("cls");
    cout << "Sort 10 random numbers in descending order\n";
    cout << "Type in 10 random numbers\n\n";
    vector<int> vector;
    int number;
    for (int x = 0; x < 10; x++) {
        cout << "Number " << x + 1 << ": ";
        cin >> number;
        vector.push_back(number);
    }

    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            if (vector.at(x) > vector.at(y)) {
                swap(vector.at(x), vector.at(y));
            }
        }
    }
    /*---------------------------PRINTING RESULT----------------------------------------------------*/
    cout << "\nSORTED:\n\n";
    for (int x = 0; x < 10; x++) {
        cout << "Number " << x + 1 << ": " << vector.at(x) << "\n";
    }
    cout << "\n";
    system("pause");
    choose();
}

void factorial() {
    system("cls");
    cout << "Calculate the factorial of a number: \n";
    int number;
    int factorial = 1;
    cout << "\nType in a number (max. 19): ";
    cin >> number;

    for (int x = 1; x <= number; x++) {
        factorial = factorial * x;
    }
    /*---------------------------PRINTING RESULT----------------------------------------------------*/
    cout << "\n!" << number << " = " << factorial << "\n\n";
    system("pause");
    choose();
}

void highestNumber() {
    system("cls");
    cout << "Get the highest out of 10 numbers\n";
    cout << "Type in 10 random numbers\n\n";
    vector<int> vector;
    int number;
    int max;
    for (int x = 0; x < 10; x++) {
        cout << "Number " << x + 1 << ": ";
        cin >> number;
        vector.push_back(number);
    }
    max = *max_element(vector.begin(), vector.end());
    /*---------------------------PRINTING RESULT----------------------------------------------------*/
    cout << "\nHighest number " << ": " << max << "\n\n";
    system("pause");
    choose();
}

void lowestNumber() {
    system("cls");
    cout << "Get the lowest out of 10 numbers\n";
    cout << "Type in 10 random numbers\n\n";
    vector<int> vector;
    int number;
    int min;
    for (int x = 0; x < 10; x++) {
        cout << "Number " << x + 1 << ": ";
        cin >> number;
        vector.push_back(number);
    }
    min = *min_element(vector.begin(), vector.end());
    /*---------------------------PRINTING RESULT----------------------------------------------------*/
    cout << "\nLowest number " << ": " << min << "\n\n";
    system("pause");
    choose();
}

void addUpAll() {
    system("cls");
    int number1;
    int number2;
    int result = 0;
    cout << "Add up all numbers between two numbers\n";
    cout << "\nNumber 1: ";
    cin >> number1;
    cout << "Number 2: ";
    cin >> number2;
    for (int x = number1; x <= number2; x++) {
        result = result + x;
    }
    /*---------------------------PRINTING RESULT----------------------------------------------------*/
    cout << "\nResult: " << result << "\n\n";
    system("pause");
    choose();
}

void average() {
    system("cls");
    int amountOfNumbers;
    vector<int> numbersVector;
    float number;
    float sumOfAll = 0;
    float result;
    cout << "Of how many numbers should the average be calculated?\n\nAmount: ";
    cin >> amountOfNumbers;
    cout << "\n";
    for (int x = 0; x < amountOfNumbers; x++) {
        cout << "Number " << x + 1 << ": ";
        cin >> number;
        numbersVector.push_back(number);
    }
    for (int x = 0; x < amountOfNumbers; x++) {
        sumOfAll = sumOfAll + numbersVector.at(x);
    }
    result = sumOfAll / amountOfNumbers;
    /*---------------------------PRINTING RESULT----------------------------------------------------*/
    cout << "\nAverage: " << result << "\n\n";
    system("pause");
    choose();
}

void prime() {
    system("cls");
    cout << "Display all prime numbers up to a certain number\n\nUp to which number all prime numbers should be displayed? ";
    int maxNumber;
    cin >> maxNumber;
    cout << "\n1\n3\n";
    for (int x = 2; x <= maxNumber; x++)
        for (int y = 2; y * y <= x; y++)
        {
            if (x % y == 0) {
                break;
            }
            else if (y + 1 > sqrt(x)) {
    /*---------------------------PRINTING RESULT----------------------------------------------------*/
                cout << x << "\n";
            }
        }
    cout << "\n";
    system("pause");
    choose();
}

void checkIfEvenOrOdd() {
    system("cls");
    cout << "Checks if the entered number is even or odd\n\nEnter a number: ";
    int number;
    cin >> number;
    /*---------------------------PRINTING RESULT----------------------------------------------------*/
    if (number % 2 == 0) {
        cout << "\n" << number << " is EVEN\n\n";
    }
    else{ cout << "\n" << number << " is ODD\n\n"; }
    system("pause");
    choose();
}

void leastCommonMultiple() {
    system("cls");
    cout << "Get the least common multiple of two numbers\n";
    int number1;
    cout << "\nNumber 1: ";
    cin >> number1;
    int number2;
    cout << "Number 2: ";
    cin >> number2;
    int leastCommonMultiple;
    if (number1 > number2) {
        leastCommonMultiple = number1;
    }
    else { leastCommonMultiple = number2; }
    while (true) {
        if (leastCommonMultiple % number1 == 0 && leastCommonMultiple % number2 == 0) {
    /*---------------------------PRINTING RESULT----------------------------------------------------*/
            cout << "\nLeast common multiple: " << leastCommonMultiple << "\n\n";
            break;
        }
        leastCommonMultiple++;
    }
    system("pause");
    choose();
}
