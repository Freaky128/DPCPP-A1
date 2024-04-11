#pragma once

#include "ItemManager.h"
#include "Item.h"
#include "MoonManager.h"
#include "Moon.h"
#include "CorpMoon.h"
#include "game_title.h"

class Game
{
private:
    bool isRunning = true;
    int dayNum = 1;
    int quota = 150;
    int balance = 50;
    int cargoBalance = 0;
    int employees = 4;
    std::shared_ptr<AbstractMoon> moon;
    ItemManager itemManager;
    MoonManager moonManager;

public:
    Game();
    void run();
};