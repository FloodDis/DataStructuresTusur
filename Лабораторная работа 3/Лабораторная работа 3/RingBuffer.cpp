#include "RingBuffer.h"

RingBuffer* InitializeRingBuffer(int sizeOfRingBuffer)
{
	RingBuffer* ringBuffer = new RingBuffer;
	ringBuffer->Data = new int[sizeOfRingBuffer];
	ringBuffer->Size = sizeOfRingBuffer;
	ringBuffer->FreeSpace = sizeOfRingBuffer;
	return ringBuffer;
}

bool IsBufferFull(RingBuffer* RingBuffer)
{
	return RingBuffer->FreeSpace == 0;
}

bool IsBufferEmpty(RingBuffer* RingBuffer)
{
	return RingBuffer->FreeSpace == RingBuffer->Size;
}

void Push(RingBuffer*& RingBuffer, int value)
{
	RingBuffer->Data[RingBuffer->ElementToWrite] = value;
	int elementToWrite = RingBuffer->ElementToWrite;
	int size = RingBuffer->Size;
	if (elementToWrite == size - 1)
	{
		RingBuffer->ElementToWrite = 0;
	}
	else
	{
		RingBuffer->ElementToWrite++;
	}
	RingBuffer->FreeSpace--;
}

int Pop(RingBuffer*& RingBuffer)
{
	int elementToRead = RingBuffer->ElementToRead;
	int size = RingBuffer->Size;
	int value = RingBuffer->Data[RingBuffer->ElementToRead];
	if (elementToRead == size - 1)
	{
		RingBuffer->ElementToRead = 0;
	}
	else
	{
		RingBuffer->ElementToRead++;
	}
	RingBuffer->FreeSpace++;
	return value;
}

