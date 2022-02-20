#include <iostream>
#include "IODictionary.h"
#include "IOHashTable.h"

void MainMenu();

int main()
{
	MainMenu();
	return 0;
}

void MainMenu()
{
	setlocale(LC_ALL, "ru");
	int option;
	while (true)
	{
		cout << "Выберите структуру данных:\n1) Хеш-таблица\n";
		cout << "2) Словарь\n3) Выйти\n";
		cin >> option;
		switch (option)
		{
			case 1:
			{
				HashTableMenu();
				break;
			}

			case 2:
			{
				DictionaryMenu();
				break;
			}

			case 3:
			{
				return;
			}

			default:
			{
				cout << "Попробуйте снова!" << endl;
				break;
			}
		}
	}
}