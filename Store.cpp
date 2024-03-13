#include <iostream>
#include <string>
#include <cmath>
#include "Game.h"
#include "UserInterface.h"
#include "Player.h"
#include "Store.h"
#include "Inventory.h"
#include "Lemon.h"

using namespace std;

Store::Store()
{
	Player player;
}

double Store::SellLemons(Player player)
{
	Inventory storeInventory;
	
	itemPurchase = "lemon";
	numberOfItems = NumberOfItemsToPurchase();
	double saleCost = storeInventory.lemon.purchasePrice * numberOfItems;
	return saleCost;
}

double Store::SellSugar(Player player)
{
	Inventory storeInventory;
	
	itemPurchase = "sugar";
	numberOfItems = NumberOfItemsToPurchase();
	double saleCost = storeInventory.sugarcube.purchasePrice * numberOfItems;
	return saleCost;
}

double Store::SellIce(Player player)
{
	Inventory storeInventory;
	
	itemPurchase = "ice";
	numberOfItems = NumberOfItemsToPurchase();
	double saleCost = storeInventory.icecube.purchasePrice * numberOfItems;
	return saleCost;
}

double Store::SellCups(Player player)
{
	Inventory storeInventory;
	
	itemPurchase = "cup";
	numberOfItems = NumberOfItemsToPurchase();
	double saleCost = storeInventory.cup.purchasePrice * numberOfItems;
	return saleCost;
}



int Store::NumberOfItemsToPurchase()
{
	userInterface userInterface;

	numberOfItems = userInterface.GetUserInteger("How many items do you want?");
	return numberOfItems;
}

void Store::itemAquiredByPlayer() //int numberOfItems, Player player, string itemPurchase)
{
	Inventory inventory;
	Player player;
	Lemon lemon;
	for (int i = 0; i < numberOfItems; i++) 
	{
		if (itemPurchase == "lemon")
		{
			
			player.inventory.lemon.addLemon();
			
			
		}
		else if (itemPurchase == "sugarcube")
		{
			player.inventory.sugarcube;
		}
		else if (itemPurchase == "icecube")
		{
			player.inventory.icecube;
		}
		else if (itemPurchase == "cup")
		{
			player.inventory.cup;
		}
	}
}

void Store::storePurchase()
{

	cout << "Your total comes out too " << saleCost << endl;
	player.wallet.money -= saleCost;
	itemAquiredByPlayer(); // numberOfItems, player, itemPurchase
	cout << "You have: " << player.wallet.money << " left" << endl;
}