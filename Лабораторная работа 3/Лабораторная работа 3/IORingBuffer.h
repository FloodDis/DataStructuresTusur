#pragma once
#include "RingBuffer.h"
#include "FrequentlyUsed.h"

///<summary>
/// ������� ���� ��� ���������� ������
/// </summary>
void RingBufferMenu();

/// <summary>
/// ������� ������ ���������� ������ �� �����
/// </summary>
/// <param name="ringBuffer">��������� �� ��������� ���������</param>
void PrintBuffer(RingBuffer* RingBuffer);

/// <summary>
/// ������� ������ ��������� ��� �����: � ���������� ������ �� �����
/// </summary>
/// <param name="ringBuffer">��������� �� ��������� ���������</param>
void ShowBuffer(RingBuffer* RingBuffer);