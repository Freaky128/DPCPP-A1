#pragma once

#include "Item.h"
#include <iostream>
#include <vector>
#include <memory>

class Game;

class ItemManager
{
private:
    std::vector<std::shared_ptr<Item> > items;

public:
    void registerItem(Item* item);
    void displayItems(int& balance);
    void buy(std::vector<std::string> args, Game& g);
    void inventory(Game& g) const;
};