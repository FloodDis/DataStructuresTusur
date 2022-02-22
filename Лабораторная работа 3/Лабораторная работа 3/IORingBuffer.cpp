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
		IsRingBufferFull = 1,

		/// <summary>
		/// Пуст ли буфер
		/// </summary>
		IsRingBufferEmpty,

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
	RingBuffer* RingBuffer = InitializeRingBuffer(sizeOfBuffer);
	cout << "Буфер создан!\n";
	ShowBuffer(RingBuffer);
	while (true)
	{
		cout << "Выберите вариант:\n"
			<< "1) Проверить буфер на заполненность\n"
			<< "2) Проверить, пуст ли буфер\n"
			<< "3) Вставить\n"
			<< "4) Взять\n"
			<< "5) Выход\n";
		int option = EnterNumber("");
		switch (option)
		{
			case IsRingBufferFull:
			{
				if (IsBufferFull(RingBuffer))
				{
					cout << "Буфер полон.\n";
					ShowBuffer(RingBuffer);
				}
				else
				{
					cout << "Буфер не полон.\n";
					ShowBuffer(RingBuffer);
				}
				break;
			}

			case IsRingBufferEmpty:
			{
				if (IsBufferEmpty(RingBuffer))
				{
					cout << "\nБуфер пуст.\n";
					ShowBuffer(RingBuffer);
				}
				else
				{
					cout << "\nБуфер не пуст.\n";
					ShowBuffer(RingBuffer);
				}
				break;
			}

			case Insert:
			{
				if (!IsBufferFull(RingBuffer))
				{
					int newElement = EnterNumber(
						"Введите значение нового элемента: ");
					Push(RingBuffer, newElement);
					ShowBuffer(RingBuffer);
					break;
				}
				else
				{
					cout << "В буфере нет места для записи!\n";
					ShowBuffer(RingBuffer);
					break;
				}

			}

			case Erase:
			{
				if (IsBufferEmpty(RingBuffer))
				{
					cout << "Буфер пуст.\n";
					ShowBuffer(RingBuffer);
					break;
				}
				else
				{
					int elementFromBuffer = Pop(RingBuffer);
					cout << "Значение из буфера:  "
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
				cout << "Попробуйте снова!\n";
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
	cout << "Ваш буфер:\n";
	PrintBuffer(RingBuffer);
}