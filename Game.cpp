#include <iostream>
#include "UserInterface.h"
#include "Game.h"
#include "Store.h"
#include "Inventory.h"

using namespace std;

Game::Game()
{

}

void Game::runGame()
{
	
	userInterface.gameSetup();
	userChoice();
	goToStore();
	// seeForcast();
	
}

char Game::userChoice()
{
	char choice;
	// int choice = userChoice();
	
	cout << "" << endl;
	cout << "What would you like to do?\nA. Go to the Store?\nB. See weeks forcast?\nC. Change recipe?\nD. Open lemonade stand\n" << endl;
	cin >> choice;

	return choice;
}

int Game::goToStore()
{
	int choice;
	cout << "Welcome to the store " << endl;
	cout << "What do you need to pick up today?" << endl;
	cout << "\n1: Lemon - cost 0.25 per Lemon\n2: Sugar Cube - cost 0.10 per Sugar Cube\n3: Ice Cube - cost 0.01 per Ice Cube\n4: Cup - cost 0.05 per Cup\n5: Back to Main Menu\n";
	cin >> choice;

	return choice;
}

void Game::seeForcast()
{
	cout << "this is the forcast for the week" << endl;
}