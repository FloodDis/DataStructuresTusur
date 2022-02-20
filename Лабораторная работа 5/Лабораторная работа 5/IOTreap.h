#pragma once
#include "Treap.h"
#include "FrequentlyUsed.h"
#include <iostream>
using namespace std;

///<summary>
///‘ункци€ вызова меню декартова дерева
///</summary>
void TreapMenu();

/// <summary>
/// ‘ункци€ вывода декартова дерева на экран
/// </summary>
/// <param name="nodeToPrint">указатель на корень дерева</param>
/// <param name="lndent">кол-во табул€ций</param>
void PrintTreap(TreapNode* nodeToPrint, int lndent = 0);

/// <summary>
/// ‘ункци€ вывода сообщени€ и декартова дерева
/// </summary>
/// <param name=="message">сообщение,выводимое на экран</param>
/// <param name=="nodeToPrint">корень поддерева</param>
void ShowTreap(string message, TreapNode* nodeToPrint);