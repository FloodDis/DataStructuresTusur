#include "BinaryTree.h"
#include <cstdlib>
#include <iostream>
using namespace std;

BinaryTreeNode* CreationOfBinaryTree(int keyOfRoot, int dataOfRoot)
{
	BinaryTreeNode* rootNode = new BinaryTreeNode;
	rootNode->Key = keyOfRoot;
	rootNode->Data = dataOfRoot;
	return(rootNode);
}

BinaryTreeNode* AddInBinaryTree(BinaryTreeNode* rootNode, int& keyToAdd, int& dataOfNewNode)
{
	if (rootNode == nullptr)
	{
		rootNode = new BinaryTreeNode;

		rootNode->Key = keyToAdd;
		rootNode->Data = dataOfNewNode;
		rootNode->Left = nullptr;
		rootNode->Right = nullptr;
	}
	else if (rootNode->Key > keyToAdd)
	{
		rootNode->Left = AddInBinaryTree(rootNode->Left, keyToAdd, dataOfNewNode);
	}
	else if (rootNode->Key <= keyToAdd)
	{
		rootNode->Right = AddInBinaryTree(rootNode->Right, keyToAdd, dataOfNewNode);
	}

	return rootNode;
}

BinaryTreeNode* DeleteFromBinaryTree(BinaryTreeNode* rootNode, int keyToDelete)
{
	if (rootNode == nullptr)
	{
		return rootNode;
	}

	if (rootNode->Key > keyToDelete)
	{
		rootNode->Left = DeleteFromBinaryTree(rootNode->Left, keyToDelete);
	}
	else if (rootNode->Key < keyToDelete)
	{
		rootNode->Right = DeleteFromBinaryTree(rootNode->Right, keyToDelete);
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
			BinaryTreeNode* pDel = rootNode;
			rootNode = rootNode->Right;
			delete pDel;
			//TODO:
			pDel = nullptr;
		}
		else if (rootNode->Left != nullptr && rootNode->Right == nullptr)
		{
			BinaryTreeNode* pDel = rootNode;
			rootNode = rootNode->Left;
			delete pDel;
			//TODO:
			pDel = nullptr;
		}
		else if (rootNode->Left != nullptr && rootNode->Right != nullptr)
		{
			BinaryTreeNode* min = MinimumBinaryTreeSearch(rootNode->Right);
			rootNode->Key = min->Key;
			rootNode->Data = min->Data;
			rootNode->Right = DeleteFromBinaryTree(rootNode->Right, min->Key);
		}
	}

	return rootNode;
}

BinaryTreeNode* BinaryTreeElementSearch(BinaryTreeNode* rootNode, int searchingKey)
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

BinaryTreeNode* MaximumBinaryTreeSearch(BinaryTreeNode* rootNode)
{
	if (rootNode == nullptr)
	{
		return nullptr;
	}
	while (rootNode->Right != nullptr)
	{
		rootNode = rootNode->Right;
	}
	return rootNode;
}

BinaryTreeNode* MinimumBinaryTreeSearch(BinaryTreeNode* rootNode)
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

void PrintBinaryTree(BinaryTreeNode* rootNode, int tabCount)
{
	if (rootNode != nullptr)
	{
		PrintBinaryTree(rootNode->Right, tabCount + 1);
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
		PrintBinaryTree(rootNode->Left, tabCount + 1);
	}
}

bool IsBinaryTreeEmpty(BinaryTreeNode* rootNode)
{
	if (rootNode == nullptr)
	{
		return true;
	}
	return false;
}

void EnterNumber(string message, int& value)
{
	cout << message;
	cin >> value;
}

void ShowBinaryTree(BinaryTreeNode* rootNode)
{
	cout << "Ваше бинарное дерево поиска:\n";
	PrintBinaryTree(rootNode, 0);
}