#pragma once
#include "Army.h"

class Squad :
    public Army
{
public:
    Squad(enumSquad armyID);
    ~Squad() {};
};