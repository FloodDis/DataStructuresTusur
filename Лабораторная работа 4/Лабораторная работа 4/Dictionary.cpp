#include "Dictionary.h"
#include "HashTable.h"

void AddInDictionary(vector<KeyValueList*> hashTableUnit, string value, string key)
{
	int hash = HashFunction(key, hashTableUnit.size());
	bool match = false;
	KeyValueList* pHead = hashTableUnit[hash];
	while (pHead != nullptr)
	{
		if (pHead->Key == key)
		{
			match = true;
			pHead = pHead->Next;
		}
		else
		{
			pHead = pHead->Next;
		}
	}
	if (match == false)
	{
		AddElementInHashTable(hashTableUnit, value, key);
	}
	else
	{
		while (hashTableUnit[hash]->Key != key)
		{
			hashTableUnit[hash] = hashTableUnit[hash]->Next;
		}
		hashTableUnit[hash]->Value = value;
	}
}

void DeleteFromDictionary(vector<KeyValueList*>& hashTableUnit, string key)
{
	DeleteElementInHashTable(hashTableUnit, key);
}

string SearchInDictionary(vector<KeyValueList*>& hashTableUnit, string key)
{
	return SearchInHashTable(key, hashTableUnit);
}

void InitializationOfDictionary(vector<KeyValueList*>& hashTableUnit, int size)
{
	InitializationOfHashTable(hashTableUnit, size);
}

void EnterNumber(string message, int& value)
{
	cout << message;
	cin >> value;
}

void EnterString(string message, string& value)
{
	cout << message;
	cin >> value;
}

void ShowDictionary(vector<KeyValueList*> hashTableUnit)
{
	cout << "��� �������:\n";
	PrintDictionary(hashTableUnit);
}

void PrintDictionary(vector<KeyValueList*> hashTableUnit)
{
	PrintTable(hashTableUnit);
}