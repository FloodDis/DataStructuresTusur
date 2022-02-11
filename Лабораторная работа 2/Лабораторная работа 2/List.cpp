#include "List.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int Randomize()
{
	int randomNumber;
	srand(time(NULL));
	randomNumber = rand() % 100 - 50;;
	return randomNumber;
}

void ShowList(Node* headNode)
{
	cout << "Your list:\n";
	PrintList(headNode);
}

void EnterNumber(string message, int& variable)
{
	cout << message;
	cin >> variable;
}

Node* InitializationOfList(int dataOfHeadNode)
{
	Node* headNode;
	headNode = (struct Node*)malloc(sizeof(struct Node));
	headNode->DataOfNode = dataOfHeadNode;
	headNode->NextNode = nullptr;
	headNode->PreviousNode = nullptr;
	return (headNode);
}

void DeleteElement(Node* headNode, int index)
{
	Node* previous;
	Node* next;
	for (int i = 0; i < index; i++)
	{
		headNode = headNode->NextNode;
	}
	previous = headNode->PreviousNode;
	next = headNode->NextNode;
	if (previous != nullptr)
		previous->NextNode = headNode->NextNode;
	if (next != nullptr)
		next->PreviousNode = headNode->PreviousNode;
	free(headNode);
}

Node* AddInTheBeginning(Node* headNode, int dataOfNewNode)
{
	Node* newHeadNode;
	newHeadNode = (struct Node*)malloc(sizeof(Node));
	newHeadNode->PreviousNode = nullptr;
	newHeadNode->NextNode = headNode;
	headNode->PreviousNode = newHeadNode;
	newHeadNode->DataOfNode = dataOfNewNode;
	return (newHeadNode);
}

void AddInTheEnd(Node* headNode, int dataOfNewNode)
{
	Node* newEndNode;
	newEndNode = (struct Node*)malloc(sizeof(Node));
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
		Node* newNode;
		Node* buffer;
		newNode = (struct Node*)malloc(sizeof(Node));
		buffer = headNode->NextNode;
		headNode->NextNode = newNode;
		newNode->DataOfNode = dataOfNewNode;
		newNode->NextNode = buffer;
		newNode->PreviousNode = headNode;
		if (buffer != nullptr)
			buffer->PreviousNode = newNode;
	}
}

void AddAfter(Node* headNode, int dataOfNewNode, int index)
{
	for (int i = 0; i < index; i++)
	{
		headNode = headNode->NextNode;
	}
	Node* newNode;
	Node* buffer;
	newNode = (struct Node*)malloc(sizeof(Node));
	buffer = headNode->NextNode;
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
	Node* i = headNode;
	Node* j = headNode;
	while (i != nullptr)
	{
		while (j != nullptr)
		{
			if (i->DataOfNode < j->DataOfNode)
			{
				swap(i->DataOfNode, j->DataOfNode);
			}
			j = j->NextNode;
		}
		i = i->NextNode;
		j = headNode;
	}
}

void PrintList(Node* headNode)
{
	int i = 0;
	while (headNode != nullptr)
	{
		printf("list[%i]=%i\n", i, headNode->DataOfNode);
		headNode = headNode->NextNode;
		i++;
	}
}

Node* LinearSearch(Node* headNode, int searchingValue)
{
	Node* indexes;
	Node* bufferList;
	int index = 0;
	bufferList = headNode;
	indexes = InitializationOfList(0);
	indexes->DataOfNode = NULL;
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

void PrintFinded(Node* indexes, Node* headNode)
{
	Node* bufferList;
	indexes = indexes->NextNode;
	while (indexes != nullptr)
	{
		bufferList = headNode;
		for (int i = 0; i < indexes->DataOfNode; i++)
		{
			bufferList = bufferList->NextNode;
		}
		printf("\nlist[%i] = %i", indexes->DataOfNode, bufferList->DataOfNode);
		indexes = indexes->NextNode;
	}
	printf("\n\n");
}

int ElementCount(Node* headNode)
{
	int i = 0;
	while (headNode != nullptr)
	{
		i++;
		headNode = headNode->NextNode;
	}
	return i;
}

void Menu(Node* headNode)
{
	int option;
	while (true)
	{
		printf("\nSelect an action:\n1) Delete element\n");
		printf("2) Add element at the beginning\n3) Add element at the end\n4) Add after specific element\n");
		printf("5) Add before specific element\n6) Sorting of list\n7) Leanear search of an element\n");
		printf("8) Quit\n");
		cin >> option;
		switch (option)
		{
			case 1:
			{
				Node* dev = headNode;
				int index = 0;
				EnterNumber("Enter index of the element to be deleted\n", index);
				if (index > ElementCount(headNode) - 1)
				{
					printf("There is no such element!\n");
					ShowList(headNode);
					break;
				}
				if (index == 0)
				{
					if (headNode->NextNode == nullptr)
					{
						int dataOfTheNode = Randomize();
						free(headNode);
						headNode = InitializationOfList(dataOfTheNode);
						ShowList(headNode);
					}
					else
					{
						Node* buffer = headNode;
						headNode = headNode->NextNode;
						headNode->PreviousNode = nullptr;
						free(buffer);
						ShowList(headNode);
					}
					break;
				}
				DeleteElement(dev, index);
				ShowList(headNode);
				break;
			}

			case 2:
			{
				int dataOfNewNode = 0;
				EnterNumber("Enter data of the new node:\n", dataOfNewNode);
				headNode = AddInTheBeginning(headNode, dataOfNewNode);
				ShowList(headNode);
				break;
			}

			case 3:
			{
				int dataOfNewNode = 0;
				EnterNumber("Enter data of the new node:\n", dataOfNewNode);
				AddInTheEnd(headNode, dataOfNewNode);
				ShowList(headNode);
				break;
			}

			case 4:
			{
				int dataOfNewNode = 0;
				int index = 0;
				EnterNumber("Enter the index of the element after which you want to insert\n", index);
				EnterNumber("Enter the data of the element to be added\n", dataOfNewNode);
				AddAfter(headNode, dataOfNewNode, index);
				ShowList(headNode);
				break;
			}

			case 5:
			{
				int dataOfNewNode = 0;
				int index = 0;
				EnterNumber("Enter the index of the element before which you want to insert\n", index);
				EnterNumber("Enter the data of the element to be added\n", dataOfNewNode);
				if (index == 0)
				{
					headNode = AddBefore(headNode, dataOfNewNode, index);
				}
				else
				{
					AddBefore(headNode, dataOfNewNode, index);
				}
				ShowList(headNode);
				break;
			}

			case 6:
			{
				BubbleSort(headNode);
				ShowList(headNode);
				break;
			}

			case 7:
			{
				int searchingValue = 0;
				EnterNumber("Enter the searching value\n", searchingValue);
				PrintFinded(LinearSearch(headNode, searchingValue), headNode);
				break;
			}

			case 8:
			{
				return;
				break;
			}
		}
	}
}