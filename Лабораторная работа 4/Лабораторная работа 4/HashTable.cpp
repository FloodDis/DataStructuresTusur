#include "HashTable.h"
#include <iostream>
#include <string>
using namespace std;

void InitializationOfHashTable(HashTable*& hashTableUnit, int size)
{
	hashTableUnit->arrayOfLists.resize(size);
	hashTableUnit->Size = size;
	for (int i = 0; i < size; i++)
	{
		hashTableUnit->arrayOfLists[i] = new KeyValueList;
	}
}

void DeleteElementInHashTable(HashTable* hashTableUnit, string key)
{
	int hash = HashFunction(key, hashTableUnit->arrayOfLists.size());
	KeyValueList* buffer = hashTableUnit->arrayOfLists[hash];
	while (buffer->Key != key && buffer != nullptr)
	{
		buffer = buffer->Next;
	}

	if (buffer->Previous == nullptr)
	{
		//TODO: Временные переменные имеют префикс tmp, а не temp,
		//TODO: нужно уточнить, как лучше поступить в этом случае 
		KeyValueList* tempBuffer = buffer;
		buffer = buffer->Next;
		delete tempBuffer;
		tempBuffer = nullptr;
		if (buffer == nullptr)
		{
			hashTableUnit->arrayOfLists[hash] = new KeyValueList;
		}
		else
		{
			hashTableUnit->arrayOfLists[hash] = buffer;
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
	for (int i = 0; i < tableToRehash->arrayOfLists.size(); i++)
	{
		KeyValueList* keyValueCopy = tableToRehash->arrayOfLists[i];
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
	//TODO: to const +
	int oldSize = tableToRehash->Size;
	int newSize = (int)(tableToRehash->GrowthFactor * oldSize);
	tableToRehash->arrayOfLists.clear();
	tableToRehash->Size = 0;
	InitializationOfHashTable(tableToRehash, newSize);
	for (int i = 0; i < countOfElements; i++)
	{
		string value = temp[i].Value;
		string key = temp[i].Key;
		AddElementInHashTable(tableToRehash, value, key);
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

//TODO: длина
void AddElementInHashTable(HashTable* hashTableUnit, string value, string key)
{
	KeyValueList* newEndNode;
	newEndNode = new KeyValueList;
	int hash = HashFunction(key, hashTableUnit->arrayOfLists.size());
	if (hashTableUnit->arrayOfLists[hash]->Key == "")
	{
		hashTableUnit->arrayOfLists[hash]->Key = key;
		hashTableUnit->arrayOfLists[hash]->Value = value;
	}
	else
	{
		KeyValueList* buffer = hashTableUnit->arrayOfLists[hash];
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

string SearchInHashTable(string searchingKey, HashTable* hashTableUnit)
{
	int hash =
		HashFunction(searchingKey, hashTableUnit->arrayOfLists.size());
	KeyValueList* buffer = hashTableUnit->arrayOfLists[hash];
	string message = "";
	while (buffer != nullptr)
	{
		if (buffer->Key == searchingKey)
		{
			message += "Элемент Key = ";
			message += buffer->Key;
			message += " Value = ";
			message += buffer->Value;
			message += " найден с хешем ";
			message += to_string(hash) + "\n";
			buffer = buffer->Next;
		}
		else
		{
			buffer = buffer->Next;
		}
	}
	return message;
}

double ElementCount(HashTable* hashTableUnit)
{
	double count = 0;
	for (int i = 0; i < hashTableUnit->arrayOfLists.size(); i++)
	{
		KeyValueList* buffer = hashTableUnit->arrayOfLists[i];
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

