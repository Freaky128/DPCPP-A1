#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>

struct Item
{
public:
    Item(std::string nName, int nPrice, float nScrapValMult, float nExplorerSurvivalMult, float nOpSurvivalMult, float nSaveChance, float nLootRecovMult)
        : name(nName),
        price(nPrice),
        scrapValMult(nScrapValMult),
        explorerSurvivalMult(nExplorerSurvivalMult),
        opSurvivalMult(nOpSurvivalMult),
        saveChance(nSaveChance),
        lootRecovMult(nLootRecovMult) {
    }

    std::string getName() const { return name;}
    bool isBought() const { return bought; };
    void buy() { bought = true; }
    int getPrice() const { return price; }
    float getScrapValMult() const { return scrapValMult; }
    float getEpSurvivalMult() const { return explorerSurvivalMult; }
    float getOpSurvivalMult() const { return opSurvivalMult; }
    float getSaveChance() const { return saveChance; }
    float getLootRecovMult() const { return lootRecovMult; }

    /*~Item() {
       std::cout << "deleted item" << std::endl;
    }*/

private:
    std::string name;
    bool bought = false;
    int price;
    float scrapValMult;
    float explorerSurvivalMult;
    float opSurvivalMult;
    float saveChance;
    float lootRecovMult;

};

#endif //ITEM_H