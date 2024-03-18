#include <iostream>
#include <string>
#include "UserInterface.h"
#include "Game.h"
#include "Store.h"
#include "Inventory.h"

using namespace std;

Store::Store()
{

}

double Store::sellLemon()
{
	
	
	return 0;
}

int Store::numberItemsToPurchase()
{
	int numberOfItems;
	cout << "how many items would you like?" << endl;
	cin >> numberOfItems;

	return numberOfItems;
}

char Store::stillBuying()
{
	Game game;
	char choice;
	cout << "Are you done buying product? Yes(Y) or No(N)" << endl;
	cin >> choice;
	if (choice == 'Y')
	{
		game.goToStore();
	}	
	return choice;
}

void Store::itemAquired()
{
	for (int i = 0; i < numberOfItems; i++)
	{

	}
}