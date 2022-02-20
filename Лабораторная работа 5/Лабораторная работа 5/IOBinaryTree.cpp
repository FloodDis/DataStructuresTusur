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
	int dataOfRoot = 
		EnterNumber("������� ������ ����� ��������� ������: ");
	int keyOfRoot = EnterNumber("������� ���� ����� ��������� ������: ");
	BinaryTreeNode* rootNode = CreationOfBinaryTree(keyOfRoot, dataOfRoot);
	ShowBinaryTree(rootNode);
	while (true)
	{
		cout << "�������� ��������:\n1) �������� �������\n"
			<< "2) ������� �������\n3) ����� �������\n"
			<< "4) ����� �������� ������\n5) ����� ������� ������\n"
			<< "6) �����\n";
		int option = EnterNumber("");
		switch (option)
		{
			case Add:
			{
				int dataOfNewNode =
					EnterNumber("������� ������ ������ ��������: ");
				int keyOfNewNode =
					EnterNumber("������� ���� ������ ��������: ");
				rootNode =
					AddInBinaryTree(rootNode, keyOfNewNode, dataOfNewNode);
				ShowBinaryTree(rootNode);
				break;
			}

			case Delete:
			{
				int keyToDelete =
					EnterNumber("������� ���� ���������� ��������: ");
				if (IsBinaryTreeEmpty(rootNode))
				{
					cout << "\n������ �����!\n";
					break;
				}
				rootNode = DeleteFromBinaryTree(rootNode, keyToDelete);
				ShowBinaryTree(rootNode);
				break;
			}

			case Find:
			{
				int searchingKey =
					EnterNumber("������� ���� �������� ��������: ");
				BinaryTreeNode* answer = nullptr;
				answer = BinaryTreeElementSearch(rootNode, searchingKey);
				if (answer == nullptr)
				{
					cout << "������� �� ������!\n";
				}
				else
				{
					cout << "������� � ������ " << answer->Key
						<< " ����� ������ " <<
						answer->Data << "\n";
				}
				ShowBinaryTree(rootNode);
				break;
			}

			case FindMax:
			{
				cout << "������������ ������� ��������� ������ ������: ";
				int maximumKey = MaximumBinaryTreeSearch(rootNode)->Key;
				int maximumData = MaximumBinaryTreeSearch(rootNode)->Data;
				cout << "(" << maximumKey << ", " << maximumData << ")\n";
				ShowBinaryTree(rootNode);
				break;
			}

			case FindMin:
			{
				cout << "����������� ������� ��������� ������ ������: ";
				int minimumKey = MinimumBinaryTreeSearch(rootNode)->Key;
				int minimumData = MinimumBinaryTreeSearch(rootNode)->Data;
				cout << "(" << minimumKey << ", " << minimumData << ")\n";
				ShowBinaryTree(rootNode);
				break;
			}

			case Exit:
			{
				return;
			}

			default:
			{
				cout << "���������� �����!\n";
				ShowBinaryTree(rootNode);
				break;
			}
		}
	}
}

void PrintBinaryTree(BinaryTreeNode* rootNode, int tabCount)
{
	if (rootNode != nullptr)
	{
		PrintBinaryTree(rootNode->Right, tabCount + 1);
		for (int i = 0; i < tabCount; i++)
		{
			cout << "\t";
		}
		cout << "(" << rootNode->Key << "; " << rootNode->Data << ")";
		if (rootNode->Left != nullptr && rootNode->Right != nullptr)
		{
			cout << "|\n";
		}
		if (rootNode->Left == nullptr && rootNode->Right != nullptr)
		{
			cout << "/\n";
		}
		if (rootNode->Left != nullptr && rootNode->Right == nullptr)
		{
			cout << "\\\n";
		}
		if (rootNode->Left == nullptr && rootNode->Right == nullptr)
		{
			cout << "\n";
		}
		PrintBinaryTree(rootNode->Left, tabCount + 1);
	}
}

void ShowBinaryTree(BinaryTreeNode* rootNode)
{
	cout << "���� �������� ������ ������:\n";
	PrintBinaryTree(rootNode, 0);
}