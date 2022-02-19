#include "Stack.h"

Node* CreationOfStack()
{
	Node* headNode;
	headNode = new Node;
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