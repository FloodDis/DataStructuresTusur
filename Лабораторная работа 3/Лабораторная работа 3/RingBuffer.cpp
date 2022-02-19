#include "RingBuffer.h"

RingBuffer* InitializationOfRingBuffer(int sizeOfRingBuffer)
{
	RingBuffer* ringBuffer = new RingBuffer;
	ringBuffer->Data = new int[sizeOfRingBuffer];
	ringBuffer->Size = sizeOfRingBuffer;
	ringBuffer->FreeSpace = sizeOfRingBuffer;
	return ringBuffer;
}

bool IsFull(RingBuffer* ringBuffer)
{
	int freeSpace = ringBuffer->FreeSpace;
	return freeSpace == 0;
}

bool IsEmpty(RingBuffer* ringBuffer)
{
	int freeSpace = ringBuffer->FreeSpace;
	int size = ringBuffer->Size;
	return freeSpace == size;
}

void PushInRingBuffer(RingBuffer*& ringBuffer, int value)
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

int PopFromRingBuffer(RingBuffer*& ringBuffer)
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

void PrintBuffer(RingBuffer* ringBuffer)
{
	for (int i = 0; i < ringBuffer->Size; i++)
	{
		cout << "[" << i << "] " << ringBuffer->Data[i] << "\n";
	}
}

void ShowRingBuffer(RingBuffer* ringBuffer)
{
	cout << "Ваш буфер:\n";
	PrintBuffer(ringBuffer);
}