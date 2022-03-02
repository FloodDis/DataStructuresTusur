﻿#pragma once
#include "Dictionary.h"
#include "FrequentlyUsed.h"
#include "IOHashTable.h"

///<summary>
///Функция вызова меню словаря
///</summary>
void DictionaryMenu();

//TODO: Несоответствие XML комментариям
/// <summary>
/// Функция вывода словаря
/// </summary>
/// <param name="message">строка с сообщением</param>
void PrintDictionary(HashTable* hashTableUnit);

/// <summary>
/// Функция вывода сообщения Ваш словарь: и словаря 
/// </summary>
/// <param name="hashTableUnit">экземпляр хеш-таблицы</param>
void Show(HashTable* hashTableUnit);