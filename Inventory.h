class Inventory
{
public:

	// variables ( Has A )
	std::string name;
	double purchasePrice;

	int lemonCount = {};
	int sugarCubeCount = {};
	int iceCubeCount = {};
	int cupCount = {};
	

	// constructor
	Inventory();

	// functions ( Can Do)
	void Lemon();
	void SugarCube();
	void IceCube();
	void Cup();
};
