#include "IODictionary.h"

void DictionaryMenu()
{
	Dictionary* dictionaryUnit = new Dictionary;
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

void ShowDictionary(HashTable* hashTableUnit)
{
	cout << "Ваш словарь:\n";
	PrintDictionary(hashTableUnit);
}

void PrintDictionary(HashTable* hashTableUnit)
{
	PrintTable(hashTableUnit);
}