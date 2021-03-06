#include "controller.h"
#include "robotpart.h"
#include "RobotModels.h"
#include "Order.h"


vector<RobotPart*> myParts;
vector<RobotModels> myModels;
vector<Order> myOrders;

vector<string> associate_list;

void control()
{


	int selection;


	cout << "***** Welcome to Robbie Robot Shop *****\n\n";
	
	
	//reading existing data from files
	read_partvector();
	read_modelvector();
	read_ordervector();

	//associates ready
	associate_list.push_back("Haram Bey");
	associate_list.push_back("Wass Ennocent");
	


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

//THis function displays the reports(vectors, orders etc)
void report()
{
	int selection;
	cout << "\n---------------------------\n|Record of Parts, Models and Orders|\n---------------------------\n1: Print Parts\n2: Print Models\n3: Print Orders\n4: Main\nSelection: ";
	cin >> selection;

	while (selection != 4)
	{
		if (selection == 1)
		{
			print_part_vector();
		}
		else if (selection == 2)
		{
			list_model_vector();
		}
		else if (selection == 3) 
		{
			print_orders();
		}

		cout << "\n---------------------------\n|Record of Parts, Models and Orders|\n---------------------------\n1: Print Parts\n2: Print Models\n3: Print Orders\n4: Main\nSelection: ";
		cin >> selection;

	}



}

//These print Part and Model vectors respectively
void print_part_vector()
{
	cout << "\n\nPrinting Parts\n";
	cout << "\n-------------------------------------------------------------------------------------------------------\n";

	printf("%-15s|%-5s|%10s|%-15s|%8s|%8s|%-20s|%-20s|\n", "Partname", " ID", "Partnum", "PartType", "Weight", "Cost", "Description", "Other Details");
	cout << "\n-------------------------------------------------------------------------------------------------------\n";
	if (myParts.size() == 0)
	{
		cout << "\n No parts stored yet! \n\n";
	}
	else
	{
		for (unsigned int i = 0; i < myParts.size(); i++)
		{
			myParts[i]->print_part(i);
		}
		cout << endl;
	}






}
void list_model_vector()
{

	int selection;
	cout << "\n---------------------------\n";
	cout << "|   Available Models   |";
	cout << "\n---------------------------\n";
	cout << "Choose model to display parts (enter ID)\n";

	cout << "\n--------------------------------------------\n";
	printf("%-15s|%-5s|%-10s|%-10s|\n", " Name", " ID"," Number", " Price");
	cout << "--------------------------------------------\n";
	for (unsigned int j = 0; j < myModels.size(); j++)
	{
		myModels[j].print_each_model(j);
	}

	if (myModels.size() == 0)
	{
		cout << "\n\n\tNo models in vector!\n\n";
		return;
	}

	cout << "\nSelection (ID):";
	selection = integer_validation(); // it returns a valid int

	if (selection >= myModels.size() || selection <0) 
	{
		cout << "Wrong Input! ID out of range\n";
		return;
	}

	// The next lines will print the vector of constituent parts 
	cout << "\nPrinting parts in model no: " << selection << endl;
	cout << "=======================================================================================================\n";


	printf("%-15s|%-5s|%10s|%-15s|%8s|%8s|%-20s|%-20s|\n", "Partname", " ID", "Partnum", "PartType", "Weight", "Cost", "Description", "Other Details");
	cout << "=======================================================================================================\n";

	myModels[selection].print_model_vector();
	cout << "=======================================================================================================\n\n";



}
void print_orders() 
{
	cout << "\n-----------------\n";
	cout << "Choose associate:\n";
	cout << "\n-----------------\n";
	for (unsigned int p = 0; p < associate_list.size(); p++)
	{
		cout << p << ": " << associate_list[p] << endl;
	}

	cout << "\nSelection: ";
	int select_SA = integer_validation();
	if (select_SA >= associate_list.size() || select_SA <0)
	{
		cout << "Invalid Input!\n";
		return;
	}



	cout << "\n\nOrder details in table\n";
	cout << "----------------------------------------------------------------------------------\n";
	printf("%-15s|%-12s|%-12s|%-12s|%-12s|%-12s|\n", "Associate", "Model_ID","Order #", "#ofBots", "Sale_$", "total_cost");

	cout << "----------------------------------------------------------------------------------\n";

	
	


	if (myOrders.size() == 0) 
	{
		cout << "No orders yet!" << endl;
		return;
	}

	for (unsigned int k = 0; k < myOrders.size(); k++) 
	{
		if (myOrders[k].getAssociate() == associate_list[select_SA]) 
		{
			myOrders[k].printorderdetails();
		}
		
	}
	cout << "\nEnter the model id for details about model and parts\n";
	int  for_details = integer_validation();
	if (for_details >= myModels.size() || for_details <0)
	{
		cout << "Invalid input!\n";
		return;
	}
	/*
	cout << left << setw(15) << robot_name << "|";
	cout << left << setw(5) << id << "|";
	cout << left << setw(10) << robot_number << "|";
	cout << left << setw(10) << robot_price << "|"<< endl;
	
	*/
	cout << "-------------------------------------\n";
	printf("%-14s|%-5s|%-10s|%-10s|\n", "Bot Name", "ID" , "Bot_No", "Bot_Price");
	cout << "-------------------------------------\n";
	myModels[for_details].print_each_model(for_details);

	cout << "\n\nPrinting Bot Components\n";
	
	cout << "\n-------------------------------------------------------------------------------------------------------\n";

	printf("%-15s|%-5s|%10s|%-15s|%8s|%8s|%-20s|%-20s|\n", "Partname", " ID", "Partnum", "PartType", "Weight", "Cost", "Description", "Other Details");
	cout << "\n-------------------------------------------------------------------------------------------------------\n";
	for (unsigned int p = 0; p < myModels[for_details].parts_in_robot.size(); p++) 
	{
		myModels[for_details].parts_in_robot[p]->print_part(p);
	}

}


//THese help printing repeatedly used functions
void print_main()
{
	cout << "----------\n|  Main  |\n----------\n";
	cout << "1: Create Parts, Models and Orders\n";
	cout << "2: Display inventory/ SA reports \n";
	cout << "3: Quit\n";

}
void print_create()
{
	cout << "\n------------\n| Create |\n------------\n";
	cout << "1: Robot Part\n";
	cout << "2: Robot Model\n";
	cout << "3: Order\n";
	cout << "4: Previous Menu\n";

}

//This next function creates new parts
void create_part()
{
	//general description
	string new_name;


	double new_weight;
	double new_cost;
	string new_description;
	int new_num;
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
		cout << "\n\n==================\nAdd a(n) " << partType[type - 1] << ":\n";


		cin.ignore();
		cin.clear();
		while (name_length_ok == false)
		{
			cout << "Part name: ";
			getline(cin, new_name);
			if (new_name.length() <= 15)
			{
				name_length_ok = true;
			}
			else { cout << "Enter name again! Max 15 characters\n"; }
		}

		cout << "Part number: ";
		new_num = integer_validation();




		cout << "Part weight: ";
		new_weight = double_validation();



		cout << "Part cost: ";
		new_cost = double_validation();





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
			while (1)
			{
				battery_compartments = double_validation();
				if (battery_compartments >= 1 && battery_compartments <= 3)
				{
					break;
				}
				else
				{
					cout << "Invalid Range!";
				}

			}



			Torso* new_torso = new Torso;
			new_torso->setGenValues(new_name, new_num, type, new_weight, new_cost, new_description);
			new_torso->setCompart(battery_compartments);

			new_torso->save_part(parts_directory);
			myParts.push_back(new_torso);
			cout << "New torso added!\n\n";



		}
		else if (type == 2)
		{
			Head * new_head = new Head;
			new_head->setGenValues(new_name, new_num, type, new_weight, new_cost, new_description);
			new_head->save_part(parts_directory);
			myParts.push_back(new_head);
			cout << "New head added! \n\n";

		}
		else if (type == 3)
		{
			Arm * new_arm = new Arm;
			new_arm->setGenValues(new_name, new_num, type, new_weight, new_cost, new_description);
			cout << "Arm power: ";
			arm_power = double_validation();

			new_arm->set_arm_power(arm_power);
			new_arm->save_part(parts_directory);
			myParts.push_back(new_arm);
			cout << "New arm added! \n\n";
		}
		else if (type == 4)
		{
			Battery * new_battery = new Battery;
			new_battery->setGenValues(new_name, new_num, type, new_weight, new_cost, new_description);
			cout << "Battery capacity: ";
			battery_capacity = double_validation();
			
			new_battery->setBattCap(battery_capacity);
			new_battery->save_part(parts_directory);
			myParts.push_back(new_battery);
			cout << "New battery added! \n\n";

		}
		else if (type == 5)
		{
			Locomotor* new_locomotor = new Locomotor;

			cout << "Locomotor max speed: ";
			loco_maxspeed = double_validation();
			cout << "Locomotor power: ";
			loco_power = double_validation();

			new_locomotor->setGenValues(new_name, new_num, type, new_weight, new_cost, new_description);
			new_locomotor->set_power_maxspeed(loco_maxspeed, loco_power);

			new_locomotor->save_part(parts_directory);
			myParts.push_back(new_locomotor);
			cout << "New locomotor added!\n\n";


		}
		





		print_part_type();
		type = integer_validation();


		description_ok = false;
		name_length_ok = false;
	}


}
void create_model()
{
	ofstream outFile;
	outFile.open(models_directory, ios::app);


	RobotModels newModel;
	string bot_name;
	double bot_price;
	int bot_num;

	int  battery_count = 0, torso_battery;

	int selection;
	cout << "=====================";
	cout << "\n\nSelect a torso: (enter ID)\n\n";
	selection = list_type_parts(1);
	newModel.parts_in_robot.push_back(myParts[selection]);
	torso_battery = myParts[selection]->get_int_one();
	

	cout << "=====================";
	cout << "\n\nSelect a head: (enter ID)\n\n";
	selection = list_type_parts(2);
	newModel.parts_in_robot.push_back(myParts[selection]);

	cout << "=====================";
	cout << "\n\nSelect an arm: (enter ID)\n\n";
	selection = list_type_parts(3);
	newModel.parts_in_robot.push_back(myParts[selection]);
	//asking for another arm
	cout << "Adding one more arm?\n1: Yes\n2: No\nSelection: ";
	selection = integer_validation();
	if (selection == 1) 
	{
		cout << "\n\nSelect another arm: (enter ID)\n\n";
		selection = list_type_parts(3);
		newModel.parts_in_robot.push_back(myParts[selection]);
	}


	cout << "=====================";
	
	do 
	{
		cout << "\n\nSelect a battery: (enter ID)\n\n";
		selection = list_type_parts(4);
		newModel.parts_in_robot.push_back(myParts[selection]);
		battery_count++;
		if (battery_count == torso_battery)break;

		cout << "Add another battery?\n1: Yes\n2: No\nSelection: ";
		selection = integer_validation();
		if (selection == 2) 
		{
			break;
		}

	} while (battery_count < torso_battery);
	


	cout << "=====================";
	cout << "\n\nSelect a locomotor: (enter ID)\n\n";
	selection = list_type_parts(5);
	newModel.parts_in_robot.push_back(myParts[selection]);

	cout << "Enter name for bot: ";
	getline(cin, bot_name);
	bot_price = newModel.robot_price_calculator();
	cout << "Enter robot number: ";
	bot_num = integer_validation();

	newModel.setValues(bot_num, bot_name, bot_price);

	outFile << bot_name << endl;
	outFile << bot_num << endl;
	outFile << bot_price << endl;
	
	for (unsigned int p = 0; p < newModel.parts_in_robot.size(); p++) 
	{
		newModel.parts_in_robot[p]->save_part(models_directory);
	}


	outFile << "END_OF_MODEL" << endl;
	cout << "Model added to vector!\n";
	myModels.push_back(newModel);
	outFile.close();



}

//This returns validated doubles
double double_validation()
{
	double valueTR;
	while (1) {
		if (cin >> valueTR) {
			// valid number
			break;
		}
		else {
			// not a valid number
			cout << "Invalid Input! Please input a numerical value." << endl;
			cin.clear();
			while (cin.get() != '\n'); // empty loop
		}
	}
	return valueTR;


}

//THis function prints actual parts (not part types)
int list_type_parts(int type)
{
	cout << "=======================================================================================================\n";
	printf("%-15s|%-5s|%10s|%-15s|%8s|%8s|%-20s|%-20s|\n", "Partname", "ID", "Partnum", "PartType", "Weight", "Cost", "Description", "Other Details");
	cout << "=======================================================================================================\n";
	int selection;
	for (unsigned int i = 0; i < myParts.size(); i++)
	{
		if (myParts[i]->part_type == type)
		{
			myParts[i]->print_part(i);
		}

	}
	cout << "Select by ID: ";
	cin >> selection;
	cin.ignore();
	return selection;

}


//These functions will create an order
void order_helper()
{
	
	string associate;
	int order_num = myOrders.size();

	
	// limited the number of associates to two
	cout << "Choose associate:\n";
	for (unsigned int p = 0; p < associate_list.size(); p++) 
	{
		cout << p  << ": " << associate_list[p] <<endl;
	}
	cout << "Selection: ";
	int select_SA = integer_validation();
	if (select_SA >= associate_list.size() || select_SA <0)
	{
		cout << "Invalid Input!\n";
		return;
	}

	associate = associate_list[select_SA];
	double profit_percent;
	double model_saleprice;
	int num_robots;
	double order_cost;
	
	int selection;
	cout << "\nChoose a model for order: (enter ID)\n";

	cout << "---------------------------------------\n";
	printf("%-15s|%-5s|%-10s|%-10s|\n", " Name", " ID", " Number", " Price");
	cout << "---------------------------------------\n";
	for (unsigned int j = 0; j < myModels.size(); j++)
	{
		myModels[j].print_each_model(j);
	}

	if (myModels.size() == 0)
	{
		cout << "\n\n\tNo models available!\n\n";
		return;
	}
	cout << "---------------------------------------\n";
	cout << "Selection:";
	selection = integer_validation(); // it returns a valid int

	if (selection >= myModels.size() || selection <0) 
	{
		cout << "Invalid Input!\n";
		return;
	}


	cout << "Profit percent on the model : ";
	profit_percent = double_validation();
	cin.ignore();

	model_saleprice = (myModels[selection].robot_price *(profit_percent / 100.0)) + myModels[selection].robot_price;


	// The next lines will print the vector of constituent parts 
	cout << "\nDetails of model no: " << selection << endl;
	cout << "=======================================================================================================\n";

	printf("%-15s|%-5s|%10s|%-15s|%8s|%8s|%-20s|%-20s|\n", "Partname", " ID","Partnum", "PartType", "Weight", "Cost", "Description", "Other Details");
	cout << "=======================================================================================================\n";

	myModels[selection].print_model_vector();
	cout << "=======================================================================================================\n\n";

	cout << "Total Robot price per robot: " << model_saleprice << endl;
	cout << "Enter the quantity of robots: ";
	num_robots = integer_validation();

	order_cost = num_robots * model_saleprice;
	cout << "Your total cost of order is: " << order_cost << endl;

	Order newOrder(associate, order_num,profit_percent, model_saleprice, num_robots, order_cost, selection);
	myOrders.push_back(newOrder);
	newOrder.saveOrder();

	
	cout << "Order Successfully created!\n";





}
void create_order()
{
	cout << "\n-----------------\n| Create a new order|\n------------------\n ";
	order_helper();

}


//This function below returns validated ints
int integer_validation()
{
	int num;
	while (1) {
		if (cin >> num) {
			// valid number
			break;
		}
		else {
			// not a valid number
			cout << "Invalid Input! Please input a numerical value." << endl;
			cin.clear();
			while (cin.get() != '\n'); // empty loop
		}
	}
	return num;

}

//This function prints part types
void print_part_type()
{
	int i;


	cout << "\n----------------\n| Select Part Type|\n----------------\n";
	for (i = 0; i < 5; i++)
	{
		cout << i + 1 << ": " << partType[i] << endl;
	}
	cout << "6: Previous menu\nSelection: ";
};



//These two read the data from text files into respective vectors
void read_partvector()
{
	//This declaration order is reflecting how each item is stored and read from file
	string new_name;

	int new_num;
	int new_type;

	double new_weight;
	double new_cost;

	string  new_description;


	//to hold eachLine
	string eachLine;

	//part-specific details
	double new_loco_maxspeed;
	double new_loco_power;

	double new_battery_capacity;

	double new_armpower;

	double new_batt_comparts;

	//opening file for reading
	ifstream readParts;
	readParts.open(parts_directory);

	while (getline(readParts, eachLine))
	{
		
		new_type = atoi(eachLine.c_str()); //read type number; change into int
		
		getline(readParts, eachLine);
		new_name = eachLine;

		getline(readParts, eachLine);
		new_num = atoi(eachLine.c_str()); //read part number; change into int
		

		getline(readParts, eachLine);
		new_weight = atof(eachLine.c_str()); //change weight into a double
		getline(readParts, eachLine);
		new_cost = atof(eachLine.c_str()); //change cost into a double

		getline(readParts, eachLine);
		new_description = eachLine; //read the description for part

		// "torso", "head", "arm", "battery", "locomotor"
		//read 

		if (new_type == 1)
		{
			getline(readParts, eachLine);
			new_batt_comparts = atof(eachLine.c_str());

			Torso* new_torso = new Torso;
			new_torso->setGenValues(new_name, new_num, new_type, new_weight, new_cost, new_description);
			new_torso->setCompart(new_batt_comparts);

			myParts.push_back(new_torso);

		}
		else if (new_type == 2)
		{
			Head * new_head = new Head;
			new_head->setGenValues(new_name, new_num, new_type, new_weight, new_cost, new_description);
			myParts.push_back(new_head);

		}
		else if (new_type == 3)
		{
			getline(readParts, eachLine);
			new_armpower = atof(eachLine.c_str());
			Arm * new_arm = new Arm;
			new_arm->setGenValues(new_name, new_num, new_type, new_weight, new_cost, new_description);
			new_arm->set_arm_power(new_armpower);
			myParts.push_back(new_arm);

		}
		else if (new_type == 4)
		{
			getline(readParts, eachLine);
			new_battery_capacity = atof(eachLine.c_str());

			Battery * new_battery = new Battery;
			new_battery->setGenValues(new_name, new_num, new_type, new_weight, new_cost, new_description);
			new_battery->setBattCap(new_battery_capacity);
			myParts.push_back(new_battery);

		}
		else if (new_type == 5)
		{

			getline(readParts, eachLine);
			new_loco_maxspeed = atof(eachLine.c_str());

			getline(readParts, eachLine);
			new_loco_power = atof(eachLine.c_str());


			Locomotor* new_locomotor = new Locomotor;
			new_locomotor->setGenValues(new_name, new_num, new_type, new_weight, new_cost, new_description);
			new_locomotor->set_power_maxspeed(new_loco_maxspeed, new_loco_power);

			myParts.push_back(new_locomotor);


		}

		//Throw away the empty line
		getline(readParts, eachLine);
		


	}

	readParts.close();




}

void read_modelvector() 
{
	
	string new_bot_name;
	int new_bot_num;
	double new_bot_price;
	

	//details for each part
	string new_name;

	int new_num, new_type;

	double new_weight, new_cost;

	string  new_description;


	//to hold eachLine
	string eachLine, lineEnd;

	//part-specific details
	double new_loco_maxspeed;
	double new_loco_power;

	double new_battery_capacity;

	double new_armpower;

	int new_batt_comparts;
	

	//opening file for reading
	ifstream readModel;
	readModel.open(models_directory);
	while (getline(readModel, eachLine)) 
	{
		RobotModels newModel;

		new_bot_name = eachLine;

		getline(readModel, eachLine);
		new_bot_num = atoi(eachLine.c_str());

		getline(readModel, eachLine);
		new_bot_price = atof(eachLine.c_str());

		getline(readModel, eachLine);

		while (eachLine != "END_OF_MODEL") 
		{
			

			//This pushes one part to new model
			while (eachLine != "") 
			{
				new_type= atoi(eachLine.c_str());
				
				getline(readModel, eachLine);
				new_name = eachLine;

				getline(readModel, eachLine);
				new_num = atoi(eachLine.c_str());

				getline(readModel, eachLine);
				new_weight = atof(eachLine.c_str());

				getline(readModel, eachLine);
				new_cost = atof(eachLine.c_str());

				getline(readModel, eachLine);
				new_description = eachLine;
				
				if (new_type == 1) 
				{
					Torso *newTor = new Torso;
					getline(readModel, eachLine);
					new_batt_comparts = atoi(eachLine.c_str());
					newTor->setGenValues(new_name, new_num, new_type, new_weight, new_cost, new_description);
					newTor->setCompart(new_batt_comparts);
					newModel.parts_in_robot.push_back(newTor);
				}
				else if (new_type == 2)
				{
					Head * newHead = new Head;
					newHead->setGenValues(new_name, new_num, new_type, new_weight, new_cost, new_description);
					newModel.parts_in_robot.push_back(newHead);
				}
				else if (new_type == 3)
				{
					getline(readModel, eachLine);
					new_armpower = atof(eachLine.c_str());
					Arm * newArm = new Arm;
					newArm->setGenValues(new_name, new_num, new_type, new_weight, new_cost, new_description);
					newArm->set_arm_power(new_armpower);
					newModel.parts_in_robot.push_back(newArm);

				}
				else if (new_type == 4)
				{
					getline(readModel, eachLine);
					new_battery_capacity = atof(eachLine.c_str());

					Battery * newBattery = new Battery;
					newBattery->setGenValues(new_name, new_num, new_type, new_weight, new_cost, new_description);
					newBattery->setBattCap(new_battery_capacity);

					newModel.parts_in_robot.push_back(newBattery);

				}
				else if (new_type == 5)
				{
					getline(readModel, eachLine);
					new_loco_maxspeed = atof(eachLine.c_str());
					
					getline(readModel, eachLine);
					new_loco_power = atof(eachLine.c_str());

					Locomotor * newLocomotor = new Locomotor;
					newLocomotor->setGenValues(new_name, new_num, new_type, new_weight, new_cost, new_description);
					newLocomotor->set_power_maxspeed(new_loco_maxspeed, new_loco_power);

					newModel.parts_in_robot.push_back(newLocomotor);

				}
				getline(readModel, eachLine);

			}

			
			getline(readModel, eachLine);
		}
		newModel.robot_name = new_bot_name;
		newModel.robot_number = new_bot_num;
		newModel.robot_price = new_bot_price;
		
		myModels.push_back(newModel);

		


	}

	

	
	readModel.close();



}
void read_ordervector() 
{

	ifstream orderFile;
	orderFile.open("orderVector.txt", ios::app);
	string order_associate;


	double order_profit_percent;
	double order_model_saleprice;
	int order_num_robots;
	double order_total_cost;
	int order_number;
	int order_model_id;
	/*
	orderFile << order_associate << endl;
	orderFile << order_number << endl;
	orderFile << order_profit_percent << endl;
	orderFile << order_model_saleprice << endl;
	orderFile << order_num_robots << endl;
	orderFile << order_total_cost<< endl;
	orderFile << order_model_id << endl;
	*/
	string eachLine;
	while (getline(orderFile, eachLine)) 
	{
		while (eachLine != "") 
		{
			order_associate = eachLine;

			getline(orderFile, eachLine);
			order_number = atoi(eachLine.c_str());
			
			getline(orderFile, eachLine);
			order_profit_percent = atof(eachLine.c_str());

			getline(orderFile, eachLine);
			order_model_saleprice = atof(eachLine.c_str());

			getline(orderFile, eachLine);
			order_num_robots = atoi(eachLine.c_str());

			getline(orderFile, eachLine);
			order_total_cost = atof(eachLine.c_str());

			getline(orderFile, eachLine);
			order_model_id= atoi(eachLine.c_str());

			getline(orderFile, eachLine);
		}
		Order read_order(order_associate, order_number, order_profit_percent, order_model_saleprice, order_num_robots, order_total_cost, order_model_id);
		myOrders.push_back(read_order);

	}

	orderFile.close();


}

	


