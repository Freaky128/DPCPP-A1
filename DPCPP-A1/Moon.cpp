#include "Moon.h"
#include "Game.h"

Moon::Moon(std::string name, int minValue, int maxValue, float baseSurvival)
    : AbstractMoon(name) {
    this->minValue = minValue;
    this->maxValue = maxValue;
    this->baseSurvival = baseSurvival;
}

void Moon::onDayBegin(Game& g) {
    std::uniform_int_distribution<int> intDistribution(0, 3);
    weather = static_cast<MoonWeather>(intDistribution(g.myGenerator));
}