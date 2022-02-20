#pragma once
#include "HashTable.h"
#include "FrequentlyUsed.h"

///<summary>
///‘ункци€ вызова меню хеш-таблицы
///</summary>
void HashTableMenu();

/// <summary>
/// ‘ункци€ вывода хеш-таблицы на экран
/// </summary>
/// <param name="hashTableUnit">экземпл€р хеш-таблицы</param>
void PrintTable(vector<KeyValueList*> hashTableUnit);

///<summary>
/// ‘ункци€ вывода строки ¬аша хеш-таблица и хеш-таблицы
/// </summary>
/// <param name="hashTableUnit">экземпл€р хеш-таблицы</param>
void ShowHashTable(vector<KeyValueList*> hashTableUnit);

/// <summary>
/// ‘ункци€ вывода списка коллизий на экран
/// </summary>
/// <param name="listUnit">экзмепл€р списка коллизий</param>
void PrintKeyValueList(KeyValueList* listUnit);