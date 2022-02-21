#include "IORingBuffer.h"

void RingBufferMenu()
{
	/// <summary>
	/// �������� ��� ��������� �������
	/// </summary>
	enum Actions
	{
		/// <summary>
		/// ����� �� �����
		/// </summary>
		IsBufferFull = 1,

		/// <summary>
		/// ���� �� �����
		/// </summary>
		IsBufferEmpty,

		/// <summary>
		/// �������� �������
		/// </summary>
		Insert,

		/// <summary>
		/// ����� �������
		/// </summary>
		Erase,

		/// <summary>
		/// ����� ������� ����
		/// </summary>
		Exit
	};
	setlocale(LC_ALL, "Russian");
	int sizeOfBuffer = EnterNumber("������� ������ ������: ");
	RingBuffer* ringBuffer = InitializeRingBuffer(sizeOfBuffer);
	cout << "����� ������!\n";
	ShowBuffer(ringBuffer);
	while (true)
	{
		cout << "�������� �������:\n1) ��������� ����� �� �������������\n"
			<< "2) ���������, ���� �� �����\n3) ��������\n4) �����\n"
			<< "5) �����\n";
		int option = EnterNumber("");
		switch (option)
		{
			case IsBufferFull:
			{
				if (IsFull(ringBuffer))
				{
					cout << "����� �����.\n";
					ShowBuffer(ringBuffer);
				}
				else
				{
					cout << "����� �� �����.\n";
					ShowBuffer(ringBuffer);
				}
				break;
			}

			case IsBufferEmpty:
			{
				if (IsEmpty(ringBuffer))
				{
					cout << "\n����� ����.\n";
					ShowBuffer(ringBuffer);
				}
				else
				{
					cout << "\n����� �� ����.\n";
					ShowBuffer(ringBuffer);
				}
				break;
			}

			case Insert:
			{
				if (!IsFull(ringBuffer))
				{
					int newElement = EnterNumber(
						"������� �������� ������ ��������: ");
					Push(ringBuffer, newElement);
					ShowBuffer(ringBuffer);
					break;
				}
				else
				{
					cout << "� ������ ��� ����� ��� ������!\n";
					ShowBuffer(ringBuffer);
					break;
				}

			}

			case Erase:
			{
				if (IsEmpty(ringBuffer))
				{
					cout << "����� ����.\n";
					ShowBuffer(ringBuffer);
					break;
				}
				else
				{
					int elementFromBuffer = Pop(ringBuffer);
					cout << "�������� �� ������:  " 
						<< elementFromBuffer << "\n";
					ShowBuffer(ringBuffer);
					break;
				}
			}

			case Exit:
			{
				return;
			}

			default:
			{
				cout << "���������� �����!\n";
				ShowBuffer(ringBuffer);
				break;
			}

		}
	}
}

void PrintBuffer(RingBuffer* ringBuffer)
{
	for (int i = 0; i < ringBuffer->Size; i++)
	{
		cout << "[" << i << "] " << ringBuffer->Data[i] << "\n";
	}
}

void ShowBuffer(RingBuffer* ringBuffer)
{
	cout << "��� �����:\n";
	PrintBuffer(ringBuffer);
}