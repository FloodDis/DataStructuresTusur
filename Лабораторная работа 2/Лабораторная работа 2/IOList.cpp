#include "IOList.h"

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

//TODO: не должно быть в структуре данных +
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

void ShowList(Node* headNode)
{
	cout << "Your list:\n";
	PrintList(headNode);
}

int EnterNumber(string message, int variable)
{
	cout << message;
	cin >> variable;
	return variable;
}