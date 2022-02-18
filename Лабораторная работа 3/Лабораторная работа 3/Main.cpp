#include "IOQueueRingBuffer.h"
#include "IORingBuffer.h"
#include "IOStack.h"
#include "IOStackBased.h"

void MainMenu()
{
	setlocale(LC_ALL, "Russian");
	while (true)
	{
		printf("Выберите структуру данных:\n1) Стек\n2) Кольцевой Буфер\n");
		printf("3) Очередь (на базе двух стеков)\n");
		printf("4) Очередь (на базе кольцевого буфера)\n");
		printf("5) Выйти\n");
		int option;
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

void main()
{
	MainMenu();
}