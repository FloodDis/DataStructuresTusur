#include "QueueStack.h"

void CreateQueue(QueueStackBased*& queueStackUnit)
{
	queueStackUnit = new QueueStackBased;
	queueStackUnit->StackIn = CreateStack();
	queueStackUnit->StackOut = CreateStack();
	queueStackUnit->StackIn->PreviousNode = nullptr;
	queueStackUnit->StackOut->PreviousNode = nullptr;
}


//TODO:длина
void Enqueue(QueueStackBased*& queueStackUnit, int dataOfElement)
{
	if (queueStackUnit->IsStackInEmpty)
	{
		queueStackUnit->StackIn->DataOfNode = dataOfElement;
		queueStackUnit->IsStackInEmpty = false;
	}
	else
	{
		queueStackUnit->StackIn =
			Push(queueStackUnit->StackIn, dataOfElement);
	}
}

int Dequeue(QueueStackBased*& queueStackUnit)
{
	if (queueStackUnit->IsStackOutEmpty)
	{
		if (queueStackUnit->StackOut == nullptr)
		{
			queueStackUnit->StackOut = CreateStack();
		}
		queueStackUnit->StackOut->DataOfNode =
			Pop(queueStackUnit->StackIn);
		queueStackUnit->StackOut->PreviousNode = nullptr;
		queueStackUnit->IsStackOutEmpty = false;
		while (queueStackUnit->StackIn != nullptr)
		{
			Node* stackOut = queueStackUnit->StackOut;
			
	//TODO: длина
			int valueFromStackIn = Pop(queueStackUnit->StackIn);
			queueStackUnit->StackOut = 
				Push(stackOut, valueFromStackIn);
		}
		queueStackUnit->IsStackInEmpty = true;
	}

	if (queueStackUnit->StackOut->PreviousNode == nullptr)
	{
		queueStackUnit->IsStackOutEmpty = true;
	}

	return Pop(queueStackUnit->StackOut);
}

void DeleteQueue(QueueStackBased*& queueStackUnit)
{
	Delete(queueStackUnit->StackIn);
	Delete(queueStackUnit->StackOut);
	delete queueStackUnit;
	queueStackUnit = nullptr;
}

