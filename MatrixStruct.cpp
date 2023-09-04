#include "MatrixStruct.h"

using std::cout;
using std::cin;
using std::endl;

void matrTest()
{	
	Matrix<int> matr;
	string fileName;
	char ch;

	cout << "������� ������ ������� n �� n: ";
	cin >> matr.sizeRows >> matr.sizeCols;

	allocateMemory(matr);

	cout << "�������� ������ ���������� �������: \n"
		<< "1 - ���������� �������\n"
		<< "2 - ��������������\n";
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
		cout << "����������� �����!\n";
		break;
	}

	printMatrix(matr);

	cout << "������� ��� �����: ";
	cin >> fileName;
	ofstream file(fileName, ios::app);
	printMatrixToFile(matr, file);
	file.close();

	clearMemory(matr);
}

////////////////////////////////////////////////////////////////////////////////////////

void matrHelpMenu()
{
	cout << "-1 �������� 2 ������\n";
	cout << "-2 ��������� ������� �� �����\n";
	cout << "-3 ���������������� �������n\n";
	cout << "-4 ��������� ������������ ������\n\n";
	cout << "-5 ���������� �������\n";
}

void matrTest2()
{
	Matrix<int> matr;
	Matrix<int> matr2;
	Matrix<int> matrAddition;
	int num;

	char buf[256] = { 0 };
	char choice[128] = { 0 };

	cout << "������� ������ ������ n �� n: ";
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

		cout << "������� ����� ����: \n";
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
				cout << "����������� �����\n";
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
			cout << "������� ����� �� ������� ������ ��������: ";
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
			cout << "������� �1: \n";
			printMatrix(matr);
			cout << "������� �2: \n";
			printMatrix(matr2);
			cout << "������� ��� ����������: \n";
			printMatrix(matrAddition);
			break;
		}
		default:
		{
			cout << "����������� �����!";
			break;
		}
		}
	}

	clearMemory(matr);
	clearMemory(matr2);
	clearMemory(matrAddition);
}