#include "IODictionary.h"

void DictionaryMenu()
{
	Dictionary* dictionaryUnit = new Dictionary;
	dictionaryUnit->HashTable = new HashTable;
	setlocale(LC_ALL, "ru");
	int size = EnterNumber("������� ������ �������:\n");
	InitializationOfDictionary(dictionaryUnit->HashTable, size);
	ShowDictionary(dictionaryUnit->HashTable);

	while (true)
	{
		cout << "�������� ��������:\n1) �������� �������\n"
			<< "2) ������� �������\n3) ����� ��������\n"
			<< "4) ��������\n5) �����\n";
		int option = EnterNumber("");
		switch (option)
		{
			case 1:
			{
				//TODO: �� ���3
				string value = EnterString("������� �������� value: ");
				string key = EnterString("������� �������� key: ");
				double size =
					dictionaryUnit->HashTable->arrayOfLists.size();
				double fillFactor =
					ElementCount(dictionaryUnit->HashTable) / size;
				//TODO: �����
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
					EnterString("������� key ���������� ��������: ");
				string answer = 
					SearchInDictionary(dictionaryUnit->HashTable, key);
				if (answer == "")
				{
					cout << "������� �� ������.\n";
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
					EnterString("������� key �������� ��������: ");
				string answer = "";
				answer =
					SearchInDictionary(dictionaryUnit->HashTable, key);
				if (answer == "")
				{
					cout << "������� �� ������.\n";
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
				cout << "���������� �����!" << endl;
				ShowDictionary(dictionaryUnit->HashTable);
				break;
			}
		}
	}
}
//TODO: ��. ��� 3
//TODO: ������������ �������� ������ ���������� dictionary,
//TODO: ���� ��� �������, � �� ���-�������.
void ShowDictionary(HashTable* hashTableUnit)
{
	cout << "��� �������:\n";
	PrintDictionary(hashTableUnit);
}
//TODO: ������ ���������, ����� �������� ��� ����� ������
void PrintDictionary(HashTable* hashTableUnit)
{
	PrintTable(hashTableUnit);
}