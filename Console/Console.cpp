#include "Console.h"

int Console::ReadInt(string message)
{
	cout << message;
	int inputValue;
	cin >> inputValue;
	if (cin.fail())
	{
		cin.clear();
		string stringToDelete;
		cin >> stringToDelete;
		throw exception("Error: incorrect input data.");
	}
	return inputValue;
}

string Console::ReadString(string message)
{
	cout << message;
	string inputValue;
	cin >> inputValue;
	return inputValue;
}