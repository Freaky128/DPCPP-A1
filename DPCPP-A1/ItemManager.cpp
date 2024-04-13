#include "ItemManager.h"
#include "Game.h"

void ItemManager::registerItem(Item* item)
{
    std::shared_ptr<Item> temp(item);

    //std::cout << temp->getName() << std::endl;
    
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
        if (!i->isBought()) {
            std::cout << " Price: $" << i->getPrice() << std::endl;
        }
        else {
            std::cout << "Bought" << std::endl;
        }
    }
    std::cout << "\nBalance: $" << balance << "\n" << std::endl;
}

void ItemManager::buy(std::vector<std::string> args, Game& g)
{
    if (args.empty() || args.size() > 1) {
        std::cout << "\nBad command; the syntax is: \"buy itemName\" \n" << std::endl;
    }
    else {
        for (std::shared_ptr<Item>& i : items) {
            std::string name = i->getName();
            util::lower(name);
            if (args[0] == name) {
                if (i->isBought()) {
                    std::cout << "\nYou already own a " << i->getName() << "\n" << std::endl;
                    return;
                }
                else if (i->getPrice() > g.getBalance()) {
                    std::cout << "\nYou don't have enough funds to buy this item.\n" << std::endl;
                    return;
                }
                else {
                    g.addItem(i);
                    i->buy();
                    g.setBalance(-i->getPrice());
                    std::cout << "\nSuccessfully bought " << i->getName() << "." << std::endl;
                    std::cout << "Your balance is now $" << g.getBalance() << "\n" << std::endl;
                    return;
                }
            }
        }
        std::cout << "\nUnknown item \"" << args[0] << "\".\n" << std::endl;
    }
}

void ItemManager::inventory(Game& g) const
{
    std::cout << "The following items are available." << std::endl;
    std::cout << "---------------------------------------\n" << std::endl;
    std::vector<std::shared_ptr<Item> > inventory = g.getItems();
    if (inventory.empty()) {
        std::cout << "(Empty)" << std::endl;
    }
    else {
        for (std::shared_ptr<Item>& i : inventory) {
            std::cout << "* " << i->getName() << std::endl;
        }
    }
    std::cout << "\nBalance: $" << g.getBalance() << "  (quota is $" << g.getQuota() << ")" << std::endl;
    std::cout << "Cargo value: $" << g.getCargoValue() << "\n" << std::endl;
}


