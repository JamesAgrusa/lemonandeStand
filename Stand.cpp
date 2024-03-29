#include <iostream>
#include <vector>
#include <iomanip>
#include "Stand.h"
#include "UserInterface.h"
#include "Weather.h"
#include "Recipe.h"
#include "Customer.h"

using namespace std;

Stand::Stand() : lemons(0), sugar(0), ice(0), cups(0), pricePerCup(0.5), money(50.0) {}

void Stand::buyIngredients()
{
	int lemonsToBuy;
	int sugarToBuy;
	int iceToBuy;
	int cupsToBuy{};

	cout << "Welcome to the store!" << endl;
	cout << "" << endl;
	cout << "Here you will get an oppertinity to buy the items available to you!" << endl;
	cout << "Items available" << endl;
	cout << "" << endl;
	cout << "Lemons: $0.05\nSugar: $0.02\nIce: $0.01\nCups: $0.10" << endl;
	cout << "" << endl;
	cout << "Enter the amount of lemons you want: ";
	cin >> lemonsToBuy;
	cout << "Enter the amount of sugar you want: ";
	cin >> sugarToBuy;
	cout << "Enter the amount of ice  you want: ";
	cin >> iceToBuy;
	cout << "Enter the amount of cups you want: ";
	cin >> cupsToBuy;

	int totalCost = lemonsToBuy * 0.05 + sugarToBuy * 0.02 + iceToBuy * .01 + cupsToBuy * .10;
	if (totalCost > money)
	{
		cout << "You dont have enough money to buy this much" << endl;
	}

	lemons += lemonsToBuy;
	sugar += sugarToBuy;
	ice += iceToBuy;
	cups += cupsToBuy;
	money -= totalCost;

	cout << "" << endl;
	cout << "Ingredients purchased successfully" << endl;
	// stillBuying();
}
void Stand::displayStatus()
{
	cout << "" << endl;
	cout << "Inventory: " << endl;
	cout << "Lemons: " << lemons << endl;
	cout << "Sugar: " << sugar << endl;
	cout << "Ice: " << ice << endl;
	cout << "Cups: " << cups << endl;
	cout << "Money: $" << money << endl;
}

char Stand::stillBuying()
{
	UserInterface userInterface;

	char choice;
	cout << "Are you still buying? Yes(Y) or No(N)" << endl;
	cin >> choice;
	if (choice == 'Y')
	{
		displayStatus();
		buyIngredients();
	}
	else if (choice == 'N')
	{
		displayStatus();
		userInterface.userChoice();
	}
	return choice;
}