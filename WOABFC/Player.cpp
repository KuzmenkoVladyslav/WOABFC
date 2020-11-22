#include "Player.h"

int Player::getPlayerHealth()
{
    return this->playerHealth;
}

void Player::setPlayerHealth(int playerHealth)
{
    this->playerHealth = playerHealth;
}

int Player::getPlayerActionPointsNow()
{
    return this->playerActionPointsNow;
}

void Player::setPlayerActionPointsNow(int playerActionPointsNow)
{
    this->playerActionPointsNow = playerActionPointsNow;
}

int Player::getPlayerActionPointsMax()
{
    return this->playerActionPointsMax;
}

void Player::setPlayerActionPointsMax(int playerActionPointsMax)
{
    this->playerActionPointsMax = playerActionPointsMax;
}

int Player::getPlayerReserveCount()
{
    return this->playerReserveCount;
}

int Player::getPlayerArmyCount()
{
    return this->playerArmyCount;
}

void Player::setPlayerArmyCount(int playerArmyCount)
{
    this->playerArmyCount = playerArmyCount;
}

int Player::getPlayerNextEraCost()
{
    return this->playerNextEraCost;
}

void Player::setPlayerNextEraCost(int playerNextEraCost)
{
    this->playerNextEraCost = playerNextEraCost;
}

int Player::getPlayerAdditionalPlaceForSquadCost()
{
    return this->playerAdditionalPlaceForSquadCost;
}

void Player::setPlayerAdditionalPlaceForSquadCost(int playerAdditionalPlaceForSquadCost)
{
    this->playerAdditionalPlaceForSquadCost = playerAdditionalPlaceForSquadCost;
}

void Player::setPlayerActiveArmy(const std::vector<Army*>& playerActiveArmy) 
{ 
    this->playerActiveArmy = playerActiveArmy; 
}

std::vector <Army*> Player::getPlayerActiveArmy()
{
    return playerActiveArmy;
}

void Player::setPlayerReserveArmyy(const std::vector<Army*>& playerReserveArmy)
{ 
    this->playerReserveArmy = playerReserveArmy; 
}

std::vector <Army*> Player::getPlayerReserveArmy()
{
    return playerReserveArmy;
}

enumEraName Player::getPlayerEra()
{
    return playerEra;
}

void Player::setPlayerEra(enumEraName playerEra)
{
    this->playerEra = playerEra;
    switch (this->playerEra)
    {
    case enumEraName::ERA_CLASSIC:
        this->playerReserveCount = 3;
        this->playerNextEraCost = 5;

    case enumEraName::ERA_MEDIVAL:
        this->playerReserveCount = 4;
        this->playerNextEraCost = 5;

    case enumEraName::ERA_RENAISSANCEE:
        this->playerReserveCount = 4;
        this->playerNextEraCost = 5;

    case enumEraName::ERA_INDUSTRIAL:
        this->playerReserveCount = 5;
        this->playerNextEraCost = 6;

    case enumEraName::ERA_MODERN:
        this->playerReserveCount = 5;
        this->playerNextEraCost = 6;

    case enumEraName::ERA_ATOMIC:
        this->playerReserveCount = 6;
        this->playerNextEraCost = 7;

    case enumEraName::ERA_INFORMATION:
        this->playerReserveCount = 6;
        this->playerNextEraCost = 8;

    case enumEraName::ERA_FUTURE:
        this->playerReserveCount = 7;
        this->playerNextEraCost = -1;

    default:
        break;
    }
}