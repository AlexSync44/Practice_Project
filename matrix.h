#pragma once
#include <iostream>
#include "my_arrays.h"

void doubleArrayQuickStart();
void matrixTest();
void doubleDynArrayQuickStart();
void dynamicMatrixTest();
void findMinInCols();
void sortMainDiag();
void increasingValue();
void matrixFromMatrix();
void averageScoreExam();
void averageScoreExam2();
void swapMatrTest();

using namespace std;

template<typename DataType>
void printMatrix(
	DataType* matr[],
	int rowsCount,
	int colsCount,
	int w = 10)
{
	cout.precision(3);
	cout.setf(
		ios::fixed |
		ios::dec |
		ios::showbase);

	cout.fill('|');

	for (size_t i = 0; i < rowsCount; i++)
	{
		for (size_t j = 0; j < colsCount; j++)
		{
			cout.width(w);
			cout << matr[i][j] << " ";
		}
		cout << '\n';
	}
}

template<typename DataType>
void fillMatrix(
	DataType* matr[],
	int rowsCount,
	int colsCount,
	int row1, int col1,
	int row2, int col2,
	DataType value)
{
	for (size_t i = row1; i <= row2; i++)
	{
		for (size_t j = col1; j <= col2; j++)
		{
			matr[i][j] = value;
		}
	}
}

template<typename DataType>
void additionMatrix(
	DataType* matr1[], int row1, int col1,
	DataType* matr2[], int row2, int col2,
	DataType* addition[])
{
	if (row1 != row2)
		return;
	if (col1 != col2)
		return;

	for (size_t i = 0; i < row1; i++)
	{
		for (size_t j = 0; j < col1; j++)
		{
			addition[i][j] = matr1[i][j] + matr2[i][j];
		}
	}
}

template<typename DataType>
void transpMatrix(
	DataType* matr[], int row1, int col1,
	DataType* transpMatr[], int row2, int col2)
{
	if (row1 != col2)
		return;
	if (col1 != row2)
		return;

	for (size_t i = 0; i < row1; i++)
	{
		for (size_t j = 0; j < col1; j++)
		{
			transpMatr[j][i] = matr[i][j];
		}
	}
}

template<typename DataType>
void fillMatrix(DataType* matr[],
	int row, int col,
	int min = 0, int max = 1000)
{
	if (!matr)
	{
		return;
	}

	long int static i = 1;
	srand(time(0) * i++);

	for (int i(0); i < row; ++i)
	{
		for (int j = 0; j < col; j++)
		{
			matr[i][j] = DataType(min + rand() % (max - min + 1));
		}
	}
}

template<typename DataType>
void makeDiagMatrix(DataType* matr[],
	int row, int col,
	int min = 0, int max = 100)
{
	if (!matr)
	{
		return;
	}

	for (int i(0); i < row; ++i)
	{
		for (int j = 0; j < col; j++)
		{
			if (i != j)
			{
				matr[i][j] = 0;
			}

		}
	}
}

template<typename DataType>
void clearMemory(DataType**& array, int rows, int cols)
{
	//очищаем сами массивы с данными
	for (int i = 0; i < rows; i++)
	{
		delete[] array[i];
	}

	//очищаем массив указателей
	delete[] array;

	//показываем что указатель не на что не указывает
	array = nullptr;
}

template<typename DataType>
void allocateMemory(DataType**& arrays, int rows, int cols)
{
	//if (arrays)
	//{
	//	clearMemory(arrays, rowsMatr, colsMatr);
	//}

	/* выделяем память под массив укателей,
	 то есть выделяем память под каждый указатель
	на одномерный массив*/

	arrays = new DataType * [rows];

	for (int i = 0; i < rows; i++)
	{ // arr[i] указатель на i-ый одномерный массив 
		arrays[i] = new DataType[cols];
		memset(arrays[i], 0, sizeof(DataType) * cols);
	}
}

template<typename DataType>
void inputMatrix(DataType** arr, int rows, int cols)
{
	if (!arr)
	{
		return;
	}

	for (size_t i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cin >> arr[i][j];
		}
	}
}

template<typename T>
void printMatrixToFile(T** matr, unsigned rows, unsigned cols, ostream& ofile)
{
	if (!matr)
	{
		return;
	}

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			ofile << matr[i][j] << ' ';
		}
		ofile << endl;
	}
}

template<typename T>
void multiplicationMatrix(T** matr, unsigned rows, unsigned cols, T** addition, int number)
{
	if (!matr)
	{
		return;
	}

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			addition[i][j] = matr[i][j] * number;
		}
	}
}

template<typename T>
void multiplyMatrices(T** matr, unsigned rowsMatr, unsigned colsMatr, T** arbitrary, unsigned rowsMatr2, unsigned colsMatr2, T** resMatr)
{
	if (!matr || !arbitrary)
	{
		return;
	}

	for (size_t i = 0; i < rowsMatr; i++)
	{
		for (size_t j = 0; j < colsMatr; j++)
		{
			resMatr[i][j] = matr[i][j] * arbitrary[j][i];
		}
	}

	int buf(0);

	for (size_t i = 0; i < rowsMatr; i++)
	{
		for (size_t j = 0; j < colsMatr; j++)
		{
			buf += arbitrary[i][j];

			if (j)
			{
				resMatr[i][j] = buf;
			}
		}
		buf = 0;
	}
}

template<typename T>
T findMinMatr(T* matr[], unsigned rows, unsigned cols, int& rowOfMin, int& colOfMin)
{
	if (!matr)
	{
		return -1;
	}

	T min = matr[0][0];
	rowOfMin = 0;
	colOfMin = 0;

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			if (matr[i][j] < min)
			{
				min = matr[i][j];
				rowOfMin = i;
				colOfMin = j;
			}
		}
	}

	return min;
}

//- максимум из минимов в каждой строке
//
//
//- минимум из максимумов в каждой строке

template<typename T>
T findMaxInMin(T* matr[], unsigned rows, unsigned cols)
{
	if (!matr)
	{
		return -1;
	}

	T maxMin = findMin(matr[0], cols);
	for (size_t i = 1; i < rows; i++)
	{
		T newMin = findMin(matr[i], cols);
		if (newMin > maxMin)
			maxMin = newMin;
	}

	return maxMin;
}

template<typename T>
T findMinInMax(T* matr[], unsigned rows, unsigned cols)
{
	if (!matr)
	{
		return -1;
	}

	T minMax = find(matr[0], cols);
	for (size_t i = 0; i < rows; i++)
	{
		T newMax = findMax(matr[i], cols);
		if (newMax < minMax)
			minMax = newMax;
	}

	return minMax;
}