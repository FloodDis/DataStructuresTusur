#include "Dictionary.h"
#include "HashTable.h"

void Add(HashTable* hashTableUnit, string value, string key)
{
	int hash = HashFunction(key, hashTableUnit->ArrayOfLists.size());
	bool match = false;
	KeyValueList* bufferHead = hashTableUnit->ArrayOfLists[hash];
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
		bufferHead = hashTableUnit->ArrayOfLists[hash];
		while (bufferHead != nullptr)
		{
			if (bufferHead->Key == key)
			{
				bufferHead->Value = value;
				bufferHead = bufferHead->Next;
			}
			else
			{
				bufferHead = bufferHead->Next;
			}
		}
	}
}

void Delete(HashTable*& hashTableUnit, string key)
{
	Delete(hashTableUnit, key);
}

vector<KeyValueList*> Find(HashTable*& hashTableUnit, string key)
{
	return Search(key, hashTableUnit);
}

void InitializeDictionary(HashTable*& hashTableUnit, int size)
{
	InitializeHashTable(hashTableUnit, size);
}