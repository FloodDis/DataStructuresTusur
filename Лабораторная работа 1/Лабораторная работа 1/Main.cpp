#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct StructOfArray
{
	int* Array;
	int Length;
	int Capacity;
	const int GrowthFactor = 8;
};

void CreateArray(StructOfArray* arrayUnit, int length, int capacity);

void AddByIndex(StructOfArray* arrayUnit, int index);

void DeleteByIndex(StructOfArray* arrayUnit, int index);

void CountingSort(StructOfArray* arrayUnit);

void LenearSearch(StructOfArray* arrayUnit, int searchingValue);

void BinarySearch(StructOfArray* arrayUnit, int searchingValue);

void PrintArray(StructOfArray* arrayUnit);

void Menu(StructOfArray* arrayUnit);

void ShowArray(StructOfArray* arrayUnit);

void main()
{
	srand(time(nullptr));
	StructOfArray arrayUnit;
	CreateArray(&arrayUnit, 6, 9);
	ShowArray(&arrayUnit);
	Menu(&arrayUnit);
}

int EnterNumber(string message, int variable)
{
	cout << message;
	cin >> variable;
	return variable;
}

void CreateArray(StructOfArray* arrayUnit, int length, int capacity)
{
	arrayUnit->Length = length;
	arrayUnit->Capacity = capacity;
	arrayUnit->Array = new int[arrayUnit->Capacity];

	for (int i = 0; i < arrayUnit->Length; i++)
	{
		arrayUnit->Array[i] = rand() % 151 - 100;
	}
}

void AddByIndex(StructOfArray* arrayUnit, int index)
{
	int temp = arrayUnit->Array[index];
	arrayUnit->Array[index] = EnterNumber(
		"Enter your element:\narray [" + to_string(index) + "] = ", arrayUnit->Array[index]);

	for (int i = index + 1; i < arrayUnit->Length; i++)
	{
		swap(temp, arrayUnit->Array[i]);
	}

	if (index != arrayUnit->Length)
	{
		arrayUnit->Array[arrayUnit->Length] = temp;
	}
	arrayUnit->Length++;

	if (arrayUnit->Length == arrayUnit->Capacity)
	{
		StructOfArray tempArray;
		CreateArray(&tempArray, arrayUnit->Length, arrayUnit->Capacity);

		for (int i = 0; i < arrayUnit->Length; i++)
		{
			tempArray.Array[i] = arrayUnit->Array[i];
		}
		delete[] arrayUnit->Array;
		arrayUnit->Array = nullptr;

		CreateArray(arrayUnit, arrayUnit->Length, arrayUnit->Length + 8);
		for (int i = 0; i < arrayUnit->Length; i++)
		{
			arrayUnit->Array[i] = tempArray.Array[i];
		}
		delete[] tempArray.Array;
		tempArray.Array = nullptr;
	}
}

void DeleteByIndex(StructOfArray* arrayUnit, int index)
{
	for (int i = index; i < arrayUnit->Length - 1; i++)
	{
		arrayUnit->Array[i] = arrayUnit->Array[i + 1];
	}
	arrayUnit->Length--;
	arrayUnit->Array[arrayUnit->Length] = NULL;
}

void CountingSort(StructOfArray* arrayUnit)
{
	int max = *max_element(arrayUnit->Array, arrayUnit->Array + arrayUnit->Length);
	int min = *min_element(arrayUnit->Array, arrayUnit->Array + arrayUnit->Length);
	int range = max - min + 1;
	int* count = new int[range];
	int* output = new int[arrayUnit->Length];

	for (int i = 0; i < range; i++)
	{
		count[i] = 0;
	}

	for (int i = 0; i < arrayUnit->Length; i++)
	{
		count[arrayUnit->Array[i] - min]++;
	}

	for (int i = 1; i < range; i++)
	{
		count[i] += count[i - 1];
	}

	for (int i = arrayUnit->Length - 1; i >= 0; i--)
	{
		output[count[arrayUnit->Array[i] - min] - 1] = arrayUnit->Array[i];
		count[arrayUnit->Array[i] - min]--;
	}

	for (int i = 0; i < arrayUnit->Length; i++)
	{
		arrayUnit->Array[i] = output[i];
	}
	delete[] count;
	count = nullptr;

	delete[] output;
	output = nullptr;
}

void LenearSearch(StructOfArray* arrayUnit, int searchingValue)
{
	int index = -1;
	for (int i = 0; i < arrayUnit->Length; i++)
	{
		if (arrayUnit->Array[i] == searchingValue)
		{
			index = i;
			break;
		}
	}

	if (index != -1)
	{
		cout << "array [" << index << "] = " << arrayUnit->Array[index] << "\n";
	}
	else
	{
		cout << "\nElement wasn't found\n" << endl;
	}
}

void BinarySearch(StructOfArray* arrayUnit, int searchingValue)
{
	int first = 0;
	int last = arrayUnit->Length;
	while (first < last)
	{
		int mid = (first + last) / 2;
		if (searchingValue <= arrayUnit->Array[mid])
		{
			last = mid;
		}
		else
		{
			first = mid + 1;
		}
	}

	if (first == arrayUnit->Length || arrayUnit->Array[first] != searchingValue)
	{
		cout << "\nElement wasn't found\n" << endl;
	}
	else
	{
		cout << "\narray[" << first << "] = " << arrayUnit->Array[first] << "\n";
	}

}

void PrintArray(StructOfArray* arrayUnit)
{
	cout << endl;
	for (int i = 0; i < arrayUnit->Length; i++)
	{
		cout << "\narray[" << i << "] = " << arrayUnit->Array[i];
	}
	cout << endl;
}

void ShowArray(StructOfArray* arrayUnit)
{
	cout << "Your array:\n";
	PrintArray(arrayUnit);
}

void Menu(StructOfArray* arrayUnit)
{
	while (true)
	{
		int option;
		cout << "Select an action:\n1) Add element\n2) Delete element\n";
		cout << "3) Sort the array\n4) Search element\n5) Print the array\n";
		cout << "6) Quit\n";
		cin >> option;

		switch (option)
		{
			case 1:
			{
				int index = arrayUnit->Length;
				do
				{
					cout << "Enter the index of adding element (0 - " << arrayUnit->Length << ")\n";
					cout << "0 - add to the beginning " << arrayUnit->Length << " - add to the end\n";
					cin >> index;
				} while (index < 0 || index > arrayUnit->Length);
				AddByIndex(arrayUnit, index);
				ShowArray(arrayUnit);
				break;
			}

			case 2:
			{
				if (arrayUnit->Length == 0)
				{
					cout << "Array is already empty\n\n";
					break;
				}

				int index = arrayUnit->Length;
				do
				{
					cout << 
						"Enter the index of deleteing element (0 - " << arrayUnit->Length - 1 << ")\n";
					cout << "0 - delete the first element\t ";
					cout << arrayUnit->Length - 1 << " - delete the last element\n";
					cin >> index;
				} while (index < 0 || index >= arrayUnit->Length);

				DeleteByIndex(arrayUnit, index);
				ShowArray(arrayUnit);
				break;
			}

			case 3:
			{
				CountingSort(arrayUnit);
				ShowArray(arrayUnit);
				break;
			}

			case 4:
			{
				int searchingValue = 0;
				searchingValue = EnterNumber("Enter searching value: ", searchingValue);

				do
				{
					option = EnterNumber(
						"Select search method:\n1) Lenear search\n2) Binary search\n", option);

					if (option == 1)
					{
						LenearSearch(arrayUnit, searchingValue);
					}
					else if (option == 2)
					{
						CountingSort(arrayUnit);
						BinarySearch(arrayUnit, searchingValue);
					}
				} while (option < 1 || option>2);
				ShowArray(arrayUnit);
				break;
			}

			case 5:
			{
				ShowArray(arrayUnit);
				break;
			}

			case 6:
			{
				return;
			}

			default:
			{
				cout << "Try again" << endl;
				break;
			}

		}
	}
}