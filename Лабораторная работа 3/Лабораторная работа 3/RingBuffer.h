#pragma once
#include <iostream>
using namespace std;

/// <summary>
/// Кольцевой буфер
/// </summary>
struct RingBuffer
{
	/// <summary>
	/// Размер буфера
	/// </summary>
	int Size;

	/// <summary>
	/// Указатель на динамический массив
	/// </summary>
	int* Data;

	/// <summary>
	/// Количество прочтенных элементов
	/// </summary>
	int ReadCount;

	/// <summary>
	/// Количество записанных элементов
	/// </summary>
	int WriteCount;

	/// <summary>
	/// Маска
	/// </summary>
	int Mask;
};

/// <summary>
/// Функция проверки кольцевого буфера на заполненность
/// </summary>
/// <param name="ringBuffer">указатель на экземпляр кольцевого буфера</param>
/// <returns>true - кольцевой буфер не заполнен, false - кольцевой буфер заполнен</returns>
bool IfThereSpaceToWrite(RingBuffer* ringBuffer);

/// <summary>
/// Функция проверки кольцевого буфера на пустоту
/// </summary>
/// <param name="ringBuffer">указатель на экземпляр кольцевого буфера</param>
/// <returns>true - кольцевой буфер пуст, false - кольцевой буфер не пуст</returns>
bool IsEmpty(RingBuffer* ringBuffer);

/// <summary>
/// Функция добавления элемента в кольцевой буфер
/// </summary>
/// <param name="ringBuffer">указатель на экземпляр кольцевого буфера</param>
/// <param name="value">значение добавляемого элемента</param>
void PushInRingBuffer(RingBuffer*& ringBuffer, int value);

/// <summary>
/// Функция извлечения элемента из кольцевого буфера
/// </summary>
/// <param name="ringBuffer">указатель на экземпляр кольцевого буфера</param>
/// <returns>значение извлекаемого элемента</returns>
int PopFromRingBuffer(RingBuffer*& ringBuffer);

/// <summary>
/// Функция инициализации кольцевого буфера
/// </summary>
/// <param name="sizeOfRingBuffer">размер кольцевого буфера</param>
/// <returns>экземпляр кольцевого буфера</returns>
RingBuffer* InitializationOfRingBuffer(int sizeOfRingBuffer);

/// <summary>
/// Функция вывода кольцевого буфера на экран
/// </summary>
/// <param name="ringBuffer">указатель на экземпляр структуры</param>
void PrintBuffer(RingBuffer* ringBuffer);

/// <summary>
/// Функция вывода сообщение Ваш буфер: и кольцевого буфера на экран
/// </summary>
/// <param name="ringBuffer">указатель на экземпляр структуры</param>
void ShowRingBuffer(RingBuffer* ringBuffer);