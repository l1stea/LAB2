// ReSharper disable CommentTypo
#include "group.h"
#include <iostream>

using namespace std;


// Не должно быть вводимых данных
group::group(const int size_array)
{
	cout << "Group конструктор вызван" << endl;
	this->size_array_ = size_array;
	this->exam_ = new exam[size_array]; // динамическое выделение памяти
}

group::group()
{
	static constexpr int const_size_array = 1;
	size_array_ = const_size_array;
	this->exam_ = new exam[const_size_array]; // динамическое выделение памяти
}

group::group(const int size_array, exam* exam)
{
	//this->sizeArray = sizeArray;
	this->exam_ = exam;
	int count = 0;
	for (int i = 0; i < size_array; i++)
	{
		try
		{
			exam[i];  // NOLINT(clang-diagnostic-unused-value)
			count++;
		}
		catch (...)
		{
			cout << "\nНекорректно введен индекс" << endl;
		}
	}
	this->size_array_ = size_array;
}

group::group(exam* exam)
{
	this->exam_ = exam;
}

group::~group()
{
	cout << "Group деструктор вызван." << endl;
	delete[] exam_; // Освобождение памяти и вызов деструктора для каждого элемента массива
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
			cout << "\nОшибка вывода!";
		}
	}
}


void group::put_exam(const int i, const exam& ex) const
{
	if (i < 0 || i >= this->size_array_)
	{
		cout << "\nНекорректный индекс для ввода объекта Exam. Ввод не выполнен." << endl;
		return;
	}
	exam_[i] = ex;
}

exam& group::get_exam(const int i) const
{
	if (i < 0 || i >= this->size_array_)
	{
		cout << "\nНекорректный индекс для вывода объекта Exam. Вывод адреса объекта Exam без параметров." << endl;
		const auto ex = new exam();
		return *ex;
	}
	return exam_[i];
}

double group::get_grade() const
{
	int sum = 0;
	for (int i = 0; i < size_array_; i++)
	{
		try
		{
			sum += exam_[i].get_grade();
		}
		catch (...)
		{
			cout << "Ошибка при подсчёте суммы!";
		}
	}
	return sum * 1.0 / size_array_;
}

double group::get_grade(const int limit) const
{
	int sum = 0;
	int count = 0; // Счётчик чисел
	for (int i = 0; i < size_array_; i++)
	{
		try
		{
			const int grade = exam_[i].get_grade();
			if (grade >= limit)
			{
				count++;
				sum += grade;
			}
		}
		catch (...)
		{
			cout << "Ошибка при подсчёте суммы!";
		}
	}
	return sum * 1.0 / count;
}

exam& group::operator[](const int i) const
{
	if (i < 0 || this->size_array_ <= i)
	{
		cout << "Некорректный индекс группы! Возвращается ссылка на объект Exam,";
		cout << "созданным с помощью конструктора без парамтеров." << endl;
		const auto ex = new exam();
		return *ex;
	}
	return get_exam(i);
}

void group::set_size(const int size_array)
{
	this->size_array_ = size_array;
}

int group::get_size() const
{
	return this->size_array_;
}

void group::new_exam()
{
	this->exam_ = new exam[get_size()];
}
