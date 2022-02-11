#pragma once
#include <iostream>
#include <vector>
using namespace std;

/// <summary>
/// ���� ������ ��������
/// </summary>
struct KeyValueList
{
	/// <summary>
	/// ����
	/// </summary>
	string Key = "";

	/// <summary>
	/// ��������
	/// </summary>
	string Value = "";

	/// <summary>
	/// ��������� �� ��������� ����
	/// </summary>
	KeyValueList* Next = nullptr;

	/// <summary>
	/// ��������� �� ���������� ����
	/// </summary>
	KeyValueList* Previous = nullptr;
};

/// <summary>
/// ������� ������������� ���-�������
/// </summary>
/// <param name="hashTableUnit">��������� ���-�������</param>
/// <param name="size">������ ���-�������</param>
void InitializationOfHashTable(vector<KeyValueList*>& hashTableUnit, int size);

/// <summary>
/// ������� ���������� ���� ����-�������� � ���-�������
/// </summary>
/// <param name="hashTableUnit">��������� ���-�������</param>
/// <param name="value">�������� ������������ ��������</param>
/// <param name="key">���� ������������ ��������</param>
void AddElementInHashTable(vector<KeyValueList*> hashTableUnit, string value, string key);

/// <summary>
/// ������� �������� ���� ����-�������� �� ���-�������
/// </summary>
/// <param name="hashTableUnit">��������� ���-�������</param>
/// <param name="key">���� ��������� ���������� ��������</param>
void DeleteElementInHashTable(vector<KeyValueList*> hashTableUnit, string key);

/// <summary>
/// ������� ���������
/// </summary>
/// <param name="oldHashTable">��������� ���-������� �� ���������</param>
/// <param name="countOfElements">���������� ���������</param>
void Rehashing(vector<KeyValueList*>& oldHashTable, double countOfElements);

/// <summary>
/// ���-�������
/// </summary>
/// <param name="key">����</param>
/// <param name="size">������ ���-�������</param>
/// <returns></returns>
int HashFunction(string key, int size);

/// <summary>
/// ������� ������ ������ �������� �� �����
/// </summary>
/// <param name="listUnit">��������� ������ ��������</param>
void PrintKeyValueList(KeyValueList* listUnit);

/// <summary>
/// ������� ������ ���-������� �� �����
/// </summary>
/// <param name="hashTableUnit">��������� ���-�������</param>
void PrintTable(vector<KeyValueList*> hashTableUnit);

/// <summary>
/// ������� ������ �������� � ���-�������
/// </summary>
/// <param name="searchingKey">���� �������� ��������</param>
/// <param name="hashTableUnit">��������� ���-�������</param>
/// <returns>������ � �������</returns>
string SearchInHashTable(string searchingKey, vector<KeyValueList*> hashTableUnit);

///<summary>
/// ������� �������� ���������
/// </summary>
/// <param name="hashTableUnit">��������� ���-�������</param>
/// <returns>���������� ���������</returns>
double ElementCount(vector<KeyValueList*> hashTableUnit);
