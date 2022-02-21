#include "IOHashTable.h"

void HashTableMenu()
{
	setlocale(LC_ALL, "ru");
	HashTable* hashTableUnit = new HashTable;
	int size = EnterNumber("������� ������ ���-�������:\n");
	InitializeHashTable(hashTableUnit, size);
	ShowHashTable(hashTableUnit);
	while (true)
	{
		//TODO: ��. ���3
		cout << "�������� ��������:\n1) �������� �������\n";
		cout << "2) ������� �������\n3) ����� ��������\n";
		cout << "4) ��������\n5) �����\n";
		int option = EnterNumber("");
		switch (option)
		{
			case 1:
			{
				double size = hashTableUnit->arrayOfLists.size();
				//TODO: �����
				string value = EnterString("������� �������� value: ");
				//TODO: �����
				string key = EnterString("������� �������� key: ");
				double fillFactor;
				int elementCount = ElementCount(hashTableUnit);
				fillFactor = ElementCount(hashTableUnit) / size;
				if (fillFactor >= hashTableUnit->MaxFillFactor)
				{
					Rehashing(hashTableUnit, ElementCount(hashTableUnit));
				}
				AddInHashTable(hashTableUnit, value, key);
				ShowHashTable(hashTableUnit);
				break;
			}

			case 2:
			{
				//TODO: �����
				string key = 
					EnterString("������� key ���������� ��������: ");
				string answer = Search(key, hashTableUnit);
				if (answer == "")
				{
					cout << "������� �� ������.\n";
					ShowHashTable(hashTableUnit);
					break;
				}
				DeleteFromHashTable(hashTableUnit, key);
				ShowHashTable(hashTableUnit);
				break;
			}

			case 3:
			{
				//TODO: �����
				string key = 
					EnterString("������� key �������� ��������: ");
				string answer = Search(key, hashTableUnit);
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

void PrintTable(HashTable* hashTableUnit)
{
	for (int i = 0; i < hashTableUnit->arrayOfLists.size(); i++)
	{
		cout << i;
		PrintKeyValueList(hashTableUnit->arrayOfLists[i]);
	}
}

void ShowHashTable(HashTable* hashTableUnit)
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