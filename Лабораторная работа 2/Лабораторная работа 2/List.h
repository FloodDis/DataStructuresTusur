#pragma once
#include <string>
using namespace std;

/// <summary>
/// Узел списка
/// </summary>
struct Node
{
	/// <summary>
	/// Данные узла
	/// </summary>
	int DataOfNode;

	/// <summary>
	/// Указатель на следующий узел
	/// </summary>
	Node* NextNode;

	/// <summary>
	/// Указатель на предыдущий узел
	/// </summary>
	Node* PreviousNode;
};

/// <summary>
/// Функция инициализации списка
/// </summary>
/// <param name="dataOfHeadNode">данные корня списка</param>
/// <returns>
/// инициализированный узел
/// </returns>
Node* InitializationOfList(int dataOfHeadNode);

/// <summary>
/// Функция удаления узла списка
/// </summary>
/// <param name="headNode">указатель на корень списка</param>
/// <param name="index">индекс удаляемого элемента</param>
void DeleteElement(Node* headNode, int index);

/// <summary>
/// Функция добавления элемента в начало списока
/// </summary>
/// <param name="headNode">указатель на корень списка</param>
/// <param name="dataOfNewNode">данные нового элемента</param>
/// <returns>
/// указатель на новый корень списка
/// </returns>
Node* AddInTheBeginning(Node* headNode, int dataOfNewNode);

/// <summary>
/// Функция добавления элемента в конец списка
/// </summary>
/// <param name="headNode">указатель на корень списка</param>
/// <param name="dataOfNewNode">данные нового элемента</param>
void AddInTheEnd(Node* headNode, int dataOfNewNode);

/// <summary>
/// Функция добавления элемента перед определенным элементом
/// </summary>
/// <param name="headNode">указатель на корень списка</param>
/// <param name="dataOfNewNode">данные нового элемента</param>
/// <param name="index">индекс элемента, перед которым нужно добавить новый элемент</param>
/// <returns>
/// указатель на новый корень списка
/// </returns>
Node* AddBefore(Node* headNode, int dataOfNewNode, int index);

/// <summary>
/// Функция добавления элемента  после определенного элемента
/// </summary>
/// <param name="headNode">указатель на корень списка</param>
/// <param name="dataOfNewNode">данные нового элемента</param>
/// <param name="index">индекс элемента, после которого нужно добавить новый элемент</param>
void AddAfter(Node* headNode, int dataOfNewNode, int index);

/// <summary>
/// Функция сортировки пузырьком
/// </summary>
/// <param name="headNode">указатель на корень списка</param>
void BubbleSort(Node* headNode);

/// <summary>
/// Функция линейного поиска
/// </summary>
/// <param name="headNode">указатель на корень списка</param>
/// <param name="searchingValue">значение искомого элемента</param>
/// <returns>
/// искомый элемент
/// </returns>
Node* LinearSearch(Node* headNode, int searchingValue);

/// <summary>
/// Функция подсчета элементов списка
/// </summary>
/// <param name="headNode">указатель на корень списка</param>
/// <returns>
/// кол-во элементов списка
/// </returns>
int ElementCount(Node* headNode);

///<summary>
/// Функция получения случайного числа
/// </summary>
/// <returns>
/// случайное число
/// </returns>
int Randomize();

