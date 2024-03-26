class Store
{
public:
	int numberOfItems{};
	double lemons{};
	double sugarcubes{};
	double icecubes{};
	double cups{};

	
	double saleCost{};

	Store();

	char stillBuying();
	int numberItemsToPurchase();
	double sellLemon();
};
