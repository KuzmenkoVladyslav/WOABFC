#pragma once
#include <SFML\Graphics.hpp>

static int state;

static int getState()
{
	return state;
}

static void setState(int newState)
{
	state = newState;
}

static sf::String languageEnglish[24] = {
	"Tutorial",
	"Multiplayer",
	"Settings",
	"How to play",
	"Exit",
	"Era: ",
	"Name: ",
	"Type: ",
	"Ancient",
	"Classic",
	"Medival",
	"Renaissancee",
	"Industrial",
	"Modern",
	"Atomic",
	"Information",
	"Future",
	"Meele\nTake half damage from Ranged squads.",
	"Range\nIgnore enemy damage when the attack.\nCan't damage enemy when was attacked.",
	"Cavalry\nCan attack twice each turn.",
	"Anti-Cavalry\nDeal double damage to Cavalry squads.\nIf a Cavalry squad attacks an Anti-Cavalry\nwith its first hit of a turn, it loses the ability\nto attack a second time that turn.",
	"Anti-Cavalry Cavalry\nCan attack twice each turn.\nDeal double damage to Cavalry squads.\nIf a Cavalry squad attacks an Anti-Cavalry\nwith its first hit of a turn, it loses the ability\nto attack a second time that turn.",
	"Doesn't have uniqe ability.",
	""
};

static sf::String languageRussian[24] = {
	L"��������",
	L"��������������������� ����",
	L"���������",
	L"��� ������",
	L"�����",
	L"�����: ",
	L"��������: ",
	L"���: ",
	L"������� ���",
	L"������������ ���",
	L"�������������",
	L"����� �����������",
	L"�������������� ���",
	L"����� �����",
	L"����� �����",
	L"�������������� ���",
	L"�������",
	L"������� ���\n�������� �������� ����� �� ����� �������� ���.",
	L"������� ���\n���������� ���� ���������� ����� �������.\n�� ������� ���� � ����� ����� ��� ��������.",
	L"���������\n����� ��������� ������ �� ���� ���.",
	L"����-���������\n������� ������� ���� ������� ���������\n����������. ���� ������������� ����� ��������\n����-������������� �� ���� ������ ����� �� ���,\n�� �� ������ ����������� ��������� ������ ���\n�� ���� ���.",
	L"����-������������� ���������\n����� ��������� ������ �� ���� ���.\n������� ������� ���� ������� ���������\n����������. ���� ������������� ����� ��������\n����-������������� �� ���� ������ ����� �� ���,\n�� �� ������ ����������� ��������� ������ ���\n�� ���� ���.",
	L"��� ���������� ������������.",
	L""
};

static sf::String languageUkrainian[24] = {
	L"��������",
	L"������ ����������������� ���",
	L"������������",
	L"�� �����",
	L"�����",
	L"�����: ",
	L"�����: ",
	L"���: ",
	L"���������� ���",
	L"�������� ���",
	L"������������",
	L"����� ³���������",
	L"������������ ���",
	L"����� ���",
	L"����� �����",
	L"������������ ���",
	L"�������",
	L"������ ��\n������ �������� ����� �� �����\n��������� ���.",
	L"������ ��\n������ ����� ������������ ���� �����.\n�� �������� ����� � �������\n���� ��� ����������.",
	L"��������\n���� ��������� ���� �� ���� ���.",
	L"����-��������\n�������� ������� ����� ������� �������\n������������. ���� ������������ ���� ��������\n����-������������ �� ���� ������ ����� �� ���,\n�� �� ������ ������������������ ������ ���\n�� ��� ���.",
	L"����-����������� ��������\n���� ��������� ���� �� ���� ���.\n�������� ������� ����� ������� �������\n������������. ���� ������������ ���� ��������\n����-������������ �� ���� ������ ����� �� ���,\n�� �� ������ ������������������ ������ ���\n�� ��� ���.",
	L"���� ��������� ���������.",
	L""
};

static sf::String languageString(int indexOfString)
{
	switch (state)
	{
	case 0:
		return languageEnglish[indexOfString];
		break;
	case 1:
		return languageRussian[indexOfString];
		break;
	case 2:
		return languageUkrainian[indexOfString];
		break;
	default:
		return "";
		break;
	}
}