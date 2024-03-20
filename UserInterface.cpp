#include <iostream>
#include <string>
#include "UserInterface.h"
#include "Store.h"
#include "Inventory.h"
#include "Recipe.h"
#include "Day.h"
#include "Weather.h"

using namespace std;

UserInterface::UserInterface()
{

}

void UserInterface::instructions()
{
	// perhaps add << flush; to get instructions to clear eventually? 
	cout << "***********************************************************************************************************" << endl;
	cout << "Hello and Welcome" << endl << flush;
	cout << "" << endl << flush;
	cout << "Here we are going to be running our own lemonade stand, how exciting!!" << endl << flush;
	cout << "" << endl << flush;
	cout << "Here is a rundown of the game" << endl << flush;
	cout << "" << endl;
	cout << "You will start each day seeing what is in your inventory, then you will decide if you want to go to the store or not" << endl << flush;
	cout << "Once you return from the store you will then decide if you wish to change your recipe or prices for the day" << endl << flush;
	cout << "When the day starts customers will begin to decide if they would like to purchase from you or not" << endl << flush;

	cout << "" << endl << flush;
	cout << "Keep in mind that the weather, the prices you set, and your recipe all super megaly affect the customers choice to buy!" << endl << flush;
	cout << "Also keep in mind the forcast at the start of each day, when making your purchaeses and changing your recipe" << endl << flush;
	cout << "" << endl << flush;
	cout << "" << endl << flush;
	cout << "***********************************************************************************************************" << endl;
}

void UserInterface::gameSetup()
{
	instructions();
	startOfDay();
}

void UserInterface::startOfDay()
{
	// player and days
	userDisplay();
	cout << "" << endl;
	//player
	costDisplay();
	cout << "" << endl;	
	// player
	recipeDisplay();
	cout << "" << endl;
	// player
	inventoryDisplay();
}

void UserInterface::costDisplay()
{
	double pricePerCup;
	Recipe recipe;
	cout << "" << endl;
	cout << "Current cost per cup: $ " << recipe.pricePerCup << endl;
	cout << "" << endl;
}

void UserInterface::userDisplay()
{
	// potentially get user name and have displayed in 'welcome' phrase
	cout << "Welcome to Your Lemonand Stand!" << endl;
	cout << "" << endl;
	cout << "No better day than today to pursue your dreams! " << endl;
}

void UserInterface::inventoryDisplay()
{
	Inventory inventory;

	// where items in user current inventory are shown
	cout << "You currently have " << endl;
	cout << "$:  " << endl;
	cout << "Lemons: " << inventory.lemonCount << endl;
	cout << "Sugar Cubes: " << inventory.sugarCubeCount << endl;
	cout << "Ice Cubes: " << inventory.iceCubeCount << endl;
	cout << "Cups: " << inventory.cupCount << endl;
}

void UserInterface::recipeDisplay()
{
	Recipe recipe;

	cout << "Your recipe calls for: "  << endl;
	cout << "Lemons: " << recipe.recipeCallsLemon << endl;
	cout << "Sugar Cubes: " << recipe.recipeCallsSugar << endl;
	cout << "Ice Cubes: " << recipe.recipeCallsIce << endl;
}



