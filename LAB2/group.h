// ReSharper disable CommentTypo
#pragma once
#include "exam.h"


class group
{
private:
	int size_array_;
	exam* exam_;
public:
	explicit group(int size_array); // �����������
	// ��������� �������� �������� �������;
	// ReSharper restore CommentTypo
	group();
	group(int size_array, exam* ex);
	explicit group(exam* exam);
	~group(); // ����������
	// ReSharper disable CommentTypo
	void print(); // ����� ������ �������� Exam � �������
	void put_exam(int i, exam& ex); // ���� ������ �� ������
	exam& get_exam(int i);// ������ ������ �� i-�� ������ Exam
	double get_grade(); // ����������� ������� ������ � ������
	double get_grade(int limit); // ���������� ������� ������, ������� �� ���� limit
	exam& operator[](int i); // ���������� ��������� ����������
	int get_size();
	//void set_size(int size_array);
	void new_exam();
	//operator GroupUniver();
	//operator GroupUniver(); // �������� ���������� ���� Group � GroupUniver
};
