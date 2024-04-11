#pragma once

#include "AbstractMoon.h"

#include <iostream>

class CorpMoon : public AbstractMoon
{
public:
    CorpMoon(std::string name) : AbstractMoon(name) {}
    void landingMessage();
    void sendEmployees(Game& g, int count);
};