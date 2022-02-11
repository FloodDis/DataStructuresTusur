#pragma once
#include "HashTable.h"

/// <summary>
/// ������� ���������� ���� ����-�������� � �������
/// </summary>
/// <param name="hashTableUnit">��������� ���-�������</param>
/// <param name="value">�������� ������������ ��������</param>
/// <param name="key">���� ������������ ��������</param>
void AddInDictionary(vector<KeyValueList*> hashTableUnit, string value, string key);

/// <summary>
/// ������� �������� ���� ����-�������� �� �������
/// </summary>
/// <param name="hashTableUnit">��������� ���-�������</param>
/// <param name="key">���� ���������� ��������</param>
void DeleteFromDictionary(vector<KeyValueList*>& hashTableUnit, string key);

/// <summary>
/// ������� ������ ���� ����-�������� � �������
/// </summary>
/// <param name="hashTableUnit">��������� ���-�������</param>
/// <param name="key">���� �������� ��������</param>
string SearchInDictionary(vector<KeyValueList*>& hashTableUnit, string key);
