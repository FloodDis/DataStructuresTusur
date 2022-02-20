#include "IOTreap.h"

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
	srand(time(nullptr));
	setlocale(LC_ALL, "ru");
	int keyOfRoot = EnterNumber("Введите ключ корня декартового дерева: ");
	int priority = rand() % 100;
	Treap* rootNode = new Treap;
	rootNode->Root =
		CreationOfTreap
		(rootNode->Root, keyOfRoot, priority, nullptr, nullptr);
	ShowTreap("Ваше декартово дерево:\n", rootNode->Root);
	while (true)
	{
		cout << "Выберите действие:\n"
			<< "1) Добавить элемент (непотимизировано)\n"
			<< "2) Добавить элемент (оптимизировано)\n3) Найти элемент\n"
			<< "4) Удалить элемент (непотимизировано)\n"
			<< "5) Удалить элемент(оптимизировано)\n6) Удалить дерево\n"
			<< "7) Разрезать дерево\n8) Слить деревья\n9) Выйти\n";
		int option = EnterNumber("");
		switch (option)
		{
			case AddUnoptimized:
			{
				int key = EnterNumber("Введите ключ нового элемента: ");
				int priority = rand() % 100;
				AddInTreapUnoptimised(rootNode, key, priority);
				ShowTreap("Ваше декартово дерево:\n", rootNode->Root);
				break;
			}

			case AddOptimized:
			{
				int key = EnterNumber("Введите ключ нового элемента: ");
				int priority = rand() % 100;
				AddInTreapOptomised
				(rootNode, rootNode->Root, nullptr, key, priority);
				ShowTreap("Ваше декартово дерево:\n", rootNode->Root);
				break;
			}

			case Find:
			{
				int key = EnterNumber("Введите ключ искомого элемента: ");
				TreapNode* answer = nullptr;
				answer = FindElementInTreap(rootNode->Root, key);
				if (answer == nullptr)
				{
					cout << "Элемент не найден!\n";
				}
				else
				{
					cout << "Элемент с ключом " << answer->Key <<
						" имеет приоритет " << answer->Priority << "\n";
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
				int key = EnterNumber("Введите ключ элемента: ");
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
				int key = EnterNumber("Введите ключ элемента: ");
				TreapNode* answer = nullptr;
				answer = FindElementInTreap(rootNode->Root, key);
				if (answer == nullptr)
				{
					cout << "\nДанного элемента нет в дереве!\n";
				}
				else
				{
					DeleteFromTreapOptimised
					(rootNode, rootNode->Root, nullptr, key);
				}
				ShowTreap("Ваше декартово дерево:\n", rootNode->Root);
				break;
			}

			case DeleteTree:
			{
				DeleteTreap(rootNode->Root);
				cout << "Ваше дерево удалено\n";
				int keyOfRoot =
					EnterNumber("Введите ключ корня декартового дерева: ");
				int priority = rand() % 100;
				rootNode->Root =
					CreationOfTreap
					(rootNode->Root, keyOfRoot, priority, nullptr, nullptr);
				ShowTreap("Ваше декартово дерево:\n", rootNode->Root);
				break;
			}

			case PrintSplitTrees:
			{
				TreapNode* left;
				TreapNode* right;
				int key = EnterNumber("Введите ключ разреразния дерева: ");
				Split(rootNode->Root, key, left, right);
				ShowTreap("Ваше левое дерево:\n", left);
				ShowTreap("Ваше правое дерево:\n", right);
				break;
			}

			case PrintMergedTree:
			{
				TreapNode* newTree = new TreapNode;
				int keyOfNewElement = EnterNumber("Введите ключ нового дерева: ";
				int priority = rand() % 100;
				newTree = 
					CreationOfTreap
					(newTree, keyOfNewElement, priority, nullptr, nullptr);
				ShowTreap("Деревья для слияния:\n", rootNode->Root);
				ShowTreap("\n", newTree);
				rootNode->Root = Merge(rootNode->Root, newTree);
				ShowTreap("Ваше слитое дерево:\n", rootNode->Root);
				break;
			}

			case Exit:
			{
				return;
			}

			default:
			{
				cout << "Попробуйте снова!\n";
				ShowTreap("Ваше декартово дерево:\n", rootNode->Root);
				break;
			}
		}
	}
}

void PrintTreap(TreapNode* nodeToPrint, int tabCount)
{
	if (nodeToPrint != nullptr)
	{
		PrintTreap(nodeToPrint->Right, tabCount + 1);
		for (int i = 0; i < tabCount; i++)
		{
			cout << "\t";
		}
		cout << "(" << nodeToPrint->Key << "; " << nodeToPrint->Priority << ")";
		if (nodeToPrint->Left != nullptr && nodeToPrint->Right != nullptr)
		{
			cout << "|\n";
		}
		if (nodeToPrint->Left == nullptr && nodeToPrint->Right != nullptr)
		{
			cout << "/\n";
		}
		if (nodeToPrint->Left != nullptr && nodeToPrint->Right == nullptr)
		{
			cout << "\\\n";
		}
		if (nodeToPrint->Left == nullptr && nodeToPrint->Right == nullptr)
		{
			cout << "\n";
		}
		PrintTreap(nodeToPrint->Left, tabCount + 1);
	}
}

void ShowTreap(string message, TreapNode* nodeToPrint)
{
	cout << message;
	PrintTreap(nodeToPrint, 0);
}