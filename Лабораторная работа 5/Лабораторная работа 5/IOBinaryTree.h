#pragma once
#include "BinaryTree.h"
#include "FrequentlyUsed.h"
#include <iostream>
using namespace std;

///<summary>
///‘ункци€ вызова меню бинарного дерева
///</summary>
void BinaryTreeMenu();

/// <summary>
/// ‘ункци€ вывода бинарного дерева на экран
/// </summary>
/// <param name="rootNode">указатель на корень бинарного дерева</param>
/// <param name="tabCount">кол-во табул€ций</param>
void Print(BinaryTreeNode* rootNode, int tabCount);

/// <summary>
/// ‘ункци€ вывода сообщени€ ¬аше бинарное дерево: и бинарного дерева
/// </summary>
/// <param name="rootNode">указатель на корень бинарного дерева</param>
void Show(BinaryTreeNode* rootNode);