#include "Game.h"

Game::Game() {
    myGenerator.seed(std::random_device{}());

    itemManager.registerItem(new Item("Flashlight", 60, 1, 1.05, 1, 0, 1)); // TODO: could change this to a csv reader for better dynamacy if get time
    itemManager.registerItem(new Item("Shovel", 100, 1, 1.05, 1, 0, 1));
    itemManager.registerItem(new Item("Pro-flashlight", 200, 1, 1.10, 1, 0, 1));
    itemManager.registerItem(new Item("Teleporter", 300, 1, 1, 1, 0.33, 1));
    itemManager.registerItem(new Item("Inverse-teleporter", 400, 1.10, 0.8, 1, 0, 1));
    itemManager.registerItem(new Item("Backpack", 500, 1, 1, 1, 0, 1.25));
    itemManager.registerItem(new Item("Hydraulics Mk2", 1000, 1, 1, 1.25, 0, 1));

    moonManager.registerMoon(new CorpMoon("Corporation"));
    moonManager.registerMoon(new Moon("Prototyping", 3, 30, 0.5));
    moonManager.registerMoon(new Moon("Insurance", 5, 50, 0.45));
    moonManager.registerMoon(new Moon("Pledge", 30, 50, 0.40));
    moonManager.registerMoon(new Moon("Defence", 10, 70, 0.35));

    moon = moonManager.getStartingMoon();
}

void Game::run()
{
    std::cout << DEADLY_CORP_TITLE << std::endl;
    std::cout << "\nWelcome!\nWe trust you will be a great asset to the corporation!" << std::endl;

    while (isRunning) {
        moonManager.onDayBegin(*this);

        std::cout << "\n============= DAY " << dayNum << " =============" << std::endl;
        std::cout << "Current cargo value: $" << cargoBalance << std::endl;
        std::cout << "Current balance: $" << balance << std::endl;
        std::cout << "Current quota: $" << quota << " (" << 4 - (dayNum % 4) << " days left to meet quota)" << std::endl;
        std::cout << "Currently orbiting: " << moon->name() << "\n" << std::endl;

        std::cout << ">MOONS\nTo see the list of moons the autopilot can route to.\n" << std::endl;
        std::cout << ">STORE\nTo see the company store's selection of useful items.\n" << std::endl;
        std::cout << ">INVENTORY\nTo see the list of items you've already bought.\n" << std::endl;

        while (true) {
            std::cout << ">";
            std::string command;
            std::vector<std::string> args;
            std::getline(std::cin, command);
            util::lower(command);
            util::splitArguments(command, args);

            if (command == "moons") {
                moonManager.displayMoons(balance);
            }
            else if (command == "route") {
                if (!isLanded) {
                    moonManager.route(args, *this);
                }
                else {
                    std::cout << "\nThis command is not available at this time.\n" << std::endl;
                }
            }
            else if (command == "land") {
                if (!isLanded) {
                    land();
                }
                else {
                    std::cout << "\nThis command is not available at this time.\n" << std::endl;
                }
            }
            else if (command == "send") {
                if (isLanded) {
                    if (args.empty() || args.size() > 1 || util::parsePositiveInt(args[0]) == -1) {
                        std::cout << "\nBad command; the syntax is: \"send numberOfEmployees\" \n" << std::endl;
                    }
                    else if (util::parsePositiveInt(args[0]) > employees) {
                        std::cout << "\nOnly " << employees << " employees are left.\n" << std::endl;
                    }
                    else {
                        moon->sendEmployees(*this, util::parsePositiveInt(args[0]));
                    }
                }
                else {
                    std::cout << "\nThis command is not available at this time.\n" << std::endl;
                }
            }
            else if (command == "sell") {

            }
            else if (command == "leave") {

            }
            else if (command == "store") {
                itemManager.displayItems(balance);
            }
            else if (command == "buy") {
                itemManager.buy(args, *this);
            }
            else if (command == "inventory") {
                itemManager.inventory(*this);
            }
            else if (command == "exit") {

            }
            else {
                std::cout << "\nUnknown command.\n" << std::endl;
            }

        }

        isRunning = false;
    }

    return;
}

std::string Game::getMoonNameLower() const
{
    std::string name = moon->name();
    util::lower(name);
    return name;
}

std::string Game::getMoonName() const
{
    return moon->name();
}

int Game::getBalance() const
{
    return balance;
}

int Game::getQuota() const
{
    return quota;
}

int Game::getCargoValue() const
{
    return cargoBalance;
}

std::vector<std::shared_ptr<Item> >& Game::getItems()
{
    return items;
}

void Game::setBalance(int value)
{
    balance += value;
}

void Game::addItem(std::shared_ptr<Item> item)
{
    items.push_back(item);
}

void Game::setMoon(std::shared_ptr<AbstractMoon> moon)
{
    this->moon = moon;
}

void Game::land()
{
    isLanded = true;
    std::cout << "\n\nWELCOME TO " << moon->name() << "!\n" << std::endl;
    std::cout << "Current cargo value: $" << cargoBalance << std::endl; // could/should encapsulate these in a function
    std::cout << "Current balance: $" << balance << std::endl;
    std::cout << "Current quota: $" << quota << " (" << 4 - (dayNum % 4) << " days left to meet quota)" << std::endl;
    std::cout << "Number of employees: " << employees << std::endl;

    moon->landingMessage();
}
