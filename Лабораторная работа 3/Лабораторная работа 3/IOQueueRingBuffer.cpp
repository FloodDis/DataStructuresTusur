#include "IOQueueRingBuffer.h"
#include "IORingBuffer.h"

void QueueRingBufferMenu()
{
	setlocale(LC_ALL, "Russian");
	int sizeOfQueue = EnterNumber("������� ������ �������: ");
	QueueRingBuffer* queueRingBuffer = new QueueRingBuffer;
	queueRingBuffer->ringBuffer = CreationOfQueue(sizeOfQueue);
	cout << "������� �������!\n";
	ShowQueueRingBuffer(queueRingBuffer->ringBuffer);
	while (true)
	{
		cout << "�������� �������:\n1) �������� ������� � �������\n";
		cout << "2) ���������� �������� �� �������\n3) ������� �������\n";
		cout << "4) �����\n";
		int option;
		option = EnterNumber("");
		switch (option)
		{
			case 1:
			{
				if (IsQueueRingBufferFull(queueRingBuffer->ringBuffer))
				{
					cout << "������� ���������.\n";
					ShowQueueRingBuffer(queueRingBuffer->ringBuffer);
					break;
				}
				else
				{
					int newElement = EnterNumber(
						"������� ����� ������� �������\n");
					EnqueueRingBuffer(queueRingBuffer->ringBuffer, newElement);
					ShowQueueRingBuffer(queueRingBuffer->ringBuffer);
					break;
				}
			}

			case 2:
			{
				if (IsQueueRingBufferEmpty(queueRingBuffer->ringBuffer))
				{
					cout << "������� �����.\n";
					ShowQueueRingBuffer(queueRingBuffer->ringBuffer);
					break;
				}
				else
				{
					int elementFromQueue =
						DequeueRingBuffer(queueRingBuffer->ringBuffer);
					cout << "����������� �������:" << elementFromQueue << "\n";
					ShowQueueRingBuffer(queueRingBuffer->ringBuffer);
					break;
				}
			}

			case 3:
			{
				DeleteQueueRingBuffer(queueRingBuffer->ringBuffer);
				cout << "���� ������� �������!\n";
				int sizeOfQueue = EnterNumber("������� ������ �������: ");
				queueRingBuffer->ringBuffer = CreationOfQueue(sizeOfQueue);
				cout << "������� �������!\n";
				ShowQueueRingBuffer(queueRingBuffer->ringBuffer);
				break;
			}

			case 4:
			{
				return;
			}

			default:
			{
				cout << "���������� ��� ���!\n";
				ShowQueueRingBuffer(queueRingBuffer->ringBuffer);
				break;
			}
		}
	}
}

void PrintQueueRingBuffer(RingBuffer* queueRingBufferUnit)
{
	PrintBuffer(queueRingBufferUnit);
}

void ShowQueueRingBuffer(RingBuffer* queueRingBufferUnit)
{
	cout << "��� �����:\n";
	PrintQueueRingBuffer(queueRingBufferUnit);
}