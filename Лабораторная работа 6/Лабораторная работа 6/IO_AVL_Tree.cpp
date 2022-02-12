#include "IO_AVL_Tree.h"

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
	int option;
	int dataOfRoot;
	int keyOfRoot;
	cout << "Введите ключ корня AVL-дерева: ";
	cin >> keyOfRoot;
	cout << "Введите данные корня AVL-дерева: ";
	cin >> dataOfRoot;
	AVLTreeNode* rootNode = CreationOfAVLTree(keyOfRoot, dataOfRoot);
	cout << "Ваше AVL-дерево:\n";
	PrintAVLTree(rootNode, 0);
	while (true)
	{
		cout << "Выберите действие:\n1) Добавить элемент\n2) Удалить элемент\n3) Найти элемент\n4) Выйти\n";
		cin >> option;
		switch (option)
		{
			case Add:
			{
				int dataOfNewNode;
				int	keyOfNewNode;
				cout << "Введите ключ нового элемента: ";
				cin >> keyOfNewNode;
				cout << "Введите данные нового элемента: ";
				cin >> dataOfNewNode;
				try
				{
					rootNode = AddInAVLTree(rootNode, keyOfNewNode, dataOfNewNode);
				}
				catch (char const* error)
				{
					cerr << error << '\n';
				}
				cout << "Ваше AVL-дерево:\n";
				PrintAVLTree(rootNode, 0);
				break;
			}

			case Delete:
			{
				int keyToDelete;
				cout << "Введите ключ удаляемого элемента: ";
				cin >> keyToDelete;
				try
				{
					rootNode = DeleteFromAVLTree(rootNode, keyToDelete);
					cout << "Элемент был удален из дерева!\n";
				}
				catch (char const* error)
				{
					cerr << error << '\n';
				}
				cout << "Ваше AVL-дерево:\n";
				PrintAVLTree(rootNode, 0);
				break;
			}

			case Find:
			{
				AVLTreeNode* answer = nullptr;
				int searchingKey;
				cout << "Введите ключ искомого элемента: ";
				cin >> searchingKey;
				answer = ElementSearchAVL(rootNode, searchingKey);
				if (answer == nullptr)
				{
					cout << "Элемент не найден!\n";
				}
				else
				{
					cout << "Элемент с ключом " << answer->Key << " имеет данные " << answer->Data << "\n";
				}
				cout << "Ваше AVL-дерево:\n";
				PrintAVLTree(rootNode, 0);
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