#include "IORingBuffer.h"

void RingBufferMenu()
{
	setlocale(LC_ALL, "Russian");
	int option;
	int sizeOfBuffer;
	EnterNumber("������� ������ ������: ", sizeOfBuffer);
	RingBuffer* ringBuffer = InitializationOfRingBuffer(sizeOfBuffer);
	printf("����� ������!\n");
	while (true)
	{
		printf("�������� �������:\n1) ���������, ���� �� � ������ ����� ��� ������\n");
		printf("2) ���������, ���� �� �����\n3) ��������\n4) �����\n5) �����\n");
		cin >> option;
		switch (option)
		{
			case 1:
			{
				bool answer = IfThereSpaceToWrite(ringBuffer);
				if (answer == true)
				{
					printf("� ������ ���� ����� ��� ������!\n");
				}
				else
				{
					printf("� ������ ��� ����� ��� ������!\n");
				}
				break;
			}

			case 2:
			{
				bool answer = IsEmpty(ringBuffer);
				if (answer == true)
				{
					printf("\n����� ����!\n");
				}
				else
				{
					printf("\n����� �� ����!\n");
					ShowRingBuffer(ringBuffer);
				}
				break;
			}

			case 3:
			{
				if (IfThereSpaceToWrite(ringBuffer))
				{
					int newElement;
					EnterNumber("������� �������� ������ ��������: ", newElement);
					PushInRingBuffer(ringBuffer, newElement);
					ShowRingBuffer(ringBuffer);
					break;
				}
				else
				{
					printf("� ������ ��� ����� ��� ������!\n");
					ShowRingBuffer(ringBuffer);
					break;
				}

			}

			case 4:
			{
				int elementFromBuffer = PopFromRingBuffer(ringBuffer);
				printf("�������� �� ������: %i\n", elementFromBuffer);
				ShowRingBuffer(ringBuffer);
				break;
			}

			case 5:
			{
				return;
				break;
			}

			default:
			{
				printf("���������� �����!\n");
				break;
			}

		}
	}
}