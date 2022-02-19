#include "IOQueueRingBuffer.h"

void QueueRingBufferBasedMenu()
{
	setlocale(LC_ALL, "Russian");
	int sizeOfQueue = EnterNumber("������� ������ �������: ");
	QueueRingBufferBased* queueRingBuffer = new QueueRingBufferBased;
	queueRingBuffer->ringBuffer = CreationOfQueue(sizeOfQueue);
	cout << "������� �������!\n";
	ShowQueueRingBuffer(queueRingBuffer->ringBuffer);
	while (true)
	{
		cout << "�������� �������:\n1) �������� ������� � �������\n";
		cout << "2) ���������� �������� �� �������\n3) ������� �������\n";
		cout << "4) �����\n";
		int option;
		do
		{
			option = EnterNumber("");
		} while (option < 1 || option>4);
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
				int elementFromQueue =
					DequeueRingBuffer(queueRingBuffer->ringBuffer);
				cout << "����������� �������:" << elementFromQueue << "\n";
				ShowQueueRingBuffer(queueRingBuffer->ringBuffer);
				break;
			}

			case 3:
			{
				DeleteQueueRingBuffer(queueRingBuffer->ringBuffer);
				cout << "���� ������� �������!\n";
				int sizeOfQueue = EnterNumber("������� ������ �������: ");
				queueRingBuffer->ringBuffer = CreationOfQueue(sizeOfQueue);
				cout << "������� �������!\n";
				break;
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
