#include "IOHashTable.h"

void HashTableMenu()
{
	vector<KeyValueList*> hashTableUnit;
	setlocale(LC_ALL, "ru");
	int size;
	EnterNumber("������� ������ ���-�������:\n", size);
	InitializationOfHashTable(hashTableUnit, size);
	ShowHashTable(hashTableUnit);
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