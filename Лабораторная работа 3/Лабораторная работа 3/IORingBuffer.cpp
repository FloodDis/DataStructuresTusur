#include "IORingBuffer.h"

void RingBufferMenu()
{
	/// <summary>
	/// Действия над кольцевым буфером
	/// </summary>
	enum Actions
	{
		/// <summary>
		/// Полон ли буфер
		/// </summary>
		IsBufferFull = 1,

		/// <summary>
		/// Пуст ли буфер
		/// </summary>
		IsBufferEmpty,

		/// <summary>
		/// Вставить элемент
		/// </summary>
		Insert,

		/// <summary>
		/// Взять элемент
		/// </summary>
		Erase,

		/// <summary>
		/// Выйти главное меню
		/// </summary>
		Exit
	};
	setlocale(LC_ALL, "Russian");
	int sizeOfBuffer = EnterNumber("Введите размер буфера: ");
	RingBuffer* ringBuffer = InitializeRingBuffer(sizeOfBuffer);
	cout << "Буфер создан!\n";
	ShowBuffer(ringBuffer);
	while (true)
	{
		cout << "Выберите вариант:\n1) Проверить буфер на заполненность\n"
			<< "2) Проверить, пуст ли буфер\n3) Вставить\n4) Взять\n"
			<< "5) Выход\n";
		int option = EnterNumber("");
		switch (option)
		{
			case IsBufferFull:
			{
				if (IsFull(ringBuffer))
				{
					cout << "Буфер полон.\n";
					ShowBuffer(ringBuffer);
				}
				else
				{
					cout << "Буфер не полон.\n";
					ShowBuffer(ringBuffer);
				}
				break;
			}

			case IsBufferEmpty:
			{
				if (IsEmpty(ringBuffer))
				{
					cout << "\nБуфер пуст.\n";
					ShowBuffer(ringBuffer);
				}
				else
				{
					cout << "\nБуфер не пуст.\n";
					ShowBuffer(ringBuffer);
				}
				break;
			}

			case Insert:
			{
				if (!IsFull(ringBuffer))
				{
					int newElement = EnterNumber(
						"Введите значение нового элемента: ");
					Push(ringBuffer, newElement);
					ShowBuffer(ringBuffer);
					break;
				}
				else
				{
					cout << "В буфере нет места для записи!\n";
					ShowBuffer(ringBuffer);
					break;
				}

			}

			case Erase:
			{
				if (IsEmpty(ringBuffer))
				{
					cout << "Буфер пуст.\n";
					ShowBuffer(ringBuffer);
					break;
				}
				else
				{
					int elementFromBuffer = Pop(ringBuffer);
					cout << "Значение из буфера:  " 
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
				cout << "Попробуйте снова!\n";
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
	cout << "Ваш буфер:\n";
	PrintBuffer(ringBuffer);
}