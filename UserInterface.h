class UserInterface
{
public:
	// variables ( Has A )
	double pricePerCup{};
	int min = 0;
	int max = 100;
	int randomInt{};
	

	// constructor 

	UserInterface();

	// functions ( Can Do )

	void instructions();
	void gameSetup();
	void startOfDay();
	void userDisplay();
	void inventoryDisplay();
	void recipeDisplay();
	void costDisplay();
	// int getRandomInt();
	
};
