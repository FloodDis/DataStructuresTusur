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
		//TODO: �������������.
		//TODO: ������ ������ � ������� ����� ������ � ��������� cout
		cout << "�������� �������:\n1) �������� ������� � �������\n";	
		//TODO: �����
		cout << "2) ���������� �������� �� �������\n3) ������� �������\n";
		cout << "4) �����\n";
		int option;
		option = EnterNumber("");
		switch (option)
		{	
		//TODO: enum ��� ������
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
					//TODO: �����
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
					//TODO: �����
					int elementFromQueue =
						DequeueRingBuffer(queueRingBuffer->ringBuffer);
					//TODO: �����
					cout << "����������� �������:" << elementFromQueue << "\n";
					ShowQueueRingBuffer(queueRingBuffer->ringBuffer);
					break;
				}
			}

			case 3:
			{
				DeleteQueueRingBuffer(queueRingBuffer->ringBuffer);
				cout << "���� ������� �������!\n";
				//TODO: �����
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
//TODO: ������ ���������
void PrintQueueRingBuffer(RingBuffer* queueRingBufferUnit)
{
	PrintBuffer(queueRingBufferUnit);
}
//TODO: ��������� ���������� �������.
//TODO: ���������� ������ ������� ����� ShowQueueRingBuffer()
//TODO: � PrintQueueRingBuffer(), �� ���������� � ��������� �������.
void ShowQueueRingBuffer(RingBuffer* queueRingBufferUnit)
{
	cout << "��� �����:\n";
	PrintQueueRingBuffer(queueRingBufferUnit);
}