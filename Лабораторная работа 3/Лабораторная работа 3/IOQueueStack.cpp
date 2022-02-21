#include "IOQueueStack.h"

void QueueStackBasedMenu()
{
	setlocale(LC_ALL, "Russian");

	QueueStackBased* queueStackUnit = new QueueStackBased;
	CreationOfQueueStackBased(queueStackUnit);
	PrintQueueStackBased(queueStackUnit);
	while (true)
	{
		cout << "Выберите действие:\n1) Добавить элемент в очередь\n";	
		//TODO: длина
		cout << "2) Извлечение элемента из очереди\n3) Удалить очередь\n";
		cout << "4) Выход\n";
		int option = EnterNumber("");
		switch (option)
		{	
		//TODO: ввести enum для кейсов
			case 1:
			{
				int dataOfNewElement = EnterNumber(
					"Введите значение нового элемента: ");
				EnqueueStackBased(queueStackUnit, dataOfNewElement);
				PrintQueueStackBased(queueStackUnit);
				break;
			}

			case 2:
			{
				bool isStackInEmpty = queueStackUnit->IsStackInEmpty;
				bool isStackOutEmpty = queueStackUnit->IsStackOutEmpty;
				if (isStackInEmpty && isStackOutEmpty)
				{
					cout << "Очередь пуста.\n";
					PrintQueueStackBased(queueStackUnit);
					break;
				}
					cout << "\nИзвлеченный элемент:" <<
					DequeueStackBased(queueStackUnit) << "\n";
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
				cout << "\nВаша очередь удалена!\n";
				QueueStackBased* queueStackUnit = new QueueStackBased;
				CreationOfQueueStackBased(queueStackUnit);
				PrintQueueStackBased(queueStackUnit);
				break;
			}

			case 4:
			{
				return;
			}

			default:
			{
				cout << "Попробуйте снова!\n";
				PrintQueueStackBased(queueStackUnit);
				break;
			}
		}
	}
}

void PrintQueueStackBased(QueueStackBased* queueStackUnit)
{
	setlocale(LC_ALL, "Russian");	
	//TODO: cout
	printf("\nStackIn:");
	if (queueStackUnit->IsStackInEmpty)
	{	
		//TODO: cout
		printf("\n{ }\n");
	}
	else
	{
		PrintStack(queueStackUnit->StackIn);
	}
		
	//TODO: cout
	printf("\nStackOut:");
	if (queueStackUnit->IsStackOutEmpty)
	{	
		//TODO: cout
		printf("\n{ }\n");
	}
	else
	{
		PrintStack(queueStackUnit->StackOut);
	}

}