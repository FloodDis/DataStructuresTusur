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
/// Хеш-таблица
/// </summary>
struct HashTable
{
	/// <summary>
	/// Вектор, состоящий из списков коллизий
	/// </summary>
	vector<KeyValueList*> ArrayOfLists;

	/// <summary>
	/// Фактор роста хеш-таблицы
	/// </summary>
	const float GrowthFactor = 1.5f;

	/// <summary>
	/// Максимальный коэффициент заполнения
	/// </summary>
	const float MaxFillFactor = 0.9f;

	/// <summary>
	/// Размер хеш-таблицы
	/// </summary>
	int Size = 0;
};

/// <summary>
/// Функция инициализации хеш-таблицы
/// </summary>
/// <param name="hashTableUnit">экземпляр хеш-таблицы</param>
/// <param name="size">размер хеш-таблицы</param>
void InitializeHashTable(HashTable*& hashTableUnit, int size);

/// <summary>
/// Функция добавления пары ключ-значение в хеш-таблицы
/// </summary>
/// <param name="hashTableUnit">экземпляр хеш-таблицы</param>
/// <param name="value">значение добавляемого элемента</param>
/// <param name="key">ключ добавляемого элемента</param>
void AddInHashTable(HashTable* hashTableUnit, string value, string key);

/// <summary>
/// Функция удаления пары ключ-значение из хеш-таблицы
/// </summary>
/// <param name="hashTableUnit">экземпляр хеш-таблицы</param>
/// <param name="key">ключ удаляемой удаляемого элемента</param>
void DeleteFromHashTable(HashTable* hashTableUnit, string key);

/// <summary>
/// Функция рехешинга
/// </summary>
/// <param name="oldHashTable">экземпляр хеш-таблицы до рехешинга</param>
/// <param name="countOfElements">количество элементов</param>
void Rehashing(HashTable*& tableToRehash, double countOfElements);

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
vector<KeyValueList*> Search(string searchingKey, HashTable* hashTableUnit);

///<summary>
/// Функция подсчета элементов
/// </summary>
/// <param name="hashTableUnit">экземпляр хеш-таблицы</param>
/// <returns>количество элементов</returns>
double ElementCount(HashTable* hashTableUnit);