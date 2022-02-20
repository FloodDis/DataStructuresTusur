#include "IODictionary.h"

void DictionaryMenu()
{
	Dictionary* dictionaryUnit = new Dictionary;
	setlocale(LC_ALL, "ru");
	int size;
	EnterNumber("������� ������ �������:\n", size);
	InitializationOfDictionary(dictionaryUnit->HashTable, size);
	ShowDictionary(dictionaryUnit->HashTable);
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
				EnterString("������� key ���������� ��������: ", key);
				DeleteFromDictionary(dictionaryUnit->HashTable, key);
				ShowDictionary(dictionaryUnit->HashTable);
				break;
			}

			case 3:
			{
				string key;
				string answer;
				EnterString("������� key �������� ��������: ", key);
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
				cout << "���������� �����!" << endl;
				break;
			}
		}
	}
}

void ShowDictionary(HashTable* hashTableUnit)
{
	cout << "��� �������:\n";
	PrintDictionary(hashTableUnit);
}

void PrintDictionary(HashTable* hashTableUnit)
{
	PrintTable(hashTableUnit);
}