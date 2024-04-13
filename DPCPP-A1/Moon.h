#pragma once

#include "AbstractMoon.h"

#include <iostream>
#include<random>

class Game;

class Moon : public AbstractMoon
{
private:
    int minValue;
    int maxValue;
    float baseSurvival;

    const float weatherMatrix[4][3] = { 1,    1,   1,
                                  1,    0.7, 1,
                                  0.75, 1,   1,
                                  1,    0.9, 0.7 };

public:
    Moon(std::string name, int minValue, int maxValue, float baseSurvival);

    int getMinValue() const { return minValue; }
    int getMaxValue() const { return maxValue; }
    float getBaseSurvival() const { return baseSurvival; }

    void onDayBegin(Game& g);
    void landingMessage() const;
    void sendEmployees(Game& g, int count);
    void sellCargo(Game& g, int amount);

    /*~Moon() {
        std::cout << "deleted moon" << std::endl;
    }*/
};