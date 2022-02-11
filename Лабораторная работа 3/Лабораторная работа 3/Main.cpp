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

void StackMenu()
{
	setlocale(LC_ALL, "Russian");
	int option;
	int value;
	printf("Введите значение первого элемента: ");
	cin >> value;
	Node* stack = CreationOfStack();
	stack->DataOfNode = value;
	printf("Стек создан!\n");
	printf("Ваш стек:\n");
	PrintStack(stack);
	while (true)
	{
		printf("Выберите вариант:\n1) Вставить\n2) Взять\n3) Удалить стек\n4) Выход\n");
		cin >> option;
		switch (option)
		{
		case 1:
		{
			int dataOfNewElement;
			printf("Введите значение нового элемента: \n");
			cin >> dataOfNewElement;
			stack = PushInStack(stack, dataOfNewElement);
			printf("Ваш стек:\n");
			PrintStack(stack);
			break;
		}
		case 2:
		{
			if (stack == nullptr)
			{
				printf("\nСтек пуст\n");
				printf("\nВаш стек:\n");
				PrintStack(stack);
			}
			else
			{
				int valueFromStack;
				valueFromStack = PopFromStack(stack);
				printf("\nЗначение из стека: %i\n", valueFromStack);
				printf("Ваш стек:\n");
				PrintStack(stack);
			}

			break;
		}
		case 3:
		{
			DeleteStack(stack);
			printf("\nСтек удалён\n");
			int value;
			printf("Введите значение первого элемента: ");
			cin >> value;
			Node* stack = CreationOfStack();
			stack->DataOfNode = value;
			printf("\nСтек создан!\n");
			printf("\nВаш стек\n");
			PrintStack(stack);
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

void RingBufferMenu()
{
	setlocale(LC_ALL, "Russian");
	int option;
	unsigned int sizeOfBuffer;
	printf("Введите размер буфера: ");
	cin >> sizeOfBuffer;
	if ((int)log2(sizeOfBuffer) % 2 != 0)
	{
		printf("Размер буфера должен быть степенью двойки!\n");
		return;
	}
	else
	{
		RingBuffer* ringBuffer = InitializationOfRingBuffer(sizeOfBuffer);
		printf("Буфер создан!\n");
		while (true)
		{
			printf("Выберите вариант:\n1) Проверить, есть ли в буфере место для записи\n");
			printf("2) Проверить, пуст ли буфер\n3) Вставить\n4) Взять\n5) Выход\n");
			cin >> option;
			switch (option)
			{
			case 1:
			{
				bool answer = IfThereSpaceToWrite(ringBuffer);
				if (answer == true)
				{
					printf("В буфере есть место для записи!\n");
				}
				else
				{
					printf("В буфере нет места для записи!\n");
				}
				break;
			}
			case 2:
			{
				bool answer = IsEmpty(ringBuffer);
				if (answer == true)
				{
					printf("\nБуфер пуст!\n");
				}
				else
				{
					printf("\nБуфер не пуст!\n");
					printf("Ваш буфер:\n");
					PrintBuffer(ringBuffer);
				}
				break;
			}
			case 3:
			{
				if (IfThereSpaceToWrite(ringBuffer))
				{
					int newElement;
					printf("Введите значение нового элемента: ");
					cin >> newElement;
					PushInRingBuffer(ringBuffer, newElement);
					printf("Ваш буфер:\n");
					PrintBuffer(ringBuffer);
					break;
				}
				else
				{
					printf("В буфере нет места для записи!\n");
					printf("Ваш буфер:\n");
					PrintBuffer(ringBuffer);
					break;
				}

			}
			case 4:
			{
				int elementFromBuffer = PopFromRingBuffer(ringBuffer);
				printf("Значение из буфера: %i\n", elementFromBuffer);
				printf("Ваш буфер:\n");
				PrintBuffer(ringBuffer);
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
	printf("Введите размер очереди: ");
	cin >> sizeOfQueue;
	if ((int)log2(sizeOfQueue) % 2 != 0)
	{
		printf("Размер буфера должен степенью 2!\n");
		return;
	}
	else
	{
		RingBuffer* queueRingBuffer = CreationOfQueue(sizeOfQueue);
		printf("Очередь создана!\n");
		printf("Ваша очередь:\n");
		PrintQueueRingBuffer(queueRingBuffer);
		while (true)
		{
			printf("Выберете вариант:\n1) Добавить элемент в очередь\n2) Извлечение элемента из очереди\n");
			printf("3) Удалить очередь\n4) Выход\n");
			cin >> option;
			switch (option)
			{
			case 1:
			{
				int newElement;
				printf("Введите новый элемент очереди\n");
				cin >> newElement;
				EnqueueRingBuffer(queueRingBuffer, newElement);
				printf("Ваша очередь:\n");
				PrintQueueRingBuffer(queueRingBuffer);
				break;
			}
			case 2:
			{
				int elementFromQueue;
				elementFromQueue = DequeueRingBuffer(queueRingBuffer);
				printf("Извлеченный элемент: %i\n", elementFromQueue);
				printf("Ваша очередь:\n");
				PrintQueueRingBuffer(queueRingBuffer);
				break;
			}
			case 3:
			{
				DeleteQueueRingBuffer(queueRingBuffer);
				printf("Ваша очередь удалена!\n");
				int sizeOfQueue;
				printf("Введите размер очереди: ");
				cin >> sizeOfQueue;
				if ((int)log2(sizeOfQueue) % 2 != 0)
				{
					printf("Размер буфера должен быть степенью 2\n");
					return;
					break;
				}
				else
				{
					RingBuffer* queueRingBuffer = CreationOfQueue(sizeOfQueue);
					printf("Очередь создана!\n");
					break;
				}
			case 4:
			{
				return;
				break;
			}
			default:
			{
				printf("Попробуйте ещё раз!\n");
				break;
			}
			}
			}
		}
	}
}

void main()
{
	MainMenu();
}