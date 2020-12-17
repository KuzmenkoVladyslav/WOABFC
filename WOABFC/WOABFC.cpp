#include <SFML/Graphics.hpp>

#include <iostream> 
#include <vector>
#include <thread>
#include <sstream>
#include <time.h>
#include <Windows.h>

#include "Army.h"
#include "Squad.h"
#include "map.h"
#include "Player.h"
#include "Menu.h"
#include "Strings.h"
#include "TextStringHelpers.h"

void gameProcess(std::vector <std::vector <Army*>>& pullGame);

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

std::vector <std::vector <Army*>> initializePullSquads()
{
	bool windowClose = false;
	
	std::thread threadLoading([&windowClose]()
	{		
		sf::RenderWindow window(sf::VideoMode(1920, 1080), "War of Ages: Battle for Castle (LOADING)", sf::Style::Fullscreen);
		int randomNumberBackground;
		srand((unsigned)time(NULL));
		randomNumberBackground = rand() % 10;
		sf::Texture menuBackgroundTexture;
		menuBackgroundTexture.loadFromFile("images/map.png");
		sf::Sprite menuBackgroundSprite(menuBackgroundTexture);

		int nowSpriteDrawing = 1;
		sf::Texture loagindTexture1, loagindTexture2, loagindTexture3, loagindTexture4, loagindTexture5, loagindTexture6, loagindTexture7, loagindTexture8;
		loagindTexture1.loadFromFile("images/loading/1.png");
		loagindTexture2.loadFromFile("images/loading/2.png");
		loagindTexture3.loadFromFile("images/loading/3.png");
		loagindTexture4.loadFromFile("images/loading/4.png");
		loagindTexture5.loadFromFile("images/loading/5.png");
		loagindTexture6.loadFromFile("images/loading/6.png");
		loagindTexture7.loadFromFile("images/loading/7.png");
		loagindTexture8.loadFromFile("images/loading/8.png");

		sf::Sprite loagindSprite1, loagindSprite2, loagindSprite3, loagindSprite4, loagindSprite5, loagindSprite6, loagindSprite7, loagindSprite8;
		loagindSprite1.setTexture(loagindTexture1);
		loagindSprite2.setTexture(loagindTexture2);
		loagindSprite3.setTexture(loagindTexture3);
		loagindSprite4.setTexture(loagindTexture4);
		loagindSprite5.setTexture(loagindTexture5);
		loagindSprite6.setTexture(loagindTexture6);
		loagindSprite7.setTexture(loagindTexture7);
		loagindSprite8.setTexture(loagindTexture8);

		while (window.isOpen())
		{			
			sf::Event event;

			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					window.close();
				}
			}

			window.clear();

			for (int i = 0; i < HEIGHT_MAP; i++)
			{
				for (int j = 0; j < WIDTH_MAP; j++)
				{
					switch (randomNumberBackground)
					{
					case 0: menuBackgroundSprite.setTextureRect(sf::IntRect(0, 0, 120, 120)); break;
					case 1: menuBackgroundSprite.setTextureRect(sf::IntRect(120, 0, 120, 120)); break;
					case 2: menuBackgroundSprite.setTextureRect(sf::IntRect(240, 0, 120, 120)); break;
					case 3: menuBackgroundSprite.setTextureRect(sf::IntRect(360, 0, 120, 120)); break;
					case 4: menuBackgroundSprite.setTextureRect(sf::IntRect(480, 0, 120, 120)); break;
					case 5: menuBackgroundSprite.setTextureRect(sf::IntRect(600, 0, 120, 120)); break;
					case 6: menuBackgroundSprite.setTextureRect(sf::IntRect(720, 0, 120, 120)); break;
					case 7: menuBackgroundSprite.setTextureRect(sf::IntRect(840, 0, 120, 120)); break;
					case 8: menuBackgroundSprite.setTextureRect(sf::IntRect(960, 0, 120, 120)); break;
					case 9: menuBackgroundSprite.setTextureRect(sf::IntRect(1080, 0, 120, 120)); break;
					}
					menuBackgroundSprite.setPosition(j * 120.0f, i * 120.0f);
					window.draw(menuBackgroundSprite);
				}
			}

			switch (nowSpriteDrawing)
			{
			case 1: loagindSprite1.setPosition(703, 286); window.draw(loagindSprite1); break;
			case 2: loagindSprite2.setPosition(703, 286); window.draw(loagindSprite2); break;
			case 3: loagindSprite3.setPosition(703, 286); window.draw(loagindSprite3); break;
			case 4: loagindSprite4.setPosition(703, 286); window.draw(loagindSprite4); break;
			case 5: loagindSprite5.setPosition(703, 286); window.draw(loagindSprite5); break;
			case 6: loagindSprite6.setPosition(703, 286); window.draw(loagindSprite6); break;
			case 7: loagindSprite7.setPosition(703, 286); window.draw(loagindSprite7); break;
			case 8: loagindSprite8.setPosition(703, 286); window.draw(loagindSprite8); break;
			default:
				break;
			}

			for (int i = 1; i < 9; i++) 
			{
				if (nowSpriteDrawing == i) 
				{
					nowSpriteDrawing++;
					if (nowSpriteDrawing > 8) 
					{
						nowSpriteDrawing = 1;
					}
					Sleep(100);
					break;
				}
			}

			if (windowClose) 
			{
				window.close();
			}

			window.display();
		}
	});

	std::vector <std::vector <Army*>> pullGame(9);
	std::vector <Army*> pullAncient, pullClassic, pullMedival, pullRenaissancee, pullIndustrial, pullModern, pullAtomic, pullInfromation, pullFuture;

	std::thread threadAncient([&pullAncient]()
	{
		for (size_t i = 0; i < 16; i++)
		{
			pullAncient.push_back(new Squad(enumSquad::SQUAD_WARRIOR));
			pullAncient.push_back(new Squad(enumSquad::SQUAD_ARCHER));
			pullAncient.push_back(new Squad(enumSquad::SQUAD_HOURSEARCHER));
			pullAncient.push_back(new Squad(enumSquad::SQUAD_SPEARMAN));
		}
	});

	std::thread threadClassic([&pullClassic]()
	{
		for (size_t i = 0; i < 16; i++)
		{
			pullClassic.push_back(new Squad(enumSquad::SQUAD_SWORDSMAN));
			pullClassic.push_back(new Squad(enumSquad::SQUAD_LONGBOWARCHER));
			pullClassic.push_back(new Squad(enumSquad::SQUAD_HORSEMAN));
			pullClassic.push_back(new Squad(enumSquad::SQUAD_HOPLITE));
		}
	});

	std::thread threadMedival([&pullMedival]()
	{
		for (size_t i = 0; i < 16; i++)
		{
			pullMedival.push_back(new Squad(enumSquad::SQUAD_LONGSWORDSMAN));
			pullMedival.push_back(new Squad(enumSquad::SQUAD_CROSSBOWMAN));
			pullMedival.push_back(new Squad(enumSquad::SQUAD_KNIGHT));
			pullMedival.push_back(new Squad(enumSquad::SQUAD_PIKEMAN));
		}
	});

	std::thread threadRenaissancee([&pullRenaissancee]()
	{
		for (size_t i = 0; i < 16; i++)
		{
			pullRenaissancee.push_back(new Squad(enumSquad::SQUAD_HARQUEBUSIER));
			pullRenaissancee.push_back(new Squad(enumSquad::SQUAD_CANNON));
			pullRenaissancee.push_back(new Squad(enumSquad::SQUAD_LANCER));
		}
	});

	std::thread threadIndustrial([&pullIndustrial]()
	{
		for (size_t i = 0; i < 16; i++)
		{
			pullIndustrial.push_back(new Squad(enumSquad::SQUAD_MUSKETEER));
			pullIndustrial.push_back(new Squad(enumSquad::SQUAD_GATLING));
			pullIndustrial.push_back(new Squad(enumSquad::SQUAD_CAVALRY));
		}
	});

	std::thread threadModern([&pullModern]()
	{
		for (size_t i = 0; i < 12; i++)
		{
			pullModern.push_back(new Squad(enumSquad::SQUAD_INFANTRYMAN));
			pullModern.push_back(new Squad(enumSquad::SQUAD_MACHINGGUN));
			pullModern.push_back(new Squad(enumSquad::SQUAD_TANKETTE));
			pullModern.push_back(new Squad(enumSquad::SQUAD_ARTBATTERY));
		}
	});

	std::thread threadAtomic([&pullAtomic]()
	{
		for (size_t i = 0; i < 8; i++)
		{
			pullAtomic.push_back(new Squad(enumSquad::SQUAD_SEAINFANTRYMAN));
			pullAtomic.push_back(new Squad(enumSquad::SQUAD_BAZOOKA));
			pullAtomic.push_back(new Squad(enumSquad::SQUAD_TANK));
			pullAtomic.push_back(new Squad(enumSquad::SQUAD_ANTITANKCANNON));
		}
	});

	std::thread threadInformation([&pullInfromation]()
	{
		for (size_t i = 0; i < 8; i++)
		{
			pullInfromation.push_back(new Squad(enumSquad::SQUAD_MOTORIZEDINFANTRY));
			pullInfromation.push_back(new Squad(enumSquad::SQUAD_ROCKET));
			pullInfromation.push_back(new Squad(enumSquad::SQUAD_MODERNTANK));
			pullInfromation.push_back(new Squad(enumSquad::SQUAD_ROCKETARTILLERY));
		}
	});

	std::thread threadFuture([&pullFuture]()
	{
		for (size_t i = 0; i < 6; i++)
		{
			pullFuture.push_back(new Squad(enumSquad::SQUAD_FUTURESMAN));
			pullFuture.push_back(new Squad(enumSquad::SQUAD_ROBOT));
		}
	});

	threadAncient.join();
	threadClassic.join();
	threadMedival.join();
	threadRenaissancee.join();
	threadIndustrial.join();
	threadModern.join();
	threadAtomic.join();
	threadInformation.join();
	threadFuture.join();
	threadLoading.detach();

	pullGame.at(0) = pullAncient;
	pullGame.at(1) = pullClassic;
	pullGame.at(2) = pullMedival;
	pullGame.at(3) = pullRenaissancee;
	pullGame.at(4) = pullIndustrial;
	pullGame.at(5) = pullModern;
	pullGame.at(6) = pullAtomic;
	pullGame.at(7) = pullInfromation;
	pullGame.at(8) = pullFuture;

	windowClose = true;

	return pullGame;
}

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

void shop(std::vector <std::vector <Army*>>& pullGame, Player*& player)
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "War of Ages: Battle for Castle (SHOP)", sf::Style::Fullscreen);

	sf::Texture mapTexture;
	mapTexture.loadFromFile("images/map.png");
	sf::Sprite mapSprite;
	mapSprite.setTexture(mapTexture);

	sf::Texture heatlhTexture;
	heatlhTexture.loadFromFile("images/heart.png");
	sf::Sprite healthSpriteFirst;
	healthSpriteFirst.setTexture(heatlhTexture);
	healthSpriteFirst.setScale(0.5f, 0.5f);
	healthSpriteFirst.setPosition(window.getSize().x - 200.0f, window.getSize().y - 100.0f);

	sf::Texture coinTexture;
	coinTexture.loadFromFile("images/coin.png");
	sf::Sprite coinSprite;
	coinSprite.setTexture(coinTexture);
	coinSprite.setScale(0.2f, 0.2f);
	coinSprite.setPosition(10.0f, window.getSize().y - 112.4f);

	sf::Texture refreshTexture;
	refreshTexture.loadFromFile("images/refresh.png");
	sf::Sprite refreshSprite;
	refreshSprite.setTexture(refreshTexture);
	refreshSprite.setScale(0.25f, 0.25f);
	refreshSprite.setPosition(window.getSize().x - 444.0f, 20.0f);

	sf::Texture upTexture;
	upTexture.loadFromFile("images/up.png");
	sf::Sprite upSprite;
	upSprite.setTexture(upTexture);
	upSprite.setScale(0.25f, 0.25f);
	upSprite.setPosition(window.getSize().x - 148.0f, 20.0f);

	sf::Texture addPlaceTexture;
	addPlaceTexture.loadFromFile("images/addPlace.png");
	sf::Sprite addPlaceSprite;
	addPlaceSprite.setTexture(addPlaceTexture);
	addPlaceSprite.setScale(0.25f, 0.25f);
	addPlaceSprite.setPosition(window.getSize().x - 296.0f, 20.0f);

	sf::Texture deleteTexture;
	deleteTexture.loadFromFile("images/trash.png");
	sf::Sprite deleteSprite;
	deleteSprite.setTexture(deleteTexture);

	sf::Texture battleTexture;
	battleTexture.loadFromFile("images/battle.png");
	sf::Sprite battleSprite;
	battleSprite.setTexture(battleTexture);
	battleSprite.setScale(0.78f, 0.78f);
	battleSprite.setPosition(window.getSize().x - 210.0f, 440.0f);

	sf::Font font;
	font.loadFromFile("16249.ttf");

	sf::Text textAttack;
	textAttack.setFont(font);
	textAttack.setOutlineColor(sf::Color::Black);
	textAttack.setStyle(sf::Text::Bold);
	
	sf::Text refreshText = textAttack;
	refreshText.setCharacterSize(60);
	refreshText.setOutlineThickness(2);
	refreshText.setPosition(window.getSize().x - 396.0f, 150.0f);

	sf::Text upText = refreshText;
	upText.setPosition(window.getSize().x - 100.0f, 150.0f);

	sf::Text addPlaceText = refreshText;
	addPlaceText.setPosition(window.getSize().x - 248.0f, 150.0f);

	sf::Text textPlayerHealthFirst = textAttack;
	textPlayerHealthFirst.setFillColor(sf::Color(155, 17, 30));
	textPlayerHealthFirst.setOutlineThickness(2);
	textPlayerHealthFirst.setOutlineColor(sf::Color::White);
	textPlayerHealthFirst.setCharacterSize(60);
	textPlayerHealthFirst.setPosition(window.getSize().x - 70.0f, window.getSize().y - 100.0f);
	textPlayerHealthFirst.setString(std::to_string(player->getPlayerHealth()));

	sf::Text textCoinCount = textAttack;
	textCoinCount.setFillColor(sf::Color(184, 134, 11));
	textCoinCount.setOutlineThickness(2);
	textCoinCount.setOutlineColor(sf::Color::White);
	textCoinCount.setCharacterSize(60);
	textCoinCount.setPosition(162.4f, window.getSize().y - 100.0f);

	sf::Text textErrorCoinsCount = textAttack;
	textErrorCoinsCount.setOutlineThickness(2);
	textErrorCoinsCount.setCharacterSize(40);
	textErrorCoinsCount.setPosition(550.0f, window.getSize().y - 90.0f);
	textErrorCoinsCount.setString(languageString(25));
	textErrorCoinsCount.setOutlineColor(sf::Color::Red);

	sf::Text textInfo = textAttack;
	textInfo.setCharacterSize(25);
	textInfo.setOutlineThickness(1.5f);
	textInfo.setPosition(20.0f, 10.0f);

	textAttack.setCharacterSize(40);
	textAttack.setOutlineThickness(4);
	sf::Text textHealth = textAttack;

	sf::CircleShape shapeAttack;
	shapeAttack.setRadius(25.f);
	shapeAttack.setOutlineThickness(4);
	sf::CircleShape shapeHealth = shapeAttack;
	shapeAttack.setFillColor(sf::Color(255, 127, 80));
	shapeHealth.setFillColor(sf::Color(100, 149, 237));

	sf::Texture textureInfo;
	textureInfo.loadFromFile("images/infobackground.jpg");
	sf::Sprite spriteInfo;
	spriteInfo.setTexture(textureInfo);
	spriteInfo.setTextureRect(sf::IntRect(0, 0, 340, 510));
	spriteInfo.setScale(1.4f, 0.8f);

	bool isSpriteMoveShop = false;
	bool isSpriteMoveActive = false;
	bool isSpriteMoveReserve = false;
	float dXSpriteMove = 0;
	int spriteMoveParameter = 0;
	bool isPressedForMoveShop = false;
	bool isPressedForMoveActive = false;
	bool isPressedForMoveReserve = false;

	bool showInfoText = true;
	bool showInfoReRenderShop = true;
	bool showInfoReRenderActive = true;
	bool showInfoReRenderReserve = true;
	int showInfoParameterShop = 0;
	int showInfoParameterActive = 0;
	int showInfoParameterReserve = 0;

	bool isDrawTrash = false;

	std::vector <Army*> tempShopArmy;
	refreshShopSquads(pullGame, player, tempShopArmy);

	std::vector <Army*> tempActiveArmy = player->getPlayerActiveArmy();
	std::vector <Army*> tempReserveArmy = player->getPlayerReserveArmy();

	sf::Clock clock;
	float textErrorTimer = 0;
	bool isTextErrorTimer = false;

	while (window.isOpen())
	{
		float time = (float)clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;

		sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.key.code == sf::Mouse::Left)
				{
					for (int i = 0; i < (int)tempShopArmy.size(); i++)
					{
						if (tempShopArmy.at(i)->getArmySprite().getGlobalBounds().contains((float)mousePosition.x, (float)mousePosition.y))
						{
							isPressedForMoveShop = true;
							spriteMoveParameter = i;
							dXSpriteMove = mousePosition.x - tempShopArmy.at(spriteMoveParameter)->getArmySpawnCoordinateX();
							isSpriteMoveShop = true;
							break;
						}
					}

					for (int i = 0; i < (int)tempActiveArmy.size(); i++)
					{
						if (tempActiveArmy.at(i)->getArmySprite().getGlobalBounds().contains((float)mousePosition.x, (float)mousePosition.y))
						{
							isPressedForMoveActive = true;
							spriteMoveParameter = i;
							dXSpriteMove = mousePosition.x - tempActiveArmy.at(spriteMoveParameter)->getArmySpawnCoordinateX();
							isSpriteMoveActive = true;
							deleteSprite.setPosition(10.0f, 440.0f);
							isDrawTrash = true;							
							break;
						}
					}

					for (int i = 0; i < (int)tempReserveArmy.size(); i++)
					{
						if (tempReserveArmy.at(i)->getArmySprite().getGlobalBounds().contains((float)mousePosition.x, (float)mousePosition.y))
						{
							isPressedForMoveReserve = true;
							spriteMoveParameter = i;
							dXSpriteMove = mousePosition.x - tempReserveArmy.at(spriteMoveParameter)->getArmySpawnCoordinateX();
							isSpriteMoveReserve = true;
							deleteSprite.setPosition(10.0f, 800.0f);
							isDrawTrash = true;
							break;
						}
					}
				}				
			}

			if (event.type == sf::Event::MouseButtonReleased)
			{
				if (event.key.code == sf::Mouse::Left)
				{
					if (isPressedForMoveShop)
					{
						for (int i = 0; i < (int)tempShopArmy.size(); i++)
						{
							if (i < spriteMoveParameter)
							{
								if ((float)mousePosition.x < tempShopArmy.at(i)->getArmySpawnCoordinateX() + 100)
								{
									std::swap(tempShopArmy[i], tempShopArmy[spriteMoveParameter]);
									setOrderOfShopArmy(tempShopArmy);
									break;
								}
							}
						}

						for (int i = tempShopArmy.size() - 1; i > -1; i--)
						{
							if (i > spriteMoveParameter)
							{
								if ((float)mousePosition.x > tempShopArmy.at(i)->getArmySpawnCoordinateX() + 100)
								{
									std::swap(tempShopArmy[i], tempShopArmy[spriteMoveParameter]);
									setOrderOfShopArmy(tempShopArmy);
									break;
								}
							}
						}

						isSpriteMoveShop = false;
						setOrderOfShopArmy(tempShopArmy);
						isPressedForMoveShop = false;
					}

					if (isPressedForMoveActive)
					{
						if (tempActiveArmy.at(spriteMoveParameter)->getArmySpawnCoordinateX() <= 160.0f)
						{
							switch (tempActiveArmy.at(spriteMoveParameter)->getEraName())
							{
							case enumEraName::ERA_ANCIENT:
								pullGame.at(0).push_back(tempActiveArmy.at(spriteMoveParameter)); break;
							case enumEraName::ERA_CLASSIC:
								pullGame.at(1).push_back(tempActiveArmy.at(spriteMoveParameter)); break;
							case enumEraName::ERA_MEDIVAL:
								pullGame.at(2).push_back(tempActiveArmy.at(spriteMoveParameter)); break;
							case enumEraName::ERA_RENAISSANCEE:
								pullGame.at(3).push_back(tempActiveArmy.at(spriteMoveParameter)); break;
							case enumEraName::ERA_INDUSTRIAL:
								pullGame.at(4).push_back(tempActiveArmy.at(spriteMoveParameter)); break;
							case enumEraName::ERA_MODERN:
								pullGame.at(5).push_back(tempActiveArmy.at(spriteMoveParameter)); break;
							case enumEraName::ERA_ATOMIC:
								pullGame.at(6).push_back(tempActiveArmy.at(spriteMoveParameter)); break;
							case enumEraName::ERA_INFORMATION:
								pullGame.at(7).push_back(tempActiveArmy.at(spriteMoveParameter)); break;
							case enumEraName::ERA_FUTURE:
								pullGame.at(8).push_back(tempActiveArmy.at(spriteMoveParameter)); break;
							default:
								break;
							}
							tempActiveArmy.erase(tempActiveArmy.begin() + spriteMoveParameter);
							tempActiveArmy = player->setPlayerTempActiveArmy(tempActiveArmy);
							spriteMoveParameter = -1;
						}
						else 
						{
							for (int i = 0; i < (int)tempActiveArmy.size(); i++)
							{
								if (i < spriteMoveParameter)
								{
									if ((float)mousePosition.x < tempActiveArmy.at(i)->getArmySpawnCoordinateX() + 100)
									{
										std::swap(tempActiveArmy[i], tempActiveArmy[spriteMoveParameter]);
										player->setPlayerActiveArmy(tempActiveArmy);
										player->setOrderOfActiveArmy();
										break;
									}
								}
							}

							for (int i = tempActiveArmy.size() - 1; i > -1; i--)
							{
								if (i > spriteMoveParameter)
								{
									if ((float)mousePosition.x > tempActiveArmy.at(i)->getArmySpawnCoordinateX() + 100)
									{
										std::swap(tempActiveArmy[i], tempActiveArmy[spriteMoveParameter]);
										player->setPlayerActiveArmy(tempActiveArmy);
										player->setOrderOfActiveArmy();
										break;
									}
								}
							}
						}						

						isSpriteMoveActive = false;
						player->setOrderOfActiveArmy();

						for (size_t i = 0; i < tempActiveArmy.size(); i++)
						{
							tempActiveArmy.at(i)->setArmySpawnCoordinateY(440.0);
						}

						player->setPlayerActiveArmy(tempActiveArmy);
						isPressedForMoveActive = false;
					}

					if (isPressedForMoveReserve)
					{
						if (tempReserveArmy.at(spriteMoveParameter)->getArmySpawnCoordinateX() <= 160.0f)
						{
							switch (tempReserveArmy.at(spriteMoveParameter)->getEraName())
							{
							case enumEraName::ERA_ANCIENT:
								pullGame.at(0).push_back(tempReserveArmy.at(spriteMoveParameter)); break;
							case enumEraName::ERA_CLASSIC:
								pullGame.at(1).push_back(tempReserveArmy.at(spriteMoveParameter)); break;
							case enumEraName::ERA_MEDIVAL:
								pullGame.at(2).push_back(tempReserveArmy.at(spriteMoveParameter)); break;
							case enumEraName::ERA_RENAISSANCEE:
								pullGame.at(3).push_back(tempReserveArmy.at(spriteMoveParameter)); break;
							case enumEraName::ERA_INDUSTRIAL:
								pullGame.at(4).push_back(tempReserveArmy.at(spriteMoveParameter)); break;
							case enumEraName::ERA_MODERN:
								pullGame.at(5).push_back(tempReserveArmy.at(spriteMoveParameter)); break;
							case enumEraName::ERA_ATOMIC:
								pullGame.at(6).push_back(tempReserveArmy.at(spriteMoveParameter)); break;
							case enumEraName::ERA_INFORMATION:
								pullGame.at(7).push_back(tempReserveArmy.at(spriteMoveParameter)); break;
							case enumEraName::ERA_FUTURE:
								pullGame.at(8).push_back(tempReserveArmy.at(spriteMoveParameter)); break;
							default:
								break;
							}
							tempReserveArmy.erase(tempReserveArmy.begin() + spriteMoveParameter);
							tempReserveArmy = player->setPlayerTempReserveArmy(tempReserveArmy);
							spriteMoveParameter = -1;
						}
						else
						{
							for (int i = 0; i < (int)tempReserveArmy.size(); i++)
							{
								if (i < spriteMoveParameter)
								{
									if ((float)mousePosition.x < tempReserveArmy.at(i)->getArmySpawnCoordinateX() + 100)
									{
										std::swap(tempReserveArmy[i], tempReserveArmy[spriteMoveParameter]);
										player->setPlayerReserveArmy(tempReserveArmy);
										player->setOrderOfReserveArmy();
										break;
									}
								}
							}

							for (int i = tempReserveArmy.size() - 1; i > -1; i--)
							{
								if (i > spriteMoveParameter)
								{
									if ((float)mousePosition.x > tempReserveArmy.at(i)->getArmySpawnCoordinateX() + 100)
									{
										std::swap(tempReserveArmy[i], tempReserveArmy[spriteMoveParameter]);
										player->setPlayerReserveArmy(tempReserveArmy);
										player->setOrderOfReserveArmy();
										break;
									}
								}
							}
						}

						isSpriteMoveReserve = false;
						player->setOrderOfReserveArmy();
						player->setPlayerReserveArmy(tempReserveArmy);
						isPressedForMoveReserve = false;
					}

					if (refreshSprite.getGlobalBounds().contains((float)mousePosition.x, (float)mousePosition.y))
					{
						if (player->getPlayerActionPointsNow() >= 1) 
						{
							player->setPlayerActionPointsNow(player->getPlayerActionPointsNow() - 1);
							refreshShopSquads(pullGame, player, tempShopArmy);
						}
						else 
						{
							isTextErrorTimer = true;
						}
					}

					if (upSprite.getGlobalBounds().contains((float)mousePosition.x, (float)mousePosition.y))
					{
						if (player->getPlayerActionPointsNow() >= player->getPlayerNextEraCost())
						{
							player->setPlayerActionPointsNow(player->getPlayerActionPointsNow() - player->getPlayerNextEraCost());

							switch (player->getPlayerEra())
							{
							case enumEraName::ERA_ANCIENT:
								player->setPlayerEra(enumEraName::ERA_CLASSIC); break;
							case enumEraName::ERA_CLASSIC:
								player->setPlayerEra(enumEraName::ERA_MEDIVAL); break;
							case enumEraName::ERA_MEDIVAL:
								player->setPlayerEra(enumEraName::ERA_RENAISSANCEE); break;
							case enumEraName::ERA_RENAISSANCEE:
								player->setPlayerEra(enumEraName::ERA_INDUSTRIAL); break;
							case enumEraName::ERA_INDUSTRIAL:
								player->setPlayerEra(enumEraName::ERA_MODERN); break;
							case enumEraName::ERA_MODERN:
								player->setPlayerEra(enumEraName::ERA_ATOMIC); break;
							case enumEraName::ERA_ATOMIC:
								player->setPlayerEra(enumEraName::ERA_INFORMATION); break;
							case enumEraName::ERA_INFORMATION:
								player->setPlayerEra(enumEraName::ERA_FUTURE); break;
							default:
								break;
							}
						}
						else
						{
							isTextErrorTimer = true;
						}
					}

					if (addPlaceSprite.getGlobalBounds().contains((float)mousePosition.x, (float)mousePosition.y))
					{
						if (player->getPlayerActionPointsNow() >= player->getPlayerAdditionalPlaceForSquadCost()) 
						{
							if (player->getPlayerArmyCount() < 4 && (int)player->getPlayerEra() >= 2 ||
								player->getPlayerArmyCount() < 5 && (int)player->getPlayerEra() >= 4 ||
								player->getPlayerArmyCount() < 6 && (int)player->getPlayerEra() >= 6 ||
								player->getPlayerArmyCount() < 7 && (int)player->getPlayerEra() >= 8)
							{
								player->setPlayerActionPointsNow(player->getPlayerActionPointsNow() - player->getPlayerAdditionalPlaceForSquadCost());
								player->setPlayerAdditionalPlaceForSquadCost(6);
								player->setPlayerArmyCount(player->getPlayerArmyCount() + 1);
							}
							else 
							{
								isTextErrorTimer = true;
							}
						}
						else
						{
							isTextErrorTimer = true;
						}
					}

					if (battleSprite.getGlobalBounds().contains((float)mousePosition.x, (float)mousePosition.y))
					{
						player->setPlayerActionPointsNow(player->getPlayerActionPointsMax());
						if (player->getPlayerNextEraCost() > 0)
						{
							player->setPlayerNextEraCost(player->getPlayerNextEraCost() - 1);
						}						

						if (player->getPlayerArmyCount() < 4 && (int)player->getPlayerEra() >= 2 ||
							player->getPlayerArmyCount() < 5 && (int)player->getPlayerEra() >= 4 ||
							player->getPlayerArmyCount() < 6 && (int)player->getPlayerEra() >= 6 ||
							player->getPlayerArmyCount() < 7 && (int)player->getPlayerEra() >= 8) 
						{
							if (player->getPlayerAdditionalPlaceForSquadCost() > 0)
							{
								player->setPlayerAdditionalPlaceForSquadCost(player->getPlayerAdditionalPlaceForSquadCost() - 1);
							}							
						}

						window.close();
					}

					isDrawTrash = false;
				}

				if (event.key.code == sf::Mouse::Right)
				{
					for (int i = 0; i < (int)tempShopArmy.size(); i++)
					{
						if (tempShopArmy.at(i)->getArmySprite().getGlobalBounds().contains((float)mousePosition.x, (float)mousePosition.y))
						{
							if (player->getPlayerReserveCount() > (int)tempReserveArmy.size() && player->getPlayerActionPointsNow() >= tempShopArmy.at(i)->getArmyCost())
							{
								player->setPlayerActionPointsNow(player->getPlayerActionPointsNow() - tempShopArmy.at(i)->getArmyCost());
								tempReserveArmy.push_back(tempShopArmy.at(i));
								tempShopArmy.erase(tempShopArmy.begin() + i);
								setOrderOfShopArmy(tempShopArmy);
								tempReserveArmy = player->setPlayerTempReserveArmy(tempReserveArmy);								
							}
							else 
							{
								isTextErrorTimer = true;
							}

							break;							
						}
					}

					for (int i = 0; i < (int)tempReserveArmy.size(); i++)
					{
						if (tempReserveArmy.at(i)->getArmySprite().getGlobalBounds().contains((float)mousePosition.x, (float)mousePosition.y))
						{
							if (player->getPlayerArmyCount() > (int)tempActiveArmy.size())
							{
								tempReserveArmy.at(i)->setArmySpawnCoordinateY(440.0f);
								tempActiveArmy.push_back(tempReserveArmy.at(i));
								tempReserveArmy.erase(tempReserveArmy.begin() + i);
								tempReserveArmy = player->setPlayerTempReserveArmy(tempReserveArmy);
								tempActiveArmy = player->setPlayerTempActiveArmy(tempActiveArmy);
							}
							else
							{
								isTextErrorTimer = true;
							}

							break;
						}
					}

					for (int i = 0; i < (int)tempActiveArmy.size(); i++)
					{
						if (tempActiveArmy.at(i)->getArmySprite().getGlobalBounds().contains((float)mousePosition.x, (float)mousePosition.y))
						{
							if (player->getPlayerReserveCount() > (int)tempReserveArmy.size()) 
							{
								tempActiveArmy.at(i)->setArmySpawnCoordinateY(440.0f);
								tempReserveArmy.push_back(tempActiveArmy.at(i));
								tempActiveArmy.erase(tempActiveArmy.begin() + i);
								tempActiveArmy = player->setPlayerTempActiveArmy(tempActiveArmy);
								tempReserveArmy = player->setPlayerTempReserveArmy(tempReserveArmy);
							}
							else
							{
								isTextErrorTimer = true;
							}
							
							break;
						}
					}
				}
			}

			if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::Escape)
				{
					returnAllShopSquadsToGeneralPull(pullGame, tempShopArmy);
					returnAllPlayerSquadsToGeneralPull(pullGame, player);
					window.close();
					gameProcess(pullGame);
				}
			}

			if (showInfoReRenderShop)
			{
				for (int i = 0; i < (int)tempShopArmy.size(); i++)
				{
					if (tempShopArmy.at(i)->getArmySprite().getGlobalBounds().contains((float)mousePosition.x, (float)mousePosition.y))
					{
						showInfoParameterShop = i;
						showInfoReRenderShop = false;

						switch (showInfoText)
						{
						case true:
							textInfo.setString(getStringTextInfo(tempShopArmy.at(i)));
							showInfoText = false;
							break;

						case false:
							textInfo.setString("");
							showInfoText = true;
							break;
						}

						break;
					}
				}
			}

			if (showInfoReRenderActive)
			{
				for (int i = 0; i < (int)tempActiveArmy.size(); i++)
				{
					if (tempActiveArmy.at(i)->getArmySprite().getGlobalBounds().contains((float)mousePosition.x, (float)mousePosition.y))
					{
						showInfoParameterActive = i;
						showInfoReRenderActive = false;

						switch (showInfoText)
						{
						case true:
							textInfo.setString(getStringTextInfo(tempActiveArmy.at(i)));
							showInfoText = false;
							break;

						case false:
							textInfo.setString("");
							showInfoText = true;
							break;
						}

						break;
					}
				}
			}

			if (showInfoReRenderReserve)
			{
				for (int i = 0; i < (int)tempReserveArmy.size(); i++)
				{
					if (tempReserveArmy.at(i)->getArmySprite().getGlobalBounds().contains((float)mousePosition.x, (float)mousePosition.y))
					{
						showInfoParameterReserve = i;
						showInfoReRenderReserve = false;

						switch (showInfoText)
						{
						case true:
							textInfo.setString(getStringTextInfo(tempReserveArmy.at(i)));
							showInfoText = false;
							break;

						case false:
							textInfo.setString("");
							showInfoText = true;
							break;
						}

						break;
					}
				}
			}

			if (!showInfoReRenderShop)
			{
				try
				{
					if (!tempShopArmy.at(showInfoParameterShop)->getArmySprite().getGlobalBounds().contains((float)mousePosition.x, (float)mousePosition.y))
					{
						showInfoParameterShop = 0;
						showInfoReRenderShop = true;
						showInfoText = true;
					}
				}
				catch (const std::out_of_range& oor)
				{
					showInfoParameterShop = 0;
					showInfoReRenderShop = true;
					showInfoText = true;
				}
			}

			if (!showInfoReRenderActive)
			{
				try
				{
					if (!tempActiveArmy.at(showInfoParameterActive)->getArmySprite().getGlobalBounds().contains((float)mousePosition.x, (float)mousePosition.y))
					{
						showInfoParameterActive = 0;
						showInfoReRenderActive = true;
						showInfoText = true;
					}
				}
				catch (const std::out_of_range& oor)
				{
					showInfoParameterActive = 0;
					showInfoReRenderActive = true;
					showInfoText = true;
				}
			}

			if (!showInfoReRenderReserve)
			{
				try
				{
					if (!tempReserveArmy.at(showInfoParameterReserve)->getArmySprite().getGlobalBounds().contains((float)mousePosition.x, (float)mousePosition.y))
					{
						showInfoParameterReserve = 0;
						showInfoReRenderReserve = true;
						showInfoText = true;
					}
				}
				catch (const std::out_of_range& oor)
				{
					showInfoParameterReserve = 0;
					showInfoReRenderReserve = true;
					showInfoText = true;
				}
			}
		}

		if (spriteMoveParameter != -1) 
		{
			if (isSpriteMoveShop)
			{
				tempShopArmy.at(spriteMoveParameter)->setArmySpawnCoordinateX(mousePosition.x - dXSpriteMove);
			}

			if (isSpriteMoveActive)
			{
				tempActiveArmy.at(spriteMoveParameter)->setArmySpawnCoordinateX(mousePosition.x - dXSpriteMove);
			}

			if (isSpriteMoveReserve)
			{
				tempReserveArmy.at(spriteMoveParameter)->setArmySpawnCoordinateX(mousePosition.x - dXSpriteMove);
			}
		}

		for (int i = 0; i < (int)tempActiveArmy.size(); i++)
		{
			for (int j = 0; j < (int)tempActiveArmy.size(); j++)
			{
				if (i == j)
				{
					continue;
				}
				else
				{
					if (tempActiveArmy.at(i)->getArmyUpgrade() == tempActiveArmy.at(j)->getArmyUpgrade() && tempActiveArmy.at(i)->getArmyUpgrade() != enumSquad::NONE)
					{
						if (tempActiveArmy.at(i)->getArmyID() == enumSquad::SQUAD_KNIGHT && tempActiveArmy.at(j)->getArmyID() == enumSquad::SQUAD_PIKEMAN ||
							tempActiveArmy.at(j)->getArmyID() == enumSquad::SQUAD_KNIGHT && tempActiveArmy.at(i)->getArmyID() == enumSquad::SQUAD_PIKEMAN)
						{
							if (player->getPlayerEra() > tempActiveArmy.at(i)->getEraName()) 
							{
								pullGame.at(2).push_back(tempActiveArmy.at(i));
								pullGame.at(2).push_back(tempActiveArmy.at(j));
								if(i > j)
								{
									tempActiveArmy.erase(tempActiveArmy.begin() + i);
									tempActiveArmy.erase(tempActiveArmy.begin() + j);
								}
								else 
								{
									tempActiveArmy.erase(tempActiveArmy.begin() + j);
									tempActiveArmy.erase(tempActiveArmy.begin() + i);
								}


								for (int k = 0; k < (int)pullGame.at(3).size(); k++) 
								{
									if (pullGame.at(3).at(k)->getArmyID() == enumSquad::SQUAD_LANCER) 
									{
										pullGame.at(3).at(k)->setArmySpawnCoordinateY(440.0f);
										tempActiveArmy.push_back(pullGame.at(3).at(k));
										pullGame.at(3).erase(pullGame.at(3).begin() + k);
										break;
									}
								}

								tempActiveArmy = player->setPlayerTempActiveArmy(tempActiveArmy);
							}
						}
						else if (tempActiveArmy.at(i)->getArmyID() == enumSquad::SQUAD_KNIGHT && tempActiveArmy.at(j)->getArmyID() == enumSquad::SQUAD_KNIGHT ||
							tempActiveArmy.at(j)->getArmyID() == enumSquad::SQUAD_PIKEMAN && tempActiveArmy.at(i)->getArmyID() == enumSquad::SQUAD_PIKEMAN)
						{
							continue;
						}
						else
						{
							if (player->getPlayerEra() > tempActiveArmy.at(i)->getEraName())
							{
								pullGame.at((int)tempActiveArmy.at(i)->getEraName()).push_back(tempActiveArmy.at(i));
								pullGame.at((int)tempActiveArmy.at(j)->getEraName()).push_back(tempActiveArmy.at(j));

								int tempIndexForEraName = (int)tempActiveArmy.at(i)->getEraName() + 1;
								enumSquad tempIndexForEnumSquad = tempActiveArmy.at(i)->getArmyUpgrade();

								if (i > j)
								{
									tempActiveArmy.erase(tempActiveArmy.begin() + i);
									tempActiveArmy.erase(tempActiveArmy.begin() + j);
								}
								else
								{
									tempActiveArmy.erase(tempActiveArmy.begin() + j);
									tempActiveArmy.erase(tempActiveArmy.begin() + i);
								}

								for (int k = 0; k < (int)pullGame.at(tempIndexForEraName).size(); k++)
								{
									if (pullGame.at(tempIndexForEraName).at(k)->getArmyID() == tempIndexForEnumSquad)
									{
										pullGame.at(tempIndexForEraName).at(k)->setArmySpawnCoordinateY(440.0);
										tempActiveArmy.push_back(pullGame.at(tempIndexForEraName).at(k));
										pullGame.at(tempIndexForEraName).erase(pullGame.at(tempIndexForEraName).begin() + k);
										break;
									}
								}

								tempActiveArmy = player->setPlayerTempActiveArmy(tempActiveArmy);
							}
						}
					}
				}
			}
		}

		for (int i = 0; i < (int)tempReserveArmy.size(); i++)
		{
			for (int j = 0; j < (int)tempReserveArmy.size(); j++)
			{
				if (i == j)
				{
					continue;
				}
				else
				{
					if (tempReserveArmy.at(i)->getArmyUpgrade() == tempReserveArmy.at(j)->getArmyUpgrade() && tempReserveArmy.at(i)->getArmyUpgrade() != enumSquad::NONE)
					{
						if (tempReserveArmy.at(i)->getArmyID() == enumSquad::SQUAD_KNIGHT && tempReserveArmy.at(j)->getArmyID() == enumSquad::SQUAD_PIKEMAN ||
							tempReserveArmy.at(j)->getArmyID() == enumSquad::SQUAD_KNIGHT && tempReserveArmy.at(i)->getArmyID() == enumSquad::SQUAD_PIKEMAN)
						{
							if (player->getPlayerEra() > tempReserveArmy.at(i)->getEraName())
							{
								pullGame.at(2).push_back(tempReserveArmy.at(i));
								pullGame.at(2).push_back(tempReserveArmy.at(j));
								if (i > j)
								{
									tempReserveArmy.erase(tempReserveArmy.begin() + i);
									tempReserveArmy.erase(tempReserveArmy.begin() + j);
								}
								else
								{
									tempReserveArmy.erase(tempReserveArmy.begin() + j);
									tempReserveArmy.erase(tempReserveArmy.begin() + i);
								}


								for (int k = 0; k < (int)pullGame.at(3).size(); k++)
								{
									if (pullGame.at(3).at(k)->getArmyID() == enumSquad::SQUAD_LANCER)
									{
										pullGame.at(3).at(k)->setArmySpawnCoordinateY(440.0f);
										tempReserveArmy.push_back(pullGame.at(3).at(k));
										pullGame.at(3).erase(pullGame.at(3).begin() + k);
										break;
									}
								}

								tempReserveArmy = player->setPlayerTempReserveArmy(tempReserveArmy);
							}
						}
						else if (tempReserveArmy.at(i)->getArmyID() == enumSquad::SQUAD_KNIGHT && tempReserveArmy.at(j)->getArmyID() == enumSquad::SQUAD_KNIGHT ||
							tempReserveArmy.at(j)->getArmyID() == enumSquad::SQUAD_PIKEMAN && tempReserveArmy.at(i)->getArmyID() == enumSquad::SQUAD_PIKEMAN)
						{
							continue;
						}
						else
						{
							if (player->getPlayerEra() > tempReserveArmy.at(i)->getEraName())
							{
								pullGame.at((int)tempReserveArmy.at(i)->getEraName()).push_back(tempReserveArmy.at(i));
								pullGame.at((int)tempReserveArmy.at(j)->getEraName()).push_back(tempReserveArmy.at(j));

								int tempIndexForEraName = (int)tempReserveArmy.at(i)->getEraName() + 1;
								enumSquad tempIndexForEnumSquad = tempReserveArmy.at(i)->getArmyUpgrade();

								if (i > j)
								{
									tempReserveArmy.erase(tempReserveArmy.begin() + i);
									tempReserveArmy.erase(tempReserveArmy.begin() + j);
								}
								else
								{
									tempReserveArmy.erase(tempReserveArmy.begin() + j);
									tempReserveArmy.erase(tempReserveArmy.begin() + i);
								}

								for (int k = 0; k < (int)pullGame.at(tempIndexForEraName).size(); k++)
								{
									if (pullGame.at(tempIndexForEraName).at(k)->getArmyID() == tempIndexForEnumSquad)
									{
										pullGame.at(tempIndexForEraName).at(k)->setArmySpawnCoordinateY(440.0f);
										tempReserveArmy.push_back(pullGame.at(tempIndexForEraName).at(k));
										pullGame.at(tempIndexForEraName).erase(pullGame.at(tempIndexForEraName).begin() + k);
										break;
									}
								}

								tempReserveArmy = player->setPlayerTempReserveArmy(tempReserveArmy);
							}
						}
					}
				}
			}
		}

		for (int i = 0; i < (int)tempActiveArmy.size(); i++)
		{
			for (int j = 0; j < (int)tempReserveArmy.size(); j++)
			{
				if (tempActiveArmy.at(i)->getArmyUpgrade() == tempReserveArmy.at(j)->getArmyUpgrade() && tempActiveArmy.at(i)->getArmyUpgrade() != enumSquad::NONE)
				{
					if (tempActiveArmy.at(i)->getArmyID() == enumSquad::SQUAD_KNIGHT && tempReserveArmy.at(j)->getArmyID() == enumSquad::SQUAD_PIKEMAN ||
						tempReserveArmy.at(j)->getArmyID() == enumSquad::SQUAD_KNIGHT && tempActiveArmy.at(i)->getArmyID() == enumSquad::SQUAD_PIKEMAN)
					{
						if (player->getPlayerEra() > tempActiveArmy.at(i)->getEraName())
						{
							pullGame.at(2).push_back(tempActiveArmy.at(i));
							pullGame.at(2).push_back(tempReserveArmy.at(j));
							if (i > j)
							{
								tempActiveArmy.erase(tempActiveArmy.begin() + i);
								tempReserveArmy.erase(tempReserveArmy.begin() + j);
							}
							else
							{
								tempReserveArmy.erase(tempReserveArmy.begin() + j);
								tempActiveArmy.erase(tempActiveArmy.begin() + i);
							}


							for (int k = 0; k < (int)pullGame.at(3).size(); k++)
							{
								if (pullGame.at(3).at(k)->getArmyID() == enumSquad::SQUAD_LANCER)
								{
									pullGame.at(3).at(k)->setArmySpawnCoordinateY(440.0f);
									tempActiveArmy.push_back(pullGame.at(3).at(k));
									pullGame.at(3).erase(pullGame.at(3).begin() + k);
									break;
								}
							}

							tempActiveArmy = player->setPlayerTempActiveArmy(tempActiveArmy);
							tempReserveArmy = player->setPlayerTempReserveArmy(tempReserveArmy);
						}
					}
					else if (tempActiveArmy.at(i)->getArmyID() == enumSquad::SQUAD_KNIGHT && tempReserveArmy.at(j)->getArmyID() == enumSquad::SQUAD_KNIGHT ||
						tempReserveArmy.at(j)->getArmyID() == enumSquad::SQUAD_PIKEMAN && tempActiveArmy.at(i)->getArmyID() == enumSquad::SQUAD_PIKEMAN)
					{
						continue;
					}
					else
					{
						if (player->getPlayerEra() > tempActiveArmy.at(i)->getEraName())
						{
							pullGame.at((int)tempActiveArmy.at(i)->getEraName()).push_back(tempActiveArmy.at(i));
							pullGame.at((int)tempReserveArmy.at(j)->getEraName()).push_back(tempReserveArmy.at(j));

							int tempIndexForEraName = (int)tempActiveArmy.at(i)->getEraName() + 1;
							enumSquad tempIndexForEnumSquad = tempActiveArmy.at(i)->getArmyUpgrade();

							if (i > j)
							{
								tempActiveArmy.erase(tempActiveArmy.begin() + i);
								tempReserveArmy.erase(tempReserveArmy.begin() + j);
							}
							else
							{
								tempReserveArmy.erase(tempReserveArmy.begin() + j);
								tempActiveArmy.erase(tempActiveArmy.begin() + i);
							}

							for (int k = 0; k < (int)pullGame.at(tempIndexForEraName).size(); k++)
							{
								if (pullGame.at(tempIndexForEraName).at(k)->getArmyID() == tempIndexForEnumSquad)
								{
									pullGame.at(tempIndexForEraName).at(k)->setArmySpawnCoordinateY(440.0f);
									tempActiveArmy.push_back(pullGame.at(tempIndexForEraName).at(k));
									pullGame.at(tempIndexForEraName).erase(pullGame.at(tempIndexForEraName).begin() + k);
									break;
								}
							}

							tempActiveArmy = player->setPlayerTempActiveArmy(tempActiveArmy);
							tempReserveArmy = player->setPlayerTempReserveArmy(tempReserveArmy);
						}
					}
				}

			}
		}

		window.clear();

		for (int i = 0; i < HEIGHT_MAP; i++)
		{
			for (int j = 0; j < WIDTH_MAP; j++)
			{
				if (ShopMap[i][j] == 'g')
				{
					mapSprite.setTextureRect(sf::IntRect(0, 0, 120, 120));
				}
				else
				{
					switch (player->getPlayerEra())
					{
					case enumEraName::ERA_ANCIENT: mapSprite.setTextureRect(sf::IntRect(120, 0, 120, 120)); break;
					case enumEraName::ERA_CLASSIC: mapSprite.setTextureRect(sf::IntRect(240, 0, 120, 120)); break;
					case enumEraName::ERA_MEDIVAL: mapSprite.setTextureRect(sf::IntRect(360, 0, 120, 120)); break;
					case enumEraName::ERA_RENAISSANCEE: mapSprite.setTextureRect(sf::IntRect(480, 0, 120, 120)); break;
					case enumEraName::ERA_INDUSTRIAL: mapSprite.setTextureRect(sf::IntRect(600, 0, 120, 120)); break;
					case enumEraName::ERA_MODERN: mapSprite.setTextureRect(sf::IntRect(720, 0, 120, 120)); break;
					case enumEraName::ERA_ATOMIC: mapSprite.setTextureRect(sf::IntRect(840, 0, 120, 120)); break;
					case enumEraName::ERA_INFORMATION: mapSprite.setTextureRect(sf::IntRect(960, 0, 120, 120)); break;
					case enumEraName::ERA_FUTURE: mapSprite.setTextureRect(sf::IntRect(1080, 0, 120, 120)); break;
					}
				}

				mapSprite.setPosition(j * 120.0f, i * 120.0f);
				window.draw(mapSprite);
			}
		}

		for (int i = 0; i < (const int)tempShopArmy.size(); i++)
		{
			shapeAttack.setPosition(tempShopArmy.at(i)->getArmySpawnCoordinateX() + 25, tempShopArmy.at(i)->getArmySpawnCoordinateY() + 125);
			shapeHealth.setPosition(tempShopArmy.at(i)->getArmySpawnCoordinateX() + 125, tempShopArmy.at(i)->getArmySpawnCoordinateY() + 125);

			if (tempShopArmy.at(i)->getArmyAttackNow() < 10)
			{
				textAttack.setPosition(tempShopArmy.at(i)->getArmySpawnCoordinateX() + 42, tempShopArmy.at(i)->getArmySpawnCoordinateY() + 125);
			}
			else
			{
				textAttack.setPosition(tempShopArmy.at(i)->getArmySpawnCoordinateX() + 32, tempShopArmy.at(i)->getArmySpawnCoordinateY() + 125);
			}

			if (tempShopArmy.at(i)->getArmyHealthNow() < 10)
			{
				textHealth.setPosition(tempShopArmy.at(i)->getArmySpawnCoordinateX() + 141, tempShopArmy.at(i)->getArmySpawnCoordinateY() + 125);
			}
			else
			{
				textHealth.setPosition(tempShopArmy.at(i)->getArmySpawnCoordinateX() + 133, tempShopArmy.at(i)->getArmySpawnCoordinateY() + 125);
			}

			textAttack.setString(std::to_string(tempShopArmy.at(i)->getArmyAttackNow()));
			textHealth.setString(std::to_string(tempShopArmy.at(i)->getArmyHealthNow()));

			window.draw(tempShopArmy.at(i)->getArmySprite());
			window.draw(shapeAttack);
			window.draw(shapeHealth);
			window.draw(textAttack);
			window.draw(textHealth);
		}

		for (int i = 0; i < (const int)tempActiveArmy.size(); i++)
		{
			shapeAttack.setPosition(tempActiveArmy.at(i)->getArmySpawnCoordinateX() + 25, tempActiveArmy.at(i)->getArmySpawnCoordinateY() + 125);
			shapeHealth.setPosition(tempActiveArmy.at(i)->getArmySpawnCoordinateX() + 125, tempActiveArmy.at(i)->getArmySpawnCoordinateY() + 125);

			if (tempActiveArmy.at(i)->getArmyAttackNow() < 10)
			{
				textAttack.setPosition(tempActiveArmy.at(i)->getArmySpawnCoordinateX() + 42, tempActiveArmy.at(i)->getArmySpawnCoordinateY() + 125);
			}
			else
			{
				textAttack.setPosition(tempActiveArmy.at(i)->getArmySpawnCoordinateX() + 32, tempActiveArmy.at(i)->getArmySpawnCoordinateY() + 125);
			}

			if (tempActiveArmy.at(i)->getArmyHealthNow() < 10)
			{
				textHealth.setPosition(tempActiveArmy.at(i)->getArmySpawnCoordinateX() + 141, tempActiveArmy.at(i)->getArmySpawnCoordinateY() + 125);
			}
			else
			{
				textHealth.setPosition(tempActiveArmy.at(i)->getArmySpawnCoordinateX() + 133, tempActiveArmy.at(i)->getArmySpawnCoordinateY() + 125);
			}

			textAttack.setString(std::to_string(tempActiveArmy.at(i)->getArmyAttackNow()));
			textHealth.setString(std::to_string(tempActiveArmy.at(i)->getArmyHealthNow()));

			window.draw(tempActiveArmy.at(i)->getArmySprite());
			window.draw(shapeAttack);
			window.draw(shapeHealth);
			window.draw(textAttack);
			window.draw(textHealth);
		}

		for (int i = 0; i < (const int)tempReserveArmy.size(); i++)
		{
			shapeAttack.setPosition(tempReserveArmy.at(i)->getArmySpawnCoordinateX() + 25, tempReserveArmy.at(i)->getArmySpawnCoordinateY() + 125);
			shapeHealth.setPosition(tempReserveArmy.at(i)->getArmySpawnCoordinateX() + 125, tempReserveArmy.at(i)->getArmySpawnCoordinateY() + 125);

			if (tempReserveArmy.at(i)->getArmyAttackNow() < 10)
			{
				textAttack.setPosition(tempReserveArmy.at(i)->getArmySpawnCoordinateX() + 42, tempReserveArmy.at(i)->getArmySpawnCoordinateY() + 125);
			}
			else
			{
				textAttack.setPosition(tempReserveArmy.at(i)->getArmySpawnCoordinateX() + 32, tempReserveArmy.at(i)->getArmySpawnCoordinateY() + 125);
			}

			if (tempReserveArmy.at(i)->getArmyHealthNow() < 10)
			{
				textHealth.setPosition(tempReserveArmy.at(i)->getArmySpawnCoordinateX() + 141, tempReserveArmy.at(i)->getArmySpawnCoordinateY() + 125);
			}
			else
			{
				textHealth.setPosition(tempReserveArmy.at(i)->getArmySpawnCoordinateX() + 133, tempReserveArmy.at(i)->getArmySpawnCoordinateY() + 125);
			}

			textAttack.setString(std::to_string(tempReserveArmy.at(i)->getArmyAttackNow()));
			textHealth.setString(std::to_string(tempReserveArmy.at(i)->getArmyHealthNow()));

			window.draw(tempReserveArmy.at(i)->getArmySprite());
			window.draw(shapeAttack);
			window.draw(shapeHealth);
			window.draw(textAttack);
			window.draw(textHealth);
		}

		if (!showInfoText)
		{
			window.draw(spriteInfo);
			window.draw(textInfo);
		}

		std::ostringstream playerCoinsString;
		playerCoinsString << player->getPlayerActionPointsNow() << " / " << player->getPlayerActionPointsMax();
		textCoinCount.setString(playerCoinsString.str());

		std::ostringstream playerRefreshCoinCount;
		playerRefreshCoinCount << 1;
		refreshText.setString(playerRefreshCoinCount.str());

		std::ostringstream playerUpCoinCount;
		playerUpCoinCount << player->getPlayerNextEraCost();
		upText.setString(playerUpCoinCount.str());

		std::ostringstream playerAddPlaceCoinCount;
		playerAddPlaceCoinCount << player->getPlayerAdditionalPlaceForSquadCost();
		addPlaceText.setString(playerAddPlaceCoinCount.str());


		window.draw(textPlayerHealthFirst);
		window.draw(healthSpriteFirst);
		window.draw(coinSprite);
		window.draw(textCoinCount);
		window.draw(refreshSprite);
		window.draw(refreshText);
		window.draw(upSprite);
		window.draw(upText);
		window.draw(addPlaceSprite);
		window.draw(addPlaceText);
		window.draw(battleSprite);

		if (isTextErrorTimer) 
		{
			textErrorTimer += time;
		}

		if (textErrorTimer <= 3000 && textErrorTimer != 0)
		{
			window.draw(textErrorCoinsCount);
		}
		else 
		{
			textErrorTimer = 0;
			isTextErrorTimer = false;
		}

		if (isDrawTrash) 
		{
			window.draw(deleteSprite);
		}

		window.display();
	}
}

void battle(std::vector <std::vector <Army*>>& pullGame, Player*& firstPlayer, Player*& secondPlayer)
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "War of Ages: Battle for Castle (BATTLE)", sf::Style::Fullscreen);

	sf::Texture mapTexture;
	mapTexture.loadFromFile("images/map.png");
	sf::Sprite mapSprite;
	mapSprite.setTexture(mapTexture);

	sf::Texture heatlhTexture;
	heatlhTexture.loadFromFile("images/heart.png");
	sf::Sprite healthSpriteFirst, healthSpriteSecond;
	healthSpriteFirst.setTexture(heatlhTexture);
	healthSpriteFirst.setScale(0.5f, 0.5f);
	healthSpriteSecond = healthSpriteFirst;
	healthSpriteFirst.setPosition(window.getSize().x - 200.0f, window.getSize().y - 100.0f);
	healthSpriteSecond.setPosition(window.getSize().x - 200.0f, 20.0f);

	std::vector <Army*> tempFirstArmy = firstPlayer->getPlayerActiveArmy();
	std::vector <Army*> tempSecondArmy = secondPlayer->getPlayerActiveArmy();

	sf::Font font;
	font.loadFromFile("16249.ttf");

	sf::Text textAttack;
	textAttack.setFont(font);
	textAttack.setOutlineColor(sf::Color::Black);
	textAttack.setStyle(sf::Text::Bold);

	sf::Text textPlayerHealthFirst = textAttack;
	textPlayerHealthFirst.setFillColor(sf::Color(155, 17, 30));
	textPlayerHealthFirst.setOutlineThickness(2);
	textPlayerHealthFirst.setOutlineColor(sf::Color::White);
	textPlayerHealthFirst.setCharacterSize(60);
	sf::Text textPlayerHealthSecond = textPlayerHealthFirst;
	textPlayerHealthFirst.setPosition(window.getSize().x - 70.0f, window.getSize().y - 100.0f);
	textPlayerHealthSecond.setPosition(window.getSize().x - 70.0f, 20.0f);

	textPlayerHealthFirst.setString(std::to_string(firstPlayer->getPlayerHealth()));
	textPlayerHealthSecond.setString(std::to_string(secondPlayer->getPlayerHealth()));

	sf::Text textInfo = textAttack;
	textInfo.setCharacterSize(25);
	textInfo.setOutlineThickness(1.5f);
	textInfo.setPosition(20.0f, 10.0f);

	textAttack.setCharacterSize(40);
	textAttack.setOutlineThickness(4);
	sf::Text textHealth = textAttack;

	sf::CircleShape shapeAttack;
	shapeAttack.setRadius(25.f);
	shapeAttack.setOutlineThickness(4);
	sf::CircleShape shapeHealth = shapeAttack;
	shapeAttack.setFillColor(sf::Color(255, 127, 80));
	shapeHealth.setFillColor(sf::Color(100, 149, 237));

	sf::Texture textureInfo;
	textureInfo.loadFromFile("images/infobackground.jpg");
	sf::Sprite spriteInfo;
	spriteInfo.setTexture(textureInfo);
	spriteInfo.setTextureRect(sf::IntRect(0, 0, 340, 510));
	spriteInfo.setScale(1.4f, 0.8f);
		
	bool isSpriteMove = false;
	float dXSpriteMove = 0;
	int spriteMoveParameter = 0;
	bool isPressedForMove = false;

	bool showInfoText = true;
	bool showInfoReRenderFirst = true, showInfoReRenderSecond = true;
	int showInfoParameter = 0;

	for (int i = 0; i < (const int)tempFirstArmy.size(); i++)
	{
		tempFirstArmy.at(i)->setArmySpawnCoordinateY(800.0);
	}

	for (int i = 0; i < (const int)tempSecondArmy.size(); i++)
	{
		tempSecondArmy.at(i)->setArmySpawnCoordinateY(80.0);
	}

	tempFirstArmy = firstPlayer->setPlayerTempActiveArmy(tempFirstArmy);
	tempSecondArmy = secondPlayer->setPlayerTempActiveArmy(tempSecondArmy);

	sf::Clock clock;

	while (window.isOpen())
	{
		float time = (float)clock.getElapsedTime().asMicroseconds();

		clock.restart();
		time = time / 800;

		sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			if (showInfoReRenderFirst)
			{
				for (int i = 0; i < (int)tempFirstArmy.size(); i++)
				{
					if (tempFirstArmy.at(i)->getArmySprite().getGlobalBounds().contains((float)mousePosition.x, (float)mousePosition.y))
					{
						showInfoParameter = i;
						showInfoReRenderFirst = false;

						switch (showInfoText)
						{
						case true:
							textInfo.setString(getStringTextInfo(tempFirstArmy.at(i)));
							showInfoText = false;
							break;

						case false:
							textInfo.setString("");
							showInfoText = true;
							break;
						}

						break;
					}
				}
			}

			if (showInfoReRenderSecond)
			{
				for (int i = 0; i < (int)tempSecondArmy.size(); i++)
				{
					if (tempSecondArmy.at(i)->getArmySprite().getGlobalBounds().contains((float)mousePosition.x, (float)mousePosition.y))
					{
						showInfoParameter = i;
						showInfoReRenderSecond = false;

						switch (showInfoText)
						{
						case true:
							textInfo.setString(getStringTextInfo(tempSecondArmy.at(i)));
							showInfoText = false;
							break;

						case false:
							textInfo.setString("");
							showInfoText = true;
							break;
						}

						break;
					}
				}
			}

			if (!showInfoReRenderFirst)
			{
				if (!tempFirstArmy.at(showInfoParameter)->getArmySprite().getGlobalBounds().contains((float)mousePosition.x, (float)mousePosition.y))
				{
					showInfoReRenderFirst = true;					
					showInfoText = true;
				}
			}

			if (!showInfoReRenderSecond)
			{
				if (!tempSecondArmy.at(showInfoParameter)->getArmySprite().getGlobalBounds().contains((float)mousePosition.x, (float)mousePosition.y))
				{
					showInfoReRenderSecond = true;
					showInfoText = true;
				}
			}
		}

		if (isSpriteMove)
		{
			tempFirstArmy.at(spriteMoveParameter)->setArmySpawnCoordinateX(mousePosition.x - dXSpriteMove);
			firstPlayer->setPlayerActiveArmy(tempFirstArmy);
		}

		window.clear();

		for (int i = 0; i < HEIGHT_MAP; i++)
		{
			for (int j = 0; j < WIDTH_MAP; j++)
			{
				if (TileMap[i][j] == 'g')
				{
					mapSprite.setTextureRect(sf::IntRect(0, 0, 120, 120));
				}
				else if (TileMap[i][j] == 'f')
				{
					switch (firstPlayer->getPlayerEra())
					{
					case enumEraName::ERA_ANCIENT: mapSprite.setTextureRect(sf::IntRect(120, 0, 120, 120)); break;
					case enumEraName::ERA_CLASSIC: mapSprite.setTextureRect(sf::IntRect(240, 0, 120, 120)); break;
					case enumEraName::ERA_MEDIVAL: mapSprite.setTextureRect(sf::IntRect(360, 0, 120, 120)); break;
					case enumEraName::ERA_RENAISSANCEE: mapSprite.setTextureRect(sf::IntRect(480, 0, 120, 120)); break;
					case enumEraName::ERA_INDUSTRIAL: mapSprite.setTextureRect(sf::IntRect(600, 0, 120, 120)); break;
					case enumEraName::ERA_MODERN: mapSprite.setTextureRect(sf::IntRect(720, 0, 120, 120)); break;
					case enumEraName::ERA_ATOMIC: mapSprite.setTextureRect(sf::IntRect(840, 0, 120, 120)); break;
					case enumEraName::ERA_INFORMATION: mapSprite.setTextureRect(sf::IntRect(960, 0, 120, 120)); break;
					case enumEraName::ERA_FUTURE: mapSprite.setTextureRect(sf::IntRect(1080, 0, 120, 120)); break;
					}
				}
				else
				{
					switch (secondPlayer->getPlayerEra())
					{
					case enumEraName::ERA_ANCIENT: mapSprite.setTextureRect(sf::IntRect(120, 0, 120, 120)); break;
					case enumEraName::ERA_CLASSIC: mapSprite.setTextureRect(sf::IntRect(240, 0, 120, 120)); break;
					case enumEraName::ERA_MEDIVAL: mapSprite.setTextureRect(sf::IntRect(360, 0, 120, 120)); break;
					case enumEraName::ERA_RENAISSANCEE: mapSprite.setTextureRect(sf::IntRect(480, 0, 120, 120)); break;
					case enumEraName::ERA_INDUSTRIAL: mapSprite.setTextureRect(sf::IntRect(600, 0, 120, 120)); break;
					case enumEraName::ERA_MODERN: mapSprite.setTextureRect(sf::IntRect(720, 0, 120, 120)); break;
					case enumEraName::ERA_ATOMIC: mapSprite.setTextureRect(sf::IntRect(840, 0, 120, 120)); break;
					case enumEraName::ERA_INFORMATION: mapSprite.setTextureRect(sf::IntRect(960, 0, 120, 120)); break;
					case enumEraName::ERA_FUTURE: mapSprite.setTextureRect(sf::IntRect(1080, 0, 120, 120)); break;
					}
				}

				mapSprite.setPosition(j * 120.0f, i * 120.0f);
				window.draw(mapSprite);
			}
		}

		for (int i = 0; i < (const int)tempFirstArmy.size(); i++)
		{
			shapeAttack.setPosition(tempFirstArmy.at(i)->getArmySpawnCoordinateX() + 25, tempFirstArmy.at(i)->getArmySpawnCoordinateY() + 125);
			shapeHealth.setPosition(tempFirstArmy.at(i)->getArmySpawnCoordinateX() + 125, tempFirstArmy.at(i)->getArmySpawnCoordinateY() + 125);

			if (tempFirstArmy.at(i)->getArmyAttackNow() < 10)
			{
				textAttack.setPosition(tempFirstArmy.at(i)->getArmySpawnCoordinateX() + 42, tempFirstArmy.at(i)->getArmySpawnCoordinateY() + 125);
			}
			else
			{
				textAttack.setPosition(tempFirstArmy.at(i)->getArmySpawnCoordinateX() + 32, tempFirstArmy.at(i)->getArmySpawnCoordinateY() + 125);
			}

			if (tempFirstArmy.at(i)->getArmyHealthNow() < 10)
			{
				textHealth.setPosition(tempFirstArmy.at(i)->getArmySpawnCoordinateX() + 141, tempFirstArmy.at(i)->getArmySpawnCoordinateY() + 125);
			}
			else
			{
				textHealth.setPosition(tempFirstArmy.at(i)->getArmySpawnCoordinateX() + 133, tempFirstArmy.at(i)->getArmySpawnCoordinateY() + 125);
			}

			textAttack.setString(std::to_string(tempFirstArmy.at(i)->getArmyAttackNow()));
			textHealth.setString(std::to_string(tempFirstArmy.at(i)->getArmyHealthNow()));

			window.draw(tempFirstArmy.at(i)->getArmySprite());
			window.draw(shapeAttack);
			window.draw(shapeHealth);
			window.draw(textAttack);
			window.draw(textHealth);
		}

		for (int i = 0; i < (const int)tempSecondArmy.size(); i++)
		{
			shapeAttack.setPosition(tempSecondArmy.at(i)->getArmySpawnCoordinateX() + 25, tempSecondArmy.at(i)->getArmySpawnCoordinateY() + 125);
			shapeHealth.setPosition(tempSecondArmy.at(i)->getArmySpawnCoordinateX() + 125, tempSecondArmy.at(i)->getArmySpawnCoordinateY() + 125);

			if (tempSecondArmy.at(i)->getArmyAttackNow() < 10)
			{
				textAttack.setPosition(tempSecondArmy.at(i)->getArmySpawnCoordinateX() + 42, tempSecondArmy.at(i)->getArmySpawnCoordinateY() + 125);
			}
			else
			{
				textAttack.setPosition(tempSecondArmy.at(i)->getArmySpawnCoordinateX() + 32, tempSecondArmy.at(i)->getArmySpawnCoordinateY() + 125);
			}

			if (tempSecondArmy.at(i)->getArmyHealthNow() < 10)
			{
				textHealth.setPosition(tempSecondArmy.at(i)->getArmySpawnCoordinateX() + 141, tempSecondArmy.at(i)->getArmySpawnCoordinateY() + 125);
			}
			else
			{
				textHealth.setPosition(tempSecondArmy.at(i)->getArmySpawnCoordinateX() + 133, tempSecondArmy.at(i)->getArmySpawnCoordinateY() + 125);
			}

			textAttack.setString(std::to_string(tempSecondArmy.at(i)->getArmyAttackNow()));
			textHealth.setString(std::to_string(tempSecondArmy.at(i)->getArmyHealthNow()));

			window.draw(tempSecondArmy.at(i)->getArmySprite());
			window.draw(shapeAttack);
			window.draw(shapeHealth);
			window.draw(textAttack);
			window.draw(textHealth);
		}

		if (!showInfoText)
		{
			window.draw(spriteInfo);
			window.draw(textInfo);
		}

		window.draw(textPlayerHealthFirst);
		window.draw(textPlayerHealthSecond);
		window.draw(healthSpriteFirst);
		window.draw(healthSpriteSecond);

		window.display();
	}
}

void gameProcess(std::vector <std::vector <Army*>>& pullGame)
{
	menu();
	Player* firstPlayer = new Player();
	Player* secondPlayer = new Player();
	std::vector <Player*> playersVector;
	bool isPlayerDead = false;
	playersVector.push_back(firstPlayer);
	playersVector.push_back(secondPlayer);
	while (!isPlayerDead)
	{
		for (int i = 0; i < (int)playersVector.size(); i++)
		{
			if (playersVector.at(i)->getPlayerHealth() > 0)
			{
				shop(pullGame, playersVector.at(i));
			}
			else
			{
				isPlayerDead = true;
				break;
			}
		}
		battle(pullGame, playersVector.at(0), playersVector.at(1));
	}
}

int main()
{
	setlocale(LC_ALL, "");
	std::vector <std::vector <Army*>> pullGame(9);
	pullGame = initializePullSquads();
	gameProcess(pullGame);
	return 0;
};