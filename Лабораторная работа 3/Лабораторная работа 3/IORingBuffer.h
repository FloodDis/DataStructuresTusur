#pragma once
#include "RingBuffer.h"
#include "FrequentlyUsed.h"

///<summary>
/// ‘ункци€ меню дл€ кольцевого буфера
/// </summary>
void RingBufferMenu();

/// <summary>
/// ‘ункци€ вывода кольцевого буфера на экран
/// </summary>
/// <param name="ringBuffer">указатель на экземпл€р структуры</param>
void PrintBuffer(RingBuffer* RingBuffer);

/// <summary>
/// ‘ункци€ вывода сообщение ¬аш буфер: и кольцевого буфера на экран
/// </summary>
/// <param name="ringBuffer">указатель на экземпл€р структуры</param>
void ShowBuffer(RingBuffer* RingBuffer);