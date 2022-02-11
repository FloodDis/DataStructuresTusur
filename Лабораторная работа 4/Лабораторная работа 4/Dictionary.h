#pragma once
#include "HashTable.h"

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
