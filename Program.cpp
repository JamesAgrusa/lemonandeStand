// basic lemonade stand gameplay present (done)
// weather system (done)
// be able to go to the store and buy lemons, sugar, ice, and cups (done)
// price of product as well as weather to affect sales of the lemonade
// each customer to be its own seperate object with its own chance of buying a glass of lemonade(done)
// make a recipe for our lemonade to be able to use x-amount of lemons, sugar, ice (done - but cant use per cup)
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
#include <cstdlib>
#include <ctime>

using namespace std;

class Customer {
public:
    double willingnessToPay; // How much the customer is willing to pay for a glass of lemonade
    double chanceOfBuying; // Probability of buying a glass of lemonade

    Customer() {
        willingnessToPay = (rand() % 50 + 50) / 100.0; // Random willingness to pay between 0.5 and 1.0
        chanceOfBuying = (rand() % 50 + 50) / 100.0; // Random chance of buying between 0.5 and 1.0               
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
    void calculateAndDisplayProfit();
    void runStand();
    void showInventory();

    // add remove from inventory stuff here
    
};

class Weather
{
public:
    // variables ( Has A )
    int temperature{};
    char randomCondition{};
    char RandomCondition{};
    int numberOfDays{ 7 };
    int singleDay{};

    // constructor
    Weather();

    // fucntions ( Can Do )
    int weatherTemp();
    string weatherType();
    void seeForcast();
    void weatherCheck();
};

class Game
{
public:
    Game();

    void runGame();
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

    void makeNewPitcher();
    void removeLemonsFromInventory();
    void removeSugarFromInventory();
    void removeIceFromInventory();
    void removeCupsFromInventory();
    bool checkEnoughLemons();
    bool checkEnoughIce();
    bool checkEnoughSugar();
    bool checkEnoughCups();
    bool checkInventory();
    bool sellCupOfLemonade();
};

class Pitcher
{
public:
    int cupsLeftInPitcher = 0;

    Pitcher();

    void fillUpPitcher();
    void fillCupLemonade();
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
    customers.clear();
    for (int i = 0; i < 10; ++i) // Generate 10 customers for the day
    {
        customers.push_back(Customer());
    }
}

void LemonadeStand::serveCustomers()
{
    Weather weather;
    Player player;
    weather.weatherCheck();
    int cupsSold = min(static_cast<int>(customers.size()), cups);
   
    // etc for other items in inventory
    money += cupsSold * pricePerCup;
    cups -= cupsSold;
    lemons -= player.recipeCallsLemon * cupsSold;
    cout << "You sold " << cupsSold << " cups of lemonade!\n";
}

void LemonadeStand::calculateAndDisplayProfit()
{
    double revenue = customers.size() * pricePerCup;
    double expenses = lemons * 0.05 + sugar * 0.02 + ice * 0.01 + cups * 0.1;
    double profit = revenue - expenses;
    money += profit;
    cout << "Daily Profit/Loss: $" << profit << endl;
    cout << "Total Profit/Loss: $" << money << endl;
}

void LemonadeStand::runStand()
{
    LemonadeStand stand;
    Weather weather;
    Player player;

    for (int day = 1; day <= 7; ++day) {
        cout << "\nDay " << day << ":\n";
        weather.seeForcast();
        cout << "" << endl;
        player.changeRecipe();
        cout << "" << endl;
        stand.buyIngredients();
        cout << "" << endl;
        stand.setPricePerCup();
        cout << "" << endl;
        stand.showInventory();
        cout << "" << endl;
        stand.generateCustomers();
        player.sellCupOfLemonade(); // work on wiggling this into the game!! 
        stand.serveCustomers();
        stand.calculateAndDisplayProfit();
    }
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

}

int Weather::weatherTemp()
{
    srand(unsigned(time(0)));
    // int min = 0;
    // int max = 100;
    int temperature = rand() % 90;
    return temperature;
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
        cout << "Todays " << "temperature is " << weather.weatherTemp() << " degrees and " << weather.weatherType() << endl;
    }    
}

void Weather::weatherCheck()
{
    Weather weather;
    Customer customer;

    if (weather.weatherTemp() <= 50)
    {
        customer.willingnessToPay = (rand() % 50 + 50); // Random willingness to pay between 0.5 and 1.0
        customer.chanceOfBuying = (rand() % 50 + 50); // Random chance of buying between 0.5 and 1.0
    }
    else if (weather.weatherTemp() >= 50)
    {
        customer.willingnessToPay = (rand() % 50);
        customer.chanceOfBuying = (rand() % 50);
    }
    else if (weather.weatherTemp() >= 20)
    {
        customer.willingnessToPay = (rand() % 20);
        customer.chanceOfBuying = (rand() % 20);
    }
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
    cout << "Keep in mind that the weather, the prices you set, and your recipe all super megaly affect the customers choice to buy!" << endl;
    cout << "Also keep in mind the forcast at the start of each day, when making your purchaeses and changing your recipe" << endl;
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

void Player::makeNewPitcher()
{
    Pitcher pitcher;
    removeLemonsFromInventory();
    removeSugarFromInventory();
    removeIceFromInventory();
    pitcher.fillCupLemonade();
}

void Player::removeLemonsFromInventory()
{
    for (int i = 0; i < recipeCallsLemon; i++)
    {
        LemonadeStand stand;
        stand.lemon;
    }
}

void Player::removeSugarFromInventory()
{
    for (int i = 0; i < recipeCallsSugar; i++)
    {
        LemonadeStand stand;
        stand.sugarcube;
    }
}

void Player::removeIceFromInventory()
{
    for (int i = 0; i < recipeCallsIce; i++)
    {
        LemonadeStand stand;
        stand.icecube;
    }
}

void Player::removeCupsFromInventory()
{
    LemonadeStand stand;
    stand.cups -= stand.cupsSold;
}

bool Player::checkEnoughLemons()
{
    LemonadeStand stand;
    Player player;
    if (stand.lemons >= player.recipeCallsLemon)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Player::checkEnoughSugar()
{
    LemonadeStand stand;
    Player player;
    if (stand.sugar >= player.recipeCallsSugar)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Player::checkEnoughIce()
{
    LemonadeStand stand;
    Player player;
    if (stand.ice >= player.recipeCallsIce)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Player::checkEnoughCups()
{
    LemonadeStand stand;
    Player player;
    if (stand.cups >= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Player::checkInventory()
{
    bool enoughLemons = checkEnoughLemons();
    bool enoughIce = checkEnoughIce();
    bool enoughSugar = checkEnoughSugar();
    bool enoughCups = checkEnoughCups();
    if (enoughLemons == true && enoughIce == true && enoughSugar == true && enoughCups == true)
    {
        makeNewPitcher();
        return true;
    }
    else
    {
        cout << "You have ran out of product!" << endl;
        return false;
    }
}

bool Player::sellCupOfLemonade()
{
    Pitcher pitcher;
    LemonadeStand stand;
    if ((pitcher.cupsLeftInPitcher >= 1) && (stand.cups >= 1))
    {
        pitcher.fillCupLemonade();
        removeCupsFromInventory();
        return true;
    }
    else
    {
        checkInventory();
        return false;
    }
}

Pitcher::Pitcher()
{

}

void Pitcher::fillUpPitcher()
{
    cupsLeftInPitcher = 14;
}

void Pitcher::fillCupLemonade()
{
    cupsLeftInPitcher -= 1;
}
