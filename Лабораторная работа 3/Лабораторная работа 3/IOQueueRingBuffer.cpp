#include "IOQueueRingBuffer.h"

void QueueRingBufferBasedMenu()
{
	setlocale(LC_ALL, "Russian");
	int sizeOfQueue;
	bool tryAgain = true;
	while (tryAgain)
	{
		try
		{
			sizeOfQueue = EnterNumber("������� ������ �������: ");
			tryAgain = false;
		}
		catch (const char* error)
		{
			cout << "Size must be a number!\n";
		}
	}
	QueueRingBufferBased* queueRingBuffer = new QueueRingBufferBased;
	queueRingBuffer->ringBuffer = CreationOfQueue(sizeOfQueue);
	cout << "������� �������!\n";
	ShowQueueRingBuffer(queueRingBuffer->ringBuffer);
	while (true)
	{
		cout << "�������� �������:\n1) �������� ������� � �������\n2) ���������� �������� �� �������\n";
		cout << "3) ������� �������\n4) �����\n";
		int option;
		bool tryAgain = true;
		while (tryAgain)
		{
			try
			{
				option = EnterNumber("");
				tryAgain = false;
			}
			catch (const char* error)
			{
				cout << "Option must be a number!\n";
			}
		}
		
		while (option < 1 || option>4)
		{
			cout << "Option must be 1-4!\n";
			cin >> option;
		}

		switch (option)
		{
			case 1:
			{
				int newElement;
				bool tryAgain = true;
				while (tryAgain)
				{
					try
					{
						newElement = EnterNumber(
							"������� ����� ������� �������\n");
					}
					catch (const char* error)
					{
						cout << "Element must be a number!\n";
					}
				}
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
