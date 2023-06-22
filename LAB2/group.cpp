#include "group.h"

Group::Group(int sizeArray)
{
	this->sizeArray = sizeArray;
	exam = new Exam[sizeArray];
}

Group::~Group()
{
	delete[] exam;
}

void Group::Print()
{
	for (int i = 0; i < sizeArray; i++)
	{
		exam[i].Print();
	}
}

int Group::Size()
{
	return sizeArray;
}

void Group::PutExam(int i, Exam& exam)
{
	this->exam[i] = exam;
}

Exam& Group::GetExam(int i)
{
	return exam[i];
}