class Recipe
{
public:
	// variables ( Has A )
	double pricePerCup = .75;
	int recipeCallsLemon = 4;
	int recipeCallsSugar = 4;
	int recipeCallsIce = 4;
	UserInterface userInterface;

	// constructor
	Recipe();

	// functions ( Can Do )

	double priceOfCup();
	int changeLemonCount();
	int changeSugarCount();
	int changeIceCount();
};
