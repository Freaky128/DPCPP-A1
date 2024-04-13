#include "CorpMoon.h"
#include "Game.h"

void CorpMoon::landingMessage() const
{
    std::cout << "\nType SELL to sell your cargo contents and increase your balance and achieve quota. Specify the amount to sell after the SELL word to only sell a portion of your cargo." << std::endl;
    std::cout << "Type LEAVE to leave the planet.\n" << std::endl;
}

void CorpMoon::sendEmployees(Game& g, int count)
{
    std::cout << "\nThis command is not available on this moon.\n" << std::endl;
}

void CorpMoon::sellCargo(Game& g, int amount)
{
    if (g.getCargoValue() == 0) {
        std::cout << "\nNothing to sell.\n" << std::endl;
        return;
    }
    else if (amount == -1) {        
            g.setBalance(g.getCargoValue());
            g.clearCargoBalance();
    }
    else if (amount > g.getCargoValue()) {
        std::cout << "\nOnly $" << g.getCargoValue() << " available in cargo.\n" << std::endl;
        return;
    }
    else {
        g.setCargoBalance(-amount);
        g.setBalance(amount);
    }

    std::cout << "\nYour service is invaluable to the corporation." << std::endl;
    std::cout << "New balance: $" << g.getBalance() << " (quota is $" << g.getQuota() << ")" << std::endl;
    std::cout << "New cargo value: $" << g.getCargoValue() << "\n" << std::endl;
}
