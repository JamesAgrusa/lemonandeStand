class Recipe
{
public:
	// variables ( Has A )
	double pricePerCup{};
	int recipeCallsLemon{};
	int recipeCallsSugar{};
	int recipeCallsIce{};

	// constructor
	Recipe();

	// functions ( Can Do )

	double priceOfCup();
	int changeLemonCount();
	int changeSugarCount();
	int changeIceCount();
};
