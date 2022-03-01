#include "FrequentlyUsed.h"

//TODO: Переделать на вариант с возвращением из функции +
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

string EnterString(string message)
{
	cout << message;
	string value;
	cin >> value;
	return value;
}