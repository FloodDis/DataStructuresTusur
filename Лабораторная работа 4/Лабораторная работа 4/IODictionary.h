#pragma once
#include "Dictionary.h"
#include "FrequentlyUsed.h"
#include "IOHashTable.h"

///<summary>
///������� ������ ���� �������
///</summary>
void DictionaryMenu();

/// <summary>
/// ������� ������ �������
/// </summary>
/// <param name="message">������ � ����������</param>
void Print(HashTable* hashTableUnit);

/// <summary>
/// ������� ������ ��������� ��� �������: � ������� 
/// </summary>
/// <param name="hashTableUnit">��������� ���-�������</param>
void Show(HashTable* hashTableUnit);