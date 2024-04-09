#include <iostream>
#include <string>
#include "Game.h"
#include "UserInterface.h"
#include "Player.h"
#include "Weather.h"
#include "Store.h"

using namespace std;

UserInterface::UserInterface()
{

}

void UserInterface::startScreen()
{
	cout << "Welcome to the Lemonade Stand" << endl;
}

void UserInterface::instructions()
{
	cout << "Here are the rules" << endl;
}

void UserInterface::startOfDayDisplay()
{
	Game game;
	game.dayCount();
}
