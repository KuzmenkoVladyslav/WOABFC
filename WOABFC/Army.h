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
    
    virtual int getArmyAttackNow()
    {
        return this->armyAttackNow;
    }

    virtual int getArmyHealthNow()
    {
        return this->armyHealthNow;
    }

    virtual void setArmySpawnCoordinateX(float armySpawnCoordinateX)
    {
        this->armySpawnCoordinateX = armySpawnCoordinateX;
        setArmySpawnCoordinates();
    }

    virtual void setArmySpawnCoordinateY(float armySpawnCoordinateY)
    {
        this->armySpawnCoordinateY = armySpawnCoordinateY;
        setArmySpawnCoordinates();
    }

    virtual void setArmySpawnCoordinates()
    {
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
    int armyHealthBasic = 0;
    int armyAttackBasic = 0;
    int armyHealthNow = 0;
    int armyAttackNow = 0;

    enumTypeSquad armyType = enumTypeSquad::TYPE_NONE;
    enumSquad armyUpgrade = enumSquad::NONE;
};