#include "group.h"
#include <iostream>
#include "groupUniver.h"

using namespace std;


Group::Group(int sizeArray)
{
	cout << "Group конструктор вызван" << endl;
	this->sizeArray = sizeArray;
	this->exam = new Exam[sizeArray]; // new - динамическое выделение памяти
}

Group::~Group()
{
	cout << "Group деструктор вызван" << endl;
	delete[] exam; // Освобождение памяти и вызов деструктора для каждого элемента массива
}

void Group::Print()
{
	for (int i = 0; i < sizeArray; i++)
	{
		exam[i].Print();
	}
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
	int count = 0; // Счётчик чисел
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
	try
	{
		return GetExam(i);
	}
	catch (out_of_range)
	{
		cout << "Некорректный индекс" << endl;
	}
}

void Group::SetSize(int sizeArray)
{
	this->sizeArray = sizeArray;
}

int Group::GetSize()
{
	return this->sizeArray;
}

void Group::NewExam()
{
	this->exam = new Exam[GetSize()];
}

//Group::operator GroupUniver()
//{
//	GroupUniver groupUniver(Size());
//	groupUniver.PutExam(sizeArray, *exam);
//	return groupUniver;
//}
