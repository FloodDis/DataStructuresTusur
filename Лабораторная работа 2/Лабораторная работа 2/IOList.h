#pragma once
#include "List.h"
#include <iostream>

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
/// Функция вывода сообщения и ввода значения переменной из консоли
/// </summary>
/// <param name="message">строка с сообщением</param>
int EnterNumber(string message);

/// <summary>
/// Функция вывода списка на экран
/// </summary>
/// <param name="headNode">указатель на корень списка</param>
void PrintList(Node* headNode);

///<summary>
/// Функция вывода сообщения Your list: и списка
/// </summary>
/// <param name="headNode">указатель на корень списка</param>
void ShowList(Node* headNode);