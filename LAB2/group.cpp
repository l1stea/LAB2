// ReSharper disable CommentTypo
#include "group.h"
#include <iostream>
#include <set>

using namespace std;



// �� ������ ���� �������� ������
group::group(int size_array): size_array_(size_array)
{
	try
	{
		string message = "������: ���������� ������ ���� ������ 0!";
		if (size_array <= 0)
			throw message;
		cout << "������ ����������� group" << endl;
		//set_size(size_array);
		this->exam_ = new exam[get_size()]; // ������������ ��������� ������
	}
	catch (string message)  // NOLINT(misc-throw-by-value-catch-by-reference)
	{
		cout << message << endl;
	}
}


group::group(): size_array_(1)
{
	//set_size(1);	
	this->exam_ = new exam[get_size()]; // ������������ ��������� ������
}


group::group(int size_array, exam* ex): size_array_(size_array)
{
	try {
		this->exam_ = ex;
		int count = 0;		
		//set_size(size_array);
	}
	catch (string message)  // NOLINT(misc-throw-by-value-catch-by-reference)
	{
		cout << message << endl;
		/*set_size(1);*/
	}
}


group::group(exam* exam): size_array_(1)
{
	this->exam_ = exam;
}



group::~group()
{
	try
	{
		cout << "������ ���������� group." << endl;
		delete[] exam_; // ������������ ������ � ����� ����������� ��� ������� �������� �������
	}
	catch (...)
	{
		cout << "������ ��� ������ �����������!";
	}
}

void group::print()
{
	for (int i = 0; i < size_array_; i++)
	{
		try {
			exam_[i].print();
		}
		catch (...)
		{
			cout << "\n������ ������!";
		}
	}
}


void group::put_exam(int i, exam& ex)
{
	if (i < 0 || i >= this->size_array_)
	{
		cout << "\n������������ ������ ��� ����� ������� Exam. ���� �� ��������." << endl;
		return;
	}
	exam_[i] = ex;
}

exam& group::get_exam(int i)
{
	if (i < 0 || i >= this->size_array_)
	{
		cout << "\n������������ ������ ��� ������ ������� Exam. ����� ������ ������� Exam ��� ����������." << endl;
		auto ex = new exam();
		return *ex;
	}
	return exam_[i];
}

double group::get_grade()
{
	int sum = 0;
	try
	{
		for (int i = 0; i < size_array_; i++)
		{
			sum += exam_[i].get_grade();
		}
	}
	catch (...)
	{
		cout << "������ ��� �������� �����!";
		sum = 0;
	}
	return sum * 1.0 / size_array_;
}

double group::get_grade(int limit)
{
	int sum = 0;
	int count = 0; // ������� �����
	try
	{
		for (int i = 0; i < size_array_; i++)
		{
			if (int grade = exam_[i].get_grade(); grade >= limit)
			{
				count++;
				sum += grade;
			}
		}
	}
	catch (...)
	{
		cout << "������ ��� �������� �����!";
		sum = 0;
	}
	return sum * 1.0 / count;
}

exam& group::operator[](int i)
{
	if (i < 0 || this->size_array_ <= i)
	{
		cout << "������������ ������ ������! ������������ ������ �� ������ Exam,";
		cout << "��������� � ������� ������������ ��� ����������." << endl;
		auto ex = new exam();
		return *ex;
	}
	return get_exam(i);
}

//void group::set_size(const int size_array)
//{
//	if (size_array <= 0)
//	{
//		string message = "�������� �������! ������ ������ ���� ������ 0!";
//		throw message;  // NOLINT(misc-throw-by-value-catch-by-reference, hicpp-exception-baseclass)
//	}
//	this->size_array_ = size_array;
//}

int group::get_size()
{
	return this->size_array_;
}

void group::new_exam()
{
	this->exam_ = new exam[get_size()];
}
