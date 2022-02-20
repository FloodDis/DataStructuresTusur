#include "IOHashTable.h"

void HashTableMenu()
{
	setlocale(LC_ALL, "ru");
	HashTable* hashTableUnit = new HashTable;
	int size = EnterNumber("������� ������ ���-�������:\n");
	InitializationOfHashTable(hashTableUnit->arrayOfLists, size);
	ShowHashTable(hashTableUnit->arrayOfLists);
	while (true)
	{
		cout << "�������� ��������:\n1) �������� �������\n";
		cout << "2) ������� �������\n3) ����� ��������\n";
		cout << "4) ��������\n5) �����\n";
		int option = EnterNumber("");
		switch (option)
		{
			case 1:
			{
				double size = hashTableUnit.size();
				string value = EnterString("������� �������� value: ");
				string key = EnterString("������� �������� key: ");
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
				string key = EnterString("������� key ���������� ��������: ");
				DeleteElementInHashTable(hashTableUnit, key);
				ShowHashTable(hashTableUnit);
				break;
			}

			case 3:
			{
				string key = EnterString("������� key �������� ��������: ");
				string answer = "";
				answer = SearchInHashTable(key, hashTableUnit);
				if (answer == "")
				{
					cout << "������� �� ������.\n";
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
				cout << "���������� �����\n";
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
	cout << "���� ���-�������:\n";
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