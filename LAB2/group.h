#pragma once
#include "exam.h"


class Group
{
private:
	int sizeArray = 0;
	Exam* exam;	
public:
	Group(int sizeArray); // Конструктор
	// Добавлены варианты создания объекта;
	Group();
	Group(int sizeArray, Exam* exam);
	Group(Exam* exam);
	~Group(); // Деструктор
	void Print(); // Вывод группы объектов Exam в консоль
	void PutExam(int i, Exam& exam); // Ввод ссылки на объект
	Exam& GetExam(int i); // Выдача ссылки на i-ый объект Exam
	double Grade(); // Возваращает среднюю оценку в группе
	double Grade(int limit); // Возвращает среднюю оценку, которая не ниже limit
	Exam& operator[](int i); // Перегрузка оператора индексации
	int GetSize();
	void SetSize(int sizeArray);
	void NewExam();
	//operator GroupUniver();
	//operator GroupUniver(); // оператор приведения типа Group в GroupUniver
};