class Store
{
public:
	// variables ( Has A )
	string itemPurchase;
	int numberOfItems;
	double saleCost;
	double SellLemons(Player player);
	double SellSugar(Player player);
	double SellIce(Player player);
	double SellCups(Player player);
	void storePurchase();
	
	Player player;
	


	Store();

	//functions ( Can Do)
	int NumberOfItemsToPurchase();
	void itemAquiredByPlayer(int numberOfItems, Player player, string itemPurchase) // int numberOfItems, Player player, string itemPurchase);
	
	

};
