#include "STL_Stydy.h"

//enum перечиление - объединение констант
enum Colors
{
	Green,
	Blue = 500,
	Red
};

const std::map<int, const char*> ColorsNames
{
	{Green, "Green"},
	{Blue, "Blue"},
	{Red, "Red"}
};

void stdMapTest()
{
	/*
	std::map - ассоциативный контейнер
	Вместо индекса у элементов другие переменные
	(ключи).
	Ключ - любой тип данных (числа, строки и т.д.)

	В обычном std::map каждый ключ уникален (то есть в одном экземпляре).
	И std::map отсортирован по ключу.

	*/

	std::map <std::string, unsigned> salesInWeek;

	//добавление
	auto sunday = std::pair<std::string, unsigned>("Sunday", 100);
	salesInWeek.insert(sunday);
	auto monday = std::pair<std::string, unsigned>("Monday", 20);
	salesInWeek.insert(monday);
	auto tuesday = std::pair<std::string, unsigned>("Tuesday", 30);
	salesInWeek.insert(tuesday);

	//salesInWeek.emplace("Wensday", 44);

	//печать
	for (const auto& sale : salesInWeek)
	{
		cout << sale.first << " " << sale.second << '\n';
	}

	cout << "Количество = " << salesInWeek.size() << endl;

	auto sunday2 = std::pair<std::string, unsigned>("Sunday", 300);
	salesInWeek.insert(sunday2);

	//печать
	for (const auto& sale : salesInWeek)
	{
		cout << sale.first << " " << sale.second << '\n';
	}
	//удаление
	salesInWeek.erase("Sunday");

	cout << "\nКоличество после удаления = " <<
		salesInWeek.size() << endl;

	//печать
	for (const auto& sale : salesInWeek)
	{
		cout << sale.first << " " << sale.second << '\n';
	}

	if (salesInWeek.empty())
	{
		cout << "Контейнер пустой\n";
	}

	//проверка на содержание ключа
	if (salesInWeek.find("Monday") != salesInWeek.end())
	{
		cout << "at test: " << salesInWeek.at("Monday");
	}
	else
	{
		cout << "Неверно указан ключ\n";
	}
}

void telephoneDirectory()
{
	std::map <int, std::string> dir;
	std::string surname;
	unsigned int number(0);
	unsigned short choice;
	bool isRunning = true;

	while (isRunning)
	{
		system("CLS");

		cout << "1. Добавить номер и фамилию человека\n"
			<< "2. Узнать фамилию абонента по номеру телефона\n"
			<< "3. Узнать номер телефона по фамилии абонента\n"
			<< "4. Завершение программы\n" << '-';
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			cout << "Введите фамилию: ";
			cin.ignore();
			getline(cin, surname);

			cout << "Введите номер: ";
			cin >> number;

			dir.insert(std::pair<int, std::string>(number, surname));

			break;
		}
		case 2:
		{
			cout << "Введите номер телефона: ";
			cin >> number;
			cin.ignore();

			auto it = dir.find(number);

			if (it != dir.end())
			{
				cout << "\nФамилия: " << it->second << endl;
			}
			else
			{
				cout << "Фамилии с таким номером нет";
			}
			cin.get();

			break;
		}
		case 3:
		{
			cout << "Введите фамилию: ";
			cin.ignore();
			getline(cin, surname);

			std::vector <int> keys = findKeys(dir, surname);

			if (keys.empty())
			{
				cout << "Значение не найдено!\n";
			}
			else
			{
				cout << "Вот номера с такой фамилией: ";
				for (const auto& key : keys)
				{
					cout << key << "; ";
				}
			}
			cin.get();

			break;
		}
		case 4:
		{
			isRunning = false;
			break;
		}
		default:
			cout << "Неизвестный выбор!";
			break;
		}

	}
}

void registry()
{
	std::map <int, std::string> dir;
	std::string input;
	int countAdd(1), countCaus(0);
	bool isRunning = true;

	auto it = dir.begin();

	while (isRunning)
	{
		system("CLS");

		cout << "add. Добавить человека в очередь\n"
			<< "next. Вызвать в регистратуру следующего\n"
			<< "list. Посмотреть список всех фамилий\n"
			<< "exit. Завершить программу\n" << '-';
		getline(cin, input);

		if (input.empty())
		{
			cin.ignore();
			continue;
		}

		for (auto& c : input)
		{
			c = tolower(c);
		}

		if (input == "add")
		{
			cout << "Введите фамилию: ";
			getline(cin, input);

			dir.insert(std::pair<int, std::string>(countAdd, input));
			countAdd++;
		}
		else if (input == "next")
		{
			if (dir.empty())
			{
				cout << "В списке нет фамилий!";
			}
			else
			{
				it = dir.begin();
				cout << it->second;
				countCaus = it->first;
				dir.erase(countCaus);
			}
			cin.get();
		}
		else if (input == "list")
		{
			it = dir.begin();
			if (it != dir.end())
			{
				cout << "Фамилии которые остались:\n";
				for (; it != dir.end(); ++it)
				{
					cout << '\n' << it->second;
				}
			}
			else
			{
				cout << "Список пуст!";
			}
			cin.get();
		}
		else if (input == "exit")
		{
			isRunning = false;
		}
		else
		{
			cout << "\nВведено неизвестное действие! |Нажмите любую кнопку, чтобы продолжить|\n\n";
			cin.get();
		}
	}
}

bool isAnagramm_V1(std::string& wordOne, std::string& wordTwo)
{
	if (wordOne.size() != wordTwo.size())
	{
		return false;
	}

	std::sort(wordOne.begin(), wordOne.end());
	std::sort(wordTwo.begin(), wordTwo.end());

	return (wordOne == wordTwo);
}

bool isAnagramm_V2(std::string& wordOne, std::string& wordTwo)
{
	if (wordOne.size() != wordTwo.size())
	{
		return false;
	}

	int scoreOne(0), scoreTwo(0);

	for (auto& elem : wordOne)
	{
		scoreOne += elem;
	}

	for (auto& elem : wordTwo)
	{
		scoreTwo += elem;
	}

	return (scoreOne == scoreTwo);
}

void anargammTest()
{
	std::string firstWord, secondWord;

	std::cout << "Введите первое слово: ";
	getline(std::cin, firstWord);

	std::cout << "Введите второе слово: ";
	getline(std::cin, secondWord);

	isAnagramm_V2(firstWord, secondWord) ? std::cout << "Анаграмма" :
		std::cout << "Не анаграмма";
}

void checkingRequests()
{
	std::map <int, std::string> map;
	std::vector <std::string> vecReq;
	std::string buf;
	int* arr = nullptr;
	auto it = map.begin();
	int size(0), request(0), bufInt(0), count(0);

	std::cout << "Введите кол-во слов: ";
	std::cin >> size;
	std::cin.ignore();

	for (size_t i = 0; i < size; i++)
	{
		getline(cin, map[i]);
	}

	std::cout << "\nВведите кол-во запросов: ";
	std::cin >> request;
	std::cin.ignore();

	arr = new int[request];
	memset(arr, 0, sizeof(int));

	for (size_t i = 0; i < request; i++)
	{
		getline(std::cin, buf);
		vecReq.push_back(buf);
	}

	for (auto vec : vecReq)
	{
		for (auto& elem : map)
		{
			if (elem.second == vec)
			{
				bufInt++;
			}
		}
		if (bufInt != 0)
		{
			arr[count] = bufInt;
			bufInt = 0;
		}
		count++;
	}

	for (size_t i = 0; i < request; i++)
	{
		std::cout << arr[i] << endl;
	}
}

void checkingRequests_Map()
{
	std::map<int, std::string> wordMap;
	std::vector<std::string> requests;
	int size = 0;
	int requestCount = 0;

	std::cout << "Введите кол-во слов: ";
	std::cin >> size;
	std::cin.ignore();

	std::string input;
	for (int i = 0; i < size; i++)
	{
		std::cout << "Введите слово " << (i + 1) << ": ";
		getline(std::cin, input);
		wordMap[i] = input;
	}

	std::cout << "\nВведите кол-во запросов: ";
	std::cin >> requestCount;
	std::cin.ignore();

	for (int i = 0; i < requestCount; i++)
	{
		std::cout << "Введите запрос " << (i + 1) << ": ";
		getline(std::cin, input);
		requests.push_back(input);
	}

	std::vector<int> results(requestCount, 0);

	for (const auto& request : requests)
	{
		for (const auto& wordPair : wordMap)
		{
			if (wordPair.second == request)
			{
				results[&wordPair - &(*wordMap.begin())]++;
			}
		}
	}

	for (const auto& result : results)
	{
		std::cout << result << std::endl;
	}
}

void countingWords()
{
	std::map <std::string, int> dir;
	std::string fileName;

	std::cout << "Введите имя файла: ";
	getline(std::cin, fileName);

	std::fstream file(fileName);
	if (!file.is_open())
	{
		std::cout << "Файл не открывается!";
	}

	while (file >> fileName)
	{
		auto it = dir.begin();
		if (dir.find(fileName) != dir.end())
		{
			dir[fileName]++;
		}
		else
		{
			dir.insert(std::pair <std::string, int>(fileName, 1));
		}
	}

	auto it = dir.begin();

	for (; it != dir.end(); ++it)
	{
		std::cout << it->first << ": " << it->second << '\n';
	}

	file.close();
}

void NumberBefore()
{
	std::map <int, std::string> dir;
	int num;
	int key;

	while ((key = _getch()) != 32)
	{
		std::cin >> num;

		if (dir.find(num) != dir.end())
		{
			std::cout << "YES" << '\n';
		}
		else
		{
			dir.insert(std::pair <int, std::string>(num, "NO"));
			std::cout << "NO" << '\n';
		}
	}
}

void commonLetters()
{
	std::map<char, int> commonLetters;
	std::string word;
	int count = 0;
	bool isRunning = true;

	while (isRunning)
	{
		std::cout << "Введите exit чтобы завершить программу: ";
		std::getline(std::cin, word);

		for (auto& c : word)
		{
			c = tolower(c);
		}

		if (word == "exit")
		{
			isRunning = false;
		}
		else
		{
			std::map<char, bool> letterPresent;
			for (auto& elem : word)
			{
				if (!letterPresent[elem])
				{
					if (commonLetters.find(elem) != commonLetters.end())
					{
						commonLetters[elem]++;
					}
					else
					{
						commonLetters[elem] = 1;
					}
					letterPresent[elem] = true;
				}
			}
			count++;
		}
		system("CLS");
	}

	std::string result;
	for (const auto& elem : commonLetters)
	{
		if (elem.second == count)
		{
			result += elem.first;
		}
	}

	std::sort(result.begin(), result.end());
	std::cout << result << std::endl;
}

//void fileSystem()
//{
//	std::map <std::string, int> dir;
//	std::string s_nameFile;
//	std::vector <int> vi_count;
//	int count(0);
//	bool isRunning(true);
//
//	auto it = dir.begin();
//	while (isRunning)
//	{
//		getline(std::cin, s_nameFile);
//		dir.insert(std::pair<std::string, int>(s_nameFile, 1));
//		
//		while (getline(iss, s_nameFile, '/'))
//		{
//			count++;
//		}
//		if (count > 1)
//		{
//			vi_count.push_back(count);
//		}
//		count = NULL;
//	}
//
//	
//}

void fileSystemRegExp()
{
	std::set <std::string> directories;
	std::regex regExp("/[^/]+/");
	std::smatch match;
	std::string dir;
	bool isRunning = true;

	while (isRunning)
	{
		system("CLS");
		std::cout << "Введите exit для выхода\n\n";
		std::cout << "Введите путь файла: ";
		getline(cin, dir);

		if (dir == "exit")
		{
			break;
		}

		if (std::regex_search(dir, match, regExp))
		{
			std::string directory = match[0];
			directories.insert(directory);
		}
	}
	
	for (const std::string& directory : directories)
	{
		std::cout << directory << endl;
	}
}

void deleteNuminVec()
{
	std::vector <int> vec;
	unsigned size(0);

	cout << "Введите размер массива: ";
	cin >> size;
	cin.ignore();

	int buf(0);
	cout << "Введите числа в массив: ";
	for (size_t i = 0; i < size; i++)
	{
		if (!(cin >> buf))
		{
			cin.ignore();
			cin.clear();
			system("CLS");
			cout << "Введите числа в массив: ";
			continue;
		}
		vec.push_back(buf);
	}

	cout << "Введите цифру который нужно удалить: ";
	cin >> buf;

	vec.erase(remove(vec.begin(), vec.end(), buf), vec.end());

	for (auto elem : vec)
	{
		cout << elem << ' ';
	}
}

void shopBuyVec()
{
	std::vector <float> prices;
	std::vector <int> item;
	int countList(0);

	cout << "Введите количество товаров: ";
	cin >> countList;
	cin.ignore();

	float buf(0.0);
	cout << "\nВведите цену на каждый товар: ";
	for (size_t i = 0; i < countList; i++)
	{
		if (!(cin >> buf))
		{
			cin.ignore();
			cin.clear();
			system("CLS");
			cout << "Введите цену товаров: ";
			continue;
		}
		else
		{
			prices.push_back(buf);
		}
	}

	cout << "\nВведите индекс предметы которые хотите купить или -1 чтобы выйти: ";
	while (true)
	{
		if (!(cin >> buf))
		{
			cin.ignore();
			cin.clear();
			system("CLS");
			cout << "Введите индекс товара: ";
			continue;
		}
		else if (buf == -1)
		{
			break;
		}
		else
		{
			item.push_back(buf);
		}
	}

	float sum(0.0);
	for (auto elem : item)
	{
		sum += prices[elem];
	}

	cout << "\n\n\t\tИтоговая сумма: " << sum;
}

void clearCache()
{
	std::deque<int> cache;
	int num;
	unsigned size;
	bool isRunning = true;

	cout << "Введите размер кэша: ";
	cin >> size;

	cout << "\n\nЧтобы выйти введите -1\n\n";
	while (isRunning)
	{
		cout << "\nВведите число: ";
		cin >> num;

		if (num == -1)
		{
			isRunning = false;
			continue;
		}

		if (cache.size() >= size)
		{
			cache.pop_front();
			cache.push_back(num);
		}
		else
		{
			cache.push_back(num);
		}
	}

	cout << "Список всех цифр: ";
	for (const auto& elem : cache)
	{
		cout << elem << ' ';
	}
}