#pragma pack(push,1)
#include "laboratoryWorks.h"
#include <iostream>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <string>
#include <sstream>


void laboratoryWork�3()
{
	int number1;
	long number2;
	char choice = ' ';

	cout << "������� ����� [-32.768; 32.768] >> ";
	cin >> number1;
	printBitsOfIntegral(number1);

	do
	{
		
		cout << "\n1 - ���������� ��� � 1\n";
		cout << "\n2 - �������� ��� � 0\n";
		cout << "\n3 - �������� ���\n";
		cout << "\n4 - �������� ���\n";
		cout << "\n0 - �����\n";
		cin >> choice;

		switch (choice)
		{	

		case '1':
			cout << "������� ����� ���� >>";
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
			cout << "\n������� ����� �� 0 �� 4: ";
				cin >> choice;
			return;
			
		}





	}	while ((choice >  '0') && (choice < '5'));




	 

}

//void ticTacToe()
//{
//	cout << "�������� ������\n";
//
//	int size;
//
//	cout << "�������  ������ ���� nXn: ";
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
//		cout << "������� ������� �� ����: ";
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
//			cout << "������ ������� ��� ������, ������� ������";
//		}
//
//
//
//		move++;
//
//		
//
//		//posotionIsValid = �������� ��� ������� ��������� � ������ ���� ������
//		
//		//��������� ������ ���� 
//		// �������� ���������� ���� �� ��
//		// 
//		// ������� ������� �� �������� ����������
//
//		// ���� ���������� ���� ������� ���������
//		// ������� �� �������
//	}	
//
//	cout << "�����\n";
//
//
//}
//
//// TO DO ������� ���������� ����� ������������ ������ � �� ������������ ����������� ��� ��������� 
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