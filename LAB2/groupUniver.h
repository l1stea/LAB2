#pragma once
#include "group.h"

class GroupUniver: Group
{
private:
	int id = 0;
public:
	GroupUniver();
	// ����������� ������ GroupUniver � ���������� ����� �������
	GroupUniver(int sizeArray);
	~GroupUniver();
	int GetId();
	void SetId(int id);
	// ������������� �������������� �������
	Group::Print; 
	Group::GetSize;
	Group::PutExam; 
	Group::GetGrade;
	Group::GetExam;
	Group::operator[];
};

