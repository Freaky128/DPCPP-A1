#include "Game.h"

Game::Game() {
    itemManager.registerItem(new Item("Flashlight", 60, 1, 1.05, 1, 0, 1)); // TODO: could change this to a csv reader for better dynamacy if get time
    itemManager.registerItem(new Item("Shovel", 100, 1, 1.05, 1, 0, 1)); // TODO: could also create a loop and pass pointers instead of objects
    itemManager.registerItem(new Item("Pro-flashlight", 200, 1, 1.10, 1, 0, 1));
    itemManager.registerItem(new Item("Teleporter", 300, 1, 1, 1, 0.33, 1));
    itemManager.registerItem(new Item("Inverse-teleporter", 400, 1.10, 0.8, 1, 0, 1));
    itemManager.registerItem(new Item("Backpack", 500, 1, 1, 1, 0, 1.25));
    itemManager.registerItem(new Item("Hydraulics Mk2", 1000, 1, 1, 1.25, 0, 1));

    //moonManager.registerMoon();
}

void Game::run()
{
    moonManager.registerMoon(new CorpMoon("Corporation"));
    moonManager.registerMoon(new Moon("Prototyping", 3, 30, 0.5));
    moonManager.registerMoon(new Moon("Insurance", 5, 50, 0.45));
    moonManager.registerMoon(new Moon("Pledge", 30, 50, 0.40));
    moonManager.registerMoon(new Moon("Defence", 10, 70, 0.35));

    return;
}
