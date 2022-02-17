#include "IOList.h"

void Menu(Node* headNode)
{
	while (true)
	{
		cout << "\nSelect an action:\n1) Delete element\n";
		cout << "2) Add element at the beginning\n3) Add element at the end\n";
		cout << "4) Add after specific element\n5) Add before specific element\n";
		cout << "6) Sorting of list\n7) Leanear search of an element\n8) Quit\n";
		int option;
		cin >> option;
		switch (option)
		{
			case 1:
			{
				Node* dev = headNode;
				//TODO: RSDN +
				int index;
				bool tryAgain = true;
				while (tryAgain)
				{
					try
					{
						index = EnterNumber("Enter index of the element to be deleted\n");
						tryAgain = false;
					}
					catch (const char* error)
					{
						cout << "\nTry again\n";
					}
				}

				if (index > ElementCount(headNode) - 1)
				{
					cout << "There is no such element!\n";
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
				int dataOfNode = 0;
				bool tryAgain = true;
				while (tryAgain)
				{
					try
					{
						dataOfNode = EnterNumber("Enter data of the new node:\n");
						tryAgain = false;
					}
					catch (const char* error)
					{
						cout << "\nTry again\n";
					}
				}
				headNode = AddInTheBeginning(headNode, dataOfNode);
				ShowList(headNode);
				break;
			}

			case 3:
			{
				int dataOfNewNode;
				bool tryAgain = true;
				while (tryAgain)
				{
					try
					{
						dataOfNewNode = EnterNumber("Enter data of the new node:\n");
						tryAgain = false;
					}
					catch (const char* error)
					{
						cout << "\nTry again\n";
					}
				}

				AddInTheEnd(headNode, dataOfNewNode);
				ShowList(headNode);
				break;
			}

			case 4:
			{
				//TODO: RSDN +
				int index = EnterNumber(
					"Enter the index of the element to insert after\n");
				int dataOfNewNode = EnterNumber(
					"Enter the data of the element to be added\n");
				AddAfter(headNode, dataOfNewNode, index);
				ShowList(headNode);
				break;
			}

			case 5:
			{
				//TODO: RSDN +
				int index = EnterNumber(
					"Enter the index of the element to insert before\n");
				int dataOfNewNode = EnterNumber(
					"Enter the data of the element to be added\n");
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
				int searchingValue = EnterNumber(
					"Enter the searching value\n");
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

int EnterNumber(string message)
{
	int inputValue;
	cout << message;
	cin >> inputValue;
	if (cin.fail())
	{
		cin.clear();
		string streamToDelete;
		cin >> streamToDelete;
		throw "Error: incorrect input data!\n";
	}
	return inputValue;
}
