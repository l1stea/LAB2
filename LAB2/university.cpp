#include "university.h"
#include <iostream>
#include "configs.h"
using namespace std;

University::University()
{
	srand(time(NULL));
	char namesStud[5][100] = { "�������� ������� ����������", "������� ����������� ���������", "������� ���� ����������",
		"���������� ������� �����������", "������ ������ ��������" };
	char namesExam[5][100] = { "����� ������� ����������", "������� ������� ���������", "������ ����� ������������",
		"�������� ������ ���������", "�������� ������ �����������" };
	char namesSub[5][100] = { "���", "�������������� ������", "������ �����������",
		"���������", "�������������� ������������" };

	this->Name = new char[100];
	Name = GetNameUniversityTUSUR();
	CountGroup = GetCountGroup();
	group = new GroupUniver*[CountGroup]; // C������c� ������ ��������, ��������� � ��������;
	for (int i = 0; i < CountGroup; i++)
	{
		group[i] = new GroupUniver(cfg.GetSizeGroup()); // C������c� ������ ��������, ��������� � ��������
		cfg.IdGroupUniver++;
		group[i]->SetId(cfg.IdGroupUniver);
		for (int j = 0; j < group[i]->Size(); j++)
		{
			Exam exam(namesStud[j], namesExam[j], namesSub[j], time(nullptr), 2 + rand() % (5 - 2 + 1));
			group[i]->PutExam(j, exam); // ������� ���������� ������� 
		}
		cout << "\n����� ������: " << group[i]->GetId() << endl;
		group[i]->Print();
	}
}

int University::GetCountGroup()
{
	return 5;
}

char* University::GetNameUniversityTUSUR()
{
	char* newstring = new char[100];
	strcpy(newstring, "�����");
	return newstring;
}

University::~University()
{
	delete Name;
	delete[] this->group;
}

void University::Print()
{
	cout << "������������ ����������: " << this->Name;
	//for (int i =0; i < GetCountGroup(); i++)
	//{

	//}
	//this->group.Print();
}

char* University::GetName()
{
	return this->Name;
}

void University::SetCountGroup(int countGroup)
{
	this->CountGroup = countGroup;
}
