#ifndef ASSOCIATE_H_
#define ASSOCIATE_H_

#include <string>
#include <ctype.h>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;



class Order 
{
	string order_associate;


	double order_profit_percent;
	double order_model_saleprice;
	int order_num_robots;
	double order_total_cost;
	int order_number;
	int order_model_id;

public:
	Order(string associate, int order_num,double profit, double sp, int num, double total, int id);
	
	void printorderdetails();
	void saveOrder();
	string getAssociate();
};


#endif // !ASSOCIATE_H_

