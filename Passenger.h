#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "my_arrays.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

struct Passenger
{
	string name;
	string itemName;
	unsigned int weigth;
	unsigned int numLuggage;
};

void passengerTest();