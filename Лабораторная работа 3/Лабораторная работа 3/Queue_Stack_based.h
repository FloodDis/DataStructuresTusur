#pragma once
#include "Stack.h"

/// <summary>
/// ������� �� ���� ���� ������
/// </summary>
struct QueueStackBased
{
	/// <summary>
	/// ����, � ������� ���������� ��������  �������
	/// </summary>
	Node* StackIn;

	/// <summary>
	/// ����, �� �������� ����������� �������� �������
	/// </summary>
	Node* StackOut;

	/// <summary>
	/// true - StackIn ����, false - StackIn �� ����
	/// </summary>
	bool IsStackInEmpty = true;

	/// <summary>
	/// true - StackOut ����, false - StackOut �� ����
	/// </summary>
	bool IsStackOutEmpty = true;
};

/// <summary>
/// ������� �������� ������� �� ���� ���� ������
/// </summary>
/// <param name="queueStackUnit">��������� �� ��������� ����������� ���������</param>
void CreationOfQueueStackBased(QueueStackBased*& queueStackUnit);

/// <summary>
/// ������� ���������� �������� � �������
/// </summary>
/// <param name="queueStackUnit">��������� �� ��������� ���������</param>
/// <param name="dataOfElement">�������� ������ ��������</param>
void EnqueueStackBased(QueueStackBased*& queueStackUnit, int dataOfElement);

/// <summary>
/// ������� ������ �������� �� �������
/// </summary>
/// <param name="queueStackUnit">��������� �� ��������� ���������</param>
/// <returns>�������� ������������ ��������</returns>
int DequeueStackBased(QueueStackBased*& queueStackUnit);

/// <summary>
/// ������� �������� �������
/// </summary>
/// <param name="queueStackUnit">��������� �� ��������� �������</param>
void DeleteQueueStackBased(QueueStackBased*& queueStackUnit);

/// <summary>
/// ������� ������ ������� �� �����
/// </summary>
/// <param name="queueStackUnit">��������� �� ��������� �������</param>
void PrintQueueStackBased(QueueStackBased* queueStackUnit);
