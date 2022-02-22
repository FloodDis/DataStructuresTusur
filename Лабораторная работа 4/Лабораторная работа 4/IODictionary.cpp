#include "IODictionary.h"

void DictionaryMenu()
{
	/// <summary>
	/// �������� ��� ��������
	/// </summary>
	enum Actions
	{
		/// <summary>
		/// �������� �������
		/// </summary>
		AddElement = 1,

		/// <summary>
		/// ������� �������
		/// </summary>
		DeleteElement,

		/// <summary>
		/// ����� �������
		/// </summary>
		FindElement,

		/// <summary>
		/// �������������� �������
		/// </summary>
		Rehash,

		/// <summary>
		/// ����� � ������� ����
		/// </summary>
		Exit
	};
	Dictionary* dictionaryUnit = new Dictionary;
	dictionaryUnit->HashTable = new HashTable;
	setlocale(LC_ALL, "ru");
	int size = EnterNumber("������� ������ �������:\n");
	InitializeDictionary(dictionaryUnit->HashTable, size);
	Show(dictionaryUnit->HashTable);

	while (true)
	{
		cout << "�������� ��������:\n"
			<< "1) �������� �������\n"
			<< "2) ������� �������\n"
			<< "3) ����� ��������\n"
			<< "4) ��������\n"
			<< "5) �����\n";
		int option = EnterNumber("");
		switch (option)
		{
			case AddElement:
			{
				string value = EnterString("������� �������� value: ");
				string key = EnterString("������� �������� key: ");
				double size =
					dictionaryUnit->HashTable->ArrayOfLists.size();
				double fillFactor =
					ElementCount(dictionaryUnit->HashTable) / size;
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

			case DeleteElement:
			{
				string key =
					EnterString("������� key ���������� ��������: ");
				vector<KeyValueList*> answer =
					Find(dictionaryUnit->HashTable, key);
				if (answer.size() == 0)
				{
					cout << "������� �� ������.\n";
					Show(dictionaryUnit->HashTable);
					break;
				}
				Delete(dictionaryUnit->HashTable, key);
				Show(dictionaryUnit->HashTable);
				break;
			}

			case FindElement:
			{
				string key =
					EnterString("������� key �������� ��������: ");
				vector<KeyValueList*> answer =
					Find(dictionaryUnit->HashTable, key);
				if (answer.size() == 0)
				{
					cout << "������� �� ������.\n";
					Show(dictionaryUnit->HashTable);
					break;
				}
				else
				{
					cout << "��������� �������:\n";
					cout << "Key: " << answer[0]->Key << "\n";
					cout << "Value: " << answer[0]->Value << "\n";
					Show(dictionaryUnit->HashTable);
					break;
				}
			}

			case Rehash:
			{
				int elementCount = ElementCount(dictionaryUnit->HashTable);
				Rehashing(dictionaryUnit->HashTable, elementCount);
				Show(dictionaryUnit->HashTable);
				break;
			}

			case Exit:
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

void Show(HashTable* hashTableUnit)
{
	cout << "��� �������:\n";
	PrintDictionary(hashTableUnit);
}

void PrintDictionary(HashTable* hashTableUnit)
{
	PrintTable(hashTableUnit);
}