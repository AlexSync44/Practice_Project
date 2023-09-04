#include "stringStudy.h"

void stdStringTest()
{
	//если строку изменять не надо
	//то есть хранилище символов
	const char* str = "My name is";

	std::string strOne, strTwo;

	cout << "Введите строку: ";

	std::getline(cin, strOne);
	cout << strOne << "\n";

	//копирование
	strTwo = strOne;

	int len = strOne.length();

	cout << "Длина = " << len << '\n';
	cout << "Обрезанная строка: " << strOne.substr(len / 2) << '\n';

	//конкатеация строка
	strTwo = strTwo + strOne;

	cout << "Сложенная строка: ";
	cout << strTwo << '\n';


	//сравнение строк
	if (strOne.compare(strTwo))
	{
		cout << "Строки не равны\n";
	}

	if (strOne == strTwo)
	{
		cout << "Строки  равны\n";
	}

	//new не надо использовать
	//std::string сама увеличит свой размер
	//Но! чтобы код был быстрее, если мы заранее знаем примерную
	//длину std::string можно предупредить, выделив память

	strTwo.clear();
	strTwo.reserve(256);

	cout << "Памяти выделено: " << strTwo.capacity() << " байт\n";

	//сортировка
	strTwo = "The quick brown fox jumps over the lazy dog";
	std::sort(strTwo.begin(), strTwo.end());
	cout << "\nОтсортированная строка: " << strTwo << '\n';

	//добавить символ в конец
	strTwo.push_back('@');
	strTwo.append(" str ind the end!");
	strTwo.insert(len / 2, " subbbstr! ");

	//заполнить строку на основе символьного массива
	char cStr[64] = "The quick brown fox jumps over the lazy dog2";
	strTwo.assign(cStr);
	cout << "\nАссигнированная строка: " << strTwo << '\n';

	//обратиться к символу
	strTwo.at(0);
	//если хотим изменить
	//strTwo[0] = 'A';

	//возвращает индекс если нашлась подстока
	int ind = strTwo.find("quick");

	//проверка что не найдено
	if (strTwo.find("quick") == std::string::npos)
	{
		cout << "Подcтрока не найдена\n";
	}

	//пустая строка
	if (strTwo.empty())
	{
		cout << "Строка пустая\n";
	}
	else cout << "Строка не пустая\n";

	//удаление части строка
	//с какого индекса и сколько штук
	strTwo.erase(2, 5);

	//Поиск регулярного выражения в строке
	//ищем всё кроме
	regex regExp("[^a-zA-Z ]");

	if (regex_search(strTwo, regExp))
	{
		cout << "Содержаться недопустимые символы\n";
	}
}

void stringCTest()
{
	//строка как статический массив
	const int size = 1024;
	const int size2 = size / 2;
	char str1[size] = "Hello world!";
	char str2[size2] = { 'H', 'e', 'l', 'l', 'o', '\0' };

	printf("Введите строку\n");
	//заполнение с консоли
	//считаем слово до пробельного символа
	//scanf_s("%s", buf, size);
	//cin >> 
	gets_s(str1, size);
	//cin.getline(str1,bif size);

	//чтение символа
	//char c = cin.get();

	printf("%s\n", str1);
	//cout << str1 << '\n';

	int len = strlen(str1);
	printf("Длина строки = %d\n", len);

	//методы копирования строк
	//1
	memset(str2, 0, size2);
	memcpy(str2, str1, len * sizeof(char) + 1);
	printf("Скопированная строка: %s\n", str2);

	//2
	//копирование в формате
	printf("Введите строку\n");
	gets_s(str1);
	memset(str2, 0, size2);
	snprintf(str2, size2, "Скопированная строка: %s\n", str1);
	printf("%s\n", str2);

	//конкатеация строка
	strncat_s(str1, str2, strlen(str2));
	printf("сумма строк: %s\n", str1);

	// разбиение на подстроки
	//gets_s(str1);

	//strstr - вернёт указатель на место в строке

	//char* pBuf = str1;
	//int subLen = strlen(strstr(pBuf, "1"));
	//while (subLen != 0)
	//{
	//	subLen = strlen(strstr(pBuf, "1"));
	//	pBuf += subLen;
	//	printf("%s\n", pBuf);
	//}

	//сравнение

	if (!strcmp("dd", "dd"))
	{
		printf("Строки равны\n");
	}
}

void sstreamTest()
{
	/*
	Зачем используем:
		1) разбиение строки на слова

		2) Перевод строки в другие типы данных и наоборот
		То есть удобно переводить из чисел в строку и
		из строки в число.

		stdout, stdin - консольные потоки
		ifstream, ofstream - файловые потоки
		sstream - строковый поток

	*/
	string text = "The quick brown fox jumps over the lazy dog";

	std::stringstream strm(text);

	cout << "Строка в потоке: " << text << endl;

	int count = 0;
	string word;

	while (!strm.eof())
	{
		strm >> word;
		count++;
	}

	cout << "В строке " << count << " слов\n";

	string numbers = "1 2 3.14 09 1 ";
	strm.clear();
	strm.seekg(0);

	strm << numbers;
	//число делаем строкой
	strm << 101 << " " << 220;

	double num = 0, sum = 0;

	while (strm >> num)
	{

		sum += num;
		cout << num << " ";

	}

	cout << endl << "Сумма чисел = " << sum << endl;
}