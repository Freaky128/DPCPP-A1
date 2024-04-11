#include "ItemManager.h"

void ItemManager::registerItem(Item* item)
{
    std::shared_ptr<Item> temp(item);

    std::cout << temp->getName() << std::endl;
    
    items.push_back(std::move(temp));
    
    /*for (std::unique_ptr<Item>& i : items) {
        std::cout << i->getName() << std::endl;
    }*/
    return;
}

void ItemManager::displayItems(int& balance)
{
    std::cout << "\nWelcome to the Corporation store." << std::endl;
    std::cout << "Use the word BUY on any item." << std::endl;
    std::cout << "---------------------------------------\n" << std::endl;
    for (std::shared_ptr<Item>& i : items) {
        std::cout << "* " << i->getName() << " // ";
        if (!i->getBought()) {
            std::cout << " Price: $" << i->getPrice() << std::endl;
        }
        else {
            std::cout << "Bought" << std::endl;
        }
    }
    std::cout << "\nBalance: $" << balance << "\n" << std::endl;
}


