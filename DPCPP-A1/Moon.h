#pragma once

#include "AbstractMoon.h"

#include<random>

class Game;

class Moon : public AbstractMoon
{
private:
    int minValue;
    int maxValue;
    float baseSurvival;

public:
    Moon(std::string name, int minValue, int maxValue, float baseSurvival);

    int getMinValue() const { return minValue; }
    int getMaxValue() const { return maxValue; }
    float getBaseSurvival() const { return baseSurvival; }

    void onDayBegin(Game& g);
};