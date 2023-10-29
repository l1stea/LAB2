#pragma once
#include "exam.h"


class group
{
private:
	int size_array_;
	exam* exam_;
public:
	explicit group(int size_array); // Конструктор
	group();
	group(int size_array, exam* ex);
	explicit group(exam* exam);
	~group(); // Деструктор
	void print(); // Вывод группы объектов Exam в консоль
	void put_exam(int i, exam& ex); // Ввод ссылки на объект
	exam& get_exam(int i);// Выдача ссылки на i-ый объект Exam
	double get_grade(); // Возваращает среднюю оценку в группе
	double get_grade(int limit); // Возвращает среднюю оценку, которая не ниже limit
	exam& operator[](int i); // Перегрузка оператора индексации
	int get_size();
	void new_exam();
	bool save_size_array(int size_array);
	bool save_size_array();

};
