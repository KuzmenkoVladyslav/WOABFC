#pragma once
#include <SFML/Graphics.hpp>
#include "enumSquad.h"
#include "enumTypeSquad.h"
#include "enumEraName.h"

class Army
{
public:
    Army() {};
    ~Army() {};

    virtual sf::Sprite getArmySprite();

    virtual float getArmySpawnCoordinateX();

    virtual float getArmySpawnCoordinateY();

    virtual float getArmySpriteCoordinateX();

    virtual float getArmySpriteCoordinateY();
    
    virtual int getArmyAttackNow();

    virtual int getArmyHealthNow();

    virtual void setArmySpawnCoordinates(float armySpawnCoordinateX, float armySpawnCoordinateY);

    virtual std::string getArmyName();

    virtual std::string getStringEraName();

    virtual std::string getStringArmyType();

    virtual enumTypeSquad getArmyType();

    virtual enumEraName getEraName();

    virtual enumSquad getArmyUpgrade();

protected:
    sf::Texture armyTexture;
    sf::Sprite armySprite;
    std::string armyFile;
    std::string armyName;

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

    enumEraName eraName = enumEraName::ERA_ANCIENT;
    enumTypeSquad armyType = enumTypeSquad::TYPE_NONE;
    enumSquad armyUpgrade = enumSquad::NONE;
};