#pragma once
#include "RingBuffer.h"

/// <summary>
/// ������� �� ���� ���������� ������
/// </summary>
struct QueueRingBufferBased
{
	/// <summary>
	/// ��������� �����
	/// </summary>
	RingBuffer ringBuffer;
};

/// <summary>
/// ������� �������� ������� �� ���� ���������� ������
/// </summary>
/// <param name="sizeOfQueue">������ �������</param>
/// <returns>��������� �������</returns>
RingBuffer* CreationOfQueue(int sizeOfQueue);

/// <summary>
/// ������� ���������� �������� � �������
/// </summary>
/// <param name="queueRingBufferUnit">��������� �� ��������� ���������</param>
/// <param name="value">�������� ������ ��������</param>
void EnqueueRingBuffer(RingBuffer*& queueRingBufferUnit, int value);

/// <summary>
/// ������� �������� �������� �� �������
/// </summary>
/// <param name="queueRingBufferUnit">��������� �� ��������� ���������</param>
/// <returns>�������� ������������ ��������</returns>
int DequeueRingBuffer(RingBuffer*& queueRingBufferUnit);

/// <summary>
/// ������� �������� �������
/// </summary>
/// <param name="queueRingBufferUnit">��������� �� ��������� ���������</param>
void DeleteQueueRingBuffer(RingBuffer*& queueRingBufferUnit);

/// <summary>
/// ������� ������ ������� �� �����
/// </summary>
/// <param name="queueRingBufferUnit">��������� �� ��������� ���������</param>
void PrintQueueRingBuffer(RingBuffer* queueRingBufferUnit);

/// <summary>
/// ������� ����� ����� � ������ ���������
/// </summary>
/// <param name="message">������ � ����������</param>
/// <param name="value">�������� �����</param>
void EnterNumber(string message, int& value);