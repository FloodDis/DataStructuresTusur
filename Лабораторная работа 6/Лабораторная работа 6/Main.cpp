#include "IOAVLTree.h"
#include "IORedBlackTree.h"
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
	while (true)
	{
		cout << "Choose data structure:\n"
			<< "1) AVL tree\n"
			<< "2) Red-black tree \n"
			<< "3) Exit\n";
		int option = EnterNumber("");
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
			}

			default:
			{
				cout << "Try again!\n";
				break;
			}
		}
	}
}