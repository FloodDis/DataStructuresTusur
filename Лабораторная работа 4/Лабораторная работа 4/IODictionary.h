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
void Print(HashTable* hashTableUnit);

/// <summary>
/// Функция вывода сообщения Ваш словарь: и словаря 
/// </summary>
/// <param name="hashTableUnit">экземпляр хеш-таблицы</param>
void Show(HashTable* hashTableUnit);