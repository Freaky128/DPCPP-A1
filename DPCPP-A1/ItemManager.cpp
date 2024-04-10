#include "ItemManager.h"

void ItemManager::registerItem(Item* item)
{
    std::unique_ptr<Item> temp(item);

    std::cout << temp->getName() << std::endl;
    
    items.push_back(std::move(temp));
    
    /*for (std::unique_ptr<Item>& i : items) {
        std::cout << i->getName() << std::endl;
    }*/
    return;
}
