#include "IOStack.h"

void StackMenu()
{
	setlocale(LC_ALL, "Russian");
	//TODO: внести в while +
	int value = EnterNumber("Введите значение первого элемента: ");
	Node* stack = CreationOfStack();
	stack->DataOfNode = value;
	cout << "Стек создан!\n";
	ShowStack(stack);
	while (true)
	{
		cout << "Выберите вариант:\n1) Вставить\n";
		cout << "2) Взять\n3) Удалить стек\n4) Выход\n";
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
					cout << "\nСтек пуст\n";
					ShowStack(stack);
				}
				else
				{
					int valueFromStack = PopFromStack(stack);
					cout << "\nЗначение из стека:" << valueFromStack <<
						"\n";
					ShowStack(stack);
				}
				break;
			}

			case 3:
			{
				DeleteStack(stack);
				cout << "\nСтек удалён\n";
				Node* stack = CreationOfStack();
				cout << "\nСтек создан!\n";
				ShowStack(stack);
				break;
			}

			case 4:
			{
				return;
			}

			default:
			{
				cout << "Попробуйте снова!\n";
				break;
			}
		}
	}
}

void PrintStack(Node* headNode)
{
	if (headNode == nullptr)
	{
		cout << "\n{ }\n";
		return;
	}

	cout << "\n{" << headNode->DataOfNode << "}";
	headNode = headNode->PreviousNode;

	while (headNode != nullptr)
	{
		cout << " " << headNode->DataOfNode;
		headNode = headNode->PreviousNode;
	}

	cout << "\n";
}

void ShowStack(Node* headNode)
{
	cout << "Ваш стек:\n";
	PrintStack(headNode);
}