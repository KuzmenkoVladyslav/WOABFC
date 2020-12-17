#pragma once
#include "enumEraName.h"
#include "Army.h"
#include <vector>

class Player
{
public:
    Player() {};
    ~Player() {};

    bool getIsWinLastGame();

    void setIsWinLastGame(bool isWinLastGame);

    int getPlayerHealth();
    
    void setPlayerHealth(int playerHealth);

    int getPlayerActionPointsNow();

    void setPlayerActionPointsNow(int playerActionPointsNow);

    int getPlayerActionPointsMax();

    void setPlayerActionPointsMax(int playerActionPointsMax);

    int getPlayerReserveCount();

    int getPlayerArmyCount();

    void setPlayerArmyCount(int playerArmyCount);

    int getPlayerNextEraCost();

    void setPlayerNextEraCost(int playerNextEraCost);

    int getPlayerAdditionalPlaceForSquadCost();

    void setPlayerAdditionalPlaceForSquadCost(int playerAdditionalPlaceForSquadCost);

    std::vector <Army*> getPlayerActiveArmy();

    void setPlayerActiveArmy(const std::vector<Army*>& playerActiveArmy);

    std::vector <Army*> getPlayerReserveArmy();

    void setPlayerReserveArmy(const std::vector<Army*>& playerReserveArmy);

    enumEraName getPlayerEra();

    void setPlayerEra(enumEraName playerEra);
    
    void setOrderOfActiveArmy();

    void setOrderOfReserveArmy();

    std::vector <Army*> setPlayerTempActiveArmy(std::vector <Army*> tempArmy);

    std::vector <Army*> setPlayerTempReserveArmy(std::vector <Army*> tempArmy);

private:
    int playerHealth = 50;
    int playerActionPointsNow = 3;
    int playerActionPointsMax = 3;
    int playerReserveCount = 3;
    int playerArmyCount = 3;
    int playerNextEraCost = 4;
    int playerAdditionalPlaceForSquadCost = 5;
    bool isWinLastGame = false;

    std::vector <Army*> playerActiveArmy;
    std::vector <Army*> playerReserveArmy;
    enumEraName playerEra = enumEraName::ERA_ANCIENT;
};