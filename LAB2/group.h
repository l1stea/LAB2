#pragma once
#include "exam.h"


class group
{
private:
	int size_array_;
	exam* exam_;
public:
	group(int size_array); // Конструктор
	group();
	group(int size_array, exam* ex);
	group(exam* exam);
	~group(); // Деструктор
	void print() const; // Вывод группы объектов Exam в консоль
	void put_exam(int i,const exam& ex); // Ввод ссылки на объект
	exam& get_exam(int i) const;// Выдача ссылки на i-ый объект Exam
	double get_grade() const; // Возваращает среднюю оценку в группе
	double get_grade(int limit) const; // Возвращает среднюю оценку, которая не ниже limit
	exam& operator[](int i); // Перегрузка оператора индексации
	int get_size() const;
	void new_exam();
};