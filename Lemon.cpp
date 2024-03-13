#include <iostream>
#include <string>
#include "Game.h"
#include "UserInterface.h"
#include "Player.h"
#include "Store.h"
#include "Inventory.h"
#include "Lemon.h"

using namespace std;

Lemon::Lemon()
{
	string name;
	name = "lemon";

	int purhcasePrice = 0.25;
}

void Lemon::addLemon()
{
	// trying to figure out how to add an item once bought
	// will then need to figure out how to delete item once used in recipe!
	Lemon lemon;
	for (int i = 0; i < numberOfItems; i++)
	{
		if (itemPurchase == '1')
		{
			lemon.numberOfItems++;
		}
	}
}