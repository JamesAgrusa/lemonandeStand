class Customer
{
public:

	double willToPay;
	double chanceOfBuying;
	vector<Customer> customers;

	Customer();

	void serveCustomers();
	double getWillToPay();
	double getChanceOfBuying()const;
	void generateCustomers();
	


};
