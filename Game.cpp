#include <iostream>
#include "UserInterface.h"
#include "Game.h"
#include "Store.h"
#include "Inventory.h"
#include "Recipe.h"
#include "Day.h"

using namespace std;

Game::Game()
{

}

void Game::runGame()
{
	userInterface.gameSetup();
	userChoice();
}

bool Game::userChoice()
{
	char choice;
	
	cout << "" << endl;
	cout << "What would you like to do?\nA. Go to the Store?\nB. See weeks forcast?\nC. Change recipe?\nD. Open lemonade stand\n" << endl;
	cin >> choice;
	if (choice == 'A')
	{
		goToStore();
	}
	else if (choice == 'B')
	{
		seeForcast();
	}
	else if (choice == 'C')
	{
		changeRecipe();
	}
	else if (choice == 'D')
	{
		MoreChoices();
		openStand();
	}
	else
	{
		cout << "That is not a vaild option, try again" << endl;
		userChoice();
	}
	

	return choice;
}

char Game::goToStore()
{
	Store store;
	char choice;
	cout << "" << endl;
	cout << "Welcome to the store " << endl;
	cout << "What do you need to pick up today?" << endl;
	cout << "\nA: Lemon - cost 0.25 per Lemon\nB: Sugar Cube - cost 0.10 per Sugar Cube\nC: Ice Cube - cost 0.01 per Ice Cube\nD: Cup - cost 0.05 per Cup\nE: Back to Main Menu\n";
	cin >> choice;
	if (choice == 'A')
	{
		
		cout << "You want to buy some lemons" << endl;
		store.numberItemsToPurchase();
		store.stillBuying();
		
	}
	else if (choice == 'B')
	{
		cout << "You want to buy some sugar cubes" << endl;
		store.numberItemsToPurchase();
		store.stillBuying();
	}
	else if (choice == 'C')
	{
		cout << "You want to buy some ice cubes" << endl;
		store.numberItemsToPurchase();
		store.stillBuying();
	}
	else if (choice == 'D')
	{
		cout << "You want to buy some cups" << endl;
		store.numberItemsToPurchase();
		store.stillBuying();
	}
	else if (choice == 'E')
	{
		userInterface.startOfDay();
		userChoice();
	}
	else
	{
		cout << "Please make another selection" << endl;
		goToStore();
	}

	return choice;
}

char Game::seeForcast()
{
	Day day;
	char choice;
	cout << "" << endl;
	cout << "this is the forcast for the week" << endl;
	cout << "many varables coming up this week!! Better monitor the chart carefully to best prepare to make maximum profit :D" << endl;
	cout << "" << endl;
	cout << "Sunday forecast: " << day.weatherTemp() << endl;
	cout << "Monday forecast: " << day.weatherTemp() << endl;
	cout << "Tuesday forecast: " << day.weatherTemp() << endl;
	cout << "Wednesday forecast: " << day.weatherTemp() << endl;
	cout << "Thursday forecast: " << day.weatherTemp() << endl;
	cout << "Friday forcast: " << day.weatherTemp() << endl;
	cout << "Saturday forecast: " << day.weatherTemp() <<  endl;
	cout << "" << endl;
	cout << "Would you like to go back to main menu? Yes(Y) or No(N)" << endl;
	cin >> choice;
	if (choice == 'Y')
	{
		userChoice();
	}
	else
	{
		seeForcast();
	}
	return choice;
}

char Game::changeRecipe()
{
	Recipe recipe;
	UserInterface userInterface;
	char choice;
	cout << "" << endl;
	cout << "Here is where we can change our recipe to work with the up coming weather" << endl;
	recipe.priceOfCup();
	recipe.changeLemonCount();
	recipe.changeSugarCount();
	recipe.changeIceCount();
	cout << "" << endl;
	cout << "Are you done changing your recipe? Yes(Y) or No(N)" << endl;
	cout << "" << endl;
	cin >> choice;
	if (choice == 'Y')
	{
		userChoice();
	}
	else
	{
		changeRecipe();
	}
	return choice;
}

void Game::openStand()
{
	cout << "" << endl;
	cout << "Here game play of the lemonade stand opening will comence?" << endl;
}

bool Game::MoreChoices()
{
	char choice;
	cout << "If you start your day, you cannot come back here until the follow day, is this okay with you? Yes(Y) or No(N)" << endl;
	cin >> choice;
	if (choice == 'Y')
	{
		return false;
	}
	else if (choice == 'N')
	{
		userChoice();
		return true;
	}
	return choice;
}