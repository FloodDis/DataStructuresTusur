#include "RingBuffer.h"

RingBuffer* InitializeRingBuffer(int sizeOfRingBuffer)
{
	RingBuffer* ringBuffer = new RingBuffer;
	ringBuffer->Data = new int[sizeOfRingBuffer];
	ringBuffer->Size = sizeOfRingBuffer;
	ringBuffer->FreeSpace = sizeOfRingBuffer;
	return ringBuffer;
}

bool IsBufferFull(RingBuffer* ringBuffer)
{
	//TODO: RSDN +
	int freeSpace = ringBuffer->FreeSpace;
	return freeSpace == 0;
}

bool IsBufferEmpty(RingBuffer* ringBuffer)
{
	int freeSpace = ringBuffer->FreeSpace;
	int size = ringBuffer->Size;
	return freeSpace == size;
}

void Push(RingBuffer*& ringBuffer, int value)
{
	ringBuffer->Data[ringBuffer->ElementToWrite] = value;
	int elementToWrite = ringBuffer->ElementToWrite;
	int size = ringBuffer->Size;
	if (elementToWrite == size - 1)
	{
		ringBuffer->ElementToWrite = 0;
	}
	else
	{
		ringBuffer->ElementToWrite++;
	}
	ringBuffer->FreeSpace--;
}

int Pop(RingBuffer*& ringBuffer)
{
	int elementToRead = ringBuffer->ElementToRead;
	int size = ringBuffer->Size;
	int value = ringBuffer->Data[ringBuffer->ElementToRead];
	if (elementToRead == size - 1)
	{
		ringBuffer->ElementToRead = 0;
	}
	else
	{
		ringBuffer->ElementToRead++;
	}
	ringBuffer->FreeSpace++;
	return value;
}

