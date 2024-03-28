#include <iostream>
#include <vector>
#include <iomanip>
#include "Stand.h"
#include "UserInterface.h"
#include "Weather.h"

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
	cout << "Lemons: $2\nSugar: $1\nIce: $1\nCups: $2" << endl;
	cout << "" << endl;
	cout << "Enter the amount of lemons you want: " << endl;
	cin >> lemonsToBuy;
	cout << "Enter the amount of sugar you want: " << endl;
	cin >> sugarToBuy;
	cout << "Enter the amount of ice  you want: " << endl;
	cin >> iceToBuy;
	cout << "Enter the amount of cups you want: " << endl;
	cin >> cupsToBuy;

	int totalCost = lemonsToBuy * 2 + sugarToBuy * 1 + iceToBuy * 1 + cupsToBuy * 2;
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
	stillBuying();
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