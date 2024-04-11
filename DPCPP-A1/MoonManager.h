#pragma once

#include "AbstractMoon.h"
#include <vector>
#include <memory>
#include <iostream>

class Game;

class MoonManager 
{
private:
    std::vector<std::shared_ptr<AbstractMoon> > moons;

public:
    void registerMoon(AbstractMoon* moon);
    std::shared_ptr<AbstractMoon> getStartingMoon();
    void displayMoons(int& balance);
    void onDayBegin(Game& g);
};