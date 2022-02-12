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
	EnterNumber("������� �������� ������� ��������: ", value);
	Node* stack = CreationOfStack();
	stack->DataOfNode = value;
	printf("���� ������!\n");
	ShowStack(stack);
	while (true)
	{
		printf("�������� �������:\n1) ��������\n2) �����\n3) ������� ����\n4) �����\n");
		cin >> option;
		switch (option)
		{
			case 1:
			{
				int dataOfNewElement;
				EnterNumber("������� �������� ������ ��������: \n", dataOfNewElement);
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
					int valueFromStack;
					valueFromStack = PopFromStack(stack);
					printf("\n�������� �� �����: %i\n", valueFromStack);
					ShowStack(stack);
				}

				break;
			}

			case 3:
			{
				DeleteStack(stack);
				printf("\n���� �����\n");
				int value;
				EnterNumber("������� �������� ������� ��������: ", value);
				Node* stack = CreationOfStack();
				stack->DataOfNode = value;
				printf("\n���� ������!\n");
				ShowStack(stack);
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
	int sizeOfBuffer;
	EnterNumber("������� ������ ������: ", sizeOfBuffer);
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
						ShowRingBuffer(ringBuffer);
					}
					break;
				}

				case 3:
				{
					if (IfThereSpaceToWrite(ringBuffer))
					{
						int newElement;
						EnterNumber("������� �������� ������ ��������: ", newElement);
						PushInRingBuffer(ringBuffer, newElement);
						ShowRingBuffer(ringBuffer);
						break;
					}
					else
					{
						printf("� ������ ��� ����� ��� ������!\n");
						ShowRingBuffer(ringBuffer);
						break;
					}

				}

				case 4:
				{
					int elementFromBuffer = PopFromRingBuffer(ringBuffer);
					printf("�������� �� ������: %i\n", elementFromBuffer);
					ShowRingBuffer(ringBuffer);
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
	cout << "������� ������ �������: ";
	cin >> sizeOfQueue;
	if ((int)log2(sizeOfQueue) % 2 != 0)
	{
		cout << "������ ������ ������ �������� 2!\n";
		return;
	}
	else
	{
		QueueRingBufferBased* queueRingBuffer = new QueueRingBufferBased;
		queueRingBuffer->ringBuffer = CreationOfQueue(sizeOfQueue);
		cout << "������� �������!\n";
		ShowQueueRingBuffer(queueRingBuffer->ringBuffer);
		while (true)
		{
			cout << "�������� �������:\n1) �������� ������� � �������\n2) ���������� �������� �� �������\n";
			cout << "3) ������� �������\n4) �����\n";
			cin >> option;
			switch (option)
			{
				case 1:
				{
					int newElement;
					EnterNumber("������� ����� ������� �������\n", newElement);
					EnqueueRingBuffer(queueRingBuffer->ringBuffer, newElement);
					ShowQueueRingBuffer(queueRingBuffer->ringBuffer);
					break;
				}

				case 2:
				{
					int elementFromQueue;
					elementFromQueue = DequeueRingBuffer(queueRingBuffer->ringBuffer);
					cout << "����������� �������: %i\n", elementFromQueue;
					ShowQueueRingBuffer(queueRingBuffer->ringBuffer);
					break;
				}

				case 3:
				{
					DeleteQueueRingBuffer(queueRingBuffer->ringBuffer);
					cout << "���� ������� �������!\n";
					int sizeOfQueue;
					EnterNumber("������� ������ �������: ", sizeOfQueue);
					if ((int)log2(sizeOfQueue) % 2 != 0)
					{
						printf("������ ������ ������ ���� �������� 2\n");
						return;
						break;
					}
					else
					{
						queueRingBuffer->ringBuffer = CreationOfQueue(sizeOfQueue);
						cout << "������� �������!\n";
						break;
					}
				}

				case 4:
				{
					return;
					break;
				}

				default:
				{
					cout << "���������� ��� ���!\n";
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