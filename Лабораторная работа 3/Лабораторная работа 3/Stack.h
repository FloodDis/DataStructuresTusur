#pragma once
#include <iostream>
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
	/// Указатель на предыдущий узел
	/// </summary>
	Node* PreviousNode;
};

/// <summary>
/// Функция создания стека
/// </summary>
/// <returns>указатель на корень стека</returns>
//TODO: см. PopFromStack
Node* CreationOfStack();

/// <summary>
/// Функция добавления элемента в стек
/// </summary>
/// <param name="headNode">укзатель на корень стека</param>
/// <param name="dataOfNewElement">значение нового элемента</param>
/// <returns>указатель на новый корень списка</returns>
//TODO: см. PopFromStack
Node* PushInStack(Node* headNode, int dataOfNewElement);

/// <summary>
/// Функция извлечения элемента из стека
/// </summary>
/// <param name="headNode">укзатель на корень стека</param>
/// <returns>значение извлеченного элемента</returns>
//TODO: PopFromStack находится в СД Stack,
//TODO: поэтому дублирования названия СД в названии метода не нужно
int PopFromStack(Node*& headNode);

/// <summary>
/// Функция удаления стека
/// </summary>
/// <param name="headNode">укзатель на корень стека</param>
//TODO: см. PopFromStack
void DeleteStack(Node*& headNode);