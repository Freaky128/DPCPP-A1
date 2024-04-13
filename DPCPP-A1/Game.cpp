#include "Game.h"

Game::Game() {
    myGenerator.seed(std::random_device{}());

    itemManager.registerItem(new Item("Flashlight", 60, 1, 1.05, 1, 0, 1)); // TODO: could change this to a csv reader for better dynamacy if get time
    itemManager.registerItem(new Item("Shovel", 100, 1, 1.05, 1, 0, 1));
    itemManager.registerItem(new Item("Pro-flashlight", 200, 1, 1.10, 1, 0, 1));
    itemManager.registerItem(new Item("Teleporter", 300, 1, 1, 1, 0.33, 1));
    itemManager.registerItem(new Item("Inverse-teleporter", 400, 1.10, 0.8, 1, 0, 1));
    itemManager.registerItem(new Item("Backpack", 500, 1, 1, 1, 0, 1.25));
    itemManager.registerItem(new Item("Hydraulics-Mk2", 1000, 1, 1, 1.25, 0, 1));

    moonManager.registerMoon(new CorpMoon("Corporation"));
    moonManager.registerMoon(new Moon("Prototyping", 3, 30, 0.5));
    moonManager.registerMoon(new Moon("Insurance", 5, 50, 0.45));
    moonManager.registerMoon(new Moon("Pledge", 30, 50, 0.40));
    moonManager.registerMoon(new Moon("Defence", 10, 70, 0.35));
    moonManager.registerMoon(new PaidMoon("April", 20, 120, 0.30, 550));
    moonManager.registerMoon(new PaidMoon("Tore", 100, 130, 0.25, 700));
    moonManager.registerMoon(new PaidMoon("Hyperion", 100, 150, 0.20, 900));

    moon = moonManager.getStartingMoon();
}

void Game::run()
{
    std::cout << DEADLY_CORP_TITLE << std::endl;
    std::cout << "\nWelcome!\nWe trust you will be a great asset to the corporation!\n" << std::endl;

    while (isRunning) {
        moonManager.onDayBegin(*this);

        std::cout << "============= DAY " << dayNum << " =============" << std::endl;
        std::cout << "Current cargo value: $" << cargoBalance << std::endl;
        std::cout << "Current balance: $" << balance << std::endl;
        std::cout << "Current quota: $" << quota << " (" << (3 - (dayNum - 1) % 4) % 4 << " days left to meet quota)" << std::endl;
        std::cout << "Currently orbiting: " << moon->name() << "\n" << std::endl;

        std::cout << ">MOONS\nTo see the list of moons the autopilot can route to.\n" << std::endl;
        std::cout << ">STORE\nTo see the company store's selection of useful items.\n" << std::endl;
        std::cout << ">INVENTORY\nTo see the list of items you've already bought.\n" << std::endl;

        if ((3 - (dayNum - 1) % 4) % 4 == 0) {
            std::cout << "NOTE: 0 days left to meet quota. Type \"route corporation\" to go to the corp's moon and sell the scrap you collected for cash.\n" << std::endl;
        }

        isSameDay = true;

        while (isSameDay) {
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
                    if (args.empty() || args.size() > 1) {
                        std::cout << "\nBad command; the syntax is: \"send numberOfEmployees\" \n" << std::endl;
                    }
                    else if (util::parsePositiveInt(args[0]) == -1) {
                        std::cout << "\nInvalid employee count \"" << args[0] << "\"\n" << std::endl;
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
                if (isLanded) {
                    if (args.size() > 1) {
                        std::cout << "\nBad command; the syntax is: \"sell optionalAmount\" \n" << std::endl;
                    }
                    else if (args.empty()) {
                        moon->sellCargo(*this, -1);
                    }
                    else if (util::parsePositiveInt(args[0]) == -1) {
                        std::cout << "\nInvalid amount \"" << args[0] << "\"\n" << std::endl;
                    }
                    else {
                        moon->sellCargo(*this, util::parsePositiveInt(args[0]));
                    }                    
                }
                else {
                    std::cout << "\nThis command is not available at this time.\n" << std::endl;
                }
            }
            else if (command == "leave") {
                if (isLanded) {
                    leave();
                }
                else {
                    std::cout << "\nThis command is not available at this time.\n" << std::endl;
                }
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
                gameExit();
            }
            else {
                std::cout << "\nUnknown command.\n" << std::endl;
            }

        }

        if ((3 - (dayNum - 1) % 4) % 4 == 0) {
            if (balance >= quota) {
                quota = quota * 1.5;
                std::cout << "-------------------------------------" << std::endl;
                std::cout << "CONGRATULATIONS ON MAKING QUOTA!\nNew quota: $" << quota << std::endl;
                std::cout << "-------------------------------------\n\n" << std::endl;
            }
            else {
                std::cout << "-------------------------------------" << std::endl;
                std::cout << ">>>>>>>>>>>>> GAME OVER <<<<<<<<<<<<<" << std::endl;
                std::cout << "-------------------------------------\n" << std::endl;
                std::cout << "You did not meet quota in time, and your employees have been fired." << std::endl;
                std::cout << "You kept them alive for " << dayNum << " days.\n" << std::endl;
                system("pause");
                gameExit();
            }
        }

        dayNum += 1;
        employees = 4;
    }

    return;
}

void Game::land()
{
    isLanded = true;
    std::cout << "\n\nWELCOME TO " << moon->name() << "!\n" << std::endl;
    std::cout << "Current cargo value: $" << cargoBalance << std::endl; // could/should encapsulate these in a function
    std::cout << "Current balance: $" << balance << std::endl;
    std::cout << "Current quota: $" << quota << " (" << (3 - (dayNum - 1) % 4) % 4 << " days left to meet quota)" << std::endl;
    std::cout << "Number of employees: " << employees << std::endl;

    moon->landingMessage();
}

void Game::leave()
{
    isLanded = false;
    isSameDay = false;
    std::cout << "\n\n" << std::endl;
}

void Game::gameExit()
{
    //no memory cleaning needed as the only dynamically allocated memory uses smart pointers.
    isSameDay = false; // could just call exit(0); as that would return all allocated memory to the OS,
    isRunning = false; // however I decided to do it this way so the destructors of my dynamically allocated object will be called.
    dayNum = 1;
}

int Game::getQuota() const
{
    return quota;
}

int Game::getBalance() const
{
    return balance;
}

int Game::getCargoValue() const
{
    return cargoBalance;
}

int Game::getEmployees() const
{
    return employees;
}

const std::string Game::getMoonNameLower() const
{
    std::string name = moon->name();
    util::lower(name);
    return name;
}

const std::string Game::getMoonName() const
{
    return moon->name();
}

const std::vector<std::shared_ptr<Item> >& Game::getItems()
{
    return items;
}

void Game::setBalance(int value)
{
    balance += value;
}

void Game::setCargoBalance(int value)
{
    cargoBalance += value;
}

void Game::clearCargoBalance()
{
    cargoBalance = 0;
}

void Game::setEmployees(int value)
{
    employees = value;
}

void Game::setMoon(std::shared_ptr<AbstractMoon> moon)
{
    this->moon = moon;
}

void Game::addItem(std::shared_ptr<Item> item)
{
    items.push_back(item);
}