#ifndef ROBOTPART_H_
#define ROBOTPART_H_

#include <iostream>
#include <vector>
#include <ctype.h>
using namespace std;





class RobotPart
{
protected:
	string part_name;
	int part_number;
	int part_type;
	double part_weight;
	double part_cost;
	string part_description;

	virtual void setGenValues(string new_name, int new_number, int new_type, double new_weight, double new_cost, string new_description) = 0;


};

class Torso : public RobotPart
{
public:
	int battery_comparts;
	virtual void setGenValues(string new_name, int new_number, int new_type, double new_weight, double new_cost, string new_description);
	void setCompart(int newComparts);
};

class Head : public RobotPart
{
public:
	virtual void setGenValues(string new_name, int new_number, int new_type, double new_weight, double new_cost, string new_description);
};


class Arm : public RobotPart
{
public:
	double arm_power;
	virtual void setGenValues(string new_name, int new_number, int new_type, double new_weight, double new_cost, string new_description);
};

class Battery : public RobotPart
{
public:
	double battery_capacity;
	void setBattCap(double new_bat_cap);
	virtual void setGenValues(string new_name, int new_number, int new_type, double new_weight, double new_cost, string new_description);
};

class Locomotor : public RobotPart
{
public:
	double locomotor_maxspeed;
	double locomotor_power;
	void set_power_maxspeed(double newMaxSpeed, double newPower);
	virtual void setGenValues(string new_name, int new_number, int new_type, double new_weight, double new_cost, string new_description);
};

#endif // !ROBOTPART_H_



