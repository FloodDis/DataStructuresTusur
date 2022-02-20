#include "IOBinaryTree.h"

void BinaryTreeMenu()
{
	/// <summary>
	/// ��������, ������� ����� ��������� � �������� ������� ������
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
		/// ����� ������������ �������
		/// </summary>
		FindMax = 4,

		/// <summary>
		/// ����� ����������� ������� 
		/// </summary>
		FindMin = 5,

		/// <summary>
		/// ����� � ������� ����
		/// </summary>
		Exit = 6
	};
	setlocale(LC_ALL, "ru");
	int option;
	int dataOfRoot;
	int keyOfRoot;
	EnterNumber("������� ���� ����� ��������� ������: ", keyOfRoot);
	EnterNumber("������� ������ ����� ��������� ������: ", dataOfRoot);
	BinaryTreeNode* rootNode = CreationOfBinaryTree(keyOfRoot, dataOfRoot);
	ShowBinaryTree(rootNode);
	while (true)
	{
		cout << "�������� ��������:\n1) �������� �������\n2) ������� �������\n3) ����� �������\n";
		cout << "4) ����� �������� ������\n5) ����� ������� ������\n6) �����\n";
		cin >> option;
		switch (option)
		{
			case Add:
			{
				int dataOfNewNode;
				int keyOfNewNode;
				EnterNumber("������� ���� ������ ��������: ", keyOfNewNode);
				EnterNumber("������� ������ ������ ��������: ", dataOfNewNode);
				rootNode = AddInBinaryTree(rootNode, keyOfNewNode, dataOfNewNode);
				ShowBinaryTree(rootNode);
				break;
			}

			case Delete:
			{
				int keyToDelete;
				if (IsBinaryTreeEmpty(rootNode))
				{
					cout << "\n������ �����!\n";
					break;
				}
				EnterNumber("������� ���� ���������� ��������: ", keyToDelete);
				rootNode = DeleteFromBinaryTree(rootNode, keyToDelete);
				ShowBinaryTree(rootNode);
				break;
			}

			case Find:
			{
				int searchingKey;
				EnterNumber("������� ���� �������� ��������: ", searchingKey);
				BinaryTreeNode* answer = nullptr;
				answer = BinaryTreeElementSearch(rootNode, searchingKey);
				if (answer == nullptr)
				{
					cout << "������� �� ������!\n";
				}
				else
				{
					cout << "������� � ������ " << answer->Key << " ����� ������ " << answer->Data << "\n";
				}
				ShowBinaryTree(rootNode);
				break;
			}

			case FindMax:
			{

				cout << "������������ ������� ������ ��������� ������ ������: ";
				cout << "(" << MaximumBinaryTreeSearch(rootNode)->Key << ", " << MaximumBinaryTreeSearch(rootNode)->Data << ")";
				ShowBinaryTree(rootNode);
				break;
			}

			case FindMin:
			{
				cout << "������������ ������� ������ ��������� ������ ������: ";
				cout << "(" << MinimumBinaryTreeSearch(rootNode)->Key << ", " << MinimumBinaryTreeSearch(rootNode)->Data << ")";
				ShowBinaryTree(rootNode);
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