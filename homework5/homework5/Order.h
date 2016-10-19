#ifndef ASSOCIATE_H_
#define ASSOCIATE_H_

#include <string>
#include <ctype.h>
#include <iomanip>
#include <iostream>
using namespace std;

const string current_associates[] = {"Haram Bey" , "Wass Ennocent"};

class Order 
{
	string order_associate;


	double order_profit_percent;
	double order_model_saleprice;
	int order_num_robots;
	double order_total_cost;

	int order_model_id;

public:
	Order(string associate, double profit, double sp, int num, double total, int id);


};


#endif // !ASSOCIATE_H_

