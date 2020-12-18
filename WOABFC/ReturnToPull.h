#pragma once
#include <vector>

#include "Army.h"
#include "Player.h"

void returnAllPlayerSquadsToGeneralPull(std::vector <std::vector <Army*>>& pullGame, Player*& firstPlayer)
{
	for (int i = 0; i < (int)firstPlayer->getPlayerActiveArmy().size(); i++)
	{
		switch (firstPlayer->getPlayerActiveArmy().at(i)->getEraName())
		{
		case enumEraName::ERA_ANCIENT:
			pullGame.at(0).push_back(firstPlayer->getPlayerActiveArmy().at(i)); break;
		case enumEraName::ERA_CLASSIC:
			pullGame.at(1).push_back(firstPlayer->getPlayerActiveArmy().at(i)); break;
		case enumEraName::ERA_MEDIVAL:
			pullGame.at(2).push_back(firstPlayer->getPlayerActiveArmy().at(i)); break;
		case enumEraName::ERA_RENAISSANCEE:
			pullGame.at(3).push_back(firstPlayer->getPlayerActiveArmy().at(i)); break;
		case enumEraName::ERA_INDUSTRIAL:
			pullGame.at(4).push_back(firstPlayer->getPlayerActiveArmy().at(i)); break;
		case enumEraName::ERA_MODERN:
			pullGame.at(5).push_back(firstPlayer->getPlayerActiveArmy().at(i)); break;
		case enumEraName::ERA_ATOMIC:
			pullGame.at(6).push_back(firstPlayer->getPlayerActiveArmy().at(i)); break;
		case enumEraName::ERA_INFORMATION:
			pullGame.at(7).push_back(firstPlayer->getPlayerActiveArmy().at(i)); break;
		case enumEraName::ERA_FUTURE:
			pullGame.at(8).push_back(firstPlayer->getPlayerActiveArmy().at(i)); break;
		default:
			break;
		}
	}

	firstPlayer->getPlayerActiveArmy().clear();

	for (int i = 0; i < (int)firstPlayer->getPlayerReserveArmy().size(); i++)
	{
		switch (firstPlayer->getPlayerReserveArmy().at(i)->getEraName())
		{
		case enumEraName::ERA_ANCIENT:
			pullGame.at(0).push_back(firstPlayer->getPlayerReserveArmy().at(i)); break;
		case enumEraName::ERA_CLASSIC:
			pullGame.at(1).push_back(firstPlayer->getPlayerReserveArmy().at(i)); break;
		case enumEraName::ERA_MEDIVAL:
			pullGame.at(2).push_back(firstPlayer->getPlayerReserveArmy().at(i)); break;
		case enumEraName::ERA_RENAISSANCEE:
			pullGame.at(3).push_back(firstPlayer->getPlayerReserveArmy().at(i)); break;
		case enumEraName::ERA_INDUSTRIAL:
			pullGame.at(4).push_back(firstPlayer->getPlayerReserveArmy().at(i)); break;
		case enumEraName::ERA_MODERN:
			pullGame.at(5).push_back(firstPlayer->getPlayerReserveArmy().at(i)); break;
		case enumEraName::ERA_ATOMIC:
			pullGame.at(6).push_back(firstPlayer->getPlayerReserveArmy().at(i)); break;
		case enumEraName::ERA_INFORMATION:
			pullGame.at(7).push_back(firstPlayer->getPlayerReserveArmy().at(i)); break;
		case enumEraName::ERA_FUTURE:
			pullGame.at(8).push_back(firstPlayer->getPlayerReserveArmy().at(i)); break;
		default:
			break;
		}
	}

	firstPlayer->getPlayerReserveArmy().clear();
}

void returnAllShopSquadsToGeneralPull(std::vector <std::vector <Army*>>& pullGame, std::vector <Army*>& tempShopArmy)
{
	for (int i = 0; i < (int)tempShopArmy.size(); i++)
	{
		switch (tempShopArmy.at(i)->getEraName())
		{
		case enumEraName::ERA_ANCIENT:
			pullGame.at(0).push_back(tempShopArmy.at(i)); break;
		case enumEraName::ERA_CLASSIC:
			pullGame.at(1).push_back(tempShopArmy.at(i)); break;
		case enumEraName::ERA_MEDIVAL:
			pullGame.at(2).push_back(tempShopArmy.at(i)); break;
		case enumEraName::ERA_RENAISSANCEE:
			pullGame.at(3).push_back(tempShopArmy.at(i)); break;
		case enumEraName::ERA_INDUSTRIAL:
			pullGame.at(4).push_back(tempShopArmy.at(i)); break;
		case enumEraName::ERA_MODERN:
			pullGame.at(5).push_back(tempShopArmy.at(i)); break;
		case enumEraName::ERA_ATOMIC:
			pullGame.at(6).push_back(tempShopArmy.at(i)); break;
		case enumEraName::ERA_INFORMATION:
			pullGame.at(7).push_back(tempShopArmy.at(i)); break;
		case enumEraName::ERA_FUTURE:
			pullGame.at(8).push_back(tempShopArmy.at(i)); break;
		default:
			break;
		}
	}

	tempShopArmy.clear();
}