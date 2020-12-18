#pragma once
#include <vector>

#include "OrderOfShop.h"
#include "Player.h"
#include "Army.h"


void refreshShopSquads(std::vector <std::vector <Army*>>& pullGame, Player*& firstPlayer, std::vector <Army*>& tempShopArmy)
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

	int randomSquadGenerator;
	int randomChanceGenerator;

	srand((unsigned)time(NULL));

	switch (firstPlayer->getPlayerEra())
	{
	case enumEraName::ERA_ANCIENT:

		randomSquadGenerator = rand() % pullGame.at(0).size();
		tempShopArmy.push_back(pullGame.at(0).at(randomSquadGenerator));
		pullGame.at(0).erase(pullGame.at(0).begin() + randomSquadGenerator);

		randomSquadGenerator = rand() % pullGame.at(0).size();
		tempShopArmy.push_back(pullGame.at(0).at(randomSquadGenerator));
		pullGame.at(0).erase(pullGame.at(0).begin() + randomSquadGenerator);

		randomSquadGenerator = rand() % pullGame.at(0).size();
		tempShopArmy.push_back(pullGame.at(0).at(randomSquadGenerator));
		pullGame.at(0).erase(pullGame.at(0).begin() + randomSquadGenerator);

		randomSquadGenerator = rand() % pullGame.at(0).size();
		tempShopArmy.push_back(pullGame.at(0).at(randomSquadGenerator));
		pullGame.at(0).erase(pullGame.at(0).begin() + randomSquadGenerator);

		break;

	case enumEraName::ERA_CLASSIC:

		randomChanceGenerator = rand() % 2;
		randomSquadGenerator = rand() % pullGame.at(randomChanceGenerator).size();
		tempShopArmy.push_back(pullGame.at(randomChanceGenerator).at(randomSquadGenerator));
		pullGame.at(randomChanceGenerator).erase(pullGame.at(randomChanceGenerator).begin() + randomSquadGenerator);

		randomChanceGenerator = rand() % 2;
		randomSquadGenerator = rand() % pullGame.at(randomChanceGenerator).size();
		tempShopArmy.push_back(pullGame.at(randomChanceGenerator).at(randomSquadGenerator));
		pullGame.at(randomChanceGenerator).erase(pullGame.at(randomChanceGenerator).begin() + randomSquadGenerator);

		randomChanceGenerator = rand() % 2;
		randomSquadGenerator = rand() % pullGame.at(randomChanceGenerator).size();
		tempShopArmy.push_back(pullGame.at(randomChanceGenerator).at(randomSquadGenerator));
		pullGame.at(randomChanceGenerator).erase(pullGame.at(randomChanceGenerator).begin() + randomSquadGenerator);

		randomChanceGenerator = rand() % 2;
		randomSquadGenerator = rand() % pullGame.at(randomChanceGenerator).size();
		tempShopArmy.push_back(pullGame.at(randomChanceGenerator).at(randomSquadGenerator));
		pullGame.at(randomChanceGenerator).erase(pullGame.at(randomChanceGenerator).begin() + randomSquadGenerator);

		break;

	case enumEraName::ERA_MEDIVAL:

		randomChanceGenerator = rand() % 4;
		if (randomChanceGenerator == 0)
		{
			randomSquadGenerator = rand() % pullGame.at(0).size();
			tempShopArmy.push_back(pullGame.at(0).at(randomSquadGenerator));
			pullGame.at(0).erase(pullGame.at(0).begin() + randomSquadGenerator);
		}
		else if (randomChanceGenerator == 1)
		{
			randomSquadGenerator = rand() % pullGame.at(1).size();
			tempShopArmy.push_back(pullGame.at(1).at(randomSquadGenerator));
			pullGame.at(1).erase(pullGame.at(1).begin() + randomSquadGenerator);
		}
		else
		{
			randomSquadGenerator = rand() % pullGame.at(2).size();
			tempShopArmy.push_back(pullGame.at(2).at(randomSquadGenerator));
			pullGame.at(2).erase(pullGame.at(2).begin() + randomSquadGenerator);
		}

		randomChanceGenerator = rand() % 4;
		if (randomChanceGenerator == 0)
		{
			randomSquadGenerator = rand() % pullGame.at(0).size();
			tempShopArmy.push_back(pullGame.at(0).at(randomSquadGenerator));
			pullGame.at(0).erase(pullGame.at(0).begin() + randomSquadGenerator);
		}
		else if (randomChanceGenerator == 1)
		{
			randomSquadGenerator = rand() % pullGame.at(1).size();
			tempShopArmy.push_back(pullGame.at(1).at(randomSquadGenerator));
			pullGame.at(1).erase(pullGame.at(1).begin() + randomSquadGenerator);
		}
		else
		{
			randomSquadGenerator = rand() % pullGame.at(2).size();
			tempShopArmy.push_back(pullGame.at(2).at(randomSquadGenerator));
			pullGame.at(2).erase(pullGame.at(2).begin() + randomSquadGenerator);
		}

		randomChanceGenerator = rand() % 4;
		if (randomChanceGenerator == 0)
		{
			randomSquadGenerator = rand() % pullGame.at(0).size();
			tempShopArmy.push_back(pullGame.at(0).at(randomSquadGenerator));
			pullGame.at(0).erase(pullGame.at(0).begin() + randomSquadGenerator);
		}
		else if (randomChanceGenerator == 1)
		{
			randomSquadGenerator = rand() % pullGame.at(1).size();
			tempShopArmy.push_back(pullGame.at(1).at(randomSquadGenerator));
			pullGame.at(1).erase(pullGame.at(1).begin() + randomSquadGenerator);
		}
		else
		{
			randomSquadGenerator = rand() % pullGame.at(2).size();
			tempShopArmy.push_back(pullGame.at(2).at(randomSquadGenerator));
			pullGame.at(2).erase(pullGame.at(2).begin() + randomSquadGenerator);
		}

		randomChanceGenerator = rand() % 4;
		if (randomChanceGenerator == 0)
		{
			randomSquadGenerator = rand() % pullGame.at(0).size();
			tempShopArmy.push_back(pullGame.at(0).at(randomSquadGenerator));
			pullGame.at(0).erase(pullGame.at(0).begin() + randomSquadGenerator);
		}
		else if (randomChanceGenerator == 1)
		{
			randomSquadGenerator = rand() % pullGame.at(1).size();
			tempShopArmy.push_back(pullGame.at(1).at(randomSquadGenerator));
			pullGame.at(1).erase(pullGame.at(1).begin() + randomSquadGenerator);
		}
		else
		{
			randomSquadGenerator = rand() % pullGame.at(2).size();
			tempShopArmy.push_back(pullGame.at(2).at(randomSquadGenerator));
			pullGame.at(2).erase(pullGame.at(2).begin() + randomSquadGenerator);
		}

		break;

	case enumEraName::ERA_RENAISSANCEE:

		randomChanceGenerator = rand() % 4;
		if (randomChanceGenerator == 0)
		{
			randomSquadGenerator = rand() % pullGame.at(1).size();
			tempShopArmy.push_back(pullGame.at(1).at(randomSquadGenerator));
			pullGame.at(1).erase(pullGame.at(1).begin() + randomSquadGenerator);
		}
		else if (randomChanceGenerator == 1)
		{
			randomSquadGenerator = rand() % pullGame.at(2).size();
			tempShopArmy.push_back(pullGame.at(2).at(randomSquadGenerator));
			pullGame.at(2).erase(pullGame.at(2).begin() + randomSquadGenerator);
		}
		else
		{
			randomSquadGenerator = rand() % pullGame.at(3).size();
			tempShopArmy.push_back(pullGame.at(3).at(randomSquadGenerator));
			pullGame.at(3).erase(pullGame.at(3).begin() + randomSquadGenerator);
		}

		randomChanceGenerator = rand() % 4;
		if (randomChanceGenerator == 0)
		{
			randomSquadGenerator = rand() % pullGame.at(1).size();
			tempShopArmy.push_back(pullGame.at(1).at(randomSquadGenerator));
			pullGame.at(1).erase(pullGame.at(1).begin() + randomSquadGenerator);
		}
		else if (randomChanceGenerator == 1)
		{
			randomSquadGenerator = rand() % pullGame.at(2).size();
			tempShopArmy.push_back(pullGame.at(2).at(randomSquadGenerator));
			pullGame.at(2).erase(pullGame.at(2).begin() + randomSquadGenerator);
		}
		else
		{
			randomSquadGenerator = rand() % pullGame.at(3).size();
			tempShopArmy.push_back(pullGame.at(3).at(randomSquadGenerator));
			pullGame.at(3).erase(pullGame.at(3).begin() + randomSquadGenerator);
		}

		randomChanceGenerator = rand() % 4;
		if (randomChanceGenerator == 0)
		{
			randomSquadGenerator = rand() % pullGame.at(1).size();
			tempShopArmy.push_back(pullGame.at(1).at(randomSquadGenerator));
			pullGame.at(1).erase(pullGame.at(1).begin() + randomSquadGenerator);
		}
		else if (randomChanceGenerator == 1)
		{
			randomSquadGenerator = rand() % pullGame.at(2).size();
			tempShopArmy.push_back(pullGame.at(2).at(randomSquadGenerator));
			pullGame.at(2).erase(pullGame.at(2).begin() + randomSquadGenerator);
		}
		else
		{
			randomSquadGenerator = rand() % pullGame.at(3).size();
			tempShopArmy.push_back(pullGame.at(3).at(randomSquadGenerator));
			pullGame.at(3).erase(pullGame.at(3).begin() + randomSquadGenerator);
		}

		randomChanceGenerator = rand() % 4;
		if (randomChanceGenerator == 0)
		{
			randomSquadGenerator = rand() % pullGame.at(1).size();
			tempShopArmy.push_back(pullGame.at(1).at(randomSquadGenerator));
			pullGame.at(1).erase(pullGame.at(1).begin() + randomSquadGenerator);
		}
		else if (randomChanceGenerator == 1)
		{
			randomSquadGenerator = rand() % pullGame.at(2).size();
			tempShopArmy.push_back(pullGame.at(2).at(randomSquadGenerator));
			pullGame.at(2).erase(pullGame.at(2).begin() + randomSquadGenerator);
		}
		else
		{
			randomSquadGenerator = rand() % pullGame.at(3).size();
			tempShopArmy.push_back(pullGame.at(3).at(randomSquadGenerator));
			pullGame.at(3).erase(pullGame.at(3).begin() + randomSquadGenerator);
		}

		break;

	case enumEraName::ERA_INDUSTRIAL:

		randomChanceGenerator = rand() % 4;
		if (randomChanceGenerator == 0)
		{
			randomSquadGenerator = rand() % pullGame.at(2).size();
			tempShopArmy.push_back(pullGame.at(2).at(randomSquadGenerator));
			pullGame.at(2).erase(pullGame.at(2).begin() + randomSquadGenerator);
		}
		else if (randomChanceGenerator == 1)
		{
			randomSquadGenerator = rand() % pullGame.at(3).size();
			tempShopArmy.push_back(pullGame.at(3).at(randomSquadGenerator));
			pullGame.at(3).erase(pullGame.at(3).begin() + randomSquadGenerator);
		}
		else
		{
			randomSquadGenerator = rand() % pullGame.at(4).size();
			tempShopArmy.push_back(pullGame.at(4).at(randomSquadGenerator));
			pullGame.at(4).erase(pullGame.at(4).begin() + randomSquadGenerator);
		}

		randomChanceGenerator = rand() % 4;
		if (randomChanceGenerator == 0)
		{
			randomSquadGenerator = rand() % pullGame.at(2).size();
			tempShopArmy.push_back(pullGame.at(2).at(randomSquadGenerator));
			pullGame.at(2).erase(pullGame.at(2).begin() + randomSquadGenerator);
		}
		else if (randomChanceGenerator == 1)
		{
			randomSquadGenerator = rand() % pullGame.at(3).size();
			tempShopArmy.push_back(pullGame.at(3).at(randomSquadGenerator));
			pullGame.at(3).erase(pullGame.at(3).begin() + randomSquadGenerator);
		}
		else
		{
			randomSquadGenerator = rand() % pullGame.at(4).size();
			tempShopArmy.push_back(pullGame.at(4).at(randomSquadGenerator));
			pullGame.at(4).erase(pullGame.at(4).begin() + randomSquadGenerator);
		}

		randomChanceGenerator = rand() % 4;
		if (randomChanceGenerator == 0)
		{
			randomSquadGenerator = rand() % pullGame.at(2).size();
			tempShopArmy.push_back(pullGame.at(2).at(randomSquadGenerator));
			pullGame.at(2).erase(pullGame.at(2).begin() + randomSquadGenerator);
		}
		else if (randomChanceGenerator == 1)
		{
			randomSquadGenerator = rand() % pullGame.at(3).size();
			tempShopArmy.push_back(pullGame.at(3).at(randomSquadGenerator));
			pullGame.at(3).erase(pullGame.at(3).begin() + randomSquadGenerator);
		}
		else
		{
			randomSquadGenerator = rand() % pullGame.at(4).size();
			tempShopArmy.push_back(pullGame.at(4).at(randomSquadGenerator));
			pullGame.at(4).erase(pullGame.at(4).begin() + randomSquadGenerator);
		}

		randomChanceGenerator = rand() % 4;
		if (randomChanceGenerator == 0)
		{
			randomSquadGenerator = rand() % pullGame.at(2).size();
			tempShopArmy.push_back(pullGame.at(2).at(randomSquadGenerator));
			pullGame.at(2).erase(pullGame.at(2).begin() + randomSquadGenerator);
		}
		else if (randomChanceGenerator == 1)
		{
			randomSquadGenerator = rand() % pullGame.at(3).size();
			tempShopArmy.push_back(pullGame.at(3).at(randomSquadGenerator));
			pullGame.at(3).erase(pullGame.at(3).begin() + randomSquadGenerator);
		}
		else
		{
			randomSquadGenerator = rand() % pullGame.at(4).size();
			tempShopArmy.push_back(pullGame.at(4).at(randomSquadGenerator));
			pullGame.at(4).erase(pullGame.at(4).begin() + randomSquadGenerator);
		}

		break;

	case enumEraName::ERA_MODERN:

		randomChanceGenerator = rand() % 4;
		if (randomChanceGenerator == 0)
		{
			randomSquadGenerator = rand() % pullGame.at(3).size();
			tempShopArmy.push_back(pullGame.at(3).at(randomSquadGenerator));
			pullGame.at(3).erase(pullGame.at(3).begin() + randomSquadGenerator);
		}
		else if (randomChanceGenerator == 1)
		{
			randomSquadGenerator = rand() % pullGame.at(4).size();
			tempShopArmy.push_back(pullGame.at(4).at(randomSquadGenerator));
			pullGame.at(4).erase(pullGame.at(4).begin() + randomSquadGenerator);
		}
		else
		{
			randomSquadGenerator = rand() % pullGame.at(5).size();
			tempShopArmy.push_back(pullGame.at(5).at(randomSquadGenerator));
			pullGame.at(5).erase(pullGame.at(5).begin() + randomSquadGenerator);
		}

		randomChanceGenerator = rand() % 4;
		if (randomChanceGenerator == 0)
		{
			randomSquadGenerator = rand() % pullGame.at(3).size();
			tempShopArmy.push_back(pullGame.at(3).at(randomSquadGenerator));
			pullGame.at(3).erase(pullGame.at(3).begin() + randomSquadGenerator);
		}
		else if (randomChanceGenerator == 1)
		{
			randomSquadGenerator = rand() % pullGame.at(4).size();
			tempShopArmy.push_back(pullGame.at(4).at(randomSquadGenerator));
			pullGame.at(4).erase(pullGame.at(4).begin() + randomSquadGenerator);
		}
		else
		{
			randomSquadGenerator = rand() % pullGame.at(5).size();
			tempShopArmy.push_back(pullGame.at(5).at(randomSquadGenerator));
			pullGame.at(5).erase(pullGame.at(5).begin() + randomSquadGenerator);
		}

		randomChanceGenerator = rand() % 4;
		if (randomChanceGenerator == 0)
		{
			randomSquadGenerator = rand() % pullGame.at(3).size();
			tempShopArmy.push_back(pullGame.at(3).at(randomSquadGenerator));
			pullGame.at(3).erase(pullGame.at(3).begin() + randomSquadGenerator);
		}
		else if (randomChanceGenerator == 1)
		{
			randomSquadGenerator = rand() % pullGame.at(4).size();
			tempShopArmy.push_back(pullGame.at(4).at(randomSquadGenerator));
			pullGame.at(4).erase(pullGame.at(4).begin() + randomSquadGenerator);
		}
		else
		{
			randomSquadGenerator = rand() % pullGame.at(5).size();
			tempShopArmy.push_back(pullGame.at(5).at(randomSquadGenerator));
			pullGame.at(5).erase(pullGame.at(5).begin() + randomSquadGenerator);
		}

		randomChanceGenerator = rand() % 4;
		if (randomChanceGenerator == 0)
		{
			randomSquadGenerator = rand() % pullGame.at(3).size();
			tempShopArmy.push_back(pullGame.at(3).at(randomSquadGenerator));
			pullGame.at(3).erase(pullGame.at(3).begin() + randomSquadGenerator);
		}
		else if (randomChanceGenerator == 1)
		{
			randomSquadGenerator = rand() % pullGame.at(4).size();
			tempShopArmy.push_back(pullGame.at(4).at(randomSquadGenerator));
			pullGame.at(4).erase(pullGame.at(4).begin() + randomSquadGenerator);
		}
		else
		{
			randomSquadGenerator = rand() % pullGame.at(5).size();
			tempShopArmy.push_back(pullGame.at(5).at(randomSquadGenerator));
			pullGame.at(5).erase(pullGame.at(5).begin() + randomSquadGenerator);
		}

		break;

	case enumEraName::ERA_ATOMIC:

		randomChanceGenerator = rand() % 4;
		if (randomChanceGenerator == 0)
		{
			randomSquadGenerator = rand() % pullGame.at(4).size();
			tempShopArmy.push_back(pullGame.at(4).at(randomSquadGenerator));
			pullGame.at(4).erase(pullGame.at(4).begin() + randomSquadGenerator);
		}
		else if (randomChanceGenerator == 1)
		{
			randomSquadGenerator = rand() % pullGame.at(5).size();
			tempShopArmy.push_back(pullGame.at(5).at(randomSquadGenerator));
			pullGame.at(5).erase(pullGame.at(5).begin() + randomSquadGenerator);
		}
		else
		{
			randomSquadGenerator = rand() % pullGame.at(6).size();
			tempShopArmy.push_back(pullGame.at(6).at(randomSquadGenerator));
			pullGame.at(6).erase(pullGame.at(6).begin() + randomSquadGenerator);
		}

		randomChanceGenerator = rand() % 4;
		if (randomChanceGenerator == 0)
		{
			randomSquadGenerator = rand() % pullGame.at(4).size();
			tempShopArmy.push_back(pullGame.at(4).at(randomSquadGenerator));
			pullGame.at(4).erase(pullGame.at(4).begin() + randomSquadGenerator);
		}
		else if (randomChanceGenerator == 1)
		{
			randomSquadGenerator = rand() % pullGame.at(5).size();
			tempShopArmy.push_back(pullGame.at(5).at(randomSquadGenerator));
			pullGame.at(5).erase(pullGame.at(5).begin() + randomSquadGenerator);
		}
		else
		{
			randomSquadGenerator = rand() % pullGame.at(6).size();
			tempShopArmy.push_back(pullGame.at(6).at(randomSquadGenerator));
			pullGame.at(6).erase(pullGame.at(6).begin() + randomSquadGenerator);
		}

		randomChanceGenerator = rand() % 4;
		if (randomChanceGenerator == 0)
		{
			randomSquadGenerator = rand() % pullGame.at(4).size();
			tempShopArmy.push_back(pullGame.at(4).at(randomSquadGenerator));
			pullGame.at(4).erase(pullGame.at(4).begin() + randomSquadGenerator);
		}
		else if (randomChanceGenerator == 1)
		{
			randomSquadGenerator = rand() % pullGame.at(5).size();
			tempShopArmy.push_back(pullGame.at(5).at(randomSquadGenerator));
			pullGame.at(5).erase(pullGame.at(5).begin() + randomSquadGenerator);
		}
		else
		{
			randomSquadGenerator = rand() % pullGame.at(6).size();
			tempShopArmy.push_back(pullGame.at(6).at(randomSquadGenerator));
			pullGame.at(6).erase(pullGame.at(6).begin() + randomSquadGenerator);
		}

		randomChanceGenerator = rand() % 4;
		if (randomChanceGenerator == 0)
		{
			randomSquadGenerator = rand() % pullGame.at(4).size();
			tempShopArmy.push_back(pullGame.at(4).at(randomSquadGenerator));
			pullGame.at(4).erase(pullGame.at(4).begin() + randomSquadGenerator);
		}
		else if (randomChanceGenerator == 1)
		{
			randomSquadGenerator = rand() % pullGame.at(5).size();
			tempShopArmy.push_back(pullGame.at(5).at(randomSquadGenerator));
			pullGame.at(5).erase(pullGame.at(5).begin() + randomSquadGenerator);
		}
		else
		{
			randomSquadGenerator = rand() % pullGame.at(6).size();
			tempShopArmy.push_back(pullGame.at(6).at(randomSquadGenerator));
			pullGame.at(6).erase(pullGame.at(6).begin() + randomSquadGenerator);
		}

		break;

	case enumEraName::ERA_INFORMATION:

		randomChanceGenerator = rand() % 4;
		if (randomChanceGenerator == 0)
		{
			randomSquadGenerator = rand() % pullGame.at(5).size();
			tempShopArmy.push_back(pullGame.at(5).at(randomSquadGenerator));
			pullGame.at(5).erase(pullGame.at(5).begin() + randomSquadGenerator);
		}
		else if (randomChanceGenerator == 1)
		{
			randomSquadGenerator = rand() % pullGame.at(6).size();
			tempShopArmy.push_back(pullGame.at(6).at(randomSquadGenerator));
			pullGame.at(6).erase(pullGame.at(6).begin() + randomSquadGenerator);
		}
		else
		{
			randomSquadGenerator = rand() % pullGame.at(7).size();
			tempShopArmy.push_back(pullGame.at(7).at(randomSquadGenerator));
			pullGame.at(7).erase(pullGame.at(7).begin() + randomSquadGenerator);
		}

		randomChanceGenerator = rand() % 4;
		if (randomChanceGenerator == 0)
		{
			randomSquadGenerator = rand() % pullGame.at(5).size();
			tempShopArmy.push_back(pullGame.at(5).at(randomSquadGenerator));
			pullGame.at(5).erase(pullGame.at(5).begin() + randomSquadGenerator);
		}
		else if (randomChanceGenerator == 1)
		{
			randomSquadGenerator = rand() % pullGame.at(6).size();
			tempShopArmy.push_back(pullGame.at(6).at(randomSquadGenerator));
			pullGame.at(6).erase(pullGame.at(6).begin() + randomSquadGenerator);
		}
		else
		{
			randomSquadGenerator = rand() % pullGame.at(7).size();
			tempShopArmy.push_back(pullGame.at(7).at(randomSquadGenerator));
			pullGame.at(7).erase(pullGame.at(7).begin() + randomSquadGenerator);
		}

		randomChanceGenerator = rand() % 4;
		if (randomChanceGenerator == 0)
		{
			randomSquadGenerator = rand() % pullGame.at(5).size();
			tempShopArmy.push_back(pullGame.at(5).at(randomSquadGenerator));
			pullGame.at(5).erase(pullGame.at(5).begin() + randomSquadGenerator);
		}
		else if (randomChanceGenerator == 1)
		{
			randomSquadGenerator = rand() % pullGame.at(6).size();
			tempShopArmy.push_back(pullGame.at(6).at(randomSquadGenerator));
			pullGame.at(6).erase(pullGame.at(6).begin() + randomSquadGenerator);
		}
		else
		{
			randomSquadGenerator = rand() % pullGame.at(7).size();
			tempShopArmy.push_back(pullGame.at(7).at(randomSquadGenerator));
			pullGame.at(7).erase(pullGame.at(7).begin() + randomSquadGenerator);
		}

		randomChanceGenerator = rand() % 4;
		if (randomChanceGenerator == 0)
		{
			randomSquadGenerator = rand() % pullGame.at(5).size();
			tempShopArmy.push_back(pullGame.at(5).at(randomSquadGenerator));
			pullGame.at(5).erase(pullGame.at(5).begin() + randomSquadGenerator);
		}
		else if (randomChanceGenerator == 1)
		{
			randomSquadGenerator = rand() % pullGame.at(6).size();
			tempShopArmy.push_back(pullGame.at(6).at(randomSquadGenerator));
			pullGame.at(6).erase(pullGame.at(6).begin() + randomSquadGenerator);
		}
		else
		{
			randomSquadGenerator = rand() % pullGame.at(7).size();
			tempShopArmy.push_back(pullGame.at(7).at(randomSquadGenerator));
			pullGame.at(7).erase(pullGame.at(7).begin() + randomSquadGenerator);
		}

		break;

	case enumEraName::ERA_FUTURE:

		randomChanceGenerator = rand() % 5;
		if (randomChanceGenerator != 0)
		{
			randomSquadGenerator = rand() % pullGame.at(7).size();
			tempShopArmy.push_back(pullGame.at(7).at(randomSquadGenerator));
			pullGame.at(7).erase(pullGame.at(7).begin() + randomSquadGenerator);
		}
		else
		{
			randomSquadGenerator = rand() % pullGame.at(8).size();
			tempShopArmy.push_back(pullGame.at(8).at(randomSquadGenerator));
			pullGame.at(8).erase(pullGame.at(8).begin() + randomSquadGenerator);
		}

		randomChanceGenerator = rand() % 5;
		if (randomChanceGenerator != 0)
		{
			randomSquadGenerator = rand() % pullGame.at(7).size();
			tempShopArmy.push_back(pullGame.at(7).at(randomSquadGenerator));
			pullGame.at(7).erase(pullGame.at(7).begin() + randomSquadGenerator);
		}
		else
		{
			randomSquadGenerator = rand() % pullGame.at(8).size();
			tempShopArmy.push_back(pullGame.at(8).at(randomSquadGenerator));
			pullGame.at(8).erase(pullGame.at(8).begin() + randomSquadGenerator);
		}

		randomChanceGenerator = rand() % 5;
		if (randomChanceGenerator != 0)
		{
			randomSquadGenerator = rand() % pullGame.at(7).size();
			tempShopArmy.push_back(pullGame.at(7).at(randomSquadGenerator));
			pullGame.at(7).erase(pullGame.at(7).begin() + randomSquadGenerator);
		}
		else
		{
			randomSquadGenerator = rand() % pullGame.at(8).size();
			tempShopArmy.push_back(pullGame.at(8).at(randomSquadGenerator));
			pullGame.at(8).erase(pullGame.at(8).begin() + randomSquadGenerator);
		}

		randomChanceGenerator = rand() % 5;
		if (randomChanceGenerator != 0)
		{
			randomSquadGenerator = rand() % pullGame.at(7).size();
			tempShopArmy.push_back(pullGame.at(7).at(randomSquadGenerator));
			pullGame.at(7).erase(pullGame.at(7).begin() + randomSquadGenerator);
		}
		else
		{
			randomSquadGenerator = rand() % pullGame.at(8).size();
			tempShopArmy.push_back(pullGame.at(8).at(randomSquadGenerator));
			pullGame.at(8).erase(pullGame.at(8).begin() + randomSquadGenerator);
		}

		break;

	default:
		break;
	}

	setOrderOfShopArmy(tempShopArmy);
}