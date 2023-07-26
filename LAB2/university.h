#pragma once
#include "groupUniver.h"
#include "configs.h"


class University
{
private:
	// ����� �������
	Configs cfg;
	// ������� �����
	int countGroup = 0;
	// ������������ ������������ (��������� �� char)
	char* name;
	// ��������� ������������ ������ (��������� �� ���������) ������ GroupUniver ����� ��� ����, ����� ������� ��������� �����
	GroupUniver** groups; 
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

	void SetName(char* name);

	GroupUniver** GetGroup();
	void SetGroup(GroupUniver** group);
};

