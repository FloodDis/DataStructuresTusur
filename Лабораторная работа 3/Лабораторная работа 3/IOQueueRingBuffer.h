#pragma once
#include "QueueRingBuffer.h"
#include "FrequentlyUsed.h"

void QueueRingBufferMenu();

/// <summary>
/// ������� ������ ������� �� �����
/// </summary>
/// <param name="queueRingBufferUnit">
///��������� �� ��������� ���������
///</param>
void PrintQueueRingBuffer(RingBuffer* queueRingBufferUnit);

/// <summary>
/// ������� ������ ��������� ��� �����: 
/// � ������� �� ���� ���������� ������
/// </summary> 
/// <param name="queueRingBufferUnit">
///��������� ������� �� ���� ���������� ������
/// </param>
void ShowQueueRingBuffer(RingBuffer* queueRingBufferUnit);