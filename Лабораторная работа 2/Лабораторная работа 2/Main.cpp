#include <iostream>
#include "List.h"
#include "IOList.h"
using namespace std;

void main()
{
	int dataOfTheNode = Randomize();
	Node* listUnit = InitializationOfList(dataOfTheNode);
	Show(listUnit);
	Menu(listUnit);
}