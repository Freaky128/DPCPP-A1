#include "CorpMoon.h"

void CorpMoon::landingMessage()
{
    std::cout << "\nType SELL to sell your cargo contents and increase your balance and achieve quota. Specify the amount to sell after the SELL word to only sell a portion of your cargo." << std::endl;
    std::cout << "Type LEAVE to leave the planet.\n" << std::endl;
}

void CorpMoon::sendEmployees(Game& g, int count)
{
    std::cout << "\nThis command is not available on this moon.\n" << std::endl;
}
