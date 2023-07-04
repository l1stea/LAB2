#pragma once
#include "groupUniver.h"
#include "configs.h"


class University
{
private:
	Configs cfg;
	int CountGroup;
	char* Name;
	// ��������� ������������ ������ ������ GroupUniver
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

