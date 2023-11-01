#pragma once
#include "exam.h"


class group
{
private:
	int size_array_;
	exam* exam_;
public:
	group(int size_array); // �����������
	group();
	group(int size_array, exam* ex);
	group(exam* exam);
	~group(); // ����������
	void print() const; // ����� ������ �������� Exam � �������
	void put_exam(int i,const exam& ex); // ���� ������ �� ������
	exam& get_exam(int i) const;// ������ ������ �� i-�� ������ Exam
	double get_grade() const; // ����������� ������� ������ � ������
	double get_grade(int limit) const; // ���������� ������� ������, ������� �� ���� limit
	exam& operator[](int i); // ���������� ��������� ����������
	int get_size() const;
	void new_exam();
};