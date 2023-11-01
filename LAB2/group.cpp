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
		this->exam_ = new exam[get_size()](); // ������������ ��������� ������
	}
	catch (string message)
	{
		cout << message << endl;
	}
}


group::group(): size_array_(1), exam_(new exam[get_size()]())
{}


group::group(int size_array,exam* ex): size_array_(size_array), exam_(new exam[get_size()]())
{
	try {
		for (int i = 0; i < size_array; i++)
		{
			exam_[i] = ex[i];
		}
	}
	catch (string message)  // NOLINT(misc-throw-by-value-catch-by-reference)
	{
		cout << message << endl;
	}
}


group::group(exam* exam): size_array_(1)
{
	exam_ = exam;
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

void group::print() const
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


void group::put_exam(int i,const exam& ex)
{
	if (i < 0 || i >= this->size_array_)
	{
		cout << "\n������������ ������ ��� ����� ������� Exam. ���� �� ��������." << endl;
		return;
	}
	//exam_[i] = ex;
	//exam_[i].set_cfg(ex.get_cfg());
	exam_[i].set_date(ex.get_date());
	exam_[i].set_grade(ex.get_grade());
	if (exam_->get_name_length() == ex.get_name_length())
	{
		exam_[i].set_name_examiner(ex.get_name_examiner());
		exam_[i].set_name_student(ex.get_name_student());
		exam_[i].set_name_subject(ex.get_name_subject());
	}
	else {
		string message = "\n���������� ������� �� ��������� �� �����!\n";
		throw message;
	}
}

exam& group::get_exam(int i) const
{
	if (i < 0 || i >= this->size_array_)
	{
		cout << "\n������������ ������ ��� ������ ������� Exam. ����� ������ ������� Exam ��� ����������." << endl;
		auto ex = new exam();
		return *ex;
	}
	return exam_[i];
}

double group::get_grade() const
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

double group::get_grade(int limit) const
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

int group::get_size() const
{
	return this->size_array_;
}

void group::new_exam()
{
	this->exam_ = new exam[get_size()];
}
