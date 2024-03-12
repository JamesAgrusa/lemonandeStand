#include <iostream>
#include "UserInterface.h"
#include "Game.h"
#include "Player.h"
#include "Store.h"

using namespace std;

Player::Player()
{

}

void Player::goToTheStore()
{
	Player player;
	userInterface userInterface;

	bool continueShopping = true;
	do
	{
		userInterface.inventoryDisplay();

		continueShopping = ContinueShopping();
	} while (continueShopping == true);
}

bool Player::ContinueShopping()
{
	char choice;
	cout << "Would you like to continue shopping?Yes(Y) or No(N)" << endl;
	cin >> choice;
	if (choice == 'Y')
	{
		return true;
	}
	else 
	{
		return false;
	}
	// return choice;
}

void Player::Shopping()
{
	userInterface userInterface;
	Store store;
	double saleCost;
	int choice;
	cout << "What would you like to buy:\n1: Lemon - cost 0.25 per Lemon\n2: Sugar Cube - cost 0.10 per Sugar Cube\n3: Ice Cube - cost 0.01 per Ice Cube\n4: Cup - cost 0.05 per Cup\n5: Back to Main Menu\n";
	cin >> choice;
	if (choice == '1')
	{
		userInterface.inventoryDisplay();
		saleCost = store.SellLemons(); // from here need to add a store class and call to it to be abe to sell lemons!!
	}
}
