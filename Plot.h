#pragma once
#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>

using std::cout;
using std::cin;
using std::string;
using std::endl;

struct Region
{
	unsigned number;
	int house;
	unsigned garage;
	unsigned barl;
	unsigned bathhouse;
	unsigned areaHouse;
	unsigned areaGarage;
	unsigned AreaBarl;
	unsigned AreaBathhouse;
	unsigned AreaAllRegion;
};

struct House
{
	string nameRooms;
	unsigned floors;
	unsigned rooms;
	int bake;
};

void plotTest();
void printNameRooms(House* house, unsigned size);