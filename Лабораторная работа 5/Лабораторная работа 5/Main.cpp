#include "Binary_tree.h"
#include "Treap.h"
#include <iostream>
using namespace std;
void MainMenu();
void BinaryTreeMenu();
void TreapMenu();
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
		EnterNumber("�������� ��������� ������:\n1) �������� ������\n2) ��������� ������\n3) �����\n", option);
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
				cout << "���������� �����!\n";
				break;
			}
		}
	}

}

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

void TreapMenu()
{
	/// <summary>
	/// ��������, ������� ����� ��������� � ���������� �������
	/// </summary>
	enum Actions
	{
		/// <summary>
		/// �������� ������� (�����������������)(1 split, 2 merge)
		/// </summary>
		AddUnoptimized = 1,

		/// <summary>
		/// �������� ������� (���������������)(1 merge)
		/// </summary>
		AddOptimized = 2,

		/// <summary>
		/// ����� ������� 
		/// </summary>
		Find = 3,

		/// <summary>
		/// ������� ������� (�����������������)(2 split, 1 merge)
		/// </summary>
		DeleteUnoptimized = 4,

		/// <summary>
		/// ������� ������� (���������������)(1 merge) 
		/// </summary>
		DeleteOptimized = 5,

		/// <summary>
		/// ������� ������ 
		/// </summary>
		DeleteTree = 6,

		/// <summary>
		/// ����� ����������� �������� �� �����
		/// </summary>
		PrintSplitTrees = 7,

		/// <summary>
		/// ����� ������ �������� �� �����
		/// </summary>
		PrintMergedTree = 8,

		/// <summary>
		/// ����� � ������� ����
		/// </summary>
		Exit = 9
	};
	srand(time(NULL));
	setlocale(LC_ALL, "ru");
	int keyOfRoot; 
	int dataOfRoot;
	int priority;
	int option;
	cout << "������� ���� ����� ����������� ������: ";
	cin >> keyOfRoot;
	priority = rand() % 100;
	Treap* rootNode = new Treap;
	rootNode->Root = CreationOfTreap(rootNode->Root, keyOfRoot, priority, nullptr, nullptr);
	cout << "���� ��������� ������: \n";
	PrintTreap(rootNode->Root);
	while (true)
	{
		cout << "�������� ��������:\n1) �������� ������� (����������������)\n2) �������� ������� (��������������)\n";
		cout << "3) ����� �������\n4) ������� ������� (����������������)\n5) ������� �������(��������������)\n6) ������� ������\n";
		cout << "7) ��������� ������\n8) ����� �������\n9) �����\n";
		cin >> option;
		switch (option)
		{
			case AddUnoptimized:
			{
				int key;
				int priority;
				cout << "������� ���� ������ ��������: ";
				cin >> key;
				priority = rand() % 100;
				AddInTreapUnoptimised(rootNode, key, priority);
				ShowTreap("���� ��������� ������:\n", rootNode->Root);
				break;
			}
			case AddOptimized:
			{
				int key;
				int priority;
				cout << "������� ���� ������ ��������: ";
				cin >> key;
				priority = rand() % 100;
				AddInTreapOptomised(rootNode, rootNode->Root, nullptr, key, priority);
				ShowTreap("���� ��������� ������:\n", rootNode->Root);
				break;
			}
			case Find:
			{
				int key;
				cout << "������� ���� �������� ��������: ";
				cin >> key;
				TreapNode* answer = nullptr;
				answer = FindElementInTreap(rootNode->Root, key);
				if (answer == nullptr)
				{
					cout << "������� �� ������!\n";
				}
				else
				{
					cout << "������� � ������ " << answer->Key << " ����� ��������� " << answer->Priority << "\n";
				}
				ShowTreap("���� ��������� ������:\n", rootNode->Root);
				break;
			}
			case DeleteUnoptimized:
			{
				if (IsTreapEmpty(rootNode))
				{
					cout << "\n������ �����!\n";
					break;
				}
				int key;
				cout << "������� ���� ��������: ";
				cin >> key;
				TreapNode* answer = nullptr;
				answer = FindElementInTreap(rootNode->Root, key);
				if (answer == nullptr)
				{
					cout << "\n������� �������� ��� � ������!\n";
				}
				else
				{
					DeleteFromTreapUnoptimised(rootNode, key);
				}
				ShowTreap("���� ��������� ������:\n", rootNode->Root);
				break;
			}
			case DeleteOptimized:
			{
				if (IsTreapEmpty(rootNode))
				{
					cout << "\n������ �����!\n";
					break;
				}
				int key;
				cout << "������� ���� ���������� ��������: ";
				cin >> key;
				TreapNode* answer = nullptr;
				answer = FindElementInTreap(rootNode->Root, key);
				if (answer == nullptr)
				{
					cout << "\n������� �������� ��� � ������!\n";
				}
				else
				{
					DeleteFromTreapOptimised(rootNode, rootNode->Root, nullptr, key);
				}
				ShowTreap("���� ��������� ������:\n", rootNode->Root);
				break;
			}
			case DeleteTree:
			{
				DeleteTreap(rootNode->Root);
				cout << "���� ������ �������\n";
				int keyOfRoot;
				int dataOfRoot;
				int priority;
				int option;
				cout << "������� ���� ����� ����������� ������: ";
				cin >> keyOfRoot;
				priority = rand() % 100;
				rootNode->Root = CreationOfTreap(rootNode->Root, keyOfRoot, priority, nullptr, nullptr);
				ShowTreap("���� ��������� ������:\n", rootNode->Root);
				break;
			}
			case PrintSplitTrees:
			{
				TreapNode* left;
				TreapNode* right;
				int key;
				cout << "������� ���� ����������� ������: ";
				cin >> key;
				Split(rootNode->Root, key, left, right);
				ShowTreap("���� ����� ������:\n", left);
				ShowTreap("���� ������ ������:\n", right);
				break;
			}
			case PrintMergedTree:
			{
				TreapNode* newTree = new TreapNode;
				int keyOfNewElement;
				cout << "������� ���� ������ ������: ";
				cin >> keyOfNewElement;
				int priority = rand() % 100;
				newTree = CreationOfTreap(newTree, keyOfNewElement, priority, nullptr, nullptr);
				ShowTreap("������� ��� �������:\n", rootNode->Root);
				ShowTreap("\n", newTree);
				rootNode->Root = Merge(rootNode->Root, newTree);
				ShowTreap("���� ������ ������:\n", rootNode->Root);
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