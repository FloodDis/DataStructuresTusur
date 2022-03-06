#include <iostream>
#include "AVLTree.h"
#include "RedBlackTree.h"
#include "PerformanceTest.h"
#include <fstream>
#include "../../Console/Console.h"
#include "../../Console/Console.cpp"
using namespace std;

void MainMenu();

/// <summary>
/// Функция вызова меню АВЛ-дерева
/// </summary>
void AVLTreeMenu();

/// <summary>
/// Функция вывода сообщения Ваше АВЛ-дерево: и АВЛ-дерева
/// </summary>
void Show(AVLTreeNode* rootNode);

/// <summary>
/// Функция вывода АВЛ-дерева на экран
/// </summary>
/// <param name="rootNode">корень дерева</param>
/// <param name="tabCount">количество табуляций</param>
void Print(AVLTreeNode* rootNode, int tabCount);

/// <summary>
/// Функция вызова меню красно-черного дерева
/// </summary>
void RBTreeMenu();

/// <summary>
/// Функция вывода сообщения Ваше красно-черное дерево: 
/// и красно-черного дерева
/// </summary>
/// <param name="treeUnit">экземпляр красно-черного дерева</param>
void Show(RBTree* treeUnit);

/// <summary>
/// Функция вывода красно-черного дерева на экран
/// </summary>
/// <param name="rootNode">корень дерева</param>
/// <param name="tabCount">количество табуляций</param>
void Print(RBTreeNode* rootNode, int tabCount);

void main()
{
	MainMenu();
}

void MainMenu()
{
	/// <summary>
	/// Варианты выбора структуры данных
	/// </summary>
	enum Actions
	{
		/// <summary>
		/// АВЛ-дерево
		/// </summary>
		AVLTree = 1,

		/// <summary>
		/// Красно-черное дерево
		/// </summary>
		RedBlackTree = 2,

		/// <summary>
		/// Выход из программы
		/// </summary>
		Exit = 3
	};
	setlocale(LC_ALL, "ru");
	while (true)
	{
		cout << "Choose data structure:\n"
			<< "1) AVL tree\n"
			<< "2) Red-black tree \n"
			<< "3) Exit\n";
		int option = Console::ReadInt("");
		switch (option)
		{
			case AVLTree:
			{
				AVLTreeMenu();
				break;
			}

			case RedBlackTree:
			{
				RBTreeMenu();
				break;
			}

			case Exit:
			{
				return;
			}

			default:
			{
				cout << "Try again!\n";
				break;
			}
		}
	}
}

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
		bool isWrong = true;
		int option;
		while (isWrong)
		{
			try
			{
				option = Console::ReadInt("");
				isWrong = false;
			}
			catch (exception error)
			{
				cout << "Wrong data!\n";
			}
		}
		
		switch (option)
		{
			case Add:
			{
				bool isWrong = true;
				int key;
				while (isWrong)
				{
					try
					{
						key = 
							Console::ReadInt("Enter key of new element: ");
						isWrong = false;
					}
					catch (exception error)
					{
						cout << "Wrong data!\n";
					}
				}

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
				bool isWrong = true;
				int key;
				while (isWrong)
				{
					try
					{
						key =
							Console::ReadInt(
								"Enter key of element to delete: ");
						isWrong = false;
					}
					catch (exception error)
					{
						cout << "Wrong data!\n";
					}
				}
				
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
				bool isWrong = true;
				int key;
				while (isWrong)
				{
					try
					{
						key =
							Console::ReadInt(
								"Enter key of element to find: ");
						isWrong = false;
					}
					catch (exception error)
					{
						cout << "Wrong data!\n";
					}
				}
			
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
	cout << "Your red-black tree:\n";
	Print(treeUnit->GetRoot(), 0);
}

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
		bool isWrong = true;
		int option;
		while (isWrong)
		{
			try
			{
				option =
					Console::ReadInt("");
				isWrong = false;
			}
			catch (exception error)
			{
				cout << "Wrong data!\n";
			}
		}
		
		switch (option)
		{
			case AddElement:
			{
				bool isWrong = true;
				int keyOfNewNode;
				while (isWrong)
				{
					try
					{
						keyOfNewNode =
							Console::ReadInt(
								"Enter key of new element: ");
						isWrong = false;
					}
					catch (exception error)
					{
						cout << "Wrong data!\n";
					}
				}
				
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
				bool isWrong = true;
				int keyToDelete;
				while (isWrong)
				{
					try
					{
						keyToDelete =
							Console::ReadInt(
								"Enter key of element to delete: ");
						isWrong = false;
					}
					catch (exception error)
					{
						cout << "Wrong data!\n";
					}
				}
				
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
				bool isWrong = true;
				int searchingKey;
				while (isWrong)
				{
					try
					{
						searchingKey =
							Console::ReadInt(
								"Enter key of element to find: ");
						isWrong = false;
					}
					catch (exception error)
					{
						cout << "Wrong data!\n";
					}
				}
				
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
					<< " Result are saved in file.\n";
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