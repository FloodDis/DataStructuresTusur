#include "IOStack.h"

void StackMenu()
{
	setlocale(LC_ALL, "Russian");
	//TODO: внести в while
	int value = EnterNumber("Введите значение первого элемента: ");
	Node* stack = CreationOfStack();
	stack->DataOfNode = value;
	printf("Стек создан!\n");
	ShowStack(stack);
	while (true)
	{
		printf("Выберите вариант:\n1) Вставить\n2) Взять\n3) Удалить стек\n4) Выход\n");
		cout << "Выберите вариант:\n1) Вставить\n"
			<< "2) Взять\n3) Удалить стек\n4) Выход\n";
		int option = EnterNumber("");
		switch (option)
		{
			case 1:
			{
				int dataOfNewElement = EnterNumber(
					"Введите значение нового элемента: \n");
				stack = PushInStack(stack, dataOfNewElement);
				ShowStack(stack);
				break;
			}

			case 2:
			{
				if (stack == nullptr)
				{
					printf("\nСтек пуст\n");
					ShowStack(stack);
				}
				else
				{
					int valueFromStack = PopFromStack(stack);
					printf("\nЗначение из стека: %i\n", valueFromStack);
					ShowStack(stack);
				}

				break;
			}

			case 3:
			{
				DeleteStack(stack);
				printf("\nСтек удалён\n");
				int value = EnterNumber("Введите значение первого элемента: ");
				Node* stack = CreationOfStack();
				stack->DataOfNode = value;
				printf("\nСтек создан!\n");
				ShowStack(stack);
				break;
			}

			case 4:
			{
				return;
			}

			default:
			{
				printf("Попробуйте снова!\n");
				break;
			}
		}
	}
}