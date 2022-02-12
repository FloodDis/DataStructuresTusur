#pragma once

/// <summary>
/// Узел декартова дерева
/// </summary>
struct TreapNode
{
	/// <summary>
	/// Ключ
	/// </summary>
	int Key;

	/// <summary>
	/// Приоритет
	/// </summary>
	int Priority;

	/// <summary>
	/// Указатель на левый дочерний узел
	/// </summary>
	TreapNode* Left = nullptr;

	/// <summary>
	/// Указатель на правый дочерний узел
	/// </summary>
	TreapNode* Right = nullptr;
};

/// <summary>
/// Декартово дерево
/// </summary>
struct Treap
{
	/// <summary>
	/// Указатель на корень декартова дерева
	/// </summary>
	TreapNode* Root;
};

/// <summary>
/// Функция создания декартова дерева
/// </summary>
/// <param name="node">указатель на корень декартова дерева</param>
/// <param name="key">ключ</param>
/// <param name="priority">приоритет</param>
/// <param name="left">указатель на корень левого поддерева</param>
/// <param name="right">указатель на корень правого поддерева</param>
/// <returns>указатель на корень декартова дерева</returns>
TreapNode* CreationOfTreap(TreapNode* node, int key, int priority, TreapNode* left, TreapNode* right);

/// <summary>
/// Функция поиска элемента в декартовом дереве
/// </summary>
/// <param name="node">указатель на корень декартова дерева</param>
/// <param name="key">ключ искомого элемента</param>
/// <returns>указатель на узел искомого элемента</returns>
TreapNode* FindElementInTreap(TreapNode* node, int key);

/// <summary>
/// Функция разрезания деревьев
/// </summary>
/// <param name="treapNode">указатель на корень декартова дерева</param>
/// <param name="key">ключ для разрезания</param>
/// <param name="left">указатель на корень левого дерева</param>
/// <param name="right">указатель на корень правого дерева</param>
void Split(TreapNode* treapNode, int key, TreapNode*& left, TreapNode*& right);

/// <summary>
/// Функция слияния деревьев
/// </summary>
/// <param name="left">указатель на левое дерево</param>
/// <param name="right">указатель на правое дерево</param>
/// <returns>указатель на корень слитого декартова дерева</returns>
TreapNode* Merge(TreapNode* left, TreapNode* right);

/// <summary>
/// Функция добавления элемента в декартово дерево (непотимизировано)
/// </summary>
/// <param name="treapUnit">указатель на экземпляр декартова дерева</param>
/// <param name="key">ключ добавляемого элемента</param>
/// <param name="priority">приоритет добавляемого элемента</param>
void AddInTreapUnoptimised(Treap* treapUnit, int key, int priority);

/// <summary>
/// Функция добавления элемента в декартово дерево (оптимизировано)
/// </summary>
/// <param name="treap">указатель на экземпляр декартова дерева</param>
/// <param name="node">указатель на корень декартова дерева</param>
/// <param name="parent">указатель на родительский узел дерева</param>
/// <param name="key">ключ добавляемого элемента</param>
/// <param name="priority">приоритет добавляемого элемента</param>
void AddInTreapOptomised(Treap* treap, TreapNode* node, TreapNode* parent, int key, int priority);

/// <summary>
/// Функция удаления элемента из декартова дерева (неоптимизировано)
/// </summary>
/// <param name="treap">указатель на экземпляр декартова дерева</param>
/// <param name="key">ключ удаляемого элемента</param>
void DeleteFromTreapUnoptimised(Treap* treap, int key);

/// <summary>
/// Функция удаления элемента из декартова дерева (оптимизировано)
/// </summary>
/// <param name="treap">казатель на экземпляр декартова дерева</param>
/// <param name="node">указатель на корень декартова дерева</param>
/// <param name="parent">указатель на родительский узел дерева</param>
/// <param name="key">ключ удаляемого элемента</param>
void DeleteFromTreapOptimised(Treap* treap, TreapNode* node, TreapNode* parent, int key);

/// <summary>
/// Функция вывода декартова дерева на экран
/// </summary>
/// <param name="nodeToPrint">указатель на корень дерева</param>
/// <param name="lndent">кол-во табуляций</param>
void PrintTreap(TreapNode* nodeToPrint, int lndent = 0);

/// <summary>
/// Функция проверки декартова дерева на пустоту
/// </summary>
/// <param name="treap">указатель на экземпляр дерева</param>
/// <returns>true - декартово дерево пустое, false - декартово дерево не пустое</returns>
bool IsTreapEmpty(Treap* treap);

/// <summary>
/// Функция удаления декартова дерева
/// </summary>
/// <param name=="node">указатель на корень декартова дерева</param>
void DeleteTreap(TreapNode* node);

/// <summary>
/// Функция вывода сообщения и декартова дерева
/// </summary>
/// <param name=="message">сообщение,выводимое на экран</param>
/// <param name=="nodeToPrint">корень поддерева</param>
void ShowTreap(string message, TreapNode* nodeToPrint);

/// <summary>
/// Функция вывода сообщения и ввода числа
/// </summary>
/// <param name=="message">сообщение,выводимое на экран</param>
/// <param name=="varible">переменная, которой присваивается вводимое значение</param>
void EnterNumber(string message, int& varible);