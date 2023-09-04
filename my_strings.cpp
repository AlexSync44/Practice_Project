#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <ctime>
#include "my_strings.h"

const int aAsciiInd_A = 65;
const int aAsciiInd_Z = 90;
const int aAsciiInd_a = 97;
const int aAsciiInd_z = 122;

using namespace std;

int countWordBeginOn(const char* str, char c)
{
	if (!str)
	{
		return -1;
	}

	int len = strlen(str) + 1;
	char* newStr = new char[len];
	strncpy_s(newStr, len, str, len);

	int count = 0;
	char* word = strtok(newStr, " ,.\t\n");

	while (word != NULL)
	{
		if (word[0] == c) count++;
		word = strtok(NULL, " ,.\t\n");
	}

	delete[] newStr;

	return count;
}

int countWords(const char* str, const char* word)
{
	if (!str)
	{
		return -1;
	}

	int len = strlen(str) + 1;
	char* newStr = new char[len];
	strncpy_s(newStr, len, str, len);

	int count = 0;

	if (strstr (newStr, word));
	{
		count++;
	}

	delete[] newStr;

	return count;
}

int countSentences(const char* str)
{
	if (!str)
	{
		return -1;
	}

	int len = strlen(str) + 1;
	char* newStr = new char[len];
	strncpy_s(newStr, len, str, len);

	int num(0), count = 0;

	for (int i = 0; i <= len; i++)
		if (newStr[i] == '.')
		{
			num++;
		}
	
	delete[] newStr;

	return num;
}

void findAndReplaceStr()
{
	const int maxSize = 1024;
	char str[maxSize]{ 0 };

	printf("Введите строку < 1024:\n");
	cin.getline(str, maxSize);

	char findChar;
	cout << "Введите символ для поиска: ";
	cin >> findChar;
	cout << "Количество слов начинающиеся на "
		<< findChar << " " << countWordBeginOn(str, findChar) << '\n';

	int count = 0;
	char word[128]{ 0 };

	cout << "\nВведите слово для поиска: ";
	cin >> word;

	count += countWords(str, word);

	if (isupper(word[0]))
	{
		word[0] = tolower(word[0]);
	}
	else
	{
		word[0] = toupper(word[0]);
	}

	count += countWords(str, word);

	cout << "Количество слов без учёта регистра "
		<< count << '\n';

	//cout << "Количество предложений = " <<
		//countSentences(str);
}

void pcReplacement()
{
	const int maxSize = 1024;
	char str[maxSize]{ 0 };
	int count = 0;

	cout << "Введите строку < 1024: \n";
	cin.getline(str, maxSize);

	char word[3] = { "пк" };
	count += countWords(str, word);

	if (isupper(word[0]))
	{
		word[0] = tolower(word[0]);
	}
	else
	{
		word[0] = toupper(word[0]);
	}

	count += countWords(str, word);
}

// задача 8 из ВУЗа
void wordSearch()
{
	const int maxSize = 1024;
	char str[maxSize]{ 0 };

	cout << "Введите строчку < 1024: \n";
	cin.getline(str, maxSize);

	char word[1024] = { 0 };
	int count = 0;

	while (cin.peek() != '\n')
	{
		cin >> word;

		if (countWords(str, word))
		{
			count++;
		}
	}
}

// задача 9 из ВУЗа
void countingNumbers()
{
	const int maxSize = 1024;
	char str[maxSize]{ 0 };

	cin.getline(str, maxSize);

	int num = 0;

	for (int i = 0; str[i]; i++)
	{
		if (isdigit(str[i]))

		{
			cout << str[i];

			num++;
		}
	}
	cout << endl << num;
}

//дазача 10
void reverseText()
{
	const char size(20);
	char arr[size];

	cout << "Введите текст: ";
	cin.get(arr, size);

	if (arr && *arr)
	{
		int i;
		for (i = 0; arr[i]; i++);

		for (i -= 1; i >= 0; i--)
		{
			cout << arr[i];
		}
	}
}

void allocateMemory(char**& string, unsigned& size)
{
	if (string)
	{
		return;
	}

	string = new char* [size];
	int len, maxLen(50);

	for (size_t i = 0; i < size; i++)
	{
		len = 1 + rand() % (maxLen);
		string[i] = new char[len];
		string[i][len - 1] = '\0';
	}
}


void clearMemory(char**& string, unsigned& size)
{
	if (!string)
	{
		return;
	}

	for (size_t i = 0; i < size; i++)
	{
		delete[] string[i];
	}

	delete[] string;
	string = nullptr;
	size = 0;
}

char rndLetterGenerate()
{
	static int i = 0;
	srand(time(0) * (++i));

	int A_Z = rand() % 2;
	char rndChar;

	if (A_Z)
	{
		rndChar = aAsciiInd_A + rand() %
			(aAsciiInd_Z - aAsciiInd_A + 1);
	}
	else
	{
		rndChar = aAsciiInd_a + rand() %
			(aAsciiInd_z - aAsciiInd_a + 1);
	}

	return rndChar;
}

void generateStrs(char** strings, int size)
{
	if (!strings)
	{
		return;
	}

	int len = 0;
	for (size_t i = 0; i < size; i++)
	{
		len = strlen(strings[i]);

		for (size_t j = 0; j < len; j++)
		{
			strings[i][j] = rndLetterGenerate();
		}
	}
}

void printStrs(char** strings, int size)
{
	if (!strings)
	{
		return;
	}

	for (size_t i = 0; i < size; i++)
	{
		cout << strings[i] << '\n';
	}
}

void rndStrsTest()
{
	unsigned size = 0;
	char** rndStrs = nullptr;

	cout << "Генерация случайных строк\n";
	cout << "Введите их количество: ";
	cin >> size;

	if (size < 1) return;

	allocateMemory(rndStrs, size);
	generateStrs(rndStrs, size);
	cout << "Сгенерированные строки: \n";
	printStrs(rndStrs, size);
	clearMemory(rndStrs, size);
}

void miniInf()
{	
	const unsigned int size = 50;
	int arr[2]{ 0 };
	char str1[size];
	char str2[size];
	char letter[2]{ 0 };

	cout << "Ввведите своё имя: ";
	cin.getline(str1, size);
	cout << '\n';

	cout << "Ввведите свою фамилию: ";
	cin.getline(str2, size);
	cout << '\n';

	cout << "Какую букву в своих оценках ты отвергаешь? ";
	cin >> letter;
	//for (size_t i = 0; i < 1; ++i)
	//{
	//letter[i];
	//}
	//letter += '1';
	cout << '\n';

	cout << "Введите ваш возраст: ";
	cin >> arr[1];

	cout << "Ваше полное имя: " << str1 << '\n' << str2;
	cout << "Ваш возраст: " << arr[1];
}

// Задачи /\/\
// сделать подфункции без cout и cin


//void caesarCipher()
//{
//	string str;
//
//	int choice;
//	cout << "Шифр Цезаря, выберите действие: \n"
//		<< "1. Зашифровать \n"
//		<< "2. Расшифровать \n";
//
//repeatInput:
//
//	while (!(cin >> choice))
//	{
//		cin.ignore();
//		cin.clear();
//		cout << "Выберите 1 из 2 действий!";
//	}
//
//	if (choice == 1 || choice == 2)
//	{
//		switch (choice)
//		{
//		case 1:
//			encryptionСaesar(str);
//			cout << str;
//			break;
//		case 2:
//			break;
//			cout << "Расшифрованая строка: " << endl;
//			decipheringСaesar(str);
//
//		default:
//			return;
//			break;
//		}
//	}
//	else
//	{
//		goto repeatInput;
//	}
//
//}
//
//void encryptionСaesar(string& str)
//{
//	int numberOfShifts;
//
//	cout << "Введите текст для кодировки: ";
//	getline(cin, str);
//
//	cout << "Введите кол-во сдвигов: ";
//	cin >> numberOfShifts;
//
//	encryptionСaesar(str, numberOfShifts);
//}
//
//void encryptionСaesar(string& str, int shift)
//{	
//	int lenStr;
//	lenStr = (int)str.length();
//
//	for (size_t i = 0; i < lenStr; i++)
//	{
//		if (isalpha(str[i]))
//		{
//			str[i] = tolower(str[i]);
//
//			for (size_t j = 0; j < shift; j++)
//			{
//				if (str[i] == 'z')
//				{
//					str[i] == 'a';
//				}
//				else str[i]++;
//			}
//		}
//	}
//}
//
//string decipheringСaesar(string& str)
//{
//	string str;
//	int count(0), lengthInNumbers, numberOfShifts;
//
//	cout << "Введите кол-во сдвигов: ";
//	cin >> numberOfShifts;
//
//	decipheringСaesar(str, numberOfShifts);
//
//	cout << "Итоговый текст: \n" << str << '\n';
//}
//
//string decipheringСaesar(string& str, int shift)
//{
//	int lengthInNumbers;
//
//	lengthInNumbers = (int)str.length();
//
//	for (size_t i = 0; i < lengthInNumbers; i++)
//	{
//		if (isalpha(str[i]))
//		{
//			str[i] = tolower(str[i]);
//
//			for (size_t j = 0; j < shift; j++)
//			{
//				if (str[i] == 'a')
//				{
//					str[i] == 'z';
//				}
//				else str[i]--;
//			}
//		}
//	}
//}

void checkingMail()
{
	string str;

	cout << "Введите на проверку email: ";
	cin >> str;

	auto pos = str.find("@");
	if (pos != string::npos)
	{
		string str1 = str.substr(0, pos);
		string str2 = str.substr(pos + 1);
	}



}

bool validMailBool(string firstPatrMail, string secondPartMail)
{
	int sizeFirstPartMail, sizeSecondPartMail, x(0);

	sizeFirstPartMail = (int)firstPatrMail.length();
	sizeSecondPartMail = (int)secondPartMail.length();

	if (sizeFirstPartMail < 1 || sizeFirstPartMail >= 64)
	{
		return false;
	}

	if (sizeSecondPartMail < 1 || sizeSecondPartMail > 64)
	{
		return false;
	}

	//if ()
	//{
	//	
	//}

}

//void validIPAddress()
//{
//	string IP;
//	int num;
//
//	cout << "Введите IP адресс: ";
//
//	while (1) {
//		getline(cin, IP);
//		cout << iPVerification(IP) << "\nВведите IP адресс: ";
//		num = getchar();
//		if (num == 13)
//			break;
//	}
//
//	if ()
//	{
//		cout << "Данный IP адресс корректный";
//	}
//	else
//	{
//		cout << "Данный IP адресс некорректный";
//	}
//}
//
//int iPVerification(string IP)
//{
//	std::stringstream validStream;
//	int i(0), n, count(0);
//
//	while (IP[i] != '\0')
//	{
//
//		if (IP[i] != '.')
//		{
//			if (!isdigit(IP[i]))
//			{
//				return 0;
//			}
//		}
//
//		if (IP[i] == '.')
//		{
//			IP[i] = ' ';
//			count++;
//
//			if (count > 3)
//				return 0;
//		}
//
//		validStream << IP[i];
//		i++;
//	}
//
//	while (validStream >> n)
//	{
//		count++;
//		if (n > 255)
//			return 0;
//	}
//
//	if (count != 4)
//	{
//		return 0;
//	}
//
//	return 1;
//}



// задача 3
void miniInformation()
{
	const unsigned int size = 50;
	char str1[size];
	char str2[size];
	char str3[size]{ 0 };

	cout << "Ввведите своё имя: ";
	cin.getline(str1, size);
	cout << '\n';

	cout << "Ввведите свою фамилию: ";
	cin.getline(str2, size);
	cout << '\n';

	strcat(str2, str1);

	cout << "Вот ваши данные в 1 строке: " << str2;
}

// задача 4
void miniInformation2()
{
	string name, surName, merger;
	

	cout << "Введите своё имя: ";
	getline(cin, name);
	cout << "Введите свою фамилию: ";
	getline(cin, surName);

	merger = name + ' ' + surName;

	cout << "Вот ваши данные в 1 строке: " << merger;
}

struct CandyBar
{
	string nameCandy;
	float weigth;
	int calories;
};

void candyBarFunc()
{
	CandyBar snack;

	snack.nameCandy = "Toffifee";
	snack.calories = 74.5;
	snack.weigth = 300;

	cout << "Название конфет: " << snack.nameCandy << '\n';
	cout << "Калорий на 100 грамм: " << snack.calories << '\n';
	cout << "Вес упаковки: " << snack.weigth << '\n';
}

//void candyBarFunc2()
//{
//	const int size = 100;
//	char arr[size]{ 0 };
//	char arr2[size]{ 0 };
//	
//	candyBar snack;
//
//	cout << "Введите название конфет: ";
//	cin.getline(arr, size);
//	
//
//
//}

struct PizzaInformation
{
	string nameOfCompany;
	float diameter;
	float weight;
};

void williamWingeate()
{
	PizzaInformation p;

	cout << "Введите название производителя пиццы: ";
	getline(cin, p.nameOfCompany);

	cout << "Введите диаметр пиццы: ";
	cin >> p.diameter;

	cout << "Введите вес пиццы: ";
	cin >> p.weight;

	cout << "\n\nНазвание компании: " << p.nameOfCompany << '\n';
	cout << "Диаметр пиццы: " << p.diameter << '\n';
	cout << "Вес пиццы: " << p.weight << '\n';
}

void passwordCheck()
{
	string mypass = "samohval";
	string userpass;

	cout << "Введите пароль: ";
	getline(cin, userpass);

	if (userpass == mypass)
	{
		cout << "Доступ разрешён.\n";
	}
	else
	{
		cout << "Неверный пароль\n";
	}
}

void clearingStr()
{
	string line;

	cout << "Введите строку: ";

	getline(cin, line);

	for (size_t i = 0; i < line.size(); i++)
	{
		if (!((line[i] >= 'a' && line[i] <= 'z') || (line[i] >= 'A'
				&& line[i] <= 'Z')))
		{
			line[i] = '\0';
		}
	}

	cout << "Результат: " << line << endl;
}

void countingWithoutFunction()
{
	string str;

	unsigned length;

	cout << "Введите строку: ";

	getline(cin, str);

	for (length = 0; str[length] != '\0'; ++length);

	cout << "Длина: " << length << endl;
}

void sortWord()
{
	string str[10], temp;

	cout << "Введите 10 слов: ";
	for (size_t i = 0; i < 10; ++i)
	{
		getline(cin, str[i]);
	}

	for (int i = 0; i < 9; ++i)
	{
		for (int j = i + 1; j < 10; ++j)
		{
			if (str[i] > str[j])
			{
				temp = str[i];
				str[i] = str[j];
				str[j] = temp;
			}
		}
	}

	cout << "Сортировка: ";

	for (size_t i = 0; i < 10; ++i)
	{
		cout << str[i];
	}
}