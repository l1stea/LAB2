#pragma once
#include "exam.h"


class Group
{
private:
	int sizeArray = 0;
	Exam* exam;
public:
	Group(int sizeArray);
	~Group();
	void Print();
	int Size();
	void PutExam(int i, Exam& exam);
	Exam& GetExam(int i);
	double Grade(); // ����������� ������� ������ � ������
	double Grade(int limit); // ���������� ������� ������, ������� �� ���� limit
	Exam& operator[](int i);
};