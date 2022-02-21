#include "IOQueueRingBuffer.h"
#include "IORingBuffer.h"
#include "IOStack.h"
#include "IOQueueStack.h"

void MainMenu()
{
	setlocale(LC_ALL, "Russian");
	while (true)
	{
		cout << "Выберите структуру данных:\n1) Стек\n"
			<< "2) Кольцевой буфер\n3) Очередь (на базе двух стеков)\n"
			<< "4) Очередь (на базе кольцевого буфера)\n"
			<< "5) Выйти\n";
		int option = EnterNumber("");
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
				QueueRingBufferMenu();
				break;
			}

			case 5:
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

void main()
{
	MainMenu();
}