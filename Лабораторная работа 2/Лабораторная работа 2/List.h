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
/// Функция вывода списка на экран
/// </summary>
/// <param name="headNode">указатель на корень списка</param>
void PrintList(Node* headNode);

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
/// Функция вывода на экран элементов, найденных с помощью линейного поиска
/// </summary>
/// <param name="indexes">указатель на корень списка индексов найденных элементов</param>
/// <param name="headNode">>указатель на корень списка</param>
void PrintFinded(Node* indexes, Node* headNode);

/// <summary>
/// Функция меню
/// </summary>
/// <param name="headNode">указатель на корень списка</param>
void Menu(Node* headNode);

/// <summary>
/// Функция подсчета элементов списка
/// </summary>
/// <param name="headNode">указатель на корень списка</param>
/// <returns>
/// кол-во элементов списка
/// </returns>
int ElementCount(Node* headNode);

/// <summary>
/// Функция вывода сообщения и ввода значения переменной из консоли
/// </summary>
/// <param name="message">строка с сообщением</param>
/// <param name="variable">значение переменной</param>
/// <returns>
/// значение переменной
/// </returns>
int EnterNumber(string message, int variable);

///<summary>
/// Функция получения случайного числа
/// </summary>
/// <returns>
/// случайное число
/// </returns>
int Randomize();

///<summary>
/// Функция вывода сообщения Your list: и списка
/// </summary>
/// <param name="headNode">указатель на корень списка</param>
void ShowList(Node* headNode);