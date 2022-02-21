#include "IOQueueRingBuffer.h"
#include "IORingBuffer.h"

void QueueRingBufferMenu()
{
	setlocale(LC_ALL, "Russian");
	int sizeOfQueue = EnterNumber("Введите размер очереди: ");
	QueueRingBuffer* queueRingBuffer = new QueueRingBuffer;
	queueRingBuffer->ringBuffer = CreateQueue(sizeOfQueue);
	cout << "Очередь создана!\n";
	ShowQueueRingBuffer(queueRingBuffer->ringBuffer);
	while (true)
	{	
		//TODO: Читабельность.
		//TODO: Каждую строку в консоли лучше писать в отдельный cout
		cout << "Выберете вариант:\n1) Добавить элемент в очередь\n";	
		//TODO: длина
		cout << "2) Извлечение элемента из очереди\n3) Удалить очередь\n";
		cout << "4) Выход\n";
		int option;
		option = EnterNumber("");
		switch (option)
		{	
		//TODO: enum для кейсов
			case 1:
			{
				if (IsFull(queueRingBuffer->ringBuffer))
				{
					cout << "Очередь заполнена.\n";
					ShowQueueRingBuffer(queueRingBuffer->ringBuffer);
					break;
				}
				else
				{
					int newElement = EnterNumber(
						"Введите новый элемент очереди\n");	
					//TODO: длина
					Enqueue(queueRingBuffer->ringBuffer, newElement);
					ShowQueueRingBuffer(queueRingBuffer->ringBuffer);
					break;
				}
			}

			case 2:
			{
				if (IsEmpty(queueRingBuffer->ringBuffer))
				{
					cout << "Очередь пуста.\n";
					ShowQueueRingBuffer(queueRingBuffer->ringBuffer);
					break;
				}
				else
				{
					//TODO: длина
					int elementFromQueue =
						Dequeue(queueRingBuffer->ringBuffer);
					//TODO: длина
					cout << "Извлеченный элемент:" << elementFromQueue << "\n";
					ShowQueueRingBuffer(queueRingBuffer->ringBuffer);
					break;
				}
			}

			case 3:
			{
				DeleteQueue(queueRingBuffer->ringBuffer);
				cout << "Ваша очередь удалена!\n";
				//TODO: длина
				int sizeOfQueue = EnterNumber("Введите размер очереди: ");
				queueRingBuffer->ringBuffer = CreateQueue(sizeOfQueue);
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
//TODO: лишняя сложность
void PrintQueueRingBuffer(RingBuffer* queueRingBufferUnit)
{
	PrintBuffer(queueRingBufferUnit);
}
//TODO: Неудачное именование методов.
//TODO: Невозможно понять разницу между ShowQueueRingBuffer()
//TODO: и PrintQueueRingBuffer(), не заглядывая в сигнатуры методов.
void ShowQueueRingBuffer(RingBuffer* queueRingBufferUnit)
{
	cout << "Ваш буфер:\n";
	PrintQueueRingBuffer(queueRingBufferUnit);
}