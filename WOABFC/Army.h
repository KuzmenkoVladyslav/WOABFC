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

    virtual float getArmySpriteCoordinateX()
    {
        return this->armySpriteCoordinateX;
    }

    virtual float getArmySpriteCoordinateY()
    {
        return this->armySpriteCoordinateY;
    }
    
    virtual float getArmyAttackNow()
    {
        return this->armyAttackNow;
    }

    virtual float getArmyHealthNow()
    {
        return this->armyHealthNow;
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
    float armySpriteCoordinateX = 0;
    float armySpriteCoordinateY = 0;
    float armySpawnCoordinateX = 0;
    float armySpawnCoordinateY = 0;
    float armyCost = 1;
    short armyHealthBasic = 0;
    short armyAttackBasic = 0;
    short armyHealthNow = 0;
    short armyAttackNow = 0;
    enumTypeSquad armyType = enumTypeSquad::TYPE_NONE;
    enumSquad armyUpgrade = enumSquad::NONE;
    
};

