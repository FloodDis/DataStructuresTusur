#pragma once
#include "PerformanceTest.h"
#include "RedBlackTree.h"
#include "FrequentlyUsed.h"
#include <fstream>
#include <iostream>
using namespace std;

/// <summary>
/// Функция вызова меню красно-черного дерева
/// </summary>
void RBTreeMenu();

/// <summary>
/// Функция вывода сообщения Ваше красно-черное дерево: 
/// и красно-черного дерева
/// </summary>
/// <param name="treeUnit">экземпляр красно-черного дерева</param>
void Show(RBTree* treeUnit);

/// <summary>
/// Функция вывода красно-черного дерева на экран
/// </summary>
/// <param name="rootNode">корень дерева</param>
/// <param name="tabCount">количество табуляций</param>
void Print(RBTreeNode* rootNode, int tabCount);