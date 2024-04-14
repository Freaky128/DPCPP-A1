#include "Moon.h"
#include "Game.h"

Moon::Moon(std::string nName, int minValue, int maxValue, float nBaseSurvival)
    : AbstractMoon(nName), minLootValue(minValue), maxLootValue(maxValue), baseSurvival(nBaseSurvival) {
}

void Moon::onDayBegin(Game &g) 
{
    std::uniform_int_distribution<int> intDistribution(0, 3);
    weather = static_cast<MoonWeather>(intDistribution(g.myGenerator));
}

void Moon::landingMessage() const
{
    if (static_cast<int>(weather) != 0) {
        std::cout << "Proceed with caution as the moon is currently " << getWeather() << std::endl;
    }

    std::cout << "\nType SEND followed by the number of employees you wish to send inside the facility. All the other employees will stay on the ship." << std::endl;
    std::cout << "Type LEAVE to leave the planet. \n" << std::endl;
}

void Moon::sendEmployees(Game &g, int count)
{
    int aliveEmployees = g.getEmployees();
    int numOperators = (aliveEmployees - count);
     
    double  explorerSurvivalChanceMultiplier = weatherMatrix[static_cast<int>(weather)][1];
    
    //std::cout << "Weather: " << static_cast<int>(weather) << std::endl;
    //std::cout << "weatherExpSurvivalMult: " << explorerSurvivalChanceMultiplier << std::endl;

    std::vector<std::shared_ptr<Item> > items = g.getItems();
    for (std::shared_ptr<Item> &i : items) {
        explorerSurvivalChanceMultiplier = explorerSurvivalChanceMultiplier * i->getEpSurvivalMult();
    }

    //std::cout << "expSurvivalMult: " << explorerSurvivalChanceMultiplier << std::endl;

    double explorerSurvivalChance = baseSurvival * explorerSurvivalChanceMultiplier;
    
    //std::cout << "expSurvivalChance: " << explorerSurvivalChance << std::endl;

    float explorerSaveChance = 0;

    for (std::shared_ptr<Item> &i : items) {
        explorerSaveChance += i->getSaveChance();
    }
    
    //std::cout << "explorerSaveChance: " << explorerSaveChance << std::endl;

    double scrapValueMultiplier = weatherMatrix[static_cast<int>(weather)][0];

    //std::cout << "weatherScrapValueMultiplier: " << scrapValueMultiplier << std::endl;

    for (std::shared_ptr<Item> &i : items) {
        scrapValueMultiplier = scrapValueMultiplier * i->getScrapValMult();
    }

    //std::cout << "scrapValueMultiplier: " << scrapValueMultiplier << std::endl;

    double lootRecoveryMultiplier = 0.5;

    for (std::shared_ptr<Item> &i : items) {
        lootRecoveryMultiplier = lootRecoveryMultiplier * i->getLootRecovMult();
    }

    //std::cout << "lootRecoveryMultiplier: " << lootRecoveryMultiplier << std::endl;

    int totalRevenue = 0;
    int deadExplorers = 0;

    std::uniform_int_distribution<int> intDistribution(minLootValue * scrapValueMultiplier, maxLootValue * scrapValueMultiplier);
    std::uniform_real_distribution<float> realDistribution;

    for (int i = 0; i < count; i++) {
        
        int revenue = intDistribution(g.myGenerator);
        
        if (realDistribution(g.myGenerator) < explorerSurvivalChance) {
            totalRevenue += revenue;
        }
        else if (realDistribution(g.myGenerator) >= explorerSaveChance) {
            totalRevenue += revenue * lootRecoveryMultiplier;
            deadExplorers += 1;
        }
    }

    double operatorSurvivalChanceMultiplier = weatherMatrix[static_cast<int>(weather)][2];

    for (std::shared_ptr<Item> &i : items) {
        operatorSurvivalChanceMultiplier = operatorSurvivalChanceMultiplier * i->getOpSurvivalMult();
    }

    //std::cout << "operatorSurvivalChanceMultiplier: " << operatorSurvivalChanceMultiplier << std::endl;

    double operatorSurvivalChance = 1.0 * operatorSurvivalChanceMultiplier;

    int deadOperators = 0;

    for (int i = 0; i < numOperators; i++) {
        if (realDistribution(g.myGenerator) >= operatorSurvivalChance) {
            deadOperators += 1;
        }
    }

    aliveEmployees -= deadExplorers;

    if (count - deadExplorers > 0) {
        std::cout << "\n" << count - deadExplorers << " employees made it back to the ship, bringing $" << totalRevenue << " worth of scrap. " << deadExplorers << " died." << std::endl;
        g.setCargoBalance(totalRevenue);
    }
    else {
        std::cout << "\n" << "None of the employees managed to make it back. " << aliveEmployees << " employees left." << std::endl;
    }

    if (deadOperators > 0) {
        std::cout << "In the meantime, " << deadOperators << " employees left on the ship died." << std::endl;
        aliveEmployees -= deadOperators;
    }

    std::cout << std::endl;

    g.setEmployees(aliveEmployees);

    if (aliveEmployees == 0) {
        g.clearCargoBalance();
        std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\nAll the employees died and the scrap is lost.\nAutopilot will now bring the ship back to orbit.\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
        g.leave();
    }
}

void Moon::sellCargo(Game &g, int amount) 
{
    std::cout << "\nThis command is not available on this moon.\n" << std::endl;
}
