#include "MatrixStruct.h"

using std::cout;
using std::cin;
using std::endl;

void matrTest()
{	
	Matrix<int> matr;
	string fileName;
	char ch;

	cout << "Введите размер матрицы n на n: ";
	cin >> matr.sizeRows >> matr.sizeCols;

	allocateMemory(matr);

	cout << "Выберите способ заполнения матрицы: \n"
		<< "1 - Случайными цифрами\n"
		<< "2 - Самостоятельно\n";
	cin >> ch;

	switch (ch)
	{
	case '1':
	{
		fillMatrix(matr);
		break;
	}
	case '2':
	{
		inputMatrix(matr);
		break;
	}
	default:
		cout << "Неизвестный выбор!\n";
		break;
	}

	printMatrix(matr);

	cout << "Введите имя файла: ";
	cin >> fileName;
	ofstream file(fileName, ios::app);
	printMatrixToFile(matr, file);
	file.close();

	clearMemory(matr);
}

////////////////////////////////////////////////////////////////////////////////////////

void matrHelpMenu()
{
	cout << "-1 Сложение 2 матриц\n";
	cout << "-2 Умножение матрицы на число\n";
	cout << "-3 Транспонирование матрицыn\n";
	cout << "-4 Умножение произвольных матриц\n\n";
	cout << "-5 Напечатать матрицы\n";
}

void matrTest2()
{
	Matrix<int> matr;
	Matrix<int> matr2;
	Matrix<int> matrAddition;
	int num;

	char buf[256] = { 0 };
	char choice[128] = { 0 };

	cout << "Введите размер матриц n на n: ";
	cin >> matr.sizeRows >> matr.sizeCols;
	matr2.sizeRows = matr.sizeRows;
	matr2.sizeCols = matr.sizeCols;
	matrAddition.sizeRows = matr.sizeRows;
	matrAddition.sizeCols = matr.sizeCols;
	
	matrHelpMenu();

	allocateMemory(matr);
	allocateMemory(matr2);
	allocateMemory(matrAddition);

	fillMatrix(matr);
	fillMatrix(matr2);

	while (strcmp(choice, "q"))
	{
		memset(buf, 0, sizeof(buf));
		memset(choice, 0, sizeof(choice));

		cout << "Введите пункт меню: \n";
		gets_s(buf, sizeof(buf));
		sscanf_s(buf, "-%s", choice, sizeof(choice));
		switch (atoi(choice))
		{
		case 0:
		{
			if (!strcmp(choice, "q"))
			{
				break;
			}
			else if (!strcmp(choice, "h"))
			{
				matrHelpMenu();
			}
			else
			{
				cout << "неизвестный выбор\n";
			}
			break;
		}
		case 1:
		{
			additionMatrix(matr, matr2, matrAddition);
			break;
		}
		case 2:
		{
			cout << "Введите число на которое хотите умножить: ";
			cin >> num;
			multiplicationMatrix(matr, matrAddition, num);
			break;
		}
		case 3:
		{
			transpMatrix(matr, matrAddition);
			break;
		}
		case 4:
		{
			multipMatrices(matr, matr2, matrAddition);
			break;
		}
		case 5:
		{
			cout << "Матрица №1: \n";
			printMatrix(matr);
			cout << "Матрица №2: \n";
			printMatrix(matr2);
			cout << "Матрица для вычеслений: \n";
			printMatrix(matrAddition);
			break;
		}
		default:
		{
			cout << "Неизвестный выбор!";
			break;
		}
		}
	}

	clearMemory(matr);
	clearMemory(matr2);
	clearMemory(matrAddition);
}