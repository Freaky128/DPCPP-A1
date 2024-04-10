#pragma once

#include "AbstractMoon.h"
#include <vector>
#include <memory>
#include <iostream>

class MoonManager 
{
private:
    std::vector<std::unique_ptr<AbstractMoon> > moons;

public:
    void registerMoon(AbstractMoon* moon);
};