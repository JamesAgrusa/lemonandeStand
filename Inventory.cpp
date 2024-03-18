#include <iostream>
#include <string>
#include "UserInterface.h"
#include "Game.h"
#include "Store.h"
#include "Inventory.h"

Inventory::Inventory()
{

}

void Inventory::Lemon()
{
	int lemonCount = {};
	name = "lemon";
	purchasePrice = 0.25;
}

void Inventory::IceCube()
{
	name = "icecube";
	purchasePrice = 0.01;
}

void Inventory::SugarCube()
{
	name = "sugarcube";
	purchasePrice = 0.10;
}

void Inventory::Cup()
{
	name = "cup";
	purchasePrice = 0.05;
}