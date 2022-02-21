#include "IODictionary.h"

void DictionaryMenu()
{
	Dictionary* dictionaryUnit = new Dictionary;
	dictionaryUnit->HashTable = new HashTable;
	setlocale(LC_ALL, "ru");
	int size = EnterNumber("������� ������ �������:\n");
	InitializeDictionary(dictionaryUnit->HashTable, size);
	Show(dictionaryUnit->HashTable);

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
				Add(dictionaryUnit->HashTable, value, key);
				Show(dictionaryUnit->HashTable);
				break;
			}

			case 2:
			{
				string key =
					EnterString("������� key ���������� ��������: ");
				string answer = 
					Find(dictionaryUnit->HashTable, key);
				if (answer == "")
				{
					cout << "������� �� ������.\n";
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
					EnterString("������� key �������� ��������: ");
				string answer = "";
				answer =
					Find(dictionaryUnit->HashTable, key);
				if (answer == "")
				{
					cout << "������� �� ������.\n";
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
				//TODO: 
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
				cout << "���������� �����!" << endl;
				Show(dictionaryUnit->HashTable);
				break;
			}
		}
	}
}
//TODO: ��. ��� 3
//TODO: ������������ �������� ������ ���������� dictionary,
//TODO: ���� ��� �������, � �� ���-�������.
void Show(HashTable* hashTableUnit)
{
	cout << "��� �������:\n";
	Print(hashTableUnit);
}
//TODO: ������ ���������, ����� �������� ��� ����� ������
void Print(HashTable* hashTableUnit)
{
	PrintTable(hashTableUnit);
}