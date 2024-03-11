#include <iostream>
#include "userInterface.h"

using namespace std;

userInterface::userInterface()
{

}

void userInterface::instructions()
{
	cout << "Hello and Welcome" << endl;
	cout << "" << endl;
	cout << "Here we are going to be running our own lemonade stand, how exciting!!" << endl;
	cout << "Here is a rundown of the game :" << endl;
	cout << "" << endl;
	cout << "You will start each day seeing what is in your inventory, then you will decide if you want to go to the store or not" << endl;
	cout << "Once you return from the store you will then decide if you wish to change your recipe or prices for the day" << endl;
	cout << "When the day starts customers will begin to decide if they would like to purchase from you or not" << endl;

	cout << "" << endl;
	cout << "Keep in mind that the weather, the prices you set, and your recipe all super megaly affect the customers choice to buy!" << endl;
	cout << "Also keep in mind the forcast at the start of each day, when making your purchaes and changing your recipe" << endl;
	cout << "" << endl;
	cout << "" << endl;
}

void userInterface::gameSetUp()
{
	instructions();
	begginingDayDisplay();
}

void userInterface::begginingDayDisplay()
{
	userDisplay();
	cout << "" << endl;
	inventoryDisplay();
	cout << "" << endl;
	recipeDisplay();

}

void userInterface::userDisplay()
{
	cout << "Welcome to Your Lemonand Stand!" << endl;
	cout << "Todays forcast is: " << endl;
}

void userInterface::inventoryDisplay()
{
	// where items in user current inventory is shown

	cout << "You currently have: $ " << endl;
	cout << "Lemons: " << endl;
	cout << "Sugar Cubes: " << endl;
	cout << "Ice Cubes: " << endl;
	cout << "Cups: " << endl;
}

void userInterface::recipeDisplay()
{
	cout << "Your current recipe calls for: " << endl;
	cout << "Lemons: " << endl;
	cout << "Sugar Cubes: " << endl;
	cout << "Ice Cubes: " << endl;
}