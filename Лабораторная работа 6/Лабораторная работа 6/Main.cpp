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
		cout << "�������� ��������� ������:\n1) AVL-������\n2) ������-������ ������\n3) �����\n";
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
			cout << "���������� �����!\n";
			break;
		}
		}
	}
}