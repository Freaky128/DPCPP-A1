#pragma once

#include <string>
#include <iostream>

struct Item
{
private:
    std::string name;
    bool bought = false;
    int price;
    float scrapValMult;
    float explorerSurvivalMult;
    float opSurvivalMult;
    float saveChance;
    float lootRecovMult;

public:
    Item(std::string name, int price, float scrapValMult, float explorerSurvivalMult, float opSurvivalMult, float saveChance, float lootRecovMult)
        : name(name),
        price(price),
        scrapValMult(scrapValMult),
        explorerSurvivalMult(explorerSurvivalMult),
        opSurvivalMult(opSurvivalMult),
        saveChance(saveChance),
        lootRecovMult(lootRecovMult) {
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
};