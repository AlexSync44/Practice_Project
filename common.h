#pragma once

#include <string>
#include <fstream>
#include <windows.h>

#define ESCAPE 27
#define UP 72
#define DOWN 80
#define ENTER 13
#define EXIT 'q'

const HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

void ConsoleCursorVisible(bool show, short size);
void GoToXY(short x, short y);