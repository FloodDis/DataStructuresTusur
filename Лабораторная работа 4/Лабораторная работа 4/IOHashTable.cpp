#include "IOHashTable.h"

void HashTableMenu()
{
	setlocale(LC_ALL, "ru");
	vector<KeyValueList*> hashTableUnit;
	int size = EnterNumber("������� ������ ���-�������:\n");
	InitializationOfHashTable(hashTableUnit, size);
	ShowHashTable(hashTableUnit);
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
				string value;
				string key;
				EnterString("������� �������� value: ", value);
				EnterString("������� �������� key: ", key);
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
				string key;
				EnterString("������� key ���������� ��������: ", key);
				DeleteElementInHashTable(hashTableUnit, key);
				ShowHashTable(hashTableUnit);
				break;
			}

			case 3:
			{
				string key;
				string answer;
				EnterString("������� key �������� ��������: ", key);
				answer = SearchInHashTable(key, hashTableUnit);
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