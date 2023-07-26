#include "group.h"
#include <iostream>
#include "groupUniver.h"

using namespace std;


Group::Group(int sizeArray)
{
	cout << "Group ����������� ������" << endl;
	while (sizeArray<1)
	{
		cout << "������ ������ ������ ���� ������ 0 � ������ 2 147 483 647. ������� �����:\n";
		cin >> sizeArray;
		if (cin.fail()) {
			cin.clear();
			cin.ignore((numeric_limits<streamsize>::max)(), '\n');
		}
		
	}
	this->sizeArray = sizeArray;
	this->exam = new Exam[sizeArray]; // new - ������������ ��������� ������
}

Group::Group()
{

	static const int constSizeArray = 2;
	sizeArray = constSizeArray;
	this->exam = new Exam[constSizeArray]; // ������������ ��������� ������
	Exam examStat[constSizeArray]; // ����������� ��������� ������
}

Group::Group(int sizeArray, Exam* exam)
{
	//this->sizeArray = sizeArray;
	this->exam = exam;
	int count = 0;
	for (int i = 0; i < sizeArray; i++)
	{
		try
		{
			exam[i];
			count++;
		}
		catch (...)
		{
			cout << "\n����������� ������ ������" << endl;
		}
	}
	this->sizeArray = sizeArray;
}

Group::Group(Exam* exam)
{
	this->exam = exam;
}

Group::~Group()
{
	cout << "Group ���������� ������" << endl;
	delete[] exam; // ������������ ������ � ����� ����������� ��� ������� �������� �������
}

void Group::Print()
{
	for (int i = 0; i < sizeArray; i++)
	{
		try {
			exam[i].Print();
		}
		catch (...)
		{
			cout << "\n������ ������!";
		}
	}
}


void Group::PutExam(int i, Exam& exam)
{
	if (i < 0 || i >= this->sizeArray)
	{
		cout << "\n������������ ������ ��� ����� ������� Exam. ���� �� ��������." << endl;
		return;
	}
	this->exam[i] = exam;
}

Exam& Group::GetExam(int i)
{
	if (i < 0 || i >= this->sizeArray)
	{
		cout << "\n������������ ������ ��� ������ ������� Exam. ����� ������ ������� Exam ��� ����������." << endl;
		Exam* exam = new Exam();
		return *exam;
	}
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
			cout << "������ ��� �������� �����!";
		}
	}
	return summ * 1.0 / sizeArray;
}

double Group::Grade(int limit)
{
	int summ = 0;
	int count = 0; // ������� �����
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
			cout << "������ ��� �������� �����!";
		}
	}
	return summ * 1.0 / count;
}

Exam& Group::operator[](int i)
{
	if (i < 0 || this->sizeArray <= i)
	{
		cout << "������������ ������ ������! ������������ ������ �� ������ Exam,";
		cout << "��������� � ������� ������������ ��� ����������." << endl;
		Exam* exam = new Exam();
		return *exam;
	}
	return GetExam(i);
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
