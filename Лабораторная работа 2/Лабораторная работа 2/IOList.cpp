#include "IOList.h"

void Menu(Node* headNode)
{
	while (true)
	{
		/// <summary>
		/// Действия над списком
		/// </summary>
		enum Actions
		{
			/// <summary>
			/// Удалить элемент
			/// </summary>
			Delete = 1,

			/// <summary>
			/// Добавить в начало
			/// </summary>
			InsertToTop,

			/// <summary>
			/// Добавить в конец
			/// </summary>
			InsertToEnd,

			/// <summary>
			/// Добавить после элемента
			/// </summary>
			/// <param name="headNode"></param>
			InsertAfter,

			/// <summary>
			/// Добавить до элемента
			/// </summary>
			InsertBefore,

			/// <summary>
			/// Отсортировать список
			/// </summary>
			Sort,

			/// <summary>
			/// Найти элемент в списке
			/// </summary>
			Find,

			/// <summary>
			/// Выход из программы
			/// </summary>
			Quit
		};
		cout << "\nSelect an action:\n1) Delete element\n"
			<< "2) Add element at the beginning\n"
			<< "3) Add element at the end\n"
			<< "4) Add after specific element\n"
			<< "5) Add before specific element\n6) Sorting of list\n"
			<< "7) Leanear search of an element\n8) Quit\n";
		int option = EnterNumber("");
		switch (option)
		{
			case Delete:
			{
				Node* bufferNode = headNode;
				int index = EnterNumber(
					"Enter index of the element to be deleted\n");
				if (index > ElementCount(bufferNode) - 1 || index < 0)
				{
					cout << "Element doesn't exist.\n";
					Show(headNode);
					break;
				}
				else if (index == 0)
				{
					if (headNode->NextNode == nullptr)
					{
						int dataOfTheNode = Randomize();
						free(headNode);
						headNode = InitializationOfList(dataOfTheNode);
						Show(headNode);
					}
					else
					{
						Node* buffer = headNode;
						headNode = headNode->NextNode;
						headNode->PreviousNode = nullptr;
						free(buffer);
						Show(headNode);
					}
					break;
				}
				DeleteElement(bufferNode, index);
				Show(headNode);
				break;
			}

			case InsertToTop:
			{
				int dataOfNode = EnterNumber(
					"Enter data of the new node:\n");
				headNode = AddInTheBeginning(headNode, dataOfNode);
				Show(headNode);
				break;
			}

			case InsertToEnd:
			{
				int dataOfNewNode = EnterNumber(
					"Enter data of the new node:\n");
				AddInTheEnd(headNode, dataOfNewNode);
				Show(headNode);
				break;
			}

			case InsertAfter:
			{
				int index;
				do
				{
					index = EnterNumber(
						"Enter the index to insert after\n");
				} while (index > ElementCount(headNode) - 1 || index < 0);
				int dataOfNode = EnterNumber(
					"Enter the data of the element to be added\n");
				AddAfter(headNode, dataOfNode, index);
				Show(headNode);
				break;
			}

			case InsertBefore:
			{
				int index;
				do
				{
					index = EnterNumber(
						"Enter the index to insert before\n");
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
				Show(headNode);
				break;
			}

			case Sort:
			{
				BubbleSort(headNode);
				Show(headNode);
				break;
			}

			case Find:
			{
				int searchingValue = EnterNumber(
					"Enter the searching value\n");
				Node* searchResult =
					LinearSearch(headNode, searchingValue);
				PrintFinded(searchResult, headNode);
				Show(headNode);
				break;
			}

			case Quit:
			{
				return;
			}

			default:
			{
				cout << "Try again!\n";
				Show(headNode);
				break;
			}
		}
	}
}

void PrintFinded(Node* foundIndexes, Node* headNode)
{
	foundIndexes = foundIndexes->NextNode;
	while (foundIndexes != nullptr)
	{
		Node* bufferList = headNode;
		for (int i = 0; i < foundIndexes->DataOfNode; i++)
		{
			bufferList = bufferList->NextNode;
		}
		cout << "\nlist[" << foundIndexes->DataOfNode << "] = " <<
			bufferList->DataOfNode;
		foundIndexes = foundIndexes->NextNode;
	}
	cout << "\n\n";
}

void Print(Node* headNode)
{
	int i = 0;
	while (headNode != nullptr)
	{
		cout << "list[" << i << "] =" << headNode->DataOfNode << "\n";
		headNode = headNode->NextNode;
		i++;
	}
}

void Show(Node* headNode)
{
	cout << "Your list:\n";
	Print(headNode);
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

int Randomize()
{
	srand(time(nullptr));
	int randomNumber = rand() % 100 - 50;
	return randomNumber;
}