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
