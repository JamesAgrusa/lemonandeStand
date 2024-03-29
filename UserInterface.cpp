#include <iostream>
#include <vector>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include "Stand.h"
#include "UserInterface.h"
#include "Weather.h"
#include "Recipe.h"
#include "Customer.h"

using namespace std;

UserInterface::UserInterface()
{
	
}

void UserInterface::userChoice()
{
	
	for (int day = 1; day <= 7; ++day)
	{
		cout << "\nDay " << day << ": " << endl;
		enum class WeatherType { SUNNY, CLOUDY, RAINY, SNOWY };
		
		
		Recipe recipe;
		Stand stand;
		Customer customer;
		
		cout << "" << endl;
		
		stand.buyIngredients();
		stand.displayStatus();
		cout << "" << endl;
		cout << "Here you can set a new price per cup of lemonade, then you can pick how many of each ingredient you want in your recipe" << endl;
		cout << "" << endl;
		recipe.priceOfCup();
		recipe.changeLemonCount();
		recipe.changeSugarCount();
		recipe.changeIceCount();
				
		customer.generateCustomers();
		customer.serveCustomers();
		seeProfit();
	}
	
}

char UserInterface::done()
{
	char choice;
	cout << "Are you done?Yes(Y) or No(N)" << endl;
	cin >> choice;
	if (choice == 'Y')
	{
		userChoice();
	}
	else
	{
		cout << "Try again!" << endl;
		done();
	}
	return choice;
}

void UserInterface::seeProfit()
{
	Stand stand;
	Customer customer;

	double revenue = customer.customers.size() * stand.pricePerCup;
	double expenses = stand.lemons * 0.05 + stand.sugar * 0.02 + stand.ice * 0.01 + stand.cups * 0.1;
	double profit = revenue - expenses;
	stand.money += profit;
	cout << "Daily Profit/Loss: $" << profit << endl;
	cout << "Total Profit/Loss: $" << stand.money << endl;
}




