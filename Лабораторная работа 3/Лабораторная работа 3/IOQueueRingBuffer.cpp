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
		Push=1,

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
	queueRingBuffer->ringBuffer = CreateQueue(sizeOfQueue);
	cout << "Очередь создана!\n";
	ShowQueue(queueRingBuffer->ringBuffer);
	while (true)
	{
		cout << "Выберете вариант:\n1) Добавить элемент в очередь\n"
			<< "2) Извлечение элемента из очереди\n3) Удалить очередь\n"
			<< "4) Выход\n";
		int option = EnterNumber("");
		switch (option)
		{
			case Push:
			{
				if (IsQueueFull(queueRingBuffer->ringBuffer))
				{
					cout << "Очередь заполнена.\n";
					ShowQueue(queueRingBuffer->ringBuffer);
					break;
				}
				else
				{
					int newElement = EnterNumber(
						"Введите новый элемент очереди\n");
					Enqueue(queueRingBuffer->ringBuffer, newElement);
					ShowQueue(queueRingBuffer->ringBuffer);
					break;
				}
			}

			case Pop:
			{
				if (IsQueueEmpty(queueRingBuffer->ringBuffer))
				{
					cout << "Очередь пуста.\n";
					ShowQueue(queueRingBuffer->ringBuffer);
					break;
				}
				else
				{
					int elementFromQueue =
						Dequeue(queueRingBuffer->ringBuffer);
					cout << "Извлеченный элемент:" << 
						elementFromQueue << "\n";
					ShowQueue(queueRingBuffer->ringBuffer);
					break;
				}
			}

			case RemoveQueue:
			{
				DeleteQueue(queueRingBuffer->ringBuffer);
				cout << "Ваша очередь удалена!\n";
				int sizeOfQueue = EnterNumber("Введите размер очереди: ");
				queueRingBuffer->ringBuffer = CreateQueue(sizeOfQueue);
				cout << "Очередь создана!\n";
				ShowQueue(queueRingBuffer->ringBuffer);
				break;
			}

			case Exit:
			{
				return;
			}

			default:
			{
				cout << "Попробуйте ещё раз!\n";
				ShowQueue(queueRingBuffer->ringBuffer);
				break;
			}
		}
	}
}

//TODO: лишняя сложность 
void PrintQueue(RingBuffer* queueRingBufferUnit)
{
	PrintBuffer(queueRingBufferUnit);
}

void ShowQueue(RingBuffer* queueRingBufferUnit)
{
	cout << "Ваш буфер:\n";
	PrintQueue(queueRingBufferUnit);
}