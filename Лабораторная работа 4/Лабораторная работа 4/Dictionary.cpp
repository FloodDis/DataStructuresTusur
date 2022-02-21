#include "Dictionary.h"
#include "HashTable.h"

void Add(HashTable* hashTableUnit, string value, string key)
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
		AddInHashTable(hashTableUnit, value, key);
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

void Delete(HashTable*& hashTableUnit, string key)
{
	Delete(hashTableUnit, key);
}

string Find(HashTable*& hashTableUnit, string key)
{
	return Search(key, hashTableUnit);
}

void InitializeDictionary(HashTable*& hashTableUnit, int size)
{
	InitializeHashTable(hashTableUnit, size);
}