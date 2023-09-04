#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct Statement
{
	string name;
	unsigned int money;
	int tm_day;
	int tm_mom;
	int tm_year;
};

struct myifstream
{
	myifstream(const std::string& name, std::ios::openmode flags = std::ios::in) :
		stream(name, flags), name(name), mode(flags)
	{
	}
	std::string name;
	std::ifstream stream;
	std::ios::openmode mode;
};

bool checkopenfile(const fstream& file);
void fWork();
int writeToFile(fstream& ofile);
char rndLetterGenerate_();
std::string rndStringGenerate(unsigned size);
void printFile(fstream& ofile);
int countingWords(fstream& ofile, const string word);
void callCountingWords();
int countingWords(const char* ofile);
void callPrintFile();
void statementTest();
void PNGTest();
void filePNGTest();
void fileMerge();
void task_1();
void task_2();
void task_3();
void task_4();