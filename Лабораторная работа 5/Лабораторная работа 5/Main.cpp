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
	setlocale(LC_ALL, "ru");
	while (true)
	{
		cout << "Выберите структуру данных:\n1) Бинарное дерево"
			<< "2) Декартово дерево\n3) Выйти\n";
		int option = EnterNumber("");
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
			}
			default:
			{
				cout << "Попробуйте снова!\n";
				break;
			}
		}
	}
}



