class userInterface
{
public:

	

	userInterface();


	void instructions();
	void gameSetUp();
	void startDayDisplay();
	static void userDisplay();
	static void inventoryDisplay();
	void recipeDisplay();
	void costDisplay();
	int GetRandomInteger(int min, int max);
	static int GetUserInteger(string output);
	
};
