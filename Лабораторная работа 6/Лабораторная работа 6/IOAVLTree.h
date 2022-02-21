#pragma once
#include <iostream>
#include "AVLTree.h"
#include "FrequentlyUsed.h"
using namespace std;

/// <summary>
/// Функция вызова меню АВЛ-дерева
/// </summary>
void AVLTreeMenu();

/// <summary>
/// Функция вывода сообщения Ваше АВЛ-дерево: и АВЛ-дерева
/// </summary>
void Show(AVLTreeNode* rootNode);

/// <summary>
/// Функция вывода АВЛ-дерева на экран
/// </summary>
/// <param name="rootNode">корень дерева</param>
/// <param name="tabCount">количество табуляций</param>
void Print(AVLTreeNode* rootNode, int tabCount);