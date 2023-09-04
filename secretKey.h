#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <ctime>
#include <fstream>
#include <string>
#include <chrono>
#include <iomanip>
#include <conio.h>
#include "my_arrays.h"
#include "my_files.h"
#include "common.h"

#define LONG_TIME_FORMAT "%d.%m.%Y %H:%M:%S"
#define SECRET_KEY_FILE "C:\\Users\\Public\\keys\\secretKey.bin"

void calcKeys(const char* fileName, int*& keys, int& size);
void encrypt(std::vector<unsigned char>& data, int const* const keys, int size);
void decrypt(std::vector<unsigned char>& data, int const* const keys, int size);
void createCodeNotepad();
void encryptMenu();
void decryptMenu();
void secretKeyTest();

struct SecretKey
{
	time_t creationDate{ 0 };
	time_t expiryDate{ 0 };
	char creatorName[64]{ 0 };
	char description[64]{ 0 };
	char keySetName[20]{ 0 };
	char secretKey[32]{ 0 };
};