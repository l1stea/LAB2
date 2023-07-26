#pragma once
#include "exam.h"


class Group
{
private:
	int sizeArray = 0;
	Exam* exam;	
public:
	Group(int sizeArray); // �����������
	// ��������� �������� �������� �������;
	Group();
	Group(int sizeArray, Exam* exam);
	Group(Exam* exam);
	~Group(); // ����������
	void Print(); // ����� ������ �������� Exam � �������
	void PutExam(int i, Exam& exam); // ���� ������ �� ������
	Exam& GetExam(int i); // ������ ������ �� i-�� ������ Exam
	double Grade(); // ����������� ������� ������ � ������
	double Grade(int limit); // ���������� ������� ������, ������� �� ���� limit
	Exam& operator[](int i); // ���������� ��������� ����������
	int GetSize();
	void SetSize(int sizeArray);
	void NewExam();
	//operator GroupUniver();
	//operator GroupUniver(); // �������� ���������� ���� Group � GroupUniver
};