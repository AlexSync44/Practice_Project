#include "stringStudy.h"

void stdStringTest()
{
	//���� ������ �������� �� ����
	//�� ���� ��������� ��������
	const char* str = "My name is";

	std::string strOne, strTwo;

	cout << "������� ������: ";

	std::getline(cin, strOne);
	cout << strOne << "\n";

	//�����������
	strTwo = strOne;

	int len = strOne.length();

	cout << "����� = " << len << '\n';
	cout << "���������� ������: " << strOne.substr(len / 2) << '\n';

	//����������� ������
	strTwo = strTwo + strOne;

	cout << "��������� ������: ";
	cout << strTwo << '\n';


	//��������� �����
	if (strOne.compare(strTwo))
	{
		cout << "������ �� �����\n";
	}

	if (strOne == strTwo)
	{
		cout << "������  �����\n";
	}

	//new �� ���� ������������
	//std::string ���� �������� ���� ������
	//��! ����� ��� ��� �������, ���� �� ������� ����� ���������
	//����� std::string ����� ������������, ������� ������

	strTwo.clear();
	strTwo.reserve(256);

	cout << "������ ��������: " << strTwo.capacity() << " ����\n";

	//����������
	strTwo = "The quick brown fox jumps over the lazy dog";
	std::sort(strTwo.begin(), strTwo.end());
	cout << "\n��������������� ������: " << strTwo << '\n';

	//�������� ������ � �����
	strTwo.push_back('@');
	strTwo.append(" str ind the end!");
	strTwo.insert(len / 2, " subbbstr! ");

	//��������� ������ �� ������ ����������� �������
	char cStr[64] = "The quick brown fox jumps over the lazy dog2";
	strTwo.assign(cStr);
	cout << "\n��������������� ������: " << strTwo << '\n';

	//���������� � �������
	strTwo.at(0);
	//���� ����� ��������
	//strTwo[0] = 'A';

	//���������� ������ ���� ������� ��������
	int ind = strTwo.find("quick");

	//�������� ��� �� �������
	if (strTwo.find("quick") == std::string::npos)
	{
		cout << "���c����� �� �������\n";
	}

	//������ ������
	if (strTwo.empty())
	{
		cout << "������ ������\n";
	}
	else cout << "������ �� ������\n";

	//�������� ����� ������
	//� ������ ������� � ������� ����
	strTwo.erase(2, 5);

	//����� ����������� ��������� � ������
	//���� �� �����
	regex regExp("[^a-zA-Z ]");

	if (regex_search(strTwo, regExp))
	{
		cout << "����������� ������������ �������\n";
	}
}

void stringCTest()
{
	//������ ��� ����������� ������
	const int size = 1024;
	const int size2 = size / 2;
	char str1[size] = "Hello world!";
	char str2[size2] = { 'H', 'e', 'l', 'l', 'o', '\0' };

	printf("������� ������\n");
	//���������� � �������
	//������� ����� �� ����������� �������
	//scanf_s("%s", buf, size);
	//cin >> 
	gets_s(str1, size);
	//cin.getline(str1,bif size);

	//������ �������
	//char c = cin.get();

	printf("%s\n", str1);
	//cout << str1 << '\n';

	int len = strlen(str1);
	printf("����� ������ = %d\n", len);

	//������ ����������� �����
	//1
	memset(str2, 0, size2);
	memcpy(str2, str1, len * sizeof(char) + 1);
	printf("������������� ������: %s\n", str2);

	//2
	//����������� � �������
	printf("������� ������\n");
	gets_s(str1);
	memset(str2, 0, size2);
	snprintf(str2, size2, "������������� ������: %s\n", str1);
	printf("%s\n", str2);

	//����������� ������
	strncat_s(str1, str2, strlen(str2));
	printf("����� �����: %s\n", str1);

	// ��������� �� ���������
	//gets_s(str1);

	//strstr - ����� ��������� �� ����� � ������

	//char* pBuf = str1;
	//int subLen = strlen(strstr(pBuf, "1"));
	//while (subLen != 0)
	//{
	//	subLen = strlen(strstr(pBuf, "1"));
	//	pBuf += subLen;
	//	printf("%s\n", pBuf);
	//}

	//���������

	if (!strcmp("dd", "dd"))
	{
		printf("������ �����\n");
	}
}

void sstreamTest()
{
	/*
	����� ����������:
		1) ��������� ������ �� �����

		2) ������� ������ � ������ ���� ������ � ��������
		�� ���� ������ ���������� �� ����� � ������ �
		�� ������ � �����.

		stdout, stdin - ���������� ������
		ifstream, ofstream - �������� ������
		sstream - ��������� �����

	*/
	string text = "The quick brown fox jumps over the lazy dog";

	std::stringstream strm(text);

	cout << "������ � ������: " << text << endl;

	int count = 0;
	string word;

	while (!strm.eof())
	{
		strm >> word;
		count++;
	}

	cout << "� ������ " << count << " ����\n";

	string numbers = "1 2 3.14 09 1 ";
	strm.clear();
	strm.seekg(0);

	strm << numbers;
	//����� ������ �������
	strm << 101 << " " << 220;

	double num = 0, sum = 0;

	while (strm >> num)
	{

		sum += num;
		cout << num << " ";

	}

	cout << endl << "����� ����� = " << sum << endl;
}