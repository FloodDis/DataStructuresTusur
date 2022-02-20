#include "Dictionary.h"
#include "HashTable.h"

void AddInDictionary(HashTable* hashTableUnit, string value, string key)
{
	int hash = HashFunction(key, hashTableUnit->arrayOfLists.size());
	bool match = false;
	KeyValueList* bufferHead = hashTableUnit->arrayOfLists[hash];
	while (bufferHead != nullptr)
	{
		if (bufferHead->Key == key)
		{
			match = true;
			bufferHead = bufferHead->Next;
		}
		else
		{
			bufferHead = bufferHead->Next;
		}
	}
	if (!match)
	{
		AddElementInHashTable(hashTableUnit, value, key);
	}
	else
	{
		while (hashTableUnit->arrayOfLists[hash]->Key != key)
		{
			hashTableUnit->arrayOfLists[hash] = 
				hashTableUnit->arrayOfLists[hash]->Next;
		}
		hashTableUnit->arrayOfLists[hash]->Value = value;
	}
}

void DeleteFromDictionary(HashTable*& hashTableUnit, string key)
{
	DeleteElementInHashTable(hashTableUnit, key);
}

string SearchInDictionary(HashTable*& hashTableUnit, string key)
{
	return SearchInHashTable(key, hashTableUnit);
}

void InitializationOfDictionary(HashTable*& hashTableUnit, int size)
{
	InitializationOfHashTable(hashTableUnit, size);
}

void ShowDictionary(HashTable* hashTableUnit)
{
	cout << "Ваш словарь:\n";
	PrintDictionary(hashTableUnit);
}

void PrintDictionary(HashTable* hashTableUnit)
{
	PrintTable(hashTableUnit);
}