#include "IO_AVL_Tree.h"
#include "IO_Red_Black_Tree.h"
using namespace std;

void MainMenu();
void main()
{
	MainMenu();
}

void MainMenu()
{
	enum Actions
	{
		AVLTree = 1,
		RedBlackTree = 2,
		Exit = 3
	};
	setlocale(LC_ALL, "ru");
	int option;
	while (true)
	{
		cout << "Выберите структуру данных:\n1) AVL-дерево\n2) Красно-черное дерево\n3) Выйти\n";
		cin >> option;
		switch (option)
		{
		case AVLTree:
		{
			AVLTreeMenu();
			break;
		}
		case RedBlackTree:
		{
			RBTreeMenu();
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