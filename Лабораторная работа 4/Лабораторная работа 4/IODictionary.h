#pragma once
#include "Dictionary.h"
#include "FrequentlyUsed.h"
#include "IOHashTable.h"

///<summary>
///Функция вызова меню словаря
///</summary>
void DictionaryMenu();

/// <summary>
/// Функция вывода словаря
/// </summary>
/// <param name="message">строка с сообщением</param>
//TODO: Именование методов, см. лаб 3
//TODO: Передаваемый параметр должен называться dictionary
void PrintDictionary(HashTable* hashTableUnit);

/// <summary>
/// Функция вывода сообщения Ваш словарь: и словаря 
/// </summary>
/// <param name="hashTableUnit">экземпляр хеш-таблицы</param>
//TODO: Именование методов, см. лаб 3
//TODO: Передаваемый параметр должен называться dictionary
void ShowDictionary(HashTable* hashTableUnit);