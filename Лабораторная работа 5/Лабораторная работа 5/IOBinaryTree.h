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
//TODO: ����������, ��. ��� 3
void PrintBinaryTree(BinaryTreeNode* rootNode, int tabCount);

/// <summary>
/// ������� ������ ��������� ���� �������� ������: � ��������� ������
/// </summary>
/// <param name="rootNode">��������� �� ������ ��������� ������</param>
//TODO: ����������, ��. ��� 3
void ShowBinaryTree(BinaryTreeNode* rootNode);