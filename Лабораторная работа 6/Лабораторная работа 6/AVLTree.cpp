#include "AVLTree.h"
#include <iostream>
using namespace std;

#include "AVLTree.h"

AVLTree::AVLTree() : _root{ nullptr }, _nodeRotateCount{ 0 }
{
}

AVLTree::~AVLTree()
{
	while (_root != nullptr)
	{
		Delete(_root->Key);
	}
}

void AVLTree::Insert(int key)
{
	_root = Insert(_root, key);
}

void AVLTree::Delete(int key)
{
	_root = Delete(_root, key);
}

AVLTreeNode* AVLTree::Find(int key)
{
	return Find(_root, key);
}

AVLTreeNode* AVLTree::Delete(AVLTreeNode* node, int key)
{
	if (node == nullptr)
	{
		throw "Element with that key value didn't exists";
	}


	if (key < node->Key)
	{
		node->Left = Delete(node->Left, key);
	}
	else if (key > node->Key)
	{
		node->Right = Delete(node->Right, key);
	}
	else
	{
		AVLTreeNode* left = node->Left;
		AVLTreeNode* right = node->Right;
		delete node;

		if (right == nullptr)
		{
			return left;
		}
		else
		{
			AVLTreeNode* minimumNode = FindMin(right);
			minimumNode->Right = DeleteMin(right);
			minimumNode->Left = left;
			return BalanceNode(minimumNode);
		}
	}
	return BalanceNode(node);
}

AVLTreeNode* AVLTree::Insert(AVLTreeNode* node, int key)
{
	if (!node)
	{
		return new AVLTreeNode{ nullptr, nullptr, key, 0 };
	}
	else if (key < node->Key)
	{
		node->Left = Insert(node->Left, key);
	}
	else if (key > node->Key)
	{
		node->Right = Insert(node->Right, key);
	}
	else
	{
		throw "Element with that key already exists";
	}
	return BalanceNode(node);
}

AVLTreeNode* AVLTree::Find(AVLTreeNode* node, int key)
{
	if (node == nullptr)
	{
		return nullptr;
	}

	if (key < node->Key)
	{
		return Find(node->Left, key);
	}
	else if (key > node->Key)
	{
		return Find(node->Right, key);
	}
	else
	{
		return node;
	}
}

AVLTreeNode* AVLTree::FindMin(AVLTreeNode* node)
{
	if (node->Left != nullptr)
	{
		return FindMin(node->Left);
	}
	else
	{
		return node;
	}
}

AVLTreeNode* AVLTree::DeleteMin(AVLTreeNode* node)
{
	if (node->Left == nullptr)
	{
		return node->Right;
	}
	else
	{
		node->Left = DeleteMin(node->Left);
		return BalanceNode(node);
	}
}

AVLTreeNode* AVLTree::RotateRight(AVLTreeNode* node)
{
	AVLTreeNode* bufferNode = node->Left;
	node->Left = bufferNode->Right;
	bufferNode->Right = node;
	UpdateHeight(node);
	UpdateHeight(bufferNode);
	return (bufferNode);
}

AVLTreeNode* AVLTree::RotateLeft(AVLTreeNode* node)
{
	AVLTreeNode* bufferNode = node->Right;
	node->Right = bufferNode->Left;
	bufferNode->Left = node;
	UpdateHeight(bufferNode);
	UpdateHeight(node);
	return (bufferNode);
}

/*
AVLTreeNode* AVLTree::Rotate(AVLTreeNode* node, bool direction)
{
	AVLTreeNode* newRoot = node->Child[!direction];
	node->Child[!direction] = newRoot->Child[direction];
	newRoot->Child[direction] = node;

	UpdateHeight(node);
	UpdateHeight(newRoot);

	_nodeRotateCount += 1;

	return newRoot;
}*/

AVLTreeNode* AVLTree::BalanceNode(AVLTreeNode* node)
{
	if (node == nullptr)
	{
		return nullptr;
	}
	UpdateHeight(node);
	if (GetBalanceFactor(node) == 2)
	{
		if (GetBalanceFactor(node->Right) < 0)
		{
			node->Right = RotateRight(node->Right);
		}
		return RotateLeft(node);
	}
	if (GetBalanceFactor(node) == -2)
	{
		if (GetBalanceFactor(node->Left) > 0)
		{
			node->Left = RotateLeft(node->Left);
		}
		return RotateRight(node);
	}
	return node;
}

short int AVLTree::GetHeight(AVLTreeNode* node)
{
	if (node != nullptr)
	{
		return node->SubTreeHeight;
	}
	return -1;
}

short int AVLTree::GetBalanceFactor(AVLTreeNode* node)
{
	return GetHeight(node->Right) - GetHeight(node->Left);
}

void AVLTree::UpdateHeight(AVLTreeNode* node)
{
	short int leftHeight = GetHeight(node->Left);
	short int rightHeight = GetHeight(node->Right);

	if (leftHeight < rightHeight)
	{
		node->SubTreeHeight = rightHeight + 1;
	}
	else
	{
		node->SubTreeHeight = leftHeight + 1;
	}
}

AVLTreeNode* AVLTree::GetRoot()
{
	return _root;
}
/*AVLTree::AVLTree(int keyOfRoot, int dataOfRoot)
{
	_root = new AVLTreeNode;
	_root->Key = keyOfRoot;
	_root->Data = dataOfRoot;
	_root->SubTreeHeight = 0;
}

int AVLTree::GetHeight(AVLTreeNode* node)
{
	if (node != nullptr)
	{
		return node->SubTreeHeight;
	}
	return -1;
}

int AVLTree::BalanceFactor(AVLTreeNode* node)
{
	return GetHeight(node->Right) - GetHeight(node->Left);
}

void AVLTree::FixHeight(AVLTreeNode* node)
{
	if (node == nullptr)
	{
		return;
	}
	if (GetHeight(node->Left) > GetHeight(node->Right))
	{
		node->SubTreeHeight = GetHeight(node->Left) + 1;
	}
	else
	{
		node->SubTreeHeight = GetHeight(node->Right) + 1;
	}
}

AVLTreeNode* AVLTree::RotateRight(AVLTreeNode* nodeToRotate)
{
	AVLTreeNode* bufferNode = nodeToRotate->Left;
	nodeToRotate->Left = bufferNode->Right;
	bufferNode->Right = nodeToRotate;
	FixHeight(nodeToRotate);
	FixHeight(bufferNode);
	return (bufferNode);
}

AVLTreeNode* AVLTree::RotateLeft(AVLTreeNode* nodeToRotate)
{
	AVLTreeNode* bufferNode = nodeToRotate->Right;
	nodeToRotate->Right = bufferNode->Left;
	bufferNode->Left = nodeToRotate;
	FixHeight(bufferNode);
	FixHeight(nodeToRotate);
	return (bufferNode);
}

AVLTreeNode* AVLTree::Balance(AVLTreeNode* node)
{
	if (node == nullptr)
	{
		return nullptr;
	}
	FixHeight(node);
	if (BalanceFactor(node) == 2)
	{
		if (BalanceFactor(node->Right) < 0)
		{
			node->Right = RotateRight(node->Right);
		}
		return RotateLeft(node);
	}
	if (BalanceFactor(node) == -2)
	{
		if (BalanceFactor(node->Left) > 0)
		{
			node->Left = RotateLeft(node->Left);
		}
		return RotateRight(node);
	}
	return node;
}

AVLTreeNode* AVLTree::Insert(int key, int dataOfNewNode)
{
	else if (_root->Key > key)
	{
		_root->Left = Insert(key, dataOfNewNode);
	}
	else if (_root->Key < key)
	{
		_root->Right =
			Insert(key, dataOfNewNode);
	}
	else
	{
		throw "Элемент с таким ключом уже существует!\n";
	}
	return Balance(rootNode);
}

AVLTreeNode* FindMin(AVLTreeNode* rootNode)
{
	if (rootNode == nullptr)
	{
		return nullptr;
	}
	while (rootNode->Left != nullptr)
	{
		rootNode = rootNode->Left;
	}
	return rootNode;
}

AVLTreeNode* Delete(AVLTreeNode* rootNode, int keyToDelete)
{
	AVLTreeNode* bufferNode = rootNode;
	if (bufferNode == nullptr)
	{
		throw "Элемент с таким ключом не существует!\n";
	}
	if (bufferNode->Key > keyToDelete)
	{
		bufferNode->Left =
			Delete(bufferNode->Left, keyToDelete);
	}
	else if (bufferNode->Key < keyToDelete)
	{
		bufferNode->Right =
			Delete(bufferNode->Right, keyToDelete);
	}
	else if (bufferNode->Key = keyToDelete)
	{
		if (bufferNode->Left == nullptr && bufferNode->Right == nullptr)
		{
			delete bufferNode;
			bufferNode = nullptr;
		}
		else if (bufferNode->Left == nullptr &&
			bufferNode->Right != nullptr)
		{
			AVLTreeNode* nodeToDelete = bufferNode;
			bufferNode = bufferNode->Right;
			delete nodeToDelete;
			nodeToDelete = nullptr;
		}
		else if (bufferNode->Left != nullptr &&
			bufferNode->Right == nullptr)
		{
			AVLTreeNode* nodeToDelete = bufferNode;
			bufferNode = bufferNode->Left;
			delete nodeToDelete;
			nodeToDelete = nullptr;
		}
		else if (bufferNode->Left != nullptr &&
			bufferNode->Right != nullptr)
		{
			AVLTreeNode* min = FindMin(bufferNode->Right);
			bufferNode->Key = min->Key;
			bufferNode->Data = min->Data;
			bufferNode->Right =
				Delete(bufferNode->Right, min->Key);
		}
	}
	return Balance(bufferNode);
}

AVLTreeNode* Find(AVLTreeNode* rootNode, int searchingKey)
{
	AVLTreeNode* bufferNode = rootNode;
	while (bufferNode != nullptr)
	{
		if (searchingKey == bufferNode->Key)
		{
			return bufferNode;
		}
		else if (searchingKey > bufferNode->Key)
		{
			bufferNode = bufferNode->Right;
		}
		else
		{
			bufferNode = bufferNode->Left;
		}
	}
	return bufferNode;
}*/