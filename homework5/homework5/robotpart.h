#ifndef ROBOTPART_H_
#define ROBOTPART_H_

#include <iostream>
#include <fstream>

#include <vector>
#include <string>
#include <ctype.h>
#include <iomanip>


using namespace std;

//these constant strings are not supposed to change at any point in the lifecycle of this program
const string partTypeCopy[] = { "torso", "head", "arm", "battery", "locomotor" };
const string parts_directory = "partsVector.txt";

class RobotPart
{
public:
	
	
	string part_name;
	int part_num;
	int part_type;
	double part_weight;
	double part_cost;
	string part_description;
	
	virtual void setGenValues(string new_name, int new_num, int new_type, double new_weight, double new_cost, string new_description) = 0;
	virtual void print_part(int part_index) = 0;
	virtual void save_part(string fileAdd) = 0;
	virtual int get_int_one() = 0;

};



class Torso : public RobotPart
{
public:
	int battery_comparts;
	void setGenValues(string new_name, int new_num, int new_type, double new_weight, double new_cost, string new_description) override;
	void setCompart(int newComparts);
	void print_part(int part_index) override;
	void save_part(string fileAdd) override;
	int get_int_one() override;
	
	
};

class Head : public RobotPart
{
public:
	
	void print_part(int part_index) override;
	void save_part(string fileAdd) override;

	//Could have used a constructor 
	void setGenValues(string new_name, int new_num, int new_type, double new_weight, double new_cost, string new_description) override;

	//This function will not be used for this class objects, even though it can be but it wont make any sense
	int get_int_one() override;
};


class Arm : public RobotPart
{
public:
	double arm_power;

	void print_part(int part_index) override;
	void save_part(string fileAdd) override;

	void set_arm_power(double new_arm_power);
	void setGenValues(string new_name, int new_num, int new_type, double new_weight, double new_cost, string new_description) override;

	//This function will not be used for this class objects, even though it can be but it wont make any sense
	int get_int_one() override;
};

class Battery : public RobotPart
{
public:
	double battery_capacity;

	void print_part(int part_index) override;
	void save_part(string fileAdd) override;

	void setBattCap(double new_bat_cap);
	void setGenValues(string new_name, int new_num, int new_type, double new_weight, double new_cost, string new_description) override;

	//This function will not be used for this class objects, even though it can be but it wont make any sense
	int get_int_one() override;
};

class Locomotor : public RobotPart
{
public:
	double locomotor_maxspeed;
	double locomotor_power;

	
	void print_part(int part_index) override;
	void save_part(string fileAdd) override;

	void set_power_maxspeed(double newMaxSpeed, double newPower);
	void setGenValues(string new_name, int new_num, int new_type, double new_weight, double new_cost, string new_description) override;

	//This function will not be used for this class objects, even though it can be but it wont make any sense
	int get_int_one() override;
};

#endif // !ROBOTPART_H_



