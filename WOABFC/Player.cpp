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

void Player::setOrderOfArmy() 
{
    switch (this->playerActiveArmy.size())
    {
    case 1: 
        this->playerActiveArmy.at(0)->setArmySpawnCoordinateX(860.0);
        break;
    case 2: 
        this->playerActiveArmy.at(0)->setArmySpawnCoordinateX(735.0);
        this->playerActiveArmy.at(1)->setArmySpawnCoordinateX(985.0);
        break;
    case 3: 
        this->playerActiveArmy.at(0)->setArmySpawnCoordinateX(610.0);
        this->playerActiveArmy.at(1)->setArmySpawnCoordinateX(860.0);
        this->playerActiveArmy.at(2)->setArmySpawnCoordinateX(1110.0);
        break;
    case 4: 
        this->playerActiveArmy.at(0)->setArmySpawnCoordinateX(485.0);
        this->playerActiveArmy.at(1)->setArmySpawnCoordinateX(735.0);
        this->playerActiveArmy.at(2)->setArmySpawnCoordinateX(985.0);
        this->playerActiveArmy.at(3)->setArmySpawnCoordinateX(1235.0);
        break;
    case 5: 
        this->playerActiveArmy.at(0)->setArmySpawnCoordinateX(360.0);
        this->playerActiveArmy.at(1)->setArmySpawnCoordinateX(610.0);
        this->playerActiveArmy.at(2)->setArmySpawnCoordinateX(860.0);
        this->playerActiveArmy.at(3)->setArmySpawnCoordinateX(1110.0);
        this->playerActiveArmy.at(4)->setArmySpawnCoordinateX(1360.0);
        break;
    case 6: 
        this->playerActiveArmy.at(0)->setArmySpawnCoordinateX(235.0);
        this->playerActiveArmy.at(1)->setArmySpawnCoordinateX(485.0);
        this->playerActiveArmy.at(2)->setArmySpawnCoordinateX(735.0);
        this->playerActiveArmy.at(3)->setArmySpawnCoordinateX(985.0);
        this->playerActiveArmy.at(4)->setArmySpawnCoordinateX(1235.0);
        this->playerActiveArmy.at(5)->setArmySpawnCoordinateX(1485.0);
        break;
    case 7: 
        this->playerActiveArmy.at(0)->setArmySpawnCoordinateX(110.0);
        this->playerActiveArmy.at(1)->setArmySpawnCoordinateX(360.0);
        this->playerActiveArmy.at(2)->setArmySpawnCoordinateX(610.0);
        this->playerActiveArmy.at(3)->setArmySpawnCoordinateX(860.0);
        this->playerActiveArmy.at(4)->setArmySpawnCoordinateX(1110.0);
        this->playerActiveArmy.at(5)->setArmySpawnCoordinateX(1360.0);
        this->playerActiveArmy.at(6)->setArmySpawnCoordinateX(1610.0);
        break;
    default:
        break;
    }
}

std::vector <Army*> Player::setPlayerTempArmy(std::vector <Army*> tempArmy)
{
    setPlayerActiveArmy(tempArmy);
    setOrderOfArmy();
    return getPlayerActiveArmy();
}