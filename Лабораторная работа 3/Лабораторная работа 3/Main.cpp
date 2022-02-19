#include "IOQueueRingBuffer.h"
#include "IORingBuffer.h"
#include "IOStack.h"
#include "IOQueueStack.h"

void MainMenu()
{
	setlocale(LC_ALL, "Russian");
	while (true)
	{
		cout << "Выберите структуру данных:\n1) Стек\n2) Кольцевой Буфер\n";
		cout << "3) Очередь (на базе двух стеков)\n";
		cout << "4) Очередь (на базе кольцевого буфера)\n";
		cout << "5) Выйти\n";
		int option;
		bool tryAgain = true;
		while (tryAgain)
		{
			try
			{
				option = EnterNumber("");
				tryAgain = false;
			}
			catch (const char* error)
			{
				cout << "Option must be a number!\n";
			}
		}

		while (option < 1 || option>5)
		{
			cout << "Option must be 1-5!\n";
			cin >> option;
		}

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