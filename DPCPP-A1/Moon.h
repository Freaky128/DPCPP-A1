#ifndef MOON_H
#define MOON_H

#include "AbstractMoon.h"

#include <iostream>
#include<random>

class Game;

class Moon : public AbstractMoon
{
public:
    Moon(std::string nName, int minValue, int maxValue, float nBaseSurvival);

    void onDayBegin(Game &g);
    void landingMessage() const;
    void sendEmployees(Game &g, int count);
    void sellCargo(Game &g, int amount);

    /*~Moon() {
        std::cout << "deleted moon" << std::endl;
    }*/

private:
    int minLootValue;
    int maxLootValue;
    float baseSurvival;

    const float weatherMatrix[4][3] = { 1,    1,   1, // matirx of weather effect multipliers
                                  1,    0.7, 1,
                                  0.75, 1,   1,
                                  1,    0.9, 0.7 };

};

#endif //MOON_H