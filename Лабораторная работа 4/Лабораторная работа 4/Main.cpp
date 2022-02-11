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
	vector<KeyValueList*> hashTableUnit;
	setlocale(LC_ALL, "ru");
	int size;
	printf("������� ������ �������:\n");
	cin >> size;
	InitializationOfHashTable(hashTableUnit, size);
	printf("\n��� �������:\n");
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
			string value, key;
			double size = hashTableUnit.size();
			printf("������� �������� value: ");
			cin >> value;
			printf("������� �������� key: ");
			cin >> key;
			if (ElementCount(hashTableUnit) / size >= 1.5)
			{
				Rehashing(hashTableUnit, ElementCount(hashTableUnit));
			}
			AddInDictionary(hashTableUnit, value, key);
			printf("\n��� �������:\n");
			PrintTable(hashTableUnit);
			break;
		}
		case 2:
		{
			string key;
			printf("������� key ���������� ��������: ");
			cin >> key;
			DeleteFromDictionary(hashTableUnit, key);
			printf("\n��� �������:\n");
			PrintTable(hashTableUnit);
			break;
		}
		case 3:
		{
			string key;
			string answer;
			printf("������� key �������� ��������: ");
			cin >> key;
			answer = SearchInDictionary(hashTableUnit, key);
			cout << answer;
			printf("\n��� �������:\n");
			PrintTable(hashTableUnit);
			break;
		}
		case 4:
		{
			Rehashing(hashTableUnit, ElementCount(hashTableUnit));
			printf("��� �������:\n");
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

void HashTableMenu()
{
	vector<KeyValueList*> hashTableUnit;
	setlocale(LC_ALL, "ru");
	int size;
	printf("������� ������ ���-�������:\n");
	cin >> size;
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
			printf("������� �������� value: ");
			cin >> value;
			printf("������� �������� key: ");
			cin >> key;
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
			printf("������� key ���������� ��������: ");
			cin >> key;
			DeleteElementInHashTable(hashTableUnit, key);
			printf("\n���� ���-�������:\n");
			PrintTable(hashTableUnit);
			break;
		}
		case 3:
		{
			string key;
			string answer;
			printf("������� key �������� ��������: ");
			cin >> key;
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