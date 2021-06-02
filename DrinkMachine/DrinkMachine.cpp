// Damiano DiCocco
// BCS 230
// Soda Machine Assignment


#include <iostream>

using namespace std;

struct Drink {
	string name;
	float cost;
	int totalQty;
};

class softDrinkMachine {

	Drink drink[5];
	float totalCash;

public:
	softDrinkMachine()
	{
		drink[0].name = "cola";
		drink[0].cost = 1.00;
		drink[0].totalQty = 20;

		drink[1].name = "Root beer";
		drink[1].cost = 1.00;
		drink[1].totalQty = 20;

		drink[2].name = "Orange soda";
		drink[2].cost = 1.00;
		drink[2].totalQty = 20;

		drink[3].name = "Grape soda";
		drink[3].cost = 1.00;
		drink[3].totalQty = 20;

		drink[4].name = "Bottled water";
		drink[4].cost = 1.50;
		drink[4].totalQty = 20;

		totalCash = 0;
	}
	~softDrinkMachine()
	{
		dailyReport();
	}

	void displayChoices()
	{
		cout << "Drink Names\t\t\tPrices" << endl;
		cout << "-----------\t\t\t------" << endl;
		cout << "1: Cola\t\t\t\t1.00" << endl;
		cout << "2: Root beer\t\t\t1.00" << endl;
		cout << "3: Orange soda\t\t\t1.00" << endl;
		cout << "4: Grape soda\t\t\t1.00" << endl;
		cout << "5: Bottled water\t\t1.50" << endl;
		cout << "6: Exit" << endl;
		cout << "Please enter a choice : ";
	}
	void buyDrink(int choice)
	{
		if (6 == choice) {
			dailyReport();
			exit(1);
		}
		inputMoney(choice);
	}

private:
	void inputMoney(int choice)
	{
		float cash;
		if (0 == drink[choice - 1].totalQty) {
			cout << "Sold Out" << endl;
			return;
		}
		cout << "Enter the amount of money inserted : ";
		cin >> cash;
		cash = cash - drink[choice - 1].cost;

		if (cash < 0) {
			cout << "Sorry, you cant afford this beverage!~ Please try agian. " << endl;
		}
		else {
			drink[choice - 1].totalQty--;



			totalCash += drink[choice - 1].cost;
			cout << "Here is your beverage" << endl;
			if (cash > 0.0)
				cout << "Balance amount : " << cash << endl;
		}
	}
	void dailyReport()
	{
		cout << "Drink Names\t\t\tAvailable Qty" << endl;
		cout << "-----------\t\t\t-------------" << endl;
		cout << "Cola\t\t\t\t\t" << drink[0].totalQty << endl;
		cout << "Root beer\t\t\t\t" << drink[1].totalQty << endl;
		cout << "Orange soda\t\t\t\t" << drink[2].totalQty << endl;
		cout << "Grape soda\t\t\t\t" << drink[3].totalQty << endl;
		cout << "Bottled water\t\t\t\t" << drink[4].totalQty << endl;
		cout << "Total Sales Amount today : " << totalCash << endl;
	}
};

int main()
{
	int choice;
	softDrinkMachine x;
	while (1) {
		x.displayChoices();
		cin >> choice;
		x.buyDrink(choice);
	}
	return 0;
}