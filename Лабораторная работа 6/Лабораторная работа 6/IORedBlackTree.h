#pragma once
#include "RedBlackTree.h"
#include "FrequentlyUsed.h"
#include <iostream>
using namespace std;

/// <summary>
/// Функция вызова меню красно-черного дерева
/// </summary>
void RBTreeMenu();

/// <summary>
/// Функция вывода сообщения Ваше красно-черное дерево: и красно-черного дерева
/// </summary>
/// <param name="treeUnit">экземпляр красно-черного дерева</param>
void ShowRBTree(RBTree* treeUnit);