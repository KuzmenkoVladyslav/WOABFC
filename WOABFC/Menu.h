#pragma once
#include <SFML/Graphics.hpp>
#include "map.h"
#include <time.h>
#include "Strings.h"

void settings();

void menu() 
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "War of Ages: Battle for Castle (MENU)", sf::Style::Fullscreen);
	window.setVerticalSyncEnabled(true);
	setlocale(LC_ALL, "");
	int randomNumberBackground;
	srand((unsigned)time(NULL));
	randomNumberBackground = rand() % 10;
	sf::Texture menuBackgroundTexture, menuButtonTexture;
	menuBackgroundTexture.loadFromFile("images/map.png");
	menuButtonTexture.loadFromFile("images/infobackground.jpg");
	sf::Sprite menuBackgroundSprite(menuBackgroundTexture), menuButtonSpriteExit(menuButtonTexture);
	menuButtonSpriteExit.setScale(3.5f, 0.2f);
	sf::Sprite menuButtonSpriteSingle = menuButtonSpriteExit, menuButtonSpriteMulti = menuButtonSpriteExit, menuButtonSpriteSettings = menuButtonSpriteExit, menuButtonHelp = menuButtonSpriteExit;
	
	menuButtonSpriteSingle.setPosition(365, 190);
	menuButtonSpriteMulti.setPosition(365, 340);
	menuButtonSpriteSettings.setPosition(365, 490);
	menuButtonHelp.setPosition(365, 640);
	menuButtonSpriteExit.setPosition(365, 790);

	sf::Font font;
	font.loadFromFile("16249.ttf");

	sf::Text textMenuSingle;
	textMenuSingle.setFont(font);
	textMenuSingle.setOutlineColor(sf::Color::Black);
	textMenuSingle.setStyle(sf::Text::Bold);
	textMenuSingle.setCharacterSize(75);
	textMenuSingle.setOutlineThickness(4);
	
	sf::Text textMenuMulti = textMenuSingle, textMenuSettings = textMenuSingle, textMenuHelp = textMenuSingle, textMenuExit = textMenuSingle;
	textMenuSingle.setString(languageString(0));
	textMenuMulti.setString(languageString(1));
	textMenuSettings.setString(languageString(2));
	textMenuHelp.setString(languageString(3));
	textMenuExit.setString(languageString(4));

	if (getState() == 0)
	{
		textMenuSingle.setPosition(835, 190);
		textMenuMulti.setPosition(780, 340);
		textMenuSettings.setPosition(830, 490);
		textMenuHelp.setPosition(770, 640);
		textMenuExit.setPosition(900, 790);
	}
	else if (getState() == 1)
	{
		textMenuSingle.setPosition(835, 190);
		textMenuMulti.setPosition(470, 340);
		textMenuSettings.setPosition(790, 490);
		textMenuHelp.setPosition(785, 640);
		textMenuExit.setPosition(855, 790);
	}
	else 
	{
		textMenuSingle.setPosition(835, 190);
		textMenuMulti.setPosition(450, 340);
		textMenuSettings.setPosition(725, 490);
		textMenuHelp.setPosition(820, 640);
		textMenuExit.setPosition(860, 790);
	}

	int menuNum = 0;

	while (window.isOpen())
	{
		sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

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
		menuButtonSpriteMulti.setColor(sf::Color(128, 128, 128));
		menuButtonSpriteSettings.setColor(sf::Color::White);
		menuButtonHelp.setColor(sf::Color::White);
		menuButtonSpriteExit.setColor(sf::Color::White);

		menuNum = 0;

		if (menuButtonSpriteSingle.getGlobalBounds().contains((float)mousePosition.x, (float)mousePosition.y)) { menuButtonSpriteSingle.setColor(sf::Color(128, 128, 128)); menuNum = 1; }
		if (menuButtonSpriteMulti.getGlobalBounds().contains((float)mousePosition.x, (float)mousePosition.y)) {}
		if (menuButtonSpriteSettings.getGlobalBounds().contains((float)mousePosition.x, (float)mousePosition.y)) { menuButtonSpriteSettings.setColor(sf::Color(128, 128, 128)); menuNum = 3; }
		if (menuButtonHelp.getGlobalBounds().contains((float)mousePosition.x, (float)mousePosition.y)) { menuButtonHelp.setColor(sf::Color(128, 128, 128)); menuNum = 4; }
		if (menuButtonSpriteExit.getGlobalBounds().contains((float)mousePosition.x, (float)mousePosition.y)) { menuButtonSpriteExit.setColor(sf::Color(128, 128, 128)); menuNum = 5; }


		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (menuNum == 1) { window.close(); }
			//if (menuNum == 2) { window.draw(about); window.display(); while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)); }
			if (menuNum == 3) { window.close(); settings(); }
			//if (menuNum == 4) { window.close(); help (); }
			if (menuNum == 5) { window.close(); exit(1); }
		}

		window.display();
	}
}

void settings()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "War of Ages: Battle for Castle (SETTINGS)", sf::Style::Fullscreen);
	window.setVerticalSyncEnabled(true);
	int randomNumberBackground;
	srand((unsigned)time(NULL));
	randomNumberBackground = rand() % 10;
	sf::Texture menuBackgroundTexture;
	menuBackgroundTexture.loadFromFile("images/map.png");
	sf::Sprite menuBackgroundSprite(menuBackgroundTexture);
	
	sf::Texture settingsTextureEnglish, settingsTextureRussian, settingsTextureUkrainian;
	settingsTextureEnglish.loadFromFile("images/langEng.png");
	settingsTextureRussian.loadFromFile("images/langRus.png");
	settingsTextureUkrainian.loadFromFile("images/langUkr.png");
	sf::Sprite settingsSpriteEnglish(settingsTextureEnglish), settingsSpriteRussian(settingsTextureRussian), settingsSpriteUkrainian(settingsTextureUkrainian);
	
	settingsSpriteEnglish.setPosition(832, 412);
	settingsSpriteRussian.setPosition(432, 412);
	settingsSpriteUkrainian.setPosition(1232, 412);

	int settingsNum = 0;

	while (window.isOpen())
	{

		sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

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

		window.draw(settingsSpriteEnglish);
		window.draw(settingsSpriteRussian);
		window.draw(settingsSpriteUkrainian);

		settingsSpriteEnglish.setColor(sf::Color::White);
		settingsSpriteRussian.setColor(sf::Color::White);
		settingsSpriteUkrainian.setColor(sf::Color::White);

		settingsNum = 0;

		if (settingsSpriteEnglish.getGlobalBounds().contains((float)mousePosition.x, (float)mousePosition.y)) { settingsSpriteEnglish.setColor(sf::Color(128, 128, 128)); settingsNum = 1; }
		if (settingsSpriteRussian.getGlobalBounds().contains((float)mousePosition.x, (float)mousePosition.y)) { settingsSpriteRussian.setColor(sf::Color(128, 128, 128)); settingsNum = 2; }
		if (settingsSpriteUkrainian.getGlobalBounds().contains((float)mousePosition.x, (float)mousePosition.y)) { settingsSpriteUkrainian.setColor(sf::Color(128, 128, 128)); settingsNum = 3; }

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			switch (settingsNum)
			{
			case 1: window.close(); setState(0); menu(); break;
			case 2: window.close(); setState(1); menu(); break;
			case 3: window.close(); setState(2); menu(); break;
			default:
				break;
			}
		}

		window.display();
	}
}