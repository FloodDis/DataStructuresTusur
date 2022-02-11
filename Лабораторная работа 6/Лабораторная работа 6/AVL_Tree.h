#pragma once

/// <summary>
/// ���� ���-������
/// </summary>
struct AVLTreeNode
{
	/// <summary>
	/// ��������� �� ����� �������� ����
	/// </summary>
	AVLTreeNode* Left = nullptr;

	/// <summary>
	/// ��������� �� ������ ����
	/// </summary>
	AVLTreeNode* Right = nullptr;

	/// <summary>
	/// ���� ����
	/// </summary>
	int Key;

	/// <summary>
	/// ������ ����
	/// </summary>
	int Data;

	/// <summary>
	/// ������ ���������
	/// </summary>
	int SubTreeHeight;
};

/// <summary>
/// ������� �������� ���� ���-������
/// </summary>
/// <param name="keyOfRoot">���� ������������ ����</param>
/// <param name="dataOfRoot">������ ������������ ����</param>
/// <returns>
/// ��������� ����
/// </returns>
AVLTreeNode* CreationOfAVLTree(int keyOfRoot, int dataOfRoot);

/// <summary>
/// ������� ��������� ������ ���������
/// </summary>
/// <param name="node">������ ���������</param>
/// <returns>
///  ������ ���������
/// </returns>
int GetHeight(AVLTreeNode* node);

/// <summary>
/// ������� ���������� ������� ����� �����������
/// </summary>
/// <param name="node">������ ������</param>
/// <returns>
/// ������� ����� �����������
/// </returns>
int BalanceFactor(AVLTreeNode* node);

/// <summary>
/// ������� ����������� ������ ������
/// </summary>
/// <param name="node">������ ������</param>
void FixHeight(AVLTreeNode* node);

/// <summary>
/// ������� ������� ��������
/// </summary>
/// <param name="pNode">����, ������ �������� ������������ �������</param>
/// <returns>
/// ����� ������ ���������
/// </returns>
AVLTreeNode* RotateRight(AVLTreeNode* pNode);

/// <summary>
/// ������� ������ ��������
/// </summary>
/// <param name="qNode">����, ������ �������� ������������ �������</param>
/// <returns>
/// ����� ������ ���������
/// </returns>
AVLTreeNode* RotateLeft(AVLTreeNode* qNode);

/// <summary>
/// ������� ������������ ���������
/// </summary>
/// <param name="node">������������� ����</param>
/// <returns>
/// ����� ������ ����������������� ���������
/// </returns>
AVLTreeNode* Balance(AVLTreeNode* node);

/// <summary>
/// ������� ���������� �������� � ���-������
/// </summary>
/// <param name="rootNode">������ ������</param>
/// <param name="keyToAdd">���� ������������ ��������</param>
/// <param name="dataOfNewNode">������ ������������ ��������</param>
/// <returns>
/// ����� ������ ������
/// </returns>
AVLTreeNode* AddInAVLTree(AVLTreeNode* rootNode, int keyToAdd, int dataOfNewNode);

/// <summary>
/// ������� ������ ������������ ��������
/// </summary>
/// <param name="rootNode">������ ������ ��� ���������</param>
/// <returns>
/// ����������� ������� ���-������
/// </returns>
AVLTreeNode* FindMinAVL(AVLTreeNode* rootNode);

/// <summary>
/// ������� �������� �������� �� ���-������
/// </summary>
/// <param name="rootNode">������ ������</param>
/// <param name="keyToDelete">���� ���������� ��������</param>
/// <returns>
/// ���� ����������������� ���-������
/// </returns>
AVLTreeNode* DeleteFromAVLTree(AVLTreeNode* rootNode, int keyToDelete);

/// <summary>
/// ������� ������ �������� � ���-������
/// </summary>
/// <param name="rootNode">������ ������</param>
/// <param name="searchingKey">���� �������� ��������</param>
/// <returns>
/// ������� ����
/// </returns>
AVLTreeNode* ElementSearchAVL(AVLTreeNode* rootNode, int searchingKey);

/// <summary>
/// ������� ������ ���-������ �� �����
/// </summary>
/// <param name="rootNode">������ ������</param>
/// <param name="tabCount">���������� ���������</param>
void PrintAVLTree(AVLTreeNode* rootNode, int tabCount);

