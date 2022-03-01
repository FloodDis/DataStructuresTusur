#include "IOBinaryTree.h"

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
	int dataOfRoot =
		EnterNumber("Введите данные корня бинарного дерева: ");
	int keyOfRoot = EnterNumber("Введите ключ корня бинарного дерева: ");
	BinaryTreeNode* rootNode = CreationOfBinaryTree(keyOfRoot, dataOfRoot);
	Show(rootNode);
	while (true)
	{
		cout << "Выберите действие:\n"
			<< "1) Добавить элемент\n"
			<< "2) Удалить элемент\n"
			<< "3) Найти элемент\n"
			<< "4) Найти максимум дерева\n"
			<< "5) Найти минимум дерева\n"
			<< "6) Выйти\n";
		int option = EnterNumber("");
		switch (option)
		{
			case Add:
			{
				int dataOfNewNode =
					EnterNumber("Введите данные нового элемента: ");
				int keyOfNewNode =
					EnterNumber("Введите ключ нового элемента: ");
				rootNode =
					AddInBinaryTree(rootNode, keyOfNewNode, dataOfNewNode);
				Show(rootNode);
				break;
			}

			case Delete:
			{
				int keyToDelete =
					EnterNumber("Введите ключ удаляемого элемента: ");
				if (IsBinaryTreeEmpty(rootNode))
				{
					cout << "\nДерево пусто!\n";
					break;
				}
				rootNode = DeleteFromBinaryTree(rootNode, keyToDelete);
				Show(rootNode);
				break;
			}

			case Find:
			{
				int searchingKey =
					EnterNumber("Введите ключ искомого элемента: ");
				BinaryTreeNode* answer = nullptr;
				answer = BinaryTreeElementSearch(rootNode, searchingKey);
				if (answer == nullptr)
				{
					cout << "Элемент не найден!\n";
				}
				else
				{
					cout << "Элемент с ключем " << answer->Key
						<< " имеет данные " <<
						answer->Data << "\n";
				}
				Show(rootNode);
				break;
			}

			case FindMax:
			{
				cout << "Максимальный элемент бинарного дерева поиска: ";
				int maximumKey = MaximumBinaryTreeSearch(rootNode)->Key;
				int maximumData = MaximumBinaryTreeSearch(rootNode)->Data;
				cout << "(" << maximumKey << ", " << maximumData << ")\n";
				Show(rootNode);
				break;
			}

			case FindMin:
			{
				cout << "Минимальный элемент бинарного дерева поиска: ";
				int minimumKey = MinimumBinaryTreeSearch(rootNode)->Key;
				int minimumData = MinimumBinaryTreeSearch(rootNode)->Data;
				cout << "(" << minimumKey << ", " << minimumData << ")\n";
				Show(rootNode);
				break;
			}

			case Exit:
			{
				return;
			}

			default:
			{
				cout << "Попробуйте снова!\n";
				Show(rootNode);
				break;
			}
		}
	}
}

void Print(BinaryTreeNode* rootNode, int tabCount)
{
	if (rootNode != nullptr)
	{
		Print(rootNode->Right, tabCount + 1);
		for (int i = 0; i < tabCount; i++)
		{
			cout << "\t";
		}
		cout << "(" << rootNode->Key << "; " << rootNode->Data << ")";
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

void Show(BinaryTreeNode* rootNode)
{
	cout << "Ваше бинарное дерево поиска:\n";
	Print(rootNode, 0);
}