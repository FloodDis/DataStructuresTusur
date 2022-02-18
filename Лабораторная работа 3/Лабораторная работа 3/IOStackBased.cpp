#include "IOStackBased.h"

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