#pragma once
#include "group.h"

class GroupUniver: Group
{
private:
	int id = 0;
public:
	// ��������������� ������������ � ���������� ����� �������
	GroupUniver(int sizeArray);
	int GetId();
	void SetId(int id);
	// ������������� �������������� �������
	Group::Print; 
	Group::Size;
	Group::PutExam; 
	Group::Grade;
	Group::GetExam;
	Group::operator[];
	//Exam& operator=(Exam i); // ���������� ��������� ����������
};

