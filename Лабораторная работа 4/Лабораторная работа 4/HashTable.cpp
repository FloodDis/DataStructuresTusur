#include "HashTable.h"
#include <iostream>
#include <string>
using namespace std;

void InitializationOfHashTable(vector<KeyValueList*>& hashTableUnit, int size)
{
	hashTableUnit.resize(size);
	for (int i = 0; i < size; i++)
	{
		hashTableUnit[i] = new KeyValueList;
	}
}

void DeleteElementInHashTable(vector<KeyValueList*> hashTableUnit, string key)
{
	int hash = HashFunction(key, hashTableUnit.size());
	int index = 0;
	while (hashTableUnit[hash]->Key != key && hashTableUnit[hash] != nullptr)
	{
		hashTableUnit[hash] = hashTableUnit[hash]->Next;
		index++;
	}
	if (index == 0)
	{
		hashTableUnit[hash]->Key = "";
		hashTableUnit[hash]->Value = "";
	}
	else
	{
		KeyValueList* next;
		KeyValueList* previous;
		previous = hashTableUnit[hash]->Previous;
		next = hashTableUnit[hash]->Next;
		if (previous != nullptr)
			previous->Next = hashTableUnit[hash]->Next;
		if (next != nullptr)
			next->Previous = hashTableUnit[hash]->Previous;
		free(hashTableUnit[hash]);
	}
}

void Rehashing(vector<KeyValueList*>& oldHashTable, double countOfElements)
{
	vector<KeyValueList*> temp;
	InitializationOfHashTable(temp, countOfElements);
	int j = 0;
	for (int i = 0; i < oldHashTable.size(); i++)
	{
		KeyValueList* keyValueCopy = new KeyValueList;
		keyValueCopy = oldHashTable[i];
		while (keyValueCopy != nullptr)
		{
			temp[j] = keyValueCopy;
			j++;
			keyValueCopy = keyValueCopy->Next;
		}
	}
	oldHashTable.clear();
	int newSize = (int)(1.5 * countOfElements);
	InitializationOfHashTable(oldHashTable, newSize);
	for (int i = 0; i < countOfElements; i++)
	{
		AddElementInHashTable(oldHashTable, temp[i]->Value, temp[i]->Key);
	}
}

void PrintTable(vector<KeyValueList*> hashTableUnit)
{
	for (int i = 0; i < hashTableUnit.size(); i++)
	{
		cout << i;
		PrintKeyValueList(hashTableUnit[i]);
	}
}

void PrintKeyValueList(KeyValueList* listUnit)
{
	while (listUnit != nullptr)
	{
		cout << " -> " << listUnit->Value << " " << listUnit->Key;
		listUnit = listUnit->Next;
	}
	cout << "\n";
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

void AddElementInHashTable(vector<KeyValueList*> hashTableUnit, string value, string key)
{
	KeyValueList* newEndNode;
	newEndNode = new KeyValueList;
	int hash = HashFunction(key, hashTableUnit.size());
	if (hashTableUnit[hash]->Key == "")
	{
		hashTableUnit[hash]->Key = key;
		hashTableUnit[hash]->Value = value;
	}
	else
	{
		while (hashTableUnit[hash]->Next != nullptr)
		{
			hashTableUnit[hash] = hashTableUnit[hash]->Next;
		}
		newEndNode->Next = nullptr;
		newEndNode->Previous = hashTableUnit[hash];
		newEndNode->Key = key;
		newEndNode->Value = value;
		hashTableUnit[hash]->Next = newEndNode;
	}
}

string SearchInHashTable(string searchingKey, vector<KeyValueList*> hashTableUnit)
{
	string value;
	int hash = HashFunction(searchingKey, hashTableUnit.size());
	while (hashTableUnit[hash] != nullptr)
	{
		if (hashTableUnit[hash]->Key == searchingKey)
		{
			return "Элемент Key = " + hashTableUnit[hash]->Key + " Value = " + hashTableUnit[hash]->Value + " найден с хешем " + to_string(hash);
		}
		else
		{
			hashTableUnit[hash] = hashTableUnit[hash]->Next;
		}
	}
	return "Данного значения нет в хеш-таблице";
}

double ElementCount(vector<KeyValueList*> hashTableUnit)
{
	double count = 0;
	for (int i = 0; i < hashTableUnit.size(); i++)
	{
		while (hashTableUnit[i] != nullptr)
		{
			count++;
			hashTableUnit[i] = hashTableUnit[i]->Next;
		}
	}
	return count;
}

void ShowHashTable(vector<KeyValueList*> hashTableUnit)
{
	cout << "Ваша хэш-таблица:\n";
	PrintTable(hashTableUnit);
}