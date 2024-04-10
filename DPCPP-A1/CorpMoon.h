#pragma once

#include "AbstractMoon.h"

class CorpMoon : public AbstractMoon
{
public:
    CorpMoon(std::string name) : AbstractMoon(name) {}
};