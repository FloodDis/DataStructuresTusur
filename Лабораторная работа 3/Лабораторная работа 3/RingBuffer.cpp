#include "RingBuffer.h"


RingBuffer* InitializationOfRingBuffer(int sizeOfRingBuffer)
{
	RingBuffer* ringBuffer = new RingBuffer;
	ringBuffer->Data = new int[sizeOfRingBuffer];
	ringBuffer->Size = sizeOfRingBuffer;
	ringBuffer->WriteCount = 0;
	ringBuffer->ReadCount = 0;
	ringBuffer->Mask = sizeOfRingBuffer - 1;
	return ringBuffer;
}

bool IfThereSpaceToWrite(RingBuffer* ringBuffer)
{
	if (ringBuffer->WriteCount - ringBuffer->ReadCount < ringBuffer->Size)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool IsEmpty(RingBuffer* ringBuffer)
{
	if (ringBuffer->ReadCount == ringBuffer->WriteCount)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void PushInRingBuffer(RingBuffer*& ringBuffer, int value)
{
	ringBuffer->Data[ringBuffer->WriteCount & ringBuffer->Mask] = value;
	ringBuffer->WriteCount++;
}

int PopFromRingBuffer(RingBuffer*& ringBuffer)
{
	if (IsEmpty(ringBuffer))
	{
		return -1;
	}
	int value;
	value = ringBuffer->Data[ringBuffer->ReadCount & ringBuffer->Mask];
	ringBuffer->ReadCount++;
	return value;
}

void PrintBuffer(RingBuffer* ringBuffer)
{

	for (int i = 0; i < ringBuffer->Size; i++)
	{
		printf("%i\n", ringBuffer->Data[i]);
	}

}