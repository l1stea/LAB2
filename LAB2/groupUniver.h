#pragma once
#include "group.h"

class GroupUniver: Group
{
private:
	int id;
	int sizeArray = 0;
	Exam* exam;
public:
	// ��������������� ������������ � ���������� ����� �������
	GroupUniver(int sizeArray);
	int GetId();
	void SetId(int id);
	// ������������� �������������� �������
	Group::Print; 
	Group::Size;
	Group::PutExam; 
	//Exam& operator=(Exam i); // ���������� ��������� ����������

};

