#include "IOQueueRingBuffer.h"

void QueueRingBufferBasedMenu()
{
	setlocale(LC_ALL, "Russian");
	int sizeOfQueue = EnterNumber("Введите размер очереди: ");
	QueueRingBufferBased* queueRingBuffer = new QueueRingBufferBased;
	queueRingBuffer->ringBuffer = CreationOfQueue(sizeOfQueue);
	cout << "Очередь создана!\n";
	ShowQueueRingBuffer(queueRingBuffer->ringBuffer);
	while (true)
	{
		cout << "Выберете вариант:\n1) Добавить элемент в очередь\n";
		cout << "2) Извлечение элемента из очереди\n3) Удалить очередь\n";
		cout << "4) Выход\n";
		int option;
		do
		{
			option = EnterNumber("");
		} while (option < 1 || option>4);
		switch (option)
		{
			case 1:
			{
				int newElement = EnterNumber(
					"Введите новый элемент очереди\n");
				EnqueueRingBuffer(queueRingBuffer->ringBuffer, newElement);
				ShowQueueRingBuffer(queueRingBuffer->ringBuffer);
				break;
			}

			case 2:
			{
				int elementFromQueue =
					DequeueRingBuffer(queueRingBuffer->ringBuffer);
				cout << "Извлеченный элемент:" << elementFromQueue << "\n";
				ShowQueueRingBuffer(queueRingBuffer->ringBuffer);
				break;
			}

			case 3:
			{
				DeleteQueueRingBuffer(queueRingBuffer->ringBuffer);
				cout << "Ваша очередь удалена!\n";
				int sizeOfQueue = EnterNumber("Введите размер очереди: ");
				queueRingBuffer->ringBuffer = CreationOfQueue(sizeOfQueue);
				cout << "Очередь создана!\n";
				break;
			}

			case 4:
			{
				return;
			}

			default:
			{
				cout << "Попробуйте ещё раз!\n";
				break;
			}
		}
	}
}
