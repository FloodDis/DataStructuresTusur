#include "IOQueueRingBuffer.h"

void QueueRingBufferBasedMenu()
{
	setlocale(LC_ALL, "Russian");
	int sizeOfQueue;
	bool tryAgain = true;
	while (tryAgain)
	{
		try
		{
			sizeOfQueue = EnterNumber("Введите размер очереди: ");
			tryAgain = false;
		}
		catch (const char* error)
		{
			cout << "Size must be a number!\n";
		}
	}
	QueueRingBufferBased* queueRingBuffer = new QueueRingBufferBased;
	queueRingBuffer->ringBuffer = CreationOfQueue(sizeOfQueue);
	cout << "Очередь создана!\n";
	ShowQueueRingBuffer(queueRingBuffer->ringBuffer);
	while (true)
	{
		cout << "Выберете вариант:\n1) Добавить элемент в очередь\n2) Извлечение элемента из очереди\n";
		cout << "3) Удалить очередь\n4) Выход\n";
		int option;
		bool tryAgain = true;
		while (tryAgain)
		{
			try
			{
				option = EnterNumber("");
				tryAgain = false;
			}
			catch (const char* error)
			{
				cout << "Option must be a number!\n";
			}
		}
		
		while (option < 1 || option>4)
		{
			cout << "Option must be 1-4!\n";
			cin >> option;
		}

		switch (option)
		{
			case 1:
			{
				int newElement;
				bool tryAgain = true;
				while (tryAgain)
				{
					try
					{
						newElement = EnterNumber(
							"Введите новый элемент очереди\n");
					}
					catch (const char* error)
					{
						cout << "Element must be a number!\n";
					}
				}
				EnqueueRingBuffer(queueRingBuffer->ringBuffer, newElement);
				ShowQueueRingBuffer(queueRingBuffer->ringBuffer);
				break;
			}

			case 2:
			{
				int elementFromQueue;
				elementFromQueue = DequeueRingBuffer(queueRingBuffer->ringBuffer);
				cout << "Извлеченный элемент: %i\n", elementFromQueue;
				ShowQueueRingBuffer(queueRingBuffer->ringBuffer);
				break;
			}

			case 3:
			{
				DeleteQueueRingBuffer(queueRingBuffer->ringBuffer);
				cout << "Ваша очередь удалена!\n";
				int sizeOfQueue;
				EnterNumber("Введите размер очереди: ", sizeOfQueue);
				if ((int)log2(sizeOfQueue) % 2 != 0)
				{
					printf("Размер буфера должен быть степенью 2\n");
					return;
					break;
				}
				else
				{
					queueRingBuffer->ringBuffer = CreationOfQueue(sizeOfQueue);
					cout << "Очередь создана!\n";
					break;
				}
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
