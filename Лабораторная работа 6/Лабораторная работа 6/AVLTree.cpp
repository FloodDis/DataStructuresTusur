#include "AVLTree.h"
#include <iostream>
using namespace std;

AVLTreeNode* CreateTree(int keyOfRoot, int dataOfRoot)
{
	AVLTreeNode* rootNode = new AVLTreeNode;
	rootNode->Key = keyOfRoot;
	rootNode->Data = dataOfRoot;
	rootNode->SubTreeHeight = 0;
	return (rootNode);
}

int GetHeight(AVLTreeNode* node)
{
	if (node != nullptr)
	{
		return node->SubTreeHeight;
	}
	return -1;
}

int BalanceFactor(AVLTreeNode* node)
{
	return GetHeight(node->Right) - GetHeight(node->Left);
}

void FixHeight(AVLTreeNode* node)
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

AVLTreeNode* RotateRight(AVLTreeNode* nodeToRotate)
{
	AVLTreeNode* bufferNode = nodeToRotate->Left;
	nodeToRotate->Left = bufferNode->Right;
	bufferNode->Right = nodeToRotate;
	FixHeight(nodeToRotate);
	FixHeight(bufferNode);
	return (bufferNode);
}

AVLTreeNode* RotateLeft(AVLTreeNode* nodeToRotate)
{
	AVLTreeNode* bufferNode = nodeToRotate->Right;
	nodeToRotate->Right = bufferNode->Left;
	bufferNode->Left = nodeToRotate;
	FixHeight(bufferNode);
	FixHeight(nodeToRotate);
	return (bufferNode);
}

AVLTreeNode* Balance(AVLTreeNode* nodeToBalance)
{
	if (nodeToBalance == nullptr)
	{
		return nullptr;
	}
	FixHeight(nodeToBalance);
	if (BalanceFactor(nodeToBalance) == 2)
	{
		if (BalanceFactor(nodeToBalance->Right) < 0)
		{
			nodeToBalance->Right = RotateRight(nodeToBalance->Right);
		}
		return RotateLeft(nodeToBalance);
	}
	if (BalanceFactor(nodeToBalance) == -2)
	{
		if (BalanceFactor(nodeToBalance->Left) > 0)
		{
			nodeToBalance->Left = RotateLeft(nodeToBalance->Left);
		}
		return RotateRight(nodeToBalance);
	}
	return nodeToBalance;
}

AVLTreeNode* Add(AVLTreeNode* rootNode, 
	int key, 
	int dataOfNewNode)
{
	if (!rootNode)
	{
		rootNode = CreateTree(key, dataOfNewNode);
	}
	else if (rootNode->Key > key)
	{
		rootNode->Left = Add(rootNode->Left, key, dataOfNewNode);
	}
	else if (rootNode->Key < key)
	{
		rootNode->Right = 
			Add(rootNode->Right, key, dataOfNewNode);
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
	if (rootNode != nullptr)
	{
		while (rootNode->Key != searchingKey)
		{
			if (searchingKey > rootNode->Key)
			{
				rootNode = rootNode->Right;
			}
			else
			{
				rootNode = rootNode->Left;
			}
		}
	}
	return rootNode;
}