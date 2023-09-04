#define _CRT_SECURE_NO_WARNINGS

#include "bankDeposit.h"

const int SizeDepositorsNames(20);
const char* Test_Depositors_Names[20]
{
	"�������� ����� ����������",
	"��������� ������� �������������",
	"��������� ������� ��������",
	"������ �������� ����������",
	"������ ������� ����������",
	"������� ��������� �������������",
	"�������� ������� �������",
	"������� ������� ��������",
	"�������� ���� ��������",
	"��������� �������� ��������",
	"�������� ������� ����������",
	"�������� ����� ���������",
	"������� �����  ���������",
	"��������� ����� ��������",
	"�������� ������ ��������",
	"��������� ����� ����������",
	"�������� ������� �������������",
	"������� ��������� ���������",
	"������� �����  ���������",
	"������ ������  ���������"
};

const int SizeDeposNames(20);
const char* Test_Depos_Names[20]
{
	"������ ������		",
	"������ ����		",
	"����� ��������		",
	"�������			",
	"����������� �������	",
	"���������������		",
	"����� �� ����� ���	",
	"������������ ����	",
	"����� �� ����		",
	"���������� �����	",
	"�������			",
	"������ �������		",
	"���������� �������	",
	"�������������		",
	"��������		",
	"�������������		",
	"�������			",
	"���������		",
	"������������ �����	",
	"�� ������		"
};

const int SizeCurrency(5);
const char* Test_currency[5]
{
	"RUB",
	"USD",
	"EUR",
	"GBP",
	"CHF"
};

void cleaMemory(Deposit*& deposit)
{
	if (deposit)
	{
		delete[] deposit;
		deposit = nullptr;
	}
}

void allocateMemory(Deposit*& deposit, unsigned size)
{
	cleaMemory(deposit);

	deposit = new Deposit[size];
}

// ����
void printDeposit(const Deposit& deposit)
{
	cout << "��� ���������\t\t\t" << "\t�������� ������\t"
		<< "\t\t\t����� �����" << "\t\t������" << "\t\t���������� ������ �������\n";
	cout << deposit.nameDepositors << "\t\t" << deposit.nameDeposit
		<< "\t\t" << deposit.depositAmount << "\t\t\t"
		<< deposit.currency << "\t\t" << deposit.interestRate << '%';
}

void printDepositCalcul(const Deposit& deposit, unsigned bufSum, unsigned year)
{
	cout << "\n���������� ����������: " << bufSum - deposit.depositAmount << '\n';

	cout << "\n����� " << year << " ��� ������� ����� ��������� ���: \n";

	cout << "��� ���������\t\t\t" << "\t�������� ������\t"
		<< "\t\t\t����� �����" << "\t\t������" << "\t\t���������� ������ �������\n";
	cout << deposit.nameDepositors << "\t\t" << deposit.nameDeposit
		<< "\t\t" << bufSum << "\t\t\t"
		<< deposit.currency << "\t\t" << deposit.interestRate << '%';
}

void printDeposit(std::ostream& out, const Deposit& deposit)
{
	out << deposit.nameDepositors << '\n' << deposit.nameDeposit << '\n'
		<< deposit.depositAmount << '\n' << deposit.currency << '\t'
		<< deposit.interestRate << "\n\n";
}

void printDeposits(const Deposit* dep, unsigned size)
{
	if (!dep || !size)
	{
		return;
	}

	for (size_t i = 0; i < size; i++)
	{
		cout << "\n# " << i << '\n';
		printDeposit(dep[i]);
	}
	cout << '\n';
}

void printDeposits(std::ostream& out, const Deposit* dep, unsigned size)
{
	if (!dep || !size)
	{
		return;
	}

	for (size_t i = 0; i < size; i++)
	{
		printDeposit(out, dep[i]);
		out << '\n';
	}
}

// ����� ������
void inputDeposit(Deposit& dep)
{
	cout << "������� ��� ��������� (���): ";
	getline(cin, dep.nameDepositors);

	cout << "������� �������� ������: ";
	getline(cin, dep.nameDeposit);

	cout << "������� ����� ������: ";
	cin >> dep.depositAmount;

	cout << "������� ������ (RUB, USD): ";
	getline(cin, dep.currency);

	cout << "������� % �������: ";
	cin >> dep.interestRate;
}

void inputDeposits(Deposit* dep, unsigned size)
{
	if (!dep || !size)
	{
		return;
	}

	for (size_t i = 0; i < size; i++)
	{
		cout << "������� ��������� ��� ������� " << i << ": \n";
		inputDeposit(dep[i]);
	}
}

double ffrand(const double min, const double max)
{
	return min + 1.0 * rand() / RAND_MAX * (max - min);
}

void fillRndDeposit(Deposit& dep, int min = 10000, int max = 200000)
{
	if (min > max) std::swap(min, max);

	static int i = 1;
	srand(time(0) * i++);

	float rnd(0);
	int ind;

	ind = rand() % SizeDepositorsNames;
	dep.nameDepositors = Test_Depositors_Names[ind];

	ind = rand() % SizeDeposNames;
	dep.nameDeposit = Test_Depos_Names[ind];
	
	rnd = min + rand() % (max - min + 1);
	dep.depositAmount = rnd;

	ind = rand() % SizeCurrency;
	dep.currency = Test_currency[ind];

	rnd = ffrand(2, 10);
	dep.interestRate = rnd;
}

void fillRndDeposits(Deposit* dep, unsigned size)
{
	if (!dep || !size)
	{
		return;
	}

	for (size_t i = 0; i < size; i++)
	{
		fillRndDeposit(dep[i]);
	}
}

int counstDepositInFile(std::ifstream& ifile)
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

	count /= 4;

	return count;
}

void inputDeposit(std::istream& in, Deposit& dep)
{
	if (in.bad())
		return;

	do
	{
		getline(in, dep.nameDepositors);
	} while (!in.eof() && dep.nameDepositors.empty());

	do
	{
		getline(in, dep.nameDeposit);
	} while (!in.eof() && dep.nameDeposit.empty());

	in >> dep.depositAmount;
	do
	{
		getline(in, dep.currency);
	} while (!in.eof() && dep.currency.empty());
	in >> dep.interestRate;
}

void inputDeposits(std::ifstream& in, const string& fileName,
	Deposit*& dep, unsigned& size)
{
	if (!in.is_open())
	{
		return;
	}

	int depositCount = counstDepositInFile(in);
	if (depositCount <= 0)
		return;

	size = depositCount;
	allocateMemory(dep, size);

	in.close();
	in.open(fileName);

	if (!in.is_open())
	{
		cout << "�� ������� ������� ���� " << fileName << '\n';
		return;
	}

	for (size_t i = 0; i < size; i++)
	{
		inputDeposit(in, dep[i]);
	}
}

bool cmpNameDeposits(Deposit depA, Deposit depB)
{
	if (depA.nameDepositors > depB.nameDepositors)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool cmpCurrency(Deposit depA, Deposit depB)
{
	if (depA.currency < depB.currency)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int cmpDepositPercentage(const void* depA, const void* depB)
{
	Deposit* xdep = (Deposit*)depA;
	Deposit* ydep = (Deposit*)depB;

	if (xdep->interestRate < ydep->interestRate)
	{
		return 1;
	}
	else
	{
		return -1;
	}
	return 1;
}

void depositCalculator(Deposit*& dep, unsigned numDeposit)
{
	if (!dep)
		return;

	unsigned int year;
	cin >> year;

	unsigned buf = dep[numDeposit].depositAmount;

	for (size_t i = 0; i < year; i++)
	{
		buf = ((buf / 100) * (100 + dep[numDeposit].interestRate));
	}

	printDepositCalcul(dep[numDeposit], buf, year);
}

// ������� ������� � �������������
void inputDepositFromStdIn(Deposit*& dep, unsigned& size)
{
	cout << "������� ���������� ������ �������? ";

	if (!(cin >> size))
	{
		cout << "������ �����\n";
		cin.clear();
		cin.ignore();
		return;
	}
	cin.get();

	allocateMemory(dep, size);
	inputDeposits(dep, size);
}

void inputRndDeposits(Deposit*& dep, unsigned& size)
{
	cout << "������� ���������� ������ �������? ";

	if (!(cin >> size))
	{
		cout << "������ �����\n";
		cin.clear();
		cin.ignore();
		return;
	}
	cin.get();

	allocateMemory(dep, size);
	fillRndDeposits(dep, size);
}

void inputDepositFromFile(Deposit*& dep, unsigned& size)
{
	cout << "������� ��� ����� ��� ������ ����������: ";

	string fileName;
	getline(cin, fileName);

	std::ifstream file(fileName, std::ios::in);

	if (!file.is_open())
	{
		cout << "������ �������� ����� �� ������\n";
		return;
	}

	inputDeposits(file, fileName, dep, size);

	file.close();
}

void printDepositToFile(const Deposit* dep, const unsigned size)
{
	if (!dep || !size)
	{
		cout << "������ ������ ��� ������ � ����\n";
		return;
	}

	cout << "������� ��� ����� ��� ������ ����������: ";

	string fileName;
	getline(cin, fileName);

	std::ofstream file(fileName, std::ios_base::app);

	printDeposits(file, dep, size);

	file.close();
}


void printDepositHelp()
{
	cout << "-1 ���� � ����������\n";
	cout << "-2 ���� �� �����\n";
	cout << "-3 ��������� ��������� ����������\n\n";

	cout << "-4 ����� �� �����\n";
	cout << "-5 ������ � ����\n\n";

	cout << "-6 ���������� �� ����� ����������\n";
	cout << "-7 ���������� �� ������\n";
	cout << "-8 ���������� �� �������� ������\n\n";

	cout << "-9 ����������� ������ ����� n ���\n\n";

	cout << "-h �������\n";
	cout << "-q �����\n\n";
}

void depositTest()
{
	cout << "\t\t�������� �� ���������� ���������\n\n";

	unsigned sizeDeposit = 0;
	Deposit* deposit = nullptr;

	char buf[256] = { 0 };
	char choice[128] = { 0 };

	printDepositHelp();

	while (strcmp(choice, "q"))
	{
		memset(buf, 0, sizeof(buf));
		memset(choice, 0, sizeof(choice));

		cout << "\n�������� ����� ����: \n";
		fgets(buf, sizeof(buf), stdin);
		sscanf(buf, "-%s", choice, sizeof(choice));

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
				printDepositHelp();
			}
			else
			{
				cout << "����������� �����\n";
			}
			break;
		}
		case 1:
		{
			inputDepositFromStdIn(deposit, sizeDeposit);
			break;
		}
		case 2:
		{
			inputDepositFromFile(deposit, sizeDeposit);
			break;
		}
		case 3:
		{
			inputRndDeposits(deposit, sizeDeposit);
			break;
		}
		case 4:
		{
			printDeposits(deposit, sizeDeposit);
			break;
		}
		case 5:
		{
			printDepositToFile(deposit, sizeDeposit);
			break;
		}
		case 6:
		{
			bubleSort(deposit, sizeDeposit, cmpNameDeposits);
			break;
		}
		case 7:
		{
			bubleSort(deposit, sizeDeposit, cmpCurrency);
			break;
		}
		case 8:
		{
			qsort(deposit, sizeDeposit, sizeof(Deposit), cmpDepositPercentage);
			break;
		}
		case 9:
		{
			unsigned numDeposit;
			cout << "������� ����� ��������� ��� �������� ������: ";
			cin >> numDeposit;

			cout << "������� ���-�� ��� ��� ������������: ";
			depositCalculator(deposit, numDeposit);
			break;
		}
		default:
		{
			cout << "����������� �����\n";
			break;
		}
		}
	}
		delete[] deposit;
}