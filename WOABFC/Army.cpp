#include "Army.h"

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

std::string Army::getStringEraName()
{
    switch (eraName)
    {
    case enumEraName::ERA_ANCIENT: return "Ancient";
    case enumEraName::ERA_CLASSIC: return "Classic";
    case enumEraName::ERA_MEDIVAL: return "Medival";
    case enumEraName::ERA_RENAISSANCEE: return "Renaissancee";
    case enumEraName::ERA_INDUSTRIAL: return "Industrial";
    case enumEraName::ERA_MODERN: return "Modern";
    case enumEraName::ERA_ATOMIC: return "Atomic";
    case enumEraName::ERA_INFORMATION: return "Information";
    case enumEraName::ERA_FUTURE: return "Future";
    default: return "";
    }
}

std::string Army::getStringArmyType()
{
    switch (armyType)
    {
    case enumTypeSquad::TYPE_MEELE: return "Meele\nTake half damage from Ranged squads.";
    case enumTypeSquad::TYPE_RANGE: return "Range\nIgnore enemy damage when the attack.\nCan't damage enemy when was attacked.";
    case enumTypeSquad::TYPE_CAVALRY: return "Cavalry\nCan attack twice each turn.";
    case enumTypeSquad::TYPE_ANTICAVALRY: return "Anti-Cavalry\nDeal double damage to Cavalry squads.\nIf a Cavalry squad attacks an Anti-Cavalry\nwith its first hit of a turn, it loses the ability\nto attack a second time that turn.";
    case enumTypeSquad::TYPE_ANTICAVALRYCAVALRY: return "Anti-Cavalry Cavalry\nCan attack twice each turn.\nDeal double damage to Cavalry squads.\nIf a Cavalry squad attacks an Anti-Cavalry\nwith its first hit of a turn, it loses the ability\nto attack a second time that turn.";
    case enumTypeSquad::TYPE_NONE: return "Doesn't have uniqe ability.";
    default: return "";
    }
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