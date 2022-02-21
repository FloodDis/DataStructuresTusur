#pragma once
#include "QueueRingBuffer.h"
#include "FrequentlyUsed.h"

void QueueRingBufferMenu();

/// <summary>
/// ‘ункци€ вывода очереди на экран
/// </summary>
/// <param name="queueRingBufferUnit">
///указатель на экземпл€р структуры
///</param>
void PrintQueue(RingBuffer* queueRingBufferUnit);

/// <summary>
/// ‘ункци€ вывода сообщени€ ¬аш буфер: 
/// и очереди на базе кольцевого буфера
/// </summary> 
/// <param name="queueRingBufferUnit">
///экземпл€р очереди на базе кольцевого буфера
/// </param>
void ShowQueue(RingBuffer* queueRingBufferUnit);