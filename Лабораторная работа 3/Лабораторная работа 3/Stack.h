#pragma once
#include <iostream>
using namespace std;

/// <summary>
/// ����
/// </summary>
struct Node
{
	/// <summary>
	/// ������ ����
	/// </summary>
	int DataOfNode;

	/// <summary>
	/// ��������� �� ���������� ����
	/// </summary>
	Node* PreviousNode;
};

/// <summary>
/// ������� �������� �����
/// </summary>
/// <returns>��������� �� ������ �����</returns>
Node* CreationOfStack();

/// <summary>
/// ������� ���������� �������� � ����
/// </summary>
/// <param name="headNode">�������� �� ������ �����</param>
/// <param name="dataOfNewElement">�������� ������ ��������</param>
/// <returns>��������� �� ����� ������ ������</returns>
Node* PushInStack(Node* headNode, int dataOfNewElement);

/// <summary>
/// ������� ���������� �������� �� �����
/// </summary>
/// <param name="headNode">�������� �� ������ �����</param>
/// <returns>�������� ������������ ��������</returns>
int PopFromStack(Node*& headNode);

/// <summary>
/// ������� �������� �����
/// </summary>
/// <param name="headNode">�������� �� ������ �����</param>
void DeleteStack(Node*& headNode);

/// <summary>
/// ������� ������ ����� �� �����
/// </summary>
/// <param name="headNode">�������� �� ������ �����</param>
void PrintStack(Node* headNode);

/// <summary>
/// ������� ������ ��������� ��� ����: � ����� �� �����
/// </summary>
/// <param name="headNode">�������� �� ������ �����</param>
void ShowStack(Node* headNode);