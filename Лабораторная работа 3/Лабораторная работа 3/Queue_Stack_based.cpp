#include "Queue_Stack_based.h"

void CreationOfQueueStackBased(QueueStackBased*& queueStackUnit)
{
	queueStackUnit = new QueueStackBased;
	queueStackUnit->StackIn = CreationOfStack();
	queueStackUnit->StackOut = CreationOfStack();
	queueStackUnit->StackIn->PreviousNode = nullptr;
	queueStackUnit->StackOut->PreviousNode = nullptr;
}

void EnqueueStackBased(QueueStackBased*& queueStackUnit, int dataOfElement)
{
	if (queueStackUnit->IsStackInEmpty)
	{
		queueStackUnit->StackIn->DataOfNode = dataOfElement;
		queueStackUnit->IsStackInEmpty = false;
	}
	else
	{
		queueStackUnit->StackIn = PushInStack(queueStackUnit->StackIn, dataOfElement);
	}
}

int DequeueStackBased(QueueStackBased*& queueStackUnit)
{
	if (queueStackUnit->IsStackOutEmpty)
	{
		if (queueStackUnit->StackOut == nullptr)
		{
			queueStackUnit->StackOut = CreationOfStack();
		}
		queueStackUnit->StackOut->DataOfNode = PopFromStack(queueStackUnit->StackIn);
		queueStackUnit->StackOut->PreviousNode = nullptr;
		queueStackUnit->IsStackOutEmpty = false;
		while (queueStackUnit->StackIn != nullptr)
		{
			queueStackUnit->StackOut = PushInStack(queueStackUnit->StackOut, PopFromStack(queueStackUnit->StackIn));
		}
		queueStackUnit->IsStackInEmpty = true;
	}

	if (queueStackUnit->StackOut->PreviousNode == nullptr)
	{
		queueStackUnit->IsStackOutEmpty = true;
	}

	return PopFromStack(queueStackUnit->StackOut);
}

void DeleteQueueStackBased(QueueStackBased*& queueStackUnit)
{
	DeleteStack(queueStackUnit->StackIn);
	DeleteStack(queueStackUnit->StackOut);
	delete queueStackUnit;
	queueStackUnit = nullptr;
}

void PrintQueueStackBased(QueueStackBased* queueStackUnit)
{
	setlocale(LC_ALL, "Russian");
	printf("\nStackIn:");
	if (queueStackUnit->IsStackInEmpty)
	{
		printf("\n{ }\n");
	}
	else
	{
		PrintStack(queueStackUnit->StackIn);
	}

	printf("\nStackOut:");
	if (queueStackUnit->IsStackOutEmpty)
	{
		printf("\n{ }\n");
	}
	else
	{
		PrintStack(queueStackUnit->StackOut);
	}

}