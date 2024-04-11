#include "MoonManager.h"
#include "Game.h"

void MoonManager::registerMoon(AbstractMoon* moon)
{
    std::shared_ptr<AbstractMoon> temp(moon);

    std::cout << temp->name() << std::endl;

    moons.push_back(std::move(temp));

    /*for (std::unique_ptr<AbstractMoon>& i : moons) {
        std::cout << i->name() << std::endl;
    }*/
    return;
}

std::shared_ptr<AbstractMoon> MoonManager::getStartingMoon()
{
    return moons[0];
}

void MoonManager::displayMoons(int &balance)
{
    std::cout << "\nWelcome to the exomoons catalogue." << std::endl;
    std::cout << "To route the autopilot to a moon, use the word ROUTE." << std::endl;
    std::cout << "---------------------------------------\n" << std::endl;
    for (std::shared_ptr<AbstractMoon>& i : moons) {
        std::cout << "* " << i->name();
        std::string weather = i->getWeather();
        if (weather != "") {
            std::cout << " (" << i->getWeather() << ")" << std::endl;
        }
        else {
            std::cout << std::endl;
        }
    }
    std::cout << "\nBalance: $" << balance << "\n" << std::endl;
}

void MoonManager::onDayBegin(Game& g)
{
    for (std::shared_ptr<AbstractMoon>& i : moons) {
        i->onDayBegin(g);
    }
}
