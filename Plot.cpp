#include "Plot.h"

const int SizeRoomsName(5); 
const char* Test_Rooms_Names[5]
{
	"�����",
	"��������",
	"������",
	"�������",
	"�������"
};

// ������ � �������
void clearMemory(Region*& region)
{
	if (region)
	{
		delete[] region;
		region = nullptr;
	}
}

void allocateMemory(Region*& region, unsigned size)
{
	clearMemory(region);

	region = new Region[size];
}

// ����� ���������� �������
void printRegion(const Region& region)
{
	cout << "����� �������\t" << "���-�� ����� �����\t"
		<< "�������������� ���������\t" << "����� ������ �������\n";
	cout << '#' << region.number << "\t\t\t" << region.house << "\t\t"
		<< "�������: " << region.garage << ' '
		<< "������: " << region.barl << ' '
		<< "����: " << region.bathhouse << '\t'
		<< region.AreaAllRegion << "�^2" << "\n\n";
}

void printRegions(const Region* region, unsigned size)
{
	if (!region || !size)
	{
		return;
	}

	for (size_t i = 0; i < size; i++)
	{
		cout << "� ����� ������� � ����: " << i << '\n';
		printRegion(region[i]);
	}
	cout << "\n\n";
}

void printRegion(Region* reg, unsigned size)
{
	if (!reg)
	{
		cout << "� ���� ��� ��������!";
		return;
	}

	int num;
	cout << "������� ����� ������� �� ����: ";
	while (!(cin >> num))
	{
		cin.clear();
		cin.ignore();
		cout << "������� ����� ������� �� ����";
	}
	printRegion(reg[num]);
}

// ����
void inputRegion(Region& region)
{
	cout << "������� ����� �������: ";
	cin >> region.number;

	cout << "������� ���-�� ����� �����: ";
	cin >> region.house;

	cout << "������� ��� - �� �������: ";
	cin >> region.garage;

	cout << "������ ���-�� ������: ";
	cin >> region.barl;

	cout << "������� ���-�� ����: ";
	cin >> region.bathhouse;

	cin.get();
}

void inputRegions(Region* region, unsigned size)
{
	if (!region || !size)
	{
		return;
	}

	for (size_t i = 0; i < size; i++)
	{
		cout << "������� ������� ��� ������� " << i + 1 << ": \n";
		inputRegion(region[i]);
	}
}

void fillRndRegion(Region& region,
	int min = 704, int max = 7777)
{
	if (min > max) std::swap(min, max);

	static int i = 1;
	srand(time(0) * i++);

	int rnd;

	rnd = min + rand() % (max - min + 1);
	region.number = rnd;

	rnd = 1 + rand() % (3 - 1 + 1);
	region.house = rnd;

	rnd = 0 + rand() % (2 - 0 + 1);
	region.garage = rnd;

	rnd = 0 + rand() % (3 - 0 + 1);
	region.barl = rnd;

	rnd = 0 + rand() % (1 - 0 + 1);
	region.bathhouse = rnd;

	rnd = 90 + rand() % (225 - 90 + 1);
	region.areaHouse = rnd;

	rnd = 15 + rand() % (35 - 15 + 1);
	region.areaGarage = rnd;

	rnd = 15 + rand() % (35 - 15 + 1);
	region.AreaBarl = rnd;

	rnd = 15 + rand() % (35 - 15 + 1);
	region.AreaBathhouse = rnd;

	rnd = 2000 + rand() % (4000 - 2000 + 1);
	region.AreaAllRegion = rnd;
}

void fillRndRegions(Region* region, unsigned size)
{
	if (!region || !size)
	{
		return;
	}

	for (size_t i = 0; i < size; i++)
	{
		fillRndRegion(region[i]);
	}
}

void fillHouse(House& house)
{
	static int i = 1;
	srand(time(0) * i++);

	int rnd;

	rnd = 1 + rand() % (3 - 1 + 1);
	house.floors = rnd;

	rnd = 2 + rand() % (4 - 2 + 1);
	house.rooms = rnd;

	rnd = rand() % 1;
	house.bake = rnd;
}

void fillRoomsName(House& house)
{
	int ind;

	ind = rand() & SizeRoomsName;
	house.nameRooms = Test_Rooms_Names[ind];
}

void fillRndHouseRooms(House*& house, Region*& reg)
{
	if (!reg)
	{
		cout << "\n\n� ���� ��� ��������!";
		return;
	}

	short num;
	short buf;

	cout << "������� ����� ������� � ����: ";
	cin >> buf;

	cout << "\n���-�� ����� �� ������ �������: " << reg[buf].house;

	cout << "\n������� ����� ���� � ������� ������ ������ ���������: ";
	while (!(cin >> num))
	{
		cin.clear();
		cin.ignore();
		cout << "\n������� ��� � ������� ������ ������ ���������: ";
	}

	if (num >= reg[buf].house)
	{
		cout << "�������� ����!";
	}

	fillHouse(house[num]);

	cout << "������ � ����: " << house->floors;
	for (size_t i = 0; i < house->rooms ; i++)
	{
		fillRoomsName(house[num]);
	}

	printNameRooms(house, house->rooms);
}

// ��������� ������
 

// TO DO
// ������� ���������� �����, ��� ����� + ���������� �� ������� ���� ����������

int freeSpaceWithoutAllBuild(Region* reg, unsigned size, unsigned num)
{
	if (!reg) 
		return -1;

	int buf = reg->AreaAllRegion;

	buf -= ((reg->areaHouse * reg->house) + (reg->areaGarage * reg->garage)
		+ (reg->AreaBarl * reg->barl) + (reg->AreaBathhouse * reg->bathhouse));
	
	return buf;
}

void regFreeSpaceAllBild(Region* reg, unsigned size)
{
	unsigned short num(0);
	int average(0);

	cout << "������� ����� ������� � ����: ";
	while (!(cin >> num))
	{
		cin.clear();
		cin.ignore();
		cout << "\n������� ����� ������� � ����: ";
	}
	average = freeSpaceWithoutAllBuild(reg, size, num);

	cout << "���������� ����� �� ������� " << num << " = "
		<< average << " �^2";
}

int occupiedPlace(Region* reg, unsigned size, unsigned num)
{
	if (!reg)
		return -1;

	int buf(0);

	buf += ((reg->areaHouse * reg->house)
		+ (reg->areaGarage * reg->garage)
		+ (reg->AreaBarl * reg->barl)
		+ (reg->AreaBathhouse * reg->bathhouse));

	return buf;
}

void regOccupiedPlace(Region* reg, unsigned size)
{
	unsigned short num(0);
	int average(0);

	cout << "������� ����� ������� � ����: ";
	while (!(cin >> num))
	{
		cin.clear();
		cin.ignore();
		cout << "\n������� ����� ������� � ����: ";
	}
	average = occupiedPlace(reg, size, num);

	cout << "�������� ����� �� ������� " << num << " = "
		<< average << " �^2";
}

// ������� ������� � �������������

void inputRegionFromStdIn(Region*& region, unsigned& size)
{
	cout << "������� �������� ������ �������? ";

	if (!(cin >> size))
	{
		cout << "\n������ �����\n";
		cin.clear();
		cin.ignore();
		return;
	}
	cin.get();

	allocateMemory(region, size);
	inputRegions(region, size);
}

void inputRndRegions(Region*& region, unsigned& size)
{
	cout << "������� �������� ������ �������? ";

	if (!(cin >> size))
	{
		cout << "������ �����\n";
		cin.clear();
		cin.ignore();
		return;
	}
	cin.get();

	allocateMemory(region, size);
	fillRndRegions(region, size);
}

void printRegionHelp()
{
	cout << "-1 ���� � ����������\n";
	cout << "-2 ��������� ��������� ��������\n";
	cout << "-3 ����� �� �����\n\n";
	cout << "-4 ���������� �� ��������� �������\n";
	cout << "-5 ���������� � ��������� ����� ������������ �������\n";
	cout << "-6 ���������� � ������� ����� ������������ �������\n";
	cout << "-7 ���������� �� ��������� ���� �� �������\n";
	cout << "";
	cout << "";
}

void printNameRooms(House* house, unsigned size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << "������� " << i + 1 << " : " << house->nameRooms << '\n';
	}
}

// ������� ������� ��� Region

void plotTest()
{
	cout << "\t\t�������� �� ���������� ������\n\n";

	unsigned sizeRegion = 0;
	Region* region = nullptr;
	House* house = nullptr;

	char buf[256] = { 0 };
	char choice[128] = { 0 };

	printRegionHelp();

	while (strcmp(choice, "q"))
	{
		memset(buf, 0, sizeof(buf));
		memset(choice, 0, sizeof(choice));

		printf("�������� ����� ����: \n");
		gets_s(buf, sizeof(buf));
		sscanf_s(buf, "-%s", choice, sizeof(choice));

		switch (atoi(choice))
		{
		case 0:
		{
			if (!strcmp(choice, "q"))
			{
				break;
			}
			else if (!strcmp(choice, "h"))
			{
				printRegionHelp();
			}
			else
			{
				cout << "����������� ��������\n";
			}
		}
		case 1:
		{
			inputRegionFromStdIn(region, sizeRegion);
			break;
		}
		case 2:
		{
			inputRndRegions(region, sizeRegion);
			break;
		}
		case 3:
		{
			printRegions(region, sizeRegion);
			break;
		}
		case 4:
		{
			printRegion(region, sizeRegion);
			break;
		}
		case 5:
		{
			regFreeSpaceAllBild(region, sizeRegion);
			break;
		}
		case 6:
		{
			regOccupiedPlace(region, sizeRegion);
			break;
		}
		case 7:
		{
			fillRndHouseRooms(house, region);
			break;
		}
		case 8:
		{

			// TO DO
			// ���������� �� ����� �������
			break;
		}
		default:
			cout << "����������� �����\n";
			break;
		}
	}
	delete[] region;
}