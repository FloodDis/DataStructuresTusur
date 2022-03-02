#pragma once
#include "QueueRingBuffer.h"
#include "FrequentlyUsed.h"

/// <summary>
/// Функция меню очереди на базе кольцевого буфера
/// </summary>
void QueueRingBufferMenu();

/// <summary>
/// Функция вывода очереди на экран
/// </summary>
/// <param name="queueRingBufferUnit">
///указатель на экземпляр структуры
///</param>
void PrintQueue(RingBuffer* queueRingBufferUnit);

/// <summary>
/// Функция вывода сообщения Ваш буфер: 
/// и очереди на базе кольцевого буфера
/// </summary> 
/// <param name="queueRingBufferUnit">
///экземпляр очереди на базе кольцевого буфера
/// </param>
void ShowQueue(RingBuffer* queueRingBufferUnit);