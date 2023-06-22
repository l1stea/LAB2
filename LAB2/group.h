#pragma once
#include "exam.h"


class Group
{
private:
	int sizeArray;
	Exam* exam;
public:
	Group(int sizeArray);
	~Group();
	void Print();
	int Size();
	void PutExam(int i, Exam& exam);
	Exam& GetExam(int i);
};

