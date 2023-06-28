#pragma once
#include "exam.h"


class Group
{
private:
	int sizeArray = 0;
	Exam* exam;
public:
	Group(int sizeArray); // �����������
	~Group(); // ����������
	void Print(); // ����� ������ �������� Exam � �������
	int Size(); // ������ ������ ������
	void PutExam(int i, Exam& exam); // ���� ������ �� ������
	Exam& GetExam(int i); // ������ ������ �� i-�� ������ Exam
	double Grade(); // ����������� ������� ������ � ������
	double Grade(int limit); // ���������� ������� ������, ������� �� ���� limit
	Exam& operator[](int i); // ���������� ��������� ����������
};