#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cmath>
#include <ctime>
#include "my_arrays.h"

// Задача 1
void remEvenEls()
{
	const int allocateSize = 256;
	int size;
	int arr[allocateSize]{ 0 };
	char choice;

	cout << "Введите размер массива: n = ";
	cin >> size;

	size %= allocateSize;

	cout << "Выберите вариант заполнения массива: ";
	cout << "1. Рандомно.";
	cout << "2. Самостоятельно.\n";
	cin >> choice;

	switch (choice)
	{
	case '1':
		for (int i = 0; i < size; i++)
		{
			arr[i] = -100 + rand() % 201;
			cout << " " << arr[i] << " ";
		}
		break;

	case '2':
		for (int i = 0; i < size; i++)
		{
			cin >> arr[i];
			cout << " " << arr[i] << " ";
		}
		break;

	default:
		for (int i = 0; i < size; i++)
		{
			arr[i] = -100 + rand() % 201;
			cout << " " << arr[i] << " ";
		}
		break;
	}

	bool isEven;
	for (size_t i = 0; i < size; i++)
	{
		isEven = arr[i] % 2 == 0;

		if (isEven)
		{
			for (size_t j = i; j < size - 1; j++)
			{
				arr[j] = arr[j + 1];
			}
			--size;
			--i;
		}
	}

	cout << "\nМассив после удаления чётных чисел:\n";
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << '\n';

}

bool comp_odd(int a, int b)
{
	return (b & 1) && !(a & 1);
}

void makeArrTest()
{
	const int size = 10;
	int arr[size]{ 0 };

	for (size_t i = 0; i < size; i++)
	{
		arr[i] = rand() % 200 - 100;
	}

	cout << "Ваш массив:\n";
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";

	cout << " Adress: " << arr;

	std::sort(arr, arr + size - 1, comp_odd);

	cout << "Ваш отсортированный массив:\n";
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}

void makeArrTest2()
{
	const int size = 10;
	int arr[size]{ 0 };

	fillArr(arr, size);
	printArr(arr, size, "Ваш массив");

	cout << " Adress: " << arr << endl;
	std::sort(arr, arr + size, comp_odd);
	printArr(arr, size, "Ваш отсортированный массив:\n");

	cout << "Сумма массива = " << sumArr(arr, size);
}

// задача 2 | сравнение отрицательных элементов в 2 массивах
void negativeElements()
{
	int number1(0), number2(0);
	const int size = 100;
	int arr1[size]{ 0 };
	int arr2[size]{ 0 };

	fillArr(arr1, size);
	for (int i(0); i < size; i++)
	{
		arr2[i] = (-100 + rand() % 200);
	}


	for (int i = 0; i < size; i++)
	{
		if (arr1[i] < 0)
		{
			number1 += 1;
		}
	}

	for (int i = 0; i < size; i++)
	{
		if (arr2[i] < 0)
		{
			number2 += 1;
		}
	}

	cout << "В 1 массиве отрицательных элементов: " << number1 << endl;
	cout << "Во 2 массиве отрицательных элементов: " << number2 << endl;

	if (number1 > number2)
	{
		cout << "\nВ 1 массиве больше отрицательных элементов";
	}
	else if (number1 < number2)
	{
		cout << "\nВо 2 массиве больше орицательных элементов";
	}
	else
		cout << "\nВ массивах одинаковое кол-во отрицательных элементов\n";
}

// задача 3 | произведение и сумма массива
void sumandProductOfAnArray()
{
	long long product(1);
	int number1(0), number2(0);
	const int size = 100;
	int arr[size]{ 0 };

	fillArr(arr, size);
	printArr(arr, size);

	for (int i = 0; i < size; i++)
	{
		number2 += 1;
		number1 += arr[i];
		product *= arr[i];
		i++;
	}
	cout << "Кол-во элементов стоящих на чётных местах: "
		<< number2 << endl;
	cout << "Сумма элементов массива = "
		<< number1 << endl;
	cout << "Произведение элементов массива = "
		<< product << endl;
}

// задача 4 | зачада про квартиры
void apartmentHouse()
{
	short number, x(1);
	const int size = 10;
	string apartNumber[size] = { "SidorovA", "IvanovA", "PetrovA", "SidorovB","IvanovB",
		"PetrovB", "SidorovC", "IvanovC", "PetrovC", "SidorovD" };

	for (int i(1); i <= 3; i++)
		{
		cout << "\nВведите номер " << x << " квартиры: " << endl;
		while (!(cin >> number))
		{
			cin.clear();
			cin.ignore();
			cout << "\nВведите номер квартиры: ";
		}
		cout << "Номер " << i << " квартиры: " << apartNumber[number] << endl;
		x++;
		}
}


// задача 5 | на ряд повторяющихся чисел
void rowOfNumbers()
{
	const int size = 10;
	int arr[size]{ 0 };
	bool theSameNumbers[size];
	int i(0), j;
	short sum(0);

	for (int i(0); i < size; i++)
	{
		arr[i] = rand() % 11;
	}

	printArr(arr, size);

	while (i < 11)
	{
		j = i + 1;
		while (j < 10)
		{
			if (arr[i] == arr[j])
			{
				cout << arr[i] << '\t' << arr[j] << endl;
				theSameNumbers[i] = theSameNumbers[j] = true;
				sum += 1;
			}
			++j;
		}
		++i;
	}
	cout << "\nКол-во похожих элементов: " << sum << endl;
}


// задача 6 | сортировка дробных чисел
void sortingFractions()
{
	const int size = 10;
	double arr[size]{ 0 };

	cout << "Введите 10 чисел для заполнения массива: " << endl;

	inputArr(arr, size);

	bubleSort(arr, size, 0);

	//for (int i = 0; i < 10; i++)
	//{
	//	for (int j = 0; j < 9; j++)
	//	{
	//		if (arr[j] > arr[j + 1])
	//		{
	//			swap(arr[j], arr[j + 1]);
	//			/*int b = arr[j];
	//			arr[j] = arr[j + 1];
	//			arr[j + 1] = b;*/
	//		}
	//	}
	//}
	printArr(arr, size);
}

void dynArrays1()
{
	int size, sum(0);

	cout << "Введите количество массива: ";
	while (!(cin >> size))
	{
		cin.clear();
		cin.ignore();
		cout << "\nВведите количество массива: ";
	}

	int* arr1 = nullptr;
	int* arr2 = nullptr;

	allocateMemory(arr1, size);
	allocateMemory(arr2, size);

	fillArray(arr1, size, 0, 10);
	fillArray(arr2, size);

	printArr(arr1, size, "Arr1: ");
	printArr(arr2, size, "Arr2: ");

	for (int i = 0; i < size; i++)
	{
		if (arr1[i] > 0)
		{
			sum += arr1[i];
		}
	}

	for (int i = 0; i < size; i++)
	{
		if (arr2[i] > 0)
		{
			sum += arr2[i];
		}
	}

	cout << "\nСумма положительных элементов двух массвов: " << sum;

	clearMemory(arr1);
	clearMemory(arr2);
}

/*было несколько попыток реализовать в 1 функцию, но все они даже не
компилировались как и попытка поставить ограничение на min max в .h файле*/

void dynArrays2()
{
	int size, sumD(0), d;

	cout << "Введите количество массива: ";
	while (!(cin >> size))
	{
		cin.clear();
		cin.ignore();
		cout << "\nВведите количество массива: ";
	}

	int* arr1 = nullptr;
	int* arr2 = nullptr;

	allocateMemory(arr1, size);
	allocateMemory(arr2, size);

	fillArray(arr1, size, 0, 10);
	fillArray(arr2, size);

	printArr(arr1, size, "Arr1: ");
	printArr(arr2, size, "Arr2: ");

	cout << "Введите число d: ";
	while (!(cin >> d))
	{
		cin.ignore();
		cin.clear();
		cout << "\nВведите число d: ";
	}

	for (int i = 0; i < size; i++)
	{
		if (arr1[i] == d)
		{
			sumD++;
		}
	}

	for (int i = 0; i < size; i++)
	{
		if (arr2[i] == d)
		{
			sumD++;
		}
	}

	cout << "Количество эллементов равных d: " << sumD;
	clearMemory(arr1);
	clearMemory(arr2);
}

void aritProgression()
{
	int size;
	float sum(0);
	unsigned begin, step;

	cout << "Введите длину массива: ";
	while (!(cin >> size))
	{
		cin.clear();
		cin.ignore();
		cout << "\nВведите длина массива: ";
	}
	cout << "Введите начальный элемент: ";
	cin >> begin;
	cout << "Введите чему равен постоянный шаг: ";
	cin >> step;

	int* arr = nullptr;

	allocateMemory(arr, size);

	arr[0] = begin;

	for (size_t i = 1; i < size; i++)
	{
		arr[i] = arr[i - 1] + step;
	}

	printArr(arr, size);

	sum = ((arr[0] + arr[size - 1]) / 2.0) * size;
	cout << "Сумма прогрессии: " << sum;

	clearMemory(arr);
}
////////////////////////////////////////////////

// задача на сортировку массива
// по убыванию 
bool cmpDecreaseArr(int a, int b)
{
	return a < b;
}

// по кратности 3
bool cmpMultipleOfThree(int a, int b)
{
	if ((a % 3 != 0) && (b % 3 == 0))
	{
		return true;
	}

	return false;
}

// по модулю
bool cmpAbs(int a, int b)
{
	return abs(a) > abs(b);
}

// по чётности
bool cmpParity(int a, int b)
{
	if ((a % 2 != 0) && (b % 2 == 0))
	{
		return true;
	}

	return false;
}

// основная функция
void sortTest()
{
	int size;
	char choice[128] = { 0 };
	char buf[256] = { 0 };

	cout << "Введите кол-во чисел в массивах: ";
	while (!(cin >> size))
	{
		cin.clear();
		cin.ignore();
		cout << "\nВведите кол-во чисел в массивах: ";
	}

	int* arr = nullptr;

	allocateMemory(arr, size);
	fillArray(arr, size, -10, 100);

	printHelpMenuSortTest();

	while (strcmp(choice, "q"))
	{
		memset(buf, 0, sizeof(buf));
		memset(choice, 0, sizeof(choice));

		cout << "Введите пункт меню: \n";
		fgets(buf, sizeof(buf), stdin);
		sscanf(buf, "-%s", choice, sizeof(choice));

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
				printHelpMenuSortTest();
			}
			else
			{
				cout << "Неизвестный выбор\n";
			}
			break;
		}
		case 1:
		{
			printArr(arr, size);
			break;
		}
		case 2:
		{
			bubleSort(arr, size, cmpDecreaseArr);
			break;
		}
		case 3:
		{
			choiceSort(arr, size, cmpParity);
			break;
		}
		case 4:
		{
			choiceSort(arr, size, cmpMultipleOfThree);
			break;
		}
		case 5:
		{
			choiceSort(arr, size, cmpAbs);
			break;
		}
		default:
		{
			cout << "Неизвестный выбор\n";
			break;
		}
		}
	}

	clearMemory(arr);
}

void printHelpMenuSortTest()
{
	cout << "-1 Показать массив\n";
	cout << "-2 Сортировать массив по убыванию\n";
	cout << "-3 Сортировать массив по чётности\n";
	cout << "-4 Сортировать по кратности 3\n\n";

	cout << "-h Справка\n";
	cout << "-q Выход\n\n";
}