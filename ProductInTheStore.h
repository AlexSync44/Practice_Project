#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "my_arrays.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;

struct Things
{
	string name;
	unsigned int quantity;
	unsigned int cost;
};

void ThingsTest();