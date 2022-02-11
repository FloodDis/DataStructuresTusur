#pragma once
#include <string>
using namespace std;

/// <summary>
/// ���� ������
/// </summary>
struct Node
{
	/// <summary>
	/// ������ ����
	/// </summary>
	int DataOfNode;

	/// <summary>
	/// ��������� �� ��������� ����
	/// </summary>
	Node* NextNode;

	/// <summary>
	/// ��������� �� ���������� ����
	/// </summary>
	Node* PreviousNode;
};

/// <summary>
/// ������� ������������� ������
/// </summary>
/// <param name="dataOfHeadNode">������ ����� ������</param>
/// <returns>
/// ������������������ ����
/// </returns>
Node* InitializationOfList(int dataOfHeadNode);

/// <summary>
/// ������� �������� ���� ������
/// </summary>
/// <param name="headNode">��������� �� ������ ������</param>
/// <param name="index">������ ���������� ��������</param>
void DeleteElement(Node* headNode, int index);

/// <summary>
/// ������� ���������� �������� � ������ �������
/// </summary>
/// <param name="headNode">��������� �� ������ ������</param>
/// <param name="dataOfNewNode">������ ������ ��������</param>
/// <returns>
/// ��������� �� ����� ������ ������
/// </returns>
Node* AddInTheBeginning(Node* headNode, int dataOfNewNode);

/// <summary>
/// ������� ���������� �������� � ����� ������
/// </summary>
/// <param name="headNode">��������� �� ������ ������</param>
/// <param name="dataOfNewNode">������ ������ ��������</param>
void AddInTheEnd(Node* headNode, int dataOfNewNode);

/// <summary>
/// ������� ���������� �������� ����� ������������ ���������
/// </summary>
/// <param name="headNode">��������� �� ������ ������</param>
/// <param name="dataOfNewNode">������ ������ ��������</param>
/// <param name="index">������ ��������, ����� ������� ����� �������� ����� �������</param>
/// <returns>
/// ��������� �� ����� ������ ������
/// </returns>
Node* AddBefore(Node* headNode, int dataOfNewNode, int index);

/// <summary>
/// ������� ���������� ��������  ����� ������������� ��������
/// </summary>
/// <param name="headNode">��������� �� ������ ������</param>
/// <param name="dataOfNewNode">������ ������ ��������</param>
/// <param name="index">������ ��������, ����� �������� ����� �������� ����� �������</param>
void AddAfter(Node* headNode, int dataOfNewNode, int index);

/// <summary>
/// ������� ���������� ���������
/// </summary>
/// <param name="headNode">��������� �� ������ ������</param>
void BubbleSort(Node* headNode);

/// <summary>
/// ������� ������ ������ �� �����
/// </summary>
/// <param name="headNode">��������� �� ������ ������</param>
void PrintList(Node* headNode);

/// <summary>
/// ������� ��������� ������
/// </summary>
/// <param name="headNode">��������� �� ������ ������</param>
/// <param name="searchingValue">�������� �������� ��������</param>
/// <returns>
/// ������� �������
/// </returns>
Node* LinearSearch(Node* headNode, int searchingValue);

/// <summary>
/// ������� ������ �� ����� ���������, ��������� � ������� ��������� ������
/// </summary>
/// <param name="indexes">��������� �� ������ ������ �������� ��������� ���������</param>
/// <param name="headNode">>��������� �� ������ ������</param>
void PrintFinded(Node* indexes, Node* headNode);

/// <summary>
/// ������� ����
/// </summary>
/// <param name="headNode">��������� �� ������ ������</param>
void Menu(Node* headNode);

/// <summary>
/// ������� �������� ��������� ������
/// </summary>
/// <param name="headNode">��������� �� ������ ������</param>
/// <returns>
/// ���-�� ��������� ������
/// </returns>
int ElementCount(Node* headNode);

/// <summary>
/// ������� ������ ��������� � ����� �������� ���������� �� �������
/// </summary>
/// <param name="message">������ � ����������</param>
/// <param name="variable">�������� ����������</param>
/// <returns>
/// �������� ����������
/// </returns>
int EnterNumber(string message, int variable);

///<summary>
/// ������� ��������� ���������� �����
/// </summary>
/// <returns>
/// ��������� �����
/// </returns>
int Randomize();

///<summary>
/// ������� ������ ��������� Your list: � ������
/// </summary>
/// <param name="headNode">��������� �� ������ ������</param>
void ShowList(Node* headNode);