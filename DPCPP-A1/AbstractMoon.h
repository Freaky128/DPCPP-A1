#ifndef ABSTRACTMOON_H
#define ABSTRACTMOON_H

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
public:
    AbstractMoon(std::string name) : moonName(name) {}

    const std::string& name() const { return moonName; }
    virtual void onDayBegin(Game& g) { return; }
    virtual void landingMessage() const = 0;
    virtual void sendEmployees(Game& g, int count) = 0;
    virtual void sellCargo(Game& g, int amount) = 0;
    virtual bool onNavigate(Game& g) const { return true; }
    virtual void print() const { std::cout << std::endl; }

    std::string getWeather() const {
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

    /*virtual ~AbstractMoon() {
        std::cout << "AbstractMoon destructor" << std::endl;
    }*/

protected:
    MoonWeather weather = MoonWeather::Clear;

private:
    std::string moonName;

};

#endif //ABSTRACTMOON_H