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

using namespace std;

Weather::Weather()
{

}

int Weather::getRandomWeather()
{
	enum class WeatherType { Sunny, Cloudy, Rainy, Snowy };
	int randNum = rand() % 4;
	return randNum;
}

int Weather::getRandomTemp(int minTemp, int maxTemp)
{
	return rand() % (maxTemp - minTemp + 1) + minTemp;
}

void Weather::getForcast()
{
	enum WeatherType { Sunny, Cloudy, Rainy, Snowy };
	Weather weather;
	srand(time(nullptr));
	const string weatherTypes[] = { "Sunny", "Cloudy", "Rainy", "Snowy" };
	const int minTemperature = 50;
	const int maxTemperature = 100;

	cout << "Weekly forecast: " << endl;
	for (int day = 1; day <= 7; ++day)
	{
		getRandomWeather();
		int temperature = getRandomTemp(minTemperature, maxTemperature);

		cout << "Day " << day << " :" << weatherTypes << " , Temperature: " << temperature << "F" << endl;
	}
}

