#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include "UserInterface.h"
#include "Game.h"
#include "Store.h"
#include "Inventory.h"
#include "Recipe.h"
#include "Day.h"

using namespace std;

Day::Day()
{

}

int Day::weatherTemp()
{
	srand(unsigned(time(0)));
	int temperature = rand() % 30 + 100;
	return temperature;
}