﻿#pragma once

/// <summary>
/// Узел АВЛ-дерева
/// </summary>
struct AVLTreeNode
{
	/// <summary>
	/// Указатель на левый дочерний узел
	/// </summary>
	AVLTreeNode* Left = nullptr;

	/// <summary>
	/// Указатель на правый узел
	/// </summary>
	AVLTreeNode* Right = nullptr;

	/// <summary>
	/// Ключ узла
	/// </summary>
	int Key;

	/// <summary>
	/// Данные узла
	/// </summary>
	int Data;

	/// <summary>
	/// Высота поддерева
	/// </summary>
	int SubTreeHeight;
};

/// <summary>
/// Функция создания узла АВЛ-дерева
/// </summary>
/// <param name="keyOfRoot">ключ создаваемого узла</param>
/// <param name="dataOfRoot">данные создаваемого узла</param>
/// <returns>
/// созданный узел
/// </returns>
AVLTreeNode* CreationOfAVLTree(int keyOfRoot, int dataOfRoot);

/// <summary>
/// Функция получения высоты поддерева
/// </summary>
/// <param name="node">корень поддерева</param>
/// <returns>
///  высота поддерева
/// </returns>
int GetHeight(AVLTreeNode* node);

/// <summary>
/// Функция вычисления разницы высот поддеревьев
/// </summary>
/// <param name="node">корень дерева</param>
/// <returns>
/// разница высот поддеревьев
/// </returns>
int BalanceFactor(AVLTreeNode* node);

/// <summary>
/// Функция исправления высоты дерева
/// </summary>
/// <param name="node">корень дерева</param>
void FixHeight(AVLTreeNode* node);

/// <summary>
/// Функция правого поворота
/// </summary>
/// <param name="pNode">узел, вокруг которого производится поворот</param>
/// <returns>
/// новый корень поддерева
/// </returns>
AVLTreeNode* RotateRight(AVLTreeNode* nodeToRotate);

/// <summary>
/// Функция левого поворота
/// </summary>
/// <param name="qNode">узел, вокруг которого производится поворот</param>
/// <returns>
/// новый корень поддерева
/// </returns>
AVLTreeNode* RotateLeft(AVLTreeNode* qNode);

/// <summary>
/// Функция балансировки поддерева
/// </summary>
/// <param name="node">балансируемый узел</param>
/// <returns>
/// новый корень сбалансированного поддерева
/// </returns>
AVLTreeNode* Balance(AVLTreeNode* nodeToBalance);

/// <summary>
/// Функция добавления элемента в АВЛ-дерево
/// </summary>
/// <param name="rootNode">корень дерева</param>
/// <param name="keyToAdd">ключ добавляемого элемента</param>
/// <param name="dataOfNewNode">данные добавляемого элемента</param>
/// <returns>
/// новый корень дерева
/// </returns>
AVLTreeNode* AddInAVLTree(AVLTreeNode* rootNode, int key, int dataOfNewNode);

/// <summary>
/// Функция поиска минимального элемента
/// </summary>
/// <param name="rootNode">корень дерева или поддерева</param>
/// <returns>
/// минимальный элемент АВЛ-дерева
/// </returns>
AVLTreeNode* FindMinAVL(AVLTreeNode* rootNode);

/// <summary>
/// Функция удаления элемента из АВЛ-дерева
/// </summary>
/// <param name="rootNode">корень дерева</param>
/// <param name="keyToDelete">ключ удаляемого элемента</param>
/// <returns>
/// узел сбалансированного АВЛ-дерева
/// </returns>
AVLTreeNode* DeleteFromAVLTree(AVLTreeNode* rootNode, int keyToDelete);

/// <summary>
/// Функция поиска элемента в АВЛ-дереве
/// </summary>
/// <param name="rootNode">корень дерева</param>
/// <param name="searchingKey">ключ искомого элемента</param>
/// <returns>
/// искомый узел
/// </returns>
AVLTreeNode* ElementSearchAVL(AVLTreeNode* rootNode, int searchingKey);

/// <summary>
/// Функция вывода АВЛ-дерева на экран
/// </summary>
/// <param name="rootNode">корень дерева</param>
/// <param name="tabCount">количество табуляций</param>
void PrintAVLTree(AVLTreeNode* rootNode, int tabCount);

