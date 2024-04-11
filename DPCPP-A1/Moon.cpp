#include "Moon.h"
#include "Game.h"

Moon::Moon(std::string name, int minValue, int maxValue, float baseSurvival)
    : AbstractMoon(name) {
    this->minValue = minValue;
    this->maxValue = maxValue;
    this->baseSurvival = baseSurvival;
}

void Moon::onDayBegin(Game& g) 
{
    std::uniform_int_distribution<int> intDistribution(0, 3);
    weather = static_cast<MoonWeather>(intDistribution(g.myGenerator));
}

void Moon::landingMessage()
{
    std::cout << "\nType SEND followed by the number of employees you wish to send inside the facility. All the other employees will stay on the ship." << std::endl;
    std::cout << "Type LEAVE to leave the planet. \n" << std::endl;
}