#include "IOTreap.h"

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
	srand(time(nullptr));
	setlocale(LC_ALL, "ru");
	int keyOfRoot = EnterNumber("������� ���� ����� ����������� ������: ");
	int priority = rand() % 100;
	Treap* rootNode = new Treap;
	rootNode->Root =
		CreationOfTreap
		(rootNode->Root, keyOfRoot, priority, nullptr, nullptr);
	ShowTreap("���� ��������� ������:\n", rootNode->Root);
	while (true)
	{
		cout << "�������� ��������:\n"
			<< "1) �������� ������� (����������������)\n"
			<< "2) �������� ������� (��������������)\n3) ����� �������\n"
			<< "4) ������� ������� (����������������)\n"
			<< "5) ������� �������(��������������)\n6) ������� ������\n"
			<< "7) ��������� ������\n8) ����� �������\n9) �����\n";
		int option = EnterNumber("");
		switch (option)
		{
			case AddUnoptimized:
			{
				int key = EnterNumber("������� ���� ������ ��������: ");
				int priority = rand() % 100;
				AddInTreapUnoptimised(rootNode, key, priority);
				ShowTreap("���� ��������� ������:\n", rootNode->Root);
				break;
			}

			case AddOptimized:
			{
				int key = EnterNumber("������� ���� ������ ��������: ");
				int priority = rand() % 100;
				AddInTreapOptomised
				(rootNode, rootNode->Root, nullptr, key, priority);
				ShowTreap("���� ��������� ������:\n", rootNode->Root);
				break;
			}

			case Find:
			{
				int key = EnterNumber("������� ���� �������� ��������: ");
				TreapNode* answer = nullptr;
				answer = FindElementInTreap(rootNode->Root, key);
				if (answer == nullptr)
				{
					cout << "������� �� ������!\n";
				}
				else
				{
					cout << "������� � ������ " << answer->Key <<
						" ����� ��������� " << answer->Priority << "\n";
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
				int key = EnterNumber("������� ���� ��������: ");
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
				int key = EnterNumber("������� ���� ��������: ");
				TreapNode* answer = nullptr;
				answer = FindElementInTreap(rootNode->Root, key);
				if (answer == nullptr)
				{
					cout << "\n������� �������� ��� � ������!\n";
				}
				else
				{
					DeleteFromTreapOptimised
					(rootNode, rootNode->Root, nullptr, key);
				}
				ShowTreap("���� ��������� ������:\n", rootNode->Root);
				break;
			}

			case DeleteTree:
			{
				DeleteTreap(rootNode->Root);
				cout << "���� ������ �������\n";
				int keyOfRoot =
					EnterNumber("������� ���� ����� ����������� ������: ");
				int priority = rand() % 100;
				rootNode->Root =
					CreationOfTreap
					(rootNode->Root, keyOfRoot, priority, nullptr, nullptr);
				ShowTreap("���� ��������� ������:\n", rootNode->Root);
				break;
			}

			case PrintSplitTrees:
			{
				TreapNode* left;
				TreapNode* right;
				int key = EnterNumber("������� ���� ����������� ������: ");
				Split(rootNode->Root, key, left, right);
				ShowTreap("���� ����� ������:\n", left);
				ShowTreap("���� ������ ������:\n", right);
				break;
			}

			case PrintMergedTree:
			{
				TreapNode* newTree = new TreapNode;
				int keyOfNewElement = EnterNumber("������� ���� ������ ������: ";
				int priority = rand() % 100;
				newTree = 
					CreationOfTreap
					(newTree, keyOfNewElement, priority, nullptr, nullptr);
				ShowTreap("������� ��� �������:\n", rootNode->Root);
				ShowTreap("\n", newTree);
				rootNode->Root = Merge(rootNode->Root, newTree);
				ShowTreap("���� ������ ������:\n", rootNode->Root);
				break;
			}

			case Exit:
			{
				return;
			}

			default:
			{
				cout << "���������� �����!\n";
				ShowTreap("���� ��������� ������:\n", rootNode->Root);
				break;
			}
		}
	}
}

void PrintTreap(TreapNode* nodeToPrint, int tabCount)
{
	if (nodeToPrint != nullptr)
	{
		PrintTreap(nodeToPrint->Right, tabCount + 1);
		for (int i = 0; i < tabCount; i++)
		{
			cout << "\t";
		}
		cout << "(" << nodeToPrint->Key << "; " << nodeToPrint->Priority << ")";
		if (nodeToPrint->Left != nullptr && nodeToPrint->Right != nullptr)
		{
			cout << "|\n";
		}
		if (nodeToPrint->Left == nullptr && nodeToPrint->Right != nullptr)
		{
			cout << "/\n";
		}
		if (nodeToPrint->Left != nullptr && nodeToPrint->Right == nullptr)
		{
			cout << "\\\n";
		}
		if (nodeToPrint->Left == nullptr && nodeToPrint->Right == nullptr)
		{
			cout << "\n";
		}
		PrintTreap(nodeToPrint->Left, tabCount + 1);
	}
}

void ShowTreap(string message, TreapNode* nodeToPrint)
{
	cout << message;
	PrintTreap(nodeToPrint, 0);
}