#ifndef PAIDMOON_H
#define PAIDMOON_H

#include "Moon.h"

#include <iostream>

class Game;

class PaidMoon : public Moon
{
public:
    PaidMoon(std::string nName, int minValue, int maxValue, float nBaseSurvival, int nPrice);
    bool onNavigate(Game &g) const;
    void print() const;

private:
    int price;

};

#endif PAIDMOON_H