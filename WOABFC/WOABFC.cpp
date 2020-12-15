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
		tempShopArmy.at(0)->setArmySpawnCoordinates(735.0, 80.0);
		tempShopArmy.at(1)->setArmySpawnCoordinates(985.0, 80.0);
		break;
	case 3:
		tempShopArmy.at(0)->setArmySpawnCoordinates(610.0, 80.0);
		tempShopArmy.at(1)->setArmySpawnCoordinates(860.0, 80.0);
		tempShopArmy.at(2)->setArmySpawnCoordinates(1110.0, 80.0);
		break;
	case 4:
		tempShopArmy.at(0)->setArmySpawnCoordinates(485.0, 80.0);
		tempShopArmy.at(1)->setArmySpawnCoordinates(735.0, 80.0);
		tempShopArmy.at(2)->setArmySpawnCoordinates(985.0, 80.0);
		tempShopArmy.at(3)->setArmySpawnCoordinates(1235.0, 80.0);
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
				if (event.type == sf::Event::Closed || event.type == sf::Event::LostFocus)
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

void shop(std::vector <std::vector <Army*>> &pullGame, Player* &firstPlayer)
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

	sf::Texture refreshTexture;
	refreshTexture.loadFromFile("images/refresh.png");
	sf::Sprite refreshSprite;
	refreshSprite.setTexture(refreshTexture);
	refreshSprite.setScale(0.25f, 0.25f);
	refreshSprite.setPosition(window.getSize().x - 296.0f, 20.0f);

	sf::Texture upTexture;
	upTexture.loadFromFile("images/up.png");
	sf::Sprite upSprite;
	upSprite.setTexture(upTexture);
	upSprite.setScale(0.25f, 0.25f);
	upSprite.setPosition(window.getSize().x - 148.0f, 20.0f);


	sf::Font font;
	font.loadFromFile("16249.ttf");

	sf::Text textAttack;
	textAttack.setFont(font);
	textAttack.setOutlineColor(sf::Color::Black);
	textAttack.setStyle(sf::Text::Bold);

	sf::Text textPlayerHealthFirst = textAttack;
	textPlayerHealthFirst.setFillColor(sf::Color::Red);
	textPlayerHealthFirst.setOutlineThickness(3);
	textPlayerHealthFirst.setOutlineColor(sf::Color::White);
	textPlayerHealthFirst.setCharacterSize(60);
	textPlayerHealthFirst.setPosition(window.getSize().x - 70.0f, window.getSize().y - 90.0f);
	textPlayerHealthFirst.setString(std::to_string(firstPlayer->getPlayerHealth()));

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

	std::vector <Army*> tempShopArmy;
	refreshShopSquads(pullGame, firstPlayer, tempShopArmy);

	std::vector <Army*> tempActiveArmy;
	std::vector <Army*> tempReserveArmy;

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
						for (int i = 0; i < (int)tempActiveArmy.size(); i++)
						{
							if (i < spriteMoveParameter)
							{
								if ((float)mousePosition.x < tempActiveArmy.at(i)->getArmySpawnCoordinateX() + 100)
								{
									std::swap(tempActiveArmy[i], tempActiveArmy[spriteMoveParameter]);
									firstPlayer->setPlayerActiveArmy(tempActiveArmy);
									firstPlayer->setOrderOfActiveArmy();
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
									firstPlayer->setPlayerActiveArmy(tempActiveArmy);
									firstPlayer->setOrderOfActiveArmy();
									break;
								}
							}
						}

						isSpriteMoveActive = false;
						firstPlayer->setOrderOfActiveArmy();

						for (size_t i = 0; i < tempActiveArmy.size(); i++)
						{
							tempActiveArmy.at(i)->setArmySpawnCoordinateY(440.0);
						}

						firstPlayer->setPlayerActiveArmy(tempActiveArmy);
						isPressedForMoveActive = false;
					}

					if (isPressedForMoveReserve)
					{
						for (int i = 0; i < (int)tempReserveArmy.size(); i++)
						{
							if (i < spriteMoveParameter)
							{
								if ((float)mousePosition.x < tempReserveArmy.at(i)->getArmySpawnCoordinateX() + 100)
								{
									std::swap(tempReserveArmy[i], tempReserveArmy[spriteMoveParameter]);
									firstPlayer->setPlayerReserveArmy(tempReserveArmy);
									firstPlayer->setOrderOfReserveArmy();
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
									firstPlayer->setPlayerReserveArmy(tempReserveArmy);
									firstPlayer->setOrderOfReserveArmy();
									break;
								}
							}
						}

						isSpriteMoveReserve = false;
						firstPlayer->setOrderOfReserveArmy();
						firstPlayer->setPlayerReserveArmy(tempReserveArmy);
						isPressedForMoveReserve = false;
					}

					if (refreshSprite.getGlobalBounds().contains((float)mousePosition.x, (float)mousePosition.y))
					{
						refreshShopSquads(pullGame, firstPlayer, tempShopArmy);
					}

					if (upSprite.getGlobalBounds().contains((float)mousePosition.x, (float)mousePosition.y))
					{
						switch (firstPlayer->getPlayerEra())
						{
						case enumEraName::ERA_ANCIENT:
							firstPlayer->setPlayerEra(enumEraName::ERA_CLASSIC); break;
						case enumEraName::ERA_CLASSIC:
							firstPlayer->setPlayerEra(enumEraName::ERA_MEDIVAL); break;
						case enumEraName::ERA_MEDIVAL:
							firstPlayer->setPlayerEra(enumEraName::ERA_RENAISSANCEE); break;
						case enumEraName::ERA_RENAISSANCEE:
							firstPlayer->setPlayerEra(enumEraName::ERA_INDUSTRIAL); break;
						case enumEraName::ERA_INDUSTRIAL:
							firstPlayer->setPlayerEra(enumEraName::ERA_MODERN); break;
						case enumEraName::ERA_MODERN:
							firstPlayer->setPlayerEra(enumEraName::ERA_ATOMIC); break;
						case enumEraName::ERA_ATOMIC:
							firstPlayer->setPlayerEra(enumEraName::ERA_INFORMATION); break;
						case enumEraName::ERA_INFORMATION:
							firstPlayer->setPlayerEra(enumEraName::ERA_FUTURE); break;
						default:
							break;
						}
					}
				}

				if (event.key.code == sf::Mouse::Right)
				{
					for (int i = 0; i < (int)tempShopArmy.size(); i++)
					{
						if (tempShopArmy.at(i)->getArmySprite().getGlobalBounds().contains((float)mousePosition.x, (float)mousePosition.y))
						{
							tempReserveArmy.push_back(tempShopArmy.at(i));
							tempShopArmy.erase(tempShopArmy.begin() + i);
							setOrderOfShopArmy(tempShopArmy);
							tempReserveArmy = firstPlayer->setPlayerTempReserveArmy(tempReserveArmy);
							break;
						}
					}

					for (int i = 0; i < (int)tempReserveArmy.size(); i++)
					{
						if (tempReserveArmy.at(i)->getArmySprite().getGlobalBounds().contains((float)mousePosition.x, (float)mousePosition.y))
						{
							tempReserveArmy.at(i)->setArmySpawnCoordinateY(430.0);
							tempActiveArmy.push_back(tempReserveArmy.at(i));
							tempReserveArmy.erase(tempReserveArmy.begin() + i);
							tempReserveArmy = firstPlayer->setPlayerTempReserveArmy(tempReserveArmy);
							tempActiveArmy = firstPlayer->setPlayerTempActiveArmy(tempActiveArmy);
							break;
						}
					}

					for (int i = 0; i < (int)tempActiveArmy.size(); i++)
					{
						if (tempActiveArmy.at(i)->getArmySprite().getGlobalBounds().contains((float)mousePosition.x, (float)mousePosition.y))
						{
							switch (tempActiveArmy.at(i)->getEraName())
							{
							case enumEraName::ERA_ANCIENT:
								pullGame.at(0).push_back(tempActiveArmy.at(i)); break;
							case enumEraName::ERA_CLASSIC:
								pullGame.at(1).push_back(tempActiveArmy.at(i)); break;
							case enumEraName::ERA_MEDIVAL:
								pullGame.at(2).push_back(tempActiveArmy.at(i)); break;
							case enumEraName::ERA_RENAISSANCEE:
								pullGame.at(3).push_back(tempActiveArmy.at(i)); break;
							case enumEraName::ERA_INDUSTRIAL:
								pullGame.at(4).push_back(tempActiveArmy.at(i)); break;
							case enumEraName::ERA_MODERN:
								pullGame.at(5).push_back(tempActiveArmy.at(i)); break;
							case enumEraName::ERA_ATOMIC:
								pullGame.at(6).push_back(tempActiveArmy.at(i)); break;
							case enumEraName::ERA_INFORMATION:
								pullGame.at(7).push_back(tempActiveArmy.at(i)); break;
							case enumEraName::ERA_FUTURE:
								pullGame.at(8).push_back(tempActiveArmy.at(i)); break;
							default:
								break;
							}
							tempActiveArmy.erase(tempActiveArmy.begin() + i);
							tempActiveArmy = firstPlayer->setPlayerTempActiveArmy(tempActiveArmy);
							break;
						}
					}
				}
			}

			if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::Escape) 
				{
					window.close(); gameProcess(pullGame);
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
				catch(const std::out_of_range& oor)
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

		window.draw(textPlayerHealthFirst);
		window.draw(healthSpriteFirst);
		window.draw(refreshSprite);
		window.draw(upSprite);

		window.display();
	}

}

void battle(std::vector <std::vector <Army*>>& pullGame)
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

	std::vector <Army*> tempFirstArmy;
	std::vector <Army*> tempSecondArmy;

	Player* firstPlayer = new Player();
	firstPlayer->setPlayerEra(enumEraName::ERA_FUTURE);
	Player* secondPlayer = new Player();
	secondPlayer->setPlayerEra(enumEraName::ERA_INFORMATION);

	sf::Font font;
	font.loadFromFile("16249.ttf");

	sf::Text textAttack;
	textAttack.setFont(font);
	textAttack.setOutlineColor(sf::Color::Black);
	textAttack.setStyle(sf::Text::Bold);

	sf::Text textPlayerHealthFirst = textAttack;
	textPlayerHealthFirst.setFillColor(sf::Color::Red);
	textPlayerHealthFirst.setOutlineThickness(3);
	textPlayerHealthFirst.setOutlineColor(sf::Color::White);
	textPlayerHealthFirst.setCharacterSize(60);
	sf::Text textPlayerHealthSecond = textPlayerHealthFirst;
	textPlayerHealthFirst.setPosition(window.getSize().x - 70.0f, window.getSize().y - 90.0f);
	textPlayerHealthSecond.setPosition(window.getSize().x - 70.0f, 30.0f);

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

	tempFirstArmy.push_back(pullGame.at(3).at(32));
	tempFirstArmy.push_back(pullGame.at(8).at(6));

	tempSecondArmy.push_back(pullGame.at(7).at(0));
	tempSecondArmy.push_back(pullGame.at(7).at(8));
	tempSecondArmy.push_back(pullGame.at(7).at(16));
	tempSecondArmy.push_back(pullGame.at(7).at(24));

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

			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.key.code == sf::Mouse::Left)
				{
					for (int i = 0; i < (int)tempFirstArmy.size(); i++)
					{
						if (tempFirstArmy.at(i)->getArmySprite().getGlobalBounds().contains((float)mousePosition.x, (float)mousePosition.y))
						{
							isPressedForMove = true;
							spriteMoveParameter = i;
							dXSpriteMove = mousePosition.x - tempFirstArmy.at(spriteMoveParameter)->getArmySpawnCoordinateX();
							isSpriteMove = true;
							break;
						}
					}
				}
			}

			if (event.type == sf::Event::MouseButtonReleased)
			{
				if (event.key.code == sf::Mouse::Left)
				{
					if (isPressedForMove)
					{
						for (int i = 0; i < (int)tempFirstArmy.size(); i++)
						{
							if (i < spriteMoveParameter)
							{
								if ((float)mousePosition.x < tempFirstArmy.at(i)->getArmySpawnCoordinateX() + 100)
								{
									std::swap(tempFirstArmy[i], tempFirstArmy[spriteMoveParameter]);
									firstPlayer->setPlayerActiveArmy(tempFirstArmy);
									firstPlayer->setOrderOfActiveArmy();
									break;
								}
							}
						}

						for (int i = tempFirstArmy.size() - 1; i > -1; i--)
						{
							if (i > spriteMoveParameter)
							{
								if ((float)mousePosition.x > tempFirstArmy.at(i)->getArmySpawnCoordinateX() + 100)
								{
									std::swap(tempFirstArmy[i], tempFirstArmy[spriteMoveParameter]);
									firstPlayer->setPlayerActiveArmy(tempFirstArmy);
									firstPlayer->setOrderOfActiveArmy();
									break;
								}
							}
						}

						isSpriteMove = false;
						firstPlayer->setOrderOfActiveArmy();

						for (size_t i = 0; i < tempFirstArmy.size(); i++)
						{
							tempFirstArmy.at(i)->setArmySpawnCoordinateY(800.0);
						}

						firstPlayer->setPlayerActiveArmy(tempFirstArmy);
						isPressedForMove = false;
					}
				}
			}

			if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::Escape)
				{
					window.close(); gameProcess(pullGame);
				}
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
	shop(pullGame, firstPlayer);
	//battle(pullGame);	
}

int main()
{
	setlocale(LC_ALL, "");
	std::vector <std::vector <Army*>> pullGame(9);
	pullGame = initializePullSquads();
	gameProcess(pullGame);
	return 0;
};