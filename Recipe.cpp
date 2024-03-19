#include <iostream>
#include <string>
#include "UserInterface.h"
#include "Game.h"
#include "Store.h"
#include "Inventory.h"
#include "Recipe.h"
#include "Day.h"

using namespace std;

Recipe::Recipe()
{

}

double Recipe::priceOfCup()
{
	double choice = pricePerCup;
	cout << "" << endl;
	cout << "How much would you like your cup of lemonade to cost?" << endl;
	cout << "" << endl;
	cin >> choice;
	
	return choice;
}

int Recipe::changeLemonCount()
{
	int choice = recipeCallsLemon;
	cout << "" << endl;
	cout << "How many lemons do you want in your recipe?" << endl;
	cin >> choice;
	return choice;
}

int Recipe::changeSugarCount()
{
	int choice = recipeCallsSugar;
	cout << "" << endl;
	cout << "How many sugar cubes do you want in your recipe?" << endl;
	cin >> choice;
	return choice;
}

int Recipe::changeIceCount()
{
	int choice = recipeCallsIce;
	cout << "" << endl;
	cout << "How many ice cubes do you want in your recipe?" << endl;
	cin >> choice;
	return choice;
}