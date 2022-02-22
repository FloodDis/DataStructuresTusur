#pragma once
#include "QueueRingBuffer.h"
#include "FrequentlyUsed.h"

/// <summary>
/// ������� ���� ������� �� ���� ���������� ������
/// </summary>
void QueueRingBufferMenu();

/// <summary>
/// ������� ������ ������� �� �����
/// </summary>
/// <param name="queueRingBufferUnit">
///��������� �� ��������� ���������
///</param>
void PrintQueue(RingBuffer* queueRingBufferUnit);

/// <summary>
/// ������� ������ ��������� ��� �����: 
/// � ������� �� ���� ���������� ������
/// </summary> 
/// <param name="queueRingBufferUnit">
///��������� ������� �� ���� ���������� ������
/// </param>
void ShowQueue(RingBuffer* queueRingBufferUnit);