#include "RingBuffer.h"

RingBuffer* InitializationOfRingBuffer(int sizeOfRingBuffer)
{
	RingBuffer* ringBuffer = new RingBuffer;
	ringBuffer->Data = new int[sizeOfRingBuffer];
	ringBuffer->Size = sizeOfRingBuffer;
	return ringBuffer;
}

bool IfThereSpaceToWrite(RingBuffer* ringBuffer)
{
	int elementToWrite = ringBuffer->ElementToWrite;
	int size = ringBuffer->Size;
	return elementToWrite < size;
}

bool IsEmpty(RingBuffer* ringBuffer)
{
	//TODO: +
	int elementToWrite = ringBuffer->ElementToWrite;
	int elementToRead = ringBuffer->ElementToRead;
	return elementToWrite == elementToRead;
}

void PushInRingBuffer(RingBuffer*& ringBuffer, int value)
{
	ringBuffer->Data[ringBuffer->ElementToWrite] = value;
	ringBuffer->ElementToWrite++;
}

int PopFromRingBuffer(RingBuffer*& ringBuffer)
{
	if (IsEmpty(ringBuffer))
	{
		return -1;
	}
	int value= ringBuffer->Data[ringBuffer->ElementToRead];
	ringBuffer->ElementToRead++;
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