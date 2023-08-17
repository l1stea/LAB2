// ReSharper disable CommentTypo
#pragma once
#include "exam.h"


class group
{
	int size_array_ = 0;
	exam* exam_;
public:
	explicit group(int size_array); // �����������
	// ��������� �������� �������� �������;
	// ReSharper restore CommentTypo
	group();
	group(int size_array, exam* exam);
	explicit group(exam* exam);
	~group(); // ����������
	// ReSharper disable CommentTypo
	void print() const; // ����� ������ �������� Exam � �������
	void put_exam(int i, const exam& ex) const; // ���� ������ �� ������
	exam& get_exam(int i) const;// ������ ������ �� i-�� ������ Exam
	double get_grade() const; // ����������� ������� ������ � ������
	double get_grade(int limit) const; // ���������� ������� ������, ������� �� ���� limit
	exam& operator[](int i) const; // ���������� ��������� ����������
	int get_size() const;
	void set_size(int size_array);
	void new_exam();
	//operator GroupUniver();
	//operator GroupUniver(); // �������� ���������� ���� Group � GroupUniver
};
