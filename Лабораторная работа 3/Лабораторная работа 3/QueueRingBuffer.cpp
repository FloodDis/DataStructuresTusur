﻿#include "QueueRingBuffer.h"

RingBuffer* CreationOfQueue(int sizeOfQueue)
{
	RingBuffer* QueueRingBuffer = InitializationOfRingBuffer(sizeOfQueue);
	return QueueRingBuffer;
}

void EnqueueRingBuffer(RingBuffer*& queueRingBufferUnit, int value)
{
	PushInRingBuffer(queueRingBufferUnit, value);
}

int DequeueRingBuffer(RingBuffer*& queueRingBufferUnit)
{
	return PopFromRingBuffer(queueRingBufferUnit);
}

void DeleteQueueRingBuffer(RingBuffer*& queueRingBufferUnit)
{
	delete[] queueRingBufferUnit->Data;
	delete queueRingBufferUnit;
	queueRingBufferUnit = nullptr;
}

void PrintQueueRingBuffer(RingBuffer* queueRingBufferUnit)
{
	PrintBuffer(queueRingBufferUnit);
}

void ShowQueueRingBuffer(RingBuffer* queueRingBufferUnit)
{
	cout << "Ваш буфер:\n";
	PrintQueueRingBuffer(queueRingBufferUnit);
}

bool IsQueueRingBufferEmpty(RingBuffer* queueRingBufferUnit)
{
	return IsEmpty(queueRingBufferUnit);
}

bool IsQueueRingBufferFull(RingBuffer* queueRingBufferUnit)
{
	return IsFull(queueRingBufferUnit);
}