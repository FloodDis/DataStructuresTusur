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
		/// ����� � ������� ����
		/// </summary>
		Exit = 7
	};
	srand(time(nullptr));
	setlocale(LC_ALL, "ru");
	int keyOfRoot = EnterNumber("������� ���� ����� ����������� ������: ");
	int priority = rand() % 100;
	Treap* rootNode = new Treap;
	rootNode->Root =
		CreationOfTreap(rootNode->Root,
			keyOfRoot, priority, nullptr, nullptr);
	Show("���� ��������� ������:\n", rootNode->Root);
	while (true)
	{
		cout << "�������� ��������:\n"
			<< "1) �������� ������� (����������������)\n"
			<< "2) �������� ������� (��������������)\n"
			<< "3) ����� �������\n"
			<< "4) ������� ������� (����������������)\n"
			<< "5) ������� �������(��������������)\n"
			<< "6) ������� ������\n"
			<< "7) �����\n";
		int option = EnterNumber("");
		switch (option)
		{
			case AddUnoptimized:
			{
				int key = EnterNumber("������� ���� ������ ��������: ");
				int priority = rand() % 100;
				AddInTreapUnoptimised(rootNode, key, priority);
				Show("���� ��������� ������:\n", rootNode->Root);
				break;
			}

			case AddOptimized:
			{
				int key = EnterNumber("������� ���� ������ ��������: ");
				int priority = rand() % 100;
				AddInTreapOptomised
				(rootNode, rootNode->Root, nullptr, key, priority);
				Show("���� ��������� ������:\n", rootNode->Root);
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
				Show("���� ��������� ������:\n", rootNode->Root);
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
				Show("���� ��������� ������:\n", rootNode->Root);
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
				Show("���� ��������� ������:\n", rootNode->Root);
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
					CreationOfTreap(rootNode->Root,
						keyOfRoot, priority, nullptr, nullptr);
				Show("���� ��������� ������:\n", rootNode->Root);
				break;
			}

			case Exit:
			{
				return;
			}

			default:
			{
				cout << "���������� �����!\n";
				Show("���� ��������� ������:\n", rootNode->Root);
				break;
			}
		}
	}
}

void Print(TreapNode* nodeToPrint, int tabCount)
{
	if (nodeToPrint != nullptr)
	{
		Print(nodeToPrint->Right, tabCount + 1);
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
		Print(nodeToPrint->Left, tabCount + 1);
	}
}

void Show(string message, TreapNode* nodeToPrint)
{
	cout << message;
	Print(nodeToPrint, 0);
}