#pragma once
#include "QueueStack.h"
#include "FrequentlyUsed.h"
#include "IOStack.h"

///<summary>
///Функция меню очереди на базе 2-х стеков
///</summary>
void QueueStackBasedMenu();

/// <summary>
/// Функция вывода очереди на экран
/// </summary>
/// <param name="queueStackUnit">указатель на экземпляр очереди</param>
void PrintQueue(QueueStackBased* queueStackUnit);