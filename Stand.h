class Stand
{
public:

	Stand();

	void buyIngredients();
	void displayStatus();
	char stillBuying();

	
private:
	int lemons;
	int sugar;
	int ice;
	int cups;
	double pricePerCup;
	double money;

	
};
