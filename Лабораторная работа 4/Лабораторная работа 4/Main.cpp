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
		printf("�������� ��������� ������:\n1) ���-�������\n2) �������\n3) �����\n");
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
			cout << "���������� �����!" << endl;
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
	EnterNumber("������� ������ �������:\n", size);
	InitializationOfDictionary(dictionaryUnit->HashTable, size);
	printf("\n��� �������:\n");
	PrintTable(dictionaryUnit->HashTable);
	int option;
	while (true)
	{
		printf("�������� ��������:\n1) �������� �������\n2) ������� �������\n3) ����� ��������\n4) ��������\n5) �����\n");
		cin >> option;
		switch (option)
		{
		case 1:
		{
			string value;
			string key;
			double size = dictionaryUnit->HashTable.size();
			EnterString("������� �������� value: ", value);
			EnterString("������� �������� key: ", key);
			if (ElementCount(dictionaryUnit->HashTable) / size >= 1.5)
			{
				Rehashing(dictionaryUnit->HashTable, ElementCount(dictionaryUnit->HashTable));
			}
			AddInDictionary(dictionaryUnit->HashTable, value, key);
			printf("\n��� �������:\n");
			PrintTable(dictionaryUnit->HashTable);
			break;
		}
		case 2:
		{
			string key;
			EnterString("������� key ���������� ��������: ", key);
			DeleteFromDictionary(dictionaryUnit->HashTable, key);
			printf("\n��� �������:\n");
			PrintTable(dictionaryUnit->HashTable);
			break;
		}
		case 3:
		{
			string key;
			string answer;
			EnterString("������� key �������� ��������: ", key);
			answer = SearchInDictionary(dictionaryUnit->HashTable, key);
			cout << answer;
			printf("\n��� �������:\n");
			PrintTable(dictionaryUnit->HashTable);
			break;
		}
		case 4:
		{
			Rehashing(dictionaryUnit->HashTable, ElementCount(dictionaryUnit->HashTable));
			printf("��� �������:\n");
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
			cout << "���������� �����!" << endl;
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
	EnterNumber("������� ������ ���-�������:\n", size);
	InitializationOfHashTable(hashTableUnit, size);
	printf("\n���� ���-�������:\n");
	PrintTable(hashTableUnit);
	int option;
	while (true)
	{
		printf("�������� ��������:\n1) �������� �������\n2) ������� �������\n3) ����� ��������\n4) ��������\n5) �����\n");
		cin >> option;
		switch (option)
		{
		case 1:
		{
			double size;
			size = hashTableUnit.size();
			string value;
			string key;
			EnterString("������� �������� value: ", value);
			EnterString("������� �������� key: ", key);
			if (ElementCount(hashTableUnit) / size >= 1.5)
			{
				Rehashing(hashTableUnit, ElementCount(hashTableUnit));
			}
			AddElementInHashTable(hashTableUnit, value, key);
			printf("\n���� ���-�������:\n");
			PrintTable(hashTableUnit);
			break;
		}
		case 2:
		{
			string key;
			EnterString("������� key ���������� ��������: ", key);
			DeleteElementInHashTable(hashTableUnit, key);
			printf("\n���� ���-�������:\n");
			PrintTable(hashTableUnit);
			break;
		}
		case 3:
		{
			string key;
			string answer;
			EnterString("������� key �������� ��������: ",key);
			answer = SearchInHashTable(key, hashTableUnit);
			cout << answer << "\n";
			printf("\n���� ���-�������:\n");
			PrintTable(hashTableUnit);
			break;
		}
		case 4:
		{
			Rehashing(hashTableUnit, ElementCount(hashTableUnit));
			printf("\n���� ���-�������:\n");
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
			cout << "���������� �����!" << endl;
			break;
		}
		}
	}
}