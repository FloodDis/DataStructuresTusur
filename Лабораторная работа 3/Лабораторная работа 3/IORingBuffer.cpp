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
		IsRingBufferFull = 1,

		/// <summary>
		/// ���� �� �����
		/// </summary>
		IsRingBufferEmpty,

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
	RingBuffer* RingBuffer = InitializeRingBuffer(sizeOfBuffer);
	cout << "����� ������!\n";
	ShowBuffer(RingBuffer);
	while (true)
	{
		cout << "�������� �������:\n"
			<< "1) ��������� ����� �� �������������\n"
			<< "2) ���������, ���� �� �����\n"
			<< "3) ��������\n"
			<< "4) �����\n"
			<< "5) �����\n";
		int option = EnterNumber("");
		switch (option)
		{
			case IsRingBufferFull:
			{
				if (IsBufferFull(RingBuffer))
				{
					cout << "����� �����.\n";
					ShowBuffer(RingBuffer);
				}
				else
				{
					cout << "����� �� �����.\n";
					ShowBuffer(RingBuffer);
				}
				break;
			}

			case IsRingBufferEmpty:
			{
				if (IsBufferEmpty(RingBuffer))
				{
					cout << "\n����� ����.\n";
					ShowBuffer(RingBuffer);
				}
				else
				{
					cout << "\n����� �� ����.\n";
					ShowBuffer(RingBuffer);
				}
				break;
			}

			case Insert:
			{
				if (!IsBufferFull(RingBuffer))
				{
					int newElement = EnterNumber(
						"������� �������� ������ ��������: ");
					Push(RingBuffer, newElement);
					ShowBuffer(RingBuffer);
					break;
				}
				else
				{
					cout << "� ������ ��� ����� ��� ������!\n";
					ShowBuffer(RingBuffer);
					break;
				}

			}

			case Erase:
			{
				if (IsBufferEmpty(RingBuffer))
				{
					cout << "����� ����.\n";
					ShowBuffer(RingBuffer);
					break;
				}
				else
				{
					int elementFromBuffer = Pop(RingBuffer);
					cout << "�������� �� ������:  "
						<< elementFromBuffer << "\n";
					ShowBuffer(RingBuffer);
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
				ShowBuffer(RingBuffer);
				break;
			}

		}
	}
}

void PrintBuffer(RingBuffer* RingBuffer)
{
	for (int i = 0; i < RingBuffer->Size; i++)
	{
		cout << "[" << i << "] " << RingBuffer->Data[i] << "\n";
	}
}

void ShowBuffer(RingBuffer* RingBuffer)
{
	cout << "��� �����:\n";
	PrintBuffer(RingBuffer);
}