//#define _CRT_SECURE_NO_WARNINGS
//
//#include "Cryptoprotection.h"
//
//
//const int SizeDevopNames(20);
//const char* Test_Devop_Names[20]
//{
//	"Ларионов Роман Тимофеевич",
//	"Курочкина Варвара Александровна",
//	"Румянцева Мияритс Павловна",
//	"Панина Кристина Тимофеевна",
//	"Иванов Миронов Кириллович",
//	"Галкина Валентина Александровна",
//	"Филиппов Антонио Никитич",
//	"Латышев Ярослав Маркович",
//	"Медведев Артём Артёмович",
//	"Михайлова Вероника Марковна",
//	"Корнеева Наталья Леонидовна",
//	"Сидорова Амина Мироновна",
//	"Иванова Софья  Вадимовна",
//	"Михайлова Мария Ивановна",
//	"Сидорова Эмилия Егоровна",
//	"Соловьева Мария Максимовна",
//	"Тимофеев Василий Александрович",
//	"Ефимова Анастасия Даниловна",
//	"Иванова Елена  Даниловна",
//	"Князев Даниил  Сергеевич"
//};
//
//const int SizeEncryptionNames(10);
//const char* Test_Encryption_Names[10]
//{
//	"ROT1			",
//	"ROT2			",
//	"Азбука Морзе		",
//	"Шифр Цезаря		",
//	"Моноалфавитная замена	",
//	"Шифр Виженера		",
//	"Шифр Энигмы		",
//	"Двоичный код		",
//	"A1Z26			",
//	"Шифрование публичным ключом"
//};
//
//void printAllSKZI()
//{
//	for (size_t i = 0; i < SizeEncryptionNames; i++)
//	{
//		cout << Test_Encryption_Names[i] << endl;
//	}
//}
//
//void cleaMemory(Cryptoprotection*& crypto)
//{
//	if (crypto)
//	{
//		delete[] crypto;
//		crypto = nullptr;
//	}
//}
//
//void allocateMemory(Cryptoprotection*& crypto, unsigned size)
//{
//	cleaMemory(crypto);
//
//	crypto = new Cryptoprotection[size];
//}
//
//// ввод
//void printCrypto(const Cryptoprotection& crypto)
//{
//	cout << "ФИО разработчика\t\t" << "Номер версии ПО\t"
//		<< "\t\tНазвание алгоритма\t\t\t" << "Лицензия ФСБ\n";
//	cout << crypto.devName << "\t\t" << crypto.numVersion << "\t\t\t"
//		<< crypto.algoritName << "\t\t";
//	if (crypto.license == true)
//	{
//		cout << "да" << "\n";
//	}
//	else
//	{
//		cout << "нет" << "\n";
//	}
//}
//
//void printCrypto(std::ostream& out, const Cryptoprotection& crypto)
//{
//	out << crypto.devName << '\n' << crypto.numVersion << '\n'
//		<< crypto.algoritName << '\n' << crypto.license << "\n\n";
//}
//
//void printCrypts(const Cryptoprotection* crypto, unsigned size)
//{
//	if (!crypto || !size)
//	{
//		return;
//	}
//
//
//	for (size_t i = 0; i < size; i++)
//	{
//		cout << "\n# " << i << '\n';
//		printCrypto(crypto[i]);
//	}
//	cout << '\n';
//}
//
//void printCrypts(std::ostream& out, const Cryptoprotection* crypto, unsigned size)
//{
//	if (!crypto || !size)
//	{
//		return;
//	}
//
//	for (size_t i = 0; i < size; i++)
//	{
//		printCrypto(out, crypto[i]);
//		out << '\n';
//	}
//}
//
//// вывод данных
//void inputStudent(Cryptoprotection& crypto)
//{
//	cout << "Введите имя разработчика (ФИО): ";
//	getline(cin, crypto.devName);
//
//	cout << "Введите номер версии ПО: ";
//	cin >> crypto.numVersion;
//
//	cout << "Введите название алгоритма: ";
//	getline(cin, crypto.algoritName);
//
//	cout << "Имется ли лицензия ФСБ? да/нет (1/0): ";
//	cin >> crypto.license;
//}
//
//void inputCrypts(Cryptoprotection* crypto, unsigned size)
//{
//	if (!crypto || !size)
//	{
//		return;
//	}
//
//	for (size_t i = 0; i < size; i++)
//	{
//		cout << "Введите разработчика под номером " << i << ": \n";
//		inputStudent(crypto[i]);
//	}
//}
//
//double frand(const double min, const double max)
//{
//	return min + 1.0 * rand() / RAND_MAX * (max - min);
//}
//
//void fillRndStudent(Cryptoprotection& crypto, int min = 0, int max = 1)
//{
//	if (min > max) std::swap(min, max);
//
//	static int i = 1;
//	srand(time(0) * i++);
//
//	double rnd(0);
//	int ind;
//
//	ind = rand() % SizeDevopNames;
//	crypto.devName = Test_Devop_Names[ind];
//
//	rnd = frand(2, 20);
//	crypto.numVersion = rnd;
//
//	ind = rand() % SizeEncryptionNames;
//	crypto.algoritName = Test_Encryption_Names[ind];
//
//	rnd = rand() % 2;
//	crypto.license = rnd;
//}
//
//void fillRndStudents(Cryptoprotection* crypto, unsigned size)
//{
//	if (!crypto || !size)
//	{
//		return;
//	}
//
//	for (size_t i = 0; i < size; i++)
//	{
//		fillRndStudent(crypto[i]);
//	}
//}
//
//int countCryptoInFile(std::ifstream& ifile)
//{
//	int count(0);
//
//	if (!ifile.is_open())
//	{
//		return -1;
//	}
//
//	string str;
//
//	while (!ifile.eof())
//	{
//		getline(ifile, str);
//
//		if (!str.empty())
//			count++;
//	}
//
//	count /= 4;
//	return count;
//}
//
//void inputCrypto(std::istream& in, Cryptoprotection& crypto)
//{
//	if (in.bad())
//		return;
//
//	do
//	{
//		getline(in, crypto.devName);
//	} while (!in.eof() && crypto.devName.empty());
//
//	in >> crypto.numVersion;
//	do
//	{
//		getline(in, crypto.algoritName);
//	} while (!in.eof() && crypto.algoritName.empty());
//	in >> crypto.license;
//}
//
//void inputCrypts(std::ifstream& in, const string& fileName,
//	Cryptoprotection*& crypto, unsigned& size)
//{
//	if (!in.is_open())
//	{
//		return;
//	}
//
//	int cryptoCount = countCryptoInFile(in);
//	if (cryptoCount <= 0)
//		return;
//
//	size = cryptoCount;
//	allocateMemory(crypto, size);
//
//	in.close();
//	in.open(fileName);
//
//	if (!in.is_open())
//	{
//		cout << "Не удалось переоткрыть файл " << fileName << '\n';
//		return;
//	}
//
//	for (size_t i = 0; i < size; i++)
//	{
//		inputStudent(in, crypto[i]);
//	}
//}
//
//void printCalculAlgorithm(int alg1, int alg2, int alg3, int alg4,
//	int alg5, int alg6, int alg7, int alg8, int alg9, int alg10)
//{
//	cout << "\nROT1 - был использован: " << alg1 << " раз(а)\n";
//	cout << "ROT2 - был использован: " << alg2 << " раз(а)\n";
//	cout << "Азбука Морзе - был использован: " << alg3 << " раз(а)\n";
//	cout << "Шифр Цезаря - был использован: " << alg4 << " раз(а)\n";
//	cout << "Моноалфавитная замена - был использован: " << alg5 << " раз(а)\n";
//	cout << "Шифр Виженера - был использован: " << alg6 << " раз(а)\n";
//	cout << "Шифр Энигмы - был использован: " << alg7 << " раз(а)\n";
//	cout << "Двоичный - код был использован: " << alg8 << " раз(а)\n";
//	cout << "A1Z26 - был использован: " << alg9 << " раз(а)\n";
//	cout << "Шифрование публичным ключом - был использован: " << alg10 << " раз(а)\n";
//}
//
//// функции диалога с пользователем
//void inputCryptoFromStdIn(Cryptoprotection*& crypto, unsigned& size)
//{
//	cout << "Сколько разработчиков хотите создать? ";
//
//	if (!(cin >> size))
//	{
//		cout << "Ошибка ввода\n";
//		cin.clear();
//		cin.ignore();
//		return;
//	}
//	cin.get();
//
//	allocateMemory(crypto, size);
//	inputCrypts(crypto, size);
//}
//
//void inputRndCrypto(Cryptoprotection*& crypto, unsigned& size)
//{
//	cout << "Сколько разработчиков хотите создать? ";
//
//	if (!(cin >> size))
//	{
//		cout << "Ошибка ввода\n";
//		cin.clear();
//		cin.ignore();
//		return;
//	}
//	cin.get();
//
//	allocateMemory(crypto, size);
//	fillRndStudents(crypto, size);
//}
//
//void inputCryptoFromFile(Student*& crypto, unsigned& size)
//{
//	cout << "Введите имя файла для чтения разработчиков: ";
//
//	string fileName;
//	getline(cin, fileName);
//
//	std::ifstream file(fileName, std::ios::in);
//
//	if (!file.is_open())
//	{
//		cout << "Ошибка открытия файла на чтение\n";
//		return;
//	}
//
//	inputCrypts(file, fileName, crypto, size);
//
//	file.close();
//}
//
//void printCryptoToFile(const Student* crypto, const unsigned size)
//{
//	if (!crypto || !size)
//	{
//		cout << "Ошибка данных при записи в файл\n";
//		return;
//	}
//
//	cout << "Введите имя файла для печати разработчиков: ";
//
//	string fileName;
//	getline(cin, fileName);
//
//	std::ofstream file(fileName, std::ios_base::app);
//
//	printCrypts(file, crypto, size);
//
//	file.close();
//}
//
//
//
//bool cmpAlgName(Student cryA, Student cryB)
//{
//	if (cryA.algoritName > cryB.algoritName)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//// работа с данными
//void calculTheAlgorithm(Cryptoprotection*& crypto, unsigned size)
//{
//	if (!crypto || !size)
//	{
//		return;
//	}
//
//	int alg1(0), alg2(0), alg3(0), alg4(0), alg5(0),
//		alg6(0), alg7(0), alg8(0), alg9(0), alg10(0);
//
//	for (size_t i = 0; i < size; i++)
//	{
//		const char* strBuf = crypto[i].algoritName.c_str();
//		if (!strcmp("ROT1			", strBuf))
//		{
//			alg1++;
//		}
//		else if (!strcmp("ROT2			", strBuf))
//		{
//			alg2++;
//		}
//		else if (!strcmp("Азбука Морзе		", strBuf))
//		{
//			alg3++;
//		}
//		else if (!strcmp("Шифр Цезаря		", strBuf))
//		{
//			alg4++;
//		}
//		else if (!strcmp("Моноалфавитная замена	", strBuf))
//		{
//			alg5++;
//		}
//		else if (!strcmp("Шифр Виженера		", strBuf))
//		{
//			alg6++;
//		}
//		else if (!strcmp("Шифр Энигмы		", strBuf))
//		{
//			alg7++;
//		}
//		else if (!strcmp("Двоичный код		", strBuf))
//		{
//			alg8++;
//		}
//		else if (!strcmp("A1Z26			", strBuf))
//		{
//			alg9++;
//		}
//		else if(!strcmp("Шифрование публичным ключом", strBuf))
//		{
//			alg10++;
//		}
//		else
//		{
//			cout << "Ошибка подсчёта алгоритмов!";
//		}
//	}
//	printCalculAlgorithm(alg1, alg2, alg3, alg4, alg5,
//		alg6, alg7, alg8, alg9, alg10);
//}
//
//int cmpVersionSoftware(const void* cryA, const void* cryB)
//{
//	Student* xpas = (Student*)cryA;
//	Student* ypas = (Student*)cryB;
//
//	if (xpas->numVersion < ypas->numVersion)
//	{
//		return 1;
//	}
//	else
//	{
//		return -1;
//	}
//}
//
//bool cmpDevName(Student cryA, Student cryB)
//{
//	if (cryA.devName > cryB.devName)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//int cmpLicense(const void* cryA, const void* cryB)
//{
//	Student* xpas = (Student*)cryA;
//	Student* ypas = (Student*)cryB;
//
//	if (xpas->license < ypas->license)
//	{
//		return 1;
//	}
//	else
//	{
//		return -1;
//	}
//}
//
//void printCryptoHelp()
//{
//	cout << "-1 Ввод с клавиатуры\n";
//	cout << "-2 Ввод из файла\n";
//	cout << "-3 Генерация случайных разработчиков\n\n";
//
//	cout << "-4 Вывод на экран\n";
//	cout << "-5 Запись в файл\n\n";
//
//	cout << "-6 Сортировка по имени разработчиков\n";
//	cout << "-7 Сортировка по версии ПО\n";
//	cout << "-8 Сортировка по лицензии ФСБ\n\n";
//
//	cout << "-9 Распечатать все виды шифрования\n";
//	cout << "-10 Посчитать кол-во раз использование алгоритмов\n\n";
//
//	cout << "-h Справка\n";
//	cout << "-q Выход\n\n";
//}
//
//void cryptoTest()
//{
//	cout << "\t\tОперации со структурой криптозащиты\n\n";
//
//	unsigned sizeCrypto = 0;
//	Cryptoprotection* crypto = nullptr;
//
//	char buf[256] = { 0 };
//	char choice[128] = { 0 };
//
//	printCryptoHelp();
//
//	while (strcmp(choice, "q"))
//	{
//		memset(buf, 0, sizeof(buf));
//		memset(choice, 0, sizeof(choice));
//
//		cout << "Введите пункт меню: \n";
//		fgets(buf, sizeof(buf), stdin);
//		sscanf(buf, "-%s", choice, sizeof(choice));
//
//		switch (atoi(choice))
//		{
//		case 0:
//		{
//			if (!strcmp(choice, "q"))
//			{
//				break;
//			}
//			else if (!strcmp(choice, "h"))
//			{
//				printCryptoHelp();
//			}
//			else
//			{
//				cout << "Неизвестный выбор\n";
//			}
//			break;
//		}
//		case 1:
//		{
//			inputCryptoFromStdIn(crypto, sizeCrypto);
//			break;
//		}
//		case 2:
//		{
//			inputCryptoFromFile(crypto, sizeCrypto);
//			break;
//		}
//		case 3:
//		{
//			inputRndCrypto(crypto, sizeCrypto);
//			break;
//		}
//		case 4:
//		{
//			printCrypts(crypto, sizeCrypto);
//			break;
//		}
//		case 5:
//		{
//			printCryptoToFile(crypto, sizeCrypto);
//			break;
//		}
//		case 6:
//		{
//			bubleSort(crypto, sizeCrypto, cmpDevName);
//			break;
//		}
//		case 7:
//		{
//			qsort(crypto, sizeCrypto, sizeof(Student), cmpVersionSoftware);
//			break;
//		}
//		case 8:
//		{
//			qsort(crypto, sizeCrypto, sizeof(Student), cmpLicense);
//			break;
//		}
//		case 9:
//		{
//			printAllSKZI();
//			break;
//		}
//		case 10:
//		{
//			bubleSort(crypto, sizeCrypto, cmpAlgName);
//			calculTheAlgorithm(crypto, sizeCrypto);
//			break;
//		}
//		default:
//		{
//			cout << "Неизвестный выбор\n";
//			break;
//		}
//		}
//	}
//	delete[] crypto;
//}