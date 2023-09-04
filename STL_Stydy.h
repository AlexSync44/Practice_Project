#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <fstream>
#include <regex>
#include <sstream>
#include <conio.h>
#include <set>
#include <deque>

using std::cout;
using std::endl;
using std::cin;

void stdMapTest();
void telephoneDirectory();
void registry();
void anargammTest();
void checkingRequests();
void checkingRequests_Map();
void countingWords();
void NumberBefore();
void commonLetters();
void fileSystemRegExp();
void deleteNuminVec();
void shopBuyVec();
void clearCache();


template <typename K, typename V>
std::vector<K> findKeys(const std::map<K, V> map, const V& value)
{
	std::vector<K> keys;

	for (auto it = map.begin(); it != map.end(); ++it)
	{
		if (it->second == value)
		{
			keys.push_back(it->first);
		}
	}
	return keys;
}