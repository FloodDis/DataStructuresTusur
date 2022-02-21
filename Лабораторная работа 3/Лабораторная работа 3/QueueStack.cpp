#include "QueueStack.h"

void CreationOfQueueStackBased(QueueStackBased*& queueStackUnit)
{
	queueStackUnit = new QueueStackBased;
	queueStackUnit->StackIn = CreationOfStack();
	queueStackUnit->StackOut = CreationOfStack();
	queueStackUnit->StackIn->PreviousNode = nullptr;
	queueStackUnit->StackOut->PreviousNode = nullptr;
}


//TODO:длина
void EnqueueStackBased(QueueStackBased*& queueStackUnit, int dataOfElement)
{
	if (queueStackUnit->IsStackInEmpty)
	{
		queueStackUnit->StackIn->DataOfNode = dataOfElement;
		queueStackUnit->IsStackInEmpty = false;
	}
	else
	{
		queueStackUnit->StackIn =
			PushInStack(queueStackUnit->StackIn, dataOfElement);
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
		queueStackUnit->StackOut->DataOfNode =
			PopFromStack(queueStackUnit->StackIn);
		queueStackUnit->StackOut->PreviousNode = nullptr;
		queueStackUnit->IsStackOutEmpty = false;
		while (queueStackUnit->StackIn != nullptr)
		{
			Node* stackOut = queueStackUnit->StackOut;
			
	//TODO: длина
			int valueFromStackIn = PopFromStack(queueStackUnit->StackIn);
			queueStackUnit->StackOut = 
				PushInStack(stackOut, valueFromStackIn);
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

