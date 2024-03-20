#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include "UserInterface.h"
#include "Game.h"
#include "Store.h"
#include "Inventory.h"
#include "Recipe.h"
#include "Day.h"
#include "Weather.h"

using namespace std;

Weather::Weather()
{

}

void Weather::Hazy()
{
	
	cout << "Hazy" << endl;
}

void Weather::Foggy()
{
	cout << "Foggy" << endl;
}

void Weather::Rainy()
{
	cout << "Rainy" << endl;
}

void Weather::Sunny()
{
	cout << "Sunny" << endl;
}

void Weather::Windy()
{
	cout << "Windy" << endl;
}