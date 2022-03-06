#pragma once
#include "RedBlackTree.h"
#include "AVLTree.h"
#include "Vector.h"
#include "Vector.cpp"
#include "Stopwatch.h"
#include <sstream>

using namespace std;

/// <summary>
/// Получить результаты измерений производительности для АВЛ-дерева.
/// </summary>
/// <param name="tree">
/// Тип дерева производительность операций которого надо замерить.
/// </param>
/// <returns>Результаты измерений в виде строки.</returns>
string GetTreePerformanceMeasurementAVL(AVLTree* tree);

/// <summary>
/// Получить результаты измерений производительности 
/// для Красно-черного дерева.
/// </summary>
/// <param name="tree">
/// Тип дерева производительность операций которого надо замерить.
/// </param>
/// <returns>Результаты измерений в виде строки.</returns>
string GetTreePerformanceMeasurementRB(RBTree* tree);

/// <summary>
/// Измерить среднеезначение времени выполнения
/// для заданной операции АВЛ-дерева.
/// </summary>
/// <param name="operationName">Название операции.</param>
/// <param name="tree">
/// дерево производительность операции которого надо изменить
/// </param>
/// <param name="keys">
/// массив ключей хранящихся в момент вызова функции в дереве.
/// </param>
/// <returns>Время затраченное на выполнение в наносекундах.</returns>
long long GetAverageExecutionTimeOfAVL(string operationName, 
	AVLTree* tree, Vector<int>& keys);

/// <summary>
/// Измерить среднеезначение времени выполнения
/// для заданной операции АВЛ-дерева.
/// </summary>
/// <param name="operationName">Название операции.</param>
/// <param name="tree">
/// дерево производительность операции которого надо изменить
/// </param>
/// <param name="keys">
/// массив ключей хранящихся в момент вызова функции в дереве.
/// </param>
/// <returns>Время затраченное на выполнение в наносекундах.</returns>
long long GetAverageExecutionTimeOfRB(string operationName,
	RBTree* tree, Vector<int>& keys);