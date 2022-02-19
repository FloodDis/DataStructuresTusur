﻿#include <iostream>
#include "Dictionary.h"
#include "HashTable.h"

void MainMenu();
void DictionaryMenu();
void HashTableMenu();
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
		printf("Выберите структуру данных:\n1) Хеш-таблица\n2) Словарь\n3) Выйти\n");
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

void DictionaryMenu()
{
	Dictionary* dictionaryUnit= new Dictionary;
	setlocale(LC_ALL, "ru");
	int size;
	EnterNumber("Введите размер словаря:\n", size);
	InitializationOfDictionary(dictionaryUnit->HashTable, size);
	ShowDictionary(dictionaryUnit->HashTable);
	int option;
	while (true)
	{
		printf("Выберите действие:\n1) Добавить элемент\n2) Удалить элемент\n3) Поиск элемента\n4) Рехешинг\n5) Выйти\n");
		cin >> option;
		switch (option)
		{
			case 1:
			{
				string value;
				string key;
				double size = dictionaryUnit->HashTable.size();
				EnterString("Введите значение value: ", value);
				EnterString("Введите значение key: ", key);
				double fillFactor = ElementCount(dictionaryUnit->HashTable) / size;
				if (fillFactor >= 0.9)
				{
					Rehashing(dictionaryUnit->HashTable, ElementCount(dictionaryUnit->HashTable));
				}
				AddInDictionary(dictionaryUnit->HashTable, value, key);
				ShowDictionary(dictionaryUnit->HashTable);
				break;
			}

			case 2:
			{
				string key;
				EnterString("Введите key удаляемого элемента: ", key);
				DeleteFromDictionary(dictionaryUnit->HashTable, key);
				ShowDictionary(dictionaryUnit->HashTable);
				break;
			}

			case 3:
			{
				string key;
				string answer;
				EnterString("Введите key искомого элемента: ", key);
				answer = SearchInDictionary(dictionaryUnit->HashTable, key);
				cout << answer;
				ShowDictionary(dictionaryUnit->HashTable);
				break;
			}

			case 4:
			{
				Rehashing(dictionaryUnit->HashTable, ElementCount(dictionaryUnit->HashTable));
				ShowDictionary(dictionaryUnit->HashTable);
				break;
			}

			case 5:
			{
				return;
				break;
			}

			default:
			{
				cout << "Попробуйте снова!" << endl;
				break;
			}
		}
	}

}

void HashTableMenu()
{
	vector<KeyValueList*> hashTableUnit;
	setlocale(LC_ALL, "ru");
	int size;
	EnterNumber("Введите размер хеш-таблицы:\n", size);
	InitializationOfHashTable(hashTableUnit, size);
	ShowHashTable(hashTableUnit);
	int option;
	while (true)
	{
		printf("Выберите действие:\n1) Добавить элемент\n2) Удалить элемент\n3) Поиск элемента\n4) Рехешинг\n5) Выйти\n");
		cin >> option;
		switch (option)
		{
			case 1:
			{
				double size;
				size = hashTableUnit.size();
				string value;
				string key;
				EnterString("Введите значение value: ", value);
				EnterString("Введите значение key: ", key);
				double fillFactor = ElementCount(hashTableUnit) / size;
				if (fillFactor >= 0.9)
				{
					Rehashing(hashTableUnit, ElementCount(hashTableUnit));
				}
				AddElementInHashTable(hashTableUnit, value, key);
				ShowHashTable(hashTableUnit);
				break;
			}

			case 2:
			{
				string key;
				EnterString("Введите key удаляемого элемента: ", key);
				DeleteElementInHashTable(hashTableUnit, key);
				ShowHashTable(hashTableUnit);
				break;
			}

			case 3:
			{
				string key;
				string answer;
				EnterString("Введите key искомого элемента: ",key);
				answer = SearchInHashTable(key, hashTableUnit);
				cout << answer << "\n";
				ShowHashTable(hashTableUnit);
				break;
			}

			case 4:
			{
				Rehashing(hashTableUnit, ElementCount(hashTableUnit));
				ShowHashTable(hashTableUnit);
				break;
			}

			case 5:
			{
				return;
				break;
			}

			default:
			{
				cout << "Попробуйте снова!" << endl;
				break;
			}
		}
	}
}