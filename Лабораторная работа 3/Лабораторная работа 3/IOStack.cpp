#include "IOStack.h"

void StackMenu()
{
	setlocale(LC_ALL, "Russian");
	//TODO: ������ � while
	int value = EnterNumber("������� �������� ������� ��������: ");
	Node* stack = CreationOfStack();
	stack->DataOfNode = value;
	printf("���� ������!\n");
	ShowStack(stack);
	while (true)
	{
		printf("�������� �������:\n1) ��������\n2) �����\n3) ������� ����\n4) �����\n");
		cout << "�������� �������:\n1) ��������\n"
			<< "2) �����\n3) ������� ����\n4) �����\n";
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
					printf("\n���� ����\n");
					ShowStack(stack);
				}
				else
				{
					int valueFromStack = PopFromStack(stack);
					printf("\n�������� �� �����: %i\n", valueFromStack);
					ShowStack(stack);
				}

				break;
			}

			case 3:
			{
				DeleteStack(stack);
				printf("\n���� �����\n");
				int value = EnterNumber("������� �������� ������� ��������: ");
				Node* stack = CreationOfStack();
				stack->DataOfNode = value;
				printf("\n���� ������!\n");
				ShowStack(stack);
				break;
			}

			case 4:
			{
				return;
			}

			default:
			{
				printf("���������� �����!\n");
				break;
			}
		}
	}
}