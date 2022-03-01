#pragma once
#include "HashTable.h"
#include "FrequentlyUsed.h"

///<summary>
///Функция вызова меню хеш-таблицы
///</summary>
void HashTableMenu();

/// <summary>
/// Функция вывода хеш-таблицы на экран
/// </summary>
/// <param name="hashTableUnit">экземпляр хеш-таблицы</param>
void PrintTable(HashTable* hashTableUnit);

///<summary>
/// Функция вывода строки Ваша хеш-таблица и хеш-таблицы
/// </summary>
/// <param name="hashTableUnit">экземпляр хеш-таблицы</param>
void ShowHashTable(HashTable* hashTableUnit);

/// <summary>
/// Функция вывода списка коллизий на экран
/// </summary>
/// <param name="listUnit">экзмепляр списка коллизий</param>
void PrintKeyValueList(KeyValueList* listUnit);