#include "secretKey.h"

const int SizeUsersNames(20);
const char* Test_Users_Names[20]
{
	"Oeyanic",
	"Enashayl",
	"Vanel",
	"Binhaaaa",
	"Ntinowa",
	"Llianan",
	"Hitt",
	"Xolas",
	"Keahineth",
	"Fiachild",
	"Emanni",
	"Sophenana",
	"Farald",
	"Gelian",
	"Quasa",
	"Juni",
	"Lencele",
	"Ynnardah",
	"Parkadelf",
	"Pablita"
};

/*
		time_t now = time(0);
        char dateExp[16]  = {0};
        char dateCreate[16]  = {0};

        tm dateExpTm = *localtime(&now);
        dateExpTm.tm_year += 1;
        time_t exp = mktime(&dateExpTm);
*/



void printInfoKey(const SecretKey& key)
{
	struct tm timeTmOne {};
	struct tm timeTmTwo {};
	char dateStrOne[60] = { 0 };
	char dateStrTwo[60] = { 0 };

	timeTmOne = *localtime(&key.creationDate);
	timeTmTwo = *localtime(&key.expiryDate);

	strftime(dateStrOne, sizeof(dateStrOne), LONG_TIME_FORMAT, &timeTmOne);
	strftime(dateStrTwo, sizeof(dateStrTwo), LONG_TIME_FORMAT, &timeTmTwo);

	cout << "Имя пользователя: " << key.creatorName <<
		"\nДата создание: " << dateStrOne <<
		"\nДата окончания ключа: " << dateStrTwo <<
		"\nИмя комплекта ключей: " << key.keySetName <<
		"\nОписание: " << key.description;
}

void printInfoKeys(const SecretKey* key, unsigned size)
{
	if (!key || !size)
	{
		cout << "Нет информации о файле! №1";
		return;
	}

	for (size_t i = 0; i < size; i++)
	{
		cout << "Файл #" << i + 1 << '\n';
		printInfoKey(key[i]);
	}
}

void printInfoKey(std::string fileName, const SecretKey& key)
{
	ofstream out(fileName, std::ios::binary);

	out << key.creatorName << '\n' << key.creationDate << '\n'
		<< key.expiryDate << '\n' << key.keySetName << '\n'
		<< key.description << '\n' << key.secretKey << '\n';
}

void inputInfoKey(SecretKey& key)
{
	cout << "Введите имя пользователя (64 символа): ";
	cin.getline(key.creatorName, 64);
	system("CLS");

	time_t now = time(0);
	tm timeOne = *localtime(&now);
	tm timeExpiry;
	int buf;

	cout << "Введите дату окончания ключа (1, 2 или 3 года): ";
	cin >> buf;
	cin.ignore();
	system("CLS");

	if (buf > 4 || buf < 0)
	{
		cout << "Введён неправильный год!";
	}

	timeExpiry = timeOne;
	timeExpiry.tm_year += buf;
	key.expiryDate = mktime(&timeExpiry);

	cout << "Введите имя комплекта ключей (20 символов): ";
	cin.getline(key.keySetName, 20);
	system("CLS");

	cout << "Введите описание (64 символа): ";
	cin.getline(key.description, 64);
	system("CLS");

	cout << "Введите секрутный ключ (32 символа): ";
	cin.getline(key.secretKey, 32);
	system("CLS");
}

void fillRndInfoKey(SecretKey& key)
{
	static int i = 1;
	srand(time(0) * i++);

	int rnd = 1 + rand() % 19;

	strncpy(key.creatorName, Test_Users_Names[rnd], strlen(Test_Users_Names[rnd]));

	time_t now = time(0);
	tm timeOne = *localtime(&now);
	key.creationDate = mktime(&timeOne);

	tm timeExpiry;
	int year(0);

	year = 1 + rand() % (4 - 1);

	timeExpiry = timeOne;
	timeExpiry.tm_year += year;
	time_t exp = mktime(&timeExpiry);
	key.expiryDate = exp;


	std::string str = "Key";
	str += to_string(rnd);
	strncpy(key.keySetName, str.c_str(), sizeof(str));

	for (size_t i = 0; i < sizeof(key.secretKey); i++)
	{
		key.secretKey[i] = rndLetterGenerate_();
	}
	key.secretKey[31] = 0;

	str = "Стандартный набор ключей №" + to_string(rnd);
	strncpy(key.description, str.c_str(), sizeof(str));
}

int counstKeyInFile(std::ifstream& ifile)
{
	int count(0);

	if (!ifile.is_open())
	{
		cout << "Ошибка с подсчётом файла №1";
		return -1;
	}

	string str;

	while (!ifile.eof())
	{
		getline(ifile, str);

		if(!str.empty())
		count++;
	}

	count /= 6;

	return count;
}

void inputSecretKey(std::istream& in, SecretKey& key)
{
	if (in.bad())
		return;

	tm timeSt;
	std::string str;
	unsigned int num;

	getline(in, str);
	strncpy(key.creatorName, str.c_str(), sizeof(str));

	in >> num;
	key.creationDate = num;

	in >> num;
	key.expiryDate = num;

	for (size_t i = 0; i < 2; i++)
	{
		getline(in, str);
		strncpy(key.keySetName, str.c_str(), sizeof(str));
	}

	getline(in, str);
	strncpy(key.description, str.c_str(), sizeof(str));

	getline(in, str);
	strncpy(key.secretKey, str.c_str(), sizeof(str));
}

void inputFileInStd(std::string fileName, SecretKey& key)
{
	ifstream in(fileName, std::ios::binary);
	if (!in.is_open())
	{
		return;
	}

	int sizeSecretKey = counstKeyInFile(in);
	if (sizeSecretKey <= 0)
		return;

	in.close();
	in.open(SECRET_KEY_FILE);

	if (!in.is_open())
	{
		cout << "Не удалось открыть файл " << SECRET_KEY_FILE << '\n';
		return;
	}

	inputSecretKey(in, key);
}

void createCodeNotepad(SecretKey& key)
{
	fillRndInfoKey(key);

	cout << "\nСтруктура сгенерирована в файл!\n";
}

void secretKeyTest()
{
	char ch;
	string menu[] = { "Создать бинарный файл", "Запись структуры В файла",
		"Ввод структуры ИЗ файла", "Вывод на экран",
		"Зашифровать", "Расшифровать","Выход" };
	int active_menu = 0;

	SecretKey key;

	while (true)
	{
		int x(50), y(13);
		GoToXY(50, 13);

		for (size_t i = 0; i < size(menu); i++)
		{
			if (i == active_menu)
			{
				SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
			}
			else
			{
				SetConsoleTextAttribute(hStdOut, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			}

			GoToXY(x, y++);
			cout << menu[i] << '\n';
		}
		ch = _getch();
		if (ch == -32) ch = _getch();

		switch (ch)
		{
		case ESCAPE:
		{
			exit(0);
		}
		case UP:
		{
			if (active_menu > 0)
			{
				--active_menu;
			}
			break;
		}
		case DOWN:
		{
			if (active_menu < size(menu) - 1)
			{
				++active_menu;
			}
			break;
		}
		case ENTER:
			switch (active_menu)
			{
			case 0:
			{
				system("CLS");
				GoToXY(x, y);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN
					| FOREGROUND_INTENSITY);

				createCodeNotepad(key);

				_getch();
				system("CLS");
				break;
			}
			case 1:
			{
				system("CLS");
				GoToXY(55, 3);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN
					| FOREGROUND_INTENSITY);

				printInfoKey(SECRET_KEY_FILE, key);

				_getch();
				system("CLS");
				break;
			}
			case 2:
			{
				system("CLS");
				GoToXY(0, 0);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN
					| FOREGROUND_INTENSITY);

				inputFileInStd(SECRET_KEY_FILE, key);

				_getch();
				system("CLS");
				break;
			}
			case 3:
			{
				system("CLS");
				GoToXY(x, y);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN
					| FOREGROUND_INTENSITY);

				printInfoKey(key);

				_getch();
				system("CLS");
				break;
			}
			case 4:
			{
				system("CLS");
				GoToXY(x, y);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN
					| FOREGROUND_INTENSITY);

				//encryptMenu(key);

				_getch();
				system("CLS");
				break;
			}
			case 5:
			{
				system("CLS");
				GoToXY(x, y);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN
					| FOREGROUND_INTENSITY);

				//decryptMenu(key);

				_getch();
				system("CLS");
				break;
			}
			case 6:
				exit(0);
			}
			break;
		default:
		{
		}
		}
	}
}