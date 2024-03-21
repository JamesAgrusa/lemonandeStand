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
	int temperature = rand() % 90;
	return temperature;
}

char Day::weatherType()
{
	Weather weather;
	char RandomCondition;
	char randomCondition[] = { 'H', 'S', 'C', 'W', 'R'};
	
	srand(unsigned(time(0)));
	RandomCondition = randomCondition[rand() % 5];
	// make a list here for the weather to be randomly selected. 
	

	return RandomCondition;
}