#include "Stack.h"

Node* CreationOfStack()
{
	Node* headNode;
	headNode = (struct Node*)malloc(sizeof(struct Node));
	headNode->PreviousNode = nullptr;
	return headNode;
}

Node* PushInStack(Node* headNode, int dataOfNewElement)
{
	Node* newHeadNode;
	newHeadNode = (struct Node*)malloc(sizeof(struct Node));
	newHeadNode->DataOfNode = dataOfNewElement;
	newHeadNode->PreviousNode = headNode;
	return newHeadNode;
}

int PopFromStack(Node*& headNode)
{
	Node* bufferHeadNode;
	bufferHeadNode = headNode;
	headNode = headNode->PreviousNode;
	return bufferHeadNode->DataOfNode;
}

void DeleteStack(Node*& headNode)
{
	while (headNode != nullptr)
	{
		Node* bufferHeadNode = headNode;
		headNode = headNode->PreviousNode;
		delete bufferHeadNode;
		bufferHeadNode = nullptr;
	}
}

void PrintStack(Node* headNode)
{
	if (headNode == nullptr)
	{
		printf("\n{ }\n");
		return;
	}

	printf("\n{%i}", headNode->DataOfNode);
	headNode = headNode->PreviousNode;

	while (headNode != nullptr)
	{
		printf(" %i", headNode->DataOfNode);
		headNode = headNode->PreviousNode;
	}

	printf("\n");
}

void ShowStack(Node* headNode)
{
	cout << "Ваш стек:\n";
	PrintStack(headNode);
}