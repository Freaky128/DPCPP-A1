#pragma once

#include "Item.h"
#include <iostream>
#include <vector>
#include <memory>

class ItemManager
{
private:
    std::vector<std::shared_ptr<Item> > items;

public:
    void registerItem(Item* item);
    void displayItems(int& balance);
};