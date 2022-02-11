#include "IO_Red_Black_Tree.h"

void RBTreeMenu()
{
	enum Actions
	{
		Add = 1,
		Delete = 2,
		Find = 3,
		Exit = 4
	};
	setlocale(LC_ALL, "ru");
	int option;
	int key;
	RBTree* treeUnit = new RBTree;
	cout << "���� ������-������ ������:\n";
	treeUnit->PrintRBTree(treeUnit->GetRoot(), 0);
	while (true)
	{
		cout << "�������� ��������:\n1) �������� �������\n2) ������� �������\n3) ����� �������\n4) �����\n";
		cin >> option;
		switch (option)
		{
		case Add:
		{
			cout << "������� ���� ������������ ��������: ";
			int key;
			cin >> key;
			try
			{
				treeUnit->Insert(key);
			}
			catch (char const* error)
			{
				cerr << error << '\n';
			}
			cout << "���� ������-������ ������:\n";
			treeUnit->PrintRBTree(treeUnit->GetRoot(), 0);
			break;
		}

		case Delete:
		{
			cout << "������� ���� ���������� ��������: ";
			int key;
			cin >> key;
			try
			{
				treeUnit->Delete(key);
				cout << "������� ��� ������!\n";
			}
			catch (char const* error)
			{
				cerr << error << '\n';
			}
			cout << "���� ������-������ ������:\n";
			treeUnit->PrintRBTree(treeUnit->GetRoot(), 0);
			break;
		}

		case Find:
		{
			cout << "������� ���� �������� ��������: ";
			int key;
			cin >> key;

			RBTreeNode* result = treeUnit->Find(key);
			if (result != nullptr)
			{
				cout << "������� � ������ " << result->Key << " ����� ����: ";
				if (result->IsBlack)
				{
					cout << "������\n";
				}
				else
				{
					cout << "�������\n";
				}
			}
			else
			{
				cout << "������ �������� ��� � ������!\n";
			}
			cout << "���� ������-������ ������:\n";
			treeUnit->PrintRBTree(treeUnit->GetRoot(), 0);
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