#include "IO_AVL_Tree.h"
using namespace std;

void MainMenu();
void main()
{
	MainMenu();
}

void MainMenu()
{
	/// <summary>
	/// Варианты выбора структуры данных
	/// </summary>
	enum Actions
	{
		/// <summary>
		/// АВЛ-дерево
		/// </summary>
		AVLTree = 1,

		/// <summary>
		/// Красно-черное дерево
		/// </summary>
		RedBlackTree = 2,

		/// <summary>
		/// Выход из программы
		/// </summary>
		Exit = 3
	};
	setlocale(LC_ALL, "ru");
	int option;
	while (true)
	{
		EnterNumber("Выберите структуру данных:\n1) AVL-дерево\n2) Красно-черное дерево\n3) Выйти\n", option);
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