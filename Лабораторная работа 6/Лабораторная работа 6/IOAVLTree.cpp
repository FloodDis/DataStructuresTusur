#include "IOAVLTree.h"

void AVLTreeMenu()
{
	/// <summary>
	/// Действия, которые можно совершить с АВЛ-деревом
	/// </summary>
	enum Actions
	{
		/// <summary>
		/// Добавить элемент
		/// </summary>
		AddElement = 1,

		/// <summary>
		/// Удалить элемент
		/// </summary>
		DeleteElement = 2,

		/// <summary>
		/// Найти элемент
		/// </summary>
		FindElement = 3,

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
	AVLTree* treeUnit = new AVLTree;
	Show(treeUnit->GetRoot());
	while (true)
	{
		cout << "Choose an action:\n"
			<< "1) Add element\n"
			<< "2) Delete element\n"
			<< "3) Find element\n"
			<< "4) Test performance\n"
			<< "5) Exit\n";
		int option = EnterNumber("");
		switch (option)
		{
			case AddElement:
			{
				int	keyOfNewNode =
					EnterNumber("Enter key of new element: ");
				try
				{
					treeUnit->Insert(keyOfNewNode);
				}
				catch (char const* error)
				{
					cout << error << '\n';
				}
				Show(treeUnit->GetRoot());
				break;
			}

			case DeleteElement:
			{
				int keyToDelete =
					EnterNumber("Enter key of element to delete: ");
				try
				{
					treeUnit->Delete(keyToDelete);
					cout << "Element was deleted!\n";
				}
				catch (char const* error)
				{
					cout << error << '\n';
				}
				Show(treeUnit->GetRoot());
				break;
			}

			case FindElement:
			{
				AVLTreeNode* answer = nullptr;
				int searchingKey =
					EnterNumber("Enter key of element to find : ");
				answer = treeUnit->Find(searchingKey);
				if (answer == nullptr)
				{
					cout << "Element isn't found!\n";
				}
				else
				{
					cout << "Element with key " << answer->Key 
						<< " is in the tree\n";
				}
				Show(treeUnit->GetRoot());
				break;
			}

			case Test:
			{
				cout << "Performance tests are executing. Please wait...\n";
				ofstream file{ "AVLTreePerformanceTest.txt" };
				file << GetTreePerformanceMeasurementAVL(treeUnit);
				file.close();
				cout << "Performance tests are finished."
					<<" Result are saved in file.\n";
				break;
			}

			case Exit:
			{
				return;
			}

			default:
			{
				cout << "Try again!\n";
				Show(treeUnit->GetRoot());
				break;
			}
		}
	}
}

void Show(AVLTreeNode* rootNode)
{
	cout << "Your AVL tree:\n";
	Print(rootNode, 0);
}

void Print(AVLTreeNode* rootNode, int tabCount)
{
	if (rootNode != nullptr)
	{
		Print(rootNode->Right, tabCount + 1);
		for (int i = 0; i < tabCount; i++)
		{
			cout << "\t";
		}
		cout << "(" << rootNode->Key << ";" << rootNode->SubTreeHeight << ")";
		if (rootNode->Left != nullptr && rootNode->Right != nullptr)
		{
			cout << "|\n";
		}
		if (rootNode->Left == nullptr && rootNode->Right != nullptr)
		{
			cout << "/\n";
		}
		if (rootNode->Left != nullptr && rootNode->Right == nullptr)
		{
			cout << "\\\n";
		}
		if (rootNode->Left == nullptr && rootNode->Right == nullptr)
		{
			cout << "\n";
		}
		Print(rootNode->Left, tabCount + 1);
	}
}