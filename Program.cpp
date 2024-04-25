#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Customer {
public:
    double chanceOfBuying{}; // Probability of buying a glass of lemonade based on weather
    double demand;
    
    Customer();
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
    int temperature{};
    char randomCondition{};
    char RandomCondition{};
    int numberOfDays{ 7 };
   
    // constructor
    Weather();

    // functions ( Can Do )
    void seeForcast();
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

Customer::Customer()
{
    chanceOfBuying = demand; //demand is determined by weather
}

LemonadeStand::LemonadeStand() : lemons(0), sugar(0), ice(0), cups(0), pricePerCup(0), money(50.0) {}

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
    LemonadeStand stand;
    int customerCount{}; // generates random customers below 
    
    if (weather.weatherType() == "Sunny" && weather.temperature <= 50)
    {
        customerCount = rand() % 45 + 1; // chance of more customers to buy
    }
    if (weather.weatherType() == "Sunny" && weather.temperature >= 50)
    {
        customerCount = rand() % 35 + 1; // chance of lesser customers due to below 50
    }
    else if (weather.weatherType() == "Cloudy" && weather.temperature <= 50)
    {
        customerCount = rand() % 40 + 1; // chance of more customers to buy
    }
    if (weather.weatherType() == "Cloudy" && weather.temperature >= 50)
    {
        customerCount = rand() % 30 + 1; // chance of lesser customers to buy due to below 50
    }
    customers.clear();
    for (int i = 0; i < customerCount; i++) {
        customers.push_back(Customer());
    }
}

void LemonadeStand::serveCustomers()
{  
    Player player;
    int cupsSold = min(static_cast<int>(customers.size()), cups);
    cups -= cupsSold; 
    lemons -= player.changeLemonCount() * cupsSold; // updates inventory
    ice -= player.changeIceCount() * cupsSold; // updates inventory
    sugar -= player.changeSugarCount() * cupsSold; // updates inventory
    cout << "" << endl;
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
    cout << "Total Profit/Loss: $" << money - 50 << endl;
    return profit;
}

void LemonadeStand::runStand()
{
    LemonadeStand stand;
    Weather weather;
    Game game;
    for (int day = 1; day <= 7; ++day) { // the game will run through this loop 7 times, then game over!
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
    temperature = rand() % 70 + 30;
}

string Weather::weatherType()
{
    string RandomCondition;
    string randomCondition[] = { "Sunny","Cloudy" };
    srand(unsigned(time(0)));
    RandomCondition = randomCondition[rand() % 2]; // random weather generated between cloudy or sunny
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