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

void Army::setArmyHealthNow(int newArmyHealth)
{
    this->armyHealthNow = newArmyHealth;
}

int Army::getArmyHealthBasic() 
{
    return this->armyHealthBasic;
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

enumSquad Army::getArmyID()
{
    return this->armyID;
}

int Army::getArmyCost() 
{
    return this->armyCost;
}