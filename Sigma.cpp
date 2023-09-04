#include <iostream>
#include <algorithm>
#include <cmath>
#include <ctime>
#include "Sigma.h"

using namespace std;

//задача 1
void theSumOfTheSeries1()
{
	cout << "Сумма ряда 1/n\n";

	double  prevEl(0), curEl(2), sum(0);
	double eps = 0.001;

	int i = 1;
	while (abs(curEl - prevEl) >= eps)
	{
		prevEl = curEl;
		curEl = 1.0 / i;
		sum += curEl;

		cout << "Сумма элементов = 1/" << i++ << '\t' << sum << endl;
	}
}

// Задача 2
void theSumOfTheSeries2()
{
	cout << "Сумма ряда n+1 / 4n\n";

	double prevEl(0), curEl(2), sum(0);
	double eps = 0.001;

	int i = 1;
	while (abs(curEl - prevEl) >= eps)
	{
		prevEl = curEl;
		curEl = 1.0 / ((i + 1.0) * (i + 1.0) * (i + 1.0) /
			(4.0 * i) * (4.0 * i) * (4.0 * i) * (4.0 * i));

		sum += curEl;
		cout << "Сумма элементов n+1 / 4n = " << i++ << '\t'
			<< sum << endl;
	}
}

// задача 3
void theSumOfTheSeries3()
{
	double prevEL(0), curEl(2), sum(0);
	double eps = 0.001;

	int i = 1;
	while (abs(curEl - prevEL) >= eps)
	{
		prevEL = curEl;
		curEl = 1.0 / (2 * (i + 1));
		sum += curEl;
		cout << "Сумма элементов 2n+1 = " << i++ << '\t' << sum << endl;
	}
}

// задача 4
void theSumOfTheSeries4()
{
	double prevEl(0), curEl(2), sum(0);
	double eps = 0.001;

	int i = 1;
	while (abs(curEl - prevEl) >= eps)
	{
		prevEl = curEl;
		curEl = 1.0 / (i * (i + 1) * (i + 2));
		sum += curEl;
		cout << "Сумма элемента 1/ n(n+1)(n+2) = " << i++ << '\t'
			<< sum << endl;
	}
}

// задача 5
void theSumOfTheSeries5()
{
	double prevEl(0), curEl(2), sum(0);
	double eps = 0.001;

	int i = 1;
	while (abs(curEl - prevEl) >= eps)
	{
		prevEl = curEl;
		curEl = 1.0 / (2 * (i + 1));
		sum += curEl;
		cout << "Сумма элемента 1/ 2(n+1) = " << i++ << '\t' <<
			sum << endl;
	}
}