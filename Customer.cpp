#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "Stand.h"
#include "UserInterface.h"
#include "Weather.h"
#include "Recipe.h"
#include "Customer.h"

using namespace std;

Customer::Customer()
{
	willToPay = (rand() % 50 + 50) / 100;
	chanceOfBuying = (rand() % 50 + 50) / 100;
}

double Customer::getWillToPay() 
{
	return willToPay;
}

double Customer::getChanceOfBuying() const
{
	return chanceOfBuying;
}

void Customer::generateCustomers()
{
	customers.clear();
	for (int i = 0; i < 10; ++i)
	{
		customers.push_back(Customer());
	}
}

void Customer::serveCustomers()
{
	Stand stand;

	int cupsSold = min(static_cast<int>(customers.size()), stand.cups);
	stand.money += cupsSold * stand.pricePerCup;
	stand.cups -= cupsSold;
	cout << "You sold " << cupsSold << " cups of lemonade!\n";
}