#include "controller.h"
#include "robotpart.h"


vector<RobotPart*> myParts;


void control()
{
	
	
	int selection;

	cout << "***** Welcome to Robbie Robot Shop *****\n\n";
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
	cout << "\n\nPrinting Vector of Objects\n";
	cout << "\n=======================================================================================================\n";
	

	printf("%-15s|%10s|%-15s|%8s|%8s|%-20s|%-20s|\n", "Partname", "Partnum", "PartType", "Weight", "Cost", "Description", "Other Details");
	cout << "=======================================================================================================\n";

	for(unsigned int i= 0; i < myParts.size(); i++)
	{
		myParts[i]->print_part();
	}

	cout << "\n";


}

void print_main()
{
	cout << "----------\n|  Main  |\n----------\n";
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
	//general description
	string new_name;
	
	
	double new_weight;
	double new_cost;
	string new_description;
	int type;

	//part-specific info holders
	int battery_compartments;
	double arm_power;
	double battery_capacity;
	double loco_maxspeed;
	double loco_power;


	bool name_length_ok = false;
	bool description_ok = false;
	
	
	print_part_type();
	type = integer_validation();
	
	// 6 is key for previous menu after 5 part types
	while (type != 6) 
	{
		cout << "\n\n==================\nAdd a(n) " << partType[type-1] << ":\n";
		

		cin.ignore();
		cin.clear();
		while(name_length_ok == false)
		{
			cout << "Part name: ";
			getline(cin, new_name);
			if (new_name.length() <=15) 
			{
				name_length_ok = true;
			}
			else { cout << "Enter name again! Max 15 characters\n"; }
		}
		
		
		
		
		

		cout << "Part weight: ";
		cin >> new_weight;

		cout << "Part cost: ";
		cin >> new_cost;

		
		
		cin.ignore();
		cin.clear();
		while (description_ok == false)
		{
			cout << "Part description: ";
			getline(cin, new_description);
			if (new_description.length() <= 15)
			{
				description_ok = true;
			}
			else { cout << "Enter description again! Max 15 characters\n"; }
		}




		

		if (type == 1) 
		{
			cout << "Battery compartments: ";
			cin >> battery_compartments;
			Torso* new_torso = new Torso ;
			new_torso->setGenValues(new_name, type, new_weight, new_cost, new_description);
			new_torso->setCompart(battery_compartments);
			if (new_torso->battery_comparts != -1) 
			{
				
				myParts.push_back(new_torso);
				cout << "New torso added! success! yay!\n==================\n";
			}
			else 
			{
				cout << "Bad input, object not added\n==================\n";
			}

			
		}
		else if (type == 2) 
		{
			Head * new_head = new Head;
			new_head->setGenValues(new_name, type, new_weight, new_cost, new_description);
			myParts.push_back(new_head);
			cout << "New head added! success! yay!\n==================\n";

		}
		else if (type == 3)
		{
			Arm * new_arm = new Arm;
			new_arm->setGenValues(new_name, type, new_weight, new_cost, new_description);
			cout << "Arm power: ";
			cin >> arm_power;
			
			new_arm->set_arm_power(arm_power);
			myParts.push_back(new_arm);
			cout << "New arm added! success! yay!\n==================\n";
		}
		else if (type == 4)
		{
			Battery * new_battery = new Battery;
			new_battery->setGenValues(new_name, type, new_weight, new_cost, new_description);
			cout << "Battery capacity: ";
			cin >> battery_capacity;
			new_battery->setBattCap(battery_capacity);
			myParts.push_back(new_battery);
			cout << "New battery added! success!\n==================\n";

		}
		else if (type == 5)
		{
			Locomotor* new_locomotor = new Locomotor;
			
			cout << "Locomotor max speed: ";
			cin >> loco_maxspeed;
			cout << "Locomotor power: ";
			cin >> loco_power;

			new_locomotor->setGenValues(new_name, type, new_weight, new_cost, new_description);
			new_locomotor->set_power_maxspeed(loco_maxspeed, loco_power);

			myParts.push_back(new_locomotor);
			cout << "New locomotor added! \n==================\n";


		}
		RobotPart:: st_part_num++;




		
		print_part_type();
		type = integer_validation();
		
		
		description_ok = false;
		name_length_ok = false;
	}


	
	







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

void print_part_type() 
{
	int i;
	

	cout << "\nChoose part type:\n";
	for (i = 0; i < 5; i++)
	{
		cout << i + 1 << ": " << partType[i] << endl;
	}
	cout << "6: Previous menu\nSelection: ";
};