#include "IORingBuffer.h"

void RingBufferMenu()
{
	setlocale(LC_ALL, "Russian");
	int sizeOfBuffer = EnterNumber("������� ������ ������: ");
	RingBuffer* ringBuffer = InitializationOfRingBuffer(sizeOfBuffer);
	cout << "����� ������!\n";
	while (true)
	{
		cout << "�������� �������:\n1) ��������� ����� �� �������������\n";
		cout << "2) ���������, ���� �� �����\n3) ��������\n4) �����\n";
		cout << "5) �����\n";
		int option = EnterNumber("");
		switch (option)
		{
			case 1:
			{
				bool answer = IfThereSpaceToWrite(ringBuffer);
				if (answer == true)
				{
					cout << "� ������ ���� ����� ��� ������!\n";
				}
				else
				{
					cout << "� ������ ��� ����� ��� ������!\n";
				}
				break;
			}

			case 2:
			{
				bool answer = IsEmpty(ringBuffer);
				if (answer == true)
				{
					cout << "\n����� ����!\n";
				}
				else
				{
					cout << "\n����� �� ����!\n";
					ShowRingBuffer(ringBuffer);
				}
				break;
			}

			case 3:
			{
				if (IfThereSpaceToWrite(ringBuffer))
				{
					int newElement = EnterNumber(
						"������� �������� ������ ��������: ");
					PushInRingBuffer(ringBuffer, newElement);
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
				int elementFromBuffer = PopFromRingBuffer(ringBuffer);
				cout << "�������� �� ������:  "<< elementFromBuffer<<"\n";
				ShowRingBuffer(ringBuffer);
				break;
			}

			case 5:
			{
				return;
			}

			default:
			{
				cout << "���������� �����!\n";
				break;
			}

		}
	}
}