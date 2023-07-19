#include "university.h"
#include <iostream>
#include "configs.h"
using namespace std;

University::University()
{
	cout << "University ������ ����������� ������" << endl;
	Name = GetNameUniversity();
	// ���������� ����� ��� ��������� ���������� �����
	group = new GroupUniver * [cfg.CountGroup]; 
}


University::University(char* name, int countGroup)
{
	cout << "University ����������� ������" << endl;
	Name = name;
	// ���������� ����� ��� ��������� ���������� �����
	group = new GroupUniver * [countGroup];
}


University::~University()
{
	cout << "University ���������� ������" << endl;
	delete this->Name;
	//for (int i = 0; i < GetCountGroup(); i++)
	//{
	//	delete[] group[i];
	//}
	delete[] group;
}


int University::GetCountGroup()
{
	return this->CountGroup;
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
	cout << "\n������������ ����������: " << this->Name;
	for (int i = 0; i < GetCountGroup(); i++)
	{
		cout << "\n����� ������: " << group[i]->GetId() << endl;
		group[i]->Print();
	}
}


char* University::GetName()
{
	return this->Name;
}


void University::SetCountGroup(int countGroup)
{
	this->CountGroup = countGroup;
}


void University::PutGroup(GroupUniver& groupUniver)
{
	group[GetCountGroup()] = new GroupUniver(groupUniver.GetSize());
	for (int i = 0; i < group[GetCountGroup()]->GetSize(); i++)
	{
		group[GetCountGroup()]->PutExam(i, groupUniver[i]);
	}
	group[GetCountGroup()]->SetId(GenerateId());
	CountGroup++;
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
	this->Name = name; 
}

GroupUniver** University::GetGroup()
{
	return this->group;
}

void University::SetGroup(GroupUniver** group)
{
	this->group = group;
}
