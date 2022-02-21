#include "IOAVLTree.h"
#include "IORedBlackTree.h"
using namespace std;

void MainMenu();

//TODO: лишняя сложность
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
		cout << "Выберите структуру данных:\n1) AVL-дерево\n"
			<< "2) Красно-черное дерево\n3) Выйти\n";
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
				cout << "Попробуйте снова!\n";
				break;
			}
		}
	}
}