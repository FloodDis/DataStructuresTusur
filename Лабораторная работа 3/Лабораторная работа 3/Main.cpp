#include "Queue_Ring_Buffer_based.h"
#include "Queue_Stack_based.h"
#include "RingBuffer.h"
#include "Stack.h"

void StackMenu();
void RingBufferMenu();
void QueueStackBasedMenu();
void QueueRingBufferBasedMenu();

void MainMenu()
{
	setlocale(LC_ALL, "Russian");
	int option;
	while (true)
	{
		printf("�������� ��������� ������:\n1) ����\n2) ��������� �����\n");
		printf("3) ������� (�� ���� ���� ������)\n");
		printf("4) ������� (�� ���� ���������� ������)\n");
		printf("5) �����\n");
		cin >> option;
		switch (option)
		{
		case 1:
		{
			StackMenu();
			break;
		}
		case 2:
		{
			RingBufferMenu();
			break;
		}
		case 3:
		{
			QueueStackBasedMenu();
			break;
		}
		case 4:
		{
			QueueRingBufferBasedMenu();
			break;
		}
		case 5:
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

void StackMenu()
{
	setlocale(LC_ALL, "Russian");
	int option;
	int value;
	printf("������� �������� ������� ��������: ");
	cin >> value;
	Node* stack = CreationOfStack();
	stack->DataOfNode = value;
	printf("���� ������!\n");
	printf("��� ����:\n");
	PrintStack(stack);
	while (true)
	{
		printf("�������� �������:\n1) ��������\n2) �����\n3) ������� ����\n4) �����\n");
		cin >> option;
		switch (option)
		{
		case 1:
		{
			int dataOfNewElement;
			printf("������� �������� ������ ��������: \n");
			cin >> dataOfNewElement;
			stack = PushInStack(stack, dataOfNewElement);
			printf("��� ����:\n");
			PrintStack(stack);
			break;
		}
		case 2:
		{
			if (stack == nullptr)
			{
				printf("\n���� ����\n");
				printf("\n��� ����:\n");
				PrintStack(stack);
			}
			else
			{
				int valueFromStack;
				valueFromStack = PopFromStack(stack);
				printf("\n�������� �� �����: %i\n", valueFromStack);
				printf("��� ����:\n");
				PrintStack(stack);
			}

			break;
		}
		case 3:
		{
			DeleteStack(stack);
			printf("\n���� �����\n");
			int value;
			printf("������� �������� ������� ��������: ");
			cin >> value;
			Node* stack = CreationOfStack();
			stack->DataOfNode = value;
			printf("\n���� ������!\n");
			printf("\n��� ����\n");
			PrintStack(stack);
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

void RingBufferMenu()
{
	setlocale(LC_ALL, "Russian");
	int option;
	unsigned int sizeOfBuffer;
	printf("������� ������ ������: ");
	cin >> sizeOfBuffer;
	if ((int)log2(sizeOfBuffer) % 2 != 0)
	{
		printf("������ ������ ������ ���� �������� ������!\n");
		return;
	}
	else
	{
		RingBuffer* ringBuffer = InitializationOfRingBuffer(sizeOfBuffer);
		printf("����� ������!\n");
		while (true)
		{
			printf("�������� �������:\n1) ���������, ���� �� � ������ ����� ��� ������\n");
			printf("2) ���������, ���� �� �����\n3) ��������\n4) �����\n5) �����\n");
			cin >> option;
			switch (option)
			{
			case 1:
			{
				bool answer = IfThereSpaceToWrite(ringBuffer);
				if (answer == true)
				{
					printf("� ������ ���� ����� ��� ������!\n");
				}
				else
				{
					printf("� ������ ��� ����� ��� ������!\n");
				}
				break;
			}
			case 2:
			{
				bool answer = IsEmpty(ringBuffer);
				if (answer == true)
				{
					printf("\n����� ����!\n");
				}
				else
				{
					printf("\n����� �� ����!\n");
					printf("��� �����:\n");
					PrintBuffer(ringBuffer);
				}
				break;
			}
			case 3:
			{
				if (IfThereSpaceToWrite(ringBuffer))
				{
					int newElement;
					printf("������� �������� ������ ��������: ");
					cin >> newElement;
					PushInRingBuffer(ringBuffer, newElement);
					printf("��� �����:\n");
					PrintBuffer(ringBuffer);
					break;
				}
				else
				{
					printf("� ������ ��� ����� ��� ������!\n");
					printf("��� �����:\n");
					PrintBuffer(ringBuffer);
					break;
				}

			}
			case 4:
			{
				int elementFromBuffer = PopFromRingBuffer(ringBuffer);
				printf("�������� �� ������: %i\n", elementFromBuffer);
				printf("��� �����:\n");
				PrintBuffer(ringBuffer);
				break;
			}
			case 5:
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
}

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

void QueueRingBufferBasedMenu()
{
	setlocale(LC_ALL, "Russian");
	int option;
	int sizeOfQueue;
	printf("������� ������ �������: ");
	cin >> sizeOfQueue;
	if ((int)log2(sizeOfQueue) % 2 != 0)
	{
		printf("������ ������ ������ �������� 2!\n");
		return;
	}
	else
	{
		RingBuffer* queueRingBuffer = CreationOfQueue(sizeOfQueue);
		printf("������� �������!\n");
		printf("���� �������:\n");
		PrintQueueRingBuffer(queueRingBuffer);
		while (true)
		{
			printf("�������� �������:\n1) �������� ������� � �������\n2) ���������� �������� �� �������\n");
			printf("3) ������� �������\n4) �����\n");
			cin >> option;
			switch (option)
			{
			case 1:
			{
				int newElement;
				printf("������� ����� ������� �������\n");
				cin >> newElement;
				EnqueueRingBuffer(queueRingBuffer, newElement);
				printf("���� �������:\n");
				PrintQueueRingBuffer(queueRingBuffer);
				break;
			}
			case 2:
			{
				int elementFromQueue;
				elementFromQueue = DequeueRingBuffer(queueRingBuffer);
				printf("����������� �������: %i\n", elementFromQueue);
				printf("���� �������:\n");
				PrintQueueRingBuffer(queueRingBuffer);
				break;
			}
			case 3:
			{
				DeleteQueueRingBuffer(queueRingBuffer);
				printf("���� ������� �������!\n");
				int sizeOfQueue;
				printf("������� ������ �������: ");
				cin >> sizeOfQueue;
				if ((int)log2(sizeOfQueue) % 2 != 0)
				{
					printf("������ ������ ������ ���� �������� 2\n");
					return;
					break;
				}
				else
				{
					RingBuffer* queueRingBuffer = CreationOfQueue(sizeOfQueue);
					printf("������� �������!\n");
					break;
				}
			case 4:
			{
				return;
				break;
			}
			default:
			{
				printf("���������� ��� ���!\n");
				break;
			}
			}
			}
		}
	}
}

void main()
{
	MainMenu();
}