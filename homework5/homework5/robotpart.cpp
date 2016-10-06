#include "robotpart.h"

void Torso::setGenValues(string new_name, int new_number, int new_type, double new_weight, double new_cost, string new_description)
{
	part_name = new_name;
	part_number = new_number;
	part_type = new_type;
	part_weight = new_weight;
	part_cost = new_cost;
	part_description = new_description;

	


}

void Torso::setCompart(int newComparts) 
{
	if (newComparts >=1 && newComparts <=3  ) 
	{
		battery_comparts = newComparts;

	}
	else { battery_comparts = -1; }
	
}

void Head::setGenValues(string new_name, int new_number, int new_type, double new_weight, double new_cost, string new_description)
{
	part_name = new_name;
	part_number = new_number;
	part_type = new_type;
	part_weight = new_weight;
	part_cost = new_cost;
	part_description = new_description;

}

void Arm::setGenValues(string new_name, int new_number, int new_type, double new_weight, double new_cost, string new_description)
{
	part_name = new_name;
	part_number = new_number;
	part_type = new_type;
	part_weight = new_weight;
	part_cost = new_cost;
	part_description = new_description;

	

}

void Battery::setGenValues(string new_name, int new_number, int new_type, double new_weight, double new_cost, string new_description)
{
	part_name = new_name;
	part_number = new_number;
	part_type = new_type;
	part_weight = new_weight;
	part_cost = new_cost;
	part_description = new_description;

	

}
void Locomotor::setGenValues(string new_name, int new_number, int new_type, double new_weight, double new_cost, string new_description)
{
	part_name = new_name;
	part_number = new_number;
	part_type = new_type;
	part_weight = new_weight;
	part_cost = new_cost;
	part_description = new_description;
}