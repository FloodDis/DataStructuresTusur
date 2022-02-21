#include "IO_Red_Black_Tree.h"

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
	ShowRBTree(treeUnit);
	while (true)
	{
		cout << "Выберите действие:\n1) Добавить элемент\n"
			<<"2) Удалить элемент\n3) Найти элемент\n4) Выйти\n";
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
				ShowRBTree(treeUnit);
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
				ShowRBTree(treeUnit);
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
				ShowRBTree(treeUnit);
				break;
			}

			case Exit:
			{
				return;
			}

			default:
			{
				cout << "Попробуйте снова!\n";
				ShowRBTree(treeUnit);
				break;
			}
		}
	}
}

//TODO: именование, см. лаб 3
void ShowRBTree(RBTree* treeUnit)
{
	cout << "Ваше красно-черное дерево:\n";
	treeUnit->PrintRBTree(treeUnit->GetRoot(), 0);
}