#include <iostream>
#include <string>
#include "UserInterface.h"
#include "Game.h"
#include "Store.h"
#include "Inventory.h"
#include "Recipe.h"

using namespace std;

Recipe::Recipe()
{

}

double Recipe::priceOfCup()
{
	double choice = pricePerCup;
	cout << "" << endl;
	cout << "How much would you like your cup of lemonade to cost?" << endl;
	cin >> choice;
	return choice;
}

int Recipe::changeLemonCount()
{
	int choice = recipeCallsLemon;
	cout << "How many lemons do you want in your recipe?" << endl;
	cin >> choice;
	return choice;
}

int Recipe::changeSugarCount()
{
	int choice = recipeCallsSugar;
	cout << "How many sugar cubes do you want in your recipe?" << endl;
	cin >> choice;
	return choice;
}

int Recipe::changeIceCount()
{
	int choice = recipeCallsIce;
	cout << "How many ice cubes do you want in your recipe?" << endl;
	cin >> choice;
	return choice;
}