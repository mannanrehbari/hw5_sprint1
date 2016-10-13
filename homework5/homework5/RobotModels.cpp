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