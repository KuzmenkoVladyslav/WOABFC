#include <SFML/Graphics.hpp>
#include <iostream> 
#include "Army.h"
#include "Squad.h"
#include "enumSquad.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "test window");	

	Army* squadWarrior = new Squad(enumSquad::SQUAD_ROBOT);

	while (window.isOpen())
	{


		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(squadWarrior->getArmySprite());

		window.display();
	}

	return 0;
}