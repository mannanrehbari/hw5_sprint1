#include "robotpart.h"



void Torso::setGenValues(string new_name, int new_num, int new_type, double new_weight, double new_cost, string new_description)
{
	part_num = new_num;
	
	
	part_name = new_name;	
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
void Torso::print_part(int part_index) 
{
	cout << left <<  setw(15) << part_name << "|";
	cout << left << setw(5) << part_index << "|";
	cout << right << setw(10) << part_num<< "|";
	cout << left << setw(15) <<  partTypeCopy[part_type -1] << "|";
	cout << right << setw(8) << part_weight << "|";
	cout << right << setw(8) << part_cost << "|";
	cout << left << setw(20) << part_description << "|";
	cout << left << "Bat.Comps: " << battery_comparts << "|";
	
	cout << endl;


}
void Torso::save_part(string fileAdd) 
{
	fstream outFile;
	outFile.open(fileAdd, ios::app);

	//general info
	outFile << part_type << endl;
	outFile << part_name << endl;
	outFile << part_num << endl;
	outFile << part_weight << endl;
	outFile << part_cost << endl;
	outFile << part_description << endl;

	//part-specific info
	outFile << battery_comparts << endl;

	outFile << endl;
	outFile.close();

}
int Torso::get_int_one() 
{
	return battery_comparts;
}




void Head::setGenValues(string new_name, int new_num, int new_type, double new_weight, double new_cost, string new_description)
{
	part_num = new_num;
	
	
	part_name = new_name;
	
	part_type = new_type;
	part_weight = new_weight;
	part_cost = new_cost;
	part_description = new_description;

}
void Head::print_part(int part_index) 
{
	cout << left << setw(15) << part_name << "|";
	cout << left << setw(5) << part_index << "|";
	cout << right << setw(10) << part_num << "|";
	cout << left << setw(15) << partTypeCopy[part_type - 1] << "|";
	cout << right << setw(8) << part_weight << "|";
	cout << right << setw(8) << part_cost << "|";
	cout << left << setw(20) << part_description << "|";
	
	cout << endl;
}
void Head::save_part(string fileAdd)
{
	fstream outFile;
	outFile.open(fileAdd, ios::app);

	//general info
	outFile << part_type << endl;
	outFile << part_name << endl;
	outFile << part_num << endl;	
	outFile << part_weight << endl;
	outFile << part_cost << endl;
	outFile << part_description << endl;

	//part-specific info
	

	outFile << endl;
	outFile.close();

}
int Head::get_int_one()
{
	return -1;
}


void Arm::setGenValues(string new_name, int new_num, int new_type, double new_weight, double new_cost, string new_description)
{
	part_num = new_num;
	
	
	part_name = new_name;
	part_type = new_type;
	part_weight = new_weight;
	part_cost = new_cost;
	part_description = new_description;

	

}
void Arm::set_arm_power(double new_arm_power) 
{
	arm_power = new_arm_power;
}
void Arm::print_part(int part_index)
{
	cout << left << setw(15) << part_name << "|";
	cout << left << setw(5) << part_index << "|";
	cout << right << setw(10) << part_num << "|";
	cout << left << setw(15) << partTypeCopy[part_type - 1] << "|";
	cout << right << setw(8) << part_weight << "|";
	cout << right << setw(8) << part_cost << "|";
	cout << left << setw(20) << part_description << "|";


	cout << endl;
	
}
void Arm::save_part(string fileAdd)
{
	fstream outFile;
	outFile.open(fileAdd, ios::app);

	//general info
	outFile << part_type << endl;
	outFile << part_name << endl;
	outFile << part_num << endl;	
	outFile << part_weight << endl;
	outFile << part_cost << endl;
	outFile << part_description << endl;

	//part-specific info
	outFile << arm_power << endl;

	outFile << endl;
	outFile.close();

}
int Arm::get_int_one()
{
	return -1;
}


void Battery::setGenValues(string new_name, int new_num, int new_type, double new_weight, double new_cost, string new_description)
{
	part_num = new_num;
	
	
	part_name = new_name;	
	part_type = new_type;

	part_weight = new_weight;
	part_cost = new_cost;
	part_description = new_description;

	

}
void Battery::setBattCap(double new_bat_cap) 
{
	battery_capacity = new_bat_cap;
}
void Battery::print_part(int part_index)
{
	cout << left << setw(15) << part_name << "|";
	cout << left << setw(5) << part_index << "|";
	cout << right << setw(10) << part_num << "|";
	cout << left << setw(15) << partTypeCopy[part_type - 1] << "|";
	cout << right << setw(8) << part_weight << "|";
	cout << right << setw(8) << part_cost << "|";
	cout << left << setw(20) << part_description << "|";
	cout << left << "Capacity: " << battery_capacity << "|";

	cout << endl;
	
}
void Battery::save_part(string fileAdd)
{
	fstream outFile;
	outFile.open(fileAdd, ios::app);

	//general info
	outFile << part_type << endl;
	outFile << part_name << endl;
	outFile << part_num << endl;	
	outFile << part_weight << endl;
	outFile << part_cost << endl;
	outFile << part_description << endl;

	//part-specific info
	outFile << battery_capacity << endl;

	outFile << endl;
	outFile.close();

}
int Battery::get_int_one()
{
	return -1;
}



void Locomotor::setGenValues(string new_name, int new_num, int new_type, double new_weight, double new_cost, string new_description)
{
	part_num = new_num;
	

	part_name = new_name;
	
	part_type = new_type;
	part_weight = new_weight;
	part_cost = new_cost;
	part_description = new_description;
}
void Locomotor::set_power_maxspeed(double newMaxSpeed, double newPower) 
{
	locomotor_maxspeed = newMaxSpeed;
	locomotor_power = newPower;
}
void Locomotor::print_part(int part_index)
{
	cout << left << setw(15) << part_name << "|";
	cout << left << setw(5) << part_index << "|";
	cout << right << setw(10) << part_num<< "|";
	cout << left << setw(15) << partTypeCopy[part_type - 1] << "|";
	cout << right << setw(8) << part_weight << "|";
	cout << right << setw(8) << part_cost << "|";
	cout << left << setw(20) << part_description << "|";
	cout << left << "MaxSpeed: " << locomotor_maxspeed << "MaxPower: " << locomotor_power << "|";

	cout << endl;
	
}
void Locomotor::save_part(string fileAdd)
{
	fstream outFile;
	outFile.open(fileAdd, ios::app);

	//general info
	outFile << part_type << endl;
	outFile << part_name << endl;
	outFile << part_num << endl;	
	outFile << part_weight << endl;
	outFile << part_cost << endl;
	outFile << part_description << endl;

	//part-specific info
	outFile << locomotor_maxspeed << endl;
	outFile << locomotor_power << endl;

	outFile << endl;
	outFile.close();

}
int Locomotor::get_int_one()
{
	return -1;
}