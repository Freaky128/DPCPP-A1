#include "PaidMoon.h"
#include "Game.h"

PaidMoon::PaidMoon(std::string name, int minValue, int maxValue, float baseSurvival, int price) 
    : Moon(name, minValue, maxValue, baseSurvival), price(price) {
}

bool PaidMoon::onNavigate(Game& g) const
{
    std::cout << "\nThe cost of going to " << name() << " is $" << price << std::endl;
    std::cout << "You have $" << g.getBalance() << ". Confirm destination? [Yes/No]\n" << std::endl;
    
    while (true) {
        std::cout << ">";
        std::string command;
        std::getline(std::cin, command);
        util::lower(command);

        if (command == "no") {
            std::cout << "\nTrip cancelled." << std::endl;
            std::cout << "Still orbiting " << g.getMoonName() << ".\n" << std::endl;
            return false;
        }
        else if (command == "yes") {
            if (g.getBalance() >= price) {
                g.setBalance(-price);
                std::cout << "\nNew balance: $" << g.getBalance() << std::endl;
                return true;
            }
            else {
                std::cout << "\nInsufficent funds. Trip cancelled." << std::endl;
                std::cout << "Still orbiting " << g.getMoonName() << ".\n" << std::endl;
                return false;
            }
        }
        else {
            std::cout << "\nUnknown command. Please input [Yes/No]\n" << std::endl;
        }
    }
}

void PaidMoon::print() const
{
    std::cout << ": $" << price << std::endl;
}
