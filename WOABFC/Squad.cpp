#include "Squad.h"

Squad::Squad(enumSquad armyID)
{
    this->armyTexture.loadFromFile("images/army.png");
    this->armySprite.setTexture(armyTexture);
    switch (armyID)
    {
        case enumSquad::SQUAD_WARRIOR:
            this->armySpriteCoordinateX = 0;
            this->armySpriteCoordinateY = 0;
            this->armyAttackBasic = 1;
            this->armyHealthBasic = 3;
            this->armyName = "Warrior";
            this->eraName = enumEraName::ERA_ANCIENT;
            this->armyUpgrade = enumSquad::SQUAD_SWORDSMAN;
            this->armyType = enumTypeSquad::TYPE_MEELE;
            break;

        case enumSquad::SQUAD_SWORDSMAN:
            this->armySpriteCoordinateX = 200;
            this->armySpriteCoordinateY = 0;
            this->armyAttackBasic = 2;
            this->armyHealthBasic = 4;
            this->armyName = "Swordsman";
            this->eraName = enumEraName::ERA_CLASSIC;
            this->armyUpgrade = enumSquad::SQUAD_LONGSWORDSMAN;
            this->armyType = enumTypeSquad::TYPE_MEELE;
            break;

        case enumSquad::SQUAD_LONGSWORDSMAN:
            this->armySpriteCoordinateX = 400;
            this->armySpriteCoordinateY = 0;
            this->armyAttackBasic = 2;
            this->armyHealthBasic = 7;
            this->armyName = "Longswordsman";
            this->eraName = enumEraName::ERA_MEDIVAL;
            this->armyUpgrade = enumSquad::SQUAD_HARQUEBUSIER;
            this->armyType = enumTypeSquad::TYPE_MEELE;
            break;

        case enumSquad::SQUAD_HARQUEBUSIER:
            this->armySpriteCoordinateX = 600;
            this->armySpriteCoordinateY = 0;
            this->armyAttackBasic = 3;
            this->armyHealthBasic = 8;
            this->armyName = "Harquebusier";
            this->eraName = enumEraName::ERA_RENAISSANCEE;
            this->armyUpgrade = enumSquad::SQUAD_MUSKETEER;
            this->armyType = enumTypeSquad::TYPE_MEELE;
            break;

        case enumSquad::SQUAD_MUSKETEER:
            this->armySpriteCoordinateX = 800;
            this->armySpriteCoordinateY = 0;
            this->armyAttackBasic = 3;
            this->armyHealthBasic = 11;
            this->armyName = "Musketman";
            this->eraName = enumEraName::ERA_INDUSTRIAL;
            this->armyUpgrade = enumSquad::SQUAD_INFANTRYMAN;
            this->armyType = enumTypeSquad::TYPE_MEELE;
            break;

        case enumSquad::SQUAD_INFANTRYMAN:
            this->armySpriteCoordinateX = 1000;
            this->armySpriteCoordinateY = 0;
            this->armyAttackBasic = 4;
            this->armyHealthBasic = 12;
            this->armyName = "Infantry";
            this->eraName = enumEraName::ERA_MODERN;
            this->armyUpgrade = enumSquad::SQUAD_SEAINFANTRYMAN;
            this->armyType = enumTypeSquad::TYPE_MEELE;
            break;

        case enumSquad::SQUAD_SEAINFANTRYMAN:
            this->armySpriteCoordinateX = 1200;
            this->armySpriteCoordinateY = 0;
            this->armyAttackBasic = 5;
            this->armyHealthBasic = 14;
            this->armyName = "Marine";
            this->eraName = enumEraName::ERA_ATOMIC;
            this->armyUpgrade = enumSquad::SQUAD_MOTORIZEDINFANTRY;
            this->armyType = enumTypeSquad::TYPE_MEELE;
            break;

        case enumSquad::SQUAD_MOTORIZEDINFANTRY:
            this->armySpriteCoordinateX = 1400;
            this->armySpriteCoordinateY = 0;
            this->armyAttackBasic = 7;
            this->armyHealthBasic = 17;
            this->armyName = "Mechanized Infantry";
            this->eraName = enumEraName::ERA_INFORMATION;
            this->armyUpgrade = enumSquad::SQUAD_FUTURESMAN;
            this->armyType = enumTypeSquad::TYPE_MEELE;
            break;

        case enumSquad::SQUAD_FUTURESMAN:
            this->armySpriteCoordinateX = 1600;
            this->armySpriteCoordinateY = 0;
            this->armyAttackBasic = 12;
            this->armyHealthBasic = 26;
            this->armyName = "Exoskeleton";
            this->eraName = enumEraName::ERA_FUTURE;
            this->armyUpgrade = enumSquad::NONE;
            this->armyType = enumTypeSquad::TYPE_MEELE;
            this->armyCost = 2;
            break;

        case enumSquad::SQUAD_ARCHER:
            this->armySpriteCoordinateX = 0;
            this->armySpriteCoordinateY = 200;
            this->armyAttackBasic = 1;
            this->armyHealthBasic = 1;
            this->armyName = "Archer";
            this->eraName = enumEraName::ERA_ANCIENT;
            this->armyUpgrade = enumSquad::SQUAD_LONGBOWARCHER;
            this->armyType = enumTypeSquad::TYPE_RANGE;
            break;

        case enumSquad::SQUAD_LONGBOWARCHER:
            this->armySpriteCoordinateX = 200;
            this->armySpriteCoordinateY = 200;
            this->armyAttackBasic = 2;
            this->armyHealthBasic = 1;
            this->armyName = "Composite Bowman";
            this->eraName = enumEraName::ERA_CLASSIC;
            this->armyUpgrade = enumSquad::SQUAD_CROSSBOWMAN;
            this->armyType = enumTypeSquad::TYPE_RANGE;
            break;

        case enumSquad::SQUAD_CROSSBOWMAN:
            this->armySpriteCoordinateX = 400;
            this->armySpriteCoordinateY = 200;
            this->armyAttackBasic = 2;
            this->armyHealthBasic = 3;
            this->armyName = "Crossbowman";
            this->eraName = enumEraName::ERA_MEDIVAL;
            this->armyUpgrade = enumSquad::SQUAD_CANNON;
            this->armyType = enumTypeSquad::TYPE_RANGE;
            break;

        case enumSquad::SQUAD_CANNON:
            this->armySpriteCoordinateX = 600;
            this->armySpriteCoordinateY = 200;
            this->armyAttackBasic = 3;
            this->armyHealthBasic = 4;
            this->armyName = "Cannon"; 
            this->eraName = enumEraName::ERA_RENAISSANCEE;
            this->armyUpgrade = enumSquad::SQUAD_GATLING;
            this->armyType = enumTypeSquad::TYPE_RANGE;
            break;

        case enumSquad::SQUAD_GATLING:
            this->armySpriteCoordinateX = 800;
            this->armySpriteCoordinateY = 200;
            this->armyAttackBasic = 4;
            this->armyHealthBasic = 4;
            this->armyName = "Gatling Gun";
            this->eraName = enumEraName::ERA_INDUSTRIAL;
            this->armyUpgrade = enumSquad::SQUAD_MACHINGGUN;
            this->armyType = enumTypeSquad::TYPE_RANGE;
            break;

        case enumSquad::SQUAD_MACHINGGUN:
            this->armySpriteCoordinateX = 1000;
            this->armySpriteCoordinateY = 200;
            this->armyAttackBasic = 6;
            this->armyHealthBasic = 5;
            this->armyName = "Machine Gun";
            this->eraName = enumEraName::ERA_MODERN;
            this->armyUpgrade = enumSquad::SQUAD_BAZOOKA;
            this->armyType = enumTypeSquad::TYPE_RANGE;
            break;

        case enumSquad::SQUAD_BAZOOKA:
            this->armySpriteCoordinateX = 1200;
            this->armySpriteCoordinateY = 200;
            this->armyAttackBasic = 8;
            this->armyHealthBasic = 6;
            this->armyName = "Bazooka";
            this->eraName = enumEraName::ERA_INFORMATION;
            this->armyUpgrade = enumSquad::SQUAD_ROCKET;
            this->armyType = enumTypeSquad::TYPE_RANGE;
            break;

        case enumSquad::SQUAD_ROCKET:
            this->armySpriteCoordinateX = 1400;
            this->armySpriteCoordinateY = 200;
            this->armyAttackBasic = 11;
            this->armyHealthBasic = 8;
            this->armyName = "Guided Missile";
            this->eraName = enumEraName::ERA_ATOMIC;
            this->armyUpgrade = enumSquad::NONE;
            this->armyType = enumTypeSquad::TYPE_RANGE;
            break;

        case enumSquad::SQUAD_HOURSEARCHER:
            this->armySpriteCoordinateX = 0;
            this->armySpriteCoordinateY = 400;
            this->armyAttackBasic = 1;
            this->armyHealthBasic = 3;
            this->armyName = "War Chariot";
            this->eraName = enumEraName::ERA_ANCIENT;
            this->armyUpgrade = enumSquad::NONE;
            this->armyType = enumTypeSquad::TYPE_CAVALRY;
            break;

        case enumSquad::SQUAD_HORSEMAN:
            this->armySpriteCoordinateX = 200;
            this->armySpriteCoordinateY = 400;
            this->armyAttackBasic = 1;
            this->armyHealthBasic = 5;
            this->armyName = "Horseman";
            this->eraName = enumEraName::ERA_CLASSIC;
            this->armyUpgrade = enumSquad::NONE;
            this->armyType = enumTypeSquad::TYPE_CAVALRY;
            break;

        case enumSquad::SQUAD_KNIGHT:
            this->armySpriteCoordinateX = 400;
            this->armySpriteCoordinateY = 400;
            this->armyAttackBasic = 2;
            this->armyHealthBasic = 6;
            this->armyName = "Knight";
            this->eraName = enumEraName::ERA_MEDIVAL;
            this->armyUpgrade = enumSquad::SQUAD_LANCER;
            this->armyType = enumTypeSquad::TYPE_CAVALRY;
            break;

        case enumSquad::SQUAD_LANCER:
            this->armySpriteCoordinateX = 600;
            this->armySpriteCoordinateY = 400;
            this->armyAttackBasic = 3;
            this->armyHealthBasic = 9;
            this->armyName = "Lancer"; 
            this->eraName = enumEraName::ERA_RENAISSANCEE;
            this->armyUpgrade = enumSquad::NONE;
            this->armyType = enumTypeSquad::TYPE_ANTICAVALRYCAVALRY;
            break;

        case enumSquad::SQUAD_CAVALRY:
            this->armySpriteCoordinateX = 800;
            this->armySpriteCoordinateY = 400;
            this->armyAttackBasic = 4;
            this->armyHealthBasic = 9;
            this->armyName = "Cavalry";
            this->eraName = enumEraName::ERA_INDUSTRIAL;
            this->armyUpgrade = enumSquad::SQUAD_TANKETTE;
            this->armyType = enumTypeSquad::TYPE_CAVALRY;
            break;

        case enumSquad::SQUAD_TANKETTE:
            this->armySpriteCoordinateX = 1000;
            this->armySpriteCoordinateY = 400;
            this->armyAttackBasic = 4;
            this->armyHealthBasic = 14;
            this->armyName = "Tankette";
            this->eraName = enumEraName::ERA_MODERN;
            this->armyUpgrade = enumSquad::SQUAD_TANK;
            this->armyType = enumTypeSquad::TYPE_CAVALRY;
            break;

        case enumSquad::SQUAD_TANK:
            this->armySpriteCoordinateX = 1200;
            this->armySpriteCoordinateY = 400;
            this->armyAttackBasic = 4;
            this->armyHealthBasic = 17;
            this->armyName = "Tank";
            this->eraName = enumEraName::ERA_ATOMIC;
            this->armyUpgrade = enumSquad::SQUAD_MODERNTANK;
            this->armyType = enumTypeSquad::TYPE_CAVALRY;
            break;

        case enumSquad::SQUAD_MODERNTANK:
            this->armySpriteCoordinateX = 1400;
            this->armySpriteCoordinateY = 400;
            this->armyAttackBasic = 6;
            this->armyHealthBasic = 23;
            this->armyName = "Modern Tank";
            this->eraName = enumEraName::ERA_INFORMATION;
            this->armyUpgrade = enumSquad::NONE;
            this->armyType = enumTypeSquad::TYPE_CAVALRY;
            break;

        case enumSquad::SQUAD_SPEARMAN:
            this->armySpriteCoordinateX = 0;
            this->armySpriteCoordinateY = 600;
            this->armyAttackBasic = 1;
            this->armyHealthBasic = 2;
            this->armyName = "Spearman";
            this->eraName = enumEraName::ERA_ANCIENT;            
            this->armyUpgrade = enumSquad::SQUAD_HOPLITE;
            this->armyType = enumTypeSquad::TYPE_ANTICAVALRY;
            break;

        case enumSquad::SQUAD_HOPLITE:
            this->armySpriteCoordinateX = 200;
            this->armySpriteCoordinateY = 600;
            this->armyAttackBasic = 2;
            this->armyHealthBasic = 3;
            this->armyName = "Hoplite";
            this->eraName = enumEraName::ERA_CLASSIC;
            this->armyUpgrade = enumSquad::SQUAD_PIKEMAN;
            this->armyType = enumTypeSquad::TYPE_ANTICAVALRY;
            break;

        case enumSquad::SQUAD_PIKEMAN:
            this->armySpriteCoordinateX = 400;
            this->armySpriteCoordinateY = 600;
            this->armyAttackBasic = 2;
            this->armyHealthBasic = 5;
            this->armyName = "Pikeman";
            this->eraName = enumEraName::ERA_MEDIVAL;
            this->armyUpgrade = enumSquad::SQUAD_LANCER;
            this->armyType = enumTypeSquad::TYPE_ANTICAVALRY;
            break;

        case enumSquad::SQUAD_ARTBATTERY:
            this->armySpriteCoordinateX = 1000;
            this->armySpriteCoordinateY = 600;
            this->armyAttackBasic = 6;
            this->armyHealthBasic = 10;
            this->armyName = "Artillery";
            this->eraName = enumEraName::ERA_MODERN;
            this->armyUpgrade = enumSquad::SQUAD_ANTITANKCANNON;
            this->armyType = enumTypeSquad::TYPE_ANTICAVALRY;
            break;

        case enumSquad::SQUAD_ANTITANKCANNON:
            this->armySpriteCoordinateX = 1200;
            this->armySpriteCoordinateY = 600;
            this->armyAttackBasic = 8;
            this->armyHealthBasic = 11;
            this->armyName = "Anti-Tank Gun";
            this->eraName = enumEraName::ERA_ATOMIC;
            this->armyUpgrade = enumSquad::SQUAD_ROCKETARTILLERY;
            this->armyType = enumTypeSquad::TYPE_ANTICAVALRY;
            break;

        case enumSquad::SQUAD_ROCKETARTILLERY:
            this->armySpriteCoordinateX = 1400;
            this->armySpriteCoordinateY = 600;
            this->armyAttackBasic = 12;
            this->armyHealthBasic = 17;
            this->armyName = "Rocket Artillery";
            this->eraName = enumEraName::ERA_INFORMATION;
            this->armyUpgrade = enumSquad::NONE;
            this->armyType = enumTypeSquad::TYPE_ANTICAVALRY;
            break;

        case enumSquad::SQUAD_ROBOT:
            this->armySpriteCoordinateX = 1600;
            this->armySpriteCoordinateY = 200;
            this->armyAttackBasic = 9;
            this->armyHealthBasic = 32;
            this->armyName = "Giant Robot";
            this->eraName = enumEraName::ERA_FUTURE;
            this->armyUpgrade = enumSquad::NONE;
            this->armyType = enumTypeSquad::TYPE_NONE;
            this->armyCost = 4;
            break;
    default:
        break;
    }

    this->armySprite.setTextureRect(sf::IntRect(static_cast<int>(this->armySpriteCoordinateX), static_cast<int>(this->armySpriteCoordinateY), static_cast<int>(this->armySize), static_cast<int>(this->armySize)));
    this->armyAttackNow = this->armyAttackBasic;
    this->armyHealthNow = this->armyHealthBasic;
}