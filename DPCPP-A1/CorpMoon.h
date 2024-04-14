#ifndef CORPMOON_H
#define CORPMOON_H

#include "AbstractMoon.h"

#include <iostream>

class Game;

class CorpMoon : public AbstractMoon
{
public:
    CorpMoon(std::string name) : AbstractMoon(name) {}
    void landingMessage() const;
    void sendEmployees(Game &g, int count);
    void sellCargo(Game &g, int amount);
};

#endif //CORPMOON_H