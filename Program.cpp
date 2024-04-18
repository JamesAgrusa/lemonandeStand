// basic lemonade stand gameplay present (done)
// weather system (done)
// be able to go to the store and buy lemons, sugar, ice, and cups (done)
// price of product as well as weather to affect sales of the lemonade(done)
// each customer to be its own seperate object with its own chance of buying a glass of lemonade(done)
// make a recipe for our lemonade to be able to use x-amount of lemons, sugar, ice (done)
// playable for at least 7 days(done)
// daily profit or loss displyaed at the end of each day, and a running total of all profit that is also displayed at the end of each day(done)
// 
// Classes needed: Program(done), Weather(done), Customer(done), Game(done), Player(done), Store
// , Day, UserInterface(done)
// you got this James <3
// Lemonade Stand take 5 D: !!

// variables ( Has A )

// constructor


// fucntions ( Can Do )

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Customer {
public:
    double willingnessToPay; // How much the customer is willing to pay for a glass of lemonade
    double chanceOfBuying; // Probability of buying a glass of lemonade

    Customer() {
        
        willingnessToPay = (rand() % 50 + 50) / 100.0;
        chanceOfBuying = (rand() % 50 + 50) / 100.0;
    }

    // Getters
    double getWillingnessToPay() const { return willingnessToPay; }
    double getChanceOfBuying() const { return chanceOfBuying; }
};

class LemonadeStand
{
public:
    int lemons;
    int sugar;
    int ice;
    int cups;
    int cupsSold;
    double pricePerCup;
    double money;
    double dailyProfit{};
    double totalProfit{};
    vector<double> weeklyProfits;
    vector<Customer> customers;
    vector<LemonadeStand> lemon;
    vector<LemonadeStand> icecube;
    vector<LemonadeStand> sugarcube;
    vector<LemonadeStand> cup;

    LemonadeStand();

    void buyIngredients();
    void setPricePerCup();
    void generateCustomers();
    void serveCustomers();
    double calculateAndDisplayProfit();
    void runStand();
    void showInventory();

    // add remove from inventory stuff here

};

class Weather
{
public:
    // variables ( Has A )
    enum WeatherCondition { SUNNY, CLOUDY, RAINY, HAZY, WINDY };
    WeatherCondition forecast;
    WeatherCondition actual;
    int temperature{};
    char randomCondition{};
    char RandomCondition{};
    int numberOfDays{ 7 };
    int singleDay{};
    int demand{};

    // constructor
    Weather();

    // fucntions ( Can Do )
    void seeForcast();
    int weatherDemand();
    string weatherType();

};

class Game
{
public:
    int servedCustomers{};

    Game();

    void runGame();
    char playAgain();

};

class UserInterface
{
public:
    UserInterface();

    void gameIntro();
    void gameInstructions();
};

class Player
{
public:
    int recipeCallsLemon{};
    int recipeCallsSugar{};
    int recipeCallsIce{};

    Player();

    void changeRecipe();
    int changeLemonCount();
    int changeSugarCount();
    int changeIceCount();


};



int main() {
    Game game;

    game.runGame();

    return 0;
}

LemonadeStand::LemonadeStand() : lemons(0), sugar(0), ice(0), cups(0), pricePerCup(1.0), money(50.0) {}

void LemonadeStand::buyIngredients()
{
    cout << "Welcome to the store!\n";
    cout << "\nPrice per Lemon: $0.20\nPrice per SugarCube: $0.10\nPrice per IceCube: $0.05\nPrice per cup: $0.15\n";
    cout << "" << endl;
    cout << "Enter the quantity of lemons to buy: ";
    cin >> lemons;
    cout << "Enter the quantity of sugar to buy: ";
    cin >> sugar;
    cout << "Enter the quantity of ice to buy: ";
    cin >> ice;
    cout << "Enter the quantity of cups to buy: ";
    cin >> cups;
}

void LemonadeStand::setPricePerCup()
{
    cout << "Enter the price per cup of lemonade: $";
    cin >> pricePerCup;
}

void LemonadeStand::generateCustomers()
{
    int customerCount = rand() % 11 + 5;
    customers.clear();
    for (int i = 0; i < customerCount; i++) {
        customers.push_back(Customer());
    }
}

void LemonadeStand::serveCustomers()
{
    Weather weather;
    Player player;

    int demand = weather.weatherDemand();
    int cupsSold = min(static_cast<int>(customers.size()), cups);
    money += cupsSold * pricePerCup;
    demand--;
    cups -= cupsSold;
    lemons -= player.changeLemonCount() * cupsSold;
    ice -= player.changeIceCount() * cupsSold;
    sugar -= player.changeSugarCount() * cupsSold;

    cout << "You sold " << cupsSold << " cups of lemonade!\n";
}

double LemonadeStand::calculateAndDisplayProfit()
{
    totalProfit = 0;
    double revenue = customers.size() * pricePerCup;
    double expenses = lemons * 0.20 + sugar * 0.10 + ice * 0.05 + cups * 0.15;
    double profit = revenue - expenses;
    weeklyProfits.push_back(profit);
    money += profit;
    for (double dailyProfit : weeklyProfits)
    {
        totalProfit += dailyProfit;
    }
    cout << "" << endl;
    cout << "Daily Profit/Loss: $" << profit << endl;
    cout << "Total Profit/Loss: $" << money << endl;
    return profit;
}

void LemonadeStand::runStand()
{
    LemonadeStand stand;
    Weather weather;
    Player player;
    Game game;
    for (int day = 1; day <= 7; ++day) {
        cout << "\nDay " << day << ":\n";
        weather.seeForcast();
        cout << "" << endl;
        stand.showInventory();
        cout << "" << endl;
        stand.buyIngredients();
        cout << "" << endl;
        stand.setPricePerCup();
        cout << "" << endl;
        stand.generateCustomers();
        stand.serveCustomers();
        stand.calculateAndDisplayProfit();
    }
    game.playAgain();
}

void LemonadeStand::showInventory()
{
    cout << "Inventory: " << endl;
    cout << "Lemons: " << lemons << endl;
    cout << "Sugar: " << sugar << endl;
    cout << "Ice: " << ice << endl;
    cout << "Cups: " << cups << endl;
}

Weather::Weather()
{
    forecast = static_cast<WeatherCondition>(rand() % 3);
    actual = static_cast<WeatherCondition>(rand() % 3);
    temperature = rand() % 40 + 60;
}


string Weather::weatherType()
{
    Weather weather;
    string RandomCondition;

    string randomCondition[] = { "Hazy", "Sunny", "Cloudy", "Windy", "Rainy" };

    srand(unsigned(time(0)));
    RandomCondition = randomCondition[rand() % 5];
    return RandomCondition;
}



void Weather::seeForcast()
{
    Weather weather;
    for (int i = 0; i < weather.numberOfDays / 7; i++)
    {
        cout << "Todays " << "temperature is " << weather.temperature << " degrees and " << weather.weatherType() << endl;
    }
}

int Weather::weatherDemand()
{
    Weather weather;
    Customer customer;
    int demand = customer.chanceOfBuying;
    if (weather.randomCondition = "Sunny" && weather.temperature > 50) // hot and sunny best case scenerio
    {
        demand = 30;
    }
    else if (weather.randomCondition = "Sunny" && weather.temperature < 50) // cold and sunny
    {
        demand = 19;
    }
    else if (weather.randomCondition = "Windy" && weather.temperature > 50) // hot and windy
    {
        demand = 20;
    }
    else if (weather.randomCondition = "Windy" && weather.temperature < 50) // cold and windy
    {
        demand = 11;
    }
    else if (weather.randomCondition = "Cloudy" && weather.temperature > 50) // hot and cloudy
    {
        demand = 25;
    }
    else if (weather.randomCondition = "Cloudy" && weather.temperature < 50) // cold and cloudy
    {
        demand = 15;
    }
    else if (weather.randomCondition = "Hazy" && weather.temperature > 50) // hot and hazy
    {
        demand = 10;
    }
    else if (weather.randomCondition = "Hazy" && weather.temperature < 50) // cold and hazy
    {
        demand = 9;
    }
    else if (weather.randomCondition = "Rainy" && weather.temperature > 50) // hot and rainy
    {
        demand = 5;
    }
    else if (weather.randomCondition = "Rainy" && weather.temperature < 50) // cold and rainy worst case scenerio
    {
        demand = 4;
    }
    return demand;
}

Game::Game()
{

}

void Game::runGame()
{
    UserInterface userinterface;
    LemonadeStand stand;
    userinterface.gameIntro();
    userinterface.gameInstructions();
    stand.runStand();
}

char Game::playAgain()
{
    char choice;
    cout << "You successfully(more or less) ran your own lemonade stand!!" << endl;
    cout << "Would you like to play again? Yes(Y) or No(N)" << endl;
    cin >> choice;
    if (choice == 'Y')
    {
        runGame();
    }
    else
    {
        cout << "Thanks for playing!" << endl;
    }
    return choice;
}

UserInterface::UserInterface()
{

}

void UserInterface::gameIntro()
{
    cout << "Hello, and welcome!" << endl;
    cout << "" << endl;
}

void UserInterface::gameInstructions()
{
    cout << "***********************************************************************************************************" << endl;
    cout << "" << endl;
    cout << "Here we are going to be running our own lemonade stand, how exciting!!" << endl;
    cout << "" << endl;
    cout << "Here is a rundown of the game" << endl;
    cout << "" << endl;
    cout << "You will start with $50. " << endl;
    cout << "You will start each day setting your Lemononade cup price and your recipe\nThen you will go to the store" << endl;
    cout << "When the day starts customers will decide if they would like to purchase from you or not" << endl;
    cout << "" << endl << flush;
    cout << "Keep in mind that the weather will affect the customers choice to buy!" << endl;
    cout << "This game will be ran for 7 days!" << endl;
    cout << "" << endl;
    cout << "" << endl;
    cout << "***********************************************************************************************************" << endl;
}

Player::Player()
{

}

int Player::changeLemonCount()
{

    int recipeCallslemon;
    cout << "How many lemons do you want in your recipe: ";
    cin >> recipeCallslemon;
    return recipeCallslemon;
}

int Player::changeSugarCount()
{

    int choice = recipeCallsSugar;
    cout << "How many sugar cubes do you want in your recipe: ";
    cin >> choice;
    return choice;
}

int Player::changeIceCount()
{

    int choice = recipeCallsIce;
    cout << "How many ice cubes do you want in your recipe: ";
    cin >> choice;
    return choice;
}

void Player::changeRecipe()
{
    changeLemonCount();
    changeSugarCount();
    changeIceCount();
}

