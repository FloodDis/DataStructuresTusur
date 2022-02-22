#include "IOHashTable.h"

void HashTableMenu()
{
	/// <summary>
	/// �������� ��� ���-��������
	/// </summary>
	enum Actions
	{
		/// <summary>
		/// �������� �������
		/// </summary>
		Add = 1,

		/// <summary>
		/// ������� �������
		/// </summary>
		Delete,

		/// <summary>
		/// ����� �������
		/// </summary>
		Find,

		/// <summary>
		/// �������������� �������
		/// </summary>
		Rehash,

		/// <summary>
		/// ����� � ������� ����
		/// </summary>
		Exit
	};
	setlocale(LC_ALL, "ru");
	HashTable* hashTableUnit = new HashTable;
	int size = EnterNumber("������� ������ ���-�������:\n");
	InitializeHashTable(hashTableUnit, size);
	ShowHashTable(hashTableUnit);
	while (true)
	{
		cout << "�������� ��������:\n1) �������� �������\n"
			<< "2) ������� �������\n3) ����� ��������\n"
			<< "4) ��������\n5) �����\n";
		int option = EnterNumber("");
		switch (option)
		{
			case Add:
			{
				double size = hashTableUnit->ArrayOfLists.size();
				string value = EnterString("������� �������� value: ");
				string key = EnterString("������� �������� key: ");
				double fillFactor = ElementCount(hashTableUnit) / size;
				int elementCount = ElementCount(hashTableUnit);
				if (fillFactor >= hashTableUnit->MaxFillFactor)
				{
					Rehashing(hashTableUnit, ElementCount(hashTableUnit));
				}
				AddInHashTable(hashTableUnit, value, key);
				ShowHashTable(hashTableUnit);
				break;
			}

			case Delete:
			{
				string key =
					EnterString("������� key ���������� ��������: ");
				vector<KeyValueList*> answer = Search(key, hashTableUnit);
				if (answer.size() == 0)
				{
					cout << "������� �� ������.\n";
					ShowHashTable(hashTableUnit);
					break;
				}
				DeleteFromHashTable(hashTableUnit, key);
				ShowHashTable(hashTableUnit);
				break;
			}

			case Find:
			{
				string key =
					EnterString("������� key �������� ��������: ");
				vector<KeyValueList*> answer = Search(key, hashTableUnit);
				if (answer.size() == 0)
				{
					cout << "������� �� ������.\n";
					ShowHashTable(hashTableUnit);
					break;
				}
				if (answer.size() > 1)
				{
					cout << "��������� ��������:\n";
				}
				else
				{
					cout << "��������� �������:\n";
				}
				
				for (int i = 0; i < answer.size(); i++)
				{
					cout << "Key: " << answer[i]->Key << "\n";
					cout << "Value: " << answer[i]->Value << "\n";
					cout << "\n";
				}
				ShowHashTable(hashTableUnit);
				break;
			}

			case Rehash:
			{
				Rehashing(hashTableUnit, ElementCount(hashTableUnit));
				ShowHashTable(hashTableUnit);
				break;
			}

			case Exit:
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
	for (int i = 0; i < hashTableUnit->ArrayOfLists.size(); i++)
	{
		cout << i;
		PrintKeyValueList(hashTableUnit->ArrayOfLists[i]);
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