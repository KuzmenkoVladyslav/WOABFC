#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <thread>

#include "Army.h"
#include "map.h"

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

		sf::Clock clock;
		float timerOfLoaging = 0.0f;

		while (window.isOpen())
		{
			float time = (float)clock.getElapsedTime().asMicroseconds();
			clock.restart();
			time = time / 800;

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
					if (timerOfLoaging > 250)
					{
						nowSpriteDrawing++;
						if (nowSpriteDrawing > 8)
						{
							nowSpriteDrawing = 1;
						}
						timerOfLoaging = 0;
						break;
					}
				}
			}

			if (windowClose)
			{
				window.close();
			}

			timerOfLoaging += time;

			window.display();
		}
	});

	std::vector <std::vector <Army*>> pullGame;
	std::vector <Army*> pullAncient, pullClassic, pullMedival, pullRenaissancee, pullIndustrial, pullModern, pullAtomic, pullInfromation, pullFuture;

	std::thread threadAncientClassicMedival([&pullAncient, &pullClassic, &pullMedival]()
	{
		for (size_t i = 0; i < 16; i++)
		{
			pullAncient.push_back(new Squad(enumSquad::SQUAD_WARRIOR));
			pullAncient.push_back(new Squad(enumSquad::SQUAD_ARCHER));
			pullAncient.push_back(new Squad(enumSquad::SQUAD_HOURSEARCHER));
			pullAncient.push_back(new Squad(enumSquad::SQUAD_SPEARMAN));
			pullClassic.push_back(new Squad(enumSquad::SQUAD_SWORDSMAN));
			pullClassic.push_back(new Squad(enumSquad::SQUAD_LONGBOWARCHER));
			pullClassic.push_back(new Squad(enumSquad::SQUAD_HORSEMAN));
			pullClassic.push_back(new Squad(enumSquad::SQUAD_HOPLITE));
			pullMedival.push_back(new Squad(enumSquad::SQUAD_LONGSWORDSMAN));
			pullMedival.push_back(new Squad(enumSquad::SQUAD_CROSSBOWMAN));
			pullMedival.push_back(new Squad(enumSquad::SQUAD_KNIGHT));
			pullMedival.push_back(new Squad(enumSquad::SQUAD_PIKEMAN));
		}
	});

	std::thread threadRenaissanceeIndustrial([&pullRenaissancee, &pullIndustrial]()
	{
		for (size_t i = 0; i < 16; i++)
		{
			pullRenaissancee.push_back(new Squad(enumSquad::SQUAD_HARQUEBUSIER));
			pullRenaissancee.push_back(new Squad(enumSquad::SQUAD_CANNON));
			pullRenaissancee.push_back(new Squad(enumSquad::SQUAD_LANCER));
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

	std::thread threadAtomicInformation([&pullAtomic, &pullInfromation]()
	{
		for (size_t i = 0; i < 8; i++)
		{
			pullAtomic.push_back(new Squad(enumSquad::SQUAD_SEAINFANTRYMAN));
			pullAtomic.push_back(new Squad(enumSquad::SQUAD_BAZOOKA));
			pullAtomic.push_back(new Squad(enumSquad::SQUAD_TANK));
			pullAtomic.push_back(new Squad(enumSquad::SQUAD_ANTITANKCANNON));
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

	threadAncientClassicMedival.join();
	threadRenaissanceeIndustrial.join();
	threadModern.join();
	threadAtomicInformation.join();
	threadFuture.join();
	threadLoading.detach();

	pullGame.push_back(pullAncient);
	pullGame.push_back(pullClassic);
	pullGame.push_back(pullMedival);
	pullGame.push_back(pullRenaissancee);
	pullGame.push_back(pullIndustrial);
	pullGame.push_back(pullModern);
	pullGame.push_back(pullAtomic);
	pullGame.push_back(pullInfromation);
	pullGame.push_back(pullFuture);

	windowClose = true;

	return pullGame;
}