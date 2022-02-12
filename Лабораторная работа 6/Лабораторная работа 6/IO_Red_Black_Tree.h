#pragma once
#include "Red_Black_Tree.h"
#include <iostream>
using namespace std;

/// <summary>
/// Функция вызова меню красно-черного дерева
/// </summary>
void RBTreeMenu();

/// <summary>
/// Функция вывода сообщения и ввода числа
/// </summary>
/// <param name="message">выводимое сообщение</param>
/// <param name="value">переменная, которой присваивается вводимое значение</param> 
void EnterNumber(string message, int& value);

/// <summary>
/// Функция вывода сообщения Ваше красно-черное дерево: и красно-черного дерева
/// </summary>
/// <param name="treeUnit">экземпляр красно-черного дерева</param>
void ShowRBTree(RBTree* treeUnit);