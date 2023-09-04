#pragma once
#define _USE_MATH_DEFINES

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <cmath>
#include "my_arrays.h"
#include "my_sorts.h"

using namespace std;

struct Product
{
	string name;
	unsigned int price;
	int tm_day;
	int tm_mom;
	int tm_year;
};

struct Point
{
	double x;
	double y;
};

struct Sector
{
	Point begin;
	Point end;
};

struct MathVector
{
	double x;
	double y;
	double z;
};

#define DAY_IN_MONTH 31
#define MONTH_IN_YEAR 12

struct Human;
void test();
//void fillStudent(Crypto& student);

void studentHighestScore();

struct CharNode;
struct CharList;
unsigned sizeString(FILE* out, const CharList* str);
void clearString(CharList* str);
void printString(FILE* out, const CharList* str);
void inputStringWithoutRepeatingSpaced(FILE* in, CharList* str);
void inputString(FILE* in, CharList** pStr);
void eraseCharNode(CharList* str, unsigned ind);
void addCharNode(CharList* str, CharNode* node, unsigned ind);
void studentT();
void sumMeters();
void sumOfStruct();
void computeTimeDiffence(struct Time t1, struct Time t2, struct Time* difference);
void countingTime();
void informationOfStudent();
void databaseResident();
void SegmentsTest();
void productsTest();
void mathVectorTest();
double length(const MathVector& vec);