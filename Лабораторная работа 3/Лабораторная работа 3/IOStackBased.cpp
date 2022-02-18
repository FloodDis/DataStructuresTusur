#include "IOStackBased.h"

void QueueStackBasedMenu()
{
	setlocale(LC_ALL, "Russian");
	int option;
	int dataOfFirstElement;
	QueueStackBased* queueStackUnit = new QueueStackBased;
	CreationOfQueueStackBased(queueStackUnit);
	PrintQueueStackBased(queueStackUnit);
	while (true)
	{
		printf("�������� ��������:\n1) �������� ������� � �������\n2) ���������� �������� �� �������\n");
		printf("3) ������� �������\n4) �����\n");
		cin >> option;
		switch (option)
		{
			case 1:
			{
				int dataOfNewElement;
				printf("������� �������� ������ ��������: ");
				cin >> dataOfNewElement;
				EnqueueStackBased(queueStackUnit, dataOfNewElement);
				PrintQueueStackBased(queueStackUnit);
				break;
			}

			case 2:
			{
				printf("\n����������� �������: %i\n", DequeueStackBased(queueStackUnit));
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
				printf("\n���� ������� �������!\n");
				QueueStackBased* queueStackUnit = new QueueStackBased;
				CreationOfQueueStackBased(queueStackUnit);
				PrintQueueStackBased(queueStackUnit);
				break;
			}

			case 4:
			{
				return;
				break;
			}

			default:
			{
				printf("���������� �����!\n");
				break;
			}
		}
	}
}