#pragma once

#include <iostream>
#include <string>

class Game;

enum class MoonWeather { 
    Clear = 0,
    Flooded,
    Stormy,
    Eclipsed
};

class AbstractMoon 
{
private:
    std::string moonName;

protected:
    MoonWeather weather = MoonWeather::Clear;

public:
    AbstractMoon(std::string name) { this->moonName = name; }

    const std::string& name() const { return moonName; }
    virtual void onDayBegin(Game& g) { return; }
    virtual void landingMessage() = 0;
    virtual void sendEmployees(Game& g, int count) = 0;
    virtual void sellCargo(Game& g, int amount) = 0;

    
    std::string getWeather() {
        int i = static_cast<int>(weather);
        switch (i) {
        case 1:
            return "Flooded";
        case 2:
            return "Stormy";
        case 3:
            return "Eclisped";
        default:
            return "";
        }
    }

    virtual ~AbstractMoon() {
        //std::cout << "AbstractMoon destructor" << std::endl;
    }
};