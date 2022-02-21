#include "IOQueueRingBuffer.h"
#include "IORingBuffer.h"

void QueueRingBufferMenu()
{
	/// <summary>
	/// �������� ��� �������� �� ���� ���������� ������
	/// </summary>
	enum Actions
	{
		/// <summary>
		/// �������� �������
		/// </summary>
		Push=1,

		/// <summary>
		/// ������� �������
		/// </summary>
		Pop,

		/// <summary>
		/// ������� �������
		/// </summary>
		RemoveQueue,

		/// <summary>
		/// ����� � ������� ����
		/// </summary>
		Exit
	};
	setlocale(LC_ALL, "Russian");
	int sizeOfQueue = EnterNumber("������� ������ �������: ");
	QueueRingBuffer* queueRingBuffer = new QueueRingBuffer;
	queueRingBuffer->ringBuffer = CreateQueue(sizeOfQueue);
	cout << "������� �������!\n";
	ShowQueue(queueRingBuffer->ringBuffer);
	while (true)
	{
		cout << "�������� �������:\n1) �������� ������� � �������\n"
			<< "2) ���������� �������� �� �������\n3) ������� �������\n"
			<< "4) �����\n";
		int option = EnterNumber("");
		switch (option)
		{
			case Push:
			{
				if (IsQueueFull(queueRingBuffer->ringBuffer))
				{
					cout << "������� ���������.\n";
					ShowQueue(queueRingBuffer->ringBuffer);
					break;
				}
				else
				{
					int newElement = EnterNumber(
						"������� ����� ������� �������\n");
					Enqueue(queueRingBuffer->ringBuffer, newElement);
					ShowQueue(queueRingBuffer->ringBuffer);
					break;
				}
			}

			case Pop:
			{
				if (IsQueueEmpty(queueRingBuffer->ringBuffer))
				{
					cout << "������� �����.\n";
					ShowQueue(queueRingBuffer->ringBuffer);
					break;
				}
				else
				{
					int elementFromQueue =
						Dequeue(queueRingBuffer->ringBuffer);
					cout << "����������� �������:" << 
						elementFromQueue << "\n";
					ShowQueue(queueRingBuffer->ringBuffer);
					break;
				}
			}

			case RemoveQueue:
			{
				DeleteQueue(queueRingBuffer->ringBuffer);
				cout << "���� ������� �������!\n";
				int sizeOfQueue = EnterNumber("������� ������ �������: ");
				queueRingBuffer->ringBuffer = CreateQueue(sizeOfQueue);
				cout << "������� �������!\n";
				ShowQueue(queueRingBuffer->ringBuffer);
				break;
			}

			case Exit:
			{
				return;
			}

			default:
			{
				cout << "���������� ��� ���!\n";
				ShowQueue(queueRingBuffer->ringBuffer);
				break;
			}
		}
	}
}

//TODO: ������ ��������� 
void PrintQueue(RingBuffer* queueRingBufferUnit)
{
	PrintBuffer(queueRingBufferUnit);
}

void ShowQueue(RingBuffer* queueRingBufferUnit)
{
	cout << "��� �����:\n";
	PrintQueue(queueRingBufferUnit);
}