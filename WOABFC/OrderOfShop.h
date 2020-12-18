#pragma once
#include <vector>

#include "Army.h"

void setOrderOfShopArmy(std::vector <Army*> tempShopArmy)
{
	switch (tempShopArmy.size())
	{
	case 1:
		tempShopArmy.at(0)->setArmySpawnCoordinates(860.0, 80.0);
		break;
	case 2:
		tempShopArmy.at(0)->setArmySpawnCoordinates(760.0, 80.0);
		tempShopArmy.at(1)->setArmySpawnCoordinates(960.0, 80.0);
		break;
	case 3:
		tempShopArmy.at(0)->setArmySpawnCoordinates(660.0, 80.0);
		tempShopArmy.at(1)->setArmySpawnCoordinates(860.0, 80.0);
		tempShopArmy.at(2)->setArmySpawnCoordinates(1060.0, 80.0);
		break;
	case 4:
		tempShopArmy.at(0)->setArmySpawnCoordinates(560.0, 80.0);
		tempShopArmy.at(1)->setArmySpawnCoordinates(760.0, 80.0);
		tempShopArmy.at(2)->setArmySpawnCoordinates(960.0, 80.0);
		tempShopArmy.at(3)->setArmySpawnCoordinates(1160.0, 80.0);
		break;
	default:
		break;
	}
}