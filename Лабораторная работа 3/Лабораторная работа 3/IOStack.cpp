#include "IOStack.h"

void StackMenu()
{
	/// <summary>
	/// �������� ��� ������
	/// </summary>
	enum Actions
	{
		/// <summary>
		/// �������� �������
		/// </summary>
		Insert = 1,

		/// <summary>
		/// ������� �������
		/// </summary>
		Extract,

		/// <summary>
		/// ������� ����
		/// </summary>
		RemoveStack,

		/// <summary>
		/// ����� � ������� ����
		/// </summary>
		Exit
	};
	setlocale(LC_ALL, "Russian");
	int value = EnterNumber("������� �������� ������� ��������: ");
	Node* stack = CreateStack();
	stack->DataOfNode = value;
	cout << "���� ������!\n";
	ShowStack(stack);
	while (true)
	{
		cout << "�������� �������:\n"
			<< "1) ��������\n"
			<< "2) �����\n"
			<< "3) ������� ����\n"
			<< "4) �����\n";
		//TODO: ������ � while +
		int option = EnterNumber("");
		switch (option)
		{
			case Insert:
			{
				int dataOfNewElement = EnterNumber(
					"������� �������� ������ ��������: \n");
				stack = Push(stack, dataOfNewElement);
				ShowStack(stack);
				break;
			}

			case Extract:
			{
				if (stack == nullptr)
				{
					cout << "\n���� ����\n";
					ShowStack(stack);
				}
				else
				{
					int valueFromStack = Pop(stack);
					cout << "\n�������� �� �����:" << valueFromStack <<
						"\n";
					ShowStack(stack);
				}
				break;
			}

			case RemoveStack:
			{
				Delete(stack);
				cout << "\n���� �����\n";
				Node* stack = CreateStack();
				cout << "\n���� ������!\n";
				ShowStack(stack);
				break;
			}

			case Exit:
			{
				return;
			}

			default:
			{
				cout << "���������� �����!\n";
				ShowStack(stack);
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