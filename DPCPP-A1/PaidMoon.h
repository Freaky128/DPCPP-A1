#pragma once

#include "Moon.h"

#include <iostream>

class Game;

class PaidMoon : public Moon
{
private:
    int price;

public:
    PaidMoon(std::string name, int minValue, int maxValue, float baseSurvival, int price);
    bool onNavigate(Game& g);
    void print() const;
};