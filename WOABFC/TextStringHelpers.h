#pragma once
#include <SFML/Graphics.hpp>

sf::String getStringEraName(enumEraName eraName)
{
	switch (eraName)
	{
	case enumEraName::ERA_ANCIENT: return languageString(8);
	case enumEraName::ERA_CLASSIC: return languageString(9);
	case enumEraName::ERA_MEDIVAL: return languageString(10);
	case enumEraName::ERA_RENAISSANCEE: return languageString(11);
	case enumEraName::ERA_INDUSTRIAL: return languageString(12);
	case enumEraName::ERA_MODERN: return languageString(13);
	case enumEraName::ERA_ATOMIC: return languageString(14);
	case enumEraName::ERA_INFORMATION: return languageString(15);
	case enumEraName::ERA_FUTURE: return languageString(16);
	default: return languageString(23);
	}
}

sf::String getStringArmyType(enumTypeSquad armyType)
{
	switch (armyType)
	{
	case enumTypeSquad::TYPE_MEELE: return languageString(17);
	case enumTypeSquad::TYPE_RANGE: return languageString(18);
	case enumTypeSquad::TYPE_CAVALRY: return languageString(19);
	case enumTypeSquad::TYPE_ANTICAVALRY: return languageString(20);
	case enumTypeSquad::TYPE_ANTICAVALRYCAVALRY: return languageString(21);
	case enumTypeSquad::TYPE_NONE: return languageString(22);
	default: return languageString(23);
	}
}

sf::String getStringTextInfo(Army* tempArmy)
{
	return languageString(5) + getStringEraName(tempArmy->getEraName()) + "\n" + languageString(6) + tempArmy->getArmyName() + "\n" + languageString(7) + getStringArmyType(tempArmy->getArmyType());
}
