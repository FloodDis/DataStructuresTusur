#pragma once
#include "List.h"
#include <iostream>

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
/// ������� ������ ��������� � ����� �������� ���������� �� �������
/// </summary>
/// <param name="message">������ � ����������</param>
int EnterNumber(string message);

/// <summary>
/// ������� ������ ������ �� �����
/// </summary>
/// <param name="headNode">��������� �� ������ ������</param>
void PrintList(Node* headNode);

///<summary>
/// ������� ������ ��������� Your list: � ������
/// </summary>
/// <param name="headNode">��������� �� ������ ������</param>
void ShowList(Node* headNode);