#ifndef ROBOTMODELS_H_
#define ROBOTMODELS_H_
#include "robotpart.h"

#include <iostream>
#include <vector>
#include <string>
#include <ctype.h>
#include <iomanip>


const string models_directory = "modelsVector.txt";

class RobotModels
{
public:
	

	int robot_number;
	string robot_name;
	double robot_price;

	vector<RobotPart*> parts_in_robot;


	double robot_price_calculator();
	void print_each_model(int id);
	void print_model_vector();

	void setValues(int newNum, string newName, double newPrice);
		
};


#endif // !ROBOTMODELS_H_

