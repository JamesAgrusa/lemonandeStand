class Game
{
public:
	// variables ( Has A )
	UserInterface userInterface;
	int lemonCount{};
	// constructor

	Game();

	// functions ( Can Do )
	void runGame();
	bool userChoice();
	void goToStore();
	char seeForcast();
	char changeRecipe();
	void openStand();
	bool MoreChoices();


};
