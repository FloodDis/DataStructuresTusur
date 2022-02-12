#pragma once
#include <iostream>
#include "IO_Red_Black_Tree.h"
#include "AVL_Tree.h"
using namespace std;

/// <summary>
/// Функция вызова меню АВЛ-дерева
/// </summary>
void AVLTreeMenu();

/// <summary>
/// Функция вывода сообщения Ваше АВЛ-дерево: и АВЛ-дерево
/// </summary>
void ShowAVLTree(AVLTreeNode* rootNode);