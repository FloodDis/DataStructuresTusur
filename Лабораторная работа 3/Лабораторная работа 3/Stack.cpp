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
	Node* pHeadNode;
	pHeadNode = headNode;
	headNode = headNode->PreviousNode;
	return pHeadNode->DataOfNode;
}

void DeleteStack(Node*& headNode)
{
	while (headNode != nullptr)
	{
		Node* pStack = headNode;
		headNode = headNode->PreviousNode;
		delete pStack;
		pStack = nullptr;
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
	cout << "��� ����:\n";
	PrintStack(headNode);
}