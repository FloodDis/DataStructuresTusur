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
//TODO: ���������� �������, ��. ��� 3
//TODO: ������������ �������� ������ ���������� dictionary
void PrintDictionary(HashTable* hashTableUnit);

/// <summary>
/// ������� ������ ��������� ��� �������: � ������� 
/// </summary>
/// <param name="hashTableUnit">��������� ���-�������</param>
//TODO: ���������� �������, ��. ��� 3
//TODO: ������������ �������� ������ ���������� dictionary
void ShowDictionary(HashTable* hashTableUnit);