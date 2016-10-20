#include "Order.h"

Order::Order(string associate, int order_num, double profit, double sp, int num, double total, int id) 
{
	order_associate = associate;
	order_number = order_num;
	order_profit_percent = profit;
	order_model_saleprice = sp;
	order_num_robots = num;
	order_total_cost = total;
	order_model_id = id;
};

void Order::printorderdetails() 
{
	cout << left << setw(15) << order_associate << "|" ;
	cout << left << setw(12) << order_model_id << "|";
	cout << left << setw(12) << order_number << "|";
	cout << left << setw(12) << order_num_robots << "|";
	cout << left << setw(12) << order_model_saleprice << "|";
	cout << left << setw(12) << order_total_cost << "|";

	cout << endl;


}
string Order::getAssociate()
{
	return order_associate;
}

void Order::saveOrder() 
{
	//Order newOrder(associate, order_num,profit_percent, model_saleprice, num_robots, order_cost, selection);
	ofstream orderFile;
	orderFile.open("orderVector.txt", ios::app);
	orderFile << order_associate << endl;
	orderFile << order_number << endl;
	orderFile << order_profit_percent << endl;
	orderFile << order_model_saleprice << endl;
	orderFile << order_num_robots << endl;
	orderFile << order_total_cost<< endl;
	orderFile << order_model_id << endl;
	
	orderFile << endl;

	orderFile.close();



}