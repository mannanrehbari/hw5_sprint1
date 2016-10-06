#include "controller.h"



void control()
{
	int selection;

	cout << "Welcome to main menu\n\t====================\n\n";
	print_main();

	cout << "Selection: ";
	selection = integer_validation();
	while (selection != 3)
	{

		if (selection == 1)
		{
			create();
		}
		else if (selection == 2)
		{
			report();
		}
		print_main();
		cout << "Selection: ";
		selection = integer_validation();
	}




}

void create()
{
	int selection;
	print_create();

	cout << "Selection: ";
	cin >> selection;
	while (selection != 4)
	{
		if (selection == 1)
		{
			create_part();
		}
		else if (selection == 2)
		{
			create_model();
		}
		else if (selection == 3)
		{
			create_order();
		}


		print_create();
		cout << "Selection: ";
		cin >> selection;
		if (selection == 4) { cout << "\nGoing back to main\n"; }
	}


}
void report()
{
	cout << "\nReport function called: Print all reports here, then go back\n";

}

void print_main()
{
	cout << "\nMain:\n";
	cout << "1: Create parts or model\n";
	cout << "2: Display report \n";
	cout << "3: Quit\n";

}
void print_create()
{
	cout << "\nCreate:\n";
	cout << "1: Robot Part\n";
	cout << "2: Robot Model\n";
	cout << "3: Order\n";
	cout << "4: Previous Menu\n";

}

void create_part()
{
	string new_name;
	int new_number;
	int new_type;
	double new_weight;
	double new_cost;
	string new_description;


	cout << "\n\nCreate a part and add it to vector and go back \n";
	int type, i;
	cout << "\nChoose part type:\n";
	for (i = 0; i < 5; i++)
	{
		cout << i + 1 << ": " << partType[i] << endl;
	}
	cout << "6: Go back to previous menu\n";
	type = integer_validation();

	cin.ignore();
	// getting the general parts 
	cout << "";







}

void create_model()
{
	cout << "\n\nCreate a new robot model, add it model vector, go back\n";
}

void create_order()
{
	cout << "\nCreate a new order for a customer, update the vector, go back\n";
}

int integer_validation()
{
	int num;
	cin >> num;
	while (!cin)
	{

		cin.clear();
		cin.ignore();
		cin >> num;
	}
	return num;

}