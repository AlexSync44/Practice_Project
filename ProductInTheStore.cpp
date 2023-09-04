#define _CRT_SECURE_NO_WARNINGS

#include "ProductInTheStore.h"

const int SizeNamesItem(30);
const char* Test_Names_Item[30]
{
	"Корзина",
	"Глобус",
	"Аккумулятор",
	"ФайлДляБумаги",
	"Гриб",
	"Табурет",
	"Ведро",
	"Зеркало",
	"Книга",
	"ПлюшеваяИгрушка",
	"Светофор",
	"Телефон",
	"Кость",
	"ВоздушныйШар",
	"КоробкаСока",
	"Молоток",
	"КатушкаНиток",
	"Келгли",
	"Рюкзак",
	"Ракушка",
	"Леденец",
	"Юла",
	"Коробка",
	"Зонт",
	"Якорь",
	"Флешка",
	"Камера",
	"Коралл",
	"Череп",
	"Штаны"
};

void clearMemory(Things*& product)
{
	if (product)
	{
		delete[] product;
		product = nullptr;
	}
}

void allocateMemory(Things*& product, unsigned size)
{
	clearMemory(product);

	product = new Things[size];
}

//вывод
void printProduct(const Things& product)
{
	cout << "Название продукта\t"
		 << "Кол-во на складе\t"
		 << "Стоимость\n";

	cout << product.name << "\t\t\t"
		 << product.quantity << "\t\t\t"
		 << product.cost;
}

void printProduct(std::ostream& out, const Things& pro)
{
	out << pro.name << '\n' << pro.quantity << '\t'
		<< pro.cost << "\n\n";
}

void printProducts(const Things* pro, unsigned size)
{
	if (!pro || !size)
	{
		return;
	}

	for (size_t i = 0; i < size; i++)
	{
		cout << "\n# " << i << '\n';
		printProduct(pro[i]);
	}
	cout << '\n';
}

void printProducts(std::ostream& out, const Things* pro, unsigned size)
{
	if (!pro || !size)
	{
		return;
	}

	for (size_t i = 0; i < size; i++)
	{
		printProduct(out, pro[i]);
		out << '\n';
	}
}

// вывод данных
void inputProduct(Things& pro)
{
	cout << "Введите название предмета: ";
	getline(cin, pro.name);

	cout << "Введите кол-во предметов на складе: ";
	cin >> pro.quantity;

	cout << "Введите его цену: ";
	cin >> pro.cost;
}

void inputProducts(Things* pro, unsigned size)
{
	if (!pro || !size)
	{
		return;
	}

	for (size_t i = 0; i < size; i++)
	{
		cout << "Введите предмет под номером " << i << ": \n";
		inputProduct(pro[i]);
	}
}

void fillRndProduct(Things& pro, int min = 300, int max = 3000)
{
	if (min > max) std::swap(min, max);

	static int i = 1;
	srand(time(0) * i++);

	float rnd(0);
	int ind;

	ind = rand() % SizeNamesItem;
	pro.name = Test_Names_Item[ind];

	rnd = min + rand() % (max - min + 1);
	pro.cost = rnd;

	rnd = 7 + rand() % (30 - 7 + 1);
	pro.quantity = rnd;
}

void fillRndProducts(Things* pro, unsigned size)
{
	if (!pro || !size)
	{
		return;
	}

	for (size_t i = 0; i < size; i++)
	{
		fillRndProduct(pro[i]);
	}
}

int countProdictInFile(std::ifstream& ifile)
{
	int count(0);

	if (!ifile.is_open())
	{
		return -1;
	}

	string str;

	while (!ifile.eof())
	{
		getline(ifile, str);

		if (!str.empty())
			count++;
	}

	count /= 2;

	return count;
}

void inputProduct(std::istream& in, Things& pro)
{
	if (in.bad())
		return;

	do
	{
		getline(in, pro.name);
	} while (!in.eof() && pro.name.empty());

	in >> pro.quantity;
	in >> pro.cost;
}

void inputProducts(std::ifstream& in, const string& fileName,
	Things*& pro, unsigned& size)
{
	if (!in.is_open())
	{
		return;
	}

	int productCount = countProdictInFile(in);
	if (productCount <= 0)
		return;

	size = productCount;
	allocateMemory(pro, size);

	in.close();
	in.open(fileName);

	if (!in.is_open())
	{
		cout << "Не удалось открыть файл " << fileName << '\n';
		return;
	}

	for (size_t i = 0; i < size; i++)
	{
		inputProduct(in, pro[i]);
	}
}

void printInfoProduct(const Things* pro, unsigned size)
{
	string name;

	cout << "Введите имя продукта: ";
	getline(cin, name);

	for (size_t i = 0; i < size; i++)
	{
		if (name == pro[i].name)
		{
			printProduct(pro[i]);
			break;
		}
	}
	cout << "Такого товара нет\n";
}

bool cmpNameProducts(Things proA, Things proB)
{
	return (proA.name > proB.name);
}

int cmpProductQuantity(const void* proA, const void* proB)
{
	Things* xdep = (Things*)proA;
	Things* ydep = (Things*)proB;

	if (xdep->quantity < ydep->quantity)
	{
		return 1;
	}
	else
	{
		return -1;
	}
	return 1;
}

int cmpProductCost(const void* proA, const void* proB)
{
	Things* xdep = (Things*)proA;
	Things* ydep = (Things*)proB;

	if (xdep->cost < ydep->cost)
	{
		return 1;
	}
	else
	{
		return -1;
	}
	return 1;
}

// функции диалога с пользователем
void inputProductFromStdIn(Things*& pro, unsigned& size)
{
	cout << "Сколько предметов хотите создать? :";

	if (!(cin >> size))
	{
		cout << "Ошибка ввода\n";
		cin.clear();
		cin.ignore();
		return;
	}
	cin.get();

	allocateMemory(pro, size);
	inputProducts(pro, size);
}

void inputRndProducts(Things*& pro, unsigned& size)
{
	cout << "Сколько предметов хотите создать? ";

	if (!(cin >> size))
	{
		cout << "Ошибка ввода\n";
		cin.clear();
		cin.ignore();
		return;
	}
	cin.get();

	allocateMemory(pro, size);
	fillRndProducts(pro, size);
}

void inputProductFromFile(Things*& pro, unsigned& size)
{
	cout << "Введите имя файла для чтения продуктов: ";

	string fileName;
	getline(cin, fileName);

	std::ifstream file(fileName, std::ios::in);

	if (!file.is_open())
	{
		cout << "Ошибка открытия файла на чтения\n";
		return;
	}

	inputProducts(file, fileName, pro, size);

	file.close();
}

void printProductToFile(const Things* pro, const unsigned size)
{
	if (!pro || !size)
	{
		cout << "Ошибка данных при записи в файл\n";
		return;
	}

	cout << "Введите имя фалйла для печати продуктов: ";

	string fileName;
	getline(cin, fileName);

	std::ofstream file(fileName, std::ios_base::app);

	printProducts(file, pro, size);

	file.close();
}

void printProductHelp()
{
	cout << "-1 Ввод с клавиатуры\n";
	cout << "-2 Ввод из файла\n";
	cout << "-3 Генерация случайных продуктов\n\n";

	cout << "-4 Вывод на экран\n";
	cout << "-5 Запись в файл\n\n";

	cout << "-6 Сортировка по имени продуктов\n";
	cout << "-7 Сортировка по кол-ву на складе\n";
	cout << "-8 Сортировка по стоимости\n\n";

	cout << "-9 Показать информацию об отдельном товаре\n\n";

	cout << "-h Справка\n";
	cout << "-q Выход\n\n";
}

void ThingsTest()
{
	cout << "\t\tОперации со структурой продуктов\n\n";

	unsigned sizeProduct = 0;
	Things* product = nullptr;

	char buf[256] = { 0 };
	char choice[128] = { 0 };

	printProductHelp();

	while (strcmp(choice, "q"))
	{
		memset(buf, 0, sizeof(buf));
		memset(choice, 0, sizeof(choice));

		cout << "\nВыберите пункт меню: \n";
		fgets(buf, sizeof(buf), stdin);
		sscanf(buf, "-%s", choice, sizeof(choice));

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
				printProductHelp();
			}
			else
			{
				cout << "Неизвестный выбор!\n";
			}
			break;
		}
		case 1:
		{
			inputProductFromStdIn(product, sizeProduct);
			break;
		}
		case 2:
		{
			inputProductFromFile(product, sizeProduct);
			break;
		}
		case 3:
		{
			inputRndProducts(product, sizeProduct);
			break;
		}
		case 4:
		{
			printProducts(product, sizeProduct);
			break;
		}
		case 5:
		{
			printProductToFile(product, sizeProduct);
			break;
		}
		case 6:
		{
			bubleSort(product, sizeProduct, cmpNameProducts);
			break;
		}
		case 7:
		{
			qsort(product, sizeProduct, sizeof(Things), cmpProductQuantity);
			break;
		}
		case 8:
		{
			qsort(product, sizeProduct, sizeof(Things), cmpProductCost);
			return;
		}
		case 9:
		{
			printInfoProduct(product, sizeProduct);
			break;
		}
		default:
		{
			cout << "Неизвестный выбор\n";
			break;
		}
		}
	}
	delete[] product;
}