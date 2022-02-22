#include "IOQueueRingBuffer.h"
#include "IORingBuffer.h"

void QueueRingBufferMenu()
{
	/// <summary>
	/// Действия над очередью на базе кольцевого буфера
	/// </summary>
	enum Actions
	{
		/// <summary>
		/// Добавить элемент
		/// </summary>
		Push = 1,

		/// <summary>
		/// Извлечь элемент
		/// </summary>
		Pop,

		/// <summary>
		/// Удалить очередь
		/// </summary>
		RemoveQueue,

		/// <summary>
		/// Выйти в главное меню
		/// </summary>
		Exit
	};
	setlocale(LC_ALL, "Russian");
	int sizeOfQueue = EnterNumber("Введите размер очереди: ");
	QueueRingBuffer* queueRingBuffer = new QueueRingBuffer;
	queueRingBuffer->RingBuffer = CreateQueue(sizeOfQueue);
	cout << "Очередь создана!\n";
	ShowQueue(queueRingBuffer->RingBuffer);
	while (true)
	{
		cout << "Выберете вариант:\n"
			<< "1) Добавить элемент в очередь\n"
			<< "2) Извлечение элемента из очереди\n"
			<< "3) Удалить очередь\n"
			<< "4) Выход\n";
		int option = EnterNumber("");
		switch (option)
		{
			case Push:
			{
				if (IsQueueFull(queueRingBuffer->RingBuffer))
				{
					cout << "Очередь заполнена.\n";
					ShowQueue(queueRingBuffer->RingBuffer);
					break;
				}
				else
				{
					int newElement = EnterNumber(
						"Введите новый элемент очереди\n");
					Enqueue(queueRingBuffer->RingBuffer, newElement);
					ShowQueue(queueRingBuffer->RingBuffer);
					break;
				}
			}

			case Pop:
			{
				if (IsQueueEmpty(queueRingBuffer->RingBuffer))
				{
					cout << "Очередь пуста.\n";
					ShowQueue(queueRingBuffer->RingBuffer);
					break;
				}
				else
				{
					int elementFromQueue =
						Dequeue(queueRingBuffer->RingBuffer);
					cout << "Извлеченный элемент:" <<
						elementFromQueue << "\n";
					ShowQueue(queueRingBuffer->RingBuffer);
					break;
				}
			}

			case RemoveQueue:
			{
				DeleteQueue(queueRingBuffer->RingBuffer);
				cout << "Ваша очередь удалена!\n";
				int sizeOfQueue = EnterNumber("Введите размер очереди: ");
				queueRingBuffer->RingBuffer = CreateQueue(sizeOfQueue);
				cout << "Очередь создана!\n";
				ShowQueue(queueRingBuffer->RingBuffer);
				break;
			}

			case Exit:
			{
				return;
			}

			default:
			{
				cout << "Попробуйте ещё раз!\n";
				ShowQueue(queueRingBuffer->RingBuffer);
				break;
			}
		}
	}
}

void PrintQueue(RingBuffer* queueRingBufferUnit)
{
	PrintBuffer(queueRingBufferUnit);
}

void ShowQueue(RingBuffer* queueRingBufferUnit)
{
	cout << "Ваш буфер:\n";
	PrintQueue(queueRingBufferUnit);
}