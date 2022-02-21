#include "IOBinaryTree.h"
#include "IOTreap.h"
#include <iostream>
using namespace std;

void MainMenu();

void main()
{
	MainMenu();
}

void MainMenu()
{
	/// <summary>
	/// Выбор структуры данных
	/// </summary>
	enum Actions
	{
		/// <summary>
		/// Бинарное дерево
		/// </summary>
		BinaryTree=1,

		/// <summary>
		/// Декартово дерево
		/// </summary>
		Treap,

		/// <summary>
		/// Выйти из программы
		/// </summary>
		Exit
	};
	setlocale(LC_ALL, "ru");
	while (true)
	{
		cout << "Выберите структуру данных:"
			<< "\n1) Бинарное дерево"
			<< "\n2) Декартово дерево"
			<< "\n3) Выйти\n";
		int option = EnterNumber("");
		switch (option)
		{
			case BinaryTree:
			{
				BinaryTreeMenu();
				break;
			}
			case Treap:
			{
				TreapMenu();
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



