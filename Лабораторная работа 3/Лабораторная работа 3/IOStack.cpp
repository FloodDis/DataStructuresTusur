#include "IOStack.h"

void StackMenu()
{
	/// <summary>
	/// Действия над стеком
	/// </summary>
	enum Actions
	{
		/// <summary>
		/// Добавить элемент
		/// </summary>
		Insert = 1,

		/// <summary>
		/// Извлечь элемент
		/// </summary>
		Extract,

		/// <summary>
		/// Удалить стек
		/// </summary>
		RemoveStack,

		/// <summary>
		/// Выйти в главное меню
		/// </summary>
		Exit
	};
	setlocale(LC_ALL, "Russian");
	int value = EnterNumber("Введите значение первого элемента: ");
	Node* stack = CreateStack();
	stack->DataOfNode = value;
	cout << "Стек создан!\n";
	ShowStack(stack);
	while (true)
	{
		cout << "Выберите вариант:\n"
			<< "1) Вставить\n"
			<< "2) Взять\n"
			<< "3) Удалить стек\n"
			<< "4) Выход\n";
		//TODO: внести в while +
		int option = EnterNumber("");
		switch (option)
		{
			case Insert:
			{
				int dataOfNewElement = EnterNumber(
					"Введите значение нового элемента: \n");
				stack = Push(stack, dataOfNewElement);
				ShowStack(stack);
				break;
			}

			case Extract:
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

			case RemoveStack:
			{
				Delete(stack);
				cout << "\nСтек удалён\n";
				Node* stack = CreateStack();
				cout << "\nСтек создан!\n";
				ShowStack(stack);
				break;
			}

			case Exit:
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

void ShowStack(Node* headNode)
{
	cout << "Ваш стек:\n";
	PrintStack(headNode);
}