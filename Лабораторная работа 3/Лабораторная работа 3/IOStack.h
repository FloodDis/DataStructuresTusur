#pragma once
#include "Stack.h"
#include "FrequentlyUsed.h"

///<summary>
///Функция меню для стека
///</summary>
void StackMenu();

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