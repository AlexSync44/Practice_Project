#include "caesarCipher.h"

#ifdef WIN32
#include <conio.h>
#include <windows.h>
#endif

#define CODE_FILE "C:\\Users\\Public\\keys\\keys.bin"

void generateKeys(const char* fileName, int maxLen, int countWord)
{
	std::string str;

	std::ofstream file(fileName);

	int size(0);
	for (size_t i = 0; i < countWord; i++)
	{
		str = rndStringGenerate(rand() % maxLen);
		file << str << ' ';
	}

	file.close();
}

void calcKeys(const char* fileName, int*& keys, int& size)
{
	std::ifstream file(fileName);

	size = countingWords(fileName);

	if (size <= 0) return;

	allocateMemory(keys, size);

	memset(keys, 0, size * sizeof(int));

	unsigned count(0);

	file.seekg(0, std::ios::beg);
	file.clear();

 	while (!file.eof())
	{
		char c = file.get();
		if (isspace(c))
		{
			count++;
		}
		else
		{
			keys[count % size] += c;
		}
	}

	file.close();
}

void encrypt(std::vector<unsigned char>& data, int const* const keys, int size)
{
	if (!keys) return;

	size_t i(0);
	for (auto& elem : data)
	{
		elem += keys[i % size];
		++i;
	}
}

void decrypt(std::vector<unsigned char>& data, int const* const keys, int size)
{
	if (!keys) return;

	size_t i(0);
	for (auto& elem : data)
	{
		elem -= keys[i % size];
		++i;
	}
}

void createCodeNotepad()
{
	int length(0), countWords(0);

	cout << "Введите макс. длину и кол-во слов: ";
	cin >> length >> countWords;

	generateKeys(CODE_FILE, length, countWords);

	GoToXY(50, 13);
	cout << "\nКод сгенерирован в файл!\n";
}

void encryptMenu()
{
	std::vector<unsigned char> data;
	std::string fileName;
	int* keys = nullptr;
	int size(0);

	cout << "Введите имя файла который хотите зашифровать c расширением: ";
	getline(cin, fileName);

	std:fstream file(fileName, std::ios::in | std::ios::binary);
	if (!file.is_open())
	{
		cout << "Не удалось открыть файл!\n";
		return;
	}

	unsigned char byte;
	while (!file.eof())
	{
		file.read((char*)&byte, sizeof(byte));
		data.push_back(byte);
	}

	calcKeys(CODE_FILE, keys, size);
	encrypt(data, keys, size);

	file.close();
	file.open(fileName, std::ios::binary | std::ios::out | std::ios::trunc);

	for (auto& elem : data)
	{
		file.write((char*)elem, sizeof(elem));
	}

	file.close();
}

void decryptMenu()
{
	std::vector<unsigned char> data;
	std::string fileName;
	int* keys = nullptr;
	int size(0);

	cout << "Введите имя файла который хотите расшифровать c расширением: ";
	getline(cin, fileName);

	std:fstream file(fileName, std::ios::out | std::ios::binary);
	if (!file.is_open())
	{
		cout << "Не удалось открыть файл!\n";
		return;
	}

	unsigned char byte;
	while (!file.eof())
	{
		file.read((char*)&byte, sizeof(byte));
		data.push_back(byte);
	}

	calcKeys(CODE_FILE, keys, size);
	decrypt(data, keys, size);

	file.close();
	file.open(fileName, std::ios::binary | std::ios::out | std::ios::trunc);

	for (auto& elem : data)
	{
		file.write((char*)elem, sizeof(elem));
	}

	file.close();
}

void caesarCodeTest()
{
	std::string menu[] = { "Генерация кодового блокнота", "Зашифровка", "Расшифровка", "Выход" };
	std::string fileName;
	char ch = ' ';
	int active_menu = 0;
	int* keys = nullptr;
	int dimension = 1024;

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
				SetConsoleTextAttribute(hStdOut, FOREGROUND_INTENSITY | FOREGROUND_RED
					| FOREGROUND_GREEN | FOREGROUND_BLUE);
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

				createCodeNotepad();

				_getch();
				system("CLS");
				break;
			}
			case 1:
			{
				system("CLS");
				GoToXY(x, y);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN
					| FOREGROUND_INTENSITY);

				encryptMenu();

				_getch();
				system("CLS");
				break;
			}
			case 2:
			{
				system("CLS");
				GoToXY(55, 3);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN
					| FOREGROUND_INTENSITY);

				decryptMenu();

				_getch();
				system("CLS");
				break;
			}
			case 3:
				exit(0);
			}
			break;
		default:
		{
		}
		}
	}
}