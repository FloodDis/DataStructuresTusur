#include "IOQueueStack.h"

void QueueStackBasedMenu()
{
	setlocale(LC_ALL, "Russian");

	QueueStackBased* queueStackUnit = new QueueStackBased;
	CreateQueue(queueStackUnit);
	PrintQueueStackBased(queueStackUnit);
	while (true)
	{
		cout << "�������� ��������:\n1) �������� ������� � �������\n";	
		//TODO: �����
		cout << "2) ���������� �������� �� �������\n3) ������� �������\n";
		cout << "4) �����\n";
		int option = EnterNumber("");
		switch (option)
		{	
		//TODO: ������ enum ��� ������
			case 1:
			{
				int dataOfNewElement = EnterNumber(
					"������� �������� ������ ��������: ");
				Enqueue(queueStackUnit, dataOfNewElement);
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
					Dequeue(queueStackUnit) << "\n";
				if (queueStackUnit->IsStackInEmpty)
				{
					queueStackUnit->StackIn = CreateStack();
					queueStackUnit->StackIn->PreviousNode = nullptr;
				}
				PrintQueueStackBased(queueStackUnit);
				break;
			}

			case 3:
			{
				DeleteQueue(queueStackUnit);
				cout << "\n���� ������� �������!\n";
				QueueStackBased* queueStackUnit = new QueueStackBased;
				CreateQueue(queueStackUnit);
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
	//TODO: cout
	printf("\nStackIn:");
	if (queueStackUnit->IsStackInEmpty)
	{	
		//TODO: cout
		printf("\n{ }\n");
	}
	else
	{
		PrintStack(queueStackUnit->StackIn);
	}
		
	//TODO: cout
	printf("\nStackOut:");
	if (queueStackUnit->IsStackOutEmpty)
	{	
		//TODO: cout
		printf("\n{ }\n");
	}
	else
	{
		PrintStack(queueStackUnit->StackOut);
	}

}