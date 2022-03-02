#include "FrequentlyUsed.h"
//TODO: Вынести в отдельный проект
int EnterNumber(string message)
{
	cout << message;
	int value;
	char input;
	while (cin >> input)
	{
		if (isdigit(input) || input == '-')
		{
			cin.unget();
			cin >> value;
			return value;
		}
		else
		{
			cout << "Неверный ввод!\n";
		}
	}
}