#pragma once

#include "ItemManager.h"
#include "Item.h"
#include "MoonManager.h"
#include "Moon.h"
#include "CorpMoon.h"

class Game
{
private:
    int balance = 0;
    int cargoBalance = 0;
    int employees = 0;
    ItemManager itemManager;
    MoonManager moonManager;

public:
    Game();
    void run();
};