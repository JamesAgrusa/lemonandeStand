#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "Stand.h"
#include "UserInterface.h"
#include "Weather.h"
#include "Recipe.h"
#include "Customer.h"

using namespace std;

Recipe::Recipe()
{

}

void  Recipe::priceOfCup()
{
	Stand stand;
	
	cout << "How much would you like your cup of lemonade to cost?\n$ ";
	cin >> stand.pricePerCup;
	cout << "You new price per cup is: $" << stand.pricePerCup << "!" << endl;
}

int Recipe::changeLemonCount()
{
	
	int choice = recipeCallsLemon;
	cout << "" << endl;
	cout << "How many lemons do you want in your recipe: ";
	cin >> choice;
	return choice;
}

int Recipe::changeSugarCount()
{
	
	int choice = recipeCallsSugar;
	cout << "" << endl;
	cout << "How many sugar cubes do you want in your recipe: ";
	cin >> choice;
	return choice;
}

int Recipe::changeIceCount()
{
	
	int choice = recipeCallsIce;
	cout << "" << endl;
	cout << "How many ice cubes do you want in your recipe: ";
	cin >> choice;
	return choice;
}