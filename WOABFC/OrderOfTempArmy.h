#pragma once
#include "Army.h"

#include <vector>

void setOrderOfTempBattleArmy(std::vector <Army*> tempBattleArmy, int numberOfPlayer)
{
	if (numberOfPlayer == 0)
	{
		switch (tempBattleArmy.size())
		{
		case 1:
			tempBattleArmy.at(0)->setArmySpawnCoordinates(860.0, 800.0);
			break;
		case 2:
			tempBattleArmy.at(0)->setArmySpawnCoordinates(760.0, 800.0);
			tempBattleArmy.at(1)->setArmySpawnCoordinates(960.0, 800.0);
			break;
		case 3:
			tempBattleArmy.at(0)->setArmySpawnCoordinates(660.0, 800.0);
			tempBattleArmy.at(1)->setArmySpawnCoordinates(860.0, 800.0);
			tempBattleArmy.at(2)->setArmySpawnCoordinates(1060.0, 800.0);
			break;
		case 4:
			tempBattleArmy.at(0)->setArmySpawnCoordinates(560.0, 800.0);
			tempBattleArmy.at(1)->setArmySpawnCoordinates(760.0, 800.0);
			tempBattleArmy.at(2)->setArmySpawnCoordinates(960.0, 800.0);
			tempBattleArmy.at(3)->setArmySpawnCoordinates(1160.0, 800.0);
			break;
		case 5:
			tempBattleArmy.at(0)->setArmySpawnCoordinates(460.0, 800.0);
			tempBattleArmy.at(1)->setArmySpawnCoordinates(660.0, 800.0);
			tempBattleArmy.at(2)->setArmySpawnCoordinates(860.0, 800.0);
			tempBattleArmy.at(3)->setArmySpawnCoordinates(1060.0, 800.0);
			tempBattleArmy.at(4)->setArmySpawnCoordinates(1260.0, 800.0);
			break;
		case 6:
			tempBattleArmy.at(0)->setArmySpawnCoordinates(360.0, 800.0);
			tempBattleArmy.at(1)->setArmySpawnCoordinates(560.0, 800.0);
			tempBattleArmy.at(2)->setArmySpawnCoordinates(760.0, 800.0);
			tempBattleArmy.at(3)->setArmySpawnCoordinates(960.0, 800.0);
			tempBattleArmy.at(4)->setArmySpawnCoordinates(1160.0, 800.0);
			tempBattleArmy.at(5)->setArmySpawnCoordinates(1360.0, 800.0);
			break;
		case 7:
			tempBattleArmy.at(0)->setArmySpawnCoordinates(260.0, 800.0);
			tempBattleArmy.at(1)->setArmySpawnCoordinates(460.0, 800.0);
			tempBattleArmy.at(2)->setArmySpawnCoordinates(660.0, 800.0);
			tempBattleArmy.at(3)->setArmySpawnCoordinates(860.0, 800.0);
			tempBattleArmy.at(4)->setArmySpawnCoordinates(1060.0, 800.0);
			tempBattleArmy.at(5)->setArmySpawnCoordinates(1260.0, 800.0);
			tempBattleArmy.at(6)->setArmySpawnCoordinates(1460.0, 800.0);
			break;
		default:
			break;
		}
	}
	else
	{
		switch (tempBattleArmy.size())
		{
		case 1:
			tempBattleArmy.at(0)->setArmySpawnCoordinates(860.0, 80.0);
			break;
		case 2:
			tempBattleArmy.at(0)->setArmySpawnCoordinates(760.0, 80.0);
			tempBattleArmy.at(1)->setArmySpawnCoordinates(960.0, 80.0);
			break;
		case 3:
			tempBattleArmy.at(0)->setArmySpawnCoordinates(660.0, 80.0);
			tempBattleArmy.at(1)->setArmySpawnCoordinates(860.0, 80.0);
			tempBattleArmy.at(2)->setArmySpawnCoordinates(1060.0, 80.0);
			break;
		case 4:
			tempBattleArmy.at(0)->setArmySpawnCoordinates(560.0, 80.0);
			tempBattleArmy.at(1)->setArmySpawnCoordinates(760.0, 80.0);
			tempBattleArmy.at(2)->setArmySpawnCoordinates(960.0, 80.0);
			tempBattleArmy.at(3)->setArmySpawnCoordinates(1160.0, 80.0);
			break;
		case 5:
			tempBattleArmy.at(0)->setArmySpawnCoordinates(460.0, 80.0);
			tempBattleArmy.at(1)->setArmySpawnCoordinates(660.0, 80.0);
			tempBattleArmy.at(2)->setArmySpawnCoordinates(860.0, 80.0);
			tempBattleArmy.at(3)->setArmySpawnCoordinates(1060.0, 80.0);
			tempBattleArmy.at(4)->setArmySpawnCoordinates(1260.0, 80.0);
			break;
		case 6:
			tempBattleArmy.at(0)->setArmySpawnCoordinates(360.0, 80.0);
			tempBattleArmy.at(1)->setArmySpawnCoordinates(560.0, 80.0);
			tempBattleArmy.at(2)->setArmySpawnCoordinates(760.0, 80.0);
			tempBattleArmy.at(3)->setArmySpawnCoordinates(960.0, 80.0);
			tempBattleArmy.at(4)->setArmySpawnCoordinates(1160.0, 80.0);
			tempBattleArmy.at(5)->setArmySpawnCoordinates(1360.0, 80.0);
			break;
		case 7:
			tempBattleArmy.at(0)->setArmySpawnCoordinates(260.0, 80.0);
			tempBattleArmy.at(1)->setArmySpawnCoordinates(460.0, 80.0);
			tempBattleArmy.at(2)->setArmySpawnCoordinates(660.0, 80.0);
			tempBattleArmy.at(3)->setArmySpawnCoordinates(860.0, 80.0);
			tempBattleArmy.at(4)->setArmySpawnCoordinates(1060.0, 80.0);
			tempBattleArmy.at(5)->setArmySpawnCoordinates(1260.0, 80.0);
			tempBattleArmy.at(6)->setArmySpawnCoordinates(1460.0, 80.0);
			break;
		default:
			break;
		}
	}
}