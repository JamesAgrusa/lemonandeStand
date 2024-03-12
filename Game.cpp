#include <iostream>
#include "Game.h"
#include "UserInterface.h"
#include "Player.h"
#include "Store.h"
#include "Inventory.h"
#include "Lemon.h"

using namespace std;

Game::Game()
{

}

void Game::runGame()
{
	userInterface userInterface;

	userInterface.gameSetUp();
	userChoices();
}

bool Game::userChoices()
{
	int choice;
	Player player;
	
	
	cout << "What would you like to do?\n1. Go to the Store?\n2. See weeks forcast?\n3. Change recipe?\n4. Open lemonade stand\n" << endl;
	cin >> choice;

	switch (choice)
	{
	case 1:
		player.goToTheStore();
		// go to the store
		break;

	case 2:
		// see the forcast
		break;

	case 3:
		// change the recipe
		break;

	case 4:
		// open the stand
		break;
		
	}

	bool continueUserChoices; // = ContinueUserChoices();

	return continueUserChoices;
}