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


std::vector <std::vector <Army*>> initializePullSquads()
{
	std::thread threadLoading([]()
	{		
		sf::RenderWindow window(sf::VideoMode(1920, 1080), "War of Ages: Battle for Castle (LOADING)", sf::Style::Fullscreen);
		int randomNumberBackground;
		srand(time(NULL));
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

			window.display();
		}
	});

	std::vector <std::vector <Army*>> pullGame(9);
	std::vector <Army*> pullAncient(64), pullClassic(64), pullMedival(64), pullRenaissancee(48), pullIndustrial(48), pullModern(48), pullAtomic(32), pullInfromation(32), pullFuture(12);
	Army* addSquadUnit;

	std::thread threadAncient([&addSquadUnit, &pullAncient]()
	{
		for (size_t i = 0; i < 16; i++)
		{
			pullAncient.at(i) = new Squad(enumSquad::SQUAD_WARRIOR);
			pullAncient.at(i + 16) = new Squad(enumSquad::SQUAD_ARCHER);
			pullAncient.at(i + 32) = new Squad(enumSquad::SQUAD_HOURSEARCHER);
			pullAncient.at(i + 48) = new Squad(enumSquad::SQUAD_SPEARMAN);
		}
	});

	std::thread threadClassic([&addSquadUnit, &pullClassic]()
	{
		for (size_t i = 0; i < 16; i++)
		{
			pullClassic.at(i) = new Squad(enumSquad::SQUAD_SWORDSMAN);
			pullClassic.at(i + 16) = new Squad(enumSquad::SQUAD_LONGBOWARCHER);
			pullClassic.at(i + 32) = new Squad(enumSquad::SQUAD_HORSEMAN);
			pullClassic.at(i + 48) = new Squad(enumSquad::SQUAD_HOPLITE);
		}
	});

	std::thread threadMedival([&addSquadUnit, &pullMedival]()
	{
		for (size_t i = 0; i < 16; i++)
		{
			pullMedival.at(i) = new Squad(enumSquad::SQUAD_LONGSWORDSMAN);
			pullMedival.at(i + 16) = new Squad(enumSquad::SQUAD_CROSSBOWMAN);
			pullMedival.at(i + 32) = new Squad(enumSquad::SQUAD_KNIGHT);
			pullMedival.at(i + 48) = new Squad(enumSquad::SQUAD_PIKEMAN);
		}
	});

	std::thread threadRenaissancee([&addSquadUnit, &pullRenaissancee]()
	{
		for (size_t i = 0; i < 16; i++)
		{
			pullRenaissancee.at(i) = new Squad(enumSquad::SQUAD_HARQUEBUSIER);
			pullRenaissancee.at(i + 16) = new Squad(enumSquad::SQUAD_CANNON);
			pullRenaissancee.at(i + 32) = new Squad(enumSquad::SQUAD_LANCER);
		}
	});

	std::thread threadIndustrial([&addSquadUnit, &pullIndustrial]()
	{
		for (size_t i = 0; i < 16; i++)
		{
			pullIndustrial.at(i) = new Squad(enumSquad::SQUAD_MUSKETEER);
			pullIndustrial.at(i + 16) = new Squad(enumSquad::SQUAD_GATLING);
			pullIndustrial.at(i + 32) = new Squad(enumSquad::SQUAD_CAVALRY);
		}
	});

	std::thread threadModern([&addSquadUnit, &pullModern]()
	{
		for (size_t i = 0; i < 12; i++)
		{
			pullModern.at(i) = new Squad(enumSquad::SQUAD_INFANTRYMAN);
			pullModern.at(i + 12) = new Squad(enumSquad::SQUAD_MACHINGGUN);
			pullModern.at(i + 24) = new Squad(enumSquad::SQUAD_TANKETTE);
			pullModern.at(i + 36) = new Squad(enumSquad::SQUAD_ARTBATTERY);
		}
	});

	std::thread threadAtomic([&addSquadUnit, &pullAtomic]()
	{
		for (size_t i = 0; i < 8; i++)
		{
			pullAtomic.at(i) = new Squad(enumSquad::SQUAD_SEAINFANTRYMAN);
			pullAtomic.at(i + 8) = new Squad(enumSquad::SQUAD_BAZOOKA);
			pullAtomic.at(i + 16) = new Squad(enumSquad::SQUAD_TANK);
			pullAtomic.at(i + 24) = new Squad(enumSquad::SQUAD_ANTITANKCANNON);
		}
	});

	std::thread threadInformation([&addSquadUnit, &pullInfromation]()
	{
		for (size_t i = 0; i < 8; i++)
		{
			pullInfromation.at(i) = new Squad(enumSquad::SQUAD_MOTORIZEDINFANTRY);
			pullInfromation.at(i + 8) = new Squad(enumSquad::SQUAD_ROCKET);
			pullInfromation.at(i + 16) = new Squad(enumSquad::SQUAD_MODERNTANK);
			pullInfromation.at(i + 24) = new Squad(enumSquad::SQUAD_ROCKETARTILLERY);
		}
	});

	std::thread threadFuture([&addSquadUnit, &pullFuture]()
	{
		for (size_t i = 0; i < 6; i++)
		{
			pullFuture.at(i) = new Squad(enumSquad::SQUAD_FUTURESMAN);
			pullFuture.at(i + 6) = new Squad(enumSquad::SQUAD_ROBOT);
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

	return pullGame;
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
	healthSpriteFirst.setPosition(window.getSize().x - 200, window.getSize().y - 100);
	healthSpriteSecond.setPosition(window.getSize().x - 200, 20);

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
	textPlayerHealthFirst.setPosition(window.getSize().x - 70, window.getSize().y - 90);
	textPlayerHealthSecond.setPosition(window.getSize().x - 70, 30);

	textPlayerHealthFirst.setString(std::to_string(firstPlayer->getPlayerHealth()));
	textPlayerHealthSecond.setString(std::to_string(secondPlayer->getPlayerHealth()));

	sf::Text textInfo = textAttack;
	textInfo.setCharacterSize(25);
	textInfo.setOutlineThickness(1.5f);
	textInfo.setPosition(window.getSize().x / 2.0f - 350.0f, window.getSize().y / 2.0f - 168.0f);

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
	spriteInfo.setScale(2.0f, 0.7f);
	spriteInfo.setPosition(window.getSize().x / 2.0f - 380.0f, window.getSize().y / 2.0f - 178.0f);

	bool isFirstSpawn = true;
	bool isSpriteMove = false;
	float dXSpriteMove = 0;
	float dYSpriteMove = 0;
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

	tempFirstArmy = firstPlayer->setPlayerTempArmy(tempFirstArmy);
	tempSecondArmy = secondPlayer->setPlayerTempArmy(tempSecondArmy);

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
							dYSpriteMove = mousePosition.y - tempFirstArmy.at(spriteMoveParameter)->getArmySpawnCoordinateY();
							isSpriteMove = true;
							break;
						}
					}

					for (int i = 0; i < (int)tempSecondArmy.size(); i++)
					{
						if (tempSecondArmy.at(i)->getArmySprite().getGlobalBounds().contains((float)mousePosition.x, (float)mousePosition.y))
						{
							isPressedForMove = true;
							spriteMoveParameter = i;
							dXSpriteMove = mousePosition.x - tempSecondArmy.at(spriteMoveParameter)->getArmySpawnCoordinateX();
							dYSpriteMove = mousePosition.y - tempSecondArmy.at(spriteMoveParameter)->getArmySpawnCoordinateY();
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
									firstPlayer->setOrderOfArmy();
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
									firstPlayer->setOrderOfArmy();
									break;
								}
							}
						}

						isSpriteMove = false;
						firstPlayer->setOrderOfArmy();

						for (size_t i = 0; i < tempFirstArmy.size(); i++)
						{
							tempFirstArmy.at(i)->setArmySpawnCoordinateY(800.0);
						}

						firstPlayer->setPlayerActiveArmy(tempFirstArmy);
						isPressedForMove = false;
					}
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

			if ((int)tempSecondArmy.size() > showInfoParameter)
			{
				if ((int)tempFirstArmy.size() > showInfoParameter)
				{
					if (!tempSecondArmy.at(showInfoParameter)->getArmySprite().getGlobalBounds().contains((float)mousePosition.x, (float)mousePosition.y) && !tempFirstArmy.at(showInfoParameter)->getArmySprite().getGlobalBounds().contains((float)mousePosition.x, (float)mousePosition.y))
					{
						showInfoReRenderFirst = true;
						showInfoReRenderSecond = true;
						showInfoText = true;
					}
				}
				else
				{
					if (!tempSecondArmy.at(showInfoParameter)->getArmySprite().getGlobalBounds().contains((float)mousePosition.x, (float)mousePosition.y))
					{
						showInfoReRenderFirst = true;
						showInfoReRenderSecond = true;
						showInfoText = true;
					}
				}
			}
			else
			{
				if (!tempFirstArmy.at(showInfoParameter)->getArmySprite().getGlobalBounds().contains((float)mousePosition.x, (float)mousePosition.y))
				{
					showInfoReRenderFirst = true;
					showInfoReRenderSecond = true;
					showInfoText = true;
				}
			}
		}

		if (isSpriteMove)
		{
			tempFirstArmy.at(spriteMoveParameter)->setArmySpawnCoordinates(mousePosition.x - dXSpriteMove, mousePosition.y - dYSpriteMove);
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

		isFirstSpawn = false;
		window.display();
	}
}

int main()
{
	setlocale(LC_ALL, "");
	menu();
	std::vector <std::vector <Army*>> pullGame(9);
	pullGame = initializePullSquads();
	battle(pullGame);		
	return 0;
};