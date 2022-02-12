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
	/// �������� ������ ��������� ������
	/// </summary>
	enum Actions
	{
		/// <summary>
		/// ���-������
		/// </summary>
		AVLTree = 1,

		/// <summary>
		/// ������-������ ������
		/// </summary>
		RedBlackTree = 2,

		/// <summary>
		/// ����� �� ���������
		/// </summary>
		Exit = 3
	};
	setlocale(LC_ALL, "ru");
	int option;
	while (true)
	{
		EnterNumber("�������� ��������� ������:\n1) AVL-������\n2) ������-������ ������\n3) �����\n", option);
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