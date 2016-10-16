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
	static int st_part_num;
	
	string part_name;
	int part_num;
	int part_type;
	double part_weight;
	double part_cost;
	string part_description;
	
	virtual void setGenValues(string new_name, int new_type, double new_weight, double new_cost, string new_description) = 0;
	virtual void print_part() = 0;
	virtual void save_part() = 0;

};



class Torso : public RobotPart
{
public:
	int battery_comparts;
	virtual void setGenValues(string new_name, int new_type, double new_weight, double new_cost, string new_description);
	void setCompart(int newComparts);
	virtual void print_part();
	virtual void save_part();
	
	
	
};

class Head : public RobotPart
{
public:
	
	virtual void print_part();
	virtual void save_part();


	virtual void setGenValues(string new_name, int new_type, double new_weight, double new_cost, string new_description);
};


class Arm : public RobotPart
{
public:
	double arm_power;

	virtual void print_part();
	virtual void save_part();

	void set_arm_power(double new_arm_power);
	virtual void setGenValues(string new_name, int new_type, double new_weight, double new_cost, string new_description);
};

class Battery : public RobotPart
{
public:
	double battery_capacity;

	virtual void print_part();
	virtual void save_part();

	void setBattCap(double new_bat_cap);
	virtual void setGenValues(string new_name, int new_type, double new_weight, double new_cost, string new_description);
};

class Locomotor : public RobotPart
{
public:
	double locomotor_maxspeed;
	double locomotor_power;

	
	virtual void print_part();
	virtual void save_part();

	void set_power_maxspeed(double newMaxSpeed, double newPower);
	virtual void setGenValues(string new_name, int new_type, double new_weight, double new_cost, string new_description);
};

#endif // !ROBOTPART_H_



