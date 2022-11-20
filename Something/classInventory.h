#pragma once
#include <string>
#include <time.h>
#include <iostream>
#include <vector>

using namespace std;

class classInventory {
private:
	// Resources
	int woodAmount		= 0;
	int stoneAmount		= 0;
	int fruitAmount		= 0;
	int peltAmount		= 0;
	int stringAmount	= 0;

	// Production Equipment
	int stoneHoeAmount = 0; // +5 efficient farming
	int stonePickaxeAmount = 0; // +5 efficient stonecutting
	int stoneAxeAmount = 0; // +5 efficient woodcutting

	// Weapon Equipment
	int woodenClubAmount = 0; // blunt damage
	int stoneSwordAmount = 0; // cutting damage
	int stoneSpearAmount = 0; // piercing damage

public:
	
	// get methods
	int getWoodAmount();
	int getStoneAmount();
	int getFruitAmount();
	int getPeltAmount();
	int getStringAmount();

	int getStoneHoeAmount();
	int getStonePickaxeAmount();
	int getStoneAxeAmount();

	int getWoodenClubAmount();
	int getStoneSwordAmount();
	int getStoneSpearAmount();

	// add methods
	void addWoodAmount(int value);
	void addStoneAmount(int value);
	void addFruitAmount(int value);
	void addPeltAmount(int value);
	void addStringAmount(int value);

	void addStoneHoeAmount(int value);
	void addStonePickaxeAmount(int value);
	void addStoneAxeAmount(int value);

	void addWoodenClubAmount(int value);
	void addStoneSwordAmount(int value);
	void addStoneSpearAmount(int value);

	// sub methods
	void subWoodAmount(int value);
	void subStoneAmount(int value);
	void subFruitAmount(int value);
	void subPeltAmount(int value);
	void subStringAmount(int value);

	void subStoneHoeAmount(int value);
	void subStonePickaxeAmount(int value);
	void subStoneAxeAmount(int value);

	void subWoodenClubAmount(int value);
	void subStoneSwordAmount(int value);
	void subStoneSpearAmount(int value);

	void showResources();

	void showProductionEquipment();
	
	void showWeaponEquipment();
};
