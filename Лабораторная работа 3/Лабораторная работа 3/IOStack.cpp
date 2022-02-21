#include "IOStack.h"

void StackMenu()
{
	setlocale(LC_ALL, "Russian");
	//TODO: внести в while +	
	//TODO: длина
	int value = EnterNumber("Введите значение первого элемента: ");
	Node* stack = CreateStack();
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
			//TODO: ввести enum для кейсов
			case 1:
			{
				int dataOfNewElement = EnterNumber(
					"Введите значение нового элемента: \n");
				stack = Push(stack, dataOfNewElement);
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
					int valueFromStack = Pop(stack);
					cout << "\nЗначение из стека:" << valueFromStack <<
						"\n";
					ShowStack(stack);
				}
				break;
			}

			case 3:
			{
				Delete(stack);
				cout << "\nСтек удалён\n";
				Node* stack = CreateStack();
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
				ShowStack(stack);
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
	
//TODO: Неудачное название методов. Не заглядывая в сигнатуру методов,
//TODO: невозможно понять, в чём разница между ShowStack()
//TODO: и PrintStack(). 
void ShowStack(Node* headNode)
{
	cout << "Ваш стек:\n";
	PrintStack(headNode);
}