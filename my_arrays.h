#pragma once
#include <vector>
#include "my_sorts.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;


template<typename DataType>
void fillArr(DataType* arr, int size, int min = 0, int max = 100)
{
	if (!arr)
	{
		return;
	}

	long int static i = 1;
	srand(time(0) * i++);

	for (int i(0); i < size; ++i)
	{
		arr[i] = DataType(min + rand() % (max - min + 1));
	}
}

template<typename DataType>
void printArr(DataType* arr, int size, const char* title = "")
{
	if (!arr)
	{
		return;
	}

	cout << title << "\n";

	for (int i(0); i < size; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}

template<typename DataType>
void printArr(DataType* arr, int size, std::ostream& out, char sep = ' ')
{
	if (!arr || !size)
	{
		return;
	}
	
	if (out.bad())
		return;

	for (int i(0); i < size; ++i)
	{
		out << arr[i] << sep;
	}
}

template<typename DataType>
DataType sumArr(DataType* numbers, unsigned size)
{
	if (!numbers)
	{
		return -1;
	}

	DataType sum = 0;
	for (size_t i = 0; i < size; i++)
	{
		sum += numbers[i];
	}

	return sum;
}

template<typename DataType>
void inputArr(DataType* arr, int size)
{
	if (!arr)
	{
		return;
	}

	for (int i(0); i < size; ++i)
	{
		while (!(cin >> arr[i]))
		{
			cin.clear();
			cin.ignore();
			cout << "\nБыл некорректный ввод: ";
		}
	}
}

template<typename DataType>
void inputArr(DataType* arr, unsigned size, std::istream& in)
{
	if (!arr || !size)
	{
		return;
	}

	if (in.bad())
		return;

	for (int i(0); i < size; ++i)
	{
		if (!in.eof())
		{
			in >> arr[i];
		}
		else
		{
			return;
		}
	}
}

template<typename DataType>
void fillArray(DataType arr[], unsigned size, int min = 0, int max = 100)
{
	if (!arr)
	{
		return;
	}

	long int static i = 1;
	srand(time(0) * i++);

	for (size_t i = 0; i < size; i++)
	{
		arr[i] = DataType(min + rand() % (max - min + 1));
	}
}

template<typename DataType>
void clearMemory(DataType*& arr)
{
	if (!arr)
	{
		return;
	}

	delete[]arr;
	arr = nullptr;
}

template<typename DataType>
void allocateMemory(DataType*& arr, int n)
{
	if (arr)
	{
		clearMemory(arr);
	}

	arr = new DataType[n];
}

template<typename T>
T findMin(T* arr, unsigned size)
{
	if (!arr)
	{
		return -1;
	}

	T min = arr[0];
	for (size_t i = 1; i < size; i++)
	{
		if (arr[i] < min)
			min = arr[i];
	}

	return min;
}

template<typename T>
T findMax(T* arr, unsigned size)
{
	if (!arr)
	{
		return -1;
	}

	T max = arr[0];
	for (size_t i = 1; i < size; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}

	return max;
}

void remEvenEls();
void negativeElements();
void sumandProductOfAnArray();
void apartmentHouse();
void rowOfNumbers();
void sortingFractions();
void dynArrays1();
void dynArrays2();
void aritProgression();
void sortTest();
void printHelpMenuSortTest();