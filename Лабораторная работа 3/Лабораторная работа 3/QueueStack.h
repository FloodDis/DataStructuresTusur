#pragma once
#include "Stack.h"

/// <summary>
/// Очередь на базе двух стеков
/// </summary>
struct QueueStackBased
{
	/// <summary>
	/// Стек, в который помещаются элементы  очереди
	/// </summary>
	Node* StackIn;

	/// <summary>
	/// Стек, из которого извлекаются элементы очереди
	/// </summary>
	Node* StackOut;

	/// <summary>
	/// true - StackIn пуст, false - StackIn не пуст
	/// </summary>
	bool IsStackInEmpty = true;

	/// <summary>
	/// true - StackOut пуст, false - StackOut не пуст
	/// </summary>
	bool IsStackOutEmpty = true;
};

/// <summary>
/// Функция создания очереди на базе двух стеков
/// </summary>
/// <param name="queueStackUnit">указатель на экземпляр создаваемой структуры</param>
void CreationOfQueueStackBased(QueueStackBased*& queueStackUnit);

/// <summary>
/// Фукнция добавления элемента в очередь
/// </summary>
/// <param name="queueStackUnit">указатель на экземпляр структуры</param>
/// <param name="dataOfElement">значение нового элемента</param>
void EnqueueStackBased(QueueStackBased*& queueStackUnit, int dataOfElement);

/// <summary>
/// Функция взятия элемента из очереди
/// </summary>
/// <param name="queueStackUnit">указатель на экземпляр структуры</param>
/// <returns>значение извлекаемого элемента</returns>
int DequeueStackBased(QueueStackBased*& queueStackUnit);

/// <summary>
/// Функция удаления очереди
/// </summary>
/// <param name="queueStackUnit">указатель на экземпляр очереди</param>
void DeleteQueueStackBased(QueueStackBased*& queueStackUnit);


