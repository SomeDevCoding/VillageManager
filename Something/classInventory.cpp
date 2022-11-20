#include <string>
#include <time.h>
#include <iostream>
#include <vector>

#include "classInventory.h"
#include "Utility.h"

using namespace std;

//Calling get methods
int classInventory::getWoodAmount() { return woodAmount; }
int classInventory::getStoneAmount() { return stoneAmount; }
int classInventory::getFruitAmount() { return fruitAmount; }
int classInventory::getPeltAmount() { return peltAmount; }
int classInventory::getStringAmount() { return stringAmount; }

int classInventory::getStoneHoeAmount() { return stoneHoeAmount; }
int classInventory::getStonePickaxeAmount() { return stonePickaxeAmount; }
int classInventory::getStoneAxeAmount() { return stoneAxeAmount; }

int classInventory::getWoodenClubAmount() { return woodenClubAmount; }
int classInventory::getStoneSwordAmount() { return stoneSwordAmount; }
int classInventory::getStoneSpearAmount() { return stoneSpearAmount; }

// Calling add methods
void classInventory::addWoodAmount(int value) { woodAmount		+= value; }
void classInventory::addStoneAmount(int value) { stoneAmount	+= value; }
void classInventory::addFruitAmount(int value) { fruitAmount	+= value; }
void classInventory::addPeltAmount(int value) { peltAmount		+= value; }
void classInventory::addStringAmount(int value) { stringAmount	+= value; }

void classInventory::addStoneHoeAmount(int value) { stoneHoeAmount			+= value; }
void classInventory::addStonePickaxeAmount(int value) { stonePickaxeAmount	+= value; }
void classInventory::addStoneAxeAmount(int value) { stoneAxeAmount			+= value; }

void classInventory::addWoodenClubAmount(int value) { woodenClubAmount += value; }
void classInventory::addStoneSwordAmount(int value) { stoneSwordAmount += value; }
void classInventory::addStoneSpearAmount(int value) { stoneSpearAmount += value; }

// Calling sub methods
void classInventory::subWoodAmount(int value) { woodAmount		-= value; }
void classInventory::subStoneAmount(int value) { stoneAmount	-= value; }
void classInventory::subFruitAmount(int value) { fruitAmount	-= value; }
void classInventory::subPeltAmount(int value) { peltAmount		-= value; }
void classInventory::subStringAmount(int value) { stringAmount	-= value; }
		
void classInventory::subStoneHoeAmount(int value) { stoneHoeAmount			-= value; }
void classInventory::subStonePickaxeAmount(int value) { stonePickaxeAmount	+= value; }
void classInventory::subStoneAxeAmount(int value) { stoneAxeAmount			-= value; }

void classInventory::subWoodenClubAmount(int value) { woodenClubAmount -= value; }
void classInventory::subStoneSwordAmount(int value) { stoneSwordAmount -= value; }
void classInventory::subStoneSpearAmount(int value) { stoneSpearAmount -= value; }

//Show resources
void classInventory::showResources() {
	clearScreen();
	cout << "Showing Amount of Resources";

	cout << "\n\nWood: "	<< brightBlueText(woodAmount);
	cout << "\nStone: "		<< brightBlueText(stoneAmount);
	cout << "\nFruit: "		<< brightBlueText(fruitAmount);
	cout << "\nPelt: "		<< brightBlueText(peltAmount);
	cout << "\nString: "	<< brightBlueText(stringAmount) << "\n";
	pauseScreen();
}

//SHow production equipment
void classInventory::showProductionEquipment() {
	clearScreen();
	cout << "Showing Amount of Production Equipment";

	cout << "\n\nStonehoe: "	<< brightBlueText(stoneHoeAmount);
	cout << "\nPickaxe: "		<< brightBlueText(stonePickaxeAmount);
	cout << "\nAxe: "			<< brightBlueText(stoneAxeAmount) << "\n";
	pauseScreen();
}

//Show weapon equipment
void classInventory::showWeaponEquipment() {
	clearScreen();
	cout << "Showing Amount of Weapon Equipment";

	cout << "\n\nWooden Club: "	<< brightBlueText(woodenClubAmount);
	cout << "\nStone Sword: "	<< brightBlueText(stoneSwordAmount);
	cout << "\nStone Spear: "	<< brightBlueText(stoneSpearAmount) << "\n";
	pauseScreen();
}