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
				bool answer = IfThereSpaceToWrite(ringBuffer);
				if (answer == true)
				{
					cout << "В буфере есть место для записи!\n";
				}
				else
				{
					cout << "В буфере нет места для записи!\n";
				}
				break;
			}

			case 2:
			{
				bool answer = IsEmpty(ringBuffer);
				if (answer == true)
				{
					cout << "\nБуфер пуст!\n";
				}
				else
				{
					cout << "\nБуфер не пуст!\n";
					ShowRingBuffer(ringBuffer);
				}
				break;
			}

			case 3:
			{
				if (IfThereSpaceToWrite(ringBuffer))
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
				int elementFromBuffer = PopFromRingBuffer(ringBuffer);
				cout << "Значение из буфера:  "<< elementFromBuffer<<"\n";
				ShowRingBuffer(ringBuffer);
				break;
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