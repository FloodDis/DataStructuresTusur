#include "IODictionary.h"

void DictionaryMenu()
{
	Dictionary* dictionaryUnit = new Dictionary;
	dictionaryUnit->HashTable = new HashTable;
	setlocale(LC_ALL, "ru");
	int size = EnterNumber("Введите размер словаря:\n");
	InitializationOfDictionary(dictionaryUnit->HashTable, size);
	ShowDictionary(dictionaryUnit->HashTable);

	while (true)
	{
		cout << "Выберите действие:\n1) Добавить элемент\n"
			<< "2) Удалить элемент\n3) Поиск элемента\n"
			<< "4) Рехешинг\n5) Выйти\n";
		int option = EnterNumber("");
		switch (option)
		{
			case 1:
			{
				//TODO: см лаб3
				string value = EnterString("Введите значение value: ");
				string key = EnterString("Введите значение key: ");
				double size =
					dictionaryUnit->HashTable->arrayOfLists.size();
				double fillFactor =
					ElementCount(dictionaryUnit->HashTable) / size;
				//TODO: длина
				if (fillFactor >= dictionaryUnit->HashTable->MaxFillFactor)
				{
					int elementCount =
						ElementCount(dictionaryUnit->HashTable);
					Rehashing(dictionaryUnit->HashTable, elementCount);
				}
				AddInDictionary(dictionaryUnit->HashTable, value, key);
				ShowDictionary(dictionaryUnit->HashTable);
				break;
			}

			case 2:
			{
				string key =
					EnterString("Введите key удаляемого элемента: ");
				string answer = 
					SearchInDictionary(dictionaryUnit->HashTable, key);
				if (answer == "")
				{
					cout << "Элемент не найден.\n";
					ShowDictionary(dictionaryUnit->HashTable);
					break;
				}
				DeleteFromDictionary(dictionaryUnit->HashTable, key);
				ShowDictionary(dictionaryUnit->HashTable);
				break;
			}

			case 3:
			{
				string key =
					EnterString("Введите key искомого элемента: ");
				string answer = "";
				answer =
					SearchInDictionary(dictionaryUnit->HashTable, key);
				if (answer == "")
				{
					cout << "Элемент не найден.\n";
					ShowDictionary(dictionaryUnit->HashTable);
					break;
				}
				else
				{
					cout << answer;
					ShowDictionary(dictionaryUnit->HashTable);
					break;
				}
			}

			case 4:
			{
				//TODO: 
				int elementCount = ElementCount(dictionaryUnit->HashTable);
				Rehashing(dictionaryUnit->HashTable, elementCount);
				ShowDictionary(dictionaryUnit->HashTable);
				break;
			}

			case 5:
			{
				return;
			}

			default:
			{
				cout << "Попробуйте снова!" << endl;
				ShowDictionary(dictionaryUnit->HashTable);
				break;
			}
		}
	}
}
//TODO: см. лаб 3
//TODO: Передаваемый параметр должен называться dictionary,
//TODO: ведь это словарь, а не хеш-таблица.
void ShowDictionary(HashTable* hashTableUnit)
{
	cout << "Ваш словарь:\n";
	PrintDictionary(hashTableUnit);
}
//TODO: Лишняя сложность, можно обойтись без этого метода
void PrintDictionary(HashTable* hashTableUnit)
{
	PrintTable(hashTableUnit);
}