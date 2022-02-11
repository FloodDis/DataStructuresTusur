#pragma once
#include <iostream>
#include <vector>
using namespace std;

/// <summary>
/// Узел списка коллизий
/// </summary>
struct KeyValueList
{
	/// <summary>
	/// Ключ
	/// </summary>
	string Key = "";

	/// <summary>
	/// Значение
	/// </summary>
	string Value = "";

	/// <summary>
	/// Указатель на следующий узел
	/// </summary>
	KeyValueList* Next = nullptr;

	/// <summary>
	/// Указатель на предыдущий узел
	/// </summary>
	KeyValueList* Previous = nullptr;
};

/// <summary>
/// Функция инициализации хеш-таблицы
/// </summary>
/// <param name="hashTableUnit">экземпляр хеш-таблицы</param>
/// <param name="size">размер хеш-таблицы</param>
void InitializationOfHashTable(vector<KeyValueList*>& hashTableUnit, int size);

/// <summary>
/// Функция добавления пары ключ-значение в хеш-таблицы
/// </summary>
/// <param name="hashTableUnit">экземпляр хеш-таблицы</param>
/// <param name="value">значение добавляемого элемента</param>
/// <param name="key">ключ добавляемого элемента</param>
void AddElementInHashTable(vector<KeyValueList*> hashTableUnit, string value, string key);

/// <summary>
/// Функция удаления пары ключ-значение из хеш-таблицы
/// </summary>
/// <param name="hashTableUnit">экземпляр хеш-таблицы</param>
/// <param name="key">ключ удаляемой удаляемого элемента</param>
void DeleteElementInHashTable(vector<KeyValueList*> hashTableUnit, string key);

/// <summary>
/// Функция рехешинга
/// </summary>
/// <param name="oldHashTable">экземпляр хеш-таблицы до рехешинга</param>
/// <param name="countOfElements">количество элементов</param>
void Rehashing(vector<KeyValueList*>& oldHashTable, double countOfElements);

/// <summary>
/// Хеш-функция
/// </summary>
/// <param name="key">ключ</param>
/// <param name="size">размер хеш-таблицы</param>
/// <returns></returns>
int HashFunction(string key, int size);

/// <summary>
/// Функция вывода списка коллизий на экран
/// </summary>
/// <param name="listUnit">экзмепляр списка коллизий</param>
void PrintKeyValueList(KeyValueList* listUnit);

/// <summary>
/// Функция вывода хеш-таблицы на экран
/// </summary>
/// <param name="hashTableUnit">экземпляр хеш-таблицы</param>
void PrintTable(vector<KeyValueList*> hashTableUnit);

/// <summary>
/// Функция поиска элемента в хеш-таблицы
/// </summary>
/// <param name="searchingKey">ключ искомого элемента</param>
/// <param name="hashTableUnit">экземпляр хеш-таблицы</param>
/// <returns>строка с ответом</returns>
string SearchInHashTable(string searchingKey, vector<KeyValueList*> hashTableUnit);

///<summary>
/// Функция подсчета элементов
/// </summary>
/// <param name="hashTableUnit">экземпляр хеш-таблицы</param>
/// <returns>количество элементов</returns>
double ElementCount(vector<KeyValueList*> hashTableUnit);
