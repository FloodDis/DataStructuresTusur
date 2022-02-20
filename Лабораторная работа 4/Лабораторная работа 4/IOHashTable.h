#pragma once
#include "HashTable.h"
#include "FrequentlyUsed.h"

///<summary>
///������� ������ ���� ���-�������
///</summary>
void HashTableMenu();

/// <summary>
/// ������� ������ ���-������� �� �����
/// </summary>
/// <param name="hashTableUnit">��������� ���-�������</param>
void PrintTable(vector<KeyValueList*> hashTableUnit);

///<summary>
/// ������� ������ ������ ���� ���-������� � ���-�������
/// </summary>
/// <param name="hashTableUnit">��������� ���-�������</param>
void ShowHashTable(vector<KeyValueList*> hashTableUnit);

/// <summary>
/// ������� ������ ������ �������� �� �����
/// </summary>
/// <param name="listUnit">��������� ������ ��������</param>
void PrintKeyValueList(KeyValueList* listUnit);