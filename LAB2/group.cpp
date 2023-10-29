// ReSharper disable CommentTypo
#include "group.h"
#include <iostream>
#include <set>

using namespace std;



// Не должно быть вводимых данных
group::group(int size_array): size_array_(size_array)
{
	try
	{
		string message = "Ошибка: количество должно быть больше 0!";
		if (size_array <= 0)
			throw message;
		cout << "Вызван конструктор group" << endl;
		//set_size(size_array);
		this->exam_ = new exam[get_size()]; // динамическое выделение памяти
	}
	catch (string message)  // NOLINT(misc-throw-by-value-catch-by-reference)
	{
		cout << message << endl;
	}
}


group::group(): size_array_(1)
{
	//set_size(1);	
	this->exam_ = new exam[get_size()]; // динамическое выделение памяти
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
		cout << "Вызван деструктор group." << endl;
		delete[] exam_; // Освобождение памяти и вызов деструктора для каждого элемента массива
	}
	catch (...)
	{
		cout << "Ошибка при вызове деструктора!";
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
			cout << "\nОшибка вывода!";
		}
	}
}


void group::put_exam(int i, exam& ex)
{
	if (i < 0 || i >= this->size_array_)
	{
		cout << "\nНекорректный индекс для ввода объекта Exam. Ввод не выполнен." << endl;
		return;
	}
	exam_[i] = ex;
}

exam& group::get_exam(int i)
{
	if (i < 0 || i >= this->size_array_)
	{
		cout << "\nНекорректный индекс для вывода объекта Exam. Вывод адреса объекта Exam без параметров." << endl;
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
		cout << "Ошибка при подсчёте суммы!";
		sum = 0;
	}
	return sum * 1.0 / size_array_;
}

double group::get_grade(int limit)
{
	int sum = 0;
	int count = 0; // Счётчик чисел
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
		cout << "Ошибка при подсчёте суммы!";
		sum = 0;
	}
	return sum * 1.0 / count;
}

exam& group::operator[](int i)
{
	if (i < 0 || this->size_array_ <= i)
	{
		cout << "Некорректный индекс группы! Возвращается ссылка на объект Exam,";
		cout << "созданным с помощью конструктора без парамтеров." << endl;
		auto ex = new exam();
		return *ex;
	}
	return get_exam(i);
}

//void group::set_size(const int size_array)
//{
//	if (size_array <= 0)
//	{
//		string message = "Неверный инддекс! Индекс должен быть больше 0!";
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
