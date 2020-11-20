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

    virtual std::string getArmyName() 
    {
        return this->armyName;
    }

    

    virtual std::string getStringEraName()
    {
        switch(eraName)
        {
        case enumEraName::ERA_ANCIENT : return "Ancient";
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

    virtual std::string getStringArmyType()
    {
        switch (armyType)
        {
        case enumTypeSquad::TYPE_MEELE: return "Meele\nTake half damage from Ranged squads.";
        case enumTypeSquad::TYPE_RANGE: return "Range\nIgnore enemy damage when the attack.\nCan't damage enemy when was attacked.";
        case enumTypeSquad::TYPE_CAVALRY: return "Cavalry\nCan attack twice each turn.";
        case enumTypeSquad::TYPE_ANTICAVALRY: return "Anti-Cavalry\nDeal double damage to Cavalry squads.\nIf a Cavalry squad attacks an Anti-Cavalry with its first hit of a turn,\nit loses the ability to attack a second time that turn.";
        case enumTypeSquad::TYPE_ANTICAVALRYCAVALRY: return "Anti-Cavalry Cavalry\nCan attack twice each turn.\nDeal double damage to Cavalry squads.\nIf a Cavalry squad attacks an Anti-Cavalry with its first hit of a turn,\nit loses the ability to attack a second time that turn.";
        case enumTypeSquad::TYPE_NONE: return "Doesn't have uniqe ability.";
        default: return "";
        }
    }

    virtual enumTypeSquad getArmyType() 
    {
        return armyType;
    }

    virtual enumEraName getEraName()
    {
        return  eraName;
    }

    virtual enumSquad getArmyUpgrade()
    {
        return  armyUpgrade;
    }

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