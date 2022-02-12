#pragma once

/// <summary>
/// ���� ��������� ������
/// </summary>
struct TreapNode
{
	/// <summary>
	/// ����
	/// </summary>
	int Key;

	/// <summary>
	/// ���������
	/// </summary>
	int Priority;

	/// <summary>
	/// ��������� �� ����� �������� ����
	/// </summary>
	TreapNode* Left = nullptr;

	/// <summary>
	/// ��������� �� ������ �������� ����
	/// </summary>
	TreapNode* Right = nullptr;
};

/// <summary>
/// ��������� ������
/// </summary>
struct Treap
{
	/// <summary>
	/// ��������� �� ������ ��������� ������
	/// </summary>
	TreapNode* Root;
};

/// <summary>
/// ������� �������� ��������� ������
/// </summary>
/// <param name="node">��������� �� ������ ��������� ������</param>
/// <param name="key">����</param>
/// <param name="priority">���������</param>
/// <param name="left">��������� �� ������ ������ ���������</param>
/// <param name="right">��������� �� ������ ������� ���������</param>
/// <returns>��������� �� ������ ��������� ������</returns>
TreapNode* CreationOfTreap(TreapNode* node, int key, int priority, TreapNode* left, TreapNode* right);

/// <summary>
/// ������� ������ �������� � ���������� ������
/// </summary>
/// <param name="node">��������� �� ������ ��������� ������</param>
/// <param name="key">���� �������� ��������</param>
/// <returns>��������� �� ���� �������� ��������</returns>
TreapNode* FindElementInTreap(TreapNode* node, int key);

/// <summary>
/// ������� ���������� ��������
/// </summary>
/// <param name="treapNode">��������� �� ������ ��������� ������</param>
/// <param name="key">���� ��� ����������</param>
/// <param name="left">��������� �� ������ ������ ������</param>
/// <param name="right">��������� �� ������ ������� ������</param>
void Split(TreapNode* treapNode, int key, TreapNode*& left, TreapNode*& right);

/// <summary>
/// ������� ������� ��������
/// </summary>
/// <param name="left">��������� �� ����� ������</param>
/// <param name="right">��������� �� ������ ������</param>
/// <returns>��������� �� ������ ������� ��������� ������</returns>
TreapNode* Merge(TreapNode* left, TreapNode* right);

/// <summary>
/// ������� ���������� �������� � ��������� ������ (����������������)
/// </summary>
/// <param name="treapUnit">��������� �� ��������� ��������� ������</param>
/// <param name="key">���� ������������ ��������</param>
/// <param name="priority">��������� ������������ ��������</param>
void AddInTreapUnoptimised(Treap* treapUnit, int key, int priority);

/// <summary>
/// ������� ���������� �������� � ��������� ������ (��������������)
/// </summary>
/// <param name="treap">��������� �� ��������� ��������� ������</param>
/// <param name="node">��������� �� ������ ��������� ������</param>
/// <param name="parent">��������� �� ������������ ���� ������</param>
/// <param name="key">���� ������������ ��������</param>
/// <param name="priority">��������� ������������ ��������</param>
void AddInTreapOptomised(Treap* treap, TreapNode* node, TreapNode* parent, int key, int priority);

/// <summary>
/// ������� �������� �������� �� ��������� ������ (����������������)
/// </summary>
/// <param name="treap">��������� �� ��������� ��������� ������</param>
/// <param name="key">���� ���������� ��������</param>
void DeleteFromTreapUnoptimised(Treap* treap, int key);

/// <summary>
/// ������� �������� �������� �� ��������� ������ (��������������)
/// </summary>
/// <param name="treap">�������� �� ��������� ��������� ������</param>
/// <param name="node">��������� �� ������ ��������� ������</param>
/// <param name="parent">��������� �� ������������ ���� ������</param>
/// <param name="key">���� ���������� ��������</param>
void DeleteFromTreapOptimised(Treap* treap, TreapNode* node, TreapNode* parent, int key);

/// <summary>
/// ������� ������ ��������� ������ �� �����
/// </summary>
/// <param name="nodeToPrint">��������� �� ������ ������</param>
/// <param name="lndent">���-�� ���������</param>
void PrintTreap(TreapNode* nodeToPrint, int lndent = 0);

/// <summary>
/// ������� �������� ��������� ������ �� �������
/// </summary>
/// <param name="treap">��������� �� ��������� ������</param>
/// <returns>true - ��������� ������ ������, false - ��������� ������ �� ������</returns>
bool IsTreapEmpty(Treap* treap);

/// <summary>
/// ������� �������� ��������� ������
/// </summary>
/// <param name=="node">��������� �� ������ ��������� ������</param>
void DeleteTreap(TreapNode* node);

/// <summary>
/// ������� ������ ��������� � ��������� ������
/// </summary>
/// <param name=="message">���������,��������� �� �����</param>
/// <param name=="nodeToPrint">������ ���������</param>
void ShowTreap(string message, TreapNode* nodeToPrint);

/// <summary>
/// ������� ������ ��������� � ����� �����
/// </summary>
/// <param name=="message">���������,��������� �� �����</param>
/// <param name=="varible">����������, ������� ������������� �������� ��������</param>
void EnterNumber(string message, int& varible);