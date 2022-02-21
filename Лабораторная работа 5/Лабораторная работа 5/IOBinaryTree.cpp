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
	Show(rootNode);
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
				Show(rootNode);
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
				Show(rootNode);
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
				Show(rootNode);
				break;
			}

			case FindMax:
			{
				cout << "������������ ������� ��������� ������ ������: ";
				int maximumKey = MaximumBinaryTreeSearch(rootNode)->Key;
				int maximumData = MaximumBinaryTreeSearch(rootNode)->Data;
				cout << "(" << maximumKey << ", " << maximumData << ")\n";
				Show(rootNode);
				break;
			}

			case FindMin:
			{
				cout << "����������� ������� ��������� ������ ������: ";
				int minimumKey = MinimumBinaryTreeSearch(rootNode)->Key;
				int minimumData = MinimumBinaryTreeSearch(rootNode)->Data;
				cout << "(" << minimumKey << ", " << minimumData << ")\n";
				Show(rootNode);
				break;
			}

			case Exit:
			{
				return;
			}

			default:
			{
				cout << "���������� �����!\n";
				Show(rootNode);
				break;
			}
		}
	}
}

void Print(BinaryTreeNode* rootNode, int tabCount)
{
	if (rootNode != nullptr)
	{
		Print(rootNode->Right, tabCount + 1);
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
		Print(rootNode->Left, tabCount + 1);
	}
}

void Show(BinaryTreeNode* rootNode)
{
	cout << "���� �������� ������ ������:\n";
	Print(rootNode, 0);
}