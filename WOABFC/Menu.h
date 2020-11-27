#pragma once
#include <SFML/Graphics.hpp>
#include "map.h"
#include <time.h>

void menu(sf::RenderWindow& window) 
{
	int randomNumberBackground;
	srand(time(NULL));
	randomNumberBackground = rand() % 10;
	sf::Texture menuBackgroundTexture, menuButtonTexture;
	menuBackgroundTexture.loadFromFile("images/map.png");
	menuButtonTexture.loadFromFile("images/infobackground.jpg");
	sf::Sprite menuBackgroundSprite(menuBackgroundTexture), menuButtonSpriteExit(menuButtonTexture);
	menuButtonSpriteExit.setScale(1.18f, 0.2f);
	sf::Sprite menuButtonSpriteSingle = menuButtonSpriteExit, menuButtonSpriteMulti = menuButtonSpriteExit, menuButtonSpriteSettings = menuButtonSpriteExit, menuButtonHelp = menuButtonSpriteExit;
	
	menuButtonSpriteSingle.setPosition(760, 190);
	menuButtonSpriteMulti.setPosition(760, 340);
	menuButtonSpriteSettings.setPosition(760, 490);
	menuButtonHelp.setPosition(760, 640);
	menuButtonSpriteExit.setPosition(760, 790);

	sf::Font font;
	font.loadFromFile("16249.ttf");

	sf::Text textMenuSingle;
	textMenuSingle.setFont(font);
	textMenuSingle.setOutlineColor(sf::Color::Black);
	textMenuSingle.setStyle(sf::Text::Bold);
	textMenuSingle.setCharacterSize(75);
	textMenuSingle.setOutlineThickness(4);
	
	sf::Text textMenuMulti = textMenuSingle, textMenuSettings = textMenuSingle, textMenuHelp = textMenuSingle, textMenuExit = textMenuSingle;
	textMenuSingle.setString("Tutorial");
	textMenuMulti.setString("Multiplayer");
	textMenuSettings.setString("Settings");
	textMenuHelp.setString("How to play");
	textMenuExit.setString("Exit");

	textMenuSingle.setPosition(830, 190);
	textMenuMulti.setPosition(780, 340);
	textMenuSettings.setPosition(830, 490);
	textMenuHelp.setPosition(770, 640);
	textMenuExit.setPosition(900, 790);

	bool isMenu = 1;
	int menuNum = 0;

	while (isMenu)
	{
		sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

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

		window.draw(menuButtonSpriteSingle);
		window.draw(menuButtonSpriteMulti);
		window.draw(menuButtonSpriteSettings);
		window.draw(menuButtonHelp);
		window.draw(menuButtonSpriteExit);

		window.draw(textMenuSingle);
		window.draw(textMenuMulti);
		window.draw(textMenuSettings);
		window.draw(textMenuHelp);
		window.draw(textMenuExit);

		menuButtonSpriteSingle.setColor(sf::Color::White);
		menuButtonSpriteMulti.setColor(sf::Color::White);
		menuButtonSpriteSettings.setColor(sf::Color::White);
		menuButtonHelp.setColor(sf::Color::White);
		menuButtonSpriteExit.setColor(sf::Color::White);

		menuNum = 0;

		if (menuButtonSpriteSingle.getGlobalBounds().contains((float)mousePosition.x, (float)mousePosition.y)) { menuButtonSpriteSingle.setColor(sf::Color(128, 128, 128)); menuNum = 1; }
		if (menuButtonSpriteMulti.getGlobalBounds().contains((float)mousePosition.x, (float)mousePosition.y)) { menuButtonSpriteMulti.setColor(sf::Color(128, 128, 128)); menuNum = 2; }
		if (menuButtonSpriteSettings.getGlobalBounds().contains((float)mousePosition.x, (float)mousePosition.y)) { menuButtonSpriteSettings.setColor(sf::Color(128, 128, 128)); menuNum = 3; }
		if (menuButtonHelp.getGlobalBounds().contains((float)mousePosition.x, (float)mousePosition.y)) { menuButtonHelp.setColor(sf::Color(128, 128, 128)); menuNum = 4; }
		if (menuButtonSpriteExit.getGlobalBounds().contains((float)mousePosition.x, (float)mousePosition.y)) { menuButtonSpriteExit.setColor(sf::Color(128, 128, 128)); menuNum = 5; }


		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (menuNum == 1) isMenu = false;
			//if (menuNum == 2) { window.draw(about); window.display(); while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)); }
			if (menuNum == 5) { window.close(); isMenu = false; }

		}

		window.display();
	}
}