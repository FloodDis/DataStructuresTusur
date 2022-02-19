#include "IORingBuffer.h"

void RingBufferMenu()
{
	setlocale(LC_ALL, "Russian");
	int sizeOfBuffer = EnterNumber("Введите размер буфера: ");
	RingBuffer* ringBuffer = InitializationOfRingBuffer(sizeOfBuffer);
	cout << "Буфер создан!\n";
	while (true)
	{
		cout << "Выберите вариант:\n1) Проверить буфер на заполненность\n";
		cout << "2) Проверить, пуст ли буфер\n3) Вставить\n4) Взять\n";
		cout << "5) Выход\n";
		int option = EnterNumber("");
		switch (option)
		{
			case 1:
			{
				if (IsFull(ringBuffer))
				{
					cout << "Буфер полон.\n";
					ShowRingBuffer(ringBuffer);
				}
				else
				{
					cout << "Буфер не полон.\n";
					ShowRingBuffer(ringBuffer);
				}
				break;
			}

			case 2:
			{
				if (IsEmpty(ringBuffer))
				{
					cout << "\nБуфер пуст.\n";
					ShowRingBuffer(ringBuffer);
				}
				else
				{
					cout << "\nБуфер не пуст.\n";
					ShowRingBuffer(ringBuffer);
				}
				break;
			}

			case 3:
			{
				if (!IsFull(ringBuffer))
				{
					int newElement = EnterNumber(
						"Введите значение нового элемента: ");
					PushInRingBuffer(ringBuffer, newElement);
					ShowRingBuffer(ringBuffer);
					break;
				}
				else
				{
					cout << "В буфере нет места для записи!\n";
					ShowRingBuffer(ringBuffer);
					break;
				}

			}

			case 4:
			{
				if (IsEmpty(ringBuffer))
				{
					cout << "Буфер пуст.\n";
					ShowRingBuffer(ringBuffer);
					break;
				}
				else
				{
					int elementFromBuffer = PopFromRingBuffer(ringBuffer);
					cout << "Значение из буфера:  " << elementFromBuffer << "\n";
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
				cout << "Попробуйте снова!\n";
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
	cout << "Ваш буфер:\n";
	PrintBuffer(ringBuffer);
}