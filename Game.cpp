#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include "UserInterface.h"
#include "Game.h"
#include "Store.h"
#include "Inventory.h"
#include "Recipe.h"
#include "Day.h"
#include "Weather.h"

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

float Game::goToStore()
{
	Store store;
	Inventory inventory;
	UserInterface userInterface;

	float userchoice;
	double wallet = 20;

	cout << "" << endl;
	while (wallet >= 0)
	{
		cout << "Welcome to the store" << endl;
		cout << "Menu: " << endl;
		cout << "1    Lemons        $0.25" << endl;
		cout << "2    Sugar Cubes   $0.10" << endl;
		cout << "3    Ice Cubes     $0.01" << endl;
		cout << "4    Cups          $0.05" << endl;

		cout << "\nYou have currently: \n" << "\nlemons: \n" << store.lemons << "\nsugarcubes: \n" << store.sugarcubes << "\nicecubes: \n" << store.icecubes << "\ncups: \n" << store.cups << endl;
		cout << "" << endl;
		cout << "your available credit is $: " << wallet << endl;
		cout << "" << endl;
		cout << "Type in the number that represents the item you want or type 5 to check out" << endl;
		cin >> userchoice;

		if (userchoice == 1)
		{
			// do i add a for loop inside here to get a typed amount insteaded off adding each one individually?
			// also how do i get this info to store and show up on userinterface display?
			// youre getting there James dont give up
			// maybe add a CART system to where everything is store in a CART list/vector or INVENTORY list/vector
			// closer than you were yesterday!!
			int userchoice;
			cout << "How many lemons: " << endl;
			cin >> userchoice;
			for (int i = 0; i >= userchoice; i++)
			{
				store.lemons++;
				wallet = wallet - 0.25;
			}
			// for (int i = static_cast<int>(list->GetCount()) - 1; i >= 0; i--)
			// return userchoice;
		}
		else if (userchoice == 2)
		{
			store.sugarcubes++;
			wallet = wallet - 0.10;
			
			// store.stillBuying();
		}
		else if (userchoice == 3)
		{
			store.icecubes++;
			wallet = wallet - 0.01;
			
			// store.stillBuying();
		}
		else if (userchoice == 4)
		{
			store.cups++;
			wallet = wallet - 0.05;
			
			// store.stillBuying();

		}
		else if (userchoice == 5)
		{
			cout << "thankyou for shopping" << endl;
			cout << "" << endl;
			cout << "your total balance left is: " << wallet << endl;
			cin.get();
			store.stillBuying();	
			
		}
		else
		{
			userInterface.startOfDay();
		}
	}
	
	cin.get();
	return userchoice;
	
}

char Game::seeForcast()
{
	Day day;
	char choice;

	cout << "" << endl;
	cout << "this is the forcast for the week" << endl;
	cout << "many varables coming up this week!! Better monitor the chart carefully to best prepare to make maximum profit :D" << endl;
	cout << "" << endl;
	cout << "H: Hazy\nS: Sunny\nC: Cloudy\nR: Rainy\nW: Windy\n";
	cout << "" << endl;
	
	for (int i = 0; i < day.numberOfDays; i++)
	{
		cout << "Day " << i + 1 << " temperature of: " << day.weatherTemp() << " and " << day.weatherType() << endl;

	}

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