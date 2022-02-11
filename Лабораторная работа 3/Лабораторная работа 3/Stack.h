#pragma once
#include <iostream>
using namespace std;

/// <summary>
/// Узел
/// </summary>
struct Node
{
	/// <summary>
	/// Данные узла
	/// </summary>
	int DataOfNode;

	/// <summary>
	/// Указатель на предыдущий узел
	/// </summary>
	Node* PreviousNode;
};

/// <summary>
/// Функция создания стека
/// </summary>
/// <returns>указатель на корень стека</returns>
Node* CreationOfStack();

/// <summary>
/// Функция добавления элемента в стек
/// </summary>
/// <param name="headNode">укзатель на корень стека</param>
/// <param name="dataOfNewElement">значение нового элемента</param>
/// <returns>указатель на новый корень списка</returns>
Node* PushInStack(Node* headNode, int dataOfNewElement);

/// <summary>
/// Функция извлечения элемента из стека
/// </summary>
/// <param name="headNode">укзатель на корень стека</param>
/// <returns>значение извлеченного элемента</returns>
int PopFromStack(Node*& headNode);

/// <summary>
/// Функция удаления стека
/// </summary>
/// <param name="headNode">укзатель на корень стека</param>
void DeleteStack(Node*& headNode);

/// <summary>
/// Функция вывода стека на экран
/// </summary>
/// <param name="headNode">укзатель на корень стека</param>
void PrintStack(Node* headNode);

/// <summary>
/// Функция вывода сообщения Ваш стек: и стека на экран
/// </summary>
/// <param name="headNode">укзатель на корень стека</param>
void ShowStack(Node* headNode);