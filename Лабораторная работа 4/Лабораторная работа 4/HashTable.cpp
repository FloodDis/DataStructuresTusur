#include "HashTable.h"
#include <iostream>
#include <string>
using namespace std;

void InitializeHashTable(HashTable*& hashTableUnit, int size)
{
	hashTableUnit->ArrayOfLists.resize(size);
	hashTableUnit->Size = size;
	for (int i = 0; i < size; i++)
	{
		hashTableUnit->ArrayOfLists[i] = new KeyValueList;
	}
}

void DeleteFromHashTable(HashTable* hashTableUnit, string key)
{
	int hash = HashFunction(key, hashTableUnit->ArrayOfLists.size());
	KeyValueList* buffer = hashTableUnit->ArrayOfLists[hash];
	while (buffer->Key != key && buffer != nullptr)
	{
		buffer = buffer->Next;
	}

	if (buffer->Previous == nullptr)
	{
		KeyValueList* tmpBuffer = buffer;
		buffer = buffer->Next;
		delete tmpBuffer;
		tmpBuffer = nullptr;
		if (buffer == nullptr)
		{
			hashTableUnit->ArrayOfLists[hash] = new KeyValueList;
		}
		else
		{
			hashTableUnit->ArrayOfLists[hash] = buffer;
			buffer = nullptr;
		}
	}
	else
	{
		KeyValueList* next;
		KeyValueList* previous;
		previous = buffer->Previous;
		next = buffer->Next;
		if (previous != nullptr)
		{
			previous->Next = buffer->Next;
		}
		if (next != nullptr)
		{
			next->Previous = buffer->Previous;
		}
		free(buffer);
	}
}

void Rehashing(HashTable*& tableToRehash, double countOfElements)
{
	vector<KeyValueList> temp;
	int j = 0;
	for (int i = 0; i < tableToRehash->ArrayOfLists.size(); i++)
	{
		KeyValueList* keyValueCopy = tableToRehash->ArrayOfLists[i];
		while (keyValueCopy != nullptr)
		{
			if (keyValueCopy->Key != "")
			{
				temp.resize(j + 1);
				temp[j].Key = keyValueCopy->Key;
				temp[j].Value = keyValueCopy->Value;
				j++;
			}
			keyValueCopy = keyValueCopy->Next;
		}
		delete keyValueCopy;
		keyValueCopy = nullptr;
	}
	int oldSize = tableToRehash->Size;
	int newSize = (int)(tableToRehash->GrowthFactor * oldSize);
	tableToRehash->ArrayOfLists.clear();
	tableToRehash->Size = 0;
	InitializeHashTable(tableToRehash, newSize);
	for (int i = 0; i < countOfElements; i++)
	{
		string value = temp[i].Value;
		string key = temp[i].Key;
		AddInHashTable(tableToRehash, value, key);
	}
}

int HashFunction(string key, int size)
{
	int hash = 0;
	for (int i = 0; i < key.length(); i++)
	{
		hash += key[i] * pow(3, i);
	}
	return hash % size;
}

void AddInHashTable(HashTable* hashTableUnit, string value, string key)
{
	//TODO: RSDN +
	KeyValueList* newEndNode = new KeyValueList;
	int hash = HashFunction(key, hashTableUnit->ArrayOfLists.size());
	if (hashTableUnit->ArrayOfLists[hash]->Key == "")
	{
		hashTableUnit->ArrayOfLists[hash]->Key = key;
		hashTableUnit->ArrayOfLists[hash]->Value = value;
	}
	else
	{
		KeyValueList* buffer = hashTableUnit->ArrayOfLists[hash];
		while (buffer->Next != nullptr)
		{
			buffer = buffer->Next;
		}
		newEndNode->Next = nullptr;
		newEndNode->Previous = buffer;
		newEndNode->Key = key;
		newEndNode->Value = value;
		buffer->Next = newEndNode;
	}
}

//TODO: убрать строку
vector<KeyValueList*> Search(string searchingKey, HashTable* hashTableUnit)
{
	int hash =
		HashFunction(searchingKey, hashTableUnit->ArrayOfLists.size());
	KeyValueList* buffer = hashTableUnit->ArrayOfLists[hash];
	vector<KeyValueList*> temp;
	int j = 0;
	while (buffer != nullptr)
	{
		if (buffer->Key == searchingKey)
		{
			temp.resize(j + 1);
			temp[j] = buffer;
			j++;
			buffer = buffer->Next;
		}
		else
		{
			buffer = buffer->Next;
		}
	}
	return temp;
}

double ElementCount(HashTable* hashTableUnit)
{
	double count = 0;
	for (int i = 0; i < hashTableUnit->ArrayOfLists.size(); i++)
	{
		KeyValueList* buffer = hashTableUnit->ArrayOfLists[i];
		while (buffer != nullptr)
		{
			if (buffer->Key != "")
			{
				count++;
			}
			buffer = buffer->Next;
		}
	}
	return count;
}