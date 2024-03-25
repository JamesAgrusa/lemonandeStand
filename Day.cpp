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
	// int min = 0;
	// int max = 100;
	int temperature = rand() % 90;
	return temperature;
}

char Day::weatherType()
{
	Weather weather;
	UserInterface userInterface;
	char RandomCondition;
	char randomCondition[] = { 'H', 'S', 'C', 'W', 'R'};
	
	srand(unsigned(time(0)));
	RandomCondition = randomCondition[rand() % 5];
	// make a list here for the weather to be randomly selected. 

	// char RandomCondition = userInterface.getRandomInt();

	switch (RandomCondition)
	{
	case 1:
		weather.Rainy();
		break;
	case 2:
		weather.Foggy();
		break;
	case 3:
		weather.Hazy();
		break;
	case 4:
		weather.Sunny();
		break;
	case 5:
		weather.Windy();
		break;
	}
	

	return RandomCondition;
}