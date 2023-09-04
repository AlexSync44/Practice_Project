#include <iostream>
#include <algorithm>
#include <cmath>
#include <ctime>
#include "my_functions.h"
#include "my_arrays.h"
#include <string>
#include <fstream>
#include "my_files.h"

typedef long long int llint;
typedef std::pair<llint, llint> llpair;

#define PI 3.141592;

double lengthVector(double x, double y)
{
	return sqrt(x * x + y * y);
}

// ������ 1 | ����� ����� �������
void searchVectorLengths()
{
	double x, y;

	cout << "\n\n������� ���������� ������� x, y: ";
	while (!(cin >> x >> y))
	{
		cin.clear();
		cin.ignore();
		cout << "\n������� ���������� � ������� 'A B': ";
	}

	double res = lengthVector(x, y);

	cout << "\n����� ������� (" << x << ';' << y << ") = " << res;
}

// ������ 3 | �������������� ���������������
void parallCharacter()
{
	double perimeter, area;
	double sin_a;
	double x, y, degrees;

	cout << "������� ����� ������ 'a', 'b' � ��� � ��������: ";
	while (!(cin >> x >> y >> degrees))
	{
		cin.clear();
		cin.ignore();
		cout << "\n������� ���������� � ������� 'a b': ";
	}

	if (degrees > 90)
	{
		cout << "\n\n��� �� ����� ���� ����� 90 ��������!";
		cout << "\n������� ������� ���� �����: ";

		degrees = NULL;
		cin >> degrees;
	}

	perimeter = 2 * (x + y);
	sin_a = sin(degrees);
	area = (x * y) * sin_a;

	cout << "\n\n�������� ���������������: " << perimeter;
	cout << "\n������� ���������������: " << area;
}

// ������ 4 | �������������� ��������������
void rectCharacter()
{
	double perimeter, area, diagonal;
	double x, y;

	cout << "\n������� ������� �������������� 'a', 'b': ";
	cin >> x >> y;

	perimeter = 2 * (x + y);
	area = (x * y);
	diagonal = (x * y) + (y * y);

	cout << "\n�������� ��������������: " << perimeter;
	cout << "\n��������� ������������: " << sqrt(diagonal);
	cout << "\n������� ������������: " << area;
}

// ������ 5 | ����� ��� ��� ��� ��������
void largestDivisor()
{
	int num1, num2, num3;
	int GCD(0);

	cout << "������� 3 ����������� �����: ";
	while (!(cin >> num1 >> num2 >> num3))
	{
		cin.clear();
		cin.ignore();
		cout << "\n������� ��� ����������� �����: ";
	}

	for (size_t i = 0; i < 3; i++)
	{
		if (num1 <= 0 || num2 <= 0 || num3 <= 0)
		{
			cout << "\n���� �� �������� ����������� ������!\n";
			cout << "������� ����� ������: ";
			cin >> num1 >> num2 >> num3;
		}
	}

	while (num1 && num2 && num3)
	{
		if (num1 > num2)
		{
			num1 %= num2;
		}
		else if (num2 > num3)
		{
			num2 %= num3;
		}
		else if (num1 > num3)
		{
			num1 %= num3;
		}
		else
		{
			num2 %= num1;
		}
		GCD = num1 + num2;
	}

	cout << "��� ��� ����� (" << num1 << ' ' << num2 << ' '
		<< num3 << " �����: " << GCD;
}

// ������� ������� � �������������
void printHelpMenu()
{
	cout << "1  ����� ����� ������� �� ���������\n";
	cout << "2  ����� �������������� ���������������\n";
	cout << "3  ����� ������������� ��������������\n";
	cout << "4  ����� ��� ��� 3-�� �����\n\n";

	cout << "h �������\n";
	cout << "q �����";
}

void callMenu()
{
	cout << "\t\t�������������� ��������\n\n";

	char choice[128] = { 0 };

	printHelpMenu();

	while (strcmp(choice, "q"))
	{

		cout << "\n\n�������� ����� ����: \n";
		cin >> choice;

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
				printHelpMenu();
			}
			else
			{
				cout << "����������� �����\n";
			}
			break;
		}
		case 1:
		{
			searchVectorLengths();
			break;
		}
		case 2:
		{
			parallCharacter();
			break;
		}
		case 3:
		{
			rectCharacter();
			break;
		}
		case 4:
		{
			largestDivisor();
			break;
		}
		default:
			cout << "����������� �����\n";
			break;
		}
	}
}

//////////////////////////////////////////////////////////////////////

// ������ 1 �� ������
void parallCharacteristic2(double& x1, double& y1, double& degrees)
{
	double perimeter, area, sin_a;

	perimeter = 2 * (x1 + y1);
	sin_a = sin(degrees);
	area = (x1 * y1) * sin_a;

	cout << "\n\n�������� ���������������: " << perimeter;
	cout << "\n������� ���������������: " << area;
}

//void callParallogramCharacteristic()
//{
//	double x1, y1, degrees1, x2, y2, degrees2;
//
//	cout << "������� ����� ������ 'a', 'b' � ��� � ��������: ";
//	while (!(cin >> x1 >> y1 >> degrees1))
//	{
//		cin.clear();
//		cin.ignore();
//		cout << "\n������� ���������� � ������� 'a b': ";
//	}
//
//	if (degrees1 > 90)
//	{
//		cout << "\n\n��� �� ����� ���� ����� 90 ��������!";
//		cout << "\n������� ������� ���� �����: ";
//
//		cin >> degrees1;
//	}
//	callParallogramCharacteristic(x1, y1, degrees1);
//
//	cout << "������� ����� ������ 'a', 'b' � ��� � ��������: ";
//	while (!(cin >> x2 >> y2 >> degrees2))
//	{
//		cin.clear();
//		cin.ignore();
//		cout << "\n������� ���������� � ������� 'a b': ";
//	}
//
//	if (degrees2 > 90)
//	{
//		cout << "\n\n��� �� ����� ���� ����� 90 ��������!";
//		cout << "\n������� ������� ���� �����: ";
//
//		cin >> degrees2;
//	}
//
//	callParallogramCharacteristic(x2, y2, degrees2);
//}

// ������ 2 �� ������
void rectCharacter2(double& x, double& y)
{
	double perimeter, area, diagonal;

	perimeter = 2 * (x + y);
	area = (2 * x) + (2 * y);
	diagonal = (x * x) + (y * y);

	cout << "\n\n�������� ������� ��������������: " << perimeter;
	cout << "\n��������� ������� ������������: " << sqrt(diagonal);
	cout << "\n������� ������� ������������: " << area;
}

void callRectCharacter()
{
	double x1, y1, x2, y2;

	cout << "������� ����� ������  ��������������� 'a', 'b' :";
	cin >> x1 >> y1;

	rectCharacter2(x1, y1);

	cout << "������� ����� ������  ��������������� 'a', 'b' :";
	cin >> x2 >> y2;

	rectCharacter2(x2, y2);
}

// TO DO ������� ������� � ������� � ��������� ���� ��� ����

// ������ �� ����� �������� �� 3-�� �������� �����
void secondValue(int x)
{
	if (x < 99 || x > 1000)
	{
		cout << "������ ����� �� 3-�� �������!";
		return;
	}

	cout << "������ �� ����� " << x << ": " << (x % 100) / 10;
}

void callSecondValue()
{
	int num;

	cout << "������� 3-�� ������� �����: ";
	while (!(cin >> num))
	{
		cin.clear();
		cin.ignore();
		cout << "\n������� 3-�� ������� ����� (123): ";
	}

	secondValue(num);
}

// ������ �������� ����� � ������������ ��
void octSystemToDec(int& x)
{
	cout << "\n���� ����� � ���������� ��: " << std::dec << x;
}

int enterNumber(int& x)
{
	cout << "������� ����� ��� ��������: ";
	cin >> std::oct >> x;

	return x;
}

void callOctToDec()
{
	int num;

	enterNumber(num);
	octSystemToDec(num);
}

double lengthVector_remade(double& x, double& y)
{
	return sqrt(x * x + y * y);
}

double tan_remade(double x, double y)
{
	if (x != 0)
	{
		return y / x;
	}
	else
		return -1;
}
 
// ������ ������ ����� ������� � ������� ����
void searchVectorCharacteristic_remade()
{
	double x1, y1, x2, y2;

	cout << "������� ���������� ���� �������� x, y: ";
	while (!(cin >> x1 >> y1 >> x2 >> y2))
	{
		cin.clear();
		cin.ignore();
		cout << "\n������� ���������� � ������� 'A1 B1 A2 B2': ";
	}

	double res1 = lengthVector_remade(x1, y1);
	double res2 = lengthVector_remade(x2, y2);

	double tan1 = tan_remade(x1, y1);
	double tan2 = tan_remade(x2, y2);

	cout << "\n����� ������� (" << x1 << ';' << y1 << ") = " << res1
	<< "\n������� ���� ������� (" << x1 << ';' << y1 << ") = " << tan1;
	cout << "\n\n����� ������� (" << x2 << ';' << y2 << ") = " << res2
	<< "\n������� ���� ������� (" << x2 << ';' << y2 << ") = " << tan2;
}

// ������ ������ �������� � ��������
int minValueInArray(int arr[],int size, int& buf, int& minInd)
{
	if (!arr)
		return -1;
	// �������� �������, ���� �� ������ ��������� ���������� ���������

	for (size_t i = 0; i < size; i++)
	{
		if (buf > arr[i]) // ����� ������������ ����� � �������
		{
			buf = arr[i];
			minInd = i;
		}
	}

	// ����� ������������ ����� � �������
	cout << "����������� �������� �������: " << buf << endl;

	return buf;
}

bool workingAnArray(int buf, int minInd, int size, int buf2)
{
	if (!minInd || !buf)
	{
		return false;
	}
	// ����������� �������� ������� � ������������ �����

	if (buf > 0 && (size / 2) < minInd && buf2 == 8)
	{
		return true;
	}
	else
		return false;
}

void basicFunc()
{
	int size, bufMin1(101), bufMin2(101), bufMin3(101),
		minInd1, minInd2, minInd3;

	cout << "������� ���-�� ����� � ��������: ";
	while (!(cin >> size))
	{
		cin.clear();
		cin.ignore();
		cout << "\n������� ���-�� ����� � ��������: ";
	}

	int* arr1 = nullptr;
	int* arr2 = nullptr;
	int* arr3 = nullptr;

	allocateMemory(arr1, size);// ��������� ������ ��� ��������
	allocateMemory(arr2, size);
	allocateMemory(arr3, size);

	fillArray(arr1, size, -10, 100);// ���������� ��������
	fillArray(arr2, size, -10, 100);
	fillArray(arr3, size, -10, 100);

	printArr(arr1, size, "������ �1: ");// ����� � ������� �������. ����� � ������
	printArr(arr2, size, "������ �2: ");
	printArr(arr3, size, "������ �3: ");

	minValueInArray(arr1, size, bufMin1, minInd1);/* ����� �������� */
	minValueInArray(arr2, size, bufMin2, minInd2);/* � ������� � �������� */ 
	minValueInArray(arr3, size, bufMin3, minInd3);

	if (workingAnArray(bufMin1, minInd1, size, bufMin3))
	{	// ���� ������� ������� true, �� ��� ������� �� 2 ������� �� ������������ ������������ 1
		for (size_t i = 0; i < minInd2; i++)
		{
			arr2[i] = 1;
		}
	}
	else
	{
		goto jmp;
	}
jmp:

	cout << '\n';
	printArr(arr1, size, "������ �1: ");// ����� � ������� �������
	printArr(arr2, size, "������ �2: ");
	printArr(arr3, size, "������ �3: ");
	
	clearMemory(arr1); // �������� ������
	clearMemory(arr2);
	clearMemory(arr3);
}

// �������� ������� �� �����
//bool simpleNumber(int num)
//{
//	for (size_t i = 2; i <= 10; i++)
//	{
//		if (num % i == 0)
//		{
//			return false;
//		}
//	}
//
//	return true;
//}

llint nod(llint a, llint b)
{
	while (a != 0 && b != 0)
	{
		if (a > b)
		{
			a = a % b;
		}
		else
		{
			b = b % a;
		}
	}

	return a + b;
}

llint nok(llint a, llint b)
{
	llint nodAB = nod(a, b);

	if (nodAB != 0)
	{
		return a * b / nodAB;
	}

	return a * b;
}

bool isPrime(llint n)
{
	if (n % 2 == 0)
	{
		return n == 2;
	}

	llint number = 3;

	while (number * number <= n && n % number != 0)
	{
		number += 2;
	}

	return number * number > n;
}

bool isPerfect(llint n)
{
	llint sum = 0;

	for (int divider = 1; divider < n; divider++)
	{
		if (n % divider == 0)
		{
			sum += divider;
		}
	}

	return (sum == n);
}

void primesNumberAutoTest()
{
	string fileName;
	int num(0);

	std::getline(cin, fileName);
	fstream autoTest(fileName, std::ios::in);

	if (!(autoTest.is_open()))
	{
		cout << "���� �� ������";
	}

	while (autoTest >> num)
	{
		if (isPrime(num))
		{
			cout << num << " - �������\n";
		}

	}
}

void simpleNumberTest()
{
	cout << "\t\t�������� ������� �����\n\n";

	int* arr = nullptr, size;
	int* addArr = nullptr;
	unsigned count = 0;
	char choice;

	cout << "������� ������ �������: n = ";
	cin >> size;

	cout << "�������� ������� ���������� �������:\n";
	cout << "1. ��������.\n";
	cout << "2. ��������������.\n";
	cin >> choice;

	allocateMemory(arr, size);
	allocateMemory(addArr, size);

	switch (choice)
	{
	case '1':
		fillArray(arr, size, 1, 257);
		printArr(arr, size);
		break;

	case '2':
		inputArr(arr, size);
		printArr(arr, size);
		break;

	default:
		fillArray(arr, size, 1, 257);
		printArr(arr, size);
		break;
	}

	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] == 1 || arr[i] == 2 || arr[i] == 3 || arr[i] == 5 || arr[i] == 7)
		{
			cout << '\n' << arr[i] << " ������� �����\n";
			i++;
		}
		else if (arr[i] == 0)
		{
			cout << "0 �� �������� �� �������, �� ���������\n";
			i++;
		}

		if (isPrime(arr[i]))
		{
			addArr[count] = arr[i];
			count++;
		}
	}

	cout << "\n������� ����� �� ����� �������: ";
	for (size_t i = 0; i < count; i++)
	{
		cout << addArr[i] << ' ';
	}

	clearMemory(arr);
	clearMemory(addArr);
}

void goldbachHypothesis()
{
	int num;
	std::cin >> num;
	for (size_t i = 2; i < num; i++)
	{
		int addNum = num - i;

		if (isPrime(i) && isPrime(addNum))
		{
			std::cout << i << " " << addNum;
			break;
		}
	}
}
