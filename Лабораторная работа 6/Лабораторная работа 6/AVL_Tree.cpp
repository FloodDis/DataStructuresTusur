#include "AVL_Tree.h"
#include <iostream>
using namespace std;

AVLTreeNode* CreationOfAVLTree(int keyOfRoot, int dataOfRoot)
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

AVLTreeNode* AddInAVLTree(AVLTreeNode* rootNode, int key, int dataOfNewNode)
{
	if (!rootNode)
	{
		rootNode = CreationOfAVLTree(key, dataOfNewNode);
	}
	else if (rootNode->Key > key)
	{
		rootNode->Left = AddInAVLTree(rootNode->Left, key, dataOfNewNode);
	}
	else if (rootNode->Key < key)
	{
		rootNode->Right = AddInAVLTree(rootNode->Right, key, dataOfNewNode);
	}
	else
	{
		throw "Элемент с таким ключом уже существует!\n";
	}
	return Balance(rootNode);
}

AVLTreeNode* FindMinAVL(AVLTreeNode* rootNode)
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

AVLTreeNode* DeleteFromAVLTree(AVLTreeNode* rootNode, int keyToDelete)
{
	if (rootNode == nullptr)
	{
		throw "Элемент с таким ключом не существует!\n";
	}
	if (rootNode->Key > keyToDelete)
	{
		rootNode->Left = DeleteFromAVLTree(rootNode->Left, keyToDelete);
	}
	else if (rootNode->Key < keyToDelete)
	{
		rootNode->Right = DeleteFromAVLTree(rootNode->Right, keyToDelete);
	}
	else if (rootNode->Key = keyToDelete)
	{
		if (rootNode->Left == nullptr && rootNode->Right == nullptr)
		{
			delete rootNode;
			rootNode = nullptr;
		}
		else if (rootNode->Left == nullptr && rootNode->Right != nullptr)
		{
			AVLTreeNode* pDel = rootNode;
			rootNode = rootNode->Right;
			delete pDel;
			pDel = nullptr;
		}
		else if (rootNode->Left != nullptr && rootNode->Right == nullptr)
		{
			AVLTreeNode* pDel = rootNode;
			rootNode = rootNode->Left;
			delete pDel;
			pDel = nullptr;
		}
		else if (rootNode->Left != nullptr && rootNode->Right != nullptr)
		{
			AVLTreeNode* min = FindMinAVL(rootNode->Right);
			rootNode->Key = min->Key;
			rootNode->Data = min->Data;
			rootNode->Right = DeleteFromAVLTree(rootNode->Right, min->Key);
		}
	}
	return Balance(rootNode);
}

AVLTreeNode* ElementSearchAVL(AVLTreeNode* rootNode, int searchingKey)
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

void PrintAVLTree(AVLTreeNode* rootNode, int tabCount)
{
	if (rootNode != nullptr)
	{
		PrintAVLTree(rootNode->Right, tabCount + 1);
		for (int i = 0; i < tabCount; i++)
		{
			cout << "\t";
		}
		cout << "(" << rootNode->Key << "; " << rootNode->Data << ")";
		if (rootNode->Left != nullptr && rootNode->Right != nullptr)
		{
			cout << "|\n";
		}
		if (rootNode->Left == nullptr && rootNode->Right != nullptr)
		{
			cout << "/\n";
		}
		if (rootNode->Left != nullptr && rootNode->Right == nullptr)
		{
			cout << "\\\n";
		}
		if (rootNode->Left == nullptr && rootNode->Right == nullptr)
		{
			cout << "\n";
		}
		PrintAVLTree(rootNode->Left, tabCount + 1);
	}
}