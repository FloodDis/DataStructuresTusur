#include "IORedBlackTree.h"

void RBTreeMenu()
{
	/// <summary>
	/// Действия, которые можно совершить с красно-черным деревом
	/// </summary>
	enum Actions
	{
		/// <summary>
		/// Добавить элемент
		/// </summary>
		Add = 1,

		/// <summary>
		/// Удалить элемент
		/// </summary>
		Delete = 2,

		/// <summary>
		/// Найти элемент
		/// </summary>
		Find = 3,

		/// <summary>
		/// Тест производительности
		/// </summary>
		Test = 4,

		/// <summary>
		/// Выйти в главное меню
		/// </summary>
		Exit = 5
	};

	setlocale(LC_ALL, "ru");
	RBTree* treeUnit = new RBTree;
	Show(treeUnit);
	while (true)
	{
		cout << "Choose an action:"
			<< "\n1) Add element"
			<< "\n2) Delete element"
			<< "\n3) Find element"
			<< "\n4) Test performance"
			<< "\n5) Exit\n";
		int option = EnterNumber("");
		switch (option)
		{
			case Add:
			{
				int key =
					EnterNumber("Enter key of new element: ");
				try
				{
					treeUnit->Insert(key);
				}
				catch (char const* error)
				{
					cout << error << '\n';
				}
				Show(treeUnit);
				break;
			}

			case Delete:
			{
				int key =
					EnterNumber("Enter key of element to delete: ");
				try
				{
					treeUnit->Delete(key);
					cout << "Element was deleted!\n";
				}
				catch (char const* error)
				{
					cout << error << '\n';
				}
				Show(treeUnit);
				break;
			}

			case Find:
			{
				int key = EnterNumber("Enter key of element to find : ");
				RBTreeNode* result = treeUnit->Find(key);
				if (result != nullptr)
				{
					cout << "Element with key  " << result->Key
						<< " have a color: ";
					if (result->IsBlack)
					{
						cout << "Black\n";
					}
					else
					{
						cout << "Red\n";
					}
				}
				else
				{
					cout << "Element isn't found!\n";
				}
				Show(treeUnit);
				break;
			}

			case Test:
			{
				cout << "Performance tests are executing."
					<< "Please wait...\n";
				ofstream file{ "RBTreePerformanceTest.txt" };
				file << GetTreePerformanceMeasurementRB(treeUnit);
				file.close();
				cout << "Performance tests are finished."
					<< "Result are saved in file.\n";
				break;
			}

			case Exit:
			{
				return;
			}

			default:
			{
				cout << "Try again!\n";
				Show(treeUnit);
				break;
			}
		}
	}
}

void Print(RBTreeNode* rootNode, int tabCount)
{
	if (rootNode != nullptr)
	{
		Print(rootNode->Child[Right], tabCount + 1);
		for (int i = 0; i < tabCount; i++)
		{
			cout << "\t";
		}
		cout << "(" << rootNode->Key << "; ";
		if (rootNode->IsBlack)
		{
			cout << "Black)";
		}
		else
		{
			cout << "Red)";
		}
		if (rootNode->Child[Left] != nullptr &&
			rootNode->Child[Right] != nullptr)
		{
			cout << "|\n";
		}
		if (rootNode->Child[Left] == nullptr &&
			rootNode->Child[Right] != nullptr)
		{
			cout << "/\n";
		}
		if (rootNode->Child[Left] != nullptr &&
			rootNode->Child[Right] == nullptr)
		{
			cout << "\\\n";
		}
		if (rootNode->Child[Left] == nullptr &&
			rootNode->Child[Right] == nullptr)
		{
			cout << "\n";
		}
		Print(rootNode->Child[Left], tabCount + 1);
	}
}

void Show(RBTree* treeUnit)
{
	cout << "Ваше красно-черное дерево:\n";
	Print(treeUnit->GetRoot(), 0);
}