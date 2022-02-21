#pragma once
#include "BinaryTree.h"
#include "FrequentlyUsed.h"
#include <iostream>
using namespace std;

///<summary>
///������� ������ ���� ��������� ������
///</summary>
void BinaryTreeMenu();

/// <summary>
/// ������� ������ ��������� ������ �� �����
/// </summary>
/// <param name="rootNode">��������� �� ������ ��������� ������</param>
/// <param name="tabCount">���-�� ���������</param>
void Print(BinaryTreeNode* rootNode, int tabCount);

/// <summary>
/// ������� ������ ��������� ���� �������� ������: � ��������� ������
/// </summary>
/// <param name="rootNode">��������� �� ������ ��������� ������</param>
void Show(BinaryTreeNode* rootNode);