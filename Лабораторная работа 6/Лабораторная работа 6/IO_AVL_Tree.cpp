#include "IO_AVL_Tree.h"

void AVLTreeMenu()
{
	/// <summary>
	/// ��������, ������� ����� ��������� � ���-�������
	/// </summary>
	enum Actions
	{
		/// <summary>
		/// �������� �������
		/// </summary>
		Add = 1,

		/// <summary>
		/// ������� �������
		/// </summary>
		Delete = 2,

		/// <summary>
		/// ����� �������
		/// </summary>
		Find = 3,

		/// <summary>
		/// ����� � ������� ����
		/// </summary>
		Exit = 4
	};
	setlocale(LC_ALL, "ru");
	int option;
	int dataOfRoot;
	int keyOfRoot;
	EnterNumber("������� ���� ����� AVL-������: ", keyOfRoot);
	EnterNumber("������� ������ ����� AVL-������: ", dataOfRoot);
	AVLTreeNode* rootNode = CreationOfAVLTree(keyOfRoot, dataOfRoot);
	cout << "���� AVL-������:\n";
	PrintAVLTree(rootNode, 0);
	while (true)
	{
		EnterNumber("�������� ��������:\n1) �������� �������\n2) ������� �������\n3) ����� �������\n4) �����\n", option);
		switch (option)
		{
			case Add:
			{
				int dataOfNewNode;
				int	keyOfNewNode;
				EnterNumber("������� ���� ������ ��������: ", keyOfNewNode);
				EnterNumber("������� ������ ������ ��������: ", dataOfNewNode);
				try
				{
					rootNode = AddInAVLTree(rootNode, keyOfNewNode, dataOfNewNode);
				}
				catch (char const* error)
				{
					cerr << error << '\n';
				}
				cout << "���� AVL-������:\n";
				PrintAVLTree(rootNode, 0);
				break;
			}

			case Delete:
			{
				int keyToDelete;
				EnterNumber("������� ���� ���������� ��������: ", keyToDelete);
				try
				{
					rootNode = DeleteFromAVLTree(rootNode, keyToDelete);
					cout << "������� ��� ������ �� ������!\n";
				}
				catch (char const* error)
				{
					cerr << error << '\n';
				}
				cout << "���� AVL-������:\n";
				PrintAVLTree(rootNode, 0);
				break;
			}

			case Find:
			{
				AVLTreeNode* answer = nullptr;
				int searchingKey;
				EnterNumber("������� ���� �������� ��������: ", searchingKey);
				answer = ElementSearchAVL(rootNode, searchingKey);
				if (answer == nullptr)
				{
					cout << "������� �� ������!\n";
				}
				else
				{
					cout << "������� � ������ " << answer->Key << " ����� ������ " << answer->Data << "\n";
				}
				cout << "���� AVL-������:\n";
				PrintAVLTree(rootNode, 0);
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