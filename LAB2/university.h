#pragma once
#include "groupUniver.h"
#include "configs.h"


class University
{
private:
	Configs cfg;
	int CountGroup;
	char* Name;
	// двумерный динамический массив класса GroupUniver
	GroupUniver** group; 
	char* GetNameUniversityTUSUR();
	int GetCountGroup();
public:
	University();
	~University();
	void Print();
	char* GetName();
	void SetCountGroup(int countGroup);
};

