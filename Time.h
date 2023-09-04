#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <regex>
#include <vector>
#include <chrono>
#include <thread>
#include <map>

using std::cout;
using std::cin;
using std::endl;

void finalDate();
void timeDifference();
void timeManager();
void birthdayReminder();
void timer();
void travelTime();


//time_t now = time(NULL);

//char* dn = ctime(&now);

//cout << "Дата сейчас: " << dn;