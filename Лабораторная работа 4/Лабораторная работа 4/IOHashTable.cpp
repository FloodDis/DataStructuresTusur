#include "IOHashTable.h"

void HashTableMenu()
{
	setlocale(LC_ALL, "ru");
	vector<KeyValueList*> hashTableUnit;
	int size = EnterNumber("Введите размер хеш-таблицы:\n");
	InitializationOfHashTable(hashTableUnit, size);
	ShowHashTable(hashTableUnit);
	while (true)
	{
		cout << "Выберите действие:\n1) Добавить элемент\n";
		cout << "2) Удалить элемент\n3) Поиск элемента\n";
		cout << "4) Рехешинг\n5) Выйти\n";
		int option = EnterNumber("");
		switch (option)
		{
			case 1:
			{
				double size = hashTableUnit.size();
				string value = EnterString("Введите значение value: ");
				string key = EnterString("Введите значение key: ");
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
				string key = EnterString("Введите key удаляемого элемента: ");
				DeleteElementInHashTable(hashTableUnit, key);
				ShowHashTable(hashTableUnit);
				break;
			}

			case 3:
			{
				string key = EnterString("Введите key искомого элемента: ");
				string answer = "";
				answer = SearchInHashTable(key, hashTableUnit);
				if (answer == "")
				{
					cout << "Элемент не найден.\n";
					ShowHashTable(hashTableUnit);
					break;
				}
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
			}

			default:
			{
				cout << "Попробуйте снова\n";
				ShowHashTable(hashTableUnit);
				break;
			}
		}
	}
}

void PrintTable(vector<KeyValueList*> hashTableUnit)
{
	for (int i = 0; i < hashTableUnit.size(); i++)
	{
		cout << i;
		PrintKeyValueList(hashTableUnit[i]);
	}
}

void ShowHashTable(vector<KeyValueList*> hashTableUnit)
{
	cout << "Ваша хеш-таблица:\n";
	PrintTable(hashTableUnit);
}

void PrintKeyValueList(KeyValueList* listUnit)
{
	while (listUnit != nullptr)
	{
		cout << " -> " << listUnit->Value << " " << listUnit->Key;
		listUnit = listUnit->Next;
	}
	cout << "\n";
}