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
		Push = 1,

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
	queueRingBuffer->RingBuffer = CreateQueue(sizeOfQueue);
	cout << "������� �������!\n";
	ShowQueue(queueRingBuffer->RingBuffer);
	while (true)
	{
		cout << "�������� �������:\n"
			<< "1) �������� ������� � �������\n"
			<< "2) ���������� �������� �� �������\n"
			<< "3) ������� �������\n"
			<< "4) �����\n";
		int option = EnterNumber("");
		switch (option)
		{
			case Push:
			{
				if (IsQueueFull(queueRingBuffer->RingBuffer))
				{
					cout << "������� ���������.\n";
					ShowQueue(queueRingBuffer->RingBuffer);
					break;
				}
				else
				{
					int newElement = EnterNumber(
						"������� ����� ������� �������\n");
					Enqueue(queueRingBuffer->RingBuffer, newElement);
					ShowQueue(queueRingBuffer->RingBuffer);
					break;
				}
			}

			case Pop:
			{
				if (IsQueueEmpty(queueRingBuffer->RingBuffer))
				{
					cout << "������� �����.\n";
					ShowQueue(queueRingBuffer->RingBuffer);
					break;
				}
				else
				{
					int elementFromQueue =
						Dequeue(queueRingBuffer->RingBuffer);
					cout << "����������� �������:" <<
						elementFromQueue << "\n";
					ShowQueue(queueRingBuffer->RingBuffer);
					break;
				}
			}

			case RemoveQueue:
			{
				DeleteQueue(queueRingBuffer->RingBuffer);
				cout << "���� ������� �������!\n";
				int sizeOfQueue = EnterNumber("������� ������ �������: ");
				queueRingBuffer->RingBuffer = CreateQueue(sizeOfQueue);
				cout << "������� �������!\n";
				ShowQueue(queueRingBuffer->RingBuffer);
				break;
			}

			case Exit:
			{
				return;
			}

			default:
			{
				cout << "���������� ��� ���!\n";
				ShowQueue(queueRingBuffer->RingBuffer);
				break;
			}
		}
	}
}

void PrintQueue(RingBuffer* queueRingBufferUnit)
{
	PrintBuffer(queueRingBufferUnit);
}

void ShowQueue(RingBuffer* queueRingBufferUnit)
{
	cout << "��� �����:\n";
	PrintQueue(queueRingBufferUnit);
}