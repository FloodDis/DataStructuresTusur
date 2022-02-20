#pragma once
#include <iostream>
#include <vector>
using namespace std;

//TODO: в отдельную HashTable +

/// <summary>
/// Хеш-таблица
/// </summary>
struct HashTable
{
	/// <summary>
	/// Вектор, состоящий из списков коллизий
	/// </summary>
	vector<KeyValueList*> arrayOfLists;

	/// <summary>
	/// Фактор роста хеш-таблицы
	/// </summary>
	const float GrowthFactor = 1.5;

	/// <summary>
	/// Максимальный коэффициент заполнения
	/// </summary>
	const float MaxFillFactor = 0.9;

	/// <summary>
	/// Размер хеш-таблицы
	/// </summary>
	int Size = arrayOfLists.size();
};

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