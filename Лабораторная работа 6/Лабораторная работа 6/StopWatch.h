#pragma once

#include <chrono>

/// <summary>
/// Секундомер
/// </summary>
class Stopwatch
{
public:
	/// <summary>
	/// Конструктор класса
	/// </summary>
	Stopwatch();

	/// <summary>
	/// Запустить секундомер.
	/// </summary>
	void Start();

	/// <summary>
	/// Остановить секундомер.
	/// </summary>
	void Stop();

	/// <summary>
	/// Сбросить измерения до нуля и прекратить дальнейший подсчёт.
	/// </summary>
	void Reset();

	/// <summary>
	/// Получить измеренное время в наносекундах.
	/// </summary>
	/// <returns>целое число - наносекунды.</returns>
	long long GetDuration();

private:

	/// <summary>
	/// Флаг остановки таймера
	/// true - таймер остановлен, false - таймер запущен.
	/// </summary>
	bool _isStopped;

	/// <summary>
	/// Момент начала отсчета.
	/// </summary>
	std::chrono::high_resolution_clock::time_point _timeBegin;

	/// <summary>
	/// Момент окончания отсчета.
	/// </summary>
	std::chrono::high_resolution_clock::time_point _timeEnd;

	/// <summary>
	/// Продолжительность периода.
	/// </summary>
	std::chrono::high_resolution_clock::time_point _timeDuration;
};
