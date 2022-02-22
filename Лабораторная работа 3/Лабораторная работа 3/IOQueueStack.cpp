#include "IOQueueStack.h"

void QueueStackBasedMenu()
{
	/// <summary>
	/// �������� ��� �������� �� ���� 2-� ������
	/// </summary>
	enum Actions
	{
		/// <summary>
		/// �������� �������
		/// </summary>
		Push = 1,

		/// <summary>
		/// ������� �������
		/// </summary>
		Pop,

		/// <summary>
		/// ������� �������
		/// </summary>
		RemoveQueue,

		/// <summary>
		/// ����� � ������� ����
		/// </summary>
		Exit
	};
	setlocale(LC_ALL, "Russian");
	QueueStackBased* queueStackUnit = new QueueStackBased;
	CreateQueue(queueStackUnit);
	PrintQueue(queueStackUnit);
	while (true)
	{
		cout << "�������� ��������:\n"
			<< "1) �������� ������� � �������\n"
			<< "2) ���������� �������� �� �������\n"
			<< "3) ������� �������\n"
			<< "4) �����\n";
		int option = EnterNumber("");
		switch (option)
		{
			case Push:
			{
				int dataOfNewElement = EnterNumber(
					"������� �������� ������ ��������: ");
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
					cout << "������� �����.\n";
					PrintQueue(queueStackUnit);
					break;
				}
				cout << "\n����������� �������:" <<
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
				cout << "\n���� ������� �������!\n";
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
				cout << "���������� �����!\n";
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