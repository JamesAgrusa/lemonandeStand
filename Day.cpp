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
#include "Weather.h"

using namespace std;

Day::Day()
{

}

int Day::weatherTemp()
{
	srand(unsigned(time(0)));
	int temperature = rand() % 30 + 90;
	return temperature;
}

string Day::weatherType()
{
	Weather weather;
	string randomCondition[] = {"Hazy", "Foggy", "Rainy", "Sunny", "Windy"};
	srand(unsigned(time(0)));
	randomCondition[rand() % 5];
	// make a list here for the weather to be randomly selected. 
	

	// return randomCondition;
}