#pragma once
#include "group.h"

class GroupUniver: Group
{
private:
	int id = 0;
public:
	GroupUniver();
	// Конструктор класса GroupUniver и добавление новых функций
	GroupUniver(int sizeArray);
	~GroupUniver();
	int GetId();
	void SetId(int id);
	// Использование унаследованных функций
	Group::Print; 
	Group::GetSize;
	Group::PutExam; 
	Group::GetGrade;
	Group::GetExam;
	Group::operator[];
};

