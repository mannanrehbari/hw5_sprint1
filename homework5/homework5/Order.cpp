#include "Order.h"

Order::Order(string associate, double profit, double sp, int num, double total, int id) 
{
	order_associate = associate;
	order_profit_percent = profit;
	order_model_saleprice = sp;
	order_num_robots = num;
	order_total_cost = total;
	order_model_id = id;
};