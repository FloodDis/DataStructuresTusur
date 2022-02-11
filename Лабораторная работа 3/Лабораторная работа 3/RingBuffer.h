#pragma once
#include <iostream>
using namespace std;

/// <summary>
/// ��������� �����
/// </summary>
struct RingBuffer
{
	/// <summary>
	/// ������ ������
	/// </summary>
	int Size;

	/// <summary>
	/// ��������� �� ������������ ������
	/// </summary>
	int* Data;

	/// <summary>
	/// ���������� ���������� ���������
	/// </summary>
	int ReadCount;

	/// <summary>
	/// ���������� ���������� ���������
	/// </summary>
	int WriteCount;

	/// <summary>
	/// �����
	/// </summary>
	int Mask;
};

/// <summary>
/// ������� �������� ���������� ������ �� �������������
/// </summary>
/// <param name="ringBuffer">��������� �� ��������� ���������� ������</param>
/// <returns>true - ��������� ����� �� ��������, false - ��������� ����� ��������</returns>
bool IfThereSpaceToWrite(RingBuffer* ringBuffer);

/// <summary>
/// ������� �������� ���������� ������ �� �������
/// </summary>
/// <param name="ringBuffer">��������� �� ��������� ���������� ������</param>
/// <returns>true - ��������� ����� ����, false - ��������� ����� �� ����</returns>
bool IsEmpty(RingBuffer* ringBuffer);

/// <summary>
/// ������� ���������� �������� � ��������� �����
/// </summary>
/// <param name="ringBuffer">��������� �� ��������� ���������� ������</param>
/// <param name="value">�������� ������������ ��������</param>
void PushInRingBuffer(RingBuffer*& ringBuffer, int value);

/// <summary>
/// ������� ���������� �������� �� ���������� ������
/// </summary>
/// <param name="ringBuffer">��������� �� ��������� ���������� ������</param>
/// <returns>�������� ������������ ��������</returns>
int PopFromRingBuffer(RingBuffer*& ringBuffer);

/// <summary>
/// ������� ������������� ���������� ������
/// </summary>
/// <param name="sizeOfRingBuffer">������ ���������� ������</param>
/// <returns>��������� ���������� ������</returns>
RingBuffer* InitializationOfRingBuffer(int sizeOfRingBuffer);

/// <summary>
/// ������� ������ ���������� ������ �� �����
/// </summary>
/// <param name="ringBuffer">��������� �� ��������� ���������</param>
void PrintBuffer(RingBuffer* ringBuffer);

