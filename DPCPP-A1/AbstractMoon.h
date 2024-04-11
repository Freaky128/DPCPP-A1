#pragma once

#include <string>

class Game;

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

protected:
    MoonWeather weather = MoonWeather::Clear;

public:
    AbstractMoon(std::string name) { this->moonName = name; }

    const std::string& name() const { return moonName; }
    virtual void onDayBegin(Game& g) { return; }
    virtual void landingMessage() = 0;
    virtual void sendEmployees(Game& g, int count) = 0;
    
    std::string getWeather() {
        int i = static_cast<int>(weather);
        switch (i) {
        case 0:
            return ""; // could do a default case instead
        case 1:
            return "Flooded";
        case 2:
            return "Eclisped";
        case 3:
            return "Stormy";
        }
    }
};