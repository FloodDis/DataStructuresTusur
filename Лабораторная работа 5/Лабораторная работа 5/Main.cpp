#include "IOBinaryTree.h"
#include "Treap.h"
#include <iostream>
using namespace std;
void MainMenu();
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
	EnterNumber("Введите ключ корня декартового дерева: ", keyOfRoot);
	priority = rand() % 100;
	Treap* rootNode = new Treap;
	rootNode->Root = CreationOfTreap(rootNode->Root, keyOfRoot, priority, nullptr, nullptr);
	ShowTreap("Ваше декартово дерево:\n", rootNode->Root);
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
				EnterNumber("Введите ключ нового элемента: ", key);
				priority = rand() % 100;
				AddInTreapUnoptimised(rootNode, key, priority);
				ShowTreap("Ваше декартово дерево:\n", rootNode->Root);
				break;
			}
			case AddOptimized:
			{
				int key;
				int priority;
				EnterNumber("Введите ключ нового элемента: ", key);
				priority = rand() % 100;
				AddInTreapOptomised(rootNode, rootNode->Root, nullptr, key, priority);
				ShowTreap("Ваше декартово дерево:\n", rootNode->Root);
				break;
			}
			case Find:
			{
				int key;
				EnterNumber("Введите ключ искомого элемента: ", key);
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
				EnterNumber("Введите ключ элемента: ", key);
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
				EnterNumber("Введите ключ удаляемого элемента: ", key);
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
				EnterNumber("Введите ключ корня декартового дерева: ", keyOfRoot);
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
				EnterNumber("Введите ключ разреразния дерева: ", key);
				Split(rootNode->Root, key, left, right);
				ShowTreap("Ваше левое дерево:\n", left);
				ShowTreap("Ваше правое дерево:\n", right);
				break;
			}
			case PrintMergedTree:
			{
				TreapNode* newTree = new TreapNode;
				int keyOfNewElement;
				EnterNumber("Введите ключ нового дерева: ", keyOfNewElement);
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