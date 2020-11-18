#include "Squad.h"

Squad::Squad(enumSquad armyID)
{
    this->armyFile = "army.png";
    this->armyTexture.loadFromFile("images/" + this->armyFile);
    this->armySprite.setTexture(armyTexture);
    switch (armyID)
    {
        case enumSquad::SQUAD_WARRIOR:
            this->armySprite.setTextureRect(sf::IntRect(0, 0, static_cast<int>(this->armySize), static_cast<int>(this->armySize)));
            this->armyAttack = 1;
            this->armyHealth = 3;
            this->armyUpgrade = enumSquad::SQUAD_SWORDSMAN;
            this->armyType = enumTypeSquad::TYPE_MEELE;
            break;

        case enumSquad::SQUAD_SWORDSMAN:
            this->armySprite.setTextureRect(sf::IntRect(200, 0, static_cast<int>(this->armySize), static_cast<int>(this->armySize)));
            this->armyAttack = 2;
            this->armyHealth = 4;
            this->armyUpgrade = enumSquad::SQUAD_LONGSWORDSMAN;
            this->armyType = enumTypeSquad::TYPE_MEELE;
            break;

        case enumSquad::SQUAD_LONGSWORDSMAN:
            this->armySprite.setTextureRect(sf::IntRect(400, 0, static_cast<int>(this->armySize), static_cast<int>(this->armySize)));
            this->armyAttack = 2;
            this->armyHealth = 7;
            this->armyUpgrade = enumSquad::SQUAD_HARQUEBUSIER;
            this->armyType = enumTypeSquad::TYPE_MEELE;
            break;

        case enumSquad::SQUAD_HARQUEBUSIER:
            this->armySprite.setTextureRect(sf::IntRect(600, 0, static_cast<int>(this->armySize), static_cast<int>(this->armySize)));
            this->armyAttack = 3;
            this->armyHealth = 8;
            this->armyUpgrade = enumSquad::SQUAD_MUSKETEER;
            this->armyType = enumTypeSquad::TYPE_MEELE;
            break;

        case enumSquad::SQUAD_MUSKETEER:
            this->armySprite.setTextureRect(sf::IntRect(800, 0, static_cast<int>(this->armySize), static_cast<int>(this->armySize)));
            this->armyAttack = 3;
            this->armyHealth = 11;
            this->armyUpgrade = enumSquad::SQUAD_INFANTRYMAN;
            this->armyType = enumTypeSquad::TYPE_MEELE;
            break;

        case enumSquad::SQUAD_INFANTRYMAN:
            this->armySprite.setTextureRect(sf::IntRect(1000, 0, static_cast<int>(this->armySize), static_cast<int>(this->armySize)));
            this->armyAttack = 4;
            this->armyHealth = 12;
            this->armyUpgrade = enumSquad::SQUAD_SEAINFANTRYMAN;
            this->armyType = enumTypeSquad::TYPE_MEELE;
            break;

        case enumSquad::SQUAD_SEAINFANTRYMAN:
            this->armySprite.setTextureRect(sf::IntRect(1200, 0, static_cast<int>(this->armySize), static_cast<int>(this->armySize)));
            this->armyAttack = 5;
            this->armyHealth = 14;
            this->armyUpgrade = enumSquad::SQUAD_MOTORIZEDINFANTRY;
            this->armyType = enumTypeSquad::TYPE_MEELE;
            break;

        case enumSquad::SQUAD_MOTORIZEDINFANTRY:
            this->armySprite.setTextureRect(sf::IntRect(1400, 0, static_cast<int>(this->armySize), static_cast<int>(this->armySize)));
            this->armyAttack = 7;
            this->armyHealth = 17;
            this->armyUpgrade = enumSquad::SQUAD_FUTURESMAN;
            this->armyType = enumTypeSquad::TYPE_MEELE;
            break;

        case enumSquad::SQUAD_FUTURESMAN:
            this->armySprite.setTextureRect(sf::IntRect(1600, 0, static_cast<int>(this->armySize), static_cast<int>(this->armySize)));
            this->armyAttack = 12;
            this->armyHealth = 26;
            this->armyUpgrade = enumSquad::NONE;
            this->armyType = enumTypeSquad::TYPE_MEELE;
            break;

        case enumSquad::SQUAD_ARCHER:
            this->armySprite.setTextureRect(sf::IntRect(0, 200, static_cast<int>(this->armySize), static_cast<int>(this->armySize)));
            this->armyAttack = 1;
            this->armyHealth = 1;
            this->armyUpgrade = enumSquad::SQUAD_LONGBOWARCHER;
            this->armyType = enumTypeSquad::TYPE_RANGE;
            break;

        case enumSquad::SQUAD_LONGBOWARCHER:
            this->armySprite.setTextureRect(sf::IntRect(200, 200, static_cast<int>(this->armySize), static_cast<int>(this->armySize)));
            this->armyAttack = 2;
            this->armyHealth = 1;
            this->armyUpgrade = enumSquad::SQUAD_CROSSBOWMAN;
            this->armyType = enumTypeSquad::TYPE_RANGE;
            break;

        case enumSquad::SQUAD_CROSSBOWMAN:
            this->armySprite.setTextureRect(sf::IntRect(400, 200, static_cast<int>(this->armySize), static_cast<int>(this->armySize)));
            this->armyAttack = 2;
            this->armyHealth = 3;
            this->armyUpgrade = enumSquad::SQUAD_CANNON;
            this->armyType = enumTypeSquad::TYPE_RANGE;
            break;

        case enumSquad::SQUAD_CANNON:
            this->armySprite.setTextureRect(sf::IntRect(600, 200, static_cast<int>(this->armySize), static_cast<int>(this->armySize)));
            this->armyAttack = 3;
            this->armyHealth = 4;
            this->armyUpgrade = enumSquad::SQUAD_GATLING;
            this->armyType = enumTypeSquad::TYPE_RANGE;
            break;

        case enumSquad::SQUAD_GATLING:
            this->armySprite.setTextureRect(sf::IntRect(800, 200, static_cast<int>(this->armySize), static_cast<int>(this->armySize)));
            this->armyAttack = 4;
            this->armyHealth = 4;
            this->armyUpgrade = enumSquad::SQUAD_MACHINGGUN;
            this->armyType = enumTypeSquad::TYPE_RANGE;
            break;

        case enumSquad::SQUAD_MACHINGGUN:
            this->armySprite.setTextureRect(sf::IntRect(1000, 200, static_cast<int>(this->armySize), static_cast<int>(this->armySize)));
            this->armyAttack = 6;
            this->armyHealth = 5;
            this->armyUpgrade = enumSquad::SQUAD_BAZOOKA;
            this->armyType = enumTypeSquad::TYPE_RANGE;
            break;

        case enumSquad::SQUAD_BAZOOKA:
            this->armySprite.setTextureRect(sf::IntRect(1200, 200, static_cast<int>(this->armySize), static_cast<int>(this->armySize)));
            this->armyAttack = 8;
            this->armyHealth = 6;
            this->armyUpgrade = enumSquad::SQUAD_ROCKET;
            this->armyType = enumTypeSquad::TYPE_RANGE;
            break;

        case enumSquad::SQUAD_ROCKET:
            this->armySprite.setTextureRect(sf::IntRect(1400, 200, static_cast<int>(this->armySize), static_cast<int>(this->armySize)));
            this->armyAttack = 11;
            this->armyHealth = 8;
            this->armyUpgrade = enumSquad::NONE;
            this->armyType = enumTypeSquad::TYPE_RANGE;
            break;

        case enumSquad::SQUAD_HOURSEARCHER:
            this->armySprite.setTextureRect(sf::IntRect(0, 400, static_cast<int>(this->armySize), static_cast<int>(this->armySize)));
            this->armyAttack = 1;
            this->armyHealth = 3;
            this->armyUpgrade = enumSquad::NONE;
            this->armyType = enumTypeSquad::TYPE_CAVALRY;
            break;

        case enumSquad::SQUAD_HORSEMAN:
            this->armySprite.setTextureRect(sf::IntRect(200, 400, static_cast<int>(this->armySize), static_cast<int>(this->armySize)));
            this->armyAttack = 1;
            this->armyHealth = 5;
            this->armyUpgrade = enumSquad::NONE;
            this->armyType = enumTypeSquad::TYPE_CAVALRY;
            break;

        case enumSquad::SQUAD_KNIGHT:
            this->armySprite.setTextureRect(sf::IntRect(400, 400, static_cast<int>(this->armySize), static_cast<int>(this->armySize)));
            this->armyAttack = 2;
            this->armyHealth = 6;
            this->armyUpgrade = enumSquad::SQUAD_LANCER;
            this->armyType = enumTypeSquad::TYPE_CAVALRY;
            break;

        case enumSquad::SQUAD_LANCER:
            this->armySprite.setTextureRect(sf::IntRect(600, 400, static_cast<int>(this->armySize), static_cast<int>(this->armySize)));
            this->armyAttack = 3;
            this->armyHealth = 9;
            this->armyUpgrade = enumSquad::NONE;
            this->armyType = enumTypeSquad::TYPE_ANTICAVALRYCAVALRY;
            break;

        case enumSquad::SQUAD_CAVALRY:
            this->armySprite.setTextureRect(sf::IntRect(800, 400, static_cast<int>(this->armySize), static_cast<int>(this->armySize)));
            this->armyAttack = 4;
            this->armyHealth = 9;
            this->armyUpgrade = enumSquad::SQUAD_TANKETTE;
            this->armyType = enumTypeSquad::TYPE_CAVALRY;
            break;

        case enumSquad::SQUAD_TANKETTE:
            this->armySprite.setTextureRect(sf::IntRect(1000, 400, static_cast<int>(this->armySize), static_cast<int>(this->armySize)));
            this->armyAttack = 4;
            this->armyHealth = 14;
            this->armyUpgrade = enumSquad::SQUAD_TANK;
            this->armyType = enumTypeSquad::TYPE_CAVALRY;
            break;

        case enumSquad::SQUAD_TANK:
            this->armySprite.setTextureRect(sf::IntRect(1200, 400, static_cast<int>(this->armySize), static_cast<int>(this->armySize)));
            this->armyAttack = 4;
            this->armyHealth = 17;
            this->armyUpgrade = enumSquad::SQUAD_MODERNTANK;
            this->armyType = enumTypeSquad::TYPE_CAVALRY;
            break;

        case enumSquad::SQUAD_MODERNTANK:
            this->armySprite.setTextureRect(sf::IntRect(1400, 400, static_cast<int>(this->armySize), static_cast<int>(this->armySize)));
            this->armyAttack = 6;
            this->armyHealth = 23;
            this->armyUpgrade = enumSquad::NONE;
            this->armyType = enumTypeSquad::TYPE_CAVALRY;
            break;

        case enumSquad::SQUAD_SPEARMAN:
            this->armySprite.setTextureRect(sf::IntRect(0, 600, static_cast<int>(this->armySize), static_cast<int>(this->armySize)));
            this->armyAttack = 1;
            this->armyHealth = 2;
            this->armyUpgrade = enumSquad::SQUAD_HOPLITE;
            this->armyType = enumTypeSquad::TYPE_ANTICAVALRY;
            break;

        case enumSquad::SQUAD_HOPLITE:
            this->armySprite.setTextureRect(sf::IntRect(200, 600, static_cast<int>(this->armySize), static_cast<int>(this->armySize)));
            this->armyAttack = 2;
            this->armyHealth = 3;
            this->armyUpgrade = enumSquad::SQUAD_PIKEMAN;
            this->armyType = enumTypeSquad::TYPE_ANTICAVALRY;
            break;

        case enumSquad::SQUAD_PIKEMAN:
            this->armySprite.setTextureRect(sf::IntRect(400, 600, static_cast<int>(this->armySize), static_cast<int>(this->armySize)));
            this->armyAttack = 2;
            this->armyHealth = 5;
            this->armyUpgrade = enumSquad::SQUAD_LANCER;
            this->armyType = enumTypeSquad::TYPE_ANTICAVALRY;
            break;

        case enumSquad::SQUAD_ARTBATTERY:
            this->armySprite.setTextureRect(sf::IntRect(1000, 600, static_cast<int>(this->armySize), static_cast<int>(this->armySize)));
            this->armyAttack = 6;
            this->armyHealth = 10;
            this->armyUpgrade = enumSquad::SQUAD_ANTITANKCANNON;
            this->armyType = enumTypeSquad::TYPE_ANTICAVALRY;
            break;

        case enumSquad::SQUAD_ANTITANKCANNON:
            this->armySprite.setTextureRect(sf::IntRect(1200, 600, static_cast<int>(this->armySize), static_cast<int>(this->armySize)));
            this->armyAttack = 8;
            this->armyHealth = 11;
            this->armyUpgrade = enumSquad::SQUAD_ARTILLERY;
            this->armyType = enumTypeSquad::TYPE_ANTICAVALRY;
            break;

        case enumSquad::SQUAD_ARTILLERY:
            this->armySprite.setTextureRect(sf::IntRect(1400, 600, static_cast<int>(this->armySize), static_cast<int>(this->armySize)));
            this->armyAttack = 12;
            this->armyHealth = 17;
            this->armyUpgrade = enumSquad::NONE;
            this->armyType = enumTypeSquad::TYPE_ANTICAVALRY;
            break;

        case enumSquad::SQUAD_ROBOT:
            this->armySprite.setTextureRect(sf::IntRect(1600, 200, static_cast<int>(this->armySize), static_cast<int>(this->armySize)));
            this->armyAttack = 9;
            this->armyHealth = 32;
            this->armyUpgrade = enumSquad::NONE;
            this->armyType = enumTypeSquad::TYPE_NONE;
            break;
    default:
        break;
    }
}

Squad::~Squad()
{

}