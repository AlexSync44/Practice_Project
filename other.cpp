#include "other.h"
#include <string>
#include <sstream>

#define FIRST_DAY "Monday"
#define SECOND_DAY "Tuesday"
#define third_day "Wednesday"
#define fourth_day "Thursday"
#define fifth_day "Friday"
#define sixth_day "Saturday"
#define seventh_day "Sunday"

//#ifdef WINTER
//	cout << "Winter";
//#endif
//
//#ifdef SUMMER
//	cout << "Summer";
//#endif
//
//#ifdef SPRING
//	cout << "Spring";
//#endif
//
//#ifdef AUTUMN
//	cout << "Autumn";
//#endif

// ������ 1
void printNameAndAdress()
{
	cout << "�������" << endl;
	cout << "������, ���������� ���. �. ٸ�����.\n"
		<< endl << endl;
}

// ������ 2
void frlongsToYards()
{
	long int frlongs;
	long long int yards;

	cout << "�������������� ��������� � ���� " << endl;
	cout << "������� ���������� � ���������: ";
	cin >> frlongs;

	cout << "�����: " << frlongs * 220 << endl << endl;
}

// ������ 3
void func_1()
{
	for (int i = 0; i < 2; i++)
	{
		cout << "Three blind mice" << endl;
	}
}

void func_2()
{
	for (int i = 0; i < 2; i++)
	{
		cout << "See how they run" << endl;
	}
}

// ������ 4
void ageOfMonths()
{
	unsigned int short age;

	cout << "\n\n������� ���� �������: ";
	cin >> age;

	cout << "��� ������� � �������: " << age * 12 << endl << endl;

}

// ������ 5
void celsiusAndFahrenheit()
{
	double celsius, fahrenheit;

	cout << "\n������� �������� �������: ";
	cin >> celsius;

	cout << celsius << " �������� �� ������� = " << 1.8 * celsius + 32 <<
		" �������� �� ����������" << endl;

}

// ������ 6
void lightYearsToAstronomical()
{
	double light, astronomical;

	cout << "\n\n������� ����� � �������� �����: ";
	cin >> light;

	cout << light << " �������� ��� = " << light * 63240 <<
		" ��������������� ���" << endl;
}

// ������ 7
void watch()
{
	int hour, minute;

	cout << "������� ���: ";
	cin >> hour;
	cout << "������� ������: ";
	cin >> minute;

	minute %= 60;
	hour += minute / 60;


	cout << "�����: " << hour << ":" << minute << "\n\n" << endl;
}

// ������ �������� 
void factorial()
{
	int factorial;
	int counter(1);
	unsigned long long res(1);

	cout << "������� ��������� �����: ";
	cin >> factorial;

	for (int i = 1; i <= factorial; i++)
	{
		res *= i;
	}
	cout << "��������� ����� " << factorial << ": " << res << endl;
}

// ������ 8 | 3 �������� � ��������
void arrayProduct()
{
	int negsum = 0;
	long int work = -1;
	int number = 0;
	const int size = 50;
	int arr[size] = { 0 };

	for (int i = 0; i < size; i++)
	{
		arr[i] = 500 - rand() % 1001;
		cout << " " << arr[i];
	}

	for (int i = 0; i < size; i++)
	{
		if (arr[i] < 0)
		{
			work *= arr[i];
			negsum += arr[i];
			number += 1;
		}
	}

	cout << "\n������������ ������������� ����������: " << work
		<< endl;
	cout << "����� ������������� ����������: " << negsum
		<< endl;
	cout << "���-�� ������������� �����: " << number
		<< endl;
}

//������ 9 | ��������� 2 ������������� ��������
void comparingArrays()
{
	int number1 = 0;
	int number2 = 0;

	const int size1 = 10;
	int arr1[size1]{ 0 };

	const int size2 = 10;
	int arr2[size2]{ 0 };

	cout << "\n\n";

	for (int i = 0; i < size1; i++)
	{
		arr1[i] = 500 - rand() % 1001;
		cout << " " << arr1[i];
	}

	cout << "\n\n";

	for (int i = 0; i < size2; i++)
	{
		arr2[i] = 500 - rand() % 1001;
		cout << " " << arr2[i];
	}

	for (int i = 0; i < size1; i++)
	{
		if (arr1[i] < 0)
		{
			number1 += 1;
		}
	}

	for (int i = 0; i < size2; i++)
	{
		if (arr2[i] < 0)
		{
			number2 += 1;
		}
	}

	cout << "\n\n���-�� ������������ ����� 1 �������: " << number1 << endl;
	cout << "���-�� ������������ ����� 2 �������: " << number2 << endl;

	if (number1 > number2)
	{
		cout << "������ ������ ������!" << endl;
		return;
	}
	else if (number2 > number1)
	{
		cout << "������ ������ ������!" << endl;
		return;
	}
	else if (number1 == number2)
	{
		cout << "������� �����!" << endl;
	}
}

// ������ 10 | ����� > 5 � �������
void arrayIsGreaterThanFive()
{
	int sum = 0;
	const int size = 50;
	int arr[size]{ 0 };

	for (int i = 0; i < size; i++)
	{
		arr[i] = 500 - rand() % 1001;
		cout << " " << arr[i];
	}

	for (int i = 0; i < size; i++)
	{
		if (arr[i] >= 5)
		{
			sum += arr[i];
		}
	}

	cout << "\n����� ��������� ������ 5 = " << sum << endl;
}

// ������ 11 | ���������� ����� � �������
void identicalNumbers()
{
	int x;
	int identical = 0;
	const int size = 100;
	int arr[size]{ 0 };

	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 11;
		cout << " " << arr[i];
	}

	cout << "\n\n������� ����� �� 10: ";

	while (!(cin >> x))
	{
		cin.clear();
		cin.ignore();
		cout << "\n������� ����� =  ";
	}

	for (int i = 0; i < size; i++)
	{
		if (arr[i] == x)
		{
			identical += 1;
		}
	}
	cout << "���-�� �����: " << identical << endl;
}

// ������ 12 | ����������� �� 2
void traceNumbersByTwo()
{
	cout << "����� ���� 1 + ... + 1/2^n\n\n";

	double s(1), elRow(1);
	unsigned n;

	cout << "������� ���-�� ��������� ���� n = ";
	while (!(cin >> n))
	{
		cin.clear();
		cin.ignore();
		cout << "\n������� ���-�� ��������� ���� n = ";
	}

	cout << "#\t\ta_i\t\tS\n";
	for (size_t i = 1; i <= n; i++)
	{
		elRow *= i + 1 / ((i + 2) * (i + 2));
		s += elRow;

		cout << i << '\t' << elRow << '\t' << s << '\n';
	}
}

//������ 13 | ����������� 1/3^n
void traceNumbersByThree()
{
	cout << "����� ���� 1 + ... + 1/3^n\n\n";

	double s(1), elRow(1);
	unsigned n;

	cout << "������� ���-�� ��������� ���� n = ";
	while (!(cin >> n))
	{
		cin.clear();
		cin.ignore();
		cout << "\n������� ���-�� ��������� ���� n = ";
	}

	cout << "#\t\ta_i\t\tS\n";
	for (size_t i = 1; i <= n; i++)
	{
		elRow *= 1.0 / ((2 * i + 1) * (2 * i + 2) * (2 * i + 2));
		s += elRow;

		cout << i << '\t' << elRow << '\t' << s << '\n';
	}
}

// ������ 14 | ����������� ����
void sumOfNumbersInACube()
{
	cout << "����� ���� 1^*3\n\n";

	double sum(0);
	unsigned n;

	cout << "������� ���-�� ��������� ���� n = ";
	while (!(cin >> n))
	{
		cin.clear();
		cin.ignore();
		cout << "\n������� ���-�� ��������� ���� n = ";
	}

	for (long i = 1; i <= n; i++)
	{
		sum += (i * i * i);						//pow(i, 3.0); ������
		cout << "����� ��������� = " << pow(i, 3.0) << '\t' << sum << endl;
	}
}

// ������ 15 | ��������� ������ � ������
void workshopComparison()
{
	int men, people, dif;

	cout << "������� ���-�� �����: ";
	while (!(cin >> people))
	{
		cin.clear();
		cin.ignore();
		cout << "\n������� ���-�� �����: ";
	}

	cout << "\n������� ���-�� ������: ";
	while (!(cin >> men))
	{
		cin.clear();
		cin.ignore();
		cout << "\n������� ���-�� ������: ";
	}

	dif = people - men;

	if (dif > men)
		cout << "\n������ ������ ��� ������ ��: " << dif - men << '\n';
	else if (dif < men)
		cout << "\n������ ������ ��� ������ ��: " << men - dif << '\n';
	else
		cout << "\n������ � ������ �������";
}

// ������ 16 | ���������� ���� �����
void boatPath()
{
	unsigned speedRiver, speedBoat, overallSpeed, speedAgainst;
	double timeBack, timeForward, riverDistance, distanceOpposite;

	cout << "������� �������� �����: ";
	while (!(cin >> speedRiver))
	{
		cin.clear();
		cin.ignore();
		cout << "\n������� �������� �����: ";
	}

	cout << "������� �������� ����: ";
	while (!(cin >> speedBoat))
	{
		cin.clear();
		cin.ignore();
		cout << "\n������� �������� ����: ";
	}

	cout << "������� ����� �������� �� �����: ";
	while (!(cin >> timeForward))
	{
		cin.clear();
		cin.ignore();
		cout << "\n������� ����� �������� �� �����: ";
	}

	cout << "������� ����� �������� ������ �������: ";
	while (!(cin >> timeBack))
	{
		cin.clear();
		cin.ignore();
		cout << "\n������� ����� �������� ������ �������: ";
	}

	overallSpeed = speedRiver + speedBoat;

	riverDistance = overallSpeed * timeForward;

	cout << "\n���� ���������� �� ������� ���� � ��/�: "
		<< riverDistance << endl;

	speedAgainst = speedRiver - speedBoat;
	distanceOpposite = speedAgainst * timeBack;

	cout << "\n���� ���������� ������ ������� � ��/�: " <<
		distanceOpposite << endl;

	cout << "\n����� ���� �����: " <<
		riverDistance + distanceOpposite << endl;
}

// ������ 17 | ������� ���������� |50 �� 50
void triangleSquare()
{
	float x, y, area;
	const int size = 6;
	double coords[size]{ 0 };

	cout << "������� ���������� ������ ������������:";
	for (size_t i = 0; i < size; i++)
	{
		if (!(cin >> coords[i]))
		{
			cin.clear();
			cin.ignore();
			cout << "������� ���������� ������ ������������:";
			--i;
		}
	}

	area = ((coords[2] - coords[0]) * (coords[5] - coords[1]) -
		(coords[4] - coords[0]) * (coords[3] - coords[1])) / 2;

	cout << "������� ������������: " << area;
}

// ������ 18 | ��������� ��� % �� ����� ����
void usaPopulation()
{
	long long peopleUsa, peopleWorld;
	double percent;

	cout << "������� ��������� ����: ";
	while (!(cin >> peopleWorld))
	{
		cin.clear();
		cin.ignore();
		cout << "\n������� ��������� ����: ";
	}

	cout << "������� ��������� ���: ";
	while (!(cin >> peopleUsa))
	{
		cin.clear();
		cin.ignore();
		cout << "\n������� ��������� ���: ";
	}

	percent = (double)peopleUsa / peopleWorld * 100;
	cout << "��������� ��� = " << percent << "%" << " �� ����� ����" << endl;
}

// ������ 19 | n ������ �� 100 ��
void litersToKm()
{
	int liters, km;
	double dif;

	cout << "������� ���-�� ������: ";
	while (!(cin >> liters))
	{
		cin.clear();
		cin.ignore();
		cout << "\n������� ���-�� ������: ";
	}

	cout << "������� ���������: ";
	while (!(cin >> km
		))
	{
		cin.clear();
		cin.ignore();
		cout << "\n������� ���������: ";
	}

	dif = (double)liters / km * 100;
	cout << dif << " ������ �� 100 ��";
}

// ������ 20 | ������� ������� � ����
void europeanGasoline()
{
	const double mileKm(1.609), gallon(3.875);
	unsigned liters, km, mile, mileGallon;

	cout << "������� ���-�� ������ �� 100 ��: ";
	while (!(cin >> liters))
	{
		cin.clear();
		cin.ignore();
		cout << "\n������� ���-�� ������: ";
	}
	km = 100 / liters;
	mile = km / mileKm;
	mileGallon = mile * gallon;

	cout << "���-�� ���� �� ������: " << gallon << endl;
}


// ������ 21 | ����������� 1, 1/!2, 1/!3...
void foursTrace()
{
	double elRow(1), sum(0), fac(1);
	unsigned n, factorial;

	cout << "������� ���-�� ��������� n: ";
	while (!(cin >> n))
	{
		cin.clear();
		cin.ignore();
		cout << "\n������� ���-�� ��������� ���� n = ";
	}

	cout << "#\ta_i\tS\n";
	for (size_t i = 2; i <= n; i++)
	{
		fac *= i;
		elRow = 1.0 / fac;
		sum += elRow;
		cout << i << '\t' << elRow << '\t' << sum << '\n';
	}
}

// ������ 22 | ����������� 0.5 0.55 0.555...
void traceFives()
{
	double elRow(0), sum(0), fac(1);
	unsigned n, factorial;

	cout << "������� ���-�� ��������� n: ";
	while (!(cin >> n))
	{
		cin.clear();
		cin.ignore();
		cout << "\n������� ���-�� ��������� ���� n = ";
	}

	cout << "#\ta_i\tS\n";
	for (size_t i = 1; i <= n; i++)
	{
		elRow /= 10;
		elRow += 0.5;
		sum += elRow;

		cout << i << '\t' << sum << '\t' << elRow << '\n';
	}
}


// ������ 23 | ���������� ����� 1
void sameNumbers1()
{
	int a, b, c;

	cout << "������� 3 �����: ";
	while (!(cin >> a >> b >> c))
	{
		cin.clear();
		cin.ignore();
		cout << "\n������� 3 �����: ";
	}
	cout << (a == b ? "���������� ����� 1 � 2" : a == c ?
		"���������� ����� 1 � 3" : b == c ? "���������� ����� 2 � 3"
		: "��� ���������� �����") << endl;
}

// ������ 24 | ���������� ����� 2
void sameNumbers2()
{
	int sum(0), i(0);
	const int size = 10;
	int arr[size]{ 0 };

	inputArr(arr, size);

	while (i < 11)
	{
		int j = i + 1;
		while (j < 10)
		{
			if (arr[i] == arr[j])
			{
				cout << arr[i] << '\t' << arr[j] << endl;
				arr[i] = arr[j] = true;
				sum += 1;
			}
			++j;
		}
		++i;
	}
	cout << "\n���-�� ������� ���������: " << sum << endl;

}

bool containsInArr(int* arr, int size, int num)
{
	for (int i(0); i < size; i++)
	{
		if (arr[i] == num)
		{
			return true;
		}
	}

	return false;
}

// ������ 5 | �� ��� ������������� �����
void rowOfNumbers2()
{
	const int size = 10;
	int arr[size]{ 0 };
	bool theSameNumbers[size]{ 0 };
	int i(0), j;
	short sum(0);

	int num;
	int countRepeat = 0;
	for (int i(0); i < size; i++)
	{
		num = rand() % 11;

		if (containsInArr(arr, i, num))
		{
			if (countRepeat < 1)
			{
				arr[i] = num;
				countRepeat++;
			}
			--i;
			continue;
		}
		else
		{
			arr[i] = num;
		}
	}

	//inputArr

	printArr(arr, size);

	while (i < 11)
	{
		j = i + 1;
		while (j < 10)
		{
			if (arr[i] == arr[j])
			{
				cout << arr[i] << '\t' << arr[j] << endl;
				theSameNumbers[i] = theSameNumbers[j] = true;
				sum += 1;
			}
			++j;
		}
		++i;
	}
	cout << "\n���-�� ������� ���������: " << sum << endl;
}

// ������ � ����� �6
void findMaxInRows()
{
	int** matrix = nullptr;
	int* maxInRow = nullptr;
	int rows, cols;

	cout << "������� ���-�� ����� � ��������: ";
	while (!(cin >> rows >> cols))
	{
		cin.clear();
		cin.ignore();
		cout << "������� ���-�� ����� � ��������: ";
	}

	allocateMemory(matrix, rows, cols);
	allocateMemory(maxInRow, rows);

	fillMatrix(matrix, rows, cols, 10, 500);

	printMatrix(matrix, rows, cols);

	for (size_t i = 0; i < rows; i++)
	{
		maxInRow[i] = matrix[i][0];

		for (size_t j = 0; j < cols; j++)
		{
			if (matrix[i][j] > maxInRow[i])
			{
				maxInRow[i] = matrix[i][j];
			}
		}
	}

	cout << "\n������������ �������� � �������: ";
	printArr(maxInRow, cols);

	delete[] matrix;
	delete[] maxInRow;
}

// ������ � ����� � 7 TO DO
void sortMainDiagMatr()
{
	int** matr = nullptr;
	int* arrMainDiag = nullptr;
	int rows, cols;

	cout << "������� ���-�� ����� � ��������: ";
	while (!(cin >> rows >> cols))
	{
		cin.clear();
		cin.ignore();
		cout << "������� ���-�� ����� � ��������: ";
	}

	allocateMemory(matr, rows, cols);
	allocateMemory(arrMainDiag, rows);
	fillMatrix(matr, rows, cols);
	printMatrix(matr, rows, cols, 4);
	cout << "\n\n";

	for (size_t i = 0; i < rows; i++)
	{
		arrMainDiag[i] = matr[i][i];
	}

	quick_sort(arrMainDiag, 0, rows - 1);

	for (size_t i = 0; i < rows; i++)
	{
		matr[i][i] = arrMainDiag[i];
	}

	printMatrix(matr, rows, cols, 4);
}

// ������ � ����� �8
void letterSearch()
{
	std::string str, resStr;
	char letter;
	int count(0), ind(0);

	cout << "������� �����: ";
	cin >> letter;

	cout << "������� �������: ";
	while (cin >> str)
	{
		ind = str.find(letter);
		if (ind >= 0)
		{
			count++;
			char c = std::toupper(str[ind]);
			str[ind] = c;
			resStr += str + ' ';
		}
	}

	cout << "���� � ������ " << letter << " = " << count << '\n';
	cout << "�����: " << resStr << endl;
}

void task1Matrix()
{
	int** matr = nullptr;
	int rows, cols, sum(0);

	cout << "������� ���-�� ����� � ��������: ";
	cin >> rows >> cols;

	allocateMemory(matr, rows, cols);
	fillMatrix(matr, rows, cols, 10, 599);

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			if (i < j)
			{
				sum += matr[i][j];
			}
		}
	}

	cout << "����� ����� ���� ������� ���������: " << sum << endl;
	delete[] matr;
}

void matrixOperation_ticket1()
{
	int** matrixOne = nullptr;
	int** matrixTwo = nullptr;
	int rowsOne, colsOne, rowsTwo, colsTwo;

	cout << "������� ���-�� ����� � �������� ��� 1 �������: ";
	while (!(cin >> rowsOne >> colsOne))
	{
		cin.clear();
		cin.ignore();
		cout << "������� ���-�� ����� � ��������: ";
	}

	cout << "������� ���-�� ����� � �������� ��� 2 �������: ";
	while (!(cin >> rowsTwo >> colsTwo))
	{
		cin.clear();
		cin.ignore();
		cout << "\n������� ���-�� ����� � ��������: ";
	}

	allocateMemory(matrixOne, rowsOne, colsOne);
	allocateMemory(matrixTwo, rowsTwo, colsTwo);

	fillMatrix(matrixOne, rowsOne, colsOne);
	fillMatrix(matrixTwo, rowsTwo, colsTwo);

	int sumMinOne = INT_MAX;
	for (size_t i = 0; i < rowsOne; i++)
	{
		int sum = sumArr(matrixOne[i], colsOne);

		if (sum < sumMinOne)
		{
			sumMinOne = sum;
		}
	}

	int sumMinTwo = INT_MAX;
	for (size_t i = 0; i < rowsTwo; i++)
	{
		int sum = sumArr(matrixTwo[i], colsTwo);

		if (sum < sumMinTwo)
		{
			sumMinTwo = sum;
		}
	}

	printMatrix(matrixOne, rowsOne, colsOne);
	cout << "\n\n";
	printMatrix(matrixTwo, rowsTwo, colsTwo);

	int res(0), count(0), compos(1);
	if (sumMinOne < sumMinTwo)
	{
		for (size_t i = 0; i < rowsOne; i++)
		{
			res = 0;
			for (size_t j = 0; j < colsOne; j++)
			{
				if (j % 2 == 1 && i < j)
				{
					res += matrixOne[i][j];
					count++;
				}
			}
			if (res != 0 && count != 0)
			{
			res /= count;
			compos *= res;
			}
		}
	}
	else if (sumMinOne > sumMinTwo)
	{
		for (size_t i = 0; i < rowsTwo; i++)
		{
			res = 0;
			for (size_t j = 0; j < colsTwo; j++)
			{
				if (j % 2 == 1 && i < j)
				{
					res += matrixTwo[i][j];
					count++;
				}
			}
			if (res != 0 && count != 0)
			{
				res /= count;
				compos *= res;
			}
		}
	}

	cout << "������������ = " << compos << endl;

	delete[] matrixOne;
	delete[] matrixTwo;
}

bool stringPalindrome(string str)
{
	if (str.empty()) return false;

	string bufStrRev;

	for (size_t i = str.size() - 1; i >= 0; i--)
	{
		bufStrRev += str[i];
	}

	return (bufStrRev == str);
}

void palindromeStrTest()
{
	std::string str;

	cout << "������� �������: ";
	getline(cin, str);

	stringPalindrome(str) ? cout << "YES\n" : cout << "NO\n";
}

void longestWord()
{
	unsigned len(0), maxLen(0);
	string str, buf, word;
	
	cout << "������� �������: ";
	getline(cin, str);
	stringstream sstream(str);

	while (sstream >> buf)
	{
		len = buf.size();
		if (len > maxLen)
		{
			word = buf;
			maxLen = len;
		}
	}

	cout << "\n�����:" << word << "\n���-�� ����: " << maxLen;
}

void detectivesTest()
{
	short num;

	cout << "������� ���������� ����� ���: ";
	cin >> num;

	switch (num)
	{
	case 1:
	{
		cout << FIRST_DAY << endl;
		break;
	}
	case 2:
	{
		cout << SECOND_DAY << endl;
		break;
	}
	case 3:
	{
		cout << third_day << endl;
		break;
	}
	case 4:
	{
		cout << fourth_day << endl;
		break;
	}
	case 5:
	{
		cout << fifth_day << endl;
		break;
	}
	case 6:
	{
		cout << sixth_day << endl;
		break;
	}
	case 7:
	{
		cout << seventh_day << endl;
		break;
	}
	default:
		cout << "� ������ 7 ����!" << endl;
		break;
	}
}

void task_3()
{
	int sizeArr;

	cin >> sizeArr;

	int* arr = nullptr;
	arr = new int[sizeArr];

	for (size_t i = 0; i < sizeArr; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < sizeArr; i++)
	{
		if (arr[sizeArr - 1] < arr[i] && i > 0)
		{
			cout << arr[i] << ' ';
		}
	}

	delete[] arr;
}

void findStrTest()
{
	string str, word;

	cout << "������� ������: \n";
	getline(cin, str);

	cout << "������� ����� ��� ������: ";
	getline(cin, word);

	int ind = str.find(word);

	if (ind == std::string::npos)
	{
		cout << "\n����� �� �������!\n";
	}
	else
	{
		cout << "\n����� ������� �� " << ind << " �������!\n";
		for (char& c : word)
		{
			c = toupper(c);
		}

		str.replace(ind, word.size(), word);
		cout << "\n������ ������ : " << str;
	}

	/*stringstream sstream(str);
	while (sstream >> buf)
	{
		count++;

		if (strcmp(buf.c_str(), word.c_str()) == 0)
		{
			cout << "\n������� ����� �� " << count << " �������\n";

			for (char& c : buf)
			{
				c = toupper(c);
			}
			str.replace(indWord, word.size(), buf);
		}
		indWord += buf.size() + 1;
	}*/
}

void frame()
{
	int width, numField, border;
	char letter;

	cout << "������� ������ �����: ";
	cin >> border;
	cin.ignore();

	cout << "������� ������ ��� �����: ";
	cin >> letter;
	cin.ignore();

	cout << "������� ���-�� ����� ����: ";
	cin >> numField;
	cin.ignore();

	cout << "������� ���������� �������� � ������ (������ ����): ";
	cin >> width;

	for (size_t i = 1; i <= border; i++)
	{
		for (size_t j = 1; j <= width + border * 2; j++)
		{
			cout << letter;
		}
		cout << endl;
	}

	for (size_t i = border; i <= numField + border; i++)
	{
		for (size_t j = 1; j <= width + border * 2; j++)
		{
			if (j <= border || j > width + border)
			{
				cout << letter;
			}
			else
			{
				cout << ' ';
			}
		}
		cout << endl;
	}

	for (size_t i = 1; i <= border; i++)
	{
		for (size_t j = 1; j <= width + border * 2; j++)
		{
			cout << letter;
		}
		cout << endl;
	}
}