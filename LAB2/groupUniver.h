#pragma once
#include "group.h"

class GroupUniver: Group
{
private:
	int id = 0;
public:
	// Переопределение конструктора и добавление новых функций
	GroupUniver(int sizeArray);
	int GetId();
	void SetId(int id);
	// Использование унаследованных функций
	Group::Print; 
	Group::Size;
	Group::PutExam; 
	Group::Grade;
	Group::GetExam;
	Group::operator[];
	//Exam& operator=(Exam i); // Перегрузка оператора индексации
};

