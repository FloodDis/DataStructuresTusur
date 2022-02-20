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
	int index = 0;
	while (hashTableUnit->arrayOfLists[hash]->Key != key && 
		hashTableUnit->arrayOfLists[hash] != nullptr)
	{
		hashTableUnit->arrayOfLists[hash] = 
			hashTableUnit->arrayOfLists[hash]->Next;
		index++;
	}
	if (index == 0)
	{
		hashTableUnit->arrayOfLists[hash]->Key = "";
		hashTableUnit->arrayOfLists[hash]->Value = "";
	}
	else
	{
		KeyValueList* next;
		KeyValueList* previous;
		previous = hashTableUnit->arrayOfLists[hash]->Previous;
		next = hashTableUnit->arrayOfLists[hash]->Next;
		if (previous != nullptr)
			previous->Next = hashTableUnit->arrayOfLists[hash]->Next;
		if (next != nullptr)
			next->Previous = hashTableUnit->arrayOfLists[hash]->Previous;
		free(hashTableUnit->arrayOfLists[hash]);
	}
}

void Rehashing(HashTable*& tableToRehash, double countOfElements)
{
	HashTable* temp;
	InitializationOfHashTable(temp, countOfElements);
	int j = 0;
	for (int i = 0; i < tableToRehash->arrayOfLists.size(); i++)
	{
		KeyValueList* keyValueCopy = new KeyValueList;
		keyValueCopy = tableToRehash->arrayOfLists[i];
		while (keyValueCopy != nullptr)
		{
			temp->arrayOfLists[j] = keyValueCopy;
			j++;
			keyValueCopy = keyValueCopy->Next;
		}
	}
	tableToRehash->arrayOfLists.clear();
	//TODO: to const +
	int newSize = (int)(tableToRehash->GrowthFactor * countOfElements);
	InitializationOfHashTable(tableToRehash, newSize);
	for (int i = 0; i < countOfElements; i++)
	{
		string value = temp->arrayOfLists[i]->Value;
		string key = temp->arrayOfLists[i]->Key;
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
		while (hashTableUnit->arrayOfLists[hash]->Next != nullptr)
		{
			hashTableUnit->arrayOfLists[hash] = 
				hashTableUnit->arrayOfLists[hash]->Next;
		}
		newEndNode->Next = nullptr;
		newEndNode->Previous = hashTableUnit->arrayOfLists[hash];
		newEndNode->Key = key;
		newEndNode->Value = value;
		hashTableUnit->arrayOfLists[hash]->Next = newEndNode;
	}
}

string SearchInHashTable(string searchingKey, HashTable* hashTableUnit)
{
	int hash = 
		HashFunction(searchingKey, hashTableUnit->arrayOfLists.size());
	while (hashTableUnit->arrayOfLists[hash] != nullptr)
	{
		if (hashTableUnit->arrayOfLists[hash]->Key == searchingKey)
		{
			string message = "Элемент Key = ";
			message += hashTableUnit->arrayOfLists[hash]->Key;
			message += " Value = ";
			message += hashTableUnit->arrayOfLists[hash]->Value;
			message += " найден с хешем ";
			message += to_string(hash);
			return message;
		}
		else
		{
			hashTableUnit->arrayOfLists[hash] = 
				hashTableUnit->arrayOfLists[hash]->Next;
		}
	}
	return "Данного значения нет в хеш-таблице";
}

double ElementCount(HashTable* hashTableUnit)
{
	double count = 0;
	for (int i = 0; i < hashTableUnit->arrayOfLists.size(); i++)
	{
		while (hashTableUnit->arrayOfLists[i] != nullptr)
		{
			count++;
			hashTableUnit->arrayOfLists[i] = 
				hashTableUnit->arrayOfLists[i]->Next;
		}
	}
	return count;
}

