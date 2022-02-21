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
		/// Выйти в главное меню
		/// </summary>
		Exit = 4
	};

	setlocale(LC_ALL, "ru");
	int dataOfRoot = EnterNumber("Введите данные корня AVL-дерева: ");
	int keyOfRoot = EnterNumber("Введите ключ корня AVL-дерева: ");
	AVLTreeNode* rootNode = CreateTree(keyOfRoot, dataOfRoot);
	Show(rootNode);
	while (true)
	{
		cout << "Выберите действие:\n1) Добавить элемент\n"
			<< "2) Удалить элемент\n3) Найти элемент\n4) Выйти\n";
		int option = EnterNumber("");
		switch (option)
		{
			case AddElement:
			{
				int dataOfNewNode =
					EnterNumber("Введите данные нового элемента: ");
				int	keyOfNewNode =
					EnterNumber("Введите ключ нового элемента: ");
				try
				{
					rootNode = Insert(rootNode, keyOfNewNode, dataOfNewNode);
				}
				catch (char const* error)
				{
					cout << error << '\n';
				}
				Show(rootNode);
				break;
			}

			case DeleteElement:
			{
				int keyToDelete =
					EnterNumber("Введите ключ удаляемого элемента: ");
				try
				{
					rootNode = Delete(rootNode, keyToDelete);
					cout << "Элемент был удален из дерева!\n";
				}
				catch (char const* error)
				{
					cout << error << '\n';
				}
				Show(rootNode);
				break;
			}

			case FindElement:
			{
				AVLTreeNode* answer = nullptr;
				int searchingKey =
					EnterNumber("Введите ключ искомого элемента: ");
				answer = Find(rootNode, searchingKey);
				if (answer == nullptr)
				{
					cout << "Элемент не найден!\n";
				}
				else
				{
					cout << "Элемент с ключом " << answer->Key
						<< " имеет данные " << answer->Data << "\n";
				}
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

void Show(AVLTreeNode* rootNode)
{
	cout << "Ваше АВЛ-дерево:\n";
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