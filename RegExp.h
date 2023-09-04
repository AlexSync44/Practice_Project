#pragma once

#include <iostream>
#include <regex>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include "my_sorts.h"
#include "my_files.h"

using std::cin;
using std::cout;
using std::string;

template <typename T>
auto extractNumbers(const std::vector<std::string>& v)
{
    std::vector<std::vector<T>> extracted;
    extracted.reserve(v.size());

    for (auto& s : v)
    {
        std::stringstream ss(s);
        std::istream_iterator<T> begin(ss), end; // итератор конца потока по умолчанию

        extracted.emplace_back(begin, end);
    }

    // это также проверяет следующий доступ к извлеченному[0]
    if (extracted.empty())
    {
        return extracted;
    }

    decltype(extracted) transposed(extracted[0].size());
    for (std::size_t i = 0; i < transposed.size(); ++i) {
        for (std::size_t j = 0; j < extracted.size(); ++j) {
            transposed.at(i).push_back(std::move(extracted.at(j).at(i)));
        }
    }

    return transposed;
}

void regExpCaptyreTest();
void findDateExp();
void findHexColor();
void regexInStringTest();
void replaceToUpperCaseInFile();
void checkingIP();
void checkingIPTest();
void checkingmail();
void checkingMailTest();
void italicsTest();
void disemvowelTest();
void regRepeatWords();
void endingWods_Z_Ind_I();
void italicsTestInFile();
void sortIPAddress();
void RealNumberTest();
void numberOfWords();
void travelTimeTest();
void checkingRealNumberTest();
void integes();
void gameBullsAndCows();
void tagReplacement();
void domainVerification();
void tokenInStr();
void repWords();
void tagReplace();
void testTokenStr();
void parsedExpression();
void searchNumberInFile();