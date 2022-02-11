#include <iostream>
#include "List.h"
using namespace std;
void main()
{
	int dataOfTheNode = Randomize();
	Node* listUnit = InitializationOfList(dataOfTheNode);
	ShowList(listUnit);
	Menu(listUnit);
}