#ifndef MOONMANAGER_H
#define MOONMANAGER_H

#include "AbstractMoon.h"
#include <vector>
#include <memory>
#include <iostream>

class Game;

class MoonManager 
{
public:
    void registerMoon(AbstractMoon *moon);
    std::shared_ptr<AbstractMoon> getStartingMoon() const;
    void displayMoons(int &balance);
    void onDayBegin(Game &g);
    void route(std::vector<std::string> args, Game &g);

private:
    std::vector<std::shared_ptr<AbstractMoon> > moons;

};

#endif //MOONMANAGER_H