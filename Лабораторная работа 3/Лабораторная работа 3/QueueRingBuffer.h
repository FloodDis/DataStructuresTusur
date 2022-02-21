#pragma once
#include "RingBuffer.h"


/// <summary>
/// Очередь на базе кольцевого буфера
/// </summary>
struct QueueRingBuffer
{
	//TODO: RSDN
	/// <summary>
	/// Кольцевой буфер
	/// </summary>
	RingBuffer* ringBuffer;
};

/// <summary>
/// Функция создания очереди на базе кольцевого буфера
/// </summary>
/// <param name="sizeOfQueue">размер очереди</param>
/// <returns>экземпляр очереди</returns>
RingBuffer* CreateQueue(int sizeOfQueue);

/// <summary>
/// Функция добавления элемента в очередь
/// </summary>
/// <param name="queueRingBufferUnit">указатель на экземпляр структуры</param>
/// <param name="value">значение нового элемента</param>
void Enqueue(RingBuffer*& queueRingBufferUnit, int value);

/// <summary>
/// Функция удаления элемента из очереди
/// </summary>
/// <param name="queueRingBufferUnit">указатель на экземпляр структуры</param>
/// <returns>значение извлеченного элемента</returns>
int Dequeue(RingBuffer*& queueRingBufferUnit);

/// <summary>
/// Функция удаления очереди
/// </summary>
/// <param name="queueRingBufferUnit">
///указатель на экземпляр структуры
/// </param>
void DeleteQueue(RingBuffer*& queueRingBufferUnit);

/// <summary>
/// Функция проверки очреди на пустоту
/// </summary>
/// <param name="queueRingBufferUnit">
/// экземпляр очереди на базе кольцевого буфера
/// </param>
/// <returns>
/// true - очередь пуста, false - очередь не пуста
/// </returns>
bool IsEmpty(RingBuffer* queueRingBufferUnit);

///<summary>
///Функция проверки очереди на заполненность
/// </summary>
/// <param name="queueRingBufferUnit">экземпляр очереди на базе кольцевого буфера</param>
/// <returns>
/// true - очередь заполнена, false - очередь не заполнена
/// </returns>
bool IsFull(RingBuffer* queueRingBufferUnit);