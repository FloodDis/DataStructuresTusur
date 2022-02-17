#include "IORingBuffer.h"

void RingBufferMenu()
{
	setlocale(LC_ALL, "Russian");
	int option;
	int sizeOfBuffer;
	EnterNumber("Введите размер буфера: ", sizeOfBuffer);
	RingBuffer* ringBuffer = InitializationOfRingBuffer(sizeOfBuffer);
	printf("Буфер создан!\n");
	while (true)
	{
		printf("Выберите вариант:\n1) Проверить, есть ли в буфере место для записи\n");
		printf("2) Проверить, пуст ли буфер\n3) Вставить\n4) Взять\n5) Выход\n");
		cin >> option;
		switch (option)
		{
			case 1:
			{
				bool answer = IfThereSpaceToWrite(ringBuffer);
				if (answer == true)
				{
					printf("В буфере есть место для записи!\n");
				}
				else
				{
					printf("В буфере нет места для записи!\n");
				}
				break;
			}

			case 2:
			{
				bool answer = IsEmpty(ringBuffer);
				if (answer == true)
				{
					printf("\nБуфер пуст!\n");
				}
				else
				{
					printf("\nБуфер не пуст!\n");
					ShowRingBuffer(ringBuffer);
				}
				break;
			}

			case 3:
			{
				if (IfThereSpaceToWrite(ringBuffer))
				{
					int newElement;
					EnterNumber("Введите значение нового элемента: ", newElement);
					PushInRingBuffer(ringBuffer, newElement);
					ShowRingBuffer(ringBuffer);
					break;
				}
				else
				{
					printf("В буфере нет места для записи!\n");
					ShowRingBuffer(ringBuffer);
					break;
				}

			}

			case 4:
			{
				int elementFromBuffer = PopFromRingBuffer(ringBuffer);
				printf("Значение из буфера: %i\n", elementFromBuffer);
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
				printf("Попробуйте снова!\n");
				break;
			}

		}
	}
}