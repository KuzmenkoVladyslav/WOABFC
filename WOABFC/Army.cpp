#include "Army.h"
#include "StringsInfo.h"

sf::Sprite Army::getArmySprite()
{
    return this->armySprite;
}

float Army::getArmySpawnCoordinateX()
{
    return this->armySpawnCoordinateX;
}

float Army::getArmySpawnCoordinateY()
{
    return this->armySpawnCoordinateY;
}

float Army::getArmySpriteCoordinateX()
{
    return this->armySpriteCoordinateX;
}

float Army::getArmySpriteCoordinateY()
{
    return this->armySpriteCoordinateY;
}

int Army::getArmyAttackNow()
{
    return this->armyAttackNow;
}

int Army::getArmyHealthNow()
{
    return this->armyHealthNow;
}

void Army::setArmySpawnCoordinateX(float armySpawnCoordinateX)
{
    this->armySpawnCoordinateX = armySpawnCoordinateX;
    this->armySprite.setPosition(this->armySpawnCoordinateX, this->armySpawnCoordinateY);
}

void Army::setArmySpawnCoordinateY(float armySpawnCoordinateY)
{
    this->armySpawnCoordinateY = armySpawnCoordinateY;
    this->armySprite.setPosition(this->armySpawnCoordinateX, this->armySpawnCoordinateY);
}

void Army::setArmySpawnCoordinates(float armySpawnCoordinateX, float armySpawnCoordinateY)
{
    this->armySpawnCoordinateX = armySpawnCoordinateX;
    this->armySpawnCoordinateY = armySpawnCoordinateY;
    this->armySprite.setPosition(this->armySpawnCoordinateX, this->armySpawnCoordinateY);
}

std::string Army::getArmyName()
{
    return this->armyName;
}

sf::String Army::getStringEraName()
{
    switch (eraName)
    {
    case enumEraName::ERA_ANCIENT: return languageInfoString(8);
    case enumEraName::ERA_CLASSIC: return languageInfoString(9);
    case enumEraName::ERA_MEDIVAL: return languageInfoString(10);
    case enumEraName::ERA_RENAISSANCEE: return languageInfoString(11);
    case enumEraName::ERA_INDUSTRIAL: return languageInfoString(12);
    case enumEraName::ERA_MODERN: return languageInfoString(13);
    case enumEraName::ERA_ATOMIC: return languageInfoString(14);
    case enumEraName::ERA_INFORMATION: return languageInfoString(15);
    case enumEraName::ERA_FUTURE: return languageInfoString(16);
    default: return languageInfoString(23);
    }
}

sf::String Army::getStringArmyType()
{
    switch (armyType)
    {
    case enumTypeSquad::TYPE_MEELE: return languageInfoString(17);
    case enumTypeSquad::TYPE_RANGE: return languageInfoString(18);
    case enumTypeSquad::TYPE_CAVALRY: return languageInfoString(19);
    case enumTypeSquad::TYPE_ANTICAVALRY: return languageInfoString(20);
    case enumTypeSquad::TYPE_ANTICAVALRYCAVALRY: return languageInfoString(21);
    case enumTypeSquad::TYPE_NONE: return languageInfoString(22);
    default: return languageInfoString(23);
    }
}

sf::String Army::getStringTextInfo() 
{
    return languageInfoString(5) + getStringEraName() + "\n" + languageInfoString(6) + getArmyName() + "\n" + languageInfoString(7) + getStringArmyType();
}

enumTypeSquad Army::getArmyType()
{
    return this->armyType;
}

enumEraName Army::getEraName()
{
    return this->eraName;
}

enumSquad Army::getArmyUpgrade()
{
    return this->armyUpgrade;
}