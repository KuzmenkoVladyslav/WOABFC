#pragma once

#include <SFML\Graphics.hpp>

int languageMenuNow = 0;

sf::String languageMenuEnglish[5] = {
	"Tutorial",
	"Multiplayer",
	"Settings",
	"How to play",
	"Exit"
};

sf::String languageMenuRussian[5] = {
	L"��������",
	L"��������������������� ����",
	L"���������",
	L"��� ������",
	L"�����"
};

sf::String languageMenuUkrainian[5] = {
	L"��������",
	L"������ ����������������� ���",
	L"������������",
	L"�� �����",
	L"�����"
};

sf::String languageMenuString(int indexOfString)
{
	switch (languageMenuNow)
	{
	case 0:
		return languageMenuEnglish[indexOfString];
		break;
	case 1:
		return languageMenuRussian[indexOfString];
		break;
	case 2:
		return languageMenuUkrainian[indexOfString];
		break;
	default:
		return "";
		break;
	}
}