#pragma once
#include "QueueRingBuffer.h"
#include "FrequentlyUsed.h"

void QueueRingBufferMenu();

/// <summary>
/// ������� ������ ������� �� �����
/// </summary>
//TODO: �����
/// <param name="queueRingBufferUnit">��������� �� ��������� ���������</param>
void PrintQueueRingBuffer(RingBuffer* queueRingBufferUnit);

/// <summary>
//TODO: �����
/// ������� ������ ��������� ��� �����: � ������� �� ���� ���������� ������
/// </summary> 
//TODO: �����
/// <param name="queueRingBufferUnit">��������� ������� �� ���� ���������� ������</param>
void ShowQueueRingBuffer(RingBuffer* queueRingBufferUnit);