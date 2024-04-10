#pragma once

#include <string>

enum class MoonWeather { 
    Clear = 0,
    Flooded,
    Eclisped,
    Stormy 
};

class AbstractMoon 
{
private:
    std::string moonName;
    MoonWeather weather;

public:
    AbstractMoon(std::string name) {
        this->moonName = name;
    }

    const std::string& name() const { return moonName; }

};