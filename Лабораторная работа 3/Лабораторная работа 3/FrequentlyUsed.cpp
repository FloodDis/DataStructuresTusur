#include "FrequentlyUsed.h"

//TODO: ���������� �� ������� � ������������ �� ������� +
int EnterNumber(string message)
{
	int inputValue;
	cout << message;
	cin >> inputValue;
	if (cin.fail())
	{
		cin.clear();
		string streamToDelete;
		cin >> streamToDelete;
		throw "Error: incorrect input data!\n";
	}
	return inputValue;
}