#include "IO_Red_Black_Tree.h"

void RBTreeMenu()
{
	enum Actions
	{
		Add = 1,
		Delete = 2,
		Find = 3,
		Exit = 4
	};
	setlocale(LC_ALL, "ru");
	int option;
	int key;
	RBTree* treeUnit = new RBTree;
	cout << "Ваше красно-черное дерево:\n";
	treeUnit->PrintRBTree(treeUnit->GetRoot(), 0);
	while (true)
	{
		cout << "Выберите действие:\n1) Добавить элемент\n2) Удалить элемент\n3) Найти элемент\n4) Выйти\n";
		cin >> option;
		switch (option)
		{
			case Add:
			{
				int key;
				EnterNumber("Введите ключ добавляемого элемента: ", key);
				try
				{
					treeUnit->Insert(key);
				}
				catch (char const* error)
				{
					cerr << error << '\n';
				}
				cout << "Ваше красно-черное дерево:\n";
				treeUnit->PrintRBTree(treeUnit->GetRoot(), 0);
				break;
			}

			case Delete:
			{
				int key;
				EnterNumber("Введите ключ удаляемого элемента: ", key);
				try
				{
					treeUnit->Delete(key);
					cout << "Элемент был удален!\n";
				}
				catch (char const* error)
				{
					cerr << error << '\n';
				}
				cout << "Ваше красно-черное дерево:\n";
				treeUnit->PrintRBTree(treeUnit->GetRoot(), 0);
				break;
			}

			case Find:
			{
				int key;
				EnterNumber("Введите ключ искомого элемента: ", key);
				RBTreeNode* result = treeUnit->Find(key);
				if (result != nullptr)
				{
					cout << "Элемент с ключом " << result->Key << " имеет цвет: ";
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
				cout << "Ваше красно-черное дерево:\n";
				treeUnit->PrintRBTree(treeUnit->GetRoot(), 0);
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

void EnterNumber(string message, int& value)
{
	cout << message;
	cin >> value;
}