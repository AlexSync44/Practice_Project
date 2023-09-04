#include "Time.h"

void timeTest()
{
	time_t timeOne = time(0);
	cout << "Секунды от 01.01.1970 = " << timeOne << endl;

	struct tm* timeTmStruct = nullptr;
	char dateStr[60] = { 0 };

	const time_t now = time(NULL);
	timeTmStruct = localtime(&now);

	char timeFormat[] = "%d.%m.%Y %H:%M:%S, %A, %W";
	int bytesWrite = strftime(dateStr, sizeof(dateStr), timeFormat, timeTmStruct);

	cout << "\nТекущая дата в формате " << timeFormat << '\n';
	cout << dateStr << "\nlen = " << bytesWrite << " " << strlen(dateStr);
	cout << "\n\n";

	cout << "Обратно в unix time: " << mktime(timeTmStruct) << '\n';
	cout << "Mc с момента запуска программы: " << clock() << '\n';


	switch (timeTmStruct->tm_wday)
	{
	case 0: strcpy(dateStr + bytesWrite, " воскресенье"); break;
	case 1: strcpy(dateStr + bytesWrite, " понедельник"); break;
	case 2: strcpy(dateStr + bytesWrite, " вторник");     break;
	case 3: strcpy(dateStr + bytesWrite, " среда");       break;
	case 4: strcpy(dateStr + bytesWrite, " четверг");     break;
	case 5: strcpy(dateStr + bytesWrite, " пятница");     break;
	case 6: strcpy(dateStr + bytesWrite, " суббота");     break;
	}

	cout << dateStr << "\nlen = " << bytesWrite << " " << strlen(dateStr);

	//Если мы меняем структуру tm, то нужно перевести время в секунды
	// и опять посчитать tm
}

void finalDate()
{
	unsigned sec(0);
	struct tm* timeTmStruct = nullptr;
	char dateStr[60] = { 0 };

	const time_t now = time(NULL);
	timeTmStruct = localtime(&now);

	char timeFormat[] = "%d.%m.%Y %H:%M:%S, %A, %W";
	int bytesWrite = strftime(dateStr, sizeof(dateStr), timeFormat, timeTmStruct);

	cout << "Текущая дата: " << dateStr
	<< "\n\nВведите сколько секунд хотите добавить: ";

	cin >> sec;

	timeTmStruct->tm_sec += sec;
	time_t addedTime = mktime(timeTmStruct);
	timeTmStruct = localtime(&addedTime);

	//bytesWrite = 
	strftime(dateStr, sizeof(dateStr), timeFormat, timeTmStruct);

	cout << "\n\nИтоговая дата: " << dateStr << '\n';
}

void timeDifference()
{
	struct tm timeTmOne {};
	struct tm timeTmTwo {};
	char dateStrOne[60] = { 0 };
	char dateStrTwo[60] = { 0 };

	const time_t now = time(NULL);
	timeTmOne = *localtime(&now);
	timeTmTwo = *localtime(&now);

	char timeFormat[] = "%d.%m.%Y";
	cout << "Введите первое время в формате " << timeFormat << ": ";
	cin >> std::get_time(&timeTmOne, "%d.%m.%Y");
	strftime(dateStrOne, sizeof(dateStrOne), timeFormat, &timeTmOne);
	cout << "Первая дата: " << dateStrOne;

	cout << "\n\n\nВведите второе время в формате " << timeFormat << ": ";
	cin >> std::get_time(&timeTmTwo, "%d.%m.%Y");
	strftime(dateStrTwo, sizeof(dateStrTwo), timeFormat, &timeTmTwo);
	cout << "Вторая дата: " << dateStrTwo;

	cout << "\nРазница " << timeTmTwo.tm_yday - timeTmOne.tm_yday << " дней\n";
	cout << "Разница " << timeTmTwo.tm_mon - timeTmOne.tm_mon << " месяцев\n";
	cout << "Разница " << timeTmTwo.tm_year - timeTmOne.tm_year << " лет\n";
}

void timeManager()
{
	std::vector <std::string> nameTask;
	std::vector <time_t> addedTime;
	std::vector <tm> timeVec;
	time_t startTime = 0, endTime = 0;
	std::string input;
	int countEndTasks = 0;
	bool state = false, isRunning = true;

	while (isRunning)
	{
		system("cls");

		cout << "begin. \tВключить таймер\n"
			<< "status. Узнать о всех законченных задачах\n"
			<< "end. \tЗакончить задачу\n"
			<< "exit. \tЗакрыть программу\n" << '-';
		getline(cin, input);

		for (auto& c : input)
		{
			c = tolower(c);
		}

		if (input == "begin")
		{
			cout << "\nВведите название задачи: ";
			getline(cin, input);
			nameTask.push_back(input);

			if (!state)
			{
				startTime = time(nullptr);
				state = true;
			}
			else
			{
				endTime = time(nullptr);
				double elapsedSeconds = difftime(endTime, startTime);
				addedTime.push_back((time_t)elapsedSeconds);

				countEndTasks++;
				startTime = 0, endTime = 0;
				startTime = time(nullptr);
			}
		}
		else if (input == "status")
		{
			for (int i = 0; i < addedTime.size(); i++)
			{
				char timeStr[9];
				struct tm* timeInfo = gmtime(&addedTime[i]);
				strftime(timeStr, sizeof(timeStr), "%H:%M:%S", timeInfo);
				cout << "Имя и время задачи: " << nameTask[i] << " " << timeStr << endl;
			}
			cin.get();
		}
		else if (input == "end")
		{
			endTime = time(nullptr);
			double elapsedSeconds = difftime(endTime, startTime);
			addedTime.push_back((time_t)elapsedSeconds);

			state = false;
			countEndTasks++;
			startTime = 0, endTime = 0;
		}
		else if (input == "exit")
		{
			isRunning = false;
		}
		else
		{
			cout << "\nВведено неизвестое действие! |Нажмите любую кнопку чтобы продолжить|\n\n";
			cin.get();
		}
	}
}

std::string toMinAndSeconds(int seconds)
{
	int minutes = seconds / 60;
	seconds = seconds % 60;
	std::string result = std::to_string(minutes) + ":";

	if (seconds < 10)
	{
		result += "0";
	}
	result += std::to_string(seconds);

	return result;
}

void timer()
{
	std::time_t now = std::time(nullptr);
	std::tm beginTime = *std::localtime(&now);
	time_t previous = time(0);
	int diff;
	int timer = beginTime.tm_min * 60 + beginTime.tm_sec;

	std::cout << "Введите время таймера MM:SS ";
	std::cin >> std::get_time(&beginTime, "%M:%S");

	cout << " " << toMinAndSeconds(timer) << '\r';
	cout.flush();

	while (timer > 0)
	{
		now = time(0);
		diff = now - previous;
		if (diff >= 1)
		{
			previous = now;
			timer -= diff;
			cout << " " << toMinAndSeconds(timer) << '\r';
			cout.flush();
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	cout << "DING! DING! DING!" << endl;
}

std::vector<std::pair<time_t, std::string>> nextBirthday(const time_t& now, const std::multimap<time_t, std::string>& people)
{
	std::vector<std::pair<time_t, std::string>> todayBirthdays;
	std::pair<time_t, std::string> human;
	int diffDay = INT_MAX, diffMonth = INT_MAX;

	auto nowTm = localtime(&now);
	const int today = nowTm->tm_mday;
	const int todayMonth = nowTm->tm_mon;

	for (auto it = people.begin(); it != people.end(); ++it)
	{
		const auto& dateTime = it->first;
		std::tm* dateTimeTm = localtime(&dateTime);

		int day = dateTimeTm->tm_mday;
		int month = dateTimeTm->tm_mon;

		if (month > todayMonth || (month == todayMonth && day >= today))
		{
			if (month == todayMonth && day == today)
			{
				todayBirthdays.push_back(*it);
				continue;
			}

			int monthDiff = month - todayMonth;
			int dayDiff = day - today;

			if (monthDiff < diffMonth || (monthDiff == diffMonth && dayDiff < diffDay))
			{
				diffMonth = monthDiff;
				diffDay = dayDiff;
				human = *it;
			}
		}
	}

	std::vector<std::pair<time_t, std::string>> res;
	if (!todayBirthdays.empty())
	{
		return todayBirthdays;
	}
	else if (!human.second.empty())
	{
		res.push_back(human);
	}
	return res;
}

void birthdayReminder()
{
	std::string name;
	std::multimap<time_t, std::string> friends;
	bool isRunning = true;

	time_t now = time(nullptr);
	tm birthday = *localtime(&now);

	while (isRunning)
	{
		system("CLS");

		cout << "Введите имя друга и дату рождения гггг.мм.дд\n";
		cout << "end. для выхода\n\n";

		cout << "Введите имя: ";
		getline(cin, name);

		if (name == "end")
		{
			isRunning = false;
			continue;
		}

		cout << "Введите день рождения: ";
		cin >> std::get_time(&birthday, "%Y/%m/%d");

		cout << "Вы ввели: " << std::asctime(&birthday) << endl;
		cin.ignore();

		friends.emplace(mktime(&birthday), name);
	}

	char date[32]{ 0 };
	auto nextBirthdayFriends = nextBirthday(now, friends);

	int size = nextBirthdayFriends.size();

	if (!size)
	{
		cout << "Все дни рождения раньше или не заданы\n";
	}
	else if (size == 1)
	{
		auto nextFriend = nextBirthdayFriends.at(0);

		name = nextFriend.second;
		time_t& timeBirthday = nextFriend.first;
		strftime(date, sizeof(date), "%Y/%m/%d", localtime(&timeBirthday));

		cout << "Ближайший день рождения:\n";
		cout << name << '\t' << date << '\n';
	}
	else
	{
		cout << "День рождения сегодня у:\n";

		for (auto& nextFriend : nextBirthdayFriends)
		{
			name = nextFriend.second;
			time_t& timeBirthday = nextFriend.first;
			strftime(date, sizeof(date), "%Y/%m/%d", localtime(&timeBirthday));

			cout << name << '\t' << date << '\n';

			memset(date, 0, sizeof(date));
		}
	}
}

void travelTime()
{
	struct tm timeTmOne {};
	struct tm timeTmTwo {};
	char dateStrOne[60] = { 0 };
	char dateStrTwo[60] = { 0 };

	const time_t now = time(NULL);
	timeTmOne = *localtime(&now);
	timeTmTwo = *localtime(&now);

	char timeFormat[] = "%d.%m.%Y %H:%M";
	cout << "Введите время отправления в формате " << timeFormat << ": ";
	cin >> std::get_time(&timeTmOne, "%d.%m.%Y %H:%M");
	strftime(dateStrOne, sizeof(dateStrOne), timeFormat, &timeTmOne);
	cout << "Первая дата: " << dateStrOne;

	cin.ignore();

	cout << "\n\n\nВведите время прибытия в формате " << timeFormat << ": ";
	cin >> std::get_time(&timeTmTwo, "%d.%m.%Y %H:%M");
	strftime(dateStrTwo, sizeof(dateStrTwo), timeFormat, &timeTmTwo);
	cout << "Вторая дата: " << dateStrTwo;

	cout << "\nРазница " << timeTmTwo.tm_mday - timeTmOne.tm_mday << " дней\n";
	cout << "Разница " << timeTmTwo.tm_mon - timeTmOne.tm_mon << " месяцев\n";
	cout << "Разница " << timeTmTwo.tm_year - timeTmOne.tm_year << " лет\n";
	cout << "Разница " << timeTmTwo.tm_hour - timeTmOne.tm_hour << " часов\n";
	cout << "Разница " << timeTmTwo.tm_min - timeTmOne.tm_min << " минут\n";
}