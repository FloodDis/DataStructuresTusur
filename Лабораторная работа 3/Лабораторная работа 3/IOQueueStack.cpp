#include "IOQueueStack.h"

void QueueStackBasedMenu()
{
	setlocale(LC_ALL, "Russian");

	QueueStackBased* queueStackUnit = new QueueStackBased;
	CreationOfQueueStackBased(queueStackUnit);
	PrintQueueStackBased(queueStackUnit);
	while (true)
	{
		cout << "�������� ��������:\n1) �������� ������� � �������\n";
		cout << "2) ���������� �������� �� �������\n3) ������� �������\n";
		cout << "4) �����\n";
		int option = EnterNumber("");
		switch (option)
		{
			case 1:
			{
				int dataOfNewElement = EnterNumber(
					"������� �������� ������ ��������: ");
				EnqueueStackBased(queueStackUnit, dataOfNewElement);
				PrintQueueStackBased(queueStackUnit);
				break;
			}

			case 2:
			{
				bool isStackInEmpty = queueStackUnit->IsStackInEmpty;
				bool isStackOutEmpty = queueStackUnit->IsStackOutEmpty;
				if (isStackInEmpty && isStackOutEmpty)
				{
					cout << "������� �����.\n";
					PrintQueueStackBased(queueStackUnit);
					break;
				}
					cout << "\n����������� �������:" <<
					DequeueStackBased(queueStackUnit) << "\n";
				if (queueStackUnit->IsStackInEmpty)
				{
					queueStackUnit->StackIn = CreationOfStack();
					queueStackUnit->StackIn->PreviousNode = nullptr;
				}
				PrintQueueStackBased(queueStackUnit);
				break;
			}

			case 3:
			{
				DeleteQueueStackBased(queueStackUnit);
				cout << "\n���� ������� �������!\n";
				QueueStackBased* queueStackUnit = new QueueStackBased;
				CreationOfQueueStackBased(queueStackUnit);
				PrintQueueStackBased(queueStackUnit);
				break;
			}

			case 4:
			{
				return;
			}

			default:
			{
				cout << "���������� �����!\n";
				PrintQueueStackBased(queueStackUnit);
				break;
			}
		}
	}
}

void PrintQueueStackBased(QueueStackBased* queueStackUnit)
{
	setlocale(LC_ALL, "Russian");
	printf("\nStackIn:");
	if (queueStackUnit->IsStackInEmpty)
	{
		printf("\n{ }\n");
	}
	else
	{
		PrintStack(queueStackUnit->StackIn);
	}

	printf("\nStackOut:");
	if (queueStackUnit->IsStackOutEmpty)
	{
		printf("\n{ }\n");
	}
	else
	{
		PrintStack(queueStackUnit->StackOut);
	}

}