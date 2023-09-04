#include "Passenger.h"

const int SizePassengerNames(20);
const char* Test_Passenger_Names[20]
{
	"Ларионов Роман Тимофеевич",
	"Курочкина Варвара Александровна",
	"Румянцева Мия Павловна",
	"Панина Кристина Тимофеевна",
	"Иванов Мирон Кириллович",
	"Галкина Валентина Александровна",
	"Филиппов Антон Никитич",
	"Латышев Ярослав Маркович",
	"Медведев Артём Артёмович",
	"Михайлова Вероника Марковна",
	"Корнеева Наталья Леонидовна",
	"Сидорова Амина Мироновна",
	"Иванова Софья Вадимовна",
	"Михайлова Мария Ивановна",
	"Сидорова Эмилия Егоровна",
	"Соловьева Мария Максимовна",
	"Тимофеев Василий Александрович",
	"Ефимова Анна Даниловна",
	"Иванова Елена Львовна",
	"Князев Даниил Иванович"
};

const int SizeItemNames(30);
const char* Test_Item_Names[30]
{
	"Корзина",
	"Глобус",
	"Аккумулятор",
	"ФайлДляБумаги",
	"Гриб",
	"Табурет",
	"Ведро",
	"Зеркало",
	"Книга",
	"ПлюшеваяИгрушка",
	"Светофор",
	"Телефон",
	"Кость",
	"ВоздушныйШар",
	"КоробкаСока",
	"Молоток",
	"КатушкаНиток",
	"Келгли",
	"Рюкзак",
	"Ракушка",
	"Леденец",
	"Юла",
	"Коробка",
	"Зонт",
	"Якорь",
	"Флешка",
	"Камера",
	"Коралл",
	"Череп",
	"Штаны"
};

// вывод продукта
void printPassenger(const Passenger& pas)
{
	cout << "ФИО пассижира\t\t" << "\tНазвание предмета\t"
		<< "Вес предмета (КГ)\t" << "Кол-во предмета\n";
	cout << pas.name << "\t\t" << pas.itemName << "\t\t\t"
		<< pas.weigth << "\t\t" << pas.numLuggage << "\n\n";
}

void printPassenger(std::ostream& out, const Passenger& pas)
{
	out << pas.name << '\n' << pas.itemName << '\t'
		<< pas.weigth << '\t' << pas.numLuggage << "\n\n";
}

void printPassengers(const Passenger* passenger, unsigned size)
{
	if (!passenger || !size)
	{
		return;
	}

	for (size_t i = 0; i < size; i++)
	{
		cout << "# " << i << '\n';
		printPassenger(passenger[i]);
	}
	cout << '\n';
}

void printPassengers(std::ostream& out, const Passenger* passenger, unsigned size)
{
	if (!passenger || !size)
	{
		return;
	}

	for (size_t i = 0; i < size; i++)
	{
		printPassenger(out, passenger[i]);
		out << '\n';
	}
}

//ввод данных
void inputPassenger(Passenger& pas)
{
	cout << "Введите имя пассажира (ФИО): ";
	getline(cin, pas.name);

	cout << "Введите название предмета: ";
	cin >> pas.itemName;

	cout << "Введите вес предмета: ";
	cin >> pas.weigth;

	cout << "Введите кол-во предмета: ";
	cin >> pas.numLuggage;

	cin.get();
}

void inputPassengers(Passenger* passenger, unsigned size)
{
	if (!passenger || !size)
	{
		return;
	}

	for (size_t i = 0; i < size; i++)
	{
		cout << "Введите пассажира под номером " << i << ": \n";
		inputPassenger(passenger[i]);
	}
}

void fillRndPassenger(Passenger& pas, int min = 1, int max = 20)
{
	if (min > max) std::swap(min, max);

	static int i = 1;
	srand(time(0) * i++);

	int rnd;
	int ind;

	ind = rand() % SizePassengerNames;
	pas.name = Test_Passenger_Names[ind];

	ind = rand() % SizeItemNames;
	pas.itemName = Test_Item_Names[ind];

	rnd = min + rand() % (50 - min + 1);
	pas.weigth = rnd;

	rnd = min + rand() % (5 - min + 1);
	pas.numLuggage = rnd;
}

void fillRndPassengers(Passenger* passenger, unsigned size)
{
	if (!passenger || !size)
	{
		return;
	}

	for (size_t i = 0; i < size; i++)
	{
		fillRndPassenger(passenger[i]);
	}
}

int countPassengerInFile(std::ifstream& ifile)
{
	int count(0);

	if (!ifile.is_open())
	{
		return -1;
	}

	string str;
	while (!ifile.eof())
	{
		getline(ifile, str);

		if (!str.empty())
			count++;
	}

	count /= 2;

	return count;
}

void inputPassenger(std::istream& in, Passenger& pas)
{
	if (in.bad())
		return;

	do
	{
		std::getline(in, pas.name);
	} while (!in.eof() && pas.name.empty());

	in >> pas.itemName;
	in >> pas.weigth;
	in >> pas.numLuggage;
}

void inputPassengers(std::ifstream& in, const std::string& fileName,
					Passenger*& passenger, unsigned& size)
{
	if (!in.is_open())
	{
		return;
	}

	int passengerCount = countPassengerInFile(in);
	if (passengerCount <= 0)
		return;

	size = passengerCount;
	allocateMemory(passenger, size);

	in.close();
	in.open(fileName);

	if (!in.is_open())
	{
		cout << "Не удалось переоткрыть файл " << fileName << '\n';
		return;
	}

	for (size_t i = 0; i < size; i++)
	{
		inputPassenger(in, passenger[i]);
	}
}

// обработка данных

void passengerWeigth(const Passenger* pas, unsigned size)
{
	if (!pas || !size)
	{
		return;
	}

	int tmp(0);

	for (size_t i = 0; i < size; i++)
	{
		if (pas[i].weigth > 30)
		{
			tmp++;
		}
	}
	if (tmp >= 1)
	{
		cout << "Число пассажиров с багажом более 30 кг: " << tmp << endl;
	}
	else
		cout << "Пассажиров с багажом более 30 кг нет!";
}

void passengerWeigthOneItem(const Passenger* pas, unsigned size)
{
	if (!pas || !size)
	{
		return;
	}

	for (size_t i = 0; i < size; i++)
	{
		if ((pas[i].weigth / pas[i].numLuggage) > 20)
		{
			cout << "Пассажир с предметом более 20 кг: " << endl;
			printPassenger(pas[i]);
		}
	}
}

float averageWeigth(Passenger*& pas, unsigned size, unsigned num)
{
	if (num >= size)
		return -1;

	return ((float)pas[num].weigth / (float)pas[num].numLuggage);
}

void passengerAverageWeigth(Passenger* pas, unsigned size)
{
	unsigned short num(0);
	float average(0);

	cout << "Введите номер пассажира: ";
	while (!(cin >> num))
	{
		cin.clear();
		cin.ignore();
		cout << "Введите номер пассажира: ";
	}
	average = averageWeigth(pas, size, num);

	cout << "\nСредний вес пассажира №" << num << " = " << average << '\n';
}

double averageWeigthAll(Passenger*& pas, unsigned size, float& average)
{
	average = 0;

	for (size_t i = 0; i < size; i++)
	{
		average += averageWeigth(pas, size, i);
	}

	return average;
}

void passengerWeightMoreAverage(Passenger*& pas, unsigned size)
{
	if (!pas || !size)
		return;

	unsigned short tmp(0);
	float average(0), buf(0);

	averageWeigthAll(pas, size, average);

	cout << "\nОбщий средний вес = " << average;

	for (size_t i = 0; i < size; i++)
	{
		buf = pas[i].weigth / pas[i].numLuggage;

		if (buf > average)
		{
			tmp++;
		}
	}

	cout << "\nЧисло пассажиров с весом багажа более среднего: "
		<< tmp << endl;
}

// функции диалога с пользователем

void inputPassengerFromStdIn(Passenger*& passenger, unsigned& size)
{
	cout << "Сколько пассажиров хотите создать? ";

	if (!(cin >> size))
	{
		cout << "Ошибка ввода\n";
		cin.clear();
		cin.ignore();
		return;
	}
	cin.get();

	allocateMemory(passenger, size);
	inputPassengers(passenger, size);
}

void inputRndPassengers(Passenger*& passenger, unsigned& size)
{
	cout << "Сколько пассажиров хотите создать? ";

	if (!(cin >> size))
	{
		cout << "Ошибка ввода\n";
		cin.clear();
		cin.ignore();
		return;
	}
	cin.get();

	allocateMemory(passenger, size);
	fillRndPassengers(passenger, size);
}

void inputPassengerFromFile(Passenger*& passenger, unsigned & size)
{
	cout << "Введите имя файла для чтения пассажиров: ";

	std::string fileName;
	std::getline(cin, fileName);

	std::ifstream file(fileName, std::ios::in);

	if (!file.is_open())
	{
		cout << "Ошибка открытия файла на чтение\n";
		return;
	}

	inputPassengers(file, fileName, passenger, size);

	file.close();
}

void printPassengerToFile(const Passenger* passengers, const unsigned size)
{
	if (!passengers || !size)
	{
		cout << "Ошибка данных при записи в файл\n";
		return;
	}

	cout << "Введите имя файла для печати пассажиров: ";

	std::string fileName;
	std::getline(cin, fileName);

	std::ofstream file(fileName, std::ios_base::app);

	if (!file.is_open())
	{
		cout << "Ошибка открытия файла на записи\n";
		return;
	}

	printPassengers(file, passengers, size);

	file.close();
}

bool cmpPassengerName(Passenger pasA, Passenger pasB)
{
	if (pasA.name > pasB.name)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool cmpPassengerItemName(Passenger pasA, Passenger pasB)
{
	if (pasA.itemName > pasB.itemName)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int cmpPassengerWeigth(const void* pasA, const void* pasB)
{
	Passenger* xpas = (Passenger*)pasA;
	Passenger* ypas = (Passenger*)pasB;

	if (xpas->weigth < ypas->weigth)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

int cmpPassengerNumLuggage(const void* pasA, const void* pasB)
{
	Passenger* xpas = (Passenger*)pasA;
	Passenger* ypas = (Passenger*)pasB;

	if (xpas->numLuggage < ypas->numLuggage)
	{
		return 1;
	}
	else
	{
		return -1;
	}
	return 1;
}

void printPassengerHelp()
{
	cout << "-1 Ввод с клавиатуры\n";
	cout << "-2 Ввод из файла\n";
	cout << "-3 Генерация случайных товаров\n\n";

	cout << "-4 Вывод на экран\n";
	cout << "-5 Запись в файл\n\n";

	cout << "-6 Число пасссажиров с багажом более 30 кг\n";
	cout << "-7 Пассажиры с вещью более 20 кг\n";
	cout << "-8 Средний вес багажа пассажира\n";
	cout << "-9 Число пассажиров с весом багажа более среднего\n";
	cout << "-10 Сортировка по имени пассажира\n";
	cout << "-11 Сортировка по имени багажа\n";
	cout << "-12 Сортировка по весу багажа\n";
	cout << "-13 Сортировка по кол-ву вещей\n\n";

	cout << "-h Справка\n";
	cout << "-q Выход\n\n";
}

void passengerTest()
{
	cout << "\t\tОперации со структурой пассажиров\n\n";

	unsigned sizePassenger = 0;
	Passenger* passenger = nullptr;

	char buf[256] = { 0 };
	char choice[128] = { 0 };

	printPassengerHelp();

	while (strcmp(choice, "q"))
	{
		memset(buf, 0, sizeof(buf));
		memset(choice, 0, sizeof(choice));

		cout << "Введите пункт меню: \n";
		gets_s(buf, sizeof(buf));
		sscanf_s(buf, "-%s", choice, sizeof(choice));

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
				printPassengerHelp();
			}
			else
			{
				cout << "неизвестный выбор\n";
			}
			break;
		}
		case 1:
		{
			inputPassengerFromStdIn(passenger, sizePassenger);
			break;
		}
		case 2:
		{
			inputPassengerFromFile(passenger, sizePassenger);
			break;
		}
		case 3:
		{
			inputRndPassengers(passenger, sizePassenger);
			break;
		}
		case 4:
		{
			printPassengers(passenger, sizePassenger);
			break;
		}
		case 5:
		{
			printPassengerToFile(passenger, sizePassenger);
			break;
		}
		case 6:
		{
			passengerWeigth(passenger, sizePassenger);
			break;
		}
		case 7:
		{
			passengerWeigthOneItem(passenger, sizePassenger);
			break;
		}
		case 8:
		{
			passengerAverageWeigth(passenger, sizePassenger);
			break;
		}
		case 9:
		{
			passengerWeightMoreAverage(passenger, sizePassenger);
			break;
		}
		case 10:
		{
			bubleSort(passenger, sizePassenger, cmpPassengerName);
			break;
		}
		case 11:
		{
			choiceSort(passenger, sizePassenger, cmpPassengerItemName);
			break;
		}
		case 12:
		{
			qsort(passenger, sizePassenger, sizeof(Passenger), cmpPassengerWeigth);
			break;
		}
		case 13:
		{
			qsort(passenger, sizePassenger, sizeof(Passenger), cmpPassengerNumLuggage);
			break;
		}
		default:
		{
			cout << "Неизвестный выбор\n";
			break;
		}
		}
	}

	delete[] passenger;
}
