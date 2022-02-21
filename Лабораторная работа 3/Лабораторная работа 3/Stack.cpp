#include "Stack.h"

Node* CreateStack()
{
	Node* headNode;
	headNode = new Node;
	headNode->PreviousNode = nullptr;
	return headNode;
}

Node* Push(Node* headNode, int dataOfNewElement)
{
	Node* newHeadNode;
	//TODO: new?
	newHeadNode = (struct Node*)malloc(sizeof(struct Node));
	newHeadNode->DataOfNode = dataOfNewElement;
	newHeadNode->PreviousNode = headNode;
	return newHeadNode;
}

int Pop(Node*& headNode)
{
	Node* bufferHeadNode;
	bufferHeadNode = headNode;
	headNode = headNode->PreviousNode;
	return bufferHeadNode->DataOfNode;
}

void Delete(Node*& headNode)
{
	while (headNode != nullptr)
	{
		Node* bufferHeadNode = headNode;
		headNode = headNode->PreviousNode;
		delete bufferHeadNode;
		bufferHeadNode = nullptr;
	}
}