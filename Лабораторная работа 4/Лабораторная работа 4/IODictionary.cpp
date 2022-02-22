#include "IODictionary.h"

void DictionaryMenu()
{
	/// <summary>
	/// Действия над словарем
	/// </summary>
	enum Actions
	{
		/// <summary>
		/// Добавить элемент
		/// </summary>
		AddElement = 1,

		/// <summary>
		/// Удалить элемент
		/// </summary>
		DeleteElement,

		/// <summary>
		/// Найти элемент
		/// </summary>
		FindElement,

		/// <summary>
		/// Перехешировать словарь
		/// </summary>
		Rehash,

		/// <summary>
		/// Выйти в главное меню
		/// </summary>
		Exit
	};
	Dictionary* dictionaryUnit = new Dictionary;
	dictionaryUnit->HashTable = new HashTable;
	setlocale(LC_ALL, "ru");
	int size = EnterNumber("Введите размер словаря:\n");
	InitializeDictionary(dictionaryUnit->HashTable, size);
	Show(dictionaryUnit->HashTable);

	while (true)
	{
		cout << "Выберите действие:\n1) Добавить элемент\n"
			<< "2) Удалить элемент\n3) Поиск элемента\n"
			<< "4) Рехешинг\n5) Выйти\n";
		int option = EnterNumber("");
		switch (option)
		{
			case AddElement:
			{
				string value = EnterString("Введите значение value: ");
				string key = EnterString("Введите значение key: ");
				double size =
					dictionaryUnit->HashTable->ArrayOfLists.size();
				double fillFactor =
					ElementCount(dictionaryUnit->HashTable) / size;
				if (fillFactor >= dictionaryUnit->HashTable->MaxFillFactor)
				{
					int elementCount =
						ElementCount(dictionaryUnit->HashTable);
					Rehashing(dictionaryUnit->HashTable, elementCount);
				}
				Add(dictionaryUnit->HashTable, value, key);
				Show(dictionaryUnit->HashTable);
				break;
			}

			case DeleteElement:
			{
				string key =
					EnterString("Введите key удаляемого элемента: ");
				string answer = 
					Find(dictionaryUnit->HashTable, key);
				if (answer == "")
				{
					cout << "Элемент не найден.\n";
					Show(dictionaryUnit->HashTable);
					break;
				}
				Delete(dictionaryUnit->HashTable, key);
				Show(dictionaryUnit->HashTable);
				break;
			}

			case FindElement:
			{
				string key =
					EnterString("Введите key искомого элемента: ");
				string answer = "";
				answer =
					Find(dictionaryUnit->HashTable, key);
				if (answer == "")
				{
					cout << "Элемент не найден.\n";
					Show(dictionaryUnit->HashTable);
					break;
				}
				else
				{
					cout << answer;
					Show(dictionaryUnit->HashTable);
					break;
				}
			}

			case Rehash:
			{
				int elementCount = ElementCount(dictionaryUnit->HashTable);
				Rehashing(dictionaryUnit->HashTable, elementCount);
				Show(dictionaryUnit->HashTable);
				break;
			}

			case Exit:
			{
				return;
			}

			default:
			{
				cout << "Попробуйте снова!" << endl;
				Show(dictionaryUnit->HashTable);
				break;
			}
		}
	}
}

void Show(HashTable* hashTableUnit)
{
	cout << "Ваш словарь:\n";
	PrintDictionary(hashTableUnit);
}

void PrintDictionary(HashTable* hashTableUnit)
{
	PrintTable(hashTableUnit);
}