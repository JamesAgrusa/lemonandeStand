#include <iostream>
#include <vector>
#include <iomanip>
#include "Stand.h"
#include "UserInterface.h"
#include "Weather.h"

using namespace std;

UserInterface::UserInterface()
{
	
}

char UserInterface::userChoice()
{
	Stand stand;
	char choice{};

	cout << "" << endl;
	cout << "What would you like to do to get your day started?\nA) Go to the store?\nB) See the forecast?\nC) Change your recipe?\nD) Open your stand!\n";
	cin >> choice;
	if (choice == 'A')
	{
		stand.buyIngredients();
		
	}
	if (choice == 'B')
	{
		cout << "balls" << endl;
		Weather weather;
		weather.getForcast();
	}
	if (choice == 'C')
	{
		cout << "balls" << endl;
	}
	if (choice == 'D')
	{
		cout << "balls" << endl;
	}

	return choice;
}