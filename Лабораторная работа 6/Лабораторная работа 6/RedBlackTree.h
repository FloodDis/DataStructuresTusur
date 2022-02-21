#pragma once
#include <iostream>
using namespace std;

/// <summary>
/// Дочерний узел
/// </summary>
enum Child
{
	/// <summary>
	/// Левый дочерний узел
	/// </summary>
	Left,

	/// <summary>
	/// Правый дочерний узел
	/// </summary>
	Right
};

/// <summary>
/// Узел красно-черного дерева
/// </summary>
struct RBTreeNode
{
	/// <summary>
	/// Ключ узла
	/// </summary>
	int Key;

	/// <summary>
	/// true если узел чёрный и false если узел красный.
	/// </summary>
	bool IsBlack;

	/// <summary>
	/// Указатели на дочернии узлы 0 - левый, 1 - правый.
	/// </summary>
	RBTreeNode* Child[2];
};

class RBTree
{
public:

	///<summary>
	/// Конструктор класса RBTree
	/// </summary>
	RBTree();

	///<summary>
	/// Деструктор класса RBTree
	/// </summary>
	~RBTree();

	/// <summary>
	/// Создаёт узел в красно-чёрном дереве с заданным ключём.
	/// </summary>
	/// <param name="key">
	/// ключ созданного узла
	/// </param>
	void Insert(int key);

	/// <summary>
	/// Удаляет любой красный узел или черный узел 
	/// с одним ребёнком из красно-чёрного дерева
	/// </summary>
	/// <param name="key">
	/// ключ удаляемого узла
	/// </param>
	void Delete(int key);

	/// <summary>
	/// Функция поиска элемента
	/// </summary>
	/// <param name="key">ключ искомого элемента</param>
	/// <returns>
	/// Искомый элемент или nullptr, если элемент не найден
	/// </returns>
	RBTreeNode* Find(int key);

	/// <summary>
	/// Функция получения корня
	/// </summary>
	/// <returns>
	/// Узел, являющийся корнем или nil (фиктивный узел)
	/// </returns>
	RBTreeNode* GetRoot()
	{
		return _root;
	}

	/// <summary>
	/// Функция получения количества выполненных поворотов 
	/// </summary>
	///<returns>
	/// Кол-во поворотов
	/// </returns>
	int GetNodeRotateCount()
	{
		return _nodeRotateCount;
	}

	/// <summary>
	/// Сбрасывает количество выполненых поворот над узлам до нуля
	/// </summary>
	void ResetNodeRotateCount()
	{
		_nodeRotateCount = 0;
	}

private:
	/// <summary>
	/// Функция проверки красный ли заданный узел
	/// </summary>
	/// <returns>
	/// true если узел красный и не равен nullptr, иначе false
	/// </returns>
	bool IsRed(RBTreeNode* node);

	/// <summary>
	/// Функция рекурсивно создаёт узел с заданным ключом
	/// в заданном поддереве, 
	/// возвращаясь назад вызывает
	/// InsertFixLeft() для выхода из левого узла и 
	/// InsertFixRight() для правого, для корретировки цвета.
	/// </summary>
	/// <param name="node">
	/// корень поддерева от куда будет 
	/// осуществляться вставка.</param>
	/// <param name="key">ключ вставляемого узла</param>
	/// <returns>
	/// корень сбалансированного поддерева
	/// </returns>
	RBTreeNode* Insert(RBTreeNode* node, int key);

	/// <summary>
	/// Функция рекурсивно удаляет любой красный узел 
	/// или черный узел с одним ребёнком в заданном поддереве
	/// </summary>
	/// <param name="node">
	/// корень поддерева с 
	/// которого будет осуществляется поиск узла с заданным ключом
	/// </param>
	/// <param name="key">ключ удаляемого узла</param>
	/// <param name="isBalanced">
	/// если дерево будет сбалансированно установит этот флаг
	/// </param>
	/// <returns>
	/// корень сбалансированного поддерева или нулевой указатель
	/// </returns>
	RBTreeNode* Delete(RBTreeNode* node, int key, bool& isBalanced);

	/// <summary>
	/// Функция вызывается во время выхода 
	/// из рекурсии для каждого узла в обратном порядке
	/// Исправляет случаи когда удаляемый узел черный, 
	/// вызывается только когда баланс уже нарушен
	/// </summary>
	/// <param name="node">текущий узел рекурсии в удалении</param>
	/// <param name="isBalanced">
	/// установит флаг если после её вызова баланс удалось исправить
	/// </param>
	/// <returns>
	/// новый корень слабансированного или нет поддерева
	/// </returns>
	RBTreeNode* DeleteFix(RBTreeNode* node,
		bool direction,
		bool& isBalanced);

	/// <summary>
	/// Функция рекурсивно ищет узел с заданным 
	/// ключом в заданном корне поддерева.
	/// </summary>
	/// <param name="node">корень поддерева.</param>
	/// <param name="key">
	/// ключ по которому осуществяется поиск элемента
	/// </param>
	/// <returns>
	/// искомый элемент или nullptr, если не найден элемент
	/// </returns>
	RBTreeNode* Find(RBTreeNode* node, int key);

	/// <summary>
	/// Функция вызывается во время выхода 
	/// из рекурсии для каждого узла в обратном порядке
	/// Исправляет два красных узла, идущих подряд
	/// </summary>
	/// <param name="node">текущий узел рекурсии в добавлении</param>
	/// <returns>
	/// новый корень сбалансированного поддерева левого ребёнка
	/// </returns>
	RBTreeNode* InsertFix(RBTreeNode* node, bool direction);

	/// <summary>
	/// Функция изменения цвета корня заданного узла
	///  и его детей на противоположный
	/// </summary>
	void FlipColor(RBTreeNode* node);

	/// <summary>
	/// Функция левого/правого поворот 
	/// вокруг заданного узла в заданном направлении. 
	/// Его левое/правое поддерево поднимается вверх, 
	/// заменяя свой левый/правый дочерний узел
	/// на заданный, а правый/левый дочерний узел
	/// заданного узла на раннее заменённый.
	/// </summary>
	/// <param name="node">
	/// узел, вокруг которого 
	/// нужно выполнить поворот</param>
	/// <param name="direction">
	/// направление поворота: 
	/// 0 - влево, 1 - вправо</param>
	/// <returns>
	/// новый корень поддерева
	/// </returns>
	RBTreeNode* Rotate(RBTreeNode* node, bool direction);

	/// <summary>
	/// Корень красно-чёрного дерева
	/// </summary>
	RBTreeNode* _root;

	/// <summary>
	/// Количество выполненых поворотов за время существования дерева
	/// </summary>
	int _nodeRotateCount;
};

