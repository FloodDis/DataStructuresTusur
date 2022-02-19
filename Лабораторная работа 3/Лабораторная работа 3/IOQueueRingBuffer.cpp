#include "IOQueueRingBuffer.h"
#include "IORingBuffer.h"

void QueueRingBufferMenu()
{
	setlocale(LC_ALL, "Russian");
	int sizeOfQueue = EnterNumber("Введите размер очереди: ");
	QueueRingBuffer* queueRingBuffer = new QueueRingBuffer;
	queueRingBuffer->ringBuffer = CreationOfQueue(sizeOfQueue);
	cout << "Очередь создана!\n";
	ShowQueueRingBuffer(queueRingBuffer->ringBuffer);
	while (true)
	{
		cout << "Выберете вариант:\n1) Добавить элемент в очередь\n";
		cout << "2) Извлечение элемента из очереди\n3) Удалить очередь\n";
		cout << "4) Выход\n";
		int option;
		option = EnterNumber("");
		switch (option)
		{
			case 1:
			{
				if (IsQueueRingBufferFull(queueRingBuffer->ringBuffer))
				{
					cout << "Очередь заполнена.\n";
					ShowQueueRingBuffer(queueRingBuffer->ringBuffer);
					break;
				}
				else
				{
					int newElement = EnterNumber(
						"Введите новый элемент очереди\n");
					EnqueueRingBuffer(queueRingBuffer->ringBuffer, newElement);
					ShowQueueRingBuffer(queueRingBuffer->ringBuffer);
					break;
				}
			}

			case 2:
			{
				if (IsQueueRingBufferEmpty(queueRingBuffer->ringBuffer))
				{
					cout << "Очередь пуста.\n";
					ShowQueueRingBuffer(queueRingBuffer->ringBuffer);
					break;
				}
				else
				{
					int elementFromQueue =
						DequeueRingBuffer(queueRingBuffer->ringBuffer);
					cout << "Извлеченный элемент:" << elementFromQueue << "\n";
					ShowQueueRingBuffer(queueRingBuffer->ringBuffer);
					break;
				}
			}

			case 3:
			{
				DeleteQueueRingBuffer(queueRingBuffer->ringBuffer);
				cout << "Ваша очередь удалена!\n";
				int sizeOfQueue = EnterNumber("Введите размер очереди: ");
				queueRingBuffer->ringBuffer = CreationOfQueue(sizeOfQueue);
				cout << "Очередь создана!\n";
				ShowQueueRingBuffer(queueRingBuffer->ringBuffer);
				break;
			}

			case 4:
			{
				return;
			}

			default:
			{
				cout << "Попробуйте ещё раз!\n";
				ShowQueueRingBuffer(queueRingBuffer->ringBuffer);
				break;
			}
		}
	}
}

void PrintQueueRingBuffer(RingBuffer* queueRingBufferUnit)
{
	PrintBuffer(queueRingBufferUnit);
}

void ShowQueueRingBuffer(RingBuffer* queueRingBufferUnit)
{
	cout << "Ваш буфер:\n";
	PrintQueueRingBuffer(queueRingBufferUnit);
}