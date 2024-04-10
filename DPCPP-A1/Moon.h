#pragma once

#include "AbstractMoon.h"

class Moon : public AbstractMoon
{
private:
    int minValue;
    int maxValue;
    float baseSurvival;

public:
    Moon(std::string name, int minValue, int maxValue, float baseSurvival)
    : AbstractMoon(name) {
        this->minValue = minValue;
        this->maxValue = maxValue;
        this->baseSurvival = baseSurvival;
    }

    int getMinValue() const { return minValue; }
    int getMaxValue() const { return maxValue; }
    float getBaseSurvival() const { return baseSurvival; }
};