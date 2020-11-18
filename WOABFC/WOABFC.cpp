#include <SFML/Graphics.hpp>
#include <iostream> 
#include "Army.h"
#include "Squad.h"
#include "enumSquad.h"
#include <vector>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "test window");
	std::vector <std::vector <Army*>> pullGame;
	std::vector <Army*> pullAncient, pullClassic, pullMedival, pullRenaissancee, pullIndustrial, pullModern, pullAtomic, pullInfromation, pullFuture;
	Army* addSquadUnit;

	for (int i = 0; i < 16; i++) 
	{
		addSquadUnit = new Squad(enumSquad::SQUAD_WARRIOR);
		pullAncient.push_back(addSquadUnit);
		addSquadUnit = new Squad(enumSquad::SQUAD_ARCHER);
		pullAncient.push_back(addSquadUnit);
		addSquadUnit = new Squad(enumSquad::SQUAD_HOURSEARCHER);
		pullAncient.push_back(addSquadUnit);
		addSquadUnit = new Squad(enumSquad::SQUAD_SPEARMAN);
		pullAncient.push_back(addSquadUnit);

		addSquadUnit = new Squad(enumSquad::SQUAD_SWORDSMAN);
		pullClassic.push_back(addSquadUnit);
		addSquadUnit = new Squad(enumSquad::SQUAD_LONGBOWARCHER);
		pullClassic.push_back(addSquadUnit);
		addSquadUnit = new Squad(enumSquad::SQUAD_HORSEMAN);
		pullClassic.push_back(addSquadUnit);
		addSquadUnit = new Squad(enumSquad::SQUAD_HOPLITE);
		pullClassic.push_back(addSquadUnit);

		addSquadUnit = new Squad(enumSquad::SQUAD_LONGSWORDSMAN);
		pullMedival.push_back(addSquadUnit);
		addSquadUnit = new Squad(enumSquad::SQUAD_CROSSBOWMAN);
		pullMedival.push_back(addSquadUnit);
		addSquadUnit = new Squad(enumSquad::SQUAD_KNIGHT);
		pullMedival.push_back(addSquadUnit);
		addSquadUnit = new Squad(enumSquad::SQUAD_PIKEMAN);
		pullMedival.push_back(addSquadUnit);

		addSquadUnit = new Squad(enumSquad::SQUAD_HARQUEBUSIER);
		pullRenaissancee.push_back(addSquadUnit);
		addSquadUnit = new Squad(enumSquad::SQUAD_CANNON);
		pullRenaissancee.push_back(addSquadUnit);
		addSquadUnit = new Squad(enumSquad::SQUAD_LANCER);
		pullRenaissancee.push_back(addSquadUnit);

		addSquadUnit = new Squad(enumSquad::SQUAD_MUSKETEER);
		pullIndustrial.push_back(addSquadUnit);
		addSquadUnit = new Squad(enumSquad::SQUAD_GATLING);
		pullIndustrial.push_back(addSquadUnit);
		addSquadUnit = new Squad(enumSquad::SQUAD_CAVALRY);
		pullIndustrial.push_back(addSquadUnit);
	}

	for (int i = 0; i < 12; i++) 
	{
		addSquadUnit = new Squad(enumSquad::SQUAD_INFANTRYMAN);
		pullModern.push_back(addSquadUnit);
		addSquadUnit = new Squad(enumSquad::SQUAD_MACHINGGUN);
		pullModern.push_back(addSquadUnit);
		addSquadUnit = new Squad(enumSquad::SQUAD_TANKETTE);
		pullModern.push_back(addSquadUnit);
		addSquadUnit = new Squad(enumSquad::SQUAD_ARTBATTERY);
		pullModern.push_back(addSquadUnit);
	}

	for (int i = 0; i < 8; i++)
	{
		addSquadUnit = new Squad(enumSquad::SQUAD_SEAINFANTRYMAN);
		pullAtomic.push_back(addSquadUnit);
		addSquadUnit = new Squad(enumSquad::SQUAD_BAZOOKA);
		pullAtomic.push_back(addSquadUnit);
		addSquadUnit = new Squad(enumSquad::SQUAD_TANK);
		pullAtomic.push_back(addSquadUnit);
		addSquadUnit = new Squad(enumSquad::SQUAD_ANTITANKCANNON);
		pullAtomic.push_back(addSquadUnit);

		addSquadUnit = new Squad(enumSquad::SQUAD_MOTORIZEDINFANTRY);
		pullInfromation.push_back(addSquadUnit);
		addSquadUnit = new Squad(enumSquad::SQUAD_ROCKET);
		pullInfromation.push_back(addSquadUnit);
		addSquadUnit = new Squad(enumSquad::SQUAD_MODERNTANK);
		pullInfromation.push_back(addSquadUnit);
		addSquadUnit = new Squad(enumSquad::SQUAD_ARTILLERY);
		pullInfromation.push_back(addSquadUnit);
	}

	for (int i = 0; i < 6; i++)
	{
		addSquadUnit = new Squad(enumSquad::SQUAD_FUTURESMAN);
		pullFuture.push_back(addSquadUnit);
		addSquadUnit = new Squad(enumSquad::SQUAD_ROBOT);
		pullFuture.push_back(addSquadUnit);
	}

	pullGame.push_back(pullAncient);
	pullGame.push_back(pullClassic);
	pullGame.push_back(pullMedival);
	pullGame.push_back(pullRenaissancee);
	pullGame.push_back(pullIndustrial);
	pullGame.push_back(pullModern);
	pullGame.push_back(pullAtomic);
	pullGame.push_back(pullInfromation);
	pullGame.push_back(pullFuture);

	while (window.isOpen())
	{


		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(pullAncient.at(0)->getArmySprite());

		window.display();
	}

	return 0;
}