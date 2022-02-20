#pragma once

/// <summary>
/// Узел бинарного дерева
/// </summary>
struct BinaryTreeNode
{
	/// <summary>
	/// Указатель на левый дочерний узел
	/// </summary>
	BinaryTreeNode* Left = nullptr;

	/// <summary>
	/// Указатель на правый дочерний узел
	/// </summary>
	BinaryTreeNode* Right = nullptr;

	/// <summary>
	/// Ключ узла
	/// </summary>
	int Key;

	/// <summary>
	/// Данные узла
	/// </summary>
	int Data;
};

/// <summary>
/// Создание бинарного дерева
/// </summary>
/// <param name="keyOfRoot">ключ корня</param>
/// <param name="dataOfRoot">данные корня</param>
/// <returns>указатель на корень бинарного дерева</returns>
BinaryTreeNode* CreationOfBinaryTree(int keyOfRoot, int dataOfRoot);

/// <summary>
/// Функция добавления элемента в бинарное дерево
/// </summary>
/// <param name="rootNode">указатель на корень бинарного дерева</param>
/// <param name="keyToDelete">ключ добавляемого элемента</param>
/// <param name="dataOfNewNode">данные добавляемого элемента</param>
/// <returns>указатель на новый корень бинарного дерева</returns>
BinaryTreeNode* AddInBinaryTree(BinaryTreeNode* rootNode, int& keyToDelete, int& dataOfNewNode);

/// <summary>
/// Функция удаления элемента из бинарного дерева
/// </summary>
/// <param name="rootNode">указатель на корень бинарного дерева</param>
/// <param name="keyToDelete">ключ удаляемого элемента</param>
/// <returns>указатель на новый корень бинарного дерева</returns>
BinaryTreeNode* DeleteFromBinaryTree(BinaryTreeNode* rootNode, int keyToDelete);

/// <summary>
/// Функция поиска элемента в бинарном дереве
/// </summary>
/// <param name="rootNode">указатель на корень бинарного дерева</param>
/// <param name="searchingKey">ключ искомого элемента</param>
/// <returns>указатель на узел искомого элемента</returns>
BinaryTreeNode* BinaryTreeElementSearch(BinaryTreeNode* rootNode, int searchingKey);

/// <summary>
/// Функция поиска максимального элемента
/// </summary>
/// <param name="rootNode">указатель на корень бинарного дерева</param>
/// <returns>указатель на узел искомого элемента</returns>
BinaryTreeNode* MaximumBinaryTreeSearch(BinaryTreeNode* rootNode);

/// <summary>
/// Функция поиска минимального элемента
/// </summary>
/// <param name="rootNode">указатель на корень бинарного дерева</param>
/// <returns>указатель на узел искомого элемента</returns>
BinaryTreeNode* MinimumBinaryTreeSearch(BinaryTreeNode* rootNode);

/// <summary>
/// Функция проверки бинарного дерева на пустоту
/// </summary>
/// <param name="rootNode">указатель на корень бинарного дерева</param>
bool IsBinaryTreeEmpty(BinaryTreeNode* rootNode);