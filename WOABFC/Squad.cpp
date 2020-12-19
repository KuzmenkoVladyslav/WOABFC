#include "Squad.h"

Squad::Squad(enumSquad armyID)
{
    this->armyID = armyID;
    
    switch (this->armyID)
    {
        case enumSquad::SQUAD_WARRIOR:
            this->armyTexture.loadFromFile("images/squads/warrior.png");
            this->armyAttackBasic = 1;
            this->armyHealthBasic = 3;
            this->armyName = "Warrior";
            this->eraName = enumEraName::ERA_ANCIENT;
            this->armyUpgrade = enumSquad::SQUAD_SWORDSMAN;
            this->armyType = enumTypeSquad::TYPE_MEELE;
            break;

        case enumSquad::SQUAD_SWORDSMAN:
            this->armyTexture.loadFromFile("images/squads/swordsman.png");
            this->armyAttackBasic = 2;
            this->armyHealthBasic = 4;
            this->armyName = "Swordsman";
            this->eraName = enumEraName::ERA_CLASSIC;
            this->armyUpgrade = enumSquad::SQUAD_LONGSWORDSMAN;
            this->armyType = enumTypeSquad::TYPE_MEELE;
            break;

        case enumSquad::SQUAD_LONGSWORDSMAN:
            this->armyTexture.loadFromFile("images/squads/longswordsman.png");
            this->armyAttackBasic = 2;
            this->armyHealthBasic = 6;
            this->armyName = "Longswordsman";
            this->eraName = enumEraName::ERA_MEDIVAL;
            this->armyUpgrade = enumSquad::SQUAD_HARQUEBUSIER;
            this->armyType = enumTypeSquad::TYPE_MEELE;
            break;

        case enumSquad::SQUAD_HARQUEBUSIER:
            this->armyTexture.loadFromFile("images/squads/harquebusier.png");
            this->armyAttackBasic = 3;
            this->armyHealthBasic = 8;
            this->armyName = "Harquebusier";
            this->eraName = enumEraName::ERA_RENAISSANCEE;
            this->armyUpgrade = enumSquad::SQUAD_MUSKETEER;
            this->armyType = enumTypeSquad::TYPE_MEELE;
            break;

        case enumSquad::SQUAD_MUSKETEER:
            this->armyTexture.loadFromFile("images/squads/musketeer.png");
            this->armyAttackBasic = 3;
            this->armyHealthBasic = 10;
            this->armyName = "Musketman";
            this->eraName = enumEraName::ERA_INDUSTRIAL;
            this->armyUpgrade = enumSquad::SQUAD_INFANTRYMAN;
            this->armyType = enumTypeSquad::TYPE_MEELE;
            break;

        case enumSquad::SQUAD_INFANTRYMAN:
            this->armyTexture.loadFromFile("images/squads/infantryman.png");
            this->armyAttackBasic = 4;
            this->armyHealthBasic = 12;
            this->armyName = "Infantry";
            this->eraName = enumEraName::ERA_MODERN;
            this->armyUpgrade = enumSquad::SQUAD_SEAINFANTRYMAN;
            this->armyType = enumTypeSquad::TYPE_MEELE;
            break;

        case enumSquad::SQUAD_SEAINFANTRYMAN:
            this->armyTexture.loadFromFile("images/squads/seainfantryman.png");
            this->armyAttackBasic = 5;
            this->armyHealthBasic = 14;
            this->armyName = "Marine";
            this->eraName = enumEraName::ERA_ATOMIC;
            this->armyUpgrade = enumSquad::SQUAD_MOTORIZEDINFANTRY;
            this->armyType = enumTypeSquad::TYPE_MEELE;
            break;

        case enumSquad::SQUAD_MOTORIZEDINFANTRY:
            this->armyTexture.loadFromFile("images/squads/motorizedinfantry.png");
            this->armyAttackBasic = 7;
            this->armyHealthBasic = 17;
            this->armyName = "Mechanized Infantry";
            this->eraName = enumEraName::ERA_INFORMATION;
            this->armyUpgrade = enumSquad::SQUAD_FUTURESMAN;
            this->armyType = enumTypeSquad::TYPE_MEELE;
            break;

        case enumSquad::SQUAD_FUTURESMAN:
            this->armyTexture.loadFromFile("images/squads/futuresman.png");
            this->armyAttackBasic = 12;
            this->armyHealthBasic = 26;
            this->armyName = "Exoskeleton";
            this->eraName = enumEraName::ERA_FUTURE;
            this->armyUpgrade = enumSquad::NONE;
            this->armyType = enumTypeSquad::TYPE_MEELE;
            this->armyCost = 2;
            break;

        case enumSquad::SQUAD_ARCHER:
            this->armyTexture.loadFromFile("images/squads/archer.png");
            this->armyAttackBasic = 2;
            this->armyHealthBasic = 1;
            this->armyName = "Archer";
            this->eraName = enumEraName::ERA_ANCIENT;
            this->armyUpgrade = enumSquad::SQUAD_LONGBOWARCHER;
            this->armyType = enumTypeSquad::TYPE_RANGE;
            break;

        case enumSquad::SQUAD_LONGBOWARCHER:
            this->armyTexture.loadFromFile("images/squads/longbowarcher.png");
            this->armyAttackBasic = 3;
            this->armyHealthBasic = 2;
            this->armyName = "Composite Bowman";
            this->eraName = enumEraName::ERA_CLASSIC;
            this->armyUpgrade = enumSquad::SQUAD_CROSSBOWMAN;
            this->armyType = enumTypeSquad::TYPE_RANGE;
            break;

        case enumSquad::SQUAD_CROSSBOWMAN:
            this->armyTexture.loadFromFile("images/squads/crossbowman.png");
            this->armyAttackBasic = 3;
            this->armyHealthBasic = 4;
            this->armyName = "Crossbowman";
            this->eraName = enumEraName::ERA_MEDIVAL;
            this->armyUpgrade = enumSquad::SQUAD_CANNON;
            this->armyType = enumTypeSquad::TYPE_RANGE;
            break;

        case enumSquad::SQUAD_CANNON:
            this->armyTexture.loadFromFile("images/squads/cannon.png");
            this->armyAttackBasic = 5;
            this->armyHealthBasic = 4;
            this->armyName = "Cannon"; 
            this->eraName = enumEraName::ERA_RENAISSANCEE;
            this->armyUpgrade = enumSquad::SQUAD_GATLING;
            this->armyType = enumTypeSquad::TYPE_RANGE;
            break;

        case enumSquad::SQUAD_GATLING:
            this->armyTexture.loadFromFile("images/squads/gatling.png");
            this->armyAttackBasic = 6;
            this->armyHealthBasic = 5;
            this->armyName = "Gatling Gun";
            this->eraName = enumEraName::ERA_INDUSTRIAL;
            this->armyUpgrade = enumSquad::SQUAD_MACHINGGUN;
            this->armyType = enumTypeSquad::TYPE_RANGE;
            break;

        case enumSquad::SQUAD_MACHINGGUN:
            this->armyTexture.loadFromFile("images/squads/machinggun.png");
            this->armyAttackBasic = 8;
            this->armyHealthBasic = 5;
            this->armyName = "Machine Gun";
            this->eraName = enumEraName::ERA_MODERN;
            this->armyUpgrade = enumSquad::SQUAD_BAZOOKA;
            this->armyType = enumTypeSquad::TYPE_RANGE;
            break;

        case enumSquad::SQUAD_BAZOOKA:
            this->armyTexture.loadFromFile("images/squads/bazooka.png");
            this->armyAttackBasic = 9;
            this->armyHealthBasic = 6;
            this->armyName = "Bazooka";
            this->eraName = enumEraName::ERA_ATOMIC;
            this->armyUpgrade = enumSquad::SQUAD_ROCKET;
            this->armyType = enumTypeSquad::TYPE_RANGE;
            break;

        case enumSquad::SQUAD_ROCKET:
            this->armyTexture.loadFromFile("images/squads/rocket.png");
            this->armyAttackBasic = 12;
            this->armyHealthBasic = 8;
            this->armyName = "Guided Missile";
            this->eraName = enumEraName::ERA_INFORMATION;
            this->armyUpgrade = enumSquad::NONE;
            this->armyType = enumTypeSquad::TYPE_RANGE;
            break;

        case enumSquad::SQUAD_HOURSEARCHER:
            this->armyTexture.loadFromFile("images/squads/hoursearcher.png");
            this->armyAttackBasic = 1;
            this->armyHealthBasic = 3;
            this->armyName = "War Chariot";
            this->eraName = enumEraName::ERA_ANCIENT;
            this->armyUpgrade = enumSquad::SQUAD_HORSEMAN;
            this->armyType = enumTypeSquad::TYPE_CAVALRY;
            break;

        case enumSquad::SQUAD_HORSEMAN:
            this->armyTexture.loadFromFile("images/squads/horseman.png");
            this->armyAttackBasic = 2;
            this->armyHealthBasic = 5;
            this->armyName = "Horseman";
            this->eraName = enumEraName::ERA_CLASSIC;
            this->armyUpgrade = enumSquad::SQUAD_KNIGHT;
            this->armyType = enumTypeSquad::TYPE_CAVALRY;
            break;

        case enumSquad::SQUAD_KNIGHT:
            this->armyTexture.loadFromFile("images/squads/knight.png");
            this->armyAttackBasic = 2;
            this->armyHealthBasic = 7;
            this->armyName = "Knight";
            this->eraName = enumEraName::ERA_MEDIVAL;
            this->armyUpgrade = enumSquad::SQUAD_LANCER;
            this->armyType = enumTypeSquad::TYPE_CAVALRY;
            break;

        case enumSquad::SQUAD_LANCER:
            this->armyTexture.loadFromFile("images/squads/lancer.png");
            this->armyAttackBasic = 3;
            this->armyHealthBasic = 10;
            this->armyName = "Lancer"; 
            this->eraName = enumEraName::ERA_RENAISSANCEE;
            this->armyUpgrade = enumSquad::NONE;
            this->armyType = enumTypeSquad::TYPE_ANTICAVALRYCAVALRY;
            break;

        case enumSquad::SQUAD_CAVALRY:
            this->armyTexture.loadFromFile("images/squads/cavalry.png");
            this->armyAttackBasic = 4;
            this->armyHealthBasic = 10;
            this->armyName = "Cavalry";
            this->eraName = enumEraName::ERA_INDUSTRIAL;
            this->armyUpgrade = enumSquad::SQUAD_TANKETTE;
            this->armyType = enumTypeSquad::TYPE_CAVALRY;
            break;

        case enumSquad::SQUAD_TANKETTE:
            this->armyTexture.loadFromFile("images/squads/tankette.png");
            this->armyAttackBasic = 4;
            this->armyHealthBasic = 15;
            this->armyName = "Tankette";
            this->eraName = enumEraName::ERA_MODERN;
            this->armyUpgrade = enumSquad::SQUAD_TANK;
            this->armyType = enumTypeSquad::TYPE_CAVALRY;
            break;

        case enumSquad::SQUAD_TANK:
            this->armyTexture.loadFromFile("images/squads/tank.png");
            this->armyAttackBasic = 5;
            this->armyHealthBasic = 17;
            this->armyName = "Tank";
            this->eraName = enumEraName::ERA_ATOMIC;
            this->armyUpgrade = enumSquad::SQUAD_MODERNTANK;
            this->armyType = enumTypeSquad::TYPE_CAVALRY;
            break;

        case enumSquad::SQUAD_MODERNTANK:
            this->armyTexture.loadFromFile("images/squads/moderntank.png");
            this->armyAttackBasic = 6;
            this->armyHealthBasic = 27;
            this->armyName = "Modern Tank";
            this->eraName = enumEraName::ERA_INFORMATION;
            this->armyUpgrade = enumSquad::NONE;
            this->armyType = enumTypeSquad::TYPE_CAVALRY;
            break;

        case enumSquad::SQUAD_SPEARMAN:
            this->armyTexture.loadFromFile("images/squads/spearman.png");
            this->armyAttackBasic = 1;
            this->armyHealthBasic = 2;
            this->armyName = "Spearman";
            this->eraName = enumEraName::ERA_ANCIENT;            
            this->armyUpgrade = enumSquad::SQUAD_HOPLITE;
            this->armyType = enumTypeSquad::TYPE_ANTICAVALRY;
            break;

        case enumSquad::SQUAD_HOPLITE:
            this->armyTexture.loadFromFile("images/squads/hoplite.png");
            this->armyAttackBasic = 2;
            this->armyHealthBasic = 3;
            this->armyName = "Hoplite";
            this->eraName = enumEraName::ERA_CLASSIC;
            this->armyUpgrade = enumSquad::SQUAD_PIKEMAN;
            this->armyType = enumTypeSquad::TYPE_ANTICAVALRY;
            break;

        case enumSquad::SQUAD_PIKEMAN:
            this->armyTexture.loadFromFile("images/squads/pikeman.png");
            this->armyAttackBasic = 2;
            this->armyHealthBasic = 6;
            this->armyName = "Pikeman";
            this->eraName = enumEraName::ERA_MEDIVAL;
            this->armyUpgrade = enumSquad::SQUAD_LANCER;
            this->armyType = enumTypeSquad::TYPE_ANTICAVALRY;
            break;

        case enumSquad::SQUAD_ARTBATTERY:
            this->armyTexture.loadFromFile("images/squads/artbattery.png");
            this->armyAttackBasic = 5;
            this->armyHealthBasic = 11;
            this->armyName = "Artillery";
            this->eraName = enumEraName::ERA_MODERN;
            this->armyUpgrade = enumSquad::SQUAD_ANTITANKCANNON;
            this->armyType = enumTypeSquad::TYPE_ANTICAVALRY;
            break;

        case enumSquad::SQUAD_ANTITANKCANNON:
            this->armyTexture.loadFromFile("images/squads/antitankcannon.png");
            this->armyAttackBasic = 8;
            this->armyHealthBasic = 11;
            this->armyName = "Anti-Tank Gun";
            this->eraName = enumEraName::ERA_ATOMIC;
            this->armyUpgrade = enumSquad::SQUAD_ROCKETARTILLERY;
            this->armyType = enumTypeSquad::TYPE_ANTICAVALRY;
            break;

        case enumSquad::SQUAD_ROCKETARTILLERY:
            this->armyTexture.loadFromFile("images/squads/rocketartillery.png");
            this->armyAttackBasic = 9;
            this->armyHealthBasic = 18;
            this->armyName = "Rocket Artillery";
            this->eraName = enumEraName::ERA_INFORMATION;
            this->armyUpgrade = enumSquad::NONE;
            this->armyType = enumTypeSquad::TYPE_ANTICAVALRY;
            break;

        case enumSquad::SQUAD_ROBOT:
            this->armyTexture.loadFromFile("images/squads/robot.png");
            this->armyAttackBasic = 10;
            this->armyHealthBasic = 34;
            this->armyName = "Giant Robot";
            this->eraName = enumEraName::ERA_FUTURE;
            this->armyUpgrade = enumSquad::NONE;
            this->armyType = enumTypeSquad::TYPE_NONE;
            this->armyCost = 4;
            break;
    default:
        break;
    }

    this->armySprite.setTexture(armyTexture);
    this->armyAttackNow = this->armyAttackBasic;
    this->armyHealthNow = this->armyHealthBasic;
}