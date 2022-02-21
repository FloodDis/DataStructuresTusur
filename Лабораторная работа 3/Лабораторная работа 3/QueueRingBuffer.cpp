#include "QueueRingBuffer.h"

RingBuffer* CreateQueue(int sizeOfQueue)
{
	//TODO: длина
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



bool IsEmpty(RingBuffer* queueRingBufferUnit)
{
	return IsEmpty(queueRingBufferUnit);
}

bool IsFull(RingBuffer* queueRingBufferUnit)
{
	return IsFull(queueRingBufferUnit);
}