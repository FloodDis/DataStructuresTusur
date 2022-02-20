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