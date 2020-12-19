#include <SFML/Graphics.hpp>

#include <vector>
#include <thread>
#include <sstream>

#include "Army.h"
#include "Squad.h"
#include "map.h"
#include "Player.h"
#include "Menu.h"
#include "Strings.h"
#include "TextStringHelpers.h"
#include "Initialize.h"
#include "OrderOfShop.h"
#include "OrderOfTempArmy.h"
#include "RefreshShopSquads.h"
#include "ReturnToPull.h"

void gameProcess(std::vector <std::vector <Army*>>& pullGame);

void checkForKilled(std::vector <Army* > & tempFirstArmy, std::vector <Army* >& tempSecondArmy)
{
	for (int i = 0; i < (int)tempFirstArmy.size(); i++)
	{
		if (tempFirstArmy.at(i)->getArmyHealthNow() < 1)
		{
			tempFirstArmy.erase(tempFirstArmy.begin() + i);
			setOrderOfTempBattleArmy(tempFirstArmy, 0);
			break;
		}
	}

	for (int i = 0; i < (int)tempSecondArmy.size(); i++)
	{
		if (tempSecondArmy.at(i)->getArmyHealthNow() < 1)
		{
			tempSecondArmy.erase(tempSecondArmy.begin() + i);
			setOrderOfTempBattleArmy(tempSecondArmy, 1);
			break;
		}
	}
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
	addPlaceSprite.setColor(sf::Color(128, 128, 128));

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
	addPlaceText.setFillColor(sf::Color(128, 128, 128));

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

	for (int i = 0; i < (int)tempActiveArmy.size(); i++) 
	{
		tempActiveArmy.at(i)->setArmyHealthNow(tempActiveArmy.at(i)->getArmyHealthBasic());
	}

	for (int i = 0; i < (int)tempActiveArmy.size(); i++)
	{
		tempActiveArmy.at(i)->setArmySpawnCoordinateY(440.0f);
	}

	tempActiveArmy = player->setPlayerTempActiveArmy(tempActiveArmy);

	std::vector <Army*> tempReserveArmy = player->getPlayerReserveArmy();

	for (int i = 0; i < (int)tempReserveArmy.size(); i++)
	{
		tempReserveArmy.at(i)->setArmyHealthNow(tempReserveArmy.at(i)->getArmyHealthBasic());
	}

	tempReserveArmy = player->setPlayerTempReserveArmy(tempReserveArmy);

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

						for (int i = (int)tempShopArmy.size() - 1; i > -1; i--)
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

							if (player->getPlayerActionPointsNow() < player->getPlayerActionPointsMax())
							{
								player->setPlayerActionPointsNow(player->getPlayerActionPointsNow() + 1);
							}

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

							for (int i = (int)tempActiveArmy.size() - 1; i > -1; i--)
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

							if (player->getPlayerActionPointsNow() < player->getPlayerActionPointsMax())
							{
								player->setPlayerActionPointsNow(player->getPlayerActionPointsNow() + 1);
							}

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

							for (int i = (int)tempReserveArmy.size() - 1; i > -1; i--)
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
								player->setPlayerAdditionalPlaceForSquadCost(5);
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

		if (player->getPlayerArmyCount() < 4 && (int)player->getPlayerEra() >= 2 ||
			player->getPlayerArmyCount() < 5 && (int)player->getPlayerEra() >= 4 ||
			player->getPlayerArmyCount() < 6 && (int)player->getPlayerEra() >= 6 ||
			player->getPlayerArmyCount() < 7 && (int)player->getPlayerEra() >= 8) 
		{
			addPlaceSprite.setColor(sf::Color::White);
			addPlaceText.setFillColor(sf::Color::White);
		}
		else 
		{
			addPlaceSprite.setColor(sf::Color(128, 128, 128));
			addPlaceText.setFillColor(sf::Color(128, 128, 128));
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

	srand((unsigned)time(NULL));

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

	for (int i = 0; i < (int)tempFirstArmy.size(); i++)
	{
		tempFirstArmy.at(i)->setIsAttackedAlready(false);
	}

	for (int i = 0; i < (int)tempSecondArmy.size(); i++)
	{
		tempSecondArmy.at(i)->setIsAttackedAlready(false);
	}

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
		
	bool showInfoText = true;
	bool showInfoReRenderFirst = true, showInfoReRenderSecond = true;
	int showInfoParameter = 0;

	setOrderOfTempBattleArmy(tempFirstArmy, 0);
	setOrderOfTempBattleArmy(tempSecondArmy, 1);

	int playerThatWillAttack;

	if (firstPlayer->getPlayerActiveArmy().size() != secondPlayer->getPlayerActiveArmy().size())
	{
		if (firstPlayer->getPlayerActiveArmy().size() > secondPlayer->getPlayerActiveArmy().size())
		{
			playerThatWillAttack = 0;
		}
		else
		{
			playerThatWillAttack = 1;
		}
	}
	
	else if (firstPlayer->getPlayerEra() != secondPlayer->getPlayerEra())
	{
		if ((int)firstPlayer->getPlayerEra() > (int)secondPlayer->getPlayerEra())
		{
			playerThatWillAttack = 0;
		}
		else
		{
			playerThatWillAttack = 1;
		}
	}
	else if (firstPlayer->getIsWinLastGame() != secondPlayer->getIsWinLastGame()) 
	{
		if (!firstPlayer->getIsWinLastGame())
		{
			playerThatWillAttack = 0;
		}
		else
		{
			playerThatWillAttack = 1;
		}
	}
	else 
	{
		playerThatWillAttack = rand() % 2;
	}

	sf::Clock clock;
	float timerOfEnding = 0.0f;
	bool firstPointsEnding = false;
	bool secondPointsEnding = false;
	bool thirdPointsEnding = false;

	float distance = 0;
	int randomAttackedArmy = 0;
	bool isMovingToCenter = true;
	bool isMovingToEnemy = false;
	bool isMovingBack = false;

	float beforeMovingCoordinateX;
	float beforeMovingCoordinateY;
	bool isFirstSavingOfBasicCoordinates = true;
	int firstAttackingIndex = 0;
	int secondAttackingIndex = 0;

	bool isCavalryAttackedAntiCavalry = false;

	float timerBeforeStartBattle = 0.0f;

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

			if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::Escape)
				{
					window.close();
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
				if (showInfoParameter < tempFirstArmy.size() && tempFirstArmy.size() > 0)
				{
					if (!tempFirstArmy.at(showInfoParameter)->getArmySprite().getGlobalBounds().contains((float)mousePosition.x, (float)mousePosition.y))
					{
						showInfoReRenderFirst = true;
						showInfoText = true;
					}
				}
			}

			if (!showInfoReRenderSecond)
			{
				if (showInfoParameter < tempSecondArmy.size() && tempSecondArmy.size() > 0)
				{
					if (!tempSecondArmy.at(showInfoParameter)->getArmySprite().getGlobalBounds().contains((float)mousePosition.x, (float)mousePosition.y))
					{
						showInfoReRenderSecond = true;
						showInfoText = true;
					}
				}
			}
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

		timerBeforeStartBattle += time;

		if(timerBeforeStartBattle >= 3000)
		{
			timerBeforeStartBattle = 3000;
			if ((int)tempFirstArmy.size() == 0 || (int)tempSecondArmy.size() == 0)
			{
				if (timerOfEnding == 0)
				{
					firstPointsEnding = true;
					secondPointsEnding = true;
					thirdPointsEnding = true;
				}
				timerOfEnding += time;
			}

			if ((int)tempFirstArmy.size() == 0 && (int)tempSecondArmy.size() == 0)
			{
				if (timerOfEnding > 2000)
				{
					firstPlayer->setIsWinLastGame(false);
					secondPlayer->setIsWinLastGame(false);
					window.close();
				}
			}
			else if ((int)tempFirstArmy.size() == 0)
			{
				if (firstPointsEnding && timerOfEnding > 1000)
				{
					firstPlayer->setPlayerHealth(firstPlayer->getPlayerHealth() - (int)secondPlayer->getPlayerEra());
					firstPointsEnding = false;
				}

				if (secondPointsEnding && timerOfEnding > 2000)
				{
					firstPlayer->setPlayerHealth(firstPlayer->getPlayerHealth() - ((int)firstPlayer->getPlayerEra() / 2));
					secondPointsEnding = false;
				}

				if (thirdPointsEnding && timerOfEnding > 3000)
				{
					firstPlayer->setPlayerHealth(firstPlayer->getPlayerHealth() - ((int)tempSecondArmy.size()));
					thirdPointsEnding = false;
				}

				if (timerOfEnding > 5000)
				{
					tempSecondArmy.clear();
					firstPlayer->setIsWinLastGame(false);
					secondPlayer->setIsWinLastGame(true);
					window.close();
				}
			}
			else if ((int)tempSecondArmy.size() == 0)
			{
				if (firstPointsEnding && timerOfEnding > 1000)
				{
					secondPlayer->setPlayerHealth(secondPlayer->getPlayerHealth() - (int)firstPlayer->getPlayerEra());
					firstPointsEnding = false;
				}

				if (secondPointsEnding && timerOfEnding > 2000)
				{
					secondPlayer->setPlayerHealth(secondPlayer->getPlayerHealth() - ((int)secondPlayer->getPlayerEra() / 2));
					secondPointsEnding = false;
				}

				if (thirdPointsEnding && timerOfEnding > 3000)
				{
					secondPlayer->setPlayerHealth(secondPlayer->getPlayerHealth() - ((int)tempFirstArmy.size()));
					thirdPointsEnding = false;
				}

				if (timerOfEnding > 5000)
				{
					tempFirstArmy.clear();
					firstPlayer->setIsWinLastGame(true);
					secondPlayer->setIsWinLastGame(false);
					window.close();
				}
			}

			checkForKilled(tempFirstArmy, tempSecondArmy);

			if (firstAttackingIndex >= tempFirstArmy.size())
			{
				firstAttackingIndex = 0;
			}

			if ((int)tempFirstArmy.size() > 0)
			{
				for (int i = 0; i < (int)tempFirstArmy.size(); i++)
				{
					if (!tempFirstArmy.at(i)->getIsAttackedAlready())
					{
						firstAttackingIndex = i;
						break;
					}
					else if (i == ((int)tempFirstArmy.size() - 1))
					{
						for (int j = 0; j < (int)tempFirstArmy.size(); j++)
						{
							tempFirstArmy.at(j)->setIsAttackedAlready(false);
						}

						firstAttackingIndex = 0;
					}
				}
			}

			if (secondAttackingIndex >= tempSecondArmy.size())
			{
				secondAttackingIndex = 0;
			}

			if ((int)tempSecondArmy.size() > 0)
			{
				for (int i = 0; i < (int)tempSecondArmy.size(); i++)
				{
					if (!tempSecondArmy.at(i)->getIsAttackedAlready())
					{
						secondAttackingIndex = i;
						break;
					}
					else if (i == ((int)tempSecondArmy.size() - 1))
					{
						for (int j = 0; j < (int)tempSecondArmy.size(); j++)
						{
							tempSecondArmy.at(j)->setIsAttackedAlready(false);
						}

						secondAttackingIndex = 0;
					}
				}
			}

			if ((int)tempFirstArmy.size() > 0 && (int)tempSecondArmy.size() > 0)
			{
				if (playerThatWillAttack == 0)
				{
					if (isFirstSavingOfBasicCoordinates)
					{
						beforeMovingCoordinateX = tempFirstArmy.at(firstAttackingIndex)->getArmySpawnCoordinateX();
						beforeMovingCoordinateY = tempFirstArmy.at(firstAttackingIndex)->getArmySpawnCoordinateY();
						isFirstSavingOfBasicCoordinates = false;
					}

					if (isMovingToCenter)
					{
						distance = sqrt((860.0f - tempFirstArmy.at(firstAttackingIndex)->getArmySpawnCoordinateX()) * (860.0f - tempFirstArmy.at(firstAttackingIndex)->getArmySpawnCoordinateX()) +
							(440.0f - tempFirstArmy.at(firstAttackingIndex)->getArmySpawnCoordinateY()) * (440.0f - tempFirstArmy.at(firstAttackingIndex)->getArmySpawnCoordinateY()));

						if (distance > 2)
						{
							tempFirstArmy.at(firstAttackingIndex)->setArmySpawnCoordinateX(tempFirstArmy.at(firstAttackingIndex)->getArmySpawnCoordinateX() + 0.3f * time * (860.0f - tempFirstArmy.at(firstAttackingIndex)->getArmySpawnCoordinateX()) / distance);
							tempFirstArmy.at(firstAttackingIndex)->setArmySpawnCoordinateY(tempFirstArmy.at(firstAttackingIndex)->getArmySpawnCoordinateY() + 0.3f * time * (440.0f - tempFirstArmy.at(firstAttackingIndex)->getArmySpawnCoordinateY()) / distance);
						}
						else
						{
							tempFirstArmy.at(firstAttackingIndex)->setArmySpawnCoordinateX(860.0f);
							tempFirstArmy.at(firstAttackingIndex)->setArmySpawnCoordinateY(440.0f);
							isMovingToCenter = false;
							isMovingToEnemy = true;
							randomAttackedArmy = rand() % (int)tempSecondArmy.size();
						}
					}
					if (isMovingToEnemy)
					{
						distance = sqrt((tempSecondArmy.at(randomAttackedArmy)->getArmySpawnCoordinateX() - tempFirstArmy.at(firstAttackingIndex)->getArmySpawnCoordinateX()) * (tempSecondArmy.at(randomAttackedArmy)->getArmySpawnCoordinateX() - tempFirstArmy.at(firstAttackingIndex)->getArmySpawnCoordinateX()) +
							(tempSecondArmy.at(randomAttackedArmy)->getArmySpawnCoordinateY() - tempFirstArmy.at(firstAttackingIndex)->getArmySpawnCoordinateY()) * (tempSecondArmy.at(randomAttackedArmy)->getArmySpawnCoordinateY() - tempFirstArmy.at(firstAttackingIndex)->getArmySpawnCoordinateY()));

						if (distance > 2)
						{
							tempFirstArmy.at(firstAttackingIndex)->setArmySpawnCoordinateX(tempFirstArmy.at(firstAttackingIndex)->getArmySpawnCoordinateX() + 0.5f * time * (tempSecondArmy.at(randomAttackedArmy)->getArmySpawnCoordinateX() - tempFirstArmy.at(firstAttackingIndex)->getArmySpawnCoordinateX()) / distance);
							tempFirstArmy.at(firstAttackingIndex)->setArmySpawnCoordinateY(tempFirstArmy.at(firstAttackingIndex)->getArmySpawnCoordinateY() + 0.5f * time * (tempSecondArmy.at(randomAttackedArmy)->getArmySpawnCoordinateY() - tempFirstArmy.at(firstAttackingIndex)->getArmySpawnCoordinateY()) / distance);
						}
						else
						{
							tempFirstArmy.at(firstAttackingIndex)->setArmySpawnCoordinateX(tempSecondArmy.at(randomAttackedArmy)->getArmySpawnCoordinateX());
							tempFirstArmy.at(firstAttackingIndex)->setArmySpawnCoordinateY(tempSecondArmy.at(randomAttackedArmy)->getArmySpawnCoordinateY());

							if (tempFirstArmy.at(firstAttackingIndex)->getArmyType() == enumTypeSquad::TYPE_RANGE)
							{
								if (tempSecondArmy.at(randomAttackedArmy)->getArmyType() == enumTypeSquad::TYPE_MEELE)
								{
									if (tempFirstArmy.at(firstAttackingIndex)->getArmyAttackNow() == 1)
									{
										tempSecondArmy.at(randomAttackedArmy)->setArmyHealthNow(tempSecondArmy.at(randomAttackedArmy)->getArmyHealthNow() - 1);
									}
									else
									{
										tempSecondArmy.at(randomAttackedArmy)->setArmyHealthNow(tempSecondArmy.at(randomAttackedArmy)->getArmyHealthNow() - tempFirstArmy.at(firstAttackingIndex)->getArmyAttackNow() / 2);
									}
								}
								else
								{
									tempSecondArmy.at(randomAttackedArmy)->setArmyHealthNow(tempSecondArmy.at(randomAttackedArmy)->getArmyHealthNow() - tempFirstArmy.at(firstAttackingIndex)->getArmyAttackNow());
								}
							}
							else if (tempFirstArmy.at(firstAttackingIndex)->getArmyType() == enumTypeSquad::TYPE_MEELE)
							{
								if (tempSecondArmy.at(randomAttackedArmy)->getArmyType() == enumTypeSquad::TYPE_RANGE)
								{
									tempSecondArmy.at(randomAttackedArmy)->setArmyHealthNow(tempSecondArmy.at(randomAttackedArmy)->getArmyHealthNow() - tempFirstArmy.at(firstAttackingIndex)->getArmyAttackNow());
								}
								else
								{
									tempFirstArmy.at(firstAttackingIndex)->setArmyHealthNow(tempFirstArmy.at(firstAttackingIndex)->getArmyHealthNow() - tempSecondArmy.at(randomAttackedArmy)->getArmyAttackNow());
									tempSecondArmy.at(randomAttackedArmy)->setArmyHealthNow(tempSecondArmy.at(randomAttackedArmy)->getArmyHealthNow() - tempFirstArmy.at(firstAttackingIndex)->getArmyAttackNow());
								}
							}
							else if (tempFirstArmy.at(firstAttackingIndex)->getArmyType() == enumTypeSquad::TYPE_ANTICAVALRY)
							{
								if (tempSecondArmy.at(randomAttackedArmy)->getArmyType() == enumTypeSquad::TYPE_RANGE)
								{
									tempSecondArmy.at(randomAttackedArmy)->setArmyHealthNow(tempSecondArmy.at(randomAttackedArmy)->getArmyHealthNow() - tempFirstArmy.at(firstAttackingIndex)->getArmyAttackNow());
								}
								else if (tempSecondArmy.at(randomAttackedArmy)->getArmyType() == enumTypeSquad::TYPE_CAVALRY ||
									tempSecondArmy.at(randomAttackedArmy)->getArmyType() == enumTypeSquad::TYPE_ANTICAVALRYCAVALRY)
								{
									tempFirstArmy.at(firstAttackingIndex)->setArmyHealthNow(tempFirstArmy.at(firstAttackingIndex)->getArmyHealthNow() - tempSecondArmy.at(randomAttackedArmy)->getArmyAttackNow());
									tempSecondArmy.at(randomAttackedArmy)->setArmyHealthNow(tempSecondArmy.at(randomAttackedArmy)->getArmyHealthNow() - 2 * (tempFirstArmy.at(firstAttackingIndex)->getArmyAttackNow()));
								}
								else
								{
									tempFirstArmy.at(firstAttackingIndex)->setArmyHealthNow(tempFirstArmy.at(firstAttackingIndex)->getArmyHealthNow() - tempSecondArmy.at(randomAttackedArmy)->getArmyAttackNow());
									tempSecondArmy.at(randomAttackedArmy)->setArmyHealthNow(tempSecondArmy.at(randomAttackedArmy)->getArmyHealthNow() - tempFirstArmy.at(firstAttackingIndex)->getArmyAttackNow());
								}
							}
							else if (tempFirstArmy.at(firstAttackingIndex)->getArmyType() == enumTypeSquad::TYPE_CAVALRY)
							{
								if (tempSecondArmy.at(randomAttackedArmy)->getArmyType() == enumTypeSquad::TYPE_RANGE)
								{
									tempSecondArmy.at(randomAttackedArmy)->setArmyHealthNow(tempSecondArmy.at(randomAttackedArmy)->getArmyHealthNow() - tempFirstArmy.at(firstAttackingIndex)->getArmyAttackNow());
								}
								else if (tempSecondArmy.at(randomAttackedArmy)->getArmyType() == enumTypeSquad::TYPE_ANTICAVALRY ||
									tempSecondArmy.at(randomAttackedArmy)->getArmyType() == enumTypeSquad::TYPE_ANTICAVALRYCAVALRY)
								{
									isCavalryAttackedAntiCavalry = true;
									tempFirstArmy.at(firstAttackingIndex)->setArmyHealthNow(tempFirstArmy.at(firstAttackingIndex)->getArmyHealthNow() - 2 * tempSecondArmy.at(randomAttackedArmy)->getArmyAttackNow());
									tempSecondArmy.at(randomAttackedArmy)->setArmyHealthNow(tempSecondArmy.at(randomAttackedArmy)->getArmyHealthNow() - tempFirstArmy.at(firstAttackingIndex)->getArmyAttackNow());
								}
								else
								{
									tempFirstArmy.at(firstAttackingIndex)->setArmyHealthNow(tempFirstArmy.at(firstAttackingIndex)->getArmyHealthNow() - tempSecondArmy.at(randomAttackedArmy)->getArmyAttackNow());
									tempSecondArmy.at(randomAttackedArmy)->setArmyHealthNow(tempSecondArmy.at(randomAttackedArmy)->getArmyHealthNow() - tempFirstArmy.at(firstAttackingIndex)->getArmyAttackNow());
								}
							}
							else if (tempFirstArmy.at(firstAttackingIndex)->getArmyType() == enumTypeSquad::TYPE_ANTICAVALRYCAVALRY)
							{
								if (tempSecondArmy.at(randomAttackedArmy)->getArmyType() == enumTypeSquad::TYPE_RANGE)
								{
									tempSecondArmy.at(randomAttackedArmy)->setArmyHealthNow(tempSecondArmy.at(randomAttackedArmy)->getArmyHealthNow() - tempFirstArmy.at(firstAttackingIndex)->getArmyAttackNow());
								}
								else if (tempSecondArmy.at(randomAttackedArmy)->getArmyType() == enumTypeSquad::TYPE_ANTICAVALRY)
								{
									isCavalryAttackedAntiCavalry = true;
									tempFirstArmy.at(firstAttackingIndex)->setArmyHealthNow(tempFirstArmy.at(firstAttackingIndex)->getArmyHealthNow() - 2 * tempSecondArmy.at(randomAttackedArmy)->getArmyAttackNow());
									tempSecondArmy.at(randomAttackedArmy)->setArmyHealthNow(tempSecondArmy.at(randomAttackedArmy)->getArmyHealthNow() - tempFirstArmy.at(firstAttackingIndex)->getArmyAttackNow());
								}
								else if (tempSecondArmy.at(randomAttackedArmy)->getArmyType() == enumTypeSquad::TYPE_ANTICAVALRYCAVALRY)
								{
									isCavalryAttackedAntiCavalry = true;
									tempFirstArmy.at(firstAttackingIndex)->setArmyHealthNow(tempFirstArmy.at(firstAttackingIndex)->getArmyHealthNow() - 2 * tempSecondArmy.at(randomAttackedArmy)->getArmyAttackNow());
									tempSecondArmy.at(randomAttackedArmy)->setArmyHealthNow(tempSecondArmy.at(randomAttackedArmy)->getArmyHealthNow() - 2 * tempFirstArmy.at(firstAttackingIndex)->getArmyAttackNow());
								}
								else if (tempSecondArmy.at(randomAttackedArmy)->getArmyType() == enumTypeSquad::TYPE_CAVALRY)
								{
									tempFirstArmy.at(firstAttackingIndex)->setArmyHealthNow(tempFirstArmy.at(firstAttackingIndex)->getArmyHealthNow() - tempSecondArmy.at(randomAttackedArmy)->getArmyAttackNow());
									tempSecondArmy.at(randomAttackedArmy)->setArmyHealthNow(tempSecondArmy.at(randomAttackedArmy)->getArmyHealthNow() - 2 * (tempFirstArmy.at(firstAttackingIndex)->getArmyAttackNow()));
								}
								else
								{
									tempFirstArmy.at(firstAttackingIndex)->setArmyHealthNow(tempFirstArmy.at(firstAttackingIndex)->getArmyHealthNow() - tempSecondArmy.at(randomAttackedArmy)->getArmyAttackNow());
									tempSecondArmy.at(randomAttackedArmy)->setArmyHealthNow(tempSecondArmy.at(randomAttackedArmy)->getArmyHealthNow() - tempFirstArmy.at(firstAttackingIndex)->getArmyAttackNow());
								}
							}
							else
							{
								if (tempSecondArmy.at(randomAttackedArmy)->getArmyType() == enumTypeSquad::TYPE_RANGE)
								{
									tempSecondArmy.at(randomAttackedArmy)->setArmyHealthNow(tempSecondArmy.at(randomAttackedArmy)->getArmyHealthNow() - tempFirstArmy.at(firstAttackingIndex)->getArmyAttackNow());
								}
								else
								{
									tempFirstArmy.at(firstAttackingIndex)->setArmyHealthNow(tempFirstArmy.at(firstAttackingIndex)->getArmyHealthNow() - tempSecondArmy.at(randomAttackedArmy)->getArmyAttackNow());
									tempSecondArmy.at(randomAttackedArmy)->setArmyHealthNow(tempSecondArmy.at(randomAttackedArmy)->getArmyHealthNow() - tempFirstArmy.at(firstAttackingIndex)->getArmyAttackNow());
								}
							}

							isMovingToEnemy = false;
							isMovingBack = true;

							for (int i = 0; i < (int)tempFirstArmy.size(); i++)
							{
								if (tempFirstArmy.at(i)->getArmyHealthNow() < 1)
								{
									tempFirstArmy.erase(tempFirstArmy.begin() + i);
									setOrderOfTempBattleArmy(tempFirstArmy, 0);
									isMovingBack = false;
									playerThatWillAttack = 1;

									if (tempSecondArmy.size() > 0 && tempFirstArmy.size() > 0)
									{
										isMovingToCenter = true;
										isFirstSavingOfBasicCoordinates = true;
									}

									break;
								}
							}

							for (int i = 0; i < (int)tempSecondArmy.size(); i++)
							{
								if (tempSecondArmy.at(i)->getArmyHealthNow() < 1)
								{
									tempSecondArmy.erase(tempSecondArmy.begin() + i);
									setOrderOfTempBattleArmy(tempSecondArmy, 1);
									break;
								}
							}
						}
					}
					if (isMovingBack)
					{
						distance = sqrt((beforeMovingCoordinateX - tempFirstArmy.at(firstAttackingIndex)->getArmySpawnCoordinateX()) * (beforeMovingCoordinateX - tempFirstArmy.at(firstAttackingIndex)->getArmySpawnCoordinateX()) +
							(beforeMovingCoordinateY - tempFirstArmy.at(firstAttackingIndex)->getArmySpawnCoordinateY()) * (beforeMovingCoordinateY - tempFirstArmy.at(firstAttackingIndex)->getArmySpawnCoordinateY()));

						if (distance > 2)
						{
							tempFirstArmy.at(firstAttackingIndex)->setArmySpawnCoordinateX(tempFirstArmy.at(firstAttackingIndex)->getArmySpawnCoordinateX() + 0.3f * time * (beforeMovingCoordinateX - tempFirstArmy.at(firstAttackingIndex)->getArmySpawnCoordinateX()) / distance);
							tempFirstArmy.at(firstAttackingIndex)->setArmySpawnCoordinateY(tempFirstArmy.at(firstAttackingIndex)->getArmySpawnCoordinateY() + 0.3f * time * (beforeMovingCoordinateY - tempFirstArmy.at(firstAttackingIndex)->getArmySpawnCoordinateY()) / distance);
						}
						else
						{
							tempFirstArmy.at(firstAttackingIndex)->setArmySpawnCoordinateX(beforeMovingCoordinateX);
							tempFirstArmy.at(firstAttackingIndex)->setArmySpawnCoordinateY(beforeMovingCoordinateY);
							isMovingBack = false;
							playerThatWillAttack = 1;

							if (tempSecondArmy.size() > 0 && tempFirstArmy.size() > 0)
							{
								tempFirstArmy.at(firstAttackingIndex)->setIsAttackedAlready(true);

								if (tempFirstArmy.at(firstAttackingIndex)->getArmyType() == enumTypeSquad::TYPE_CAVALRY ||
									tempFirstArmy.at(firstAttackingIndex)->getArmyType() == enumTypeSquad::TYPE_ANTICAVALRYCAVALRY)
								{
									if (!isCavalryAttackedAntiCavalry)
									{
										tempFirstArmy.at(firstAttackingIndex)->setIsAttackedAlready(false);
										playerThatWillAttack = 0;
									}
									else
									{
										isCavalryAttackedAntiCavalry = false;
									}
								}

								isMovingToCenter = true;
								isFirstSavingOfBasicCoordinates = true;
							}
						}
					}
				}
				else
				{
					if (isFirstSavingOfBasicCoordinates)
					{
						beforeMovingCoordinateX = tempSecondArmy.at(secondAttackingIndex)->getArmySpawnCoordinateX();
						beforeMovingCoordinateY = tempSecondArmy.at(secondAttackingIndex)->getArmySpawnCoordinateY();
						isFirstSavingOfBasicCoordinates = false;
					}

					if (isMovingToCenter)
					{
						distance = sqrt((860.0f - tempSecondArmy.at(secondAttackingIndex)->getArmySpawnCoordinateX()) * (860.0f - tempSecondArmy.at(secondAttackingIndex)->getArmySpawnCoordinateX()) +
							(440.0f - tempSecondArmy.at(secondAttackingIndex)->getArmySpawnCoordinateY()) * (440.0f - tempSecondArmy.at(secondAttackingIndex)->getArmySpawnCoordinateY()));

						if (distance > 2)
						{
							tempSecondArmy.at(secondAttackingIndex)->setArmySpawnCoordinateX(tempSecondArmy.at(secondAttackingIndex)->getArmySpawnCoordinateX() + 0.3f * time * (860.0f - tempSecondArmy.at(secondAttackingIndex)->getArmySpawnCoordinateX()) / distance);
							tempSecondArmy.at(secondAttackingIndex)->setArmySpawnCoordinateY(tempSecondArmy.at(secondAttackingIndex)->getArmySpawnCoordinateY() + 0.3f * time * (440.0f - tempSecondArmy.at(secondAttackingIndex)->getArmySpawnCoordinateY()) / distance);
						}
						else
						{
							tempSecondArmy.at(secondAttackingIndex)->setArmySpawnCoordinateX(860.0f);
							tempSecondArmy.at(secondAttackingIndex)->setArmySpawnCoordinateY(440.0f);
							isMovingToCenter = false;
							isMovingToEnemy = true;
							randomAttackedArmy = rand() % (int)tempFirstArmy.size();
						}
					}
					if (isMovingToEnemy)
					{
						distance = sqrt((tempFirstArmy.at(randomAttackedArmy)->getArmySpawnCoordinateX() - tempSecondArmy.at(secondAttackingIndex)->getArmySpawnCoordinateX()) * (tempFirstArmy.at(randomAttackedArmy)->getArmySpawnCoordinateX() - tempSecondArmy.at(secondAttackingIndex)->getArmySpawnCoordinateX()) +
							(tempFirstArmy.at(randomAttackedArmy)->getArmySpawnCoordinateY() - tempSecondArmy.at(secondAttackingIndex)->getArmySpawnCoordinateY()) * (tempFirstArmy.at(randomAttackedArmy)->getArmySpawnCoordinateY() - tempSecondArmy.at(secondAttackingIndex)->getArmySpawnCoordinateY()));

						if (distance > 2)
						{
							tempSecondArmy.at(secondAttackingIndex)->setArmySpawnCoordinateX(tempSecondArmy.at(secondAttackingIndex)->getArmySpawnCoordinateX() + 0.5f * time * (tempFirstArmy.at(randomAttackedArmy)->getArmySpawnCoordinateX() - tempSecondArmy.at(secondAttackingIndex)->getArmySpawnCoordinateX()) / distance);
							tempSecondArmy.at(secondAttackingIndex)->setArmySpawnCoordinateY(tempSecondArmy.at(secondAttackingIndex)->getArmySpawnCoordinateY() + 0.5f * time * (tempFirstArmy.at(randomAttackedArmy)->getArmySpawnCoordinateY() - tempSecondArmy.at(secondAttackingIndex)->getArmySpawnCoordinateY()) / distance);
						}
						else
						{
							tempSecondArmy.at(secondAttackingIndex)->setArmySpawnCoordinateX(tempFirstArmy.at(randomAttackedArmy)->getArmySpawnCoordinateX());
							tempSecondArmy.at(secondAttackingIndex)->setArmySpawnCoordinateY(tempFirstArmy.at(randomAttackedArmy)->getArmySpawnCoordinateY());

							if (tempSecondArmy.at(secondAttackingIndex)->getArmyType() == enumTypeSquad::TYPE_RANGE)
							{
								if (tempFirstArmy.at(randomAttackedArmy)->getArmyType() == enumTypeSquad::TYPE_MEELE)
								{
									if (tempSecondArmy.at(secondAttackingIndex)->getArmyAttackNow() == 1)
									{
										tempFirstArmy.at(randomAttackedArmy)->setArmyHealthNow(tempFirstArmy.at(randomAttackedArmy)->getArmyHealthNow() - 1);
									}
									else
									{
										tempFirstArmy.at(randomAttackedArmy)->setArmyHealthNow(tempFirstArmy.at(randomAttackedArmy)->getArmyHealthNow() - tempSecondArmy.at(secondAttackingIndex)->getArmyAttackNow() / 2);
									}
								}
								else
								{
									tempFirstArmy.at(randomAttackedArmy)->setArmyHealthNow(tempFirstArmy.at(randomAttackedArmy)->getArmyHealthNow() - tempSecondArmy.at(secondAttackingIndex)->getArmyAttackNow());
								}
							}
							else if (tempSecondArmy.at(secondAttackingIndex)->getArmyType() == enumTypeSquad::TYPE_MEELE)
							{
								if (tempFirstArmy.at(randomAttackedArmy)->getArmyType() == enumTypeSquad::TYPE_RANGE)
								{
									tempFirstArmy.at(randomAttackedArmy)->setArmyHealthNow(tempFirstArmy.at(randomAttackedArmy)->getArmyHealthNow() - tempSecondArmy.at(secondAttackingIndex)->getArmyAttackNow());
								}
								else
								{
									tempSecondArmy.at(secondAttackingIndex)->setArmyHealthNow(tempSecondArmy.at(secondAttackingIndex)->getArmyHealthNow() - tempFirstArmy.at(randomAttackedArmy)->getArmyAttackNow());
									tempFirstArmy.at(randomAttackedArmy)->setArmyHealthNow(tempFirstArmy.at(randomAttackedArmy)->getArmyHealthNow() - tempSecondArmy.at(secondAttackingIndex)->getArmyAttackNow());
								}
							}
							else if (tempSecondArmy.at(secondAttackingIndex)->getArmyType() == enumTypeSquad::TYPE_ANTICAVALRY)
							{
								if (tempFirstArmy.at(randomAttackedArmy)->getArmyType() == enumTypeSquad::TYPE_RANGE)
								{
									tempFirstArmy.at(randomAttackedArmy)->setArmyHealthNow(tempFirstArmy.at(randomAttackedArmy)->getArmyHealthNow() - tempSecondArmy.at(secondAttackingIndex)->getArmyAttackNow());
								}
								else if (tempFirstArmy.at(randomAttackedArmy)->getArmyType() == enumTypeSquad::TYPE_CAVALRY ||
									tempFirstArmy.at(randomAttackedArmy)->getArmyType() == enumTypeSquad::TYPE_ANTICAVALRYCAVALRY)
								{
									tempSecondArmy.at(secondAttackingIndex)->setArmyHealthNow(tempSecondArmy.at(secondAttackingIndex)->getArmyHealthNow() - tempFirstArmy.at(randomAttackedArmy)->getArmyAttackNow());
									tempFirstArmy.at(randomAttackedArmy)->setArmyHealthNow(tempFirstArmy.at(randomAttackedArmy)->getArmyHealthNow() - 2 * (tempSecondArmy.at(secondAttackingIndex)->getArmyAttackNow()));
								}
								else
								{
									tempSecondArmy.at(secondAttackingIndex)->setArmyHealthNow(tempSecondArmy.at(secondAttackingIndex)->getArmyHealthNow() - tempFirstArmy.at(randomAttackedArmy)->getArmyAttackNow());
									tempFirstArmy.at(randomAttackedArmy)->setArmyHealthNow(tempFirstArmy.at(randomAttackedArmy)->getArmyHealthNow() - tempSecondArmy.at(secondAttackingIndex)->getArmyAttackNow());
								}
							}
							else if (tempSecondArmy.at(secondAttackingIndex)->getArmyType() == enumTypeSquad::TYPE_CAVALRY)
							{
								if (tempFirstArmy.at(randomAttackedArmy)->getArmyType() == enumTypeSquad::TYPE_RANGE)
								{
									tempFirstArmy.at(randomAttackedArmy)->setArmyHealthNow(tempFirstArmy.at(randomAttackedArmy)->getArmyHealthNow() - tempSecondArmy.at(secondAttackingIndex)->getArmyAttackNow());
								}
								else if (tempFirstArmy.at(randomAttackedArmy)->getArmyType() == enumTypeSquad::TYPE_ANTICAVALRY ||
									tempFirstArmy.at(randomAttackedArmy)->getArmyType() == enumTypeSquad::TYPE_ANTICAVALRYCAVALRY)
								{
									isCavalryAttackedAntiCavalry = true;
									tempSecondArmy.at(secondAttackingIndex)->setArmyHealthNow(tempSecondArmy.at(secondAttackingIndex)->getArmyHealthNow() - 2 * tempFirstArmy.at(randomAttackedArmy)->getArmyAttackNow());
									tempFirstArmy.at(randomAttackedArmy)->setArmyHealthNow(tempFirstArmy.at(randomAttackedArmy)->getArmyHealthNow() - tempSecondArmy.at(secondAttackingIndex)->getArmyAttackNow());
								}
								else
								{
									tempSecondArmy.at(secondAttackingIndex)->setArmyHealthNow(tempSecondArmy.at(secondAttackingIndex)->getArmyHealthNow() - tempFirstArmy.at(randomAttackedArmy)->getArmyAttackNow());
									tempFirstArmy.at(randomAttackedArmy)->setArmyHealthNow(tempFirstArmy.at(randomAttackedArmy)->getArmyHealthNow() - tempSecondArmy.at(secondAttackingIndex)->getArmyAttackNow());
								}
							}
							else if (tempSecondArmy.at(secondAttackingIndex)->getArmyType() == enumTypeSquad::TYPE_ANTICAVALRYCAVALRY)
							{
								if (tempFirstArmy.at(randomAttackedArmy)->getArmyType() == enumTypeSquad::TYPE_RANGE)
								{
									tempFirstArmy.at(randomAttackedArmy)->setArmyHealthNow(tempFirstArmy.at(randomAttackedArmy)->getArmyHealthNow() - tempSecondArmy.at(secondAttackingIndex)->getArmyAttackNow());
								}
								else if (tempFirstArmy.at(randomAttackedArmy)->getArmyType() == enumTypeSquad::TYPE_ANTICAVALRY)
								{
									isCavalryAttackedAntiCavalry = true;
									tempSecondArmy.at(secondAttackingIndex)->setArmyHealthNow(tempSecondArmy.at(secondAttackingIndex)->getArmyHealthNow() - 2 * tempFirstArmy.at(randomAttackedArmy)->getArmyAttackNow());
									tempFirstArmy.at(randomAttackedArmy)->setArmyHealthNow(tempFirstArmy.at(randomAttackedArmy)->getArmyHealthNow() - tempSecondArmy.at(secondAttackingIndex)->getArmyAttackNow());
								}
								else if (tempFirstArmy.at(randomAttackedArmy)->getArmyType() == enumTypeSquad::TYPE_ANTICAVALRYCAVALRY)
								{
									isCavalryAttackedAntiCavalry = true;
									tempSecondArmy.at(secondAttackingIndex)->setArmyHealthNow(tempSecondArmy.at(secondAttackingIndex)->getArmyHealthNow() - 2 * tempFirstArmy.at(randomAttackedArmy)->getArmyAttackNow());
									tempFirstArmy.at(randomAttackedArmy)->setArmyHealthNow(tempFirstArmy.at(randomAttackedArmy)->getArmyHealthNow() - 2 * tempSecondArmy.at(secondAttackingIndex)->getArmyAttackNow());
								}
								else if (tempFirstArmy.at(randomAttackedArmy)->getArmyType() == enumTypeSquad::TYPE_CAVALRY)
								{
									tempSecondArmy.at(secondAttackingIndex)->setArmyHealthNow(tempSecondArmy.at(secondAttackingIndex)->getArmyHealthNow() - tempFirstArmy.at(randomAttackedArmy)->getArmyAttackNow());
									tempFirstArmy.at(randomAttackedArmy)->setArmyHealthNow(tempFirstArmy.at(randomAttackedArmy)->getArmyHealthNow() - 2 * (tempSecondArmy.at(secondAttackingIndex)->getArmyAttackNow()));
								}
								else
								{
									tempSecondArmy.at(secondAttackingIndex)->setArmyHealthNow(tempSecondArmy.at(secondAttackingIndex)->getArmyHealthNow() - tempFirstArmy.at(randomAttackedArmy)->getArmyAttackNow());
									tempFirstArmy.at(randomAttackedArmy)->setArmyHealthNow(tempFirstArmy.at(randomAttackedArmy)->getArmyHealthNow() - tempSecondArmy.at(secondAttackingIndex)->getArmyAttackNow());
								}
							}
							else
							{
								if (tempFirstArmy.at(randomAttackedArmy)->getArmyType() == enumTypeSquad::TYPE_RANGE)
								{
									tempFirstArmy.at(randomAttackedArmy)->setArmyHealthNow(tempFirstArmy.at(randomAttackedArmy)->getArmyHealthNow() - tempSecondArmy.at(secondAttackingIndex)->getArmyAttackNow());
								}
								else
								{
									tempSecondArmy.at(secondAttackingIndex)->setArmyHealthNow(tempSecondArmy.at(secondAttackingIndex)->getArmyHealthNow() - tempFirstArmy.at(randomAttackedArmy)->getArmyAttackNow());
									tempFirstArmy.at(randomAttackedArmy)->setArmyHealthNow(tempFirstArmy.at(randomAttackedArmy)->getArmyHealthNow() - tempSecondArmy.at(secondAttackingIndex)->getArmyAttackNow());
								}
							}

							isMovingToEnemy = false;
							isMovingBack = true;

							for (int i = 0; i < (int)tempFirstArmy.size(); i++)
							{
								if (tempFirstArmy.at(i)->getArmyHealthNow() < 1)
								{
									tempFirstArmy.erase(tempFirstArmy.begin() + i);
									setOrderOfTempBattleArmy(tempFirstArmy, 0);
									break;
								}
							}

							for (int i = 0; i < (int)tempSecondArmy.size(); i++)
							{
								if (tempSecondArmy.at(i)->getArmyHealthNow() < 1)
								{
									tempSecondArmy.erase(tempSecondArmy.begin() + i);
									setOrderOfTempBattleArmy(tempSecondArmy, 1);
									isMovingBack = false;
									playerThatWillAttack = 0;

									if (tempSecondArmy.size() > 0 && tempFirstArmy.size() > 0)
									{
										isMovingToCenter = true;
										isFirstSavingOfBasicCoordinates = true;
									}

									break;
								}
							}
						}
					}
					if (isMovingBack)
					{
						distance = sqrt((beforeMovingCoordinateX - tempSecondArmy.at(secondAttackingIndex)->getArmySpawnCoordinateX()) * (beforeMovingCoordinateX - tempSecondArmy.at(secondAttackingIndex)->getArmySpawnCoordinateX()) +
							(beforeMovingCoordinateY - tempSecondArmy.at(secondAttackingIndex)->getArmySpawnCoordinateY()) * (beforeMovingCoordinateY - tempSecondArmy.at(secondAttackingIndex)->getArmySpawnCoordinateY()));

						if (distance > 2)
						{
							tempSecondArmy.at(secondAttackingIndex)->setArmySpawnCoordinateX(tempSecondArmy.at(secondAttackingIndex)->getArmySpawnCoordinateX() + 0.3f * time * (beforeMovingCoordinateX - tempSecondArmy.at(secondAttackingIndex)->getArmySpawnCoordinateX()) / distance);
							tempSecondArmy.at(secondAttackingIndex)->setArmySpawnCoordinateY(tempSecondArmy.at(secondAttackingIndex)->getArmySpawnCoordinateY() + 0.3f * time * (beforeMovingCoordinateY - tempSecondArmy.at(secondAttackingIndex)->getArmySpawnCoordinateY()) / distance);
						}
						else
						{
							tempSecondArmy.at(secondAttackingIndex)->setArmySpawnCoordinateX(beforeMovingCoordinateX);
							tempSecondArmy.at(secondAttackingIndex)->setArmySpawnCoordinateY(beforeMovingCoordinateY);
							isMovingBack = false;
							playerThatWillAttack = 0;

							if (tempSecondArmy.size() > 0 && tempFirstArmy.size() > 0)
							{
								tempSecondArmy.at(secondAttackingIndex)->setIsAttackedAlready(true);

								if (tempSecondArmy.at(secondAttackingIndex)->getArmyType() == enumTypeSquad::TYPE_CAVALRY ||
									tempSecondArmy.at(secondAttackingIndex)->getArmyType() == enumTypeSquad::TYPE_ANTICAVALRYCAVALRY)
								{
									if (!isCavalryAttackedAntiCavalry)
									{
										tempSecondArmy.at(secondAttackingIndex)->setIsAttackedAlready(false);
										playerThatWillAttack = 1;
									}
									else
									{
										isCavalryAttackedAntiCavalry = false;
									}
								}

								isMovingToCenter = true;
								isFirstSavingOfBasicCoordinates = true;
							}
						}
					}
				}
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

			std::ostringstream firstPlayerArmyHealth;
			firstPlayerArmyHealth << tempFirstArmy.at(i)->getArmyHealthNow();
			textHealth.setString(firstPlayerArmyHealth.str());

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

			std::ostringstream secondPlayerArmyHealth;
			secondPlayerArmyHealth << tempSecondArmy.at(i)->getArmyHealthNow();
			textHealth.setString(secondPlayerArmyHealth.str());

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

		std::ostringstream firstPlayerHealthText;
		firstPlayerHealthText << firstPlayer->getPlayerHealth();
		textPlayerHealthFirst.setString(firstPlayerHealthText.str());

		std::ostringstream secondPlayerHealthText;
		secondPlayerHealthText << secondPlayer->getPlayerHealth();
		textPlayerHealthSecond.setString(secondPlayerHealthText.str());

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
				break; break;
			}
		}
		
		if (!isPlayerDead)
		{
			battle(pullGame, playersVector.at(0), playersVector.at(1));
		}
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