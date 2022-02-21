#include "IORedBlackTree.h"

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
		/// Выйти в главное меню
		/// </summary>
		Exit = 4
	};

	setlocale(LC_ALL, "ru");
	RBTree* treeUnit = new RBTree;
	Show(treeUnit);
	while (true)
	{
		cout << "Выберите действие:"
			<< "\n1) Добавить элемент"
			<< "\n2) Удалить элемент"
			<< "\n3) Найти элемент"
			<< "\n4) Выйти\n";
		int option = EnterNumber("");
		switch (option)
		{
			case Add:
			{
				int key =
					EnterNumber("Введите ключ добавляемого элемента: ");
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
				int key =
					EnterNumber("Введите ключ удаляемого элемента: ");
				try
				{
					treeUnit->Delete(key);
					cout << "Элемент был удален!\n";
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
				int key = EnterNumber("Введите ключ искомого элемента: ");
				RBTreeNode* result = treeUnit->Find(key);
				if (result != nullptr)
				{
					cout << "Элемент с ключом " << result->Key
						<< " имеет цвет: ";
					if (result->IsBlack)
					{
						cout << "Черный\n";
					}
					else
					{
						cout << "Красный\n";
					}
				}
				else
				{
					cout << "Такого элемента нет в дереве!\n";
				}
				Show(treeUnit);
				break;
			}

			case Exit:
			{
				return;
			}

			default:
			{
				cout << "Попробуйте снова!\n";
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
	cout << "Ваше красно-черное дерево:\n";
	Print(treeUnit->GetRoot(), 0);
}