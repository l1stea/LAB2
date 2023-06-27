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
	double Grade(); // Возваращает среднюю оценку в группе
	double Grade(int limit); // Возвращает среднюю оценку, которая не ниже limit
	Exam& operator[](int i);
};