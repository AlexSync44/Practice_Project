#pragma once
#include <iostream>
#include <climits>

using std::cout;
using std::cin;
using std::string;

void laboratoryWork№3();
void ticTacToe();

template<typename DataType>
void printBitsOfIntegral(DataType number)
{

	//TO DO
	// большое значение убрать старший бит
	cout << number << ':';
	for (int i = 8 * sizeof(DataType); i >= 0; i--)
	{
		if (i % 4 == 0)
		{
			cout << ((number >> i) & 1) << ' ';
		}
		else
		{
			cout << ((number >> i) & 1);
		}
	}
}