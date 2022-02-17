#include "Queue_Ring_Buffer_based.h"
#include "Queue_Stack_based.h"
#include "RingBuffer.h"
#include "Stack.h"

void StackMenu();
void RingBufferMenu();
void QueueStackBasedMenu();
void QueueRingBufferBasedMenu();

void MainMenu()
{
	setlocale(LC_ALL, "Russian");
	int option;
	while (true)
	{
		printf("Выберите структуру данных:\n1) Стек\n2) Кольцевой Буфер\n");
		printf("3) Очередь (на базе двух стеков)\n");
		printf("4) Очередь (на базе кольцевого буфера)\n");
		printf("5) Выйти\n");
		cin >> option;
		switch (option)
		{
			case 1:
			{
				StackMenu();
				break;
			}

			case 2:
			{
				RingBufferMenu();
				break;
			}

			case 3:
			{
				QueueStackBasedMenu();
				break;
			}

			case 4:
			{
				QueueRingBufferBasedMenu();
				break;
			}

			case 5:
			{
				return;
				break;
			}

			default:
			{
				printf("Попробуйте снова!\n");
				break;
			}
		}
	}
}





void QueueStackBasedMenu()
{
	setlocale(LC_ALL, "Russian");
	int option;
	int dataOfFirstElement;
	QueueStackBased* queueStackUnit = new QueueStackBased;
	CreationOfQueueStackBased(queueStackUnit);
	PrintQueueStackBased(queueStackUnit);
	while (true)
	{
		printf("Выберите действие:\n1) Добавить элемент в очередь\n2) Извлечение элемента из очереди\n");
		printf("3) Удалить очередь\n4) Выход\n");
		cin >> option;
		switch (option)
		{
			case 1:
			{
				int dataOfNewElement;
				printf("Введите значение нового элемента: ");
				cin >> dataOfNewElement;
				EnqueueStackBased(queueStackUnit, dataOfNewElement);
				PrintQueueStackBased(queueStackUnit);
				break;
			}

			case 2:
			{
				printf("\nИзвлеченный элемент: %i\n", DequeueStackBased(queueStackUnit));
				if (queueStackUnit->IsStackInEmpty)
				{
					queueStackUnit->StackIn = CreationOfStack();
					queueStackUnit->StackIn->PreviousNode = nullptr;
				}
				PrintQueueStackBased(queueStackUnit);
				break;
			}

			case 3:
			{
				DeleteQueueStackBased(queueStackUnit);
				printf("\nВаша очередь удалена!\n");
				QueueStackBased* queueStackUnit = new QueueStackBased;
				CreationOfQueueStackBased(queueStackUnit);
				PrintQueueStackBased(queueStackUnit);
				break;
			}

			case 4:
			{
				return;
				break;
			}

			default:
			{
				printf("Попробуйте снова!\n");
				break;
			}
		}
	}
}

void QueueRingBufferBasedMenu()
{
	setlocale(LC_ALL, "Russian");
	int option;
	int sizeOfQueue;
	cout << "Введите размер очереди: ";
	cin >> sizeOfQueue;
	if ((int)log2(sizeOfQueue) % 2 != 0)
	{
		cout << "Размер буфера должен степенью 2!\n";
		return;
	}
	else
	{
		QueueRingBufferBased* queueRingBuffer = new QueueRingBufferBased;
		queueRingBuffer->ringBuffer = CreationOfQueue(sizeOfQueue);
		cout << "Очередь создана!\n";
		ShowQueueRingBuffer(queueRingBuffer->ringBuffer);
		while (true)
		{
			cout << "Выберете вариант:\n1) Добавить элемент в очередь\n2) Извлечение элемента из очереди\n";
			cout << "3) Удалить очередь\n4) Выход\n";
			cin >> option;
			switch (option)
			{
				case 1:
				{
					int newElement;
					EnterNumber("Введите новый элемент очереди\n", newElement);
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
}


void main()
{
	MainMenu();
}