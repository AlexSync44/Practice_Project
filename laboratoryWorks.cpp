#pragma pack(push,1)
#include "laboratoryWorks.h"
#include <iostream>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <string>
#include <sstream>


void laboratoryWork№3()
{
	int number1;
	long number2;
	char choice = ' ';

	cout << "Введите число [-32.768; 32.768] >> ";
	cin >> number1;
	printBitsOfIntegral(number1);

	do
	{
		
		cout << "\n1 - Установить бит в 1\n";
		cout << "\n2 - Сбросить бит в 0\n";
		cout << "\n3 - Опросить бит\n";
		cout << "\n4 - Изменить бит\n";
		cout << "\n0 - Выход\n";
		cin >> choice;

		switch (choice)
		{	

		case '1':
			cout << "Введите номер бита >>";
			cin >> number2;
			number1 |= number2;
			printBitsOfIntegral(number1);
			break;

		case '2':
			number1 &= ~(1 << 0);
			printBitsOfIntegral(number1);
			break;

		case '3':

			break;

		case '4':
			cin >> number1;
			printBitsOfIntegral(number1);
		default:
			cout << "\nВведите число от 0 до 4: ";
				cin >> choice;
			return;
			
		}





	}	while ((choice >  '0') && (choice < '5'));




	 

}

//void ticTacToe()
//{
//	cout << "Крестики нолики\n";
//
//	int size;
//
//	cout << "Введите  размер поля nXn: ";
//	cin >> size;
//
//	char** field = [size][size]{};
//	char* pField[size]{ 0 };
//	
//	for (size_t i = 0; i < size; i++)
//	{
//		for (size_t j = 0; j < size; i++)
//		{
//			field[i][j] = '-';
//		}
//	}
//
//	for (size_t i = 0; i < size; i++)
//	{
//		pField[i] = field[i];
//	}
//
//	char c;
//	unsigned row(0), col(0);
//	bool posotionIsValid = false;
//
//	for (size_t move = 0; move < size * size; move++)
//	{
//		cout << "Введите позицию на поле: ";
//		if (move % 2 == 0)
//		{
//			c = 'X';
//		}
//		else
//		{
//			c = 'O';
//		}
//
//		cout << c << " ";
//
//		if (row, col = '\0')
//		{
//			cin >> row >> col;
//		}
//		else
//		{
//			cout << "Данная позиция уже занята, введите другую";
//		}
//
//
//
//		move++;
//
//		
//
//		//posotionIsValid = проверка что индексы адекватны и ячейки поля пустые
//		
//		//заполнить ячейку поля 
//		// проверка комбинации если всё ок
//		// 
//		// создать функцию то проверка комбинации
//
//		// если комбинация есть выводим сообщение
//		// выходим из функции
//	}	
//
//	cout << "Ничья\n";
//
//
//}
//
//// TO DO сделать реализацию через динамический массив с не статическими переменными для изменения 
//char checkWinner(char** field, int size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		for (size_t j = 0; j < size; j++)
//		{
//		if (field[i * 3] == field[i * 3 + 1] && field[i * 3 + 1] == field[i * 3 + 2])
//		{
//			return field[i][j];
//		}
//		else if (field[i] == field[i + 3] && field[i + 3] == field[i + 6])
//		{
//			return field[i][j];
//		}
//		else if ((field[2] == field[4] && field[4] == field[6]) || (field[0] == field[4] && field[4] == field[8]))
//		{
//			return field[i][j];
//		}
//	}
//	return '-';
//}