#include "university.h"
#include <iostream>
#include "configs.h"
using namespace std;

University::University()
{
	Name = GetNameUniversity();
	// Выделяется место под указанное количество групп
	group = new GroupUniver * [cfg.CountGroup]; 
}


University::~University()
{
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
	strcpy(newstring, "ТУСУР");
	return newstring;
}


void University::Print()
{
	cout << "\nНаименование учреждения: " << this->Name;
	for (int i = 0; i < GetCountGroup(); i++)
	{
		cout << "\nНомер группы: " << group[i]->GetId() << endl;
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
	group[GetCountGroup()] = new GroupUniver(groupUniver.Size());
	for (int i = 0; i < group[GetCountGroup()]->Size(); i++)
	{
		group[GetCountGroup()]->PutExam(i, groupUniver[i]);
	}
	group[GetCountGroup()]->SetId(GenerateId());
	CountGroup++;
}
