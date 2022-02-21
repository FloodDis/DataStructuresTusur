#include "QueueRingBuffer.h"

RingBuffer* CreateQueue(int sizeOfQueue)
{
	RingBuffer* QueueRingBuffer = InitializeRingBuffer(sizeOfQueue);
	return QueueRingBuffer;
}

void Enqueue(RingBuffer*& queueRingBufferUnit, int value)
{
	Push(queueRingBufferUnit, value);
}

int Dequeue(RingBuffer*& queueRingBufferUnit)
{
	return Pop(queueRingBufferUnit);
}

void DeleteQueue(RingBuffer*& queueRingBufferUnit)
{
	delete[] queueRingBufferUnit->Data;
	delete queueRingBufferUnit;
	queueRingBufferUnit = nullptr;
}

bool IsQueueEmpty(RingBuffer* queueRingBufferUnit)
{
	return IsBufferEmpty(queueRingBufferUnit);
}

bool IsQueueFull(RingBuffer* queueRingBufferUnit)
{
	return IsBufferFull(queueRingBufferUnit);
}