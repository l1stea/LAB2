// ReSharper disable CommentTypo
#pragma once
#include "exam.h"


class group
{
	int size_array_ = 0;
	exam* exam_;
public:
	explicit group(int size_array); // Конструктор
	// Добавлены варианты создания объекта;
	// ReSharper restore CommentTypo
	group();
	group(int size_array, exam* exam);
	explicit group(exam* exam);
	~group(); // Деструктор
	// ReSharper disable CommentTypo
	void print() const; // Вывод группы объектов Exam в консоль
	void put_exam(int i, const exam& ex) const; // Ввод ссылки на объект
	exam& get_exam(int i) const;// Выдача ссылки на i-ый объект Exam
	double get_grade() const; // Возваращает среднюю оценку в группе
	double get_grade(int limit) const; // Возвращает среднюю оценку, которая не ниже limit
	exam& operator[](int i) const; // Перегрузка оператора индексации
	int get_size() const;
	void set_size(int size_array);
	void new_exam();
	//operator GroupUniver();
	//operator GroupUniver(); // оператор приведения типа Group в GroupUniver
};
