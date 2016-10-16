#ifndef ROBOTMODELS_H_
#define ROBOTMODELS_H_
#include "robotpart.h"

#include <iostream>
#include <vector>
#include <string>
#include <ctype.h>
#include <iomanip>



class RobotModels
{
public:
	static int st_model_num;

	int robot_number;
	string robot_name;
	double robot_price;

	vector<RobotPart*> parts_in_robot;
	double robot_price_calculator();
	void print_each_model();
	void print_model_vector();

	void setValues(int newNum, string newName, double newPrice);
		
};


#endif // !ROBOTMODELS_H_

