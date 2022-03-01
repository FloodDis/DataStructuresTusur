#pragma once
#include <iostream>
using namespace std;

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
	/// Высота поддерева
	/// </summary>
	int SubTreeHeight;
};
/*
/// <summary>
/// АВЛ-дерево
/// </summary>
struct AVLTree
{
	/// <summary>
	/// Корень АВЛ-дерева
	/// </summary>
	AVLTreeNode* Root;

	/// <summary>
	/// Кол-во поворотов
	/// </summary>
	int NodeRotateCount;
};*/

/// <summary>
/// АВЛ-дерево
/// </summary>
class AVLTree
{
public:
	/// <summary>
	/// Конструктор класса
	/// </summary>
	AVLTree();

	/// <summary>
	/// Деструктор класса
	/// </summary>
	~AVLTree();

	/// <summary>
	/// Создаёт узел в АВЛ дереве с заданным ключём.
	/// </summary>
	/// <param name="key">
	/// ключ, созданного узла.
	/// </param>
	void Insert(int key);

	/// <summary>
	/// Удаляет элемент из АВЛ дерева с заданным ключём.
	/// </summary>
	/// <param name="key">
	/// значения ключа
	/// </param>
	void Delete(int key);

	/// <summary>
	/// Возвращает элемент АВЛ дерева с заданным ключём, 
	/// если элемент с заданным ключём не найден, то nullptr.
	/// </summary>
	/// <param name="key">
	/// ключ по которому осуществяется поиск элемента.
	/// </param>
	/// <returns>
	/// Элемент или nullptr если элемент не найден.
	/// </returns>
	AVLTreeNode* Find(int key);

	/// <summary>
	/// Возвращает корень АВЛ дерева или nullptr.
	/// </summary>
	/// <returns>
	/// Узел, являющийся корнем или nullptr.
	/// </returns>
	AVLTreeNode* GetRoot();

	/// <summary>
	/// Возвращает количество выполненых поворотов 
	/// над узлами за время существаоания дерева.
	/// </summary>
	int GetNodeRotateCount()
	{
		return _nodeRotateCount;
	}

	/// <summary>
	/// Сбрасывает количество выполненых поворот над узлам до нуля.
	/// </summary>
	void ResetNodeRotateCount()
	{
		_nodeRotateCount = 0;
	}

private:

	/// <summary>
	/// Рекурсивно создаёт узел с заданным ключём 
	/// в заданном поддереве, возвращаясь назад вызывает
	/// BalanceNode() для каждого узла, 
	/// что не допускает возникновения дизбаланса в заданном поддереве.
	/// </summary>
	/// <param name="node">
	/// корень поддерева от куда будет осуществляться вставка.
	/// </param>
	/// <param name="key">
	/// ключ, созданного узла.
	/// </param>
	/// <returns>
	/// корень, сбалансированного поддерева.
	/// </returns>
	AVLTreeNode* Insert(AVLTreeNode* node, int key);

	/// <summary>
	/// Рекурсивно удаляет узел с заданным ключём 
	/// в заданном поддереве, возвращаясь назад вызывает
	/// BalanceNode() для каждого узла, что не допускает 
	/// возникновения дизбаланса в заданном поддереве.
	/// </summary>
	/// <param name="node">корень поддерева,
	///  с которого будет осуществляется поиск кзла с заданным ключём.</param>
	/// <param name="key">ключ, удаляемого узла</param>
	/// <returns>
	/// корень, сбалансированного поддерева или нулевой указатель.
	/// </returns>
	AVLTreeNode* Delete(AVLTreeNode* node, int key);

	/// <summary>
	/// Рекурсивно ищет узел с заданным ключём в заданном корне поддерева.
	/// </summary>
	/// <param name="node">корень поддерева.</param>
	/// <param name="key">
	/// ключ по которому осуществяется поиск элемента.</param>
	/// <returns>
	/// Элемент или nullptr если не найден элемент.
	/// </returns>
	AVLTreeNode* Find(AVLTreeNode* node, int key);

	/// <summary>
	/// Рекурсивный поиск минимального узла в заданном поддереве.
	/// </summary>
	/// <param name="node">узел, в котором осуществляется поиск.</param>
	/// <returns>
	/// Минимальный узел в заданном поддереве.
	/// </returns>
	AVLTreeNode* FindMin(AVLTreeNode* node);

	/// <summary>
	/// Рекурсивно удаляет минимальный узел 
	/// из заданного поддерева, возвращаясь назад вызывает
	/// BalanceNode() для каждого узла, 
	/// что не допускает возникновения дизбаланса в заданном поддереве.
	/// </summary>
	/// <param name="node">узел, 
	/// с которого осуществляется поиск и дальнейшее удаление.</param>
	/// <returns>
	/// Новый корень полученного поддерева, может быть nullptr.
	/// </returns>
	AVLTreeNode* DeleteMin(AVLTreeNode* node);

	/// <summary>
	/// Правый поворот вокруг заданного узла.
	/// </summary>
	/// <param name="node">узел, 
	/// вокруг которого нужно выполнить поворот.</param>
	/// <returns>
	/// Новый корень полученного поддерева.
	/// </returns>
	AVLTreeNode* RotateRight(AVLTreeNode* node);

	/// <summary>
	/// Левый поворот вокруг заданного узла.
	/// </summary>
	/// <param name="node">узел, 
	/// вокруг которого нужно выполнить поворот.</param>
	/// <returns>
	/// Новый корень полученного поддерева.
	/// </returns>
	AVLTreeNode* RotateLeft(AVLTreeNode* node);

	/// <summary>
	/// Исправляет дизбаланс заданного узла, 
	/// выполняя двойной или одинарный поворот.
	/// </summary>
	/// <param name="node">узел, дизбаланс которого надо испарвить.</param>
	/// <returns>
	/// Новый корень исправленного узла.
	/// </returns>
	AVLTreeNode* BalanceNode(AVLTreeNode* node);

	/// <summary>
	/// Вычисляет высоту заданного узла.
	/// </summary>
	/// <param name="node">узел, высоту которого надо найти.</param>
	/// <returns>
	/// Высота узла или -1 если node == nullptr.
	/// </returns>
	short int GetHeight(AVLTreeNode* node);

	/// <summary>
	/// Вычисляет разницу высот правого и левого поддерева заданного узла.
	/// </summary>
	/// <param name="node">
	/// узел, разницу высоты поддеревьев которого надо вычислить.</param>
	/// <returns>
	/// Вернёт положительное число, 
	/// если высота правого поддерева больше левого.	
	/// Верёт 0, если высоты поддеревьев равны. Иначе отрицательное.
	/// </returns>
	short int GetBalanceFactor(AVLTreeNode* node);

	/// <summary>
	/// Корректирует высоту заданного узла 
	/// (при условии, что высоты его поддеревьев верны).
	/// </summary>
	/// <param name="node">
	/// узел, высоту которого надо скоректировать.
	/// </param>
	void UpdateHeight(AVLTreeNode* node);

	/// <summary>
	/// Корень АВЛ дерева.
	/// </summary>
	AVLTreeNode* _root;

	/// <summary>
	/// Количество выполненых поворотов за время существования дерева.
	/// </summary>
	int _nodeRotateCount;
};

/*
/// <summary>
/// Функция создания узла АВЛ-дерева
/// </summary>
/// <param name="keyOfRoot">ключ создаваемого узла</param>
/// <param name="dataOfRoot">данные создаваемого узла</param>
/// <returns>
/// созданный узел
/// </returns>
AVLTreeNode* CreateTree(int keyOfRoot, int dataOfRoot);

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
AVLTreeNode* RotateLeft(AVLTreeNode* nodeToRotate);

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
/// <param name="key">ключ добавляемого элемента</param>
/// <param name="dataOfNewNode">данные добавляемого элемента</param>
/// <returns>
/// новый корень дерева
/// </returns>
AVLTreeNode* Insert(AVLTreeNode* rootNode,
	int key,
	int dataOfNewNode);

/// <summary>
/// Функция поиска минимального элемента
/// </summary>
/// <param name="rootNode">корень дерева или поддерева</param>
/// <returns>
/// минимальный элемент АВЛ-дерева
/// </returns>
AVLTreeNode* FindMin(AVLTreeNode* rootNode);

/// <summary>
/// Функция удаления элемента из АВЛ-дерева
/// </summary>
/// <param name="rootNode">корень дерева</param>
/// <param name="keyToDelete">ключ удаляемого элемента</param>
/// <returns>
/// узел сбалансированного АВЛ-дерева
/// </returns>
AVLTreeNode* Delete(AVLTreeNode* rootNode, int keyToDelete);

/// <summary>
/// Функция поиска элемента в АВЛ-дереве
/// </summary>
/// <param name="rootNode">корень дерева</param>
/// <param name="searchingKey">ключ искомого элемента</param>
/// <returns>
/// искомый узел
/// </returns>
AVLTreeNode* Find(AVLTreeNode* rootNode, int searchingKey);*/