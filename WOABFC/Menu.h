#pragma once
#include <SFML/Graphics.hpp>
#include "map.h"
#include <time.h>
#include "Strings.h"

void settings();
void help();

void menu() 
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "War of Ages: Battle for Castle", sf::Style::None);
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

	if (getLanguageState() == 0)
	{
		textMenuSingle.setPosition(835, 190);
		textMenuMulti.setPosition(780, 340);
		textMenuSettings.setPosition(830, 490);
		textMenuHelp.setPosition(770, 640);
		textMenuExit.setPosition(900, 790);
	}
	else if (getLanguageState() == 1)
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
			if (menuNum == 2) { /* do nothing  */ }
			if (menuNum == 3) { window.close(); settings(); }
			if (menuNum == 4) { window.close(); help(); }
			if (menuNum == 5) { window.close(); exit(1); }
		}

		window.display();
	}
}

void settings()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "War of Ages: Battle for Castle", sf::Style::None);
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
			case 1: window.close(); setLanguageState(0); menu(); break;
			case 2: window.close(); setLanguageState(1); menu(); break;
			case 3: window.close(); setLanguageState(2); menu(); break;
			default:
				break;
			}
		}

		window.display();
	}
}

void help()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "War of Ages: Battle for Castle", sf::Style::None);
	window.setVerticalSyncEnabled(true);

	sf::Texture deleteTexture;
	deleteTexture.loadFromFile("images/trash.png");
	sf::Sprite deleteSprite;
	deleteSprite.setTexture(deleteTexture);
	deleteSprite.setScale(0.5f, 0.5f);

	sf::Texture leftArrowTexture;
	leftArrowTexture.loadFromFile("images/arrowLeft.png");
	sf::Sprite leftArrowSprite;
	leftArrowSprite.setTexture(leftArrowTexture);
	leftArrowSprite.setPosition(30.0f, 918.0f);

	sf::Texture rightArrowTexture;
	rightArrowTexture.loadFromFile("images/arrowRight.png");
	sf::Sprite rightArrowSprite;
	rightArrowSprite.setTexture(rightArrowTexture);
	rightArrowSprite.setPosition(1758.0f, 918.0f);

	sf::Texture heatlhTexture;
	heatlhTexture.loadFromFile("images/heart.png");
	sf::Sprite healthSprite;
	healthSprite.setTexture(heatlhTexture);
	healthSprite.setScale(0.5f, 0.5f);
	healthSprite.setPosition(200.0f, 50.0f);

	sf::Texture coinTexture;
	coinTexture.loadFromFile("images/coin.png");
	sf::Sprite coinSprite;
	coinSprite.setTexture(coinTexture);
	coinSprite.setScale(0.2f, 0.2f);
	coinSprite.setPosition(200.0f, 250.0f);

	sf::Texture refreshTexture;
	refreshTexture.loadFromFile("images/refresh.png");
	sf::Sprite refreshSprite;
	refreshSprite.setTexture(refreshTexture);
	refreshSprite.setScale(0.25f, 0.25f);
	refreshSprite.setPosition(200.0f, 450.0f);

	sf::Texture upTexture;
	upTexture.loadFromFile("images/up.png");
	sf::Sprite upSprite;
	upSprite.setTexture(upTexture);
	upSprite.setScale(0.25f, 0.25f);
	upSprite.setPosition(200.0f, 650.0f);

	sf::Texture addPlaceTexture;
	addPlaceTexture.loadFromFile("images/addPlace.png");
	sf::Sprite addPlaceSprite;
	addPlaceSprite.setTexture(addPlaceTexture);
	addPlaceSprite.setScale(0.25f, 0.25f);
	addPlaceSprite.setPosition(200.0f, 850.0f);

	sf::Texture battleTexture;
	battleTexture.loadFromFile("images/battle.png");
	sf::Sprite battleSprite;
	battleSprite.setTexture(battleTexture);
	battleSprite.setScale(0.78f, 0.78f);
	battleSprite.setPosition(200.0f, 50.0f);

	sf::Texture deleteTextureInfo;
	deleteTextureInfo.loadFromFile("images/trash.png");
	sf::Sprite deleteSpriteInfo;
	deleteSpriteInfo.setTexture(deleteTextureInfo);
	deleteSpriteInfo.setPosition(200.0f, 250.0f);

	sf::Texture rightClickTexture;
	rightClickTexture.loadFromFile("images/rightClick.png");
	sf::Sprite rightClickSprite;
	rightClickSprite.setTexture(rightClickTexture);
	rightClickSprite.setPosition(255.0f, 500.0f);
	rightClickSprite.setScale(1.25f, 1.25f);

	sf::Texture leftClickTexture;
	leftClickTexture.loadFromFile("images/leftClick.png");
	sf::Sprite leftClickSprite;
	leftClickSprite.setTexture(leftClickTexture);
	leftClickSprite.setPosition(255.0f, 750.0f);
	leftClickSprite.setScale(1.25f, 1.25f);

	sf::Font font;
	font.loadFromFile("16249.ttf");

	sf::Text textPlayerHealth;
	textPlayerHealth.setFont(font);
	textPlayerHealth.setStyle(sf::Text::Bold);
	textPlayerHealth.setFillColor(sf::Color(155, 17, 30));
	textPlayerHealth.setOutlineColor(sf::Color::White);
	textPlayerHealth.setOutlineThickness(2);
	textPlayerHealth.setCharacterSize(60);
	textPlayerHealth.setPosition(330.0f, 65.0f);
	textPlayerHealth.setString("50");

	sf::Text textInfoPlayerHealth;
	textInfoPlayerHealth.setFont(font);
	textInfoPlayerHealth.setStyle(sf::Text::Bold);
	textInfoPlayerHealth.setOutlineColor(sf::Color::Black);
	textInfoPlayerHealth.setOutlineThickness(2);
	textInfoPlayerHealth.setCharacterSize(40);
	textInfoPlayerHealth.setPosition(560.0f, 65.0f);
	textInfoPlayerHealth.setString(languageString(26));

	sf::Text textCoinCount = textPlayerHealth;
	textCoinCount.setFillColor(sf::Color(184, 134, 11));
	textCoinCount.setOutlineThickness(2);
	textCoinCount.setPosition(330.0f, 265.0f);
	textCoinCount.setString("4 / 6");

	sf::Text textInfoCointCount = textInfoPlayerHealth;
	textInfoCointCount.setPosition(560.0f, 265.0f);
	textInfoCointCount.setString(languageString(27));

	sf::Text textInfoRefreshSprite = textInfoPlayerHealth;
	textInfoRefreshSprite.setPosition(560.0f, 485.0f);
	textInfoRefreshSprite.setString(languageString(28));

	sf::Text textInfoUpSprite = textInfoPlayerHealth;
	textInfoUpSprite.setPosition(560.0f, 685.0f);
	textInfoUpSprite.setString(languageString(29));

	sf::Text textInfoAddPlaceSprite = textInfoPlayerHealth;
	textInfoAddPlaceSprite.setPosition(560.0f, 885.0f);
	textInfoAddPlaceSprite.setString(languageString(30));

	sf::Text textInfobattleSprite = textInfoPlayerHealth;
	textInfobattleSprite.setPosition(510.0f, 115.0f);
	textInfobattleSprite.setString(languageString(31));

	sf::Text textInfoDeleteTexture = textInfoPlayerHealth;
	textInfoDeleteTexture.setPosition(510.0f, 245.0f);
	textInfoDeleteTexture.setString(languageString(32));

	sf::Text textInfoRightClick = textInfoPlayerHealth;
	textInfoRightClick.setPosition(510.0f, 465.0f);
	textInfoRightClick.setString(languageString(33));

	sf::Text textInfoLeftClick = textInfoPlayerHealth;
	textInfoLeftClick.setPosition(510.0f, 765.0f);
	textInfoLeftClick.setString(languageString(34));

	int randomNumberBackground;
	srand((unsigned)time(NULL));
	randomNumberBackground = rand() % 10;
	sf::Texture menuBackgroundTexture;
	menuBackgroundTexture.loadFromFile("images/map.png");
	sf::Sprite menuBackgroundSprite(menuBackgroundTexture);

	int helpState = 0;

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

			if (event.type == sf::Event::MouseButtonReleased)
			{
				if (event.key.code == sf::Mouse::Left)
				{
					if (deleteSprite.getGlobalBounds().contains((float)mousePosition.x, (float)mousePosition.y)) 
					{ 
						window.close(); menu();
					}

					if (leftArrowSprite.getGlobalBounds().contains((float)mousePosition.x, (float)mousePosition.y)) 
					{ 
						helpState--;
					}

					if (rightArrowSprite.getGlobalBounds().contains((float)mousePosition.x, (float)mousePosition.y)) 
					{ 
						helpState++;
					}
				}
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

		if (helpState == 0)
		{
			window.draw(healthSprite);
			window.draw(textPlayerHealth);
			window.draw(textInfoPlayerHealth);
			window.draw(coinSprite);
			window.draw(textCoinCount);
			window.draw(textInfoCointCount);
			window.draw(refreshSprite);
			window.draw(upSprite);
			window.draw(addPlaceSprite);
			window.draw(textInfoRefreshSprite);
			window.draw(textInfoUpSprite);
			window.draw(textInfoAddPlaceSprite);
		}
		else if (helpState == 1)
		{
			window.draw(battleSprite);
			window.draw(textInfobattleSprite);
			window.draw(deleteSpriteInfo);
			window.draw(rightClickSprite);
			window.draw(leftClickSprite);
			window.draw(textInfoDeleteTexture);
			window.draw(textInfoRightClick);
			window.draw(textInfoLeftClick);
		}

		window.draw(deleteSprite);

		if (helpState > 0) 
		{
			window.draw(leftArrowSprite);
		}

		if (helpState < 1)
		{
			window.draw(rightArrowSprite);
		}

		window.display();
	}
}