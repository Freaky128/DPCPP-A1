#ifndef ITEMMANAGER_H
#define ITEMMANAGER_H

#include "Item.h"
#include <iostream>
#include <vector>
#include <memory>

class Game;

class ItemManager
{
public:
    void registerItem(Item *item);
    void displayItems(int &balance);
    void buy(std::vector<std::string> args, Game &g);
    void inventory(Game &g) const;

private:
    std::vector<std::shared_ptr<Item> > items;

};

#endif //ITEMMANAGER_H