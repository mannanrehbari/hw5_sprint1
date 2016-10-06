#ifndef ROBOTPART_H_
#define ROBOTPART_H_

#include <iostream>
#include <vector>

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

	virtual void getValues() = 0;


};

class Torso : public RobotPart
{
public:
	int battery_comparts;
	void getValues();
};

class Head : public RobotPart
{
public:
	void getValues();
};


class Arm : public RobotPart
{
public:
	double power_arm;
	void getValues();
};

class Battery : public RobotPart
{
public:
	double energy_capacity;
	void getValues();
};

class Locomotor : public RobotPart
{
public:
	double max_op_speed;
	void getValues();
};

#endif // !ROBOTPART_H_



