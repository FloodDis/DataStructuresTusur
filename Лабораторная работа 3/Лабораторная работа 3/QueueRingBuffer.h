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
/// Функция вывода сообщения Ваш буфер: и очереди на базе кольцевого буфера
/// </summary>
/// <param name="queueRingBufferUnit">экземпляр очереди на базе кольцевого буфера</param>
void ShowQueueRingBuffer(RingBuffer* queueRingBufferUnit);

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