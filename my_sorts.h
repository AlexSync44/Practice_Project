#pragma once

#include <iostream>
#include <ctime>

using std::endl;
using std::cin;
using std::cout;
using std::string;

template <typename T>
void selectionSort(T* arr, const int size, bool (*cmp)(T, T))
{
	int minInd;
	T x;
	for (int i = 0; i < size; i++)
	{
		minInd = i;
		x = arr[i];
		for (int j = i + 1; j < size; j++)
		{
			if (cmp(arr[j], x))
			{
				minInd = j;
				x = arr[j];
			}
		}
		arr[minInd] = arr[i];
		arr[i] = x;
	}
}

void selectionSort(void* arr, const unsigned size,
	const unsigned sizeOfElement,
	int (*cmp)(const void*, const void*));

void combSort(void* arr, const unsigned size,
	const unsigned sizeOfElement,
	int (*cmp)(const void*, const void*));

void heapSort(void* arr, const unsigned size,
	const unsigned sizeOfElement,
	int (*cmp)(const void*, const void*));

inline
void insertionSort(int arr[], const int size, int (*cmp)(int, int))
{
	int i, j, temp;
	for (i = 1; i < size; i++)
	{
		temp = arr[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (!cmp(arr[j], temp))
				break;

			arr[j + 1] = arr[j];
			arr[j] = temp;
		}
	}
}

template<typename DataType>
void bubleSort(DataType* arr, int size, bool ascending = true)
{
	if (!arr)
	{
		return;
	}

	if (ascending)
	{
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size - i - 1; ++j)
			{
				if (arr[j] < arr[j + 1])
				{
					std::swap(arr[j], arr[j + 1]);
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size - i - 1; ++j)
			{
				if (arr[j] > arr[j + 1])
				{
					std::swap(arr[j], arr[j + 1]);
				}
			}
		}
	}
}

template<typename T>
void bubleSort(T* arr, int size, bool (*cmp)(T, T))
{
	if (!arr)
	{
		return;
	}

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size - i - 1; ++j)
		{
			if (cmp(arr[j], arr[j + 1]))
			{
				std::swap(arr[j], arr[j + 1]);
			}
		}
	}
}

template<typename T>
void choiceSort(T* arr, unsigned size, bool (*cmp)(T, T))
{
	if (!arr)
	{
		return;
	}

	for (size_t i = 0; i < size; i++)
	{
		T tmp = arr[0];
		for (size_t j = i + 1; j < size; j++)
		{
			if (cmp(arr[i], arr[j]))
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

template<typename T>
void quickSort(T* arr, unsigned size, bool (*cmp)(T, T))
{
	long i = 0, j = size;
	T tmp, p;

	p = arr[size >> 1];

	do
	{
		while (arr[i] < p) i++;
		while (arr[j] > p) j--;

		if (cmp(arr[i] <= arr[j]))
		{
			tmp = arr[i]; arr[i] = arr[j]; arr[j] = tmp;
			i++; j--;
		}
	} while (i <= j);
}

template<typename T>
void printArr(T* arr, unsigned size, std::string str)
{
	if (!arr)
	{
		return;
	}

	std::cout << str << ' ';
	for (size_t i = 0; i < size; ++i)
	{
		std::cout << arr[i] << ' ';
	}
}

void sortsTest();
void quick_sort(int* a, int L, int R);
void merge(int* a, int L, int R, int M);
void merge(const int* arrA, int sizeA, const int* arrB, int sizeB, int*& arrRes, int& sizeRes);
void pyramidal_sort(int* a, int n);