#include "Queue_Ring_Buffer_based.h"

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

void EnterNumber(string message, int& value)
{
	cout << message;
	cin >> value;
}

void ShowQueueRingBuffer(RingBuffer* queueRingBufferUnit)
{
	cout << "Ваш буфер:\n";
	PrintQueueRingBuffer(queueRingBufferUnit);
}