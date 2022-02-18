#include "IOQueueRingBuffer.h"

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
			option = EnterNumber("");
			switch (option)
			{
				case 1:
				{
					int newElement = EnterNumber(
						"������� ����� ������� �������\n");
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
