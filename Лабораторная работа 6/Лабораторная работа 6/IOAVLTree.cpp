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
		/// Выйти в главное меню
		/// </summary>
		Exit = 4
	};

	setlocale(LC_ALL, "ru");
	int dataOfRoot = EnterNumber("Введите данные корня AVL-дерева: ");
	int keyOfRoot = EnterNumber("Введите ключ корня AVL-дерева: ");
	AVLTreeNode* rootNode = CreationOfAVLTree(keyOfRoot, dataOfRoot);
	ShowAVLTree(rootNode);
	while (true)
	{
		cout << "Выберите действие:\n1) Добавить элемент\n"
			<< "2) Удалить элемент\n3) Найти элемент\n4) Выйти\n";
		int option = EnterNumber("");
		switch (option)
		{
			case Add:
			{
				int dataOfNewNode =
					EnterNumber("Введите данные нового элемента: ");
				int	keyOfNewNode =
					EnterNumber("Введите ключ нового элемента: ");
				try
				{
					rootNode =
						AddInAVLTree(rootNode, keyOfNewNode, dataOfNewNode);
				}
				catch (char const* error)
				{
					cout << error << '\n';
				}
				ShowAVLTree(rootNode);
				break;
			}

			case Delete:
			{
				int keyToDelete =
					EnterNumber("Введите ключ удаляемого элемента: ");
				try
				{
					rootNode = DeleteFromAVLTree(rootNode, keyToDelete);
					cout << "Элемент был удален из дерева!\n";
				}
				catch (char const* error)
				{
					cout << error << '\n';
				}
				ShowAVLTree(rootNode);
				break;
			}

			case Find:
			{
				AVLTreeNode* answer = nullptr;
				int searchingKey = 
					EnterNumber("Введите ключ искомого элемента: ");
				answer = ElementSearchAVL(rootNode, searchingKey);
				if (answer == nullptr)
				{
					cout << "Элемент не найден!\n";
				}
				else
				{
					cout << "Элемент с ключом " << answer->Key 
						<< " имеет данные " << answer->Data << "\n";
				}
				ShowAVLTree(rootNode);
				break;
			}

			case Exit:
			{
				return;
			}

			default:
			{
				cout << "Попробуйте снова!\n";
				break;
			}
		}
	}
}

//TODO: именование, см. лаб 3
void ShowAVLTree(AVLTreeNode* rootNode)
{
	cout << "Ваше АВЛ-дерево:\n";
	PrintAVLTree(rootNode, 0);
}

void PrintAVLTree(AVLTreeNode* rootNode, int tabCount)
{
	if (rootNode != nullptr)
	{
		PrintAVLTree(rootNode->Right, tabCount + 1);
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
		PrintAVLTree(rootNode->Left, tabCount + 1);
	}
}