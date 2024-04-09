class Player
{
public:
// variables ( Has A )
	int lemons{};
	int sugar{};
	int ice{};
	int cups{};
	int recipeCallsLemon{};
	int recipeCallsSugar{};
	int recipeCallsIce{};
// constructor
	Player();

// fucntions ( Can Do )
	void showInventory();
	void changeRecipe();
	int changeLemonCount();
	int changeSugarCount();
	int changeIceCount();

};
