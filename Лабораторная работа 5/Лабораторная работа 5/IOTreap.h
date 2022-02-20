#pragma once
#include "Treap.h"
#include "FrequentlyUsed.h"
#include <iostream>
using namespace std;

///<summary>
///������� ������ ���� ��������� ������
///</summary>
void TreapMenu();

/// <summary>
/// ������� ������ ��������� ������ �� �����
/// </summary>
/// <param name="nodeToPrint">��������� �� ������ ������</param>
/// <param name="lndent">���-�� ���������</param>
void PrintTreap(TreapNode* nodeToPrint, int lndent = 0);

/// <summary>
/// ������� ������ ��������� � ��������� ������
/// </summary>
/// <param name=="message">���������,��������� �� �����</param>
/// <param name=="nodeToPrint">������ ���������</param>
void ShowTreap(string message, TreapNode* nodeToPrint);