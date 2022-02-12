#include "Red_Black_Tree.h"

RBTree::RBTree()
{
	_root = nullptr;
	_nodeRotateCount = 0;
}

RBTree::~RBTree()
{
	while (_root != nullptr)
	{
		bool isBalanced = false;
		_root = Delete(_root, _root->Key, isBalanced);
	}
}

void RBTree::Insert(int key)
{
	_root = Insert(_root, key);
	_root->IsBlack = true;
}

void RBTree::Delete(int key)
{
	bool isBalanced = false;
	_root = Delete(_root, key, isBalanced);
	if (_root != nullptr)
	{
		_root->IsBlack = true;
	}
}

RBTreeNode* RBTree::Find(int key)
{
	return Find(_root, key);
}

RBTreeNode* RBTree::Delete(RBTreeNode* node, int key, bool& isBalanced)
{
	if (!node)
	{
		throw "Элемента с таким ключом не существует!";
	}

	if (node->Key == key)
	{
		if (node->Child[Left] == nullptr || node->Child[Right] == nullptr)
		{
			RBTreeNode* singleChild = nullptr;
			if (node->Child[Left])
			{
				singleChild = node->Child[Left];
			}
			if (node->Child[Right])
			{
				singleChild = node->Child[Right];
			}

			if (IsRed(node))
			{
				delete node;
				isBalanced = true;
			}

			else if (IsRed(singleChild))
			{
				singleChild->IsBlack = true;
				delete node;
				isBalanced = true;
			}
			else
			{
				delete node;
			}

			return singleChild;
		}
		else
		{

			RBTreeNode* maximum = node->Child[Left];
			while (maximum->Child[Right] != nullptr)
			{
				maximum = maximum->Child[Right];
			}
			node->Key = maximum->Key;
			key = maximum->Key;
		}
	}

	bool direction = key > node->Key;

	node->Child[direction] = Delete(node->Child[direction], key, isBalanced);

	if (isBalanced)
	{
		return node;
	}
	else
	{
		return DeleteFix(node, direction, isBalanced);
	}
}

RBTreeNode* RBTree::DeleteFix(RBTreeNode* node, bool direction, bool& isBalanced)
{
	RBTreeNode* parent = node;
	RBTreeNode* sibling = node->Child[!direction];
	if (IsRed(sibling))
	{
		node = Rotate(node, direction);
		sibling = parent->Child[!direction];
	}

	if (sibling)
	{

		if (!IsRed(sibling->Child[Left]) && !IsRed(sibling->Child[Right]))
		{
			if (IsRed(parent))
			{
				isBalanced = true;
			}
			parent->IsBlack = true;
			sibling->IsBlack = false;
		}

		else
		{
			bool parentColor = parent->IsBlack;
			bool isSiblingRed = !(node == parent);
			if (IsRed(sibling->Child[!direction]))
			{
				parent = Rotate(parent, direction);
			}
			else
			{
				parent->Child[!direction] = Rotate(parent->Child[!direction], !direction);
				parent = Rotate(parent, direction);
			}

			parent->IsBlack = parentColor;
			parent->Child[Left]->IsBlack = true;
			parent->Child[Right]->IsBlack = true;

			if (isSiblingRed)
			{
				node->Child[direction] = parent;
			}
			else
			{
				node = parent;
			}

			isBalanced = true;
		}
	}

	return node;
}

RBTreeNode* RBTree::Find(RBTreeNode* node, int key)
{
	if (node == nullptr)
	{
		return nullptr;
	}

	if (key < node->Key)
	{
		return Find(node->Child[Left], key);
	}
	else if (key > node->Key)
	{
		return Find(node->Child[Right], key);
	}
	else
	{
		return node;
	}
}

RBTreeNode* RBTree::InsertFix(RBTreeNode* node, bool direction)
{
	if (IsRed(node->Child[direction]))
	{
		if (IsRed(node->Child[!direction]))
		{
			if (IsRed(node->Child[direction]->Child[direction]) || IsRed(node->Child[direction]->Child[!direction]))
			{
				FlipColor(node);
			}
		}
		else
		{
			if (IsRed(node->Child[direction]->Child[direction]))
			{
				node = Rotate(node, !direction);
			}
			else if (IsRed(node->Child[direction]->Child[!direction]))
			{
				node->Child[direction] = Rotate(node->Child[direction], direction);
				node = Rotate(node, !direction);
			}
		}
	}
	return node;
}

void RBTree::FlipColor(RBTreeNode* node)
{
	node->IsBlack = !node->IsBlack;
	node->Child[Left]->IsBlack = !node->Child[Left]->IsBlack;
	node->Child[Right]->IsBlack = !node->Child[Right]->IsBlack;
}

RBTreeNode* RBTree::Rotate(RBTreeNode* node, bool direction)
{
	RBTreeNode* newRoot = node->Child[!direction];
	node->Child[!direction] = newRoot->Child[direction];
	newRoot->Child[direction] = node;

	newRoot->IsBlack = node->IsBlack;
	node->IsBlack = false;

	_nodeRotateCount += 1;

	return newRoot;
}

bool RBTree::IsRed(RBTreeNode* node)
{
	if (node == nullptr)
	{
		return false;
	}

	return !node->IsBlack;
}

RBTreeNode* RBTree::Insert(RBTreeNode* node, int key)
{
	if (!node)
	{
		return new RBTreeNode{ key, false, nullptr, nullptr };
	}

	if (key == node->Key)
	{
		throw "Элемент с таким ключом уже существует!";
	}

	bool direction = key > node->Key;

	node->Child[direction] = Insert(node->Child[direction], key);

	return InsertFix(node, direction);
}

void RBTree::PrintRBTree(RBTreeNode* rootNode, int tabCount)
{
	if (rootNode != nullptr)
	{
		PrintRBTree(rootNode->Child[Right], tabCount + 1);
		for (int i = 0; i < tabCount; i++)
		{
			cout << "\t";
		}
		cout << "(" << rootNode->Key << "; ";
		if (rootNode->IsBlack)
		{
			cout << "Black)";
		}
		else
		{
			cout << "Red)";
		}
		if (rootNode->Child[Left] != nullptr && rootNode->Child[Right] != nullptr)
		{
			cout << "|\n";
		}
		if (rootNode->Child[Left] == nullptr && rootNode->Child[Right] != nullptr)
		{
			cout << "/\n";
		}
		if (rootNode->Child[Left] != nullptr && rootNode->Child[Right] == nullptr)
		{
			cout << "\\\n";
		}
		if (rootNode->Child[Left] == nullptr && rootNode->Child[Right] == nullptr)
		{
			cout << "\n";
		}
		PrintRBTree(rootNode->Child[Left], tabCount + 1);
	}
}