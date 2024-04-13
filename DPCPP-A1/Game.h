#pragma once

#include "ItemManager.h"
#include "Item.h"
#include "MoonManager.h"
#include "Moon.h"
#include "CorpMoon.h"
#include "game_title.h"
#include "util.h"
#include "PaidMoon.h"

#include <random>

class Game
{
private:
    bool isRunning = true;
    bool isSameDay = true;
    int dayNum = 1;
    int quota = 150;
    int balance = 50;
    int cargoBalance = 0;
    int employees = 4;
    bool isLanded = false;
    std::shared_ptr<AbstractMoon> moon;
    std::vector<std::shared_ptr<Item> > items;
    ItemManager itemManager;
    MoonManager moonManager;

public:
    std::mt19937 myGenerator; //compiler kept thinking that myGenerator was a function if i seeded it here so it is now seeded in the constructor of Game

    Game();
    void run();
    void land();
    void leave();
    void gameExit();

    int getQuota() const;
    int getBalance() const;
    int getCargoValue() const;
    int getEmployees() const;
    const std::string getMoonNameLower() const;
    const std::string getMoonName() const;
    const std::vector<std::shared_ptr<Item> >& getItems();

    void setBalance(int value);
    void setCargoBalance(int value);
    void clearCargoBalance();
    void setEmployees(int value);
    void setMoon(std::shared_ptr<AbstractMoon> moon);
    void addItem(std::shared_ptr<Item> item);
    
};