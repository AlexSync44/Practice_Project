#include "my_struct.h"


const int aAsciiInd_A = 65;
const int aAsciiInd_Z = 90;
const int aAsciiInd_a = 97;
const int aAsciiInd_z = 122;
#define DBG 1

struct Human
{
	const char* name;
	const char* surName;
	unsigned short age;
	float weight;
	unsigned short growth;
};

const char* Test_Name[20]
{
	"Дроздова Елизавета Андреевна",
	"Еремеев Роман Никитич",
	"Ермакова София Михайловна",
	"Захаров Иван Маркович",
	"Зыков Андрей Ярославович",
	"Иванова Ника Яковлевна",
	"Казаков Максим Матвеевич",
	"Казакова Мария Олеговна",
	"Калашникова София Григорьевна",
	"Карпов Максим Артёмович"
	"Бочаров Марк Борисович"
	"Смирнов Николай Евгеньевич"
	"Малышева Диана Львовна"
	"Марков Даниил Тимофеевич"
	"Зубков Максим Маркович"
	"Бондарев Роман Егорович"
	"Евдокимова Полина Степановна"
	"Миронов Степан Дамирович"
	"Мешкова Милана Ивановна"
	"Миронов Иван Германович"
};

const char* Test_Subject_Names[20]
{
	"химия",
	"биология",
	"физика",
	"экология",
	"география",
	"естествознание",
	"астрономия",
	"математика",
	"русский язык",
	"английский",
	"немецкий",
	"китайский",
	"мат. анализ",
	"лийненая алгебра",
	"аналитическая геометрия",
	"введение в специальность",
	"экономика",
	"численные методы",
	"программирование c++",
	"алгоритмы и стуктуры данных"
};

const int SizeProductNames(20);
const char* Test_Product_Names[20]
{
	"Хлеб",
	"Будильник",
	"Кристалл",
	"Яйцо",
	"Гвоздь",
	"Светофор",
	"Варежка",
	"Фонарь",
	"Куб",
	"Маска",
	"Магнит",
	"Бант",
	"Зонт",
	"Облако",
	"Ложка",
	"Келгли",
	"Леденец",
	"Мегафон",
	"Глобус",
	"Барабан"
};

//struct Crypto
//{
//	string name;
//	short grade;
//	short gradeMath;
//	short gradePhysics;
//	short gradeProg;
//	short rndGrade1;
//	short rndGrade2;
//	short rndGrade3;
//};

//void fillStudent(Crypto& student)
//{
//	srand(time(0));
//
//	int ind = rand() % 20;
//	student.name = Test_Name[ind];
//
//	int rnd = (2 + rand() % 3);
//	student.gradeMath = rnd;
//	student.gradePhysics = rnd;
//	student.gradeProg = rnd;
//}


//void rndStudentAndGrades(Crypto& student)
//{
//	srand(time(0));
//
//
//	int ind = rand() % 20;
//	student.name = Test_Name[ind];
//
//	int rnd = (2 + rand() % 3);
//	student.rndGrade1 = rnd;
//	student.rndGrade2 = rnd;
//	student.rndGrade3 = rnd;
//
//	cout << "Оценка по предмету " << Test_Subject_Names[ind] << ": " << student.rndGrade1;
//	cout << "Оценка по предмету " << Test_Subject_Names[ind] << ": " << student.rndGrade2;
//	cout << "Оценка по предмету " << Test_Subject_Names[ind] << ": " << student.rndGrade3;
//}

struct Cryptoprotection
{
	char name[50];
	int roll;
	int group;
	int mark;
};

void studentT()
{
	Cryptoprotection student;

	cout << "\t\tИнформация о студенте\n";
	cout << "\nИмя: ";
	cin >> student.name;
	cout << "Курс: ";
	cin >> student.roll;
	cout << "Группа: ";
	cin >> student.group;
	cout << "Оценка: ";
	cin >> student.mark;

	cout << "\n\nОтображение информации!";
	cout << "\nИмя: " << student.name;
	cout << "\nКурс: " << student.roll;
	cout << "\nГруппа: " << student.group;
	cout << "\nОценка: " << student.mark;
}

struct Dustance
{
	int f;
	float meters;
} d1, d2, sum;

void sumMeters()
{
	cout << "\t\tПервая структура";
	cout << "\nКоличество шагов: ";
	cin >> d1.f;
	cout << "Количество метров: ";
	cin >> d1.meters;

	cout << "\n\t\tВторая структура";
	cout << "\nКоличество шагов: ";
	cin >> d2.f;
	cout << "Количество метров: ";
	cin >> d2.meters;

	sum.f = d1.f + d2.f;
	sum.meters = d1.meters + d2.meters;

	cout << "\n\t\tСумма шагов и метров";
	cout << "\nСумма шагов: " << sum.f;
	cout << "\nСумма метров: " << sum.meters << "\n\n";
}

//typedef struct complex
//{
//	float real;
//	float imag;
//} complexNumber;
//
//complexNumber add(complex n1, complex n2)
//{
//	complex temp;
//
//	temp.real = n1.real + n2.real;
//	temp.imag = n1.imag + n2.imag;
//
//	return(temp);
//}
//
//void sumOfStruct()
//{
//	complexNumber n1, n2, temporaryNumber;
//	char signOfImag;
//
//	cout << "\t\tПервое комплексное число\n";
//	cout << "Введите действительную и мнимую часть соответственно: ";
//	cin >> n1.real >> n1.imag;
//
//	cout << endl << "\t\tПервое комплексное число\n";
//	cout << "Введите действительную и мнимую часть соответственно: ";
//	cin >> n2.real >> n2.imag;
//
//	signOfImag = (temporaryNumber.imag > 0) ? '+' : '-';
//
//	temporaryNumber.imag = (temporaryNumber.imag > 0) ?
//		temporaryNumber.imag : -temporaryNumber.imag;
//
//	temporaryNumber = add(n1, n2);
//	cout << "Сумма = " << temporaryNumber.real 
//		<< temporaryNumber.imag << "i\n";
//}

struct Time
{
	int seconds;
	int minutes;
	int hours;
};

void computeTimeDiffence(struct Time t1, struct Time t2, struct Time* difference)
{
	if (t2.seconds > t1.seconds)
	{
		--t1.minutes;
		t1.seconds += 60;
	}
	difference->seconds = t1.seconds - t2.seconds;

	if (t2.minutes > t1.minutes)
	{
		--t1.hours;
		t1.minutes += 60;
	}

	difference->minutes = t1.minutes - t2.minutes;
	difference->hours = t1.hours - t2.hours;
}

void countingTime()
{
	struct Time t1, t2, difference;

	cout << "\t\tНачальное время.\n";
	cout << "Введите часы, минуты и секунды: ";
	cin >> t1.hours >> t1.minutes >> t1.seconds;

	cout << "\t\t\n\nКонечное время.\n";
	cout << "Введите часы, минуты и секунды: ";
	cin >> t2.hours >> t2.minutes >> t2.seconds;

	computeTimeDiffence(t2, t1, &difference);

	cout << "\nРазница: " << t1.hours << ':'
		<< t1.minutes << ':' << t1.seconds;
	cout << " -> " << t2.hours << ':'
		<< t2.minutes << ':' << t2.seconds;

	cout << " = " << difference.hours << ':' << difference.minutes
		<< ':' << difference.seconds;
}

struct Students
{
	char name[50];
	int roll;
	float mark;
} s[5];

void informationOfStudent()
{
	cout << "Вводим информацию о студентах:\n";

	for (size_t i = 0; i < 5; i++)
	{
		cout << "Курс: ";
		while (!(cin >> s[i].roll))
		{
			cin.clear();
			cin.ignore();

			cout << "Введите курс студента: ";
		}

		cout << "Имя: ";
		while (!(cin >> s[i].name))
		{
			cin.clear();
			cin.ignore();

			cout << "Введите имя студента: ";
		}

		cout << "Оценка: ";
		while (!(cin >> s[i].mark))
		{
			cin.ignore();
			cin.clear();

			cout << "Введите оценку студента: ";
		}

		cout << '\n';
	}

	cout << "Информация о студентах:\n";

	for (size_t i = 0; i < 5; ++i)
	{
		cout << "Курс: " << s[i].roll << endl;
		cout << "Имя: " << s[i].name << endl;
		cout << "Оценка: " << s[i].mark << endl;
	}
}



struct Residents
{
	char name[65];
	char address[150];
	char gender[1];
	unsigned short age;
} resident[5];

void databaseResident()
{
	srand(time(0));

	int male(0), female(0);
	int ind = rand() % 20;

	//for (size_t i = 0; i < 5; i++)
	//{
	//	resident[i].name = Test_Name[ind];
	//}

	for (size_t i = 0; i < 5; i++)
	{
		cout << "Введите имя жителя: ";
		cin >> resident[i].name;

		cout << "Введите возраст жителя: ";
		cin >> resident[i].age;

		cout << "Гендер жителя 'м' или 'ж': ";
		cin >> resident[i].gender;

		cout << "Введите адрес жителей: ";
		cin >> resident[i].address;
	}

	for (size_t i = 0; i < 5; i++)
	{
		if (resident[i].gender == "м")
		{
			++male;
		}
		else if (resident[i].gender == "ж");
		{
			++female;
		}
	}

	if (male > female)
	{
		cout << "Мужчин больше женщин в этом доме";
	}
	else if (male < female)
	{
		cout << "Женщин больше чем мужчин в этом доме";
	}
	else
	{
		cout << "Мужчин и женщин одинаковое количество!";
	}
}

////////////////////////////////////////////////////////////////////////                     ////////////////

void clearMemory(Product*& product)
{
	if (product)
	{
		delete[] product;
		product = nullptr;
	}
}

void allocateMemory(Product*& product, unsigned size)
{
	clearMemory(product);

	product = new Product[size];
}

// вывод продукта
void printProduct(const Product& pro)
{
	cout << "Название продукта\t" << "Цена продукта\t"
		<< "Дата поставки\n";
	cout << pro.name << "\t\t\t" << pro.price << "\t\t\t"
		<< pro.tm_day << ' ' << pro.tm_mom << ' '
		<< pro.tm_year << '\n';
}

void printProduct(std::ostream& out, const Product& pro)
{
	out << pro.name << '\n' << pro.price << '\t'
		<< pro.tm_day << ' ' << pro.tm_mom << ' '
		<< pro.tm_year << "\n\n";
}

void printProducts(const Product* product, unsigned size)
{
	if (!product || !size)
	{
		return;
	}

	for (size_t i = 0; i < size; i++)
	{
		cout << "# " << i << '\n';
		printProduct(product[i]);
	}
	cout << '\n';
}

void printProducts(std::ostream& out, const Product* product, unsigned size)
{
	if (!product || !size)
	{
		return;
	}

	for (size_t i = 0; i < size; i++)
	{
		printProduct(out, product[i]);
		out << '\n';
	}
}

//Ввод

void inputProduct(Product& pro)
{
	cout << "Введите название продукта: ";
	getline(cin, pro.name);

	cout << "Введите цену продукта: ";
	cin >> pro.price;

	cout << "Введите дату поставки дд мм гггг: ";
	cin >> pro.tm_day >> pro.tm_mom >> pro.tm_year;

	cin.get();
}

void inputProducts(Product* products, unsigned size)
{
	if (!products || !size)
	{
		return;
	}

	for (size_t i = 0; i < size; i++)
	{
		cout << "Введите продукт под номером " << i + 1 << ": \n";
		inputProduct(products[i]);
	}
}

void fillRndProduct(Product& pro,
	int min = 0, int max = 2000)
{
	if (min > max) std::swap(min, max);


	static int i = 1;
	srand(time(0) * i++);

	int rnd;
	int ind;

	ind = rand() % SizeProductNames;
	pro.name = Test_Product_Names[ind];

	rnd = min + rand() % (max - min + 1);
	pro.price = rnd;

	rnd = rand() % DAY_IN_MONTH;
	pro.tm_day = rnd;

	rnd = rand() % MONTH_IN_YEAR;
	pro.tm_mom = rnd;

	rnd = 1980 + rand() % (2022 - 1980 + 1);
	pro.tm_year = rnd;
}

void fillRndProducts(Product* products, unsigned size)
{
	if (!products || !size)
	{
		return;
	}

	for (size_t i = 0; i < size; i++)
	{
		fillRndProduct(products[i]);
	}
}

int countProductInFile(std::ifstream& ifile)
{
	int count(0);

	if (!ifile.is_open())
		return -1;

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

void inputProduct(std::istream& in, Product& pro)
{
	if (in.bad()) return;

	in >> pro.name;
	in >> pro.price;
}

void inputProducts(std::ifstream& in, const std::string& fileName, Product*& products, unsigned& size)
{
	if (!in.is_open())
	{
		return;
	}

	int productCount = countProductInFile(in);
	if (productCount <= 0)
		return;

	size = productCount;
	allocateMemory(products, size);

	in.close();
	in.open(fileName);

	if (!in.is_open())
	{
		cout << "Не удалось переоткрыть файл " << fileName << '\n';
		return;
	}

	for (size_t i = 0; i < size; i++)
	{
		inputProduct(in, products[i]);
	}
}

// обработка данных

Product productMin(const Product* products, unsigned size)
{
	if (!products || !size)
	{
		return Product();
	}

	auto min = products[0];

	for (size_t i = 0; i < size; i++)
	{
		if (products[i].price < min.price)
		{
			min = products[i];
		}
	}

	return min;
}

void printSortPriceProductTest(const Product* product, unsigned size)
{
	Product pro = productMin(product, size);

	cout << "Минимальная цена:\n";
	printProduct(pro);
	cout << "Цена = " << pro.price << "\n";
}

float averagePrice(const Product* product, unsigned int size)
{
	if (!product || !size)
	{
		return -1;
	}

	float average = 0;

	for (size_t i = 0; i < size; i++)
	{
		average += product[i].price;
	}

	return (average / size);
}

void printProductsAboveAverage(const Product* products, unsigned size)
{
	if (!products || !size)
	{
		cout << "Проблема с продуктами. Невозможно написать среднюю цену\n";
		return;
	}

	float averagePri = averagePrice(products, size);
	cout << "Средняя цена товаров = " << averagePri << endl;
}

bool printSortedProductByDate(const Product* pro, unsigned int size,
	unsigned short day, unsigned short month, unsigned short year)
{
	if (!pro || !size)
	{
		return false;
	}

	day %= 31;
	month %= 12;

	bool ret = false;
	bool dataIsLater = false;



	for (size_t i = 0; i < size; i++)
	{
		if (pro[i].tm_year > year)
		{
			printProduct(pro[i]);
			ret = true;

		}
		else if ((pro[i].tm_year == year) &&
			(pro[i].tm_mom > month))
		{
			printProduct(pro[i]);
			ret = true;

		}
		else if ((pro[i].tm_year == year) &&
			(pro[i].tm_mom == month) &&
			(pro[i].tm_day > day))
		{
			printProduct(pro[i]);
			ret = true;
		}
	}

	return ret;
}

void printProductsSortDateTest(const Product* products, unsigned size)
{
	if (!products || !size)
	{
		cout << "Проблема с продуктами. Невозможно отсортировать по дате!";
		return;
	}

	int day(0), month(0), year(0);

	cout << "Введите дату в формате дд мм гггг: ";
	cin >> day >> month >> year;
	cout << "Товары поступившие позже указанной даты:\n";

	printSortedProductByDate(products, size, day, month, year);

}

// функции диалога с пользователем

void inputProductFromStdIn(Product*& products, unsigned& size)
{
	cout << "Сколько продуктов хотите создать? ";

	if (!(cin >> size))
	{
		cout << "Ошибка ввода\n";
		cin.clear();
		cin.ignore();
		return;
	}
	cin.get();

	allocateMemory(products, size);
	inputProducts(products, size);
}

void inputRndProducts(Product*& products, unsigned& size)
{
	cout << "Сколько продуктов хотите создать? ";

	if (!(cin >> size))
	{
		cout << "Ошибка ввода\n";
		cin.clear();
		cin.ignore();
		return;
	}
	cin.get();

	allocateMemory(products, size);
	fillRndProducts(products, size);
}

void inputProductsFromFile(Product*& product, unsigned size)
{
	cout << "Введите имя файла для чтения продуктов: ";

	std::string fileName;
	std::getline(cin, fileName);

	std::ifstream file(fileName, std::ios::in);

	if (!file.is_open())
	{
		cout << "Ошибка открытия файла на чтение\n";
		return;
	}

	inputProducts(product, size);

	file.close();
}

void printProductToFile(const Product* products, const unsigned size)
{
	if (!products || !size)
	{
		cout << "Ошибка данных при записи в файл\n";
		return;
	}

	cout << "Введите имя файла для печати продуктов: ";

	std::string fileName;
	std::getline(cin, fileName);

	std::ofstream file(fileName, std::ios_base::app);

	if (!file.is_open())
	{
		cout << "Ошибка открытия файла на запись\n";
		return;
	}

	printProducts(file, products, size);

	file.close();
}

bool cmpProductName(Product proA, Product proB)
{
	if (proA.name > proB.name)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int cmpProductPrice(const void* proA, const void* proB)
{
	Product* xpro = (Product*)proA;
	Product* ypro = (Product*)proB;

	if (xpro->price > ypro->price)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

//bool cmpProductDate()
//{
//	//
//}

void printShopHelp()
{
	cout << "-1 Ввод с клавиатуры\n";
	cout << "-2 Ввод из файла\n";
	cout << "-3 Генерация случайных товаров\n\n";

	cout << "-4 Вывод на экран\n";
	cout << "-5 Запись в файл\n\n";

	cout << "-6 Показать товар с самой маленькой ценой\n";
	cout << "-7 Cредняя цена всего товара\n";
	cout << "-8 Сортировать по дате\n";
	cout << "-9 Сортировка по имени\n";
	cout << "-10 Сортировка по цене\n\n";

	cout << "-h Справка\n";
	cout << "-q Выход\n\n";

}

// Главная функция для Products

void productsTest()
{
	cout << "\t\tОперации со структурой магазин\n\n";

	unsigned sizeProducts = 0;
	Product* product = nullptr;

	char buf[256] = { 0 };
	char choice[128] = { 0 };

	printShopHelp();

	while (strcmp(choice, "q"))
	{
		memset(buf, 0, sizeof(buf));
		memset(choice, 0, sizeof(choice));

		printf("Выберите пункт меню: \n");
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
				printShopHelp();
			}
			else
			{
				cout << "Неизвестный выбор\n";
			}
			break;
		}
		case 1:
		{
			inputProductFromStdIn(product, sizeProducts);
			break;
		}
		case 2:
		{
			inputProductsFromFile(product, sizeProducts);
			break;
		}
		case 3:
		{
			inputRndProducts(product, sizeProducts);
			break;
		}
		case 4:
		{
			printProducts(product, sizeProducts);
			break;
		}
		case 5:
		{
			printProductToFile(product, sizeProducts);
			break;
		}
		case 6:
		{
			printSortPriceProductTest(product, sizeProducts);
			break;
		}
		case 7:
		{
			printProductsAboveAverage(product, sizeProducts);
			break;
		}
		case 8:
		{
			printProductsSortDateTest(product, sizeProducts);
			break;
		}
		case 9:
		{
			selectionSort(product, sizeProducts, cmpProductName);
			break;
		}
		case 10:
		{
			qsort(product, sizeProducts, sizeof(Product), cmpProductPrice);
			break;
		}
		default:
			cout << "Неизвестный выбор\n";
			break;
		}
	}

	delete[] product;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////

// Задача на структуру вектора

void printVector(const MathVector& vector)
{
	cout << "\n";
	cout << "x = " << vector.x << ' ';
	cout << "y = " << vector.y << ' ';
	cout << "z = " << vector.z << ' ';
	cout << "length = ";
	cout << length(vector);
	cout << '\n';
}

void setVector(MathVector& vector,
	double x, double y, double z)
{
	vector.x = x;
	vector.y = y;
	vector.z = z;
}

void fillRndVector(MathVector& vector)
{
	vector.x = rand() % 1000;
	vector.y = rand() % 1000;
	vector.z = rand() % 1000;
}

MathVector add(
	const MathVector& vecOne,
	const MathVector& vecTwo)
{
	MathVector newVec;

	auto x = vecOne.x + vecTwo.x;
	auto y = vecOne.y + vecTwo.y;
	auto z = vecOne.z + vecTwo.z;

	setVector(newVec, x, y, z);

	return newVec;
}

MathVector substruct(
	const MathVector& vecOne,
	const MathVector& vecTwo)
{
	MathVector newVec;

	auto x = vecOne.x - vecTwo.x;
	auto y = vecOne.y - vecTwo.y;
	auto z = vecOne.z - vecTwo.z;

	setVector(newVec, x, y, z);

	return newVec;
}

MathVector multiply(const MathVector& vec,
	double k)
{
	MathVector newVec;

	auto x = vec.x * k;
	auto y = vec.y * k;
	auto z = vec.z * k;

	setVector(newVec, x, y, z);

	return newVec;
}

double length(const MathVector& vec)
{
	auto x = vec.x;
	auto y = vec.y;
	auto z = vec.z;

	return sqrt(x * x + y * y + z * z);
}

void normalizeVector(MathVector& vec)
{
	auto len = length(vec);

	if (!len) return;

	vec.x /= len;
	vec.y /= len;
	vec.z /= len;
}

#define DBG 1

int scalarPiece(
	const MathVector& vecOne,
	const MathVector& vecTwo)
{
	int buf;

	auto x = vecOne.x * vecTwo.x;
	auto y = vecOne.y * vecTwo.y;
	auto z = vecOne.z * vecTwo.z;

	buf = x + y + z;
#if DBG
	cout << "Скалярное произведение v1 и v2 = " << buf
		<< "\n\n";
#endif
	return buf;
}

double angleVectors(
	MathVector& vecOne,
	MathVector& vecTwo)
{
	double angle(-1);
	auto scalar = scalarPiece(vecOne, vecTwo);

	auto modA = length(vecOne);
	auto modB = length(vecTwo);

	if (modA && modB)
	{
		auto x = (scalar / (modA * modB));
		auto angle = acos(x) * M_PI / 180;
	}

	return angle;
}

void fillMultiply(MathVector& vecOne,
	MathVector& vecTwo,
	MathVector& vecThree)
{
	int buf;
	char ch[64] = { 0 };

	cout << "Введите число на которое хотите умножить вектор: ";
	cin >> buf;

	cout << "Введите вектор который хотите умножить на "
		<< buf << " : ";
	cin >> ch;

	switch (atoi(ch))
	{
	case 1:
	{
		vecOne = multiply(vecOne, buf);

		cout << "v1 * x = ";
		printVector(vecOne);
		break;
	}
	case 2:
	{
		vecTwo = multiply(vecTwo, buf);

		cout << "v2 * x = ";
		printVector(vecTwo);
		break;
	}
	case 3:
	{
		vecThree = multiply(vecThree, buf);

		cout << "v3 * x = ";
		printVector(vecThree);
		break;
	}
	default:
	{
		cout << "Неизвестный выбор\n";
		break;
	}
	}
}

void VectorHelpMenu()
{
	cout << "1 - Заполнить векторы\n";
	cout << "2 - Напечатать векторы\n\n";
	cout << "3 - Сложить векторы\n";
	cout << "4 - Вычисть векторы\n";
	cout << "5 - Умножить вектора на скаляр\n";
	cout << "6 - Нормализация векторов\n";
	cout << "7 - Вычесление скалярного произведения\n";
	cout << "8 - Вычисление угла между векторами\n";
}

void mathVectorTest()
{
	cout << "\t\tОперации с векторами\n\n";

	char choice[128] = { 0 };
	MathVector vOne, vTwo, vThree;

	VectorHelpMenu();

	while (strcmp(choice, "q"))
	{
		memset(choice, 0, sizeof(choice));

		cout << "Введите пункт меню: \n";
		gets_s(choice, sizeof(choice));

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
				VectorHelpMenu();
			}
			else
			{
				cout << "Неизвестный выбор\n";
			}
			break;
		}
		case 1:
		{
			fillRndVector(vOne);
			fillRndVector(vTwo);
			fillRndVector(vThree);
			break;
		}
		case 2:
		{
			printVector(vOne);
			printVector(vTwo);
			printVector(vThree);
			break;
		}
		case 3:
		{
			cout << "v1 + v2 = ";
			vThree = add(vOne, vTwo);
			printVector(vThree);
			break;
		}
		case 4:
		{
			cout << "v1 - v2 = ";
			vThree = substruct(vOne, vTwo);
			printVector(vThree);
			break;
		}
		case 5:
		{
			fillMultiply(vOne, vTwo, vThree);
			break;
		}
		case 6:
		{
			normalizeVector(vOne);
			normalizeVector(vTwo);
			normalizeVector(vThree);
			break;
		}
		case 7:
		{
			scalarPiece(vOne, vTwo);
			break;
		}
		case 8:
		{
			angleVectors(vOne, vTwo);
			break;
		}
		default:
		{
			cout << "Неизвестный выбор\n";
			break;
		}
		}
	}
}