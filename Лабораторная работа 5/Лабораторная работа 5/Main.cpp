#include "Binary_tree.h"
#include "Treap.h"
#include <iostream>
using namespace std;
void MainMenu();
void BinaryTreeMenu();
void TreapMenu();
void main()
{
	MainMenu();
}

void MainMenu()
{
	setlocale(LC_ALL, "ru");
	int option;
	while (true)
	{
		EnterNumber("Выберите структуру данных:\n1) Бинарное дерево\n2) Декартово дерево\n3) Выйти\n", option);
		switch (option)
		{
			case 1:
			{
				BinaryTreeMenu();
				break;
			}
			case 2:
			{
				TreapMenu();
				break;
			}
			case 3:
			{
				return;
				break;
			}
			default:
			{
				cout << "Попробуйте снова!\n";
				break;
			}
		}
	}

}

void BinaryTreeMenu()
{
	/// <summary>
	/// Действия, которые можно совершить с бинарным деревом поиска
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
		/// Найти максимальный элемент
		/// </summary>
		FindMax = 4,

		/// <summary>
		/// Найти минимальный элемент 
		/// </summary>
		FindMin = 5,

		/// <summary>
		/// Выйти в главное меню
		/// </summary>
		Exit = 6
	};
	setlocale(LC_ALL, "ru");
	int option;
	int dataOfRoot;
	int keyOfRoot;
	EnterNumber("Введите ключ корня бинарного дерева: ", keyOfRoot);
	EnterNumber("Введите данные корня бинарного дерева: ", dataOfRoot);
	BinaryTreeNode* rootNode = CreationOfBinaryTree(keyOfRoot, dataOfRoot);
	ShowBinaryTree(rootNode);
	while (true)
	{
		cout << "Выберите действие:\n1) Добавить элемент\n2) Удалить элемент\n3) Найти элемент\n";
		cout << "4) Найти максимум дерева\n5) Найти минимум дерева\n6) Выйти\n";
		cin >> option;
		switch (option)
		{
			case Add:
			{
				int dataOfNewNode;
				int keyOfNewNode;
				EnterNumber("Введите ключ нового элемента: ", keyOfNewNode);
				EnterNumber("Введите данные нового элемента: ", dataOfNewNode);
				rootNode = AddInBinaryTree(rootNode, keyOfNewNode, dataOfNewNode);
				ShowBinaryTree(rootNode);
				break;
			}
			case Delete:
			{
				int keyToDelete;
				if (IsBinaryTreeEmpty(rootNode))
				{
					cout << "\nДерево пусто!\n";
					break;
				}
				EnterNumber("Введите ключ удаляемого элемента: ", keyToDelete);
				rootNode = DeleteFromBinaryTree(rootNode, keyToDelete);
				ShowBinaryTree(rootNode);
				break;
			}
			case Find:
			{
				int searchingKey;
				EnterNumber("Введите ключ искомого элемента: ", searchingKey);
				BinaryTreeNode* answer = nullptr;
				answer = BinaryTreeElementSearch(rootNode, searchingKey);
				if (answer == nullptr)
				{
					cout << "Элемент не найден!\n";
				}
				else
				{
					cout << "Элемент с ключем " << answer->Key << " имеет данные " << answer->Data << "\n";
				}
				ShowBinaryTree(rootNode);
				break;
			}
			case FindMax:
			{

				cout << "Максимальный элемент вашего бинарного дерева поиска: ";
				cout << "(" << MaximumBinaryTreeSearch(rootNode)->Key << ", " << MaximumBinaryTreeSearch(rootNode)->Data << ")";
				ShowBinaryTree(rootNode);
				break;
			}
			case FindMin:
			{
				cout << "Миниимальный элемент вашего бинарного дерева поиска: ";
				cout << "(" << MinimumBinaryTreeSearch(rootNode)->Key << ", " << MinimumBinaryTreeSearch(rootNode)->Data << ")";
				ShowBinaryTree(rootNode);
				break;
			}
			case Exit:
			{
				return;
				break;
			}
			default:
			{
				cout << "Попробуйте снова!\n";
				break;
			}
		}
	}
}

void TreapMenu()
{
	/// <summary>
	/// Действия, которые можно совершить с декартовым деревом
	/// </summary>
	enum Actions
	{
		/// <summary>
		/// Добавить элемент (неоптимизированно)(1 split, 2 merge)
		/// </summary>
		AddUnoptimized = 1,

		/// <summary>
		/// Добавить элемент (оптимизированно)(1 merge)
		/// </summary>
		AddOptimized = 2,

		/// <summary>
		/// Найти элемент 
		/// </summary>
		Find = 3,

		/// <summary>
		/// Удалить элемент (непотимизированно)(2 split, 1 merge)
		/// </summary>
		DeleteUnoptimized = 4,

		/// <summary>
		/// Удалить элемент (оптимизированно)(1 merge) 
		/// </summary>
		DeleteOptimized = 5,

		/// <summary>
		/// Удалить дерево 
		/// </summary>
		DeleteTree = 6,

		/// <summary>
		/// Вывод разрезанных деревьев на экран
		/// </summary>
		PrintSplitTrees = 7,

		/// <summary>
		/// Вывод слитых деревьев на экран
		/// </summary>
		PrintMergedTree = 8,

		/// <summary>
		/// Выход в главное меню
		/// </summary>
		Exit = 9
	};
	srand(time(NULL));
	setlocale(LC_ALL, "ru");
	int keyOfRoot; 
	int dataOfRoot;
	int priority;
	int option;
	cout << "Введите ключ корня декартового дерева: ";
	cin >> keyOfRoot;
	priority = rand() % 100;
	Treap* rootNode = new Treap;
	rootNode->Root = CreationOfTreap(rootNode->Root, keyOfRoot, priority, nullptr, nullptr);
	cout << "Ваше декартово дерево: \n";
	PrintTreap(rootNode->Root);
	while (true)
	{
		cout << "Выберите действие:\n1) Добавить элемент (непотимизировано)\n2) Добавить элемент (оптимизировано)\n";
		cout << "3) Найти элемент\n4) Удалить элемент (непотимизировано)\n5) Удалить элемент(оптимизировано)\n6) Удалить дерево\n";
		cout << "7) Разрезать дерево\n8) Слить деревья\n9) Выйти\n";
		cin >> option;
		switch (option)
		{
			case AddUnoptimized:
			{
				int key;
				int priority;
				cout << "Введите ключ нового элемента: ";
				cin >> key;
				priority = rand() % 100;
				AddInTreapUnoptimised(rootNode, key, priority);
				ShowTreap("Ваше декартово дерево:\n", rootNode->Root);
				break;
			}
			case AddOptimized:
			{
				int key;
				int priority;
				cout << "Введите ключ нового элемента: ";
				cin >> key;
				priority = rand() % 100;
				AddInTreapOptomised(rootNode, rootNode->Root, nullptr, key, priority);
				ShowTreap("Ваше декартово дерево:\n", rootNode->Root);
				break;
			}
			case Find:
			{
				int key;
				cout << "Введите ключ искомого элемента: ";
				cin >> key;
				TreapNode* answer = nullptr;
				answer = FindElementInTreap(rootNode->Root, key);
				if (answer == nullptr)
				{
					cout << "Элемент не найден!\n";
				}
				else
				{
					cout << "Элемент с ключем " << answer->Key << " имеет приоритет " << answer->Priority << "\n";
				}
				ShowTreap("Ваше декартово дерево:\n", rootNode->Root);
				break;
			}
			case DeleteUnoptimized:
			{
				if (IsTreapEmpty(rootNode))
				{
					cout << "\nДерево пусто!\n";
					break;
				}
				int key;
				cout << "Введите ключ элемента: ";
				cin >> key;
				TreapNode* answer = nullptr;
				answer = FindElementInTreap(rootNode->Root, key);
				if (answer == nullptr)
				{
					cout << "\nДанного элемента нет в дереве!\n";
				}
				else
				{
					DeleteFromTreapUnoptimised(rootNode, key);
				}
				ShowTreap("Ваше декартово дерево:\n", rootNode->Root);
				break;
			}
			case DeleteOptimized:
			{
				if (IsTreapEmpty(rootNode))
				{
					cout << "\nДерево пусто!\n";
					break;
				}
				int key;
				cout << "Введите ключ удаляемого элемента: ";
				cin >> key;
				TreapNode* answer = nullptr;
				answer = FindElementInTreap(rootNode->Root, key);
				if (answer == nullptr)
				{
					cout << "\nДанного элемента нет в дереве!\n";
				}
				else
				{
					DeleteFromTreapOptimised(rootNode, rootNode->Root, nullptr, key);
				}
				ShowTreap("Ваше декартово дерево:\n", rootNode->Root);
				break;
			}
			case DeleteTree:
			{
				DeleteTreap(rootNode->Root);
				cout << "Ваше дерево удалено\n";
				int keyOfRoot;
				int dataOfRoot;
				int priority;
				int option;
				cout << "Введите ключ корня декартового дерева: ";
				cin >> keyOfRoot;
				priority = rand() % 100;
				rootNode->Root = CreationOfTreap(rootNode->Root, keyOfRoot, priority, nullptr, nullptr);
				ShowTreap("Ваше декартово дерево:\n", rootNode->Root);
				break;
			}
			case PrintSplitTrees:
			{
				TreapNode* left;
				TreapNode* right;
				int key;
				cout << "Введите ключ разреразния дерева: ";
				cin >> key;
				Split(rootNode->Root, key, left, right);
				ShowTreap("Ваше левое дерево:\n", left);
				ShowTreap("Ваше правое дерево:\n", right);
				break;
			}
			case PrintMergedTree:
			{
				TreapNode* newTree = new TreapNode;
				int keyOfNewElement;
				cout << "Введите ключ нового дерева: ";
				cin >> keyOfNewElement;
				int priority = rand() % 100;
				newTree = CreationOfTreap(newTree, keyOfNewElement, priority, nullptr, nullptr);
				ShowTreap("Деревья для слияния:\n", rootNode->Root);
				ShowTreap("\n", newTree);
				rootNode->Root = Merge(rootNode->Root, newTree);
				ShowTreap("Ваше слитое дерево:\n", rootNode->Root);
				break;
			}
			case Exit:
			{
				return;
				break;
			}
			default:
			{
				cout << "Попробуйте снова!\n";
				break;
			}
		}
	}
}