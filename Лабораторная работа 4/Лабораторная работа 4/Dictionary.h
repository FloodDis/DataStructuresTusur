#pragma once
#include "HashTable.h"

/// <summary>
/// Словарь
/// </summary>
struct Dictionary
{
	/// <summary>
	/// Хеш-таблица
	/// </summary>
	HashTable* HashTable;
};

/// <summary>
/// Функция инициализации словаря
/// </summary>
/// <param name="hashTableUnit">ссылка на экземпляр хэш-таблицы</param>
/// <param name="size">размер словаря</param>
void InitializeDictionary(HashTable*& hashTableUnit, int size);

/// <summary>
/// Функция добавления пары ключ-значение в словарь
/// </summary>
/// <param name="hashTableUnit">экземпляр хеш-таблицы</param>
/// <param name="value">значение добавляемого элемента</param>
/// <param name="key">ключ добавляемого элемента</param>
void Add(HashTable* hashTableUnit, string value, string key);

/// <summary>
/// Функция удаления пары ключ-значение из словаря
/// </summary>
/// <param name="hashTableUnit">экземпляр хеш-таблицы</param>
/// <param name="key">ключ удаляемого элемента</param>
void Delete(HashTable*& hashTableUnit, string key);

/// <summary>
/// Функция поиска пары ключ-значение в словаре
/// </summary>
/// <param name="hashTableUnit">экземпляр хеш-таблицы</param>
/// <param name="key">ключ искомого элемента</param>
string Find(HashTable*& hashTableUnit, string key);