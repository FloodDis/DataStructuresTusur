#include "AVLTree.h"
#include <iostream>
using namespace std;

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
	_nodeRotateCount += 1;
	return (bufferNode);
}

AVLTreeNode* AVLTree::RotateLeft(AVLTreeNode* node)
{
	AVLTreeNode* bufferNode = node->Right;
	node->Right = bufferNode->Left;
	bufferNode->Left = node;
	UpdateHeight(node);
	UpdateHeight(bufferNode);
	_nodeRotateCount += 1;
	return (bufferNode);
}

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