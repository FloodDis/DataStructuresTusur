#include "IOList.h"

void Menu(Node* headNode)
{
	while (true)
	{
		cout << "\nSelect an action:\n1) Delete element\n";
		cout << "2) Add element at the beginning\n";
		cout << "3) Add element at the end\n4) Add after specific element\n";
		cout << "5) Add before specific element\n6) Sorting of list\n";
		cout << "7) Leanear search of an element\n8) Quit\n";
		int option = EnterNumber("");
		switch (option)
		{
			case 1:
			{
				Node* dev = headNode;
				//TODO: RSDN +
				int index;
				do
				{
					index = EnterNumber(
						"Enter index of the element to be deleted\n");
				} while (index > ElementCount(headNode) - 1 || index < 0);
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
				int dataOfNode = EnterNumber(
					"Enter data of the new node:\n");
				headNode = AddInTheBeginning(headNode, dataOfNode);
				ShowList(headNode);
				break;
			}

			case 3:
			{
				int dataOfNewNode = EnterNumber(
					"Enter data of the new node:\n");
				AddInTheEnd(headNode, dataOfNewNode);
				ShowList(headNode);
				break;
			}

			case 4:
			{
				//TODO: RSDN +
				int index;
				do
				{
					index = EnterNumber(
						"Enter the index of the element to insert after\n");
				} while (index > ElementCount(headNode) - 1 || index < 0);
				int dataOfNode = EnterNumber(
					"Enter the data of the element to be added\n");
				AddAfter(headNode, dataOfNode, index);
				ShowList(headNode);
				break;
			}

			case 5:
			{
				//TODO: RSDN +
				int index;
				do
				{
					index = EnterNumber(
						"Enter the index of the element to insert before\n");
				} while (index > ElementCount(headNode) - 1 || index < 0);

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
				Node* searchResult = LinearSearch(headNode, searchingValue);
				PrintFinded(searchResult, headNode);
				ShowList(headNode);
				break;
			}

			case 8:
			{
				return;
			}

			default:
			{
				cout << "Try again!\n";
				ShowList(headNode);
				break;
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
		cout << "\nlist[" << indexes->DataOfNode << "] = " << 
			bufferList->DataOfNode;
		indexes = indexes->NextNode;
	}
	cout << "\n\n";
}

//TODO: �� ������ ���� � ��������� ������ +
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
	cout << message;
	int value;
	char input;
	while (cin >> input)
	{
		if (isdigit(input) || input == '-')
		{
			cin.unget();
			cin >> value;
			return value;
		}
		else
		{
			cout << "Incorrect input!\n";
		}
	}
}