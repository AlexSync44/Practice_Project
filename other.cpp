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

// задача 1
void printNameAndAdress()
{
	cout << "Алексей" << endl;
	cout << "Россия, Московская обл. г. Щёлково.\n"
		<< endl << endl;
}

// задача 2
void frlongsToYards()
{
	long int frlongs;
	long long int yards;

	cout << "Преобразование фарлонгов в ярды " << endl;
	cout << "Введите расстояние в фарлонгах: ";
	cin >> frlongs;

	cout << "Ярдов: " << frlongs * 220 << endl << endl;
}

// задача 3
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

// задача 4
void ageOfMonths()
{
	unsigned int short age;

	cout << "\n\nВведите свой возраст: ";
	cin >> age;

	cout << "Ваш возраст в месяцах: " << age * 12 << endl << endl;

}

// задача 5
void celsiusAndFahrenheit()
{
	double celsius, fahrenheit;

	cout << "\nВведите значение Цельсия: ";
	cin >> celsius;

	cout << celsius << " градусов по Цельсию = " << 1.8 * celsius + 32 <<
		" градусов по Фаренгейту" << endl;

}

// задача 6
void lightYearsToAstronomical()
{
	double light, astronomical;

	cout << "\n\nВведите число в световых годах: ";
	cin >> light;

	cout << light << " световых лет = " << light * 63240 <<
		" астрономических лет" << endl;
}

// задача 7
void watch()
{
	int hour, minute;

	cout << "Введите час: ";
	cin >> hour;
	cout << "Введите минуты: ";
	cin >> minute;

	minute %= 60;
	hour += minute / 60;


	cout << "Время: " << hour << ":" << minute << "\n\n" << endl;
}

// задача практика 
void factorial()
{
	int factorial;
	int counter(1);
	unsigned long long res(1);

	cout << "Введите факториал числа: ";
	cin >> factorial;

	for (int i = 1; i <= factorial; i++)
	{
		res *= i;
	}
	cout << "Факториал числа " << factorial << ": " << res << endl;
}

// задача 8 | 3 операции с массивом
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

	cout << "\nПроизведение отрицательных эллементов: " << work
		<< endl;
	cout << "Сумма отрицательных эллементов: " << negsum
		<< endl;
	cout << "Кол-во отрицательных чисел: " << number
		<< endl;
}

//задача 9 | сравнение 2 отрицательных массивов
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

	cout << "\n\nКол-во отрицаельных чисел 1 массива: " << number1 << endl;
	cout << "Кол-во отрицаельных чисел 2 массива: " << number2 << endl;

	if (number1 > number2)
	{
		cout << "Первый массив больше!" << endl;
		return;
	}
	else if (number2 > number1)
	{
		cout << "Второй массив больше!" << endl;
		return;
	}
	else if (number1 == number2)
	{
		cout << "Массивы равны!" << endl;
	}
}

// задача 10 | сумма > 5 в массиве
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

	cout << "\nСумма элементов больше 5 = " << sum << endl;
}

// задача 11 | одинаковые числа в массиве
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

	cout << "\n\nВведите число до 10: ";

	while (!(cin >> x))
	{
		cin.clear();
		cin.ignore();
		cout << "\nВведите число =  ";
	}

	for (int i = 0; i < size; i++)
	{
		if (arr[i] == x)
		{
			identical += 1;
		}
	}
	cout << "Кол-во чисел: " << identical << endl;
}

// задача 12 | трассировка на 2
void traceNumbersByTwo()
{
	cout << "Сумма ряда 1 + ... + 1/2^n\n\n";

	double s(1), elRow(1);
	unsigned n;

	cout << "Введите кол-во элементов ряда n = ";
	while (!(cin >> n))
	{
		cin.clear();
		cin.ignore();
		cout << "\nВведите кол-во элементов ряда n = ";
	}

	cout << "#\t\ta_i\t\tS\n";
	for (size_t i = 1; i <= n; i++)
	{
		elRow *= i + 1 / ((i + 2) * (i + 2));
		s += elRow;

		cout << i << '\t' << elRow << '\t' << s << '\n';
	}
}

//задача 13 | трассировка 1/3^n
void traceNumbersByThree()
{
	cout << "Сумма ряда 1 + ... + 1/3^n\n\n";

	double s(1), elRow(1);
	unsigned n;

	cout << "Введите кол-во элементов ряда n = ";
	while (!(cin >> n))
	{
		cin.clear();
		cin.ignore();
		cout << "\nВведите кол-во элементов ряда n = ";
	}

	cout << "#\t\ta_i\t\tS\n";
	for (size_t i = 1; i <= n; i++)
	{
		elRow *= 1.0 / ((2 * i + 1) * (2 * i + 2) * (2 * i + 2));
		s += elRow;

		cout << i << '\t' << elRow << '\t' << s << '\n';
	}
}

// задача 14 | трассировка куба
void sumOfNumbersInACube()
{
	cout << "Сумма ряда 1^*3\n\n";

	double sum(0);
	unsigned n;

	cout << "Введите кол-во элементов ряда n = ";
	while (!(cin >> n))
	{
		cin.clear();
		cin.ignore();
		cout << "\nВведите кол-во элементов ряда n = ";
	}

	for (long i = 1; i <= n; i++)
	{
		sum += (i * i * i);						//pow(i, 3.0); замена
		cout << "Сумма элементов = " << pow(i, 3.0) << '\t' << sum << endl;
	}
}

// задача 15 | сравнение мужчин и женщин
void workshopComparison()
{
	int men, people, dif;

	cout << "Введите кол-во людей: ";
	while (!(cin >> people))
	{
		cin.clear();
		cin.ignore();
		cout << "\nВведите кол-во людей: ";
	}

	cout << "\nВведите кол-во мужчин: ";
	while (!(cin >> men))
	{
		cin.clear();
		cin.ignore();
		cout << "\nВведите кол-во мужчин: ";
	}

	dif = people - men;

	if (dif > men)
		cout << "\nЖенщин больше чем мужчин на: " << dif - men << '\n';
	else if (dif < men)
		cout << "\nМужчин больше чем женщин на: " << men - dif << '\n';
	else
		cout << "\nМужчин и женщин поровну";
}

// задача 16 | пройденный путь лодки
void boatPath()
{
	unsigned speedRiver, speedBoat, overallSpeed, speedAgainst;
	double timeBack, timeForward, riverDistance, distanceOpposite;

	cout << "Введите скорость лодки: ";
	while (!(cin >> speedRiver))
	{
		cin.clear();
		cin.ignore();
		cout << "\nВведите скорость лодки: ";
	}

	cout << "Введите скорость реки: ";
	while (!(cin >> speedBoat))
	{
		cin.clear();
		cin.ignore();
		cout << "\nВведите скорость реки: ";
	}

	cout << "Введите время движения по озеру: ";
	while (!(cin >> timeForward))
	{
		cin.clear();
		cin.ignore();
		cout << "\nВведите время движения по озеру: ";
	}

	cout << "Введите время движения против течения: ";
	while (!(cin >> timeBack))
	{
		cin.clear();
		cin.ignore();
		cout << "\nВведите время движения против течения: ";
	}

	overallSpeed = speedRiver + speedBoat;

	riverDistance = overallSpeed * timeForward;

	cout << "\nПуть пройденный по течению реки в км/ч: "
		<< riverDistance << endl;

	speedAgainst = speedRiver - speedBoat;
	distanceOpposite = speedAgainst * timeBack;

	cout << "\nПуть пройденный против течения в км/ч: " <<
		distanceOpposite << endl;

	cout << "\nОбщий путь лодки: " <<
		riverDistance + distanceOpposite << endl;
}

// задача 17 | Площадь треуголька |50 на 50
void triangleSquare()
{
	float x, y, area;
	const int size = 6;
	double coords[size]{ 0 };

	cout << "Введите координаты вершин треугольника:";
	for (size_t i = 0; i < size; i++)
	{
		if (!(cin >> coords[i]))
		{
			cin.clear();
			cin.ignore();
			cout << "Введите координаты вершин треугольника:";
			--i;
		}
	}

	area = ((coords[2] - coords[0]) * (coords[5] - coords[1]) -
		(coords[4] - coords[0]) * (coords[3] - coords[1])) / 2;

	cout << "Площадь треугольника: " << area;
}

// задача 18 | Население США % от всего мира
void usaPopulation()
{
	long long peopleUsa, peopleWorld;
	double percent;

	cout << "Введите население мира: ";
	while (!(cin >> peopleWorld))
	{
		cin.clear();
		cin.ignore();
		cout << "\nВведите население мира: ";
	}

	cout << "Введите население США: ";
	while (!(cin >> peopleUsa))
	{
		cin.clear();
		cin.ignore();
		cout << "\nВведите население США: ";
	}

	percent = (double)peopleUsa / peopleWorld * 100;
	cout << "Население США = " << percent << "%" << " от всего мира" << endl;
}

// задача 19 | n литров на 100 км
void litersToKm()
{
	int liters, km;
	double dif;

	cout << "Введите кол-во литров: ";
	while (!(cin >> liters))
	{
		cin.clear();
		cin.ignore();
		cout << "\nВведите кол-во литров: ";
	}

	cout << "Введите километры: ";
	while (!(cin >> km
		))
	{
		cin.clear();
		cin.ignore();
		cout << "\nВведите километры: ";
	}

	dif = (double)liters / km * 100;
	cout << dif << " Литров на 100 КМ";
}

// задача 20 | перевод голонов в мили
void europeanGasoline()
{
	const double mileKm(1.609), gallon(3.875);
	unsigned liters, km, mile, mileGallon;

	cout << "Введите кол-во литров на 100 КМ: ";
	while (!(cin >> liters))
	{
		cin.clear();
		cin.ignore();
		cout << "\nВведите кол-во литров: ";
	}
	km = 100 / liters;
	mile = km / mileKm;
	mileGallon = mile * gallon;

	cout << "Кол-во миль на галлон: " << gallon << endl;
}


// задача 21 | Трассировка 1, 1/!2, 1/!3...
void foursTrace()
{
	double elRow(1), sum(0), fac(1);
	unsigned n, factorial;

	cout << "Введите кол-во элементов n: ";
	while (!(cin >> n))
	{
		cin.clear();
		cin.ignore();
		cout << "\nВведите кол-во элементов ряда n = ";
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

// задача 22 | Трассировка 0.5 0.55 0.555...
void traceFives()
{
	double elRow(0), sum(0), fac(1);
	unsigned n, factorial;

	cout << "Введите кол-во элементов n: ";
	while (!(cin >> n))
	{
		cin.clear();
		cin.ignore();
		cout << "\nВведите кол-во элементов ряда n = ";
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


// задача 23 | одинаковые числа 1
void sameNumbers1()
{
	int a, b, c;

	cout << "Введите 3 числа: ";
	while (!(cin >> a >> b >> c))
	{
		cin.clear();
		cin.ignore();
		cout << "\nВведите 3 числа: ";
	}
	cout << (a == b ? "Одинаковые числа 1 и 2" : a == c ?
		"Одинаковые числа 1 и 3" : b == c ? "Одинаковые числа 2 и 3"
		: "Нет одинаковых чисел") << endl;
}

// задача 24 | одинаковые числа 2
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
	cout << "\nКол-во похожих элементов: " << sum << endl;

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

// задача 5 | на ряд повторяющихся чисел
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
	cout << "\nКол-во похожих элементов: " << sum << endl;
}

// задача с уника №6
void findMaxInRows()
{
	int** matrix = nullptr;
	int* maxInRow = nullptr;
	int rows, cols;

	cout << "Введите кол-во строк и столбцов: ";
	while (!(cin >> rows >> cols))
	{
		cin.clear();
		cin.ignore();
		cout << "Введите кол-во строк и столбцов: ";
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

	cout << "\nМаксимальные значения в строках: ";
	printArr(maxInRow, cols);

	delete[] matrix;
	delete[] maxInRow;
}

// задача с уника № 7 TO DO
void sortMainDiagMatr()
{
	int** matr = nullptr;
	int* arrMainDiag = nullptr;
	int rows, cols;

	cout << "Введите кол-во строк и столбцов: ";
	while (!(cin >> rows >> cols))
	{
		cin.clear();
		cin.ignore();
		cout << "Введите кол-во строк и столбцов: ";
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

// задачи с уника №8
void letterSearch()
{
	std::string str, resStr;
	char letter;
	int count(0), ind(0);

	cout << "Введите букву: ";
	cin >> letter;

	cout << "Введите строчку: ";
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

	cout << "Слов с буквой " << letter << " = " << count << '\n';
	cout << "Слова: " << resStr << endl;
}

void task1Matrix()
{
	int** matr = nullptr;
	int rows, cols, sum(0);

	cout << "Введите кол-во строк и столбцов: ";
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

	cout << "Сумма чисел выше главной диагонали: " << sum << endl;
	delete[] matr;
}

void matrixOperation_ticket1()
{
	int** matrixOne = nullptr;
	int** matrixTwo = nullptr;
	int rowsOne, colsOne, rowsTwo, colsTwo;

	cout << "Введите кол-во строк и столбцов для 1 массива: ";
	while (!(cin >> rowsOne >> colsOne))
	{
		cin.clear();
		cin.ignore();
		cout << "Введите кол-во строк и столбцов: ";
	}

	cout << "Введите кол-во строк и столбцов для 2 массива: ";
	while (!(cin >> rowsTwo >> colsTwo))
	{
		cin.clear();
		cin.ignore();
		cout << "\nВведите кол-во строк и столбцов: ";
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

	cout << "Произведение = " << compos << endl;

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

	cout << "Введите строчку: ";
	getline(cin, str);

	stringPalindrome(str) ? cout << "YES\n" : cout << "NO\n";
}

void longestWord()
{
	unsigned len(0), maxLen(0);
	string str, buf, word;
	
	cout << "Введите строчку: ";
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

	cout << "\nСлово:" << word << "\nКол-во букв: " << maxLen;
}

void detectivesTest()
{
	short num;

	cout << "Введите порядковый номер дня: ";
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
		cout << "В неделе 7 дней!" << endl;
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

	cout << "Введите строку: \n";
	getline(cin, str);

	cout << "Введите слово для поиска: ";
	getline(cin, word);

	int ind = str.find(word);

	if (ind == std::string::npos)
	{
		cout << "\nСлово не найдено!\n";
	}
	else
	{
		cout << "\nСлово найдено на " << ind << " позиции!\n";
		for (char& c : word)
		{
			c = toupper(c);
		}

		str.replace(ind, word.size(), word);
		cout << "\nПолная строка : " << str;
	}

	/*stringstream sstream(str);
	while (sstream >> buf)
	{
		count++;

		if (strcmp(buf.c_str(), word.c_str()) == 0)
		{
			cout << "\nНайдено слово на " << count << " позиции\n";

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

	cout << "Введите ширину рамки: ";
	cin >> border;
	cin.ignore();

	cout << "Введите символ для рамки: ";
	cin >> letter;
	cin.ignore();

	cout << "Введите кол-во строк поля: ";
	cin >> numField;
	cin.ignore();

	cout << "Введите количество символов в строке (ширину поля): ";
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