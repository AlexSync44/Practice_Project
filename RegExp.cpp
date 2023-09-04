#include "RegExp.h"
#include <cstdlib>
#include <fstream>

void regExpCaptyreTest()
{
	std::string s{ R"(
tхb:username!username@username.tcc.domain.com Connected
tхb:username!username@username.tcc.domain.com WEBMSG #Username1 :this is a message 
tхb:username!username@username.tcc.domain.com Status: visible WEBMSG #Username2 :this is a message2
)" };

	std::regex rgx("WEBMSG #([a-zA-Z0-9]+) :(.*)");
	std::smatch matches;

	int j = 1;
	while (bool res = std::regex_search(s, matches, rgx))
	{
		if (res)
		{
			std::cout << "Match #" << j++ << " found\n";

			for (size_t i = 0; i < matches.size(); ++i) {
				std::cout << i << ": '" << matches[i].str() << "'\n";
			}
		}
		else {
			std::cout << "Match not found\n";
		}


		int ind = s.find(matches[0].str());
		if (ind >= 0)
		{
			s.erase(0, ind + matches[0].str().size());
			//std::cout << "\n" << str << std::endl;

		}
	}
}

void findDateExp()
{
	std::regex exp("\\s*\\d{4}/\\d{2}/\\d{2} *\\d{4}:\\d{2}(:\\d{2}?\\)s*");
	string date;

	cout << "Введите дату в форме YYYY/MM/DD HH:MM(:SS)\n";
	getline(cin, date);

	if (std::regex_match(date, exp))
	{
		cout << "Дата в верном формате!\n";
	}
	else
	{
		cout << "Дата введена неверно!\n";
	}
}

void findHexColor()
{
	std::regex exp("(#[0-9A-Fa-f]{6}) (color)");
	std::smatch match;
	std::string color;

	cout << "Введите строку с HTML цветом: ";
	getline(cin, color);

	if (std::regex_search(color, match, exp))
	{
		cout << "Такой цвет есть\n";
	}
	else
	{
		cout << "Такого цвета нет\n";
	}

	while (std::regex_search(color, match, exp))
	{
		for (size_t i = 0; i < match.size(); i++)
		{
			cout << "match #" << i << ' ' << match[i].str() << '\n';
		}

		// удаляет ind от 0 до конца
		int ind = color.find(match[0].str());
		if (ind >= 0)
		{
			color.erase(0, ind + match[0].str().size());
		}
	}
}

void regexInStringTest()
{
	std::regex exp("\\b[A-Z]\\w+\\b");
	std::smatch match;
	string str, buf;

	getline(cin, str);

	buf = str;

	while (std::regex_search(buf, match, exp))
	{
		for (size_t i = 0; i < match.size(); i++)
		{
			cout << "match #" << i << ' ' << match[i].str() << '\n';
		}
		int indInStr = str.find(match[0].str());

		if (indInStr >= 0)
		{
			string upperStr = match[0].str();

			for (char& c : upperStr)
			{
				c = std::toupper(c);
			}
			//std::regex_replace(buf, regExp, upperStr);

			// замена mail с indInStr размер(size) символов на upperStr
			str.replace(indInStr, upperStr.size(), upperStr);
		}
		// удаляем от 0 до конца совпадения ind + match[0].str()
		int ind = buf.find(match[0].str());
		if (ind >= 0)
		{
			buf.erase(0, ind + match[0].str().size());
		}
	}

	cout << str << '\n';
}

void replaceToUpperCaseInFile()
{
	std::regex exp("\\b[A-Z]\\w*\\b");
	std::smatch match;
	string str, buf;

	string fileName, outFileName;

	cout << "Введите название файла: ";

	getline(cin, fileName);
	std::ifstream file(fileName, std::ios::in);
	outFileName = fileName + "UpperCase.txt";
	std::ofstream file2(outFileName, std::ios::out);

	if (!file.is_open())
	{
		cout << "Не удалось открыть файл " << fileName << '\n';
		return;
	}

	if (!file2.is_open())
	{
		cout << "Файл для изменения не открыт!";
		return;
	}

	while (!file.eof())
	{
		std::getline(file, str);

		buf = str;

		while (std::regex_search(buf, match, exp))
		{
			//for (size_t i = 0; i < match.size(); i++)
			//{
			//	cout << "match #" << i << ' ' << match[i].mail() << '\n';
			//}
			int indInStr = str.find(match[0].str());

			if (indInStr >= 0)
			{
				string upperStr = match[0].str();

				for (char& c : upperStr)
				{
					c = std::toupper(c);
				}
				//std::regex_replace(buf, regExp, upperStr);

				// замена mail с indInStr размер(size) символов на upperStr
				str.replace(indInStr, upperStr.size(), upperStr);
			}
			// удаляет ind от 0 до конца
			int ind = buf.find(match[0].str());
			if (ind >= 0)
			{
				buf.erase(0, ind + match[0].str().size());
			}
		}
		file2 << str << std::endl;
	}

	file.close();
	file2.close();
}

bool IPIsValid(const string& mail)
{
	std::regex regExp("\\s*((2[0-5]{2}|1[0-9]{2}|[0-9]{1,2})\\.){3}(2[0-5]{2}|1[0-9]{2}|[0-9]{1,2})\\s*");

	return std::regex_match(mail, regExp);
}

void checkingIP()
{
	string IP;
	bool valid;

	cout << "Введите Ip4:\n";
	getline(cin, IP);

	IPIsValid(IP) ?
		cout << "IP действительный" << std::endl :
		cout << "IP недействительный" << std::endl;
}

const char* VALID_IPS[]
{
	"127.0.0.1",
	"255.255.255.255",
	"1.2.3.4",
	"55.77.213.101"
};
#define VALID_IPS_SIZE (sizeof(VALID_IPS) / sizeof(VALID_IPS[0]))

const char* NOT_VALID_IPS[]
{
	"255.256.257.258",
	"0.55.33.22.",
	"10.00.000.0",
	"23.055.255.033",
	"65.123..9",
	"a.b.c.d"
};
#define NOT_VALID_IPS_SIZE (sizeof(NOT_VALID_IPS) / sizeof(NOT_VALID_IPS[0]))

void checkingIPTest()
{
	string IP;
	bool valid;

	for (size_t i = 0; i < VALID_IPS_SIZE; i++)
	{
		valid = IPIsValid(VALID_IPS[i]);


		cout.setf(std::ios::left);
		cout.width(15);

		cout << "ip = " << VALID_IPS[i] << "\t\tvalid? " <<
			std::boolalpha << valid << std::endl;
	}
	cout << std::endl;

	for (size_t i = 0; i < NOT_VALID_IPS_SIZE; i++)
	{
		valid = IPIsValid(NOT_VALID_IPS[i]);


		cout.setf(std::ios::left);
		cout.width(15);

		cout << "ip = " << NOT_VALID_IPS[i] << "\t\tvalid? " <<
			std::boolalpha << valid << std::endl;
	}
	cout << std::endl;
}

bool mailisvalid(string str)
{
	int ind = str.find("@");

	if (ind == std::string::npos || ind == 0 || ind == str.size() - 1)
	{
		return false;
	}

	std::string first, second;
	first = str.substr(0, ind);
	second = str.substr(ind + 1, str.size() - ind - 1);

	if (first.size() < 1 || first.size() > 64)
	{
		return false;
	}

	if (second.size() < 1 || second.size() > 63)
	{
		return false;
	}

	std::regex expValidPoint("^\\.|\\.\\.|\\.$");

	if (std::regex_search(str, expValidPoint))
	{
		return false;
	}

	//поиск всего кроме(^) указ.
	std::regex secondValid("[^a-zA-Z0-9\-\.]");
	std::regex firstValid("[^a-zA-Z0-9\-\.!#$%&`=~/\?\^\{\}\|\*\+]");

	if (std::regex_search(first, firstValid))
	{
		return false;
	}

	if (std::regex_search(second, secondValid))
	{
		return false;
	}

	return true;
}

const char* VALID_MAILS[] =
{ "simple@example.com",
"very@.com",
"mon@example.com",
"disposable.style.email.with+symbol@example.com",
"other.email-with-hyphen@example.com",
"fully-qualified-domain@example.com",
"user.name+tag+sorting@example.com",
"x@example.com",
"example-indeed@strange-example.com",
"admin@mailserver1",
"example@s.example",
"mailhost!username@example.org",
"user@example.com",
"x@example.org" };
#define VALID_MAILS_SIZE (sizeof(VALID_MAILS) / sizeof(VALID_MAILS[0]))

const char* INVALID_MAILS[] = {
"John..Doe@example.com",
"Abc.example.com",
"A@b@c@example.com",
"a\"b(c)d,e:f g<h>i[j\k]l@example.com",
"1234567890123456789012345678901234567890123456789012345678901234+x@example.com",
"i_like_underscore@but_its_not_allow_in _this_part.example.com" };
#define INVALID_MAILS_SIZE (sizeof(INVALID_MAILS) / sizeof(INVALID_MAILS[0]))

void checkingmail()
{
	string mail;

	bool valid;

	getline(cin, mail);

	mailisvalid(mail) ? cout << "mail действительный" << std::endl
		: cout << "mail недействительный" << std::endl;
}

void checkingMailTest()
{
	bool valid;

	cout << "Valid email" << std::endl;
	for (size_t i = 0; i < VALID_MAILS_SIZE; i++)
	{
		valid = mailisvalid(VALID_MAILS[i]);


		cout.setf(std::ios::left);
		cout.width(15);

		cout << "ip = " << VALID_MAILS[i] << "\t\tvalid? " <<
			std::boolalpha << valid << std::endl;
	}
	cout << std::endl;

	cout << "No valid email" << std::endl;
	for (size_t i = 0; i < INVALID_MAILS_SIZE; i++)
	{
		valid = mailisvalid(INVALID_MAILS[i]);


		cout.setf(std::ios::left);
		cout.width(15);

		cout << "ip = " << INVALID_MAILS[i] << "\t\tvalid? " <<
			std::boolalpha << valid << std::endl;
	}
	cout << std::endl;
}

string makeItalics(const std::string& str)
{
	int count = std::count(str.begin(), str.end(), '*');

	if (count % 2 != 0)
	{
		return "";
	}

	std::regex rx("(\\*[^*]|\\*$)");
	//std::regex regExp("\\*.*?\\*");
	std::string fmt("<em>");
	std::string fmd("</em>");
	std::string newStr = str;

	std::regex_constants::match_flag_type fonly =
		std::regex_constants::format_first_only;

	int i(0);
	while (std::regex_search(newStr, rx))
	{
		if (i % 2 == 0)
		{
			newStr = std::regex_replace(newStr, rx, fmt, fonly);
		}
		else
		{
			newStr = std::regex_replace(newStr, rx, fmd, fonly);
		}
		i++;
	}
	return newStr;
}

void italicsTest()
{
	std::string str("*this is italic* *axayaz*");

	cout << makeItalics(str);
}

void italicsTestInFile()
{
	string str;
	std::string nameFile;

	cout << "Введите имя файла: ";
	getline(cin, nameFile);

	std::ifstream file(nameFile);

	if (!file.is_open())
	{
		cout << "Ошибка чтения файла!\n";
		return;
	}

	while (!file.eof())
	{
		getline(file, str);
		cout << makeItalics(str);
	}

	file.close();
}

// tack reg regExp
void regRepeatWords()
{
	//std::string str("Most sake tried unpacked admiration distrusts pleased"
	//	" pleased pleased pleased direction behind favourite families merits."
	//	" Because kept kept kept kept living they perpetual itself opinion brought"
	//	" precaution improved highly morning hope seems. Forming shyness unwilling");

	std::string str = "this is is a test test west";

	string bufStr = str;
	string left(" <strong> ");
	string right(" </strong> ");
	std::regex regExp("(\\b\\w+\\b)\\s+\\1");
	std::smatch match;

	std::regex_constants::match_flag_type fonly =
		std::regex_constants::format_first_only;

	cout << "str = " << str << endl;

	while (std::regex_search(bufStr, match, regExp))
	{
		auto firstWord = match[1].str();
		auto replaceWord = match[0].str();

		replaceWord.insert(firstWord.size(), left);
		replaceWord.append(right);

		bufStr = std::regex_replace(bufStr, regExp, replaceWord, fonly);

		cout << endl;
		cout << "replace to : " << replaceWord << endl;
		cout << "new str = " << bufStr << endl;
	}
}

// tack 3.1 reh regExp
void endingWods_Z_Ind_I()
{
	std::regex regExp("(\\b[A-Z]\\w*(z|я)\\b)");
	string word, buf;
	unsigned count(0);

	string fileName;

	cout << "Введите название файла: ";

	std::getline(cin, fileName);
	std::ifstream file(fileName, std::ios::in);

	if (!file.is_open())
	{
		cout << "Не удалось открыть файл " << fileName << '\n';
		return;
	}

	while (!file.eof())
	{
		file >> word;

		if (std::regex_match(word, regExp))
		{
			cout << word << endl;
			count++;
		}

	}

	cout << "Количество равно = " << count << endl;

	file.close();
}

// tack 3.2 reg regExp
const char* VALID_IP[]
{
	"127.0.0.1",
	"55.77.213.101",
	"255.255.255.255",
	"0.0.0.0",
	"1.2.3.4",
	"70.175.125.254",
	"145.7.15.2",
	"155.219.9.125",
	"21.129.215.96",
	"232.184.10.121",
	"37.236.245.146",
	"191.202.179.103",
	"83.18.83.30",
	"195.10.5.60",
	"182.244.197.230",
	"40.114.56.254",
	"213.65.139.212",
	"13.89.175.175",
	"0.27.181.117",
	"10.21.198.181"
};
#define VALID_IPS_SIZE (sizeof(VALID_IP) / sizeof(VALID_IP[0]))

std::vector<string> split(const string& str, char delim)
{
	auto i = 0;
	std::vector<string> list;

	auto pos = str.find(delim);

	while (pos != string::npos)
	{
		list.push_back(str.substr(i, pos - i));
		i = ++pos;
		pos = str.find(delim, pos);
	}

	list.push_back(str.substr(i, str.length()));

	return list;
}

void sortIPAddress()
{
	string word;

	std::string   fileName("filesTest./ip.txt");
	std::ifstream file(fileName, std::ios::in);

	if (!file.is_open())
	{
		cout << "Не удалось открыть файл " << fileName << '\n';
		return;
	}

	std::vector<string> IPVector;

	while (!file.eof())
	{
		file >> word;

		if (IPIsValid(word))
		{
			IPVector.push_back(word);
		}
	}

	if (IPVector.empty())
	{
		cout << "В файле " << fileName << " нет корретных ip\n";
		file.close();

		return;
	}

	std::sort(IPVector.begin(), IPVector.end());

	cout << "Отсортированные ip адреса из файла " << fileName << endl;
	for (const auto& ip : IPVector)
	{
		cout << ip << '\n';
	}

	file.close();
}

//task 1
void timeWay(long first, long second, bool nextDay)
{
	int res(0);

	if (nextDay)
	{
		res = first - second;
		cout << "\nПоезд приедет на следующий день!\n";
	}
	else
	{
		res = second - first;
	}

	int h = res / 3600 % 24;
	int m = res % 3600 / 60;
	int s = res % 3600 % 60;

	cout << "время пути состовляет: " << h << ":" << m / 10 << m % 10 << ":"
		<< s / 10 << s % 10;
}

void travelTimeTest()
{
	int hour(0), hour2(0), min1(0), min2(0), sec(0), sec2(0),
		timefirst(0), timeSecond(0);
	bool nextDay;

	cout << "Введите время отправления (00.00.00): ";
	while (!(cin >> hour >> min1 >> sec))
	{
		cin.clear();
		cin.ignore();
		cout << "Введите коректное время!";
	}

	cout << "Введите время прибытия (00.00.00): ";
	while (!(cin >> hour2 >> min2 >> sec2))
	{
		cin.clear();
		cin.ignore();
		cout << "Введите коректное время!";
	}

	hour2 < hour ? nextDay = true : nextDay = false;

	while (hour > 0)
	{
		timefirst += 3600;
		--hour;
	}
	while (min1 > 0)
	{
		timefirst += 60;
		--min1;
	}
	timefirst += sec;

	while (hour2 > 0)
	{
		timeSecond += 3600;
		hour2--;
	}
	while (min2 > 0)
	{
		timeSecond += 60;
		min2--;
	}
	timeSecond += sec2;

	timeWay(timefirst, timeSecond, nextDay);
}

const char* VALID_REAL_NUMBER[]
{
	"0123",
	"00.000",
	".15",
	"165.",
	"999999999999999999999999999999999.999999999999999999999999999999"
};
#define VALID_REAL_NUMBER_SIZES (sizeof(VALID_REAL_NUMBER) / sizeof(VALID_REAL_NUMBER[0]))

const char* INVALID_REAL_NUMBER[]
{
	"1.2.3",
	"-.",
	"11e-3",
	"+25"
};
#define INVALID_REAL_NUMBER_SIZES (sizeof(INVALID_REAL_NUMBER) / sizeof(INVALID_REAL_NUMBER[0]))

//task 2
bool isRealNumberValid(const string str)
{
	std::regex regExp("\\b-?\\d*\\.?\\d+\\b");

	if (std::regex_search(str, regExp))
	{
		return false;
	}

	//std::regex presenceDigit("\\d");

	//if (std::regex_search(str, presenceDigit))
	//{
	//	return false;
	//}

	return true;
}

void checkingRealNumberTest()
{
	bool valid;

	cout << "Valid IP" << std::endl;
	for (size_t i = 0; i < VALID_REAL_NUMBER_SIZES; i++)
	{
		valid = mailisvalid(VALID_REAL_NUMBER[i]);


		cout.setf(std::ios::left);
		cout.width(15);

		cout << "ip = " << VALID_REAL_NUMBER[i] << "\t\tvalid? " <<
			std::boolalpha << valid << std::endl;
	}
	cout << std::endl;

	cout << "No valid IP" << std::endl;
	for (size_t i = 0; i < INVALID_REAL_NUMBER_SIZES; i++)
	{
		valid = mailisvalid(INVALID_REAL_NUMBER[i]);


		cout.setf(std::ios::left);
		cout.width(15);

		cout << "ip = " << INVALID_REAL_NUMBER[i] << "\t\tvalid? " <<
			std::boolalpha << valid << std::endl;
	}
	cout << std::endl;
}

void RealNumberTest()
{
	std::string str;

	cout << "Введите вещественное число: ";
	std::getline(cin, str);

	isRealNumberValid(str) ? cout << "Yes" : cout << "No";
}

//task 3
void numberOfWords()
{
	std::regex regExp("([^\\s]+)");
	std::string str;

	cout << "Введите строчку: ";
	std::getline(cin, str);

	std::sregex_iterator first(str.begin(), str.end(), regExp);
	std::sregex_iterator last;

	cout << "Кол-во слов: " << std::distance(first, last) << '\n';
}

//task 4
void gameBullsAndCows()
{
	char playerOne[4]{};
	char playerTwo[4]{};
	auto bulls(0), cows(0);

	cout << "Загадайте 4 цифры: ";
	cin >> playerOne;
	system("cls");

	// для будущих проверок коров
	unsigned short numOne = playerOne[0],
		numTwo = playerOne[1],
		numTree = playerOne[2],
		numFour = playerOne[3];

	while (strcmp(playerTwo, "q"))
	{
		cout << "Отгадайте 4 цифры: ";
		cin >> playerTwo;

		if (!strcmp(playerTwo, "q"))
		{
			break;
		}

		for (size_t i = 0; i < 4; i++)
		{
			if (playerTwo[i] == playerOne[i])
			{
				bulls++;
			}
			else if (playerTwo[i] == numOne || playerTwo[i] == numTwo ||
				playerTwo[i] == numTree || playerTwo[i] == numFour)
			{
				cows++;
			}
		}
		if (bulls == 4)
		{
			cout << "Игрок №2 победил!" << '\n';
			break;
		}
		else
		{
			cout << "Быков (цифры на своём месте): " << bulls << "\nКоров (цифр не на своём месте ): " << cows << '\n';
			bulls = NULL;
			cows = NULL;
		}
	}
	system("cls");
	const HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hStdOut, { 67, 18 });
	SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN
		| FOREGROUND_INTENSITY);


	cout << "GAME OVER";
	_getch();
}

//task regexp №1
void integes()
{
	std::regex regExp("\\d+");
	std::smatch match;
	std::string str = "-18 4 83 744 -90 344";
	
	while (std::regex_search(str, match, regExp))
	{
		for (size_t i = 0; i < match.size(); i++)
		{
			cout << "match #" << i << ' ' << match[i].str() << '\n';
		}

		// удаляет ind от 0 до конца
		int ind = str.find(match[0].str());
		if (ind >= 0)
		{
			str.erase(0, ind + match[0].str().size());
		}
	}
}

// дополнительная функция для вставки
string insertStrings(string str1, string str2, int ind)
{
	return str1.insert(ind, str2);
}

// task regex №2 with file HTML(.txt)
void tagReplace()
{
	std::regex regExp("(?<=<body.*?>)");
	std::smatch match;
	std::string fileName, str, bufStr;
	std::string rep = "<h1>Hello</h1>";

	cout << "Введите имя файла: ";
	getline(cin, fileName);
	std::fstream file(fileName, std::ios::in | std::ios::ate);

	if (!(file.is_open())) return;

	while (file.eof())
	{
		getline(file, str);
	}

	if (std::regex_search(str, match, regExp))
	{
		int indInStr = str.find(match[0].str());
		bufStr = str;

		str = insertStrings(bufStr, rep, indInStr);

		file << str;
	}
	else
	{
		cout << "В тексте нет слова <body...>";
	}

	file.close();
}

//task regex №2
void tagReplacement()
{
	std::regex regExp("\\<body\\>");
	std::string rep = "<h1>Hello</h1>";
	std::string str;

	getline(cin, str);

	std::string newStr = str;

	std::regex_constants::match_flag_type fonly =
		std::regex_constants::format_first_only;

	newStr = std::regex_replace(newStr, regExp, rep, fonly);

	cout << newStr;
}

//task regexp №3
void domainVerification()
{
	std::regex regExp("http(s)?:\\/{2}\\w+\\.((com)?(ru)?(gg)?(io)?(su)?(ua)?(me)?)(\\/)?");
	std::string str;

	getline(cin, str);

	std::regex_search(str, regExp) ?
		cout << "Данный домен действительный!" :
		cout << "Данный домен НЕ действительный!";
}

// task regex №5 corrected version
std::vector<std::string> regex_split(const std::string& str, const std::regex& reg) {
	const std::sregex_token_iterator beg{ str.cbegin(), str.cend(), reg, -1 };
	const std::sregex_token_iterator end{};

	return { beg, end };
}

void testTokenStr()
{
	const std::string str{ "один два,три, четыре,  пять--шесть ,семь, ,восемь-девять" };
	std::regex reg("()");

	std::sregex_token_iterator iter(str.begin(), str.end(), reg, -1);
	std::sregex_token_iterator end;

	std::vector<string> tokens(iter, end);

	for (const string& s : tokens) {
		cout << s << endl;
	}
}

//task regexp №4
void repWords()
{
	std::string str;
	std::string str2;
	std::string strBuf;

	const char rep('*');

	cout << "Введите 1 строчку: ";
	getline(cin, str);
	cout << "Введите 2 строчку: ";
	getline(cin, str2);

	if (str == str2)
	{
		strBuf = str;

		for (size_t i = 0; i < 2; i++)
		{
			strBuf.insert(strBuf.begin(), rep);
			strBuf.insert(strBuf.end(), rep);
		}

		cout << "\nНовая строка: " << strBuf << endl;
	}
	else
	{
		cout << "Строки разные!";
	}
		
}

//task regexp №5
void tokenInStr()
{
	std::string str;
	const char del = ',';
	unsigned short count(0);

	cout << "Введите строчку: ";
	getline(cin, str);

	std::vector<std::string> vecStr;
	std::stringstream strStream(str);

	std::string bufStr;
	while (std::getline(strStream, bufStr, del))
	{
		vecStr.push_back(str);
	}

	for (auto& str : vecStr)
	{
		count++;
	}

	cout << count;
}

void parsedExpression()
{
	constexpr auto regex_str = R"( )";
	std::cmatch match;
	std::string str;
	const std::regex reg{regex_str };

	getline(cin, str);

	const auto tokens = regex_split(str, reg);

	for (auto&& token : tokens)
	{
		cout << token << '\n';
	}
}

void searchNumberInFile()
{
	std::regex regExp("\\d{4}");
	std::string str, fileName;
	std::smatch match;

	cout << "Введите имя файла: ";
	getline(cin, fileName);
	std::fstream file(fileName, std::ios::in);

	if (!checkopenfile(file)) return;

	int maxNum(0);
	while (!file.eof())
	{
		std::getline(file, str);

		if (std::regex_search(str, match, regExp))
		{
			cout << str << endl;

			while (std::regex_search(str, match, regExp))
			{
				int num = std::atoi(match[0].str().c_str());
				if (num > maxNum)
				{
					maxNum = num;
				}

				// удаляет ind от 0 до конца
				int ind = str.find(match[0].str());
				if (ind >= 0)
				{
					str.erase(0, ind + match[0].str().size());
				}
			}
		}
	}

	cout << "\nСамое большое число: " << maxNum << endl;

	file.close();
}
