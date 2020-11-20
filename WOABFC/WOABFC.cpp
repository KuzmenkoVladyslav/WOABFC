#include <SFML/Graphics.hpp>
#include <iostream> 
#include "Army.h"
#include "Squad.h"
#include "enumSquad.h"
#include <vector>
#include <sstream>
#include <thread>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "War of Ages: Battle for Castle", sf::Style::Fullscreen);
	std::vector <std::vector <Army*>> pullGame(9);
	std::vector <Army*> pullAncient(64), pullClassic(64), pullMedival(64), pullRenaissancee(48), pullIndustrial(48), pullModern(48), pullAtomic(32), pullInfromation(32), pullFuture(12);
	Army* addSquadUnit;
	
	float tempSpawn;

	sf::Font font;
	font.loadFromFile("16249.ttf");

	sf::Text textAttack;	
	textAttack.setFont(font);	
	textAttack.setOutlineColor(sf::Color::Black);
	textAttack.setStyle(sf::Text::Bold);

	sf::Text textInfo = textAttack;
	textInfo.setCharacterSize(35);
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
	textureInfo.loadFromFile("images/missionbg.jpg");
	sf::Sprite spriteInfo;
	spriteInfo.setTexture(textureInfo);
	spriteInfo.setTextureRect(sf::IntRect(0, 0, 340, 510));  //приведение типов, размеры картинки исходные
	spriteInfo.setScale(2.5f, 0.7f);
	spriteInfo.setPosition(window.getSize().x / 2.0 - 400.0, window.getSize().y / 2.0 - 100.0);

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

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (showInfoReRender)
			{
				for (int i = 0; i < 9; i++)
				{
					if (pullGame.at(i).at(0)->getArmySprite().getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y))
					{
						showInfoParameter = i;
						showInfoReRender = false;

						switch (showInfoText)
						{
						case true:
							textInfo.setString("Era: " + pullGame.at(i).at(0)->getStringEraName() + "\n" +
								"Name: " + pullGame.at(i).at(0)->getArmyName() + "\n" +
								"Type: " + pullGame.at(i).at(0)->getStringArmyType());
							showInfoText = false;
							textInfo.setPosition(window.getSize().x / 2.0 - 250.0, window.getSize().y / 2.0 - 50.0);
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

			if (!pullGame.at(showInfoParameter).at(0)->getArmySprite().getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y))
			{
				showInfoReRender = true;
				showInfoText = true;
			}			
		}

		window.clear();

		for (int i = 0; i < 9; i++) 
		{
			tempSpawn = (float)(i * 200);
			pullGame.at(i).at(0)->setArmySpawnCoordinateX(tempSpawn);
			shapeAttack.setPosition(pullGame.at(i).at(0)->getArmySpawnCoordinateX() + 25, pullGame.at(i).at(0)->getArmySpawnCoordinateY() + 125);
			shapeHealth.setPosition(pullGame.at(i).at(0)->getArmySpawnCoordinateX() + 125, pullGame.at(i).at(0)->getArmySpawnCoordinateY() + 125);

			if (pullGame.at(i).at(0)->getArmyAttackNow() < 10)
			{
				textAttack.setPosition(pullGame.at(i).at(0)->getArmySpawnCoordinateX() + 42, pullGame.at(i).at(0)->getArmySpawnCoordinateY() + 125);
			}
			else
			{
				textAttack.setPosition(pullGame.at(i).at(0)->getArmySpawnCoordinateX() + 32, pullGame.at(i).at(0)->getArmySpawnCoordinateY() + 125);
			}

			if (pullGame.at(i).at(0)->getArmyHealthNow() < 10)
			{
				textHealth.setPosition(pullGame.at(i).at(0)->getArmySpawnCoordinateX() + 141, pullGame.at(i).at(0)->getArmySpawnCoordinateY() + 125);
			}
			else
			{
				textHealth.setPosition(pullGame.at(i).at(0)->getArmySpawnCoordinateX() + 133, pullGame.at(i).at(0)->getArmySpawnCoordinateY() + 125);
			}

			textAttack.setString(std::to_string(pullGame.at(i).at(0)->getArmyAttackNow()));
			textHealth.setString(std::to_string(pullGame.at(i).at(0)->getArmyHealthNow()));

			if(!showInfoText) 
			{ 
				window.draw(spriteInfo); 
				window.draw(textInfo); 
			}

			window.draw(pullGame.at(i).at(0)->getArmySprite());
			window.draw(shapeAttack);
			window.draw(shapeHealth);
			window.draw(textAttack);
			window.draw(textHealth);
		}

		window.display();
	}

	return 0;
}