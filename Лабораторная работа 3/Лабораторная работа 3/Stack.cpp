﻿#include "Stack.h"

Node* CreateStack()
{
	//TODO: RSDN
	Node* headNode;
	headNode = new Node;
	headNode->PreviousNode = nullptr;
	return headNode;
}

Node* Push(Node* headNode, int dataOfNewElement)
{
	//TODO: RSDN
	Node* newHeadNode;
	newHeadNode = new Node;
	newHeadNode->DataOfNode = dataOfNewElement;
	newHeadNode->PreviousNode = headNode;
	return newHeadNode;
}

int Pop(Node*& headNode)
{
	//TODO: RSDN
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