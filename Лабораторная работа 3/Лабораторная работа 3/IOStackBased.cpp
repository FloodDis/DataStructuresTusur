#include "IOStackBased.h"

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
				break;
			}
		}
	}
}