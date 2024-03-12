#include <iostream>
#include <cmath>
#include <ctime>
#include <string>
#include "UserInterface.h"
#include "Game.h"
#include "Player.h"
#include "Store.h"
#include "Inventory.h"
#include "Lemon.h"

using namespace std;

userInterface::userInterface()
{

}

void userInterface::instructions()
{
	// perhaps add << flush; to get instructions to clear eventually? 
	cout << "Hello and Welcome" << endl<<flush;
	cout << "" << endl<<flush;
	cout << "Here we are going to be running our own lemonade stand, how exciting!!" << endl<<flush;
	cout << "" << endl<<flush;
	cout << "Here is a rundown of the game :" << endl<<flush;	
	cout << "You will start each day seeing what is in your inventory, then you will decide if you want to go to the store or not" << endl<<flush;
	cout << "Once you return from the store you will then decide if you wish to change your recipe or prices for the day" << endl<<flush;
	cout << "When the day starts customers will begin to decide if they would like to purchase from you or not" << endl<<flush;

	cout << "" << endl<<flush;
	cout << "Keep in mind that the weather, the prices you set, and your recipe all super megaly affect the customers choice to buy!" << endl<<flush;
	cout << "Also keep in mind the forcast at the start of each day, when making your purchaes and changing your recipe" << endl<<flush;
	cout << "" << endl<< flush;
	cout << "" << endl<<flush;
	cout << "***********************************************************************************************************" << endl;
}

void userInterface::gameSetUp()
{
	instructions();
	startDayDisplay();
}

void userInterface::startDayDisplay()
{
	// player and days
	userDisplay();
	cout << "" << endl;
	//player
	costDisplay();
	cout << "" << endl;
	// player
	inventoryDisplay();
	cout << "" << endl;
	// player
	recipeDisplay();
	

}

void userInterface::userDisplay()
{
	// potentially get user name and have displayed in 'welcome' phrase
	cout << "Welcome to Your Lemonand Stand!" << endl;
	cout << "Todays forcast is: " << endl;
}

void userInterface::inventoryDisplay()
{
	// where items in user current inventory is shown

	cout << "You currently have " << endl;
	cout << "$:  " << endl;
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
	cout << "" << endl;
}

void userInterface::costDisplay()
{
	cout << "Current cost per cup: " << endl;
}

int userInterface::GetRandomInteger(int min, int max)
{
	int min = 1;
	int max = 100;
	srand(unsigned(time(0)));
	int randInteger = rand() % min + max;
	return randInteger;
}

int userInterface::GetUserInteger(string output)
{
	int output;
	int result;

	cout << output << endl;
	cin >> output;

	output = result;

	return result;
}