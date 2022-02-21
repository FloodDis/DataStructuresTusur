#include "IORingBuffer.h"

void RingBufferMenu()
{
	setlocale(LC_ALL, "Russian");
	int sizeOfBuffer = EnterNumber("������� ������ ������: ");
	RingBuffer* ringBuffer = InitializeRingBuffer(sizeOfBuffer);
	cout << "����� ������!\n";
	ShowRingBuffer(ringBuffer);
	while (true)
	{
			
		//TODO: �����.
		//TODO: ������ ������ ������ � ������� �����
		//TODO: ������ � ��������� cout, ���� ��������.
		cout << "�������� �������:\n1) ��������� ����� �� �������������\n";
		cout << "2) ���������, ���� �� �����\n3) ��������\n4) �����\n";
		cout << "5) �����\n";
		int option = EnterNumber("");
		switch (option)
		{	
			//TODO: ������ enum ��� ������
			case 1:
			{
				if (IsFull(ringBuffer))
				{
					cout << "����� �����.\n";
					ShowRingBuffer(ringBuffer);
				}
				else
				{
					cout << "����� �� �����.\n";
					ShowRingBuffer(ringBuffer);
				}
				break;
			}

			case 2:
			{
				if (IsEmpty(ringBuffer))
				{
					cout << "\n����� ����.\n";
					ShowRingBuffer(ringBuffer);
				}
				else
				{
					cout << "\n����� �� ����.\n";
					ShowRingBuffer(ringBuffer);
				}
				break;
			}

			case 3:
			{
				if (!IsFull(ringBuffer))
				{
					int newElement = EnterNumber(
						"������� �������� ������ ��������: ");
					Push(ringBuffer, newElement);
					ShowRingBuffer(ringBuffer);
					break;
				}
				else
				{
					cout << "� ������ ��� ����� ��� ������!\n";
					ShowRingBuffer(ringBuffer);
					break;
				}

			}

			case 4:
			{
				if (IsEmpty(ringBuffer))
				{
					cout << "����� ����.\n";
					ShowRingBuffer(ringBuffer);
					break;
				}
				else
				{	
					//TODO: �����
					int elementFromBuffer = Pop(ringBuffer);	
					//TODO: �����
					cout << "�������� �� ������:  " << elementFromBuffer << "\n";
					ShowRingBuffer(ringBuffer);
					break;
				}
			}

			case 5:
			{
				return;
			}

			default:
			{
				cout << "���������� �����!\n";
				ShowRingBuffer(ringBuffer);
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

void ShowRingBuffer(RingBuffer* ringBuffer)
{
	cout << "��� �����:\n";
	PrintBuffer(ringBuffer);
}