#include "Player.h"

bool Player::getIsWinLastGame() 
{
    return isWinLastGame;
}

void Player::setIsWinLastGame(bool isWinLastGame) 
{
    this->isWinLastGame = isWinLastGame;
}

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

void Player::setPlayerReserveArmy(const std::vector<Army*>& playerReserveArmy)
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
        this->playerNextEraCost = 6;
        this->playerActionPointsMax = 3;
        break;

    case enumEraName::ERA_MEDIVAL:
        this->playerReserveCount = 4;
        this->playerNextEraCost = 6;
        this->playerActionPointsMax = 3;
        break;

    case enumEraName::ERA_RENAISSANCEE:
        this->playerReserveCount = 4;
        this->playerNextEraCost = 6;
        this->playerActionPointsMax = 4;
        break;

    case enumEraName::ERA_INDUSTRIAL:
        this->playerReserveCount = 5;
        this->playerNextEraCost = 7;
        this->playerActionPointsMax = 4;
        break;

    case enumEraName::ERA_MODERN:
        this->playerReserveCount = 5;
        this->playerNextEraCost = 7;
        this->playerActionPointsMax = 4;
        break;

    case enumEraName::ERA_ATOMIC:
        this->playerReserveCount = 6;
        this->playerNextEraCost = 8;
        this->playerActionPointsMax = 5;
        break;

    case enumEraName::ERA_INFORMATION:
        this->playerReserveCount = 6;
        this->playerNextEraCost = 9;
        this->playerActionPointsMax = 5;
        break;

    case enumEraName::ERA_FUTURE:
        this->playerReserveCount = 7;
        this->playerNextEraCost = -1;
        this->playerActionPointsMax = 6;
        break;

    default:
        break;
    }
}

void Player::setOrderOfActiveArmy() 
{
    switch (this->playerActiveArmy.size())
    {
    case 1: 
        this->playerActiveArmy.at(0)->setArmySpawnCoordinateX(860.0);
        break;
    case 2: 
        this->playerActiveArmy.at(0)->setArmySpawnCoordinateX(760.0);
        this->playerActiveArmy.at(1)->setArmySpawnCoordinateX(960.0);
        break;
    case 3: 
        this->playerActiveArmy.at(0)->setArmySpawnCoordinateX(660.0);
        this->playerActiveArmy.at(1)->setArmySpawnCoordinateX(860.0);
        this->playerActiveArmy.at(2)->setArmySpawnCoordinateX(1060.0);
        break;
    case 4: 
        this->playerActiveArmy.at(0)->setArmySpawnCoordinateX(560.0);
        this->playerActiveArmy.at(1)->setArmySpawnCoordinateX(760.0);
        this->playerActiveArmy.at(2)->setArmySpawnCoordinateX(960.0);
        this->playerActiveArmy.at(3)->setArmySpawnCoordinateX(1160.0);
        break;
    case 5: 
        this->playerActiveArmy.at(0)->setArmySpawnCoordinateX(460.0);
        this->playerActiveArmy.at(1)->setArmySpawnCoordinateX(660.0);
        this->playerActiveArmy.at(2)->setArmySpawnCoordinateX(860.0);
        this->playerActiveArmy.at(3)->setArmySpawnCoordinateX(1060.0);
        this->playerActiveArmy.at(4)->setArmySpawnCoordinateX(1260.0);
        break;
    case 6: 
        this->playerActiveArmy.at(0)->setArmySpawnCoordinateX(360.0);
        this->playerActiveArmy.at(1)->setArmySpawnCoordinateX(560.0);
        this->playerActiveArmy.at(2)->setArmySpawnCoordinateX(760.0);
        this->playerActiveArmy.at(3)->setArmySpawnCoordinateX(960.0);
        this->playerActiveArmy.at(4)->setArmySpawnCoordinateX(1160.0);
        this->playerActiveArmy.at(5)->setArmySpawnCoordinateX(1360.0);
        break;
    case 7: 
        this->playerActiveArmy.at(0)->setArmySpawnCoordinateX(260.0);
        this->playerActiveArmy.at(1)->setArmySpawnCoordinateX(460.0);
        this->playerActiveArmy.at(2)->setArmySpawnCoordinateX(660.0);
        this->playerActiveArmy.at(3)->setArmySpawnCoordinateX(860.0);
        this->playerActiveArmy.at(4)->setArmySpawnCoordinateX(1060.0);
        this->playerActiveArmy.at(5)->setArmySpawnCoordinateX(1260.0);
        this->playerActiveArmy.at(6)->setArmySpawnCoordinateX(1460.0);
        break;
    default:
        break;
    }
}

void Player::setOrderOfReserveArmy()
{
    switch (this->playerReserveArmy.size())
    {
    case 1:
        this->playerReserveArmy.at(0)->setArmySpawnCoordinates(860.0, 800.0);
        break;
    case 2:
        this->playerReserveArmy.at(0)->setArmySpawnCoordinates(760.0, 800.0);
        this->playerReserveArmy.at(1)->setArmySpawnCoordinates(960.0, 800.0);
        break;
    case 3:
        this->playerReserveArmy.at(0)->setArmySpawnCoordinates(660.0, 800.0);
        this->playerReserveArmy.at(1)->setArmySpawnCoordinates(860.0, 800.0);
        this->playerReserveArmy.at(2)->setArmySpawnCoordinates(1060.0, 800.0);
        break;
    case 4:
        this->playerReserveArmy.at(0)->setArmySpawnCoordinates(560.0, 800.0);
        this->playerReserveArmy.at(1)->setArmySpawnCoordinates(760.0, 800.0);
        this->playerReserveArmy.at(2)->setArmySpawnCoordinates(960.0, 800.0);
        this->playerReserveArmy.at(3)->setArmySpawnCoordinates(1160.0, 800.0);
        break;
    case 5:
        this->playerReserveArmy.at(0)->setArmySpawnCoordinates(460.0, 800.0);
        this->playerReserveArmy.at(1)->setArmySpawnCoordinates(660.0, 800.0);
        this->playerReserveArmy.at(2)->setArmySpawnCoordinates(860.0, 800.0);
        this->playerReserveArmy.at(3)->setArmySpawnCoordinates(1060.0, 800.0);
        this->playerReserveArmy.at(4)->setArmySpawnCoordinates(1260.0, 800.0);
        break;
    case 6:
        this->playerReserveArmy.at(0)->setArmySpawnCoordinates(360.0, 800.0);
        this->playerReserveArmy.at(1)->setArmySpawnCoordinates(560.0, 800.0);
        this->playerReserveArmy.at(2)->setArmySpawnCoordinates(760.0, 800.0);
        this->playerReserveArmy.at(3)->setArmySpawnCoordinates(960.0, 800.0);
        this->playerReserveArmy.at(4)->setArmySpawnCoordinates(1160.0, 800.0);
        this->playerReserveArmy.at(5)->setArmySpawnCoordinates(1360.0, 800.0);
        break;
    case 7:
        this->playerReserveArmy.at(0)->setArmySpawnCoordinates(260.0, 800.0);
        this->playerReserveArmy.at(1)->setArmySpawnCoordinates(460.0, 800.0);
        this->playerReserveArmy.at(2)->setArmySpawnCoordinates(660.0, 800.0);
        this->playerReserveArmy.at(3)->setArmySpawnCoordinates(860.0, 800.0);
        this->playerReserveArmy.at(4)->setArmySpawnCoordinates(1060.0, 800.0);
        this->playerReserveArmy.at(5)->setArmySpawnCoordinates(1260.0, 800.0);
        this->playerReserveArmy.at(6)->setArmySpawnCoordinates(1460.0, 800.0);
        break;
    default:
        break;
    }
}

std::vector <Army*> Player::setPlayerTempActiveArmy(std::vector <Army*> tempArmy)
{
    setPlayerActiveArmy(tempArmy);
    setOrderOfActiveArmy();
    return getPlayerActiveArmy();
}

std::vector <Army*> Player::setPlayerTempReserveArmy(std::vector <Army*> tempArmy)
{
    setPlayerReserveArmy(tempArmy);
    setOrderOfReserveArmy();
    return getPlayerReserveArmy();
}