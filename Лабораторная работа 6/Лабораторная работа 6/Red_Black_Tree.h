#pragma once
#include <iostream>
using namespace std;

enum Child
{
	Left,
	Right
};

struct RBTreeNode
{
	/// <summary>
	/// ���� ����
	/// </summary>
	int Key;

	/// <summary>
	/// true ���� ���� ������ � false ���� ���� �������.
	/// </summary>
	bool IsBlack;

	/// <summary>
	/// ��������� �� �������� ���� 0 - �����, 1 - ������.
	/// </summary>
	RBTreeNode* Child[2];
};

class RBTree
{
public:
	RBTree();
	~RBTree();

	/// <summary>
	/// ������ ���� � ������-������ ������ � �������� ������.
	/// </summary>
	/// <param name="key">
	/// ���� ���������� ����
	/// </param>
	void Insert(int key);

	/// <summary>
	/// ������� ����� ������� ���� ��� ������ ���� � ����� ������� �� ������-������� ������
	/// </summary>
	/// <param name="key">
	/// ���� ���������� ����
	/// </param>
	void Delete(int key);

	/// <summary>
	/// ������� ������ ��������
	/// </summary>
	/// <param name="key">���� �������� ��������</param>
	/// <returns>
	/// ������� ������� ��� nullptr, ���� ������� �� ������
	/// </returns>
	RBTreeNode* Find(int key);

	/// <summary>
	/// ������� ��������� �����
	/// </summary>
	/// <returns>
	/// ����, ���������� ������ ��� nil (��������� ����)
	/// </returns>
	RBTreeNode* GetRoot()
	{
		return _root;
	}

	/// <summary>
	/// ������� ��������� ���������� ����������� ��������� 
	/// </summary>
	///<returns>
	/// ���-�� ���������
	/// </returns>
	int GetNodeRotateCount()
	{
		return _nodeRotateCount;
	}

	/// <summary>
	/// ������� ������ ���-������ �� �����
	/// </summary>
	/// <param name="rootNode">������ ������</param>
	/// <param name="tabCount">���������� ���������</param>
	void PrintRBTree(RBTreeNode* rootNode, int tabCount);

	/// <summary>
	/// ���������� ���������� ���������� ������� ��� ����� �� ����
	/// </summary>
	void ResetNodeRotateCount()
	{
		_nodeRotateCount = 0;
	}

private:
	/// <summary>
	/// ������� �������� ������� �� �������� ����
	/// </summary>
	/// <returns>true ���� ���� ������� � �� ����� nullptr, ����� false</returns>
	bool IsRed(RBTreeNode* node);

	/// <summary>
	/// ������� ���������� ������ ���� � �������� ������ � �������� ���������, ����������� ����� ��������
	/// InsertFixLeft() ��� ������ �� ������ ���� � InsertFixRight() ��� �������, ��� ������������ �����.
	/// </summary>
	/// <param name="node">������ ��������� �� ���� ����� �������������� �������.</param>
	/// <param name="key">���� ������������ ����</param>
	/// <returns>
	/// ������ ����������������� ���������
	/// </returns>
	RBTreeNode* Insert(RBTreeNode* node, int key);

	/// <summary>
	/// ������� ���������� ������� ����� ������� ���� ��� ������ ���� � ����� ������� � �������� ���������
	/// </summary>
	/// <param name="node">������ ��������� � �������� ����� �������������� ����� ���� � �������� ������</param>
	/// <param name="key">���� ���������� ����</param>
	/// <param name="isBalanced">���� ������ ����� ��������������� ��������� ���� ����</param>
	/// <returns>
	/// ������ ����������������� ��������� ��� ������� ���������
	/// </returns>
	RBTreeNode* Delete(RBTreeNode* node, int key, bool& isBalanced);

	/// <summary>
	/// ������� ���������� �� ����� ������ �� �������� ��� ������� ���� � �������� �������
	/// ���������� ������ ����� ��������� ���� ������, ���������� ������ ����� ������ ��� �������
	/// </summary>
	/// <param name="node">������� ���� �������� � ��������</param>
	/// <param name="isBalanced">��������� ���� ���� ����� � ������ ������ ������� ���������</param>
	/// <returns>
	/// ����� ������ ����������������� ��� ��� ���������
	/// </returns>
	RBTreeNode* DeleteFix(RBTreeNode* node, bool direction, bool& isBalanced);

	/// <summary>
	/// ������� ���������� ���� ���� � �������� ������ � �������� ����� ���������.
	/// </summary>
	/// <param name="node">������ ���������.</param>
	/// <param name="key">���� �� �������� ������������� ����� ��������</param>
	/// <returns>
	/// ������ ������� ��� nullptr, ���� �� ������ �������
	/// </returns>
	RBTreeNode* Find(RBTreeNode* node, int key);

	/// <summary>
	/// ������� ���������� �� ����� ������ �� �������� ��� ������� ���� � �������� �������
	/// ���������� ��� ������� ����, ������ ������
	/// </summary>
	/// <param name="node">������� ���� �������� � ����������</param>
	/// <returns>����� ������ ����������������� ��������� ������ ������</returns>
	RBTreeNode* InsertFix(RBTreeNode* node, bool direction);

	/// <summary>
	/// ������� ��������� ����� ����� ��������� ���� � ��� ����� �� ���������������
	/// </summary>
	void FlipColor(RBTreeNode* node);

	/// <summary>
	/// ������� ������/������� ������� ������ ��������� ���� � �������� �����������. ��� �����/������ ��������� ����������� �����, ������� ���� �����/������ �������� ����
	/// �� ��������, � ������/����� �������� ���� ��������� ���� �� ������ ���������.
	/// </summary>
	/// <param name="node">����, ������ �������� ����� ��������� �������</param>
	/// <param name="direction">����������� ��������: 0 - �����, 1 - ������</param>
	/// <returns>
	/// ����� ������ ���������
	/// </returns>
	RBTreeNode* Rotate(RBTreeNode* node, bool direction);

	/// <summary>
	/// ������ ������-������� ������
	/// </summary>
	RBTreeNode* _root;

	/// <summary>
	/// ���������� ���������� ��������� �� ����� ������������� ������
	/// </summary>
	int _nodeRotateCount;
};

