#include <iostream>
#include <string>
#include "Game.h"
#include "UserInterface.h"
#include "Player.h"
#include "Weather.h"
#include "Store.h"

using namespace std;

Weather::Weather()
{

}

int Weather::weatherTemp()
{
    srand(unsigned(time(0)));
    // int min = 0;
    // int max = 100;
    int temperature = rand() % 90;
    return temperature;
}

char Weather::weatherType()
{
    Weather weather;
    char RandomCondition;
    char randomCondition[] = { 'H', 'S', 'C', 'W', 'R'}; // convert to a string Hazy, sunny, cloudy, windy, rainy

    srand(unsigned(time(0)));
    RandomCondition = randomCondition[rand() % 5];
    return RandomCondition;
}

void Weather::seeForcast()
{
    Weather weather;
    for (int i = 0; i < weather.numberOfDays / 7; i++)
    {
        cout << "Todays " << "temperature is " << weather.weatherTemp() << " degrees and " << weather.weatherType() << endl;
    }
}