#include "IOBinaryTree.h"
#include "Treap.h"
#include <iostream>
using namespace std;

void MainMenu();

void main()
{
	MainMenu();
}

void MainMenu()
{
	setlocale(LC_ALL, "ru");
	int option;
	while (true)
	{
		EnterNumber("Выберите структуру данных:\n1) Бинарное дерево\n2) Декартово дерево\n3) Выйти\n", option);
		switch (option)
		{
			case 1:
			{
				BinaryTreeMenu();
				break;
			}
			case 2:
			{
				TreapMenu();
				break;
			}
			case 3:
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



