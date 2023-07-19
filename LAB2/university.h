#pragma once
#include "groupUniver.h"
#include "configs.h"


class University
{
private:
	// ����� �������
	Configs cfg;
	// ������� �����
	int CountGroup = 0;
	// ������������ ������������ (��������� �� char)
	char* Name;
	// ��������� ������������ ������ ������ GroupUniver
	GroupUniver** group; 
	char* GetNameUniversity();
	int GetCountGroup();
	int GenerateId();
public:
	// �����������
	University();
	University(char* name, int countGroup);
	// ����������
	~University();
	void Print();
	// �������� ������������ �������������
	char* GetName();
	// ������ ���������� �����
	void SetCountGroup(int countGroup);
	// ������ ������ (����� ��������� ��������� ������ GroupUniver)
	void PutGroup(GroupUniver& groupUniver);

	// ������ � ������ �����
	Configs GetCfg();
	void SetCfg(Configs cfg);

	//int GetCountGroup();
	//void SetCountGroup(int countGroup);

	void SetName(char* name);

	GroupUniver** GetGroup();
	void SetGroup(GroupUniver** group);
};

