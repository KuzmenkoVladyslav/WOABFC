#pragma once
#include <SFML/Graphics.hpp>
#include "enumSquad.h"
#include "enumTypeSquad.h"

class Army
{
public:
    Army() {};
    ~Army() {};

    virtual sf::Sprite getArmySprite() 
    {
        return this->armySprite;
    }

    virtual float getArmySpawnCoordinateX() 
    {
        return this->armySpawnCoordinateX;
    }

    virtual float getArmySpawnCoordinateY()
    {
        return this->armySpawnCoordinateY;
    }

    virtual void setArmySpawnCoordinates(float armySpawnCoordinateX, float armySpawnCoordinateY)
    {
        this->armySpawnCoordinateX = armySpawnCoordinateX;
        this->armySpawnCoordinateY = armySpawnCoordinateY;
        this->armySprite.setPosition(this->armySpawnCoordinateX, this->armySpawnCoordinateY);
    }

protected:
    sf::Texture armyTexture;
    sf::Sprite armySprite;
    std::string armyFile;

    float armySize = 200;
    float armySpawnCoordinateX = 0;
    float armySpawnCoordinateY = 0;
    short armyHealth = 0;
    short armyAttack = 0;
    enumTypeSquad armyType = enumTypeSquad::TYPE_NONE;
    enumSquad armyUpgrade = enumSquad::NONE;
    
};

