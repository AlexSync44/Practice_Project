#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "my_arrays.h"


using std::cout;
using std::cin;
using std::endl;
using std::string;

struct Cryptoprotection
{
	string devName;
	string algoritName;
	bool license;
	double numVersion;
};

void cryptoTest();