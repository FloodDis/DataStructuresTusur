﻿#pragma once
#include "HashTable.h"

/// <summary>
/// Словарь
/// </summary>
struct Dictionary
{
	/// <summary>
	/// Хэш-таблица
	/// </summary>
	vector<KeyValueList*> HashTable;
};

/// <summary>
/// Функция инициализации словаря
/// </summary>
/// <param name="hashTableUnit">ссылка на экземпляр хэш-таблицы</param>
/// <param name="size">размер словаря</param>
void InitializationOfDictionary(vector<KeyValueList*>& hashTableUnit, int size);

/// <summary>
/// Функция добавления пары ключ-значение в словарь
/// </summary>
/// <param name="hashTableUnit">экземпляр хеш-таблицы</param>
/// <param name="value">значение добавляемого элемента</param>
/// <param name="key">ключ добавляемого элемента</param>
void AddInDictionary(vector<KeyValueList*> hashTableUnit, string value, string key);

/// <summary>
/// Функция удаления пары ключ-значение из словаря
/// </summary>
/// <param name="hashTableUnit">экземпляр хеш-таблицы</param>
/// <param name="key">ключ удаляемого элемента</param>
void DeleteFromDictionary(vector<KeyValueList*>& hashTableUnit, string key);

/// <summary>
/// Функция поиска пары ключ-значение в словаре
/// </summary>
/// <param name="hashTableUnit">экземпляр хеш-таблицы</param>
/// <param name="key">ключ искомого элемента</param>
string SearchInDictionary(vector<KeyValueList*>& hashTableUnit, string key);

/// <summary>
/// Функция вывода словаря
/// </summary>
/// <param name="message">строка с сообщением</param>
void PrintDictionary(vector<KeyValueList*> hashTableUnit);

/// <summary>
/// Функция вывода сообщения Ваш словарь: и словаря 
/// </summary>
/// <param name="hashTableUnit">экземпляр хэш-таблицы</param>
void ShowDictionary(vector<KeyValueList*> hashTableUnit);