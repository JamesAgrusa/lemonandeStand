#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Customer {
public:
    double chanceOfBuying; // Probability of buying a glass of lemonade
    double demand;
    
    Customer() {
        chanceOfBuying = demand;//(rand() % 50 + 50) / 100.0; 
    }

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
    vector<Customer> customers;

    LemonadeStand();

    void buyIngredients();
    void setPricePerCup();
    void generateCustomers();
    void serveCustomers();
    double calculateAndDisplayProfit();
    void runStand();
    void showInventory();
};

class Weather
{
public:
    // variables ( Has A )
    enum WeatherCondition { SUNNY, CLOUDY, RAINY, HAZY, WINDY };
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
    double weatherDemand();
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
    Weather weather;

    int customerCount = rand() % 20 + 5; // generates random customers between 5 - 24
    
    customers.clear();
    for (int i = 0; i < customerCount; i++) {
        customers.push_back(Customer());
    }
}

void LemonadeStand::serveCustomers()
{
    Weather weather;
    Player player;

    double demand = weather.weatherDemand();
    int cupsSold = min(static_cast<int>(customers.size()), cups);
    money += cupsSold * pricePerCup;
    cups -= cupsSold; 
    lemons -= player.changeLemonCount() * cupsSold; // updates inventory
    ice -= player.changeIceCount() * cupsSold; // updates inventory
    sugar -= player.changeSugarCount() * cupsSold; // updates inventory

    cout << "You sold " << cupsSold << " cups of lemonade!\n";
}

double LemonadeStand::calculateAndDisplayProfit()
{
    double revenue = customers.size() * pricePerCup;
    double expenses = lemons * 0.20 + sugar * 0.10 + ice * 0.05 + cups * 0.15;
    double profit = revenue - expenses;
    money += profit;
    cout << "" << endl;
    cout << "You spent: $" << expenses << " for the day on supplies" << endl;    
    cout << "Daily Profit/Loss: $" << profit << endl;
    cout << "Total Profit/Loss: $" << money << endl;
    return profit;
}

void LemonadeStand::runStand()
{
    LemonadeStand stand;
    Weather weather;
    Game game;
    for (int day = 1; day <= 7; ++day) { // the game will run through this loop 7 times
        cout << "\nDay " << day << ": ";
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
    cout << "" << endl;
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
    temperature = rand() % 60 + 30;
}

string Weather::weatherType()
{
    Weather weather;
    string RandomCondition;
    string randomCondition[] = { "Hazy", "Sunny", "Cloudy", "Windy", "Rainy" };
    srand(unsigned(time(0)));
    RandomCondition = randomCondition[rand() % 5]; // random weather generated between the conditions made above
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

double Weather::weatherDemand()
{
    Weather weather;
    Customer customer;
    double demand = customer.chanceOfBuying;
    if (weather.randomCondition = "Sunny" && weather.temperature > 50) // hot and sunny
    {
        customer.demand = rand() % 100 + 80;
    }
    else if (weather.randomCondition = "Sunny" && weather.temperature < 50) // cold and sunny
    {
        customer.demand = rand() % 90 + 70;
    }
    else if (weather.randomCondition = "Windy" && weather.temperature > 50) // hot and windy
    {
        customer.demand = rand() % 85 + 65;
    }
    else if (weather.randomCondition = "Windy" && weather.temperature < 50) // cold and windy
    {
        customer.demand = rand() % 75 + 55;
    }
    else if (weather.randomCondition = "Cloudy" && weather.temperature > 50) // hot and cloudy
    {
        customer.demand = rand() % 95 + 75;
    }
    else if (weather.randomCondition = "Cloudy" && weather.temperature < 50) // cold and cloudy
    {
        customer.demand = rand() % 80 + 60;
    }
    else if (weather.randomCondition = "Hazy" && weather.temperature > 50) // hot and hazy
    {
        customer.demand = rand() % 70 + 50;
    }
    else if (weather.randomCondition = "Hazy" && weather.temperature < 50) // cold and hazy
    {
        customer.demand = rand() % 65 + 45;
    }
    else if (weather.randomCondition = "Rainy" && weather.temperature > 50) // hot and rainy
    {
        customer.demand = rand() % 10 + 5;
    }
    else if (weather.randomCondition = "Rainy" && weather.temperature < 50) // cold and rainy
    {
        customer.demand = rand() % 10 + 5;
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
    userinterface.gameInstructions();
    stand.runStand();
}

char Game::playAgain()
{
    char choice;
    cout << "Game Over" << endl;
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

void UserInterface::gameInstructions()
{
    cout << "***********************************************************************************************************" << endl;
    cout << "Hello, and welcome!" << endl;
    cout << "Here we are going to be running our own lemonade stand, how exciting!!" << endl;
    cout << "Here is a rundown of the game" << endl;
    cout << "You will start with $50. " << endl;
    cout << "You will start each day by going to the store\nThen you will get to set your price per cup price\nFinally you get to define your recipe!" << endl;
    cout << "When the day starts customers will decide if they would like to purchase from you or not" << endl;
    cout << "Keep in mind that the weather will affect the customers choice to buy!" << endl;
    cout << "This game will be ran for 7 days!" << endl;
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