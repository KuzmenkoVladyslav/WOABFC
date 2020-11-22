#include <SFML/Graphics.hpp>

#include <iostream> 
#include <vector>
#include <thread>

#include "Army.h"
#include "Squad.h"
#include "enumSquad.h"
#include "map.h"
#include "Player.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "War of Ages: Battle for Castle", sf::Style::Fullscreen);

	sf::Texture mapTexture;
	mapTexture.loadFromFile("images/map.png");
	sf::Sprite mapSprite;
	mapSprite.setTexture(mapTexture);

	std::vector <std::vector <Army*>> pullGame(9);
	std::vector <Army*> pullAncient(64), pullClassic(64), pullMedival(64), pullRenaissancee(48), pullIndustrial(48), pullModern(48), pullAtomic(32), pullInfromation(32), pullFuture(12);
	Army* addSquadUnit;

	std::vector <Army*> tempFirstArmy;

	Player* firstPlayer = new Player();

	//float tempSpawn;

	sf::Font font;
	font.loadFromFile("16249.ttf");

	sf::Text textAttack;
	textAttack.setFont(font);
	textAttack.setOutlineColor(sf::Color::Black);
	textAttack.setStyle(sf::Text::Bold);

	sf::Text textInfo = textAttack;
	textInfo.setCharacterSize(30);
	textInfo.setOutlineThickness(2);

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
	spriteInfo.setTextureRect(sf::IntRect(0, 0, 340, 510));  //приведение типов, размеры картинки исходные
	spriteInfo.setScale(2.0f, 0.7f);
	spriteInfo.setPosition(window.getSize().x / 2.0 - 380.0, window.getSize().y / 2.0 - 178.0);

	bool isFirstSpawn = true;
	bool isSpriteMove = false;
	float dXSpriteMove = 0;
	float dYSpriteMove = 0;
	int spriteMoveParameter = 0;

	bool showInfoText = true;
	bool showInfoReRender = true;
	int showInfoParameter = 0;

	std::thread threadAncient([&addSquadUnit, &pullAncient]()
		{
			std::fill(pullAncient.begin(), pullAncient.begin() + 16, addSquadUnit = new Squad(enumSquad::SQUAD_WARRIOR));
			std::fill(pullAncient.begin() + 16, pullAncient.begin() + 32, addSquadUnit = new Squad(enumSquad::SQUAD_ARCHER));
			std::fill(pullAncient.begin() + 32, pullAncient.begin() + 48, addSquadUnit = new Squad(enumSquad::SQUAD_HOURSEARCHER));
			std::fill(pullAncient.begin() + 48, pullAncient.begin() + 64, addSquadUnit = new Squad(enumSquad::SQUAD_SPEARMAN));
		});

	std::thread threadClassic([&addSquadUnit, &pullClassic]()
		{
			std::fill(pullClassic.begin(), pullClassic.begin() + 16, addSquadUnit = new Squad(enumSquad::SQUAD_SWORDSMAN));
			std::fill(pullClassic.begin() + 16, pullClassic.begin() + 32, addSquadUnit = new Squad(enumSquad::SQUAD_LONGBOWARCHER));
			std::fill(pullClassic.begin() + 32, pullClassic.begin() + 48, addSquadUnit = new Squad(enumSquad::SQUAD_HORSEMAN));
			std::fill(pullClassic.begin() + 48, pullClassic.begin() + 64, addSquadUnit = new Squad(enumSquad::SQUAD_HOPLITE));
		});

	std::thread threadMedival([&addSquadUnit, &pullMedival]()
		{
			std::fill(pullMedival.begin(), pullMedival.begin() + 16, addSquadUnit = new Squad(enumSquad::SQUAD_LONGSWORDSMAN));
			std::fill(pullMedival.begin() + 16, pullMedival.begin() + 32, addSquadUnit = new Squad(enumSquad::SQUAD_CROSSBOWMAN));
			std::fill(pullMedival.begin() + 32, pullMedival.begin() + 48, addSquadUnit = new Squad(enumSquad::SQUAD_KNIGHT));
			std::fill(pullMedival.begin() + 48, pullMedival.begin() + 64, addSquadUnit = new Squad(enumSquad::SQUAD_PIKEMAN));
		});

	std::thread threadRenaissancee([&addSquadUnit, &pullRenaissancee]()
		{
			std::fill(pullRenaissancee.begin(), pullRenaissancee.begin() + 16, addSquadUnit = new Squad(enumSquad::SQUAD_HARQUEBUSIER));
			std::fill(pullRenaissancee.begin() + 16, pullRenaissancee.begin() + 32, addSquadUnit = new Squad(enumSquad::SQUAD_CANNON));
			std::fill(pullRenaissancee.begin() + 32, pullRenaissancee.begin() + 48, addSquadUnit = new Squad(enumSquad::SQUAD_LANCER));
		});

	std::thread threadIndustrial([&addSquadUnit, &pullIndustrial]()
		{
			std::fill(pullIndustrial.begin(), pullIndustrial.begin() + 16, addSquadUnit = new Squad(enumSquad::SQUAD_MUSKETEER));
			std::fill(pullIndustrial.begin() + 16, pullIndustrial.begin() + 32, addSquadUnit = new Squad(enumSquad::SQUAD_GATLING));
			std::fill(pullIndustrial.begin() + 32, pullIndustrial.begin() + 48, addSquadUnit = new Squad(enumSquad::SQUAD_CAVALRY));
		});

	std::thread threadModern([&addSquadUnit, &pullModern]()
		{
			std::fill(pullModern.begin(), pullModern.begin() + 12, addSquadUnit = new Squad(enumSquad::SQUAD_INFANTRYMAN));
			std::fill(pullModern.begin() + 12, pullModern.begin() + 24, addSquadUnit = new Squad(enumSquad::SQUAD_MACHINGGUN));
			std::fill(pullModern.begin() + 24, pullModern.begin() + 36, addSquadUnit = new Squad(enumSquad::SQUAD_TANKETTE));
			std::fill(pullModern.begin() + 36, pullModern.begin() + 48, addSquadUnit = new Squad(enumSquad::SQUAD_ARTBATTERY));
		});

	std::thread threadAtomic([&addSquadUnit, &pullAtomic]()
		{
			std::fill(pullAtomic.begin(), pullAtomic.begin() + 8, addSquadUnit = new Squad(enumSquad::SQUAD_SEAINFANTRYMAN));
			std::fill(pullAtomic.begin() + 8, pullAtomic.begin() + 16, addSquadUnit = new Squad(enumSquad::SQUAD_BAZOOKA));
			std::fill(pullAtomic.begin() + 16, pullAtomic.begin() + 24, addSquadUnit = new Squad(enumSquad::SQUAD_TANK));
			std::fill(pullAtomic.begin() + 24, pullAtomic.begin() + 32, addSquadUnit = new Squad(enumSquad::SQUAD_ANTITANKCANNON));
		});

	std::thread threadInformation([&addSquadUnit, &pullInfromation]()
		{
			std::fill(pullInfromation.begin(), pullInfromation.begin() + 8, addSquadUnit = new Squad(enumSquad::SQUAD_MOTORIZEDINFANTRY));
			std::fill(pullInfromation.begin() + 8, pullInfromation.begin() + 16, addSquadUnit = new Squad(enumSquad::SQUAD_ROCKET));
			std::fill(pullInfromation.begin() + 16, pullInfromation.begin() + 24, addSquadUnit = new Squad(enumSquad::SQUAD_MODERNTANK));
			std::fill(pullInfromation.begin() + 24, pullInfromation.begin() + 32, addSquadUnit = new Squad(enumSquad::SQUAD_ROCKETARTILLERY));
		});

	std::thread threadFuture([&addSquadUnit, &pullFuture]()
		{
			std::fill(pullFuture.begin(), pullFuture.begin() + 6, addSquadUnit = new Squad(enumSquad::SQUAD_FUTURESMAN));
			std::fill(pullFuture.begin() + 6, pullFuture.begin() + 12, addSquadUnit = new Squad(enumSquad::SQUAD_ROBOT));
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

	pullGame.at(0) = pullAncient;
	pullGame.at(1) = pullClassic;
	pullGame.at(2) = pullMedival;
	pullGame.at(3) = pullRenaissancee;
	pullGame.at(4) = pullIndustrial;
	pullGame.at(5) = pullModern;
	pullGame.at(6) = pullAtomic;
	pullGame.at(7) = pullInfromation;
	pullGame.at(8) = pullFuture;


	tempFirstArmy.push_back(pullGame.at(0).at(0));
	tempFirstArmy.push_back(pullGame.at(0).at(16));
	tempFirstArmy.push_back(pullGame.at(0).at(32));
	tempFirstArmy.push_back(pullGame.at(0).at(63));

	firstPlayer->setPlayerActiveArmy(tempFirstArmy);

	sf::Clock clock;

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();

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
					for (int i = 0; i < firstPlayer->getPlayerActiveArmy().size(); i++)
					{
						if (firstPlayer->getPlayerActiveArmy().at(i)->getArmySprite().getGlobalBounds().contains(mousePosition.x, mousePosition.y))
						{
							spriteMoveParameter = i;
							dXSpriteMove = mousePosition.x - firstPlayer->getPlayerActiveArmy().at(spriteMoveParameter)->getArmySpawnCoordinateX();
							dYSpriteMove = mousePosition.y - firstPlayer->getPlayerActiveArmy().at(spriteMoveParameter)->getArmySpawnCoordinateY();
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
					isSpriteMove = false;
				}
			}

			if (showInfoReRender)
			{
				for (int i = 0; i < firstPlayer->getPlayerActiveArmy().size(); i++)
				{
					if (firstPlayer->getPlayerActiveArmy().at(i)->getArmySprite().getGlobalBounds().contains(mousePosition.x, mousePosition.y))
					{
						showInfoParameter = i;
						showInfoReRender = false;

						switch (showInfoText)
						{
						case true:
							textInfo.setString("Era: " + firstPlayer->getPlayerActiveArmy().at(i)->getStringEraName() + "\n" +
								"Name: " + firstPlayer->getPlayerActiveArmy().at(i)->getArmyName() + "\n" +
								"Type: " + firstPlayer->getPlayerActiveArmy().at(i)->getStringArmyType());
							showInfoText = false;
							textInfo.setPosition(window.getSize().x / 2.0 - 350.0, window.getSize().y / 2.0 - 168.0);
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

			if (!firstPlayer->getPlayerActiveArmy().at(showInfoParameter)->getArmySprite().getGlobalBounds().contains(mousePosition.x, mousePosition.y))
			{
				showInfoReRender = true;
				showInfoText = true;
			}
		}

		if (isSpriteMove)
		{
			firstPlayer->getPlayerActiveArmy().at(spriteMoveParameter)->setArmySpawnCoordinates(mousePosition.x - dXSpriteMove, mousePosition.y - dYSpriteMove);
		}

		window.clear();

		for (int i = 0; i < HEIGHT_MAP; i++)
		{
			for (int j = 0; j < WIDTH_MAP; j++)
			{
				if (TileMap[i][j] == 'g')  mapSprite.setTextureRect(sf::IntRect(0, 0, 120, 120));
				if (TileMap[i][j] == 'f')  mapSprite.setTextureRect(sf::IntRect(120, 0, 120, 120));
				if (TileMap[i][j] == 's')  mapSprite.setTextureRect(sf::IntRect(240, 0, 120, 120));
				mapSprite.setPosition(j * 120, i * 120);
				window.draw(mapSprite);
			}
		}

		for (int i = 0; i < firstPlayer->getPlayerActiveArmy().size(); i++)
		{
			//if (isFirstSpawn) {
			//	tempSpawn = (float)(i * 200);
			//	pullGame.at(i).at(0)->setArmySpawnCoordinates(tempSpawn, 0);
			//}

			shapeAttack.setPosition(firstPlayer->getPlayerActiveArmy().at(i)->getArmySpawnCoordinateX() + 25, firstPlayer->getPlayerActiveArmy().at(i)->getArmySpawnCoordinateY() + 125);
			shapeHealth.setPosition(firstPlayer->getPlayerActiveArmy().at(i)->getArmySpawnCoordinateX() + 125, firstPlayer->getPlayerActiveArmy().at(i)->getArmySpawnCoordinateY() + 125);

			if (firstPlayer->getPlayerActiveArmy().at(i)->getArmyAttackNow() < 10)
			{
				textAttack.setPosition(firstPlayer->getPlayerActiveArmy().at(i)->getArmySpawnCoordinateX() + 42, firstPlayer->getPlayerActiveArmy().at(i)->getArmySpawnCoordinateY() + 125);
			}
			else
			{
				textAttack.setPosition(firstPlayer->getPlayerActiveArmy().at(i)->getArmySpawnCoordinateX() + 32, firstPlayer->getPlayerActiveArmy().at(i)->getArmySpawnCoordinateY() + 125);
			}

			if (firstPlayer->getPlayerActiveArmy().at(i)->getArmyHealthNow() < 10)
			{
				textHealth.setPosition(firstPlayer->getPlayerActiveArmy().at(i)->getArmySpawnCoordinateX() + 141, firstPlayer->getPlayerActiveArmy().at(i)->getArmySpawnCoordinateY() + 125);
			}
			else
			{
				textHealth.setPosition(firstPlayer->getPlayerActiveArmy().at(i)->getArmySpawnCoordinateX() + 133, firstPlayer->getPlayerActiveArmy().at(i)->getArmySpawnCoordinateY() + 125);
			}

			textAttack.setString(std::to_string(firstPlayer->getPlayerActiveArmy().at(i)->getArmyAttackNow()));
			textHealth.setString(std::to_string(firstPlayer->getPlayerActiveArmy().at(i)->getArmyHealthNow()));

			window.draw(firstPlayer->getPlayerActiveArmy().at(i)->getArmySprite());
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

		isFirstSpawn = false;

		window.display();
	}		
	
	return 0;
}