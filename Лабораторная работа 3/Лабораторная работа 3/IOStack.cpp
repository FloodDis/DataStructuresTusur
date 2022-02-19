#include "IOStack.h"

void StackMenu()
{
	setlocale(LC_ALL, "Russian");
	//TODO: ������ � while +
	int value = EnterNumber("������� �������� ������� ��������: ");
	Node* stack = CreationOfStack();
	stack->DataOfNode = value;
	cout << "���� ������!\n";
	ShowStack(stack);
	while (true)
	{
		cout << "�������� �������:\n1) ��������\n";
		cout << "2) �����\n3) ������� ����\n4) �����\n";
		int option = EnterNumber("");
		switch (option)
		{
			case 1:
			{
				int dataOfNewElement = EnterNumber(
					"������� �������� ������ ��������: \n");
				stack = PushInStack(stack, dataOfNewElement);
				ShowStack(stack);
				break;
			}

			case 2:
			{
				if (stack == nullptr)
				{
					cout << "\n���� ����\n";
					ShowStack(stack);
				}
				else
				{
					int valueFromStack = PopFromStack(stack);
					cout << "\n�������� �� �����:" << valueFromStack <<
						"\n";
					ShowStack(stack);
				}
				break;
			}

			case 3:
			{
				DeleteStack(stack);
				cout << "\n���� �����\n";
				Node* stack = CreationOfStack();
				cout << "\n���� ������!\n";
				ShowStack(stack);
				break;
			}

			case 4:
			{
				return;
			}

			default:
			{
				cout << "���������� �����!\n";
				break;
			}
		}
	}
}

void PrintStack(Node* headNode)
{
	if (headNode == nullptr)
	{
		cout << "\n{ }\n";
		return;
	}

	cout << "\n{" << headNode->DataOfNode << "}";
	headNode = headNode->PreviousNode;

	while (headNode != nullptr)
	{
		cout << " " << headNode->DataOfNode;
		headNode = headNode->PreviousNode;
	}

	cout << "\n";
}

void ShowStack(Node* headNode)
{
	cout << "��� ����:\n";
	PrintStack(headNode);
}