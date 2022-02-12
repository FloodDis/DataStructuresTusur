#pragma once
#include "Red_Black_Tree.h"
#include <iostream>
using namespace std;

/// <summary>
/// ������� ������ ���� ������-������� ������
/// </summary>
void RBTreeMenu();

/// <summary>
/// ������� ������ ��������� � ����� �����
/// </summary>
/// <param name="message">��������� ���������</param>
/// <param name="value">����������, ������� ������������� �������� ��������</param> 
void EnterNumber(string message, int& value);