class Day
{
public:
	// variables ( Has A )

	string condition;
	int temperature{};
	int randomCondition{};
	int min = 1;
	int max = 7;
	 

	// constructor
	Day();

	// functions ( Can Do )

	int weatherTemp();
	string weatherType();


};
