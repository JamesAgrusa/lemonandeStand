#include <iostream>
#include <string>
#include "Game.h"
#include "UserInterface.h"
#include "Player.h"
#include "Store.h"

using namespace std;

Store::Store()
{

}

double Store::SellLemons()
{
	itemPurchased = "lemon";
	numberOfItems = NumberOfItemsToPurchase();
	doule saleCost = // add inventory class call to it and update store inventory
}

int Store::NumberOfItemsToPurchase()
{
	userInterface userInterface;

	numberOfItems = userInterface.GetUserInteger("How many items do you want?");
	return numberOfItems;
}