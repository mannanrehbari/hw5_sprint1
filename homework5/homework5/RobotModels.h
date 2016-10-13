#ifndef ROBOTMODELS_H_
#define ROBOTMODELS_H_
#include "robotpart.h"



class RobotModels
{
public:
	static int st_model_num;
	string robot_name;
	double robot_price;

	vector<RobotPart*> parts_in_robot;
	double robot_price_calculator();
		
};


#endif // !ROBOTMODELS_H_

