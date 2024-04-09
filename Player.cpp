#include <iostream>
#include <string>
#include "Game.h"
#include "UserInterface.h"
#include "Player.h"
#include "Weather.h"
#include "Store.h"

using namespace std;

Player::Player() : lemons(0), sugar(0), ice(0), cups(0) // pricePerCup(1.0), money(50.0) {}
{

}

void Player::showInventory()
{
    cout << "Inventory: " << endl;
    cout << "Lemons: " << lemons << endl;
    cout << "Sugar: " << sugar << endl;
    cout << "Ice: " << ice << endl;
    cout << "Cups: " << cups << endl;
}

int Player::changeLemonCount()
{

    int choice = recipeCallsLemon;
    cout << "How many lemons do you want in your recipe: ";
    cin >> choice;
    return choice;
}

int Player::changeSugarCount()
{

    int choice = recipeCallsSugar;
    cout << "How many sugar cubes do you want in your recipe: ";
    cin >> choice;
    return choice;
}

int Player::changeIceCount()
{

    int choice = recipeCallsIce;
    cout << "How many ice cubes do you want in your recipe: ";
    cin >> choice;
    return choice;
}

void Player::changeRecipe()
{
    changeLemonCount();
    changeSugarCount();
    changeIceCount();
}
