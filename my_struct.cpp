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
	"�������� ��������� ���������",
	"������� ����� �������",
	"�������� ����� ����������",
	"������� ���� ��������",
	"����� ������ �����������",
	"������� ���� ���������",
	"������� ������ ���������",
	"�������� ����� ��������",
	"����������� ����� �����������",
	"������ ������ ��������"
	"������� ���� ���������"
	"������� ������� ����������"
	"�������� ����� �������"
	"������ ������ ����������"
	"������ ������ ��������"
	"�������� ����� ��������"
	"���������� ������ ����������"
	"������� ������ ���������"
	"������� ������ ��������"
	"������� ���� ����������"
};

const char* Test_Subject_Names[20]
{
	"�����",
	"��������",
	"������",
	"��������",
	"���������",
	"��������������",
	"����������",
	"����������",
	"������� ����",
	"����������",
	"��������",
	"���������",
	"���. ������",
	"�������� �������",
	"������������� ���������",
	"�������� � �������������",
	"���������",
	"��������� ������",
	"���������������� c++",
	"��������� � �������� ������"
};

const int SizeProductNames(20);
const char* Test_Product_Names[20]
{
	"����",
	"���������",
	"��������",
	"����",
	"������",
	"��������",
	"�������",
	"������",
	"���",
	"�����",
	"������",
	"����",
	"����",
	"������",
	"�����",
	"������",
	"�������",
	"�������",
	"������",
	"�������"
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
//	cout << "������ �� �������� " << Test_Subject_Names[ind] << ": " << student.rndGrade1;
//	cout << "������ �� �������� " << Test_Subject_Names[ind] << ": " << student.rndGrade2;
//	cout << "������ �� �������� " << Test_Subject_Names[ind] << ": " << student.rndGrade3;
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

	cout << "\t\t���������� � ��������\n";
	cout << "\n���: ";
	cin >> student.name;
	cout << "����: ";
	cin >> student.roll;
	cout << "������: ";
	cin >> student.group;
	cout << "������: ";
	cin >> student.mark;

	cout << "\n\n����������� ����������!";
	cout << "\n���: " << student.name;
	cout << "\n����: " << student.roll;
	cout << "\n������: " << student.group;
	cout << "\n������: " << student.mark;
}

struct Dustance
{
	int f;
	float meters;
} d1, d2, sum;

void sumMeters()
{
	cout << "\t\t������ ���������";
	cout << "\n���������� �����: ";
	cin >> d1.f;
	cout << "���������� ������: ";
	cin >> d1.meters;

	cout << "\n\t\t������ ���������";
	cout << "\n���������� �����: ";
	cin >> d2.f;
	cout << "���������� ������: ";
	cin >> d2.meters;

	sum.f = d1.f + d2.f;
	sum.meters = d1.meters + d2.meters;

	cout << "\n\t\t����� ����� � ������";
	cout << "\n����� �����: " << sum.f;
	cout << "\n����� ������: " << sum.meters << "\n\n";
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
//	cout << "\t\t������ ����������� �����\n";
//	cout << "������� �������������� � ������ ����� ��������������: ";
//	cin >> n1.real >> n1.imag;
//
//	cout << endl << "\t\t������ ����������� �����\n";
//	cout << "������� �������������� � ������ ����� ��������������: ";
//	cin >> n2.real >> n2.imag;
//
//	signOfImag = (temporaryNumber.imag > 0) ? '+' : '-';
//
//	temporaryNumber.imag = (temporaryNumber.imag > 0) ?
//		temporaryNumber.imag : -temporaryNumber.imag;
//
//	temporaryNumber = add(n1, n2);
//	cout << "����� = " << temporaryNumber.real 
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

	cout << "\t\t��������� �����.\n";
	cout << "������� ����, ������ � �������: ";
	cin >> t1.hours >> t1.minutes >> t1.seconds;

	cout << "\t\t\n\n�������� �����.\n";
	cout << "������� ����, ������ � �������: ";
	cin >> t2.hours >> t2.minutes >> t2.seconds;

	computeTimeDiffence(t2, t1, &difference);

	cout << "\n�������: " << t1.hours << ':'
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
	cout << "������ ���������� � ���������:\n";

	for (size_t i = 0; i < 5; i++)
	{
		cout << "����: ";
		while (!(cin >> s[i].roll))
		{
			cin.clear();
			cin.ignore();

			cout << "������� ���� ��������: ";
		}

		cout << "���: ";
		while (!(cin >> s[i].name))
		{
			cin.clear();
			cin.ignore();

			cout << "������� ��� ��������: ";
		}

		cout << "������: ";
		while (!(cin >> s[i].mark))
		{
			cin.ignore();
			cin.clear();

			cout << "������� ������ ��������: ";
		}

		cout << '\n';
	}

	cout << "���������� � ���������:\n";

	for (size_t i = 0; i < 5; ++i)
	{
		cout << "����: " << s[i].roll << endl;
		cout << "���: " << s[i].name << endl;
		cout << "������: " << s[i].mark << endl;
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
		cout << "������� ��� ������: ";
		cin >> resident[i].name;

		cout << "������� ������� ������: ";
		cin >> resident[i].age;

		cout << "������ ������ '�' ��� '�': ";
		cin >> resident[i].gender;

		cout << "������� ����� �������: ";
		cin >> resident[i].address;
	}

	for (size_t i = 0; i < 5; i++)
	{
		if (resident[i].gender == "�")
		{
			++male;
		}
		else if (resident[i].gender == "�");
		{
			++female;
		}
	}

	if (male > female)
	{
		cout << "������ ������ ������ � ���� ����";
	}
	else if (male < female)
	{
		cout << "������ ������ ��� ������ � ���� ����";
	}
	else
	{
		cout << "������ � ������ ���������� ����������!";
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

// ����� ��������
void printProduct(const Product& pro)
{
	cout << "�������� ��������\t" << "���� ��������\t"
		<< "���� ��������\n";
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

//����

void inputProduct(Product& pro)
{
	cout << "������� �������� ��������: ";
	getline(cin, pro.name);

	cout << "������� ���� ��������: ";
	cin >> pro.price;

	cout << "������� ���� �������� �� �� ����: ";
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
		cout << "������� ������� ��� ������� " << i + 1 << ": \n";
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
		cout << "�� ������� ����������� ���� " << fileName << '\n';
		return;
	}

	for (size_t i = 0; i < size; i++)
	{
		inputProduct(in, products[i]);
	}
}

// ��������� ������

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

	cout << "����������� ����:\n";
	printProduct(pro);
	cout << "���� = " << pro.price << "\n";
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
		cout << "�������� � ����������. ���������� �������� ������� ����\n";
		return;
	}

	float averagePri = averagePrice(products, size);
	cout << "������� ���� ������� = " << averagePri << endl;
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
		cout << "�������� � ����������. ���������� ������������� �� ����!";
		return;
	}

	int day(0), month(0), year(0);

	cout << "������� ���� � ������� �� �� ����: ";
	cin >> day >> month >> year;
	cout << "������ ����������� ����� ��������� ����:\n";

	printSortedProductByDate(products, size, day, month, year);

}

// ������� ������� � �������������

void inputProductFromStdIn(Product*& products, unsigned& size)
{
	cout << "������� ��������� ������ �������? ";

	if (!(cin >> size))
	{
		cout << "������ �����\n";
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
	cout << "������� ��������� ������ �������? ";

	if (!(cin >> size))
	{
		cout << "������ �����\n";
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
	cout << "������� ��� ����� ��� ������ ���������: ";

	std::string fileName;
	std::getline(cin, fileName);

	std::ifstream file(fileName, std::ios::in);

	if (!file.is_open())
	{
		cout << "������ �������� ����� �� ������\n";
		return;
	}

	inputProducts(product, size);

	file.close();
}

void printProductToFile(const Product* products, const unsigned size)
{
	if (!products || !size)
	{
		cout << "������ ������ ��� ������ � ����\n";
		return;
	}

	cout << "������� ��� ����� ��� ������ ���������: ";

	std::string fileName;
	std::getline(cin, fileName);

	std::ofstream file(fileName, std::ios_base::app);

	if (!file.is_open())
	{
		cout << "������ �������� ����� �� ������\n";
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
	cout << "-1 ���� � ����������\n";
	cout << "-2 ���� �� �����\n";
	cout << "-3 ��������� ��������� �������\n\n";

	cout << "-4 ����� �� �����\n";
	cout << "-5 ������ � ����\n\n";

	cout << "-6 �������� ����� � ����� ��������� �����\n";
	cout << "-7 C������ ���� ����� ������\n";
	cout << "-8 ����������� �� ����\n";
	cout << "-9 ���������� �� �����\n";
	cout << "-10 ���������� �� ����\n\n";

	cout << "-h �������\n";
	cout << "-q �����\n\n";

}

// ������� ������� ��� Products

void productsTest()
{
	cout << "\t\t�������� �� ���������� �������\n\n";

	unsigned sizeProducts = 0;
	Product* product = nullptr;

	char buf[256] = { 0 };
	char choice[128] = { 0 };

	printShopHelp();

	while (strcmp(choice, "q"))
	{
		memset(buf, 0, sizeof(buf));
		memset(choice, 0, sizeof(choice));

		printf("�������� ����� ����: \n");
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
				cout << "����������� �����\n";
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
			cout << "����������� �����\n";
			break;
		}
	}

	delete[] product;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////

// ������ �� ��������� �������

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
	cout << "��������� ������������ v1 � v2 = " << buf
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

	cout << "������� ����� �� ������� ������ �������� ������: ";
	cin >> buf;

	cout << "������� ������ ������� ������ �������� �� "
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
		cout << "����������� �����\n";
		break;
	}
	}
}

void VectorHelpMenu()
{
	cout << "1 - ��������� �������\n";
	cout << "2 - ���������� �������\n\n";
	cout << "3 - ������� �������\n";
	cout << "4 - ������� �������\n";
	cout << "5 - �������� ������� �� ������\n";
	cout << "6 - ������������ ��������\n";
	cout << "7 - ���������� ���������� ������������\n";
	cout << "8 - ���������� ���� ����� ���������\n";
}

void mathVectorTest()
{
	cout << "\t\t�������� � ���������\n\n";

	char choice[128] = { 0 };
	MathVector vOne, vTwo, vThree;

	VectorHelpMenu();

	while (strcmp(choice, "q"))
	{
		memset(choice, 0, sizeof(choice));

		cout << "������� ����� ����: \n";
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
				cout << "����������� �����\n";
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
			cout << "����������� �����\n";
			break;
		}
		}
	}
}