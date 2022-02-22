#include "IOQueueStack.h"

void QueueStackBasedMenu()
{
	/// <summary>
	/// Действия над очередью на базе 2-х стеков
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
	QueueStackBased* queueStackUnit = new QueueStackBased;
	CreateQueue(queueStackUnit);
	PrintQueue(queueStackUnit);
	while (true)
	{
		cout << "Выберите действие:\n"
			<< "1) Добавить элемент в очередь\n"
			<< "2) Извлечение элемента из очереди\n"
			<< "3) Удалить очередь\n"
			<< "4) Выход\n";
		int option = EnterNumber("");
		switch (option)
		{
			case Push:
			{
				int dataOfNewElement = EnterNumber(
					"Введите значение нового элемента: ");
				Enqueue(queueStackUnit, dataOfNewElement);
				PrintQueue(queueStackUnit);
				break;
			}

			case Pop:
			{
				bool isStackInEmpty = queueStackUnit->IsStackInEmpty;
				bool isStackOutEmpty = queueStackUnit->IsStackOutEmpty;
				if (isStackInEmpty && isStackOutEmpty)
				{
					cout << "Очередь пуста.\n";
					PrintQueue(queueStackUnit);
					break;
				}
				cout << "\nИзвлеченный элемент:" <<
					Dequeue(queueStackUnit) << "\n";
				if (queueStackUnit->IsStackInEmpty)
				{
					queueStackUnit->StackIn = CreateStack();
					queueStackUnit->StackIn->PreviousNode = nullptr;
				}
				PrintQueue(queueStackUnit);
				break;
			}

			case RemoveQueue:
			{
				DeleteQueue(queueStackUnit);
				cout << "\nВаша очередь удалена!\n";
				QueueStackBased* queueStackUnit = new QueueStackBased;
				CreateQueue(queueStackUnit);
				PrintQueue(queueStackUnit);
				break;
			}

			case Exit:
			{
				return;
			}

			default:
			{
				cout << "Попробуйте снова!\n";
				PrintQueue(queueStackUnit);
				break;
			}
		}
	}
}

void PrintQueue(QueueStackBased* queueStackUnit)
{
	setlocale(LC_ALL, "Russian");
	cout << "\nStackIn:";
	if (queueStackUnit->IsStackInEmpty)
	{
		cout << "\n{ }\n";
	}
	else
	{
		PrintStack(queueStackUnit->StackIn);
	}

	cout << "\nStackOut:";
	if (queueStackUnit->IsStackOutEmpty)
	{
		cout << "\n{ }\n";
	}
	else
	{
		PrintStack(queueStackUnit->StackOut);
	}
}