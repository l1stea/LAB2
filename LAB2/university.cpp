#include "university.h"
#include <iostream>
#include "configs.h"
#pragma warning(disable : 4996)
using namespace std;

University::University()
{
	cout << "University ��� ���������� ����������� ������" << endl;
	name = GetNameUniversity();
	// ���������� ����� ��� ��������� ���������� ����� � ��������
	groups = new GroupUniver * [cfg.CountGroup]; 
}


University::University(char* name, int countGroup)
{
	cout << "University ����������� ������" << endl;
	name = name;
	// ���������� ����� ��� ��������� ���������� �����
	groups = new GroupUniver * [countGroup];
}


University::~University()
{
	cout << "University ���������� ������" << endl;
	delete this->name;
	//for (int i = 0; i < GetCountGroup(); i++)
	//{
	//	delete[] groups[i];
	//} 
	delete[] groups;
}


int University::GetCountGroup()
{
	return this->countGroup;
}


int University::GenerateId()
{
	return GetCountGroup() + 1;
}


char* University::GetNameUniversity()
{
	char* newstring = new char[100];
	strcpy(newstring, "�����");
	return newstring;
}


void University::Print()
{
	cout << "\n������������ ����������: " << this->name;
	for (int i = 0; i < GetCountGroup(); i++)
	{
		cout << "\n����� ������: " << groups[i]->GetId() << endl;
		groups[i]->Print();
	}
}


char* University::GetName()
{
	return this->name;
}


void University::SetCountGroup(int countGroup)
{
	this->countGroup = countGroup;
}


void University::PutGroup(GroupUniver& groupUniver)
{
	groups[GetCountGroup()] = new GroupUniver(groupUniver.GetSize());
	for (int i = 0; i < groups[GetCountGroup()]->GetSize(); i++)
	{
		groups[GetCountGroup()]->PutExam(i, groupUniver[i]);
	}
	groups[GetCountGroup()]->SetId(GenerateId());
	countGroup++;
}

Configs University::GetCfg()
{
	return this->cfg;
}

void University::SetCfg(Configs cfg)
{
	this->cfg = cfg;
}

void University::SetName(char* name)
{
	this->name = name;
}

GroupUniver** University::GetGroup()
{
	return this->groups;
}

void University::SetGroup(GroupUniver** group)
{
	this->groups = group;
}
