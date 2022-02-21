#include "List.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int Randomize()
{
	//TODO: RSDN +
	//TODO: nullptr +
	srand(time(nullptr));
	int randomNumber = rand() % 100 - 50;
	return randomNumber;
}

Node* InitializationOfList(int dataOfHeadNode)
{
	//TODO: new? +
	Node* headNode = new Node;
	headNode->DataOfNode = dataOfHeadNode;
	headNode->NextNode = nullptr;
	headNode->PreviousNode = nullptr;
	return (headNode);
}

void DeleteElement(Node* headNode, int index)
{
	//TODO: RSDN +
	for (int i = 0; i < index; i++)
	{
		headNode = headNode->NextNode;
	}
	Node* previous = headNode->PreviousNode;
	Node* next = headNode->NextNode;

	//TODO:+
	if (previous != nullptr)
	{
		previous->NextNode = headNode->NextNode;
	}
	if (next != nullptr)
	{
		next->PreviousNode = headNode->PreviousNode;
	}
	free(headNode);
}

Node* AddInTheBeginning(Node* headNode, int dataOfNewNode)
{
	//TODO: RSDN +
	Node* newHeadNode = new Node;
	newHeadNode->PreviousNode = nullptr;
	newHeadNode->NextNode = headNode;
	headNode->PreviousNode = newHeadNode;
	newHeadNode->DataOfNode = dataOfNewNode;
	return (newHeadNode);
}

void AddInTheEnd(Node* headNode, int dataOfNewNode)
{
	//TODO: RSDN +
	Node* newEndNode = new Node;
	//TODO: new +
	while (headNode->NextNode != nullptr)
	{
		headNode = headNode->NextNode;
	}
	newEndNode->NextNode = nullptr;
	newEndNode->PreviousNode = headNode;
	newEndNode->DataOfNode = dataOfNewNode;
	headNode->NextNode = newEndNode;
}

Node* AddBefore(Node* headNode, int dataOfNewNode, int index)
{
	if (index == 0)
	{
		headNode = AddInTheBeginning(headNode, dataOfNewNode);
		return (headNode);
	}
	else
	{
		for (int i = 0; i < index - 1; i++)
		{
			headNode = headNode->NextNode;
		}
		//TODO: RSDN +
		Node* newNode = new Node;
		Node* buffer = headNode->NextNode;
		headNode->NextNode = newNode;
		newNode->DataOfNode = dataOfNewNode;
		newNode->NextNode = buffer;
		newNode->PreviousNode = headNode;
		//TODO: +
		if (buffer != nullptr)
		{
			buffer->PreviousNode = newNode;
		}
	}
}

void AddAfter(Node* headNode, int dataOfNewNode, int index)
{
	for (int i = 0; i < index; i++)
	{
		headNode = headNode->NextNode;
	}
	//TODO: RSDN +
	Node* newNode = new Node;
	Node* buffer = headNode->NextNode;
	//TODO: new +
	headNode->NextNode = newNode;
	newNode->DataOfNode = dataOfNewNode;
	newNode->NextNode = buffer;
	newNode->PreviousNode = headNode;
	if (buffer != nullptr)
	{
		buffer->PreviousNode = newNode;
	}
}

void BubbleSort(Node* headNode)
{
	//TODO: RSDN +
	Node* firstNode = headNode;
	Node* secondNode = headNode;
	while (firstNode != nullptr)
	{
		while (secondNode != nullptr)
		{
			if (firstNode->DataOfNode < secondNode->DataOfNode)
			{
				swap(firstNode->DataOfNode, secondNode->DataOfNode);
			}
			secondNode = secondNode->NextNode;
		}
		firstNode = firstNode->NextNode;
		secondNode = headNode;
	}
}

Node* LinearSearch(Node* headNode, int searchingValue)
{
	//TODO: RSDN +
	//TODO: Возможно, есть более удачное имя для indexes,
	//TODO: т.к. не понятно сходу, индексы чего она должна хранить?
	Node* indexes = InitializationOfList(0);
	Node* bufferList = headNode;
	int index = 0;
	//TODO: nullptr +
	while (bufferList != nullptr)
	{
		if (bufferList->DataOfNode == searchingValue)
		{
			AddInTheEnd(indexes, index);
		}
		index++;
		bufferList = bufferList->NextNode;
	}
	return indexes;
}

int ElementCount(Node* headNode)
{
	int elementCount = 0;
	while (headNode != nullptr)
	{
		elementCount++;
		headNode = headNode->NextNode;
	}
	return elementCount;
}