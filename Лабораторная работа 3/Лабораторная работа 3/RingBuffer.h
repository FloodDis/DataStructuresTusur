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

	//TODO:+

	/// <summary>
	/// Индекс элемента, который будет извлечен из очереди
	/// </summary>
	int ElementToRead = 0;

	/// <summary>
	/// Индекс элемента, в который будет помещен новый элемент
	/// </summary>
	int ElementToWrite = 0;

	/// <summary>
	/// Кол-во незанятых элементов буфера
	/// </summary>
	int FreeSpace = Size;
};

/// <summary>
/// Функция проверки буфера на заполненность
/// </summary>
/// <param name="ringBuffer">указатель на экземпляр кольцевого буфера</param>
/// <returns>
/// true - буфер полон, false - буфер не полон
/// </returns>
bool IsFull(RingBuffer* ringBuffer);

/// <summary>
/// Функция проверки буфера на пустоту
/// </summary>
/// <param name="ringBuffer">указатель на экземпляр кольцевого буфера</param>
/// <returns>
/// true - буфер пуст, false - буфер не пуст
/// </returns>
bool IsEmpty(RingBuffer* ringBuffer);

/// <summary>
/// Функция добавления элемента в кольцевой буфер
/// </summary>
/// <param name="ringBuffer">указатель на экземпляр кольцевого буфера</param>
/// <param name="value">значение добавляемого элемента</param>
//TODO: см. PopFromStack
void PushInRingBuffer(RingBuffer*& ringBuffer, int value);

/// <summary>
/// Функция извлечения элемента из кольцевого буфера
/// </summary>
/// <param name="ringBuffer">указатель на экземпляр кольцевого буфера</param>
/// <returns>значение извлекаемого элемента</returns>
//TODO: см. PopFromStack
int PopFromRingBuffer(RingBuffer*& ringBuffer);

/// <summary>
/// Функция инициализации кольцевого буфера
/// </summary>
/// <param name="sizeOfRingBuffer">размер кольцевого буфера</param>
/// <returns>экземпляр кольцевого буфера</returns>
//TODO: см. PopFromStack
RingBuffer* InitializationOfRingBuffer(int sizeOfRingBuffer);

