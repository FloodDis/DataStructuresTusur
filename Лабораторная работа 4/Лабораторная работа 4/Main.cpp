#include <iostream>
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

void DictionaryMenu()
{
	Dictionary* dictionaryUnit= new Dictionary;
	setlocale(LC_ALL, "ru");
	int size;
	EnterNumber("Введите размер словаря:\n", size);
	InitializationOfDictionary(dictionaryUnit->HashTable, size);
	printf("\nВаш словарь:\n");
	PrintTable(dictionaryUnit->HashTable);
	int option;
	while (true)
	{
		printf("Выберите действие:\n1) Добавить элемент\n2) Удалить элемент\n3) Поиск элемента\n4) Рехешинг\n5) Выйти\n");
		cin >> option;
		switch (option)
		{
		case 1:
		{
			string value, key;
			double size = dictionaryUnit->HashTable.size();
			printf("Введите значение value: ");
			cin >> value;
			printf("Введите значение key: ");
			cin >> key;
			if (ElementCount(dictionaryUnit->HashTable) / size >= 1.5)
			{
				Rehashing(dictionaryUnit->HashTable, ElementCount(dictionaryUnit->HashTable));
			}
			AddInDictionary(dictionaryUnit->HashTable, value, key);
			printf("\nВаш словарь:\n");
			PrintTable(dictionaryUnit->HashTable);
			break;
		}
		case 2:
		{
			string key;
			printf("Введите key удаляемого элемента: ");
			cin >> key;
			DeleteFromDictionary(dictionaryUnit->HashTable, key);
			printf("\nВаш словарь:\n");
			PrintTable(dictionaryUnit->HashTable);
			break;
		}
		case 3:
		{
			string key;
			string answer;
			printf("Введите key искомого элемента: ");
			cin >> key;
			answer = SearchInDictionary(dictionaryUnit->HashTable, key);
			cout << answer;
			printf("\nВаш словарь:\n");
			PrintTable(dictionaryUnit->HashTable);
			break;
		}
		case 4:
		{
			Rehashing(dictionaryUnit->HashTable, ElementCount(dictionaryUnit->HashTable));
			printf("Ваш словарь:\n");
			PrintTable(dictionaryUnit->HashTable);
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
	printf("Введите размер хеш-таблицы:\n");
	cin >> size;
	InitializationOfHashTable(hashTableUnit, size);
	printf("\nВаша хеш-таблица:\n");
	PrintTable(hashTableUnit);
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
			printf("Введите значение value: ");
			cin >> value;
			printf("Введите значение key: ");
			cin >> key;
			if (ElementCount(hashTableUnit) / size >= 1.5)
			{
				Rehashing(hashTableUnit, ElementCount(hashTableUnit));
			}
			AddElementInHashTable(hashTableUnit, value, key);
			printf("\nВаша хеш-таблица:\n");
			PrintTable(hashTableUnit);
			break;
		}
		case 2:
		{
			string key;
			printf("Введите key удаляемого элемента: ");
			cin >> key;
			DeleteElementInHashTable(hashTableUnit, key);
			printf("\nВаша хеш-таблица:\n");
			PrintTable(hashTableUnit);
			break;
		}
		case 3:
		{
			string key;
			string answer;
			printf("Введите key искомого элемента: ");
			cin >> key;
			answer = SearchInHashTable(key, hashTableUnit);
			cout << answer << "\n";
			printf("\nВаша хеш-таблица:\n");
			PrintTable(hashTableUnit);
			break;
		}
		case 4:
		{
			Rehashing(hashTableUnit, ElementCount(hashTableUnit));
			printf("\nВаша хеш-таблица:\n");
			PrintTable(hashTableUnit);
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