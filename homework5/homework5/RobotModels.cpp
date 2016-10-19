#include "RobotModels.h"



double RobotModels::robot_price_calculator() 
{
	double total_price = 0;

	for (unsigned int i = 0; i < parts_in_robot.size(); i++) 
	{
		total_price += parts_in_robot[i]->part_cost;
	}
	return total_price;
}

void RobotModels::print_each_model(int id) 
{
	cout << left << setw(15) << robot_name << "|";
	cout << left << setw(5) << id << "|";
	cout << left << setw(10) << robot_number << "|";
	cout << left << setw(10) << robot_price << "|"<< endl; 


}

void RobotModels::setValues(int newNum, string newName, double newPrice) 
{
	robot_name = newName;
	robot_number = newNum;
	robot_price = newPrice;

};

void RobotModels::print_model_vector() 
{
	
	for (unsigned int k = 0; k < parts_in_robot.size(); k++) 
	{
		parts_in_robot[k]->print_part(k);
	}


}

