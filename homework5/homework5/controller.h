#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <iostream>
#include <string>
#include <vector>
using namespace std;

const string partType[] = { "torso", "head", "arm", "battery", "locomotor" };

void control();

//for creating instances 
void create();
void create_part(); //will create a part instance and add it to part vector
void create_model();
void create_order();

void report();


void print_main();
void print_create();
void print_part_type();

//to ensure integer input is valid 
// not thoroughly implemented
int integer_validation();

#endif // !1

