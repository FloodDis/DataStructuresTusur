#pragma once
#include "RingBuffer.h"

/// <summary>
/// Очередь на базе кольцевого буфера
/// </summary>
struct QueueRingBufferBased
{
	/// <summary>
	/// Кольцевой буфер
	/// </summary>
	RingBuffer ringBuffer;
};

/// <summary>
/// Функция создания очереди на базе кольцевого буфера
/// </summary>
/// <param name="sizeOfQueue">размер очереди</param>
/// <returns>экземпляр очереди</returns>
RingBuffer* CreationOfQueue(int sizeOfQueue);

/// <summary>
/// Функция добавления элемента в очередь
/// </summary>
/// <param name="queueRingBufferUnit">указатель на экземпляр структуры</param>
/// <param name="value">значение нового элемента</param>
void EnqueueRingBuffer(RingBuffer*& queueRingBufferUnit, int value);

/// <summary>
/// Функция удаления элемента из очереди
/// </summary>
/// <param name="queueRingBufferUnit">указатель на экземпляр структуры</param>
/// <returns>значение извлеченного элемента</returns>
int DequeueRingBuffer(RingBuffer*& queueRingBufferUnit);

/// <summary>
/// Функция удаления очереди
/// </summary>
/// <param name="queueRingBufferUnit">указатель на экземпляр структуры</param>
void DeleteQueueRingBuffer(RingBuffer*& queueRingBufferUnit);

/// <summary>
/// Функция вывода очереди на экран
/// </summary>
/// <param name="queueRingBufferUnit">указатель на экземпляр структуры</param>
void PrintQueueRingBuffer(RingBuffer* queueRingBufferUnit);

/// <summary>
/// Функция ввода числа и вывода сообщения
/// </summary>
/// <param name="message">строка с сообщением</param>
/// <param name="value">значение числа</param>
void EnterNumber(string message, int& value);