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
	Node* newHeadNode;
	newHeadNode = new Node;
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

//TODO: не должно быть в структуре данных
void PrintList(Node* headNode)
{
	int i = 0;
	while (headNode != nullptr)
	{
		//TODO: +
		cout << "list[" << i << "] =" << headNode->DataOfNode << "\n";
		headNode = headNode->NextNode;
		i++;
	}
}

Node* LinearSearch(Node* headNode, int searchingValue)
{
	//TODO: RSDN +
	Node* indexes = InitializationOfList(2);
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


void PrintFinded(Node* indexes, Node* headNode)
{
	//TODO: +
	indexes = indexes->NextNode;
	while (indexes != nullptr)
	{
		Node* bufferList = headNode;
		for (int i = 0; i < indexes->DataOfNode; i++)
		{
			bufferList = bufferList->NextNode;
		}
		cout << "\nlist[" << indexes->DataOfNode << "] = " << bufferList->DataOfNode;
		indexes = indexes->NextNode;
	}
	cout << "\n\n";
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
			//TODO: RSDN
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
			//TODO: RSDN
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
			//TODO: RSDN
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
		}
		}
	}
}