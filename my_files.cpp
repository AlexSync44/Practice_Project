#include "my_files.h"
#include <iostream>
#include <algorithm>
#include <cmath>
#include <ctime>
#include "matrix.h"
#include "my_arrays.h"
#include "my_sorts.h"

const int aAsciiInd_A = 65;
const int aAsciiInd_Z = 90;
const int aAsciiInd_a = 97;
const int aAsciiInd_z = 122;

bool checkopenfile(const fstream& file)
{
	if (!file.is_open())
	{
		cout << "���� �� ������, ������!" << endl;
		return false;
	}
	else
	{
		cout << "���� ������" << endl;
	}

	return true;
}

int writeToFile(fstream& ofile)
{
	if (!checkopenfile(ofile)) return -1;

	string buf;
	cout << "������� ������ ��� ����������: " << endl;
	getline(cin, buf);

	ofile << buf << "\n";

	return 0;
}

char rndLetterGenerate_()
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

string rndStringGenerate(unsigned size)
{
	string rndStr;

	for (size_t i = 0; i < size; i++)
	{
		rndStr += rndLetterGenerate_();
	}

	return (string)rndStr;
}

void printMatrix(fstream& ofile)
{
	int cols(0), rows(0);
	int** matrix = nullptr;

	cout << "������� ������ ������� < 30: ";
	while (!(cin >> rows >> cols))
	{
		cin.clear();
		cin.ignore();
		cout << "������� ������  ������� > 1, �� < 30: ";
	}

	fillMatrix(matrix, rows, cols);

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			ofile << matrix[i][j];
		}
	}
}

void fWork()
{
	short choice = -1;
	char name[40];

	cout << "������� ��� �����: " << endl;
	cin.getline(name, sizeof(name));
	fstream fout(name, ios::in | ios::out | ios::app);

	if (!checkopenfile(fout)) return;



	while (choice != 0)
	{
	cout << "�������� �������:\n"
		<< "1. ���� � ����������.\n"
		<< "2. ��������� ��������� ������.\n"
		<< "3. ������� � ������� ����������.\n"
		<< "4. ������� �������.\n"
		<< "0. �����.\n";

		while (!(cin >> choice))
		{
			cin.clear();
			cin.ignore();
			cout << "\n\n �������� �������� �� ������ ����!";
		}

		//catch \n
		cin.get();

		switch (choice)
		{
		case 1:
			writeToFile(fout);
			break;
		case 2:
		{
			int size;
			cout << "������� ������ ��������� ������: ";
			cin >> size;

			auto rndStr = rndStringGenerate(size);

			cout << rndStr << '\n';
			fout << rndStr;
			break;
		}
		case 3: printFile(fout);
			break;
		case 4: printMatrix(fout);
			break;
		case 0:
			break;
		default:
			cout << "����� �� ������!";
			break;
		}
	}

	fout.close();
}
//////////////////////////////////////////////////////////////
int countingWords(const char* fileName)
{
	if (!fileName)
		return -1;

	std::ifstream ofile(fileName);

	string buff;
	int sumWords(0);

	while (ofile >> buff)
	{
		sumWords++;
	}

	ofile.close();
	return sumWords;
}

int countingWords(fstream& ofile, const string word)
{
	if (!(ofile.is_open()))
		return -1;

	string buff;
	int sumWords(0);

	while (ofile >> buff)
	{
		if(buff == word)
		sumWords++;
	}
	return sumWords;
}

// ������ 1
void callCountingWords()
{
	string name;
	string word;

	cout << "������� ��� �����: ";
	getline(cin, name);
	fstream fout(name, ios::in);

	if (!checkopenfile(fout))
	{
		return;
	}
	cout << "������� ����� ��� ������: ";
	cin >> word;

	int count = countingWords(fout, word);

	cout << "\n����� ����������� " << count << " ���\n";

	fout.close();
}



// ������ 2
void callPrintFile()
{
	char name[256];

	cout << "������� ��� �����: ";
	cin.getline(name, sizeof(name));
	fstream fout(name, ios::in);

	if (!(checkopenfile(fout)))
		return;

	printFile(fout);

	fout.close();
}

void printFile(fstream& ofile)
{
	string buf;

	while (!ofile.eof())
	{
		std::getline(ofile, buf);

		cout << buf << '\n';
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ������ 3

// ���� ��������� �� �����
int countStatementInFile(std::ifstream& ifile)
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

void inputStatement(std::istream& in, Statement& state)
{
	if (in.bad())
		return;

	do
	{
		std::getline(in, state.name);
	} while (!in.eof() && state.name.empty());

	in >> state.money;
	in >> state.tm_day;
	in >> state.tm_mom;
	in >> state.tm_year;
}

void inputStatements(std::ifstream& in, const std::string& fileName,
					Statement*& state, unsigned& size)
{
	if (!in.is_open())
	{
		return;
	}

	int statementCount = countStatementInFile(in);
	if (statementCount <= 0)
		return;

	size = statementCount;
	allocateMemory(state, size);

	in.close();
	in.open(fileName);

	if (!in.is_open())
	{
		cout << "�� ������� ������� ���� " << fileName << '\n';
		return;
	}

	for (size_t i = 0; i < size; i++)
	{
		inputStatement(in, state[i]);
	}
}

void inputStatementFromFile(Statement*& state, unsigned& size)
{
	cout << "������� ��� ����� ��� ������ ���������: ";

	string fileName;
	std::getline(cin, fileName);

	ifstream file(fileName, std::ios::in);

	if (!file.is_open())
	{
		cout << "������ �������� ����� �� ������\n";
		return;
	}

	inputStatements(file, fileName, state, size);

	file.close();
}

// ��������� � �������
void printStatement(const Statement& state)
{
	cout << state.name << "\t" << state.money << "\t"
		<< state.tm_day << '.' << state.tm_mom << '.'
		<< state.tm_year << '\n';
}

void printStatements(const Statement* statement, unsigned size)
{
	if (!statement || !size)
	{
		return;
	}

	for (size_t i = 0; i < size; i++)
	{
		cout << i << '\n';
		printStatement(statement[i]);
	}
	cout << '\n';
}

// ���������� �� ����
int cmpStatementMoney(const void* steA, const void* steB)
{
	Statement* xste = (Statement*)steA;
	Statement* yste = (Statement*)steB;

	if (xste->money < yste->money)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

int totalMoney(const Statement* statement, unsigned size)
{
	if (!statement) return -1;

	int buf(0);

	for (size_t i = 0; i < size; i++)
	{
		buf += statement[i].money;
	}
	return buf;
}

void statementTest()
{
	unsigned sizeStatement = 0;
	Statement* state = nullptr;

	inputStatementFromFile(state, sizeStatement);
	
	cout << "�� ����������: \n\n";
	printStatements(state, sizeStatement);

	cout << "������ ����� �������(�): \n\n";
	qsort(state, sizeStatement, sizeof(Statement), cmpStatementMoney);
	printStatement(state[0]);

	cout << "\n\n����� ���-�� �����: " << totalMoney(state, sizeStatement);
	printStatements(state, sizeStatement);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
// �������� PNG �����
string getFormat(std::ifstream& file)
{
	string format;

	if (!file.is_open())
	{
		return "";
	}

	int byteRead(0);
	char c;

	while (!file.eof() && byteRead <= 3)
	{
		byteRead++;

		file.read(&c, 1);

		if (byteRead > 1)
		{
			format += c;
		}
	}

	return format;
}

bool checkingPNG(std::ifstream& ifile)
{
	if (getFormat(ifile) == "PNG" ||
		getFormat(ifile) == "png")
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void filePNGTest()
{
	string fileName;

	cout << "������� ��� �����: ";
	getline(cin, fileName);

	ifstream file(fileName, std::ios::binary);

	if (!file.is_open())
	{
		cout << "�� ������� ������� ���� " << fileName << '\n';
		return;
	}

	if (checkingPNG(file))
	{
		cout << "���� PNG �������!\n";
	}
	else
	{
		cout << "���� �� PNG";
	}

	file.close();
}


const char* INPUT_FILENAME = "123121.png";
void PNGSizeTest()
{
	std::ifstream file;
	size_t size = 0;

	std::cout << "��������� ���� " << INPUT_FILENAME << std::endl;

	file.open(INPUT_FILENAME, std::ios::in | std::ios::binary);
	char* data = 0;

	file.seekg(0, std::ios::end);
	size = file.tellg();
	std::cout << "������ �����: " << size << std::endl;
	file.seekg(0, std::ios::beg);

	data = new char[size - 8 + 1];
	file.seekg(8);
	file.read(data, size - 8);
	data[size] = '\0';

	std::cout << "������ ������: " << file.tellg() << std::endl;
	cin.get();
}

//void fileMerge()
//{
//	//int arrA[10]{ 1, 4, 7 };
//	//int arrB[10]{ 1, 2, 3 };
//
//	//int* arrRes = nullptr;
//	//int size(0);
//
//	//printArr(arrA, 3);
//	//printArr(arrB, 3);
//
//	//merge(arrA, 3, arrB, 3, arrRes, size);
//
//	//printArr(arrRes, 6);
//
//	//delete[] arrRes;
//}

int counstElementsInFile(myifstream& ifile)
{
	auto& file = ifile.stream;
	int count(0);

	if (!file.is_open())
	{
		return -1;
	}
	int n = 0;

	while (!file.eof())
	{
		file >> n;
		++count;
	}

	file.close();
	file.open(ifile.name, ifile.mode);

	if(!file.is_open())
	{
		return -1;
	}

	return count;
}

void fileMerge()
{
	string fileName1, fileName2, fileNameRes;

	cout << "������� ��� ������� �����: ";
	getline(cin, fileName1);
	cout << "������� ��� ������� �����: ";
	getline(cin, fileName2);

	cout << "������� ��� ��������� �����: ";
	getline(cin, fileNameRes);


	myifstream fOne(fileName1);
	myifstream fTwo(fileName2);
	std::ofstream fRes(fileNameRes);

	auto& fileOne = fOne.stream;
	auto& fileTwo = fTwo.stream;

	if (!fileOne.is_open())
	{
		cout << "���� �1 �� ������!";
		return;
	}
	else if (!fileTwo.is_open())
	{
		cout << "���� �2 �� ������!";
		return;
	}

	int sizeOne = counstElementsInFile(fOne);
	int sizeTwo = counstElementsInFile(fTwo);
	int sizeRes = sizeOne + sizeTwo;

	if (sizeOne <= 0 || sizeTwo <= 0)
	{
		cout << "������ ���������� ������ \n";
		return;
	}

	int* arrOne = nullptr;
	int* arrTwo = nullptr;
	int* arrRes = nullptr;

	allocateMemory(arrOne, sizeOne);
	allocateMemory(arrTwo, sizeTwo);

	inputArr(arrOne, sizeOne, fileOne);
	inputArr(arrTwo, sizeTwo, fileTwo);

	merge(arrOne, sizeOne, arrTwo, sizeTwo, arrRes, sizeRes);

	printArr(arrRes, sizeRes, fRes, '\n');

	cout << "������ ��������!";

	clearMemory(arrOne);
	clearMemory(arrTwo);
	clearMemory(arrRes);
}
