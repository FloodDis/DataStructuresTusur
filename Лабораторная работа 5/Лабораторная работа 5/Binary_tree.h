#pragma once

/// <summary>
/// ���� ��������� ������
/// </summary>
struct BinaryTreeNode
{
	/// <summary>
	/// ��������� �� ����� �������� ����
	/// </summary>
	BinaryTreeNode* Left = nullptr;

	/// <summary>
	/// ��������� �� ������ �������� ����
	/// </summary>
	BinaryTreeNode* Right = nullptr;

	/// <summary>
	/// ���� ����
	/// </summary>
	int Key;

	/// <summary>
	/// ������ ����
	/// </summary>
	int Data;
};

/// <summary>
/// �������� ��������� ������
/// </summary>
/// <param name="keyOfRoot">���� �����</param>
/// <param name="dataOfRoot">������ �����</param>
/// <returns>��������� �� ������ ��������� ������</returns>
BinaryTreeNode* CreationOfBinaryTree(int keyOfRoot, int dataOfRoot);

/// <summary>
/// ������� ���������� �������� � �������� ������
/// </summary>
/// <param name="rootNode">��������� �� ������ ��������� ������</param>
/// <param name="keyToDelete">���� ������������ ��������</param>
/// <param name="dataOfNewNode">������ ������������ ��������</param>
/// <returns>��������� �� ����� ������ ��������� ������</returns>
BinaryTreeNode* AddInBinaryTree(BinaryTreeNode* rootNode, int& keyToDelete, int& dataOfNewNode);

/// <summary>
/// ������� �������� �������� �� ��������� ������
/// </summary>
/// <param name="rootNode">��������� �� ������ ��������� ������</param>
/// <param name="keyToDelete">���� ���������� ��������</param>
/// <returns>��������� �� ����� ������ ��������� ������</returns>
BinaryTreeNode* DeleteFromBinaryTree(BinaryTreeNode* rootNode, int keyToDelete);

/// <summary>
/// ������� ������ �������� � �������� ������
/// </summary>
/// <param name="rootNode">��������� �� ������ ��������� ������</param>
/// <param name="searchingKey">���� �������� ��������</param>
/// <returns>��������� �� ���� �������� ��������</returns>
BinaryTreeNode* BinaryTreeElementSearch(BinaryTreeNode* rootNode, int searchingKey);

/// <summary>
/// ������� ������ ������������� ��������
/// </summary>
/// <param name="rootNode">��������� �� ������ ��������� ������</param>
/// <returns>��������� �� ���� �������� ��������</returns>
BinaryTreeNode* MaximumBinaryTreeSearch(BinaryTreeNode* rootNode);

/// <summary>
/// ������� ������ ������������ ��������
/// </summary>
/// <param name="rootNode">��������� �� ������ ��������� ������</param>
/// <returns>��������� �� ���� �������� ��������</returns>
BinaryTreeNode* MinimumBinaryTreeSearch(BinaryTreeNode* rootNode);

/// <summary>
/// ������� ������ ��������� ������ �� �����
/// </summary>
/// <param name="rootNode">��������� �� ������ ��������� ������</param>
/// <param name="tabCount">����� ���������� ���� ��������� ������</param>
void PrintBinaryTree(BinaryTreeNode* rootNode, int tabCount);

/// <summary>
/// ������� �������� ��������� ������ �� �������
/// </summary>
/// <param name="rootNode">��������� �� ������ ��������� ������</param>
bool IsBinaryTreeEmpty(BinaryTreeNode* rootNode);

/// <summary>
/// ������� ������ ��������� � ����� �����
/// </summary>
/// <param name="message">������, ������� ����� �������</param>
/// <param name="value">����������, ������� ������������� ����� �����</param>
void EnterNumber(string message, int& value);