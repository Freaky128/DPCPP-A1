#pragma once

#include <string>
#include <iostream>

struct Item
{
private:
    std::string name;
    int price;
    float scrapValMult;
    float explorerSurvivalMult;
    float opSurvivalMult;
    float saveChance;
    float lootRecovMult;

public:
    Item(std::string name, int price, float scrapValMult, float explorerSurvivalMult, float opSurvivalMult, float saveChance, float lootRecovMult) {
        this->name = name;
        this->price = price;
        this->scrapValMult = scrapValMult;
        this->explorerSurvivalMult = explorerSurvivalMult;
        this->opSurvivalMult = opSurvivalMult;
        this->saveChance = saveChance;
        this->lootRecovMult = lootRecovMult;
    }

    std::string getName() const { return name;}
    int getPrice() const { return price; }
    float getScrapValMult() const { return scrapValMult; }
    float getOpSurvivalMult() const { return opSurvivalMult; }
    float getSaveChance() const { return saveChance; }
    float getLootRecovMult() const { return lootRecovMult; }

    ~Item() {
        std::cout << "deleted" << std::endl;
    }
};