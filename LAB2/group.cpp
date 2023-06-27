#include "group.h"
#include <iostream>
using namespace std;

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

double Group::Grade()
{
	int summ = 0;
	for (int i = 0; i < sizeArray; i++)
	{
		try
		{
			summ += exam[i].GetGrade();
		}
		catch (...)
		{
			cout << "Ошибка при подсчёте суммы!";
		}
	}
	return summ * 1.0 / sizeArray;
}

double Group::Grade(int limit)
{
	int summ = 0;
	int count = 0;
	for (int i = 0; i < sizeArray; i++)
	{
		try
		{
			int grade = exam[i].GetGrade();
			if (grade >= limit)
			{
				count++;
				summ += grade;
			}
		}
		catch (...)
		{
			cout << "Ошибка при подсчёте суммы!";
		}
	}
	return summ * 1.0 / count;
}

Exam& Group::operator[](int i)
{
	return GetExam(i);
}