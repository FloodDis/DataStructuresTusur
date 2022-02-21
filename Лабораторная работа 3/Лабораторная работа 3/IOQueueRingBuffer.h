#pragma once
#include "QueueRingBuffer.h"
#include "FrequentlyUsed.h"

void QueueRingBufferMenu();

/// <summary>
/// ‘ункци€ вывода очереди на экран
/// </summary>
//TODO: длина
/// <param name="queueRingBufferUnit">указатель на экземпл€р структуры</param>
void PrintQueueRingBuffer(RingBuffer* queueRingBufferUnit);

/// <summary>
//TODO: длина
/// ‘ункци€ вывода сообщени€ ¬аш буфер: и очереди на базе кольцевого буфера
/// </summary> 
//TODO: длина
/// <param name="queueRingBufferUnit">экземпл€р очереди на базе кольцевого буфера</param>
void ShowQueueRingBuffer(RingBuffer* queueRingBufferUnit);