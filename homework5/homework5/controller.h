#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>


using namespace std;

const string partType[] = { "torso", "head", "arm", "battery", "locomotor" };

void control();

//for creating instances 
void create();
void create_part(); //will create a part instance and add it to part vector
double double_validation();

void create_model();
int list_type_parts(int type);

void order_helper();

void create_order();

void report();


void print_main();
void print_create();
void print_part_type();
void print_part_vector();
void list_model_vector();
void print_orders();
//to ensure integer input is valid 
// not thoroughly implemented
int integer_validation();


//File io for vector of objects

void read_partvector();
void read_modelvector();
void read_ordervector();

#endif // !1

