#pragma once
#include <iostream>
using namespace std;

/// <summary>
/// ������
/// </summary>
/// <typeparam name="Type"></typeparam>
template<typename Type>
class Vector
{
public:
	/// <summary>
	/// �����������
	/// </summary>
	Vector();

	/// <summary>
	/// ����������
	/// </summary>
	~Vector();

	/// <summary>
	/// ������� �������� � ������.
	/// </summary>
	/// <param name="value">- �������� �������� ��� �������.</param>
	/// <param name="index">
	/// - � ����� ������ ������� �������� �������.
	/// </param>
	void InsertElement(Type value, unsigned int index);

	/// <summary>
	/// ������� ������� ������� ��� ����������� ��������.
	/// </summary>
	/// <param name="index">- ������ ��������.</param>
	void DeleteElement(unsigned int index);

	/// <summary>
	/// ������� �������� � ������ �������.
	/// </summary>
	/// <param name="value">- �������� ��� �������.</param>
	void PushFront(Type value);

	/// <summary>
	/// ������� �������� � ����� �������.
	/// </summary>
	/// <param name="value">- �������� ��� �������.</param>
	void PushBack(Type value);

	/// <summary>
	/// �������� �������� �� ������ �������.
	/// </summary>
	void PopFront();

	/// <summary>
	/// �������� �������� �� ����� �������.
	/// </summary>
	void PopBack();

	/// <summary>
	/// ����� ������ �������� �� ��������, 
	/// ����� -1 ���� ������� �� ������, ����� �������������� �������.
	/// </summary>
	/// <param name="value">- ��������, ������ �������� ���� �����.</param>
	/// <returns>
	/// ������ �������� � �������� ��������� ��� -1,
	///  ���� ������ �������� � ����� ��������� ���.
	/// </returns>
	int FindLinary(Type value);

	/// <summary>
	/// ����� ������ �������� �� ��������, 
	/// ����� -1 ���� ������� �� ������, 
	/// ����� �������������� �������.
	/// </summary>
	/// <param name="value">- ��������, ������ �������� ���� �����.</param>
	/// <returns>
	/// ������ �������� � �������� ��������� ��� -1,
	///  ���� ������ �������� � ����� ��������� ���.
	/// </returns>
	int FindBinary(Type value);

	/// <summary>
	/// ��������� �������� ������� �� �����������. (���������� �������)
	/// </summary>
	void Sort();

	/// <summary>
	/// �������� ������� ������������� ������� �� ��� �������.
	/// </summary>
	/// <param name="index">- ������ ����������� ��������.</param>
	/// <returns>������� ��� ������ ��������.</returns>
	Type GetElement(unsigned int index);
	Type operator[](unsigned int index);

	/// <summary>
	/// ���������� ������� ������ �������.
	/// </summary>
	/// <returns>����������� ����� �����.</returns>
	unsigned int GetSize() const;

	/// <summary>
	/// ���������� ����������� �������.
	/// </summary>
	/// <returns>����������� ����� �����</returns>
	unsigned int GetCapacity() const;

private:
	/// <summary>
	/// ��������� �� ������� �� ������ 
	/// �� ������� ������� (0 <= index < size).
	/// </summary>
	/// <param name="index">- ����������� ������.</param>
	/// <returns>
	/// ���������� true ���� ������ �� ������� �� ������� �������, 
	/// ����� false
	/// </returns>
	bool IsIndexCorrect(int index);

	/// <summary>
	/// ��������� ������ ����������� ������� 
	/// (������������ ��������� ����� �������� ���������).
	/// </summary>
	/// <param name="capacity">- ����� ����������� �������.</param>
	void Reserve(unsigned int capacity);

	/// <summary>
	/// ������ ��������� � �������
	/// </summary>
	Type* _iternalElements;

	/// <summary>
	/// ������� �������
	/// </summary>
	unsigned int _capacity;

	/// <summary>
	/// ������ �������
	/// </summary>
	unsigned int _size;

	/// <summary>
	/// ������ �����
	/// </summary>
	const double _growthFactor;
};
