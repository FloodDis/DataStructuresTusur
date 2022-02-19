#include "IOHashTable.h"

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
				EnterString("Введите key искомого элемента: ", key);
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