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
//TODO: см. PopFromStack
RingBuffer* CreationOfQueue(int sizeOfQueue);

/// <summary>
/// Функция добавления элемента в очередь
/// </summary>
/// <param name="queueRingBufferUnit">указатель на экземпляр структуры</param>
/// <param name="value">значение нового элемента</param>
//TODO: см. PopFromStack
void EnqueueRingBuffer(RingBuffer*& queueRingBufferUnit, int value);

/// <summary>
/// Функция удаления элемента из очереди
/// </summary>
/// <param name="queueRingBufferUnit">указатель на экземпляр структуры</param>
/// <returns>значение извлеченного элемента</returns>
//TODO: см. PopFromStack
int DequeueRingBuffer(RingBuffer*& queueRingBufferUnit);

/// <summary>
/// Функция удаления очереди
/// </summary>
//TODO: длина строки
/// <param name="queueRingBufferUnit">указатель на экземпляр структуры</param>
//TODO: см. PopFromStack
void DeleteQueueRingBuffer(RingBuffer*& queueRingBufferUnit);



/// <summary>
/// Функция проверки очреди на пустоту
/// </summary>
/// <param name="queueRingBufferUnit">экземпляр очереди на базе кольцевого буфера</param>
/// <returns>
/// true - очередь пуста, false - очередь не пуста
/// </returns>
bool IsQueueRingBufferEmpty(RingBuffer* queueRingBufferUnit);

///<summary>
///Функция проверки очереди на заполненность
/// </summary>
/// <param name="queueRingBufferUnit">экземпляр очереди на базе кольцевого буфера</param>
/// <returns>
/// true - очередь заполнена, false - очередь не заполнена
/// </returns>
bool IsQueueRingBufferFull(RingBuffer* queueRingBufferUnit);