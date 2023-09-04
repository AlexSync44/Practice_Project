#pragma once
#include <iostream>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <string>
#include <fstream>
#include "matrix.h"

template<typename T>
struct Matrix
{
	T** matrix;
	unsigned sizeRows;
	unsigned sizeCols;
};

template<typename T>
void allocateMemory(Matrix<T>& matr)
{
	allocateMemory(matr.matrix, matr.sizeRows, matr.sizeCols);
}

template<typename T>
void clearMemory(Matrix<T>& matr)
{
	clearMemory(matr.matrix, matr.sizeRows, matr.sizeCols);
}

template<typename T>
void printMatrix(Matrix<T>& matr)
{
	printMatrix(matr.matrix, matr.sizeRows, matr.sizeCols, 5);
}

template<typename T>
void fillMatrix(Matrix<T>& matr)
{
	fillMatrix(matr.matrix, matr.sizeRows, matr.sizeCols, 0, 100);
}

template<typename T>
void printMatrixToFile(Matrix<T>& matr, ostream& ofile)
{
	printMatrixToFile(matr.matrix, matr.sizeRows, matr.sizeCols, ofile);
}

template<typename T>
void inputMatrix(Matrix<T>& matr)
{
	inputMatrix(matr.matrix, matr.sizeRows, matr.sizeCols);
}

template<typename T>
void additionMatrix(Matrix<T>& matr, Matrix<T>& matr2, Matrix<T>& addition)
{
	additionMatrix(matr.matrix, matr.sizeRows, matr.sizeCols,
				   matr2.matrix, matr2.sizeRows, matr2.sizeCols,
				   addition.matrix);
}

template<typename T>
void transpMatrix(Matrix<T>& matr, Matrix<T>& matr2)
{
	transpMatrix(matr.matrix, matr.sizeRows, matr.sizeCols,
				 matr2.matrix, matr2.sizeRows, matr2.sizeCols);
}

template<typename T>
void makeDiagMatrix(Matrix<T>& matr, Matrix<T>& matr2)
{
	makeDiagMatrix(matr.matrix, matr.sizeRows, matr.sizeCols,
				   matr2.matrix, matr2.sizeRows, matr2.sizeCols);
}

template<typename T>
void multiplicationMatrix(Matrix<T>& matr, Matrix<T>& addition, int number)
{
	multiplicationMatrix(matr.matrix, matr.sizeRows, matr.sizeCols, addition.matrix, number);
}

template<typename T>
void multipMatrices(Matrix<T>& matr, Matrix<T>& addition, Matrix<T>& resMatr)
{
	multiplyMatrices(matr.matrix, matr.sizeRows, matr.sizeCols,
		addition.matrix, addition.sizeRows, addition.sizeCols, resMatr.matrix);
}

template<typename T>
void fillThreeMatrix(Matrix<T>& matr, Matrix<T>& matr2, Matrix<T>& matrAddition)
{
	char ch;

	cout << "Введите размер матриц n на n: ";
	cin >> matr.sizeRows >> matr.sizeCols;
	matr2.sizeRows = matr.sizeRows;
	matr2.sizeCols = matr.sizeCols;
	matrAddition.sizeRows = matr.sizeRows;
	matrAddition.sizeCols = matr.sizeCols;

	allocateMemory(matr);
	allocateMemory(matr2);
	allocateMemory(matrAddition);

	cout << "Выберите способ заполнения матрицы: \n"
		<< "1 - Случайными цифрами\n"
		<< "2 - Самостоятельно\n";
	cin >> ch;

	switch (ch)
	{
	case 1:
	{
		fillMatrix(matr);
		fillMatrix(matr2);
		fillMatrix(matrAddition);
		break;
	}
	case 2:
	{
		inputMatrix(matr);
		inputMatrix(matr2);
		inputMatrix(matrAddition);
		break;
	}
	default:
		cout << "Неизвестный выбор!\n";
		break;
	}
}

void matrTest();
void matrTest2();