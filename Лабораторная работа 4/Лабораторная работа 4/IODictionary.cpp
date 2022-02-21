#include "IODictionary.h"

void DictionaryMenu()
{
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
			case 1:
			{
				//TODO: см лаб3
				string value = EnterString("Введите значение value: ");
				string key = EnterString("Введите значение key: ");
				double size =
					dictionaryUnit->HashTable->arrayOfLists.size();
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

			case 2:
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

			case 3:
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

			case 4:
			{
				int elementCount = ElementCount(dictionaryUnit->HashTable);
				Rehashing(dictionaryUnit->HashTable, elementCount);
				Show(dictionaryUnit->HashTable);
				break;
			}

			case 5:
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