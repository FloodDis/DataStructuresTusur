#pragma once
#include "HashTable.h"

/// <summary>
/// �������
/// </summary>
struct Dictionary
{
	/// <summary>
	/// ���-�������
	/// </summary>
	vector<KeyValueList*> HashTable;
};

/// <summary>
/// ������� ������������� �������
/// </summary>
/// <param name="hashTableUnit">������ �� ��������� ���-�������</param>
/// <param name="size">������ �������</param>
void InitializationOfDictionary(vector<KeyValueList*>& hashTableUnit, int size);

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

/// <summary>
/// ������� ����� ����� � ������ ���������
/// </summary>
/// <param name="message">������ � ����������</param>
/// <param name="value">����������, ������� ������������� �����</param>
void EnterNumber(string message, int& value);

/// <summary>
/// ������� ����� ������ � ������ ���������
/// </summary>
/// <param name="message">������ � ����������</param>
/// <param name="value">����������, ������� ������������� ������</param>
void EnterString(string message, string& value);

/// <summary>
/// ������� ������ ��������� ��� �������: � ������� 
/// </summary>
/// <param name="hashTableUnit">��������� ���-�������</param>
void ShowDictionary(vector<KeyValueList*> hashTableUnit);