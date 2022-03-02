#pragma once
#include "RingBuffer.h"
#include "FrequentlyUsed.h"

///<summary>
/// Функция меню для кольцевого буфера
/// </summary>
void RingBufferMenu();

/// <summary>
/// Функция вывода кольцевого буфера на экран
/// </summary>
/// <param name="ringBuffer">указатель на экземпляр структуры</param>
void PrintBuffer(RingBuffer* RingBuffer);

/// <summary>
/// Функция вывода сообщение Ваш буфер: и кольцевого буфера на экран
/// </summary>
/// <param name="ringBuffer">указатель на экземпляр структуры</param>
void ShowBuffer(RingBuffer* RingBuffer);