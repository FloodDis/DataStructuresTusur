#include "FrequentlyUsed.h"

//TODO: ���������� �� ������� � ������������ �� ������� +
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
			cout << "�������� ����!\n";
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
