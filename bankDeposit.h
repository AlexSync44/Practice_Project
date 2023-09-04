#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "my_arrays.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

struct Deposit
{
	string nameDepositors;
	string nameDeposit;
	string currency;
	unsigned int depositAmount;
	float interestRate;
};

void depositTest();