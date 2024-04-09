#include <iostream>
#include <string>
#include "Game.h"
#include "UserInterface.h"
#include "Player.h"
#include "Weather.h"
#include "Store.h"

using namespace std;

Game::Game()
{

}

void Game::startGame() // intro to the game. start screen, and instuctions, into running the game. 
{
	UserInterface userinterface;
	userinterface.startScreen();
	userinterface.instructions();
	runGame();
}

void Game::dayCount() // the game runs through the simulation (7) days in a loop. Displays Day 1 - 7 and start of new day
{
	Weather weather;
	Player player;
	for (int day = 1; day <= 7; day++)
	{
		bool continueUserChoice = true;

		cout << "\nDay " << day << ":\n";
		weather.seeForcast();
		player.showInventory(); // after show inventory maybe get a function that will display a list of things to pick from to do. ie; change recipe, go to store, then start stand. 
		player.changeRecipe();
		do 
		{
			continueUserChoice = userChoice();
		} while (continueUserChoice = true);
		// here make a function that runs the rest of the game after doing the shopping loop!
		
	}
}

void Game::runGame()
{
	UserInterface userinterface;

	userinterface.startOfDayDisplay();
}

bool Game::userChoice()
{
	Player player;
	char choice;
	cout << "What would you like to do?\nA) go to store\nB) open stand\n";
	cin >> choice;
	if (choice == 'A')
	{
		cout << "Welcome to the store" << endl;

	}
	else if (choice == 'B')
	{
		cout << "Welcome to the Stand" << endl;
	}
	else
	{
		userChoice();
	}
	return choice;
}

