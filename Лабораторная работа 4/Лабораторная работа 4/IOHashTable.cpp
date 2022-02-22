#include "IOHashTable.h"

void HashTableMenu()
{
	/// <summary>
	/// Действия над хеш-таблицей
	/// </summary>
	enum Actions
	{
		/// <summary>
		/// Добавить элемент
		/// </summary>
		Add = 1,

		/// <summary>
		/// Удалить элемент
		/// </summary>
		Delete,

		/// <summary>
		/// Найти элемент
		/// </summary>
		Find,

		/// <summary>
		/// Перехешировать таблицу
		/// </summary>
		Rehash,

		/// <summary>
		/// Выйти в главное меню
		/// </summary>
		Exit
	};
	setlocale(LC_ALL, "ru");
	HashTable* hashTableUnit = new HashTable;
	int size = EnterNumber("Введите размер хеш-таблицы:\n");
	InitializeHashTable(hashTableUnit, size);
	ShowHashTable(hashTableUnit);
	while (true)
	{
		cout << "Выберите действие:\n1) Добавить элемент\n"
			<< "2) Удалить элемент\n3) Поиск элемента\n"
			<< "4) Рехешинг\n5) Выйти\n";
		int option = EnterNumber("");
		switch (option)
		{
			case Add:
			{
				double size = hashTableUnit->ArrayOfLists.size();
				string value = EnterString("Введите значение value: ");
				string key = EnterString("Введите значение key: ");
				double fillFactor = ElementCount(hashTableUnit) / size;
				int elementCount = ElementCount(hashTableUnit);
				if (fillFactor >= hashTableUnit->MaxFillFactor)
				{
					Rehashing(hashTableUnit, ElementCount(hashTableUnit));
				}
				AddInHashTable(hashTableUnit, value, key);
				ShowHashTable(hashTableUnit);
				break;
			}

			case Delete:
			{
				string key =
					EnterString("Введите key удаляемого элемента: ");
				vector<KeyValueList*> answer = Search(key, hashTableUnit);
				if (answer.size() == 0)
				{
					cout << "Элемент не найден.\n";
					ShowHashTable(hashTableUnit);
					break;
				}
				DeleteFromHashTable(hashTableUnit, key);
				ShowHashTable(hashTableUnit);
				break;
			}

			case Find:
			{
				string key =
					EnterString("Введите key искомого элемента: ");
				vector<KeyValueList*> answer = Search(key, hashTableUnit);
				if (answer.size() == 0)
				{
					cout << "Элемент не найден.\n";
					ShowHashTable(hashTableUnit);
					break;
				}
				if (answer.size() > 1)
				{
					cout << "Найденные элементы:\n";
				}
				else
				{
					cout << "Найденный элемент:\n";
				}
				
				for (int i = 0; i < answer.size(); i++)
				{
					cout << "Key: " << answer[i]->Key << "\n";
					cout << "Value: " << answer[i]->Value << "\n";
					cout << "\n";
				}
				ShowHashTable(hashTableUnit);
				break;
			}

			case Rehash:
			{
				Rehashing(hashTableUnit, ElementCount(hashTableUnit));
				ShowHashTable(hashTableUnit);
				break;
			}

			case Exit:
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

void PrintTable(HashTable* hashTableUnit)
{
	for (int i = 0; i < hashTableUnit->ArrayOfLists.size(); i++)
	{
		cout << i;
		PrintKeyValueList(hashTableUnit->ArrayOfLists[i]);
	}
}

void ShowHashTable(HashTable* hashTableUnit)
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