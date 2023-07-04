#pragma once
#include "group.h"

class GroupUniver: Group
{
private:
	int id;
	int sizeArray = 0;
	Exam* exam;
public:
	// Переопределение конструктора и добавление новых функций
	GroupUniver(int sizeArray);
	int GetId();
	void SetId(int id);
	// Использование унаследованных функций
	Group::Print; 
	Group::Size;
	Group::PutExam; 
	//Exam& operator=(Exam i); // Перегрузка оператора индексации

};

