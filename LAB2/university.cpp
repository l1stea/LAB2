#include "university.h"
#include <iostream>
#include "configs.h"
using namespace std;

University::University()
{
	srand(time(NULL));
	char namesStud[5][100] = { "Горбунов Парамон Платонович", "Морозов Максимилиан Федорович", "Тарасов Эрик Лукьянович",
		"Калашников Дмитрий Рудольфович", "Рожков Адольф Егорович" };
	char namesExam[5][100] = { "Жуков Емельян Дмитрьевич", "Сазонов Леонард Никитевич", "Жданов Архип Владимирович",
		"Зиновьев Эльдар Филатович", "Кудряшов Лазарь Геннадиевич" };
	char namesSub[5][100] = { "ООП", "Математический анализ", "Теория вероятности",
		"Философия", "Информационная безопасность" };

	this->Name = new char[100];
	Name = GetNameUniversityTUSUR();
	CountGroup = GetCountGroup();
	group = new GroupUniver*[CountGroup]; // Cоздаетcя группа размером, указанным в конфигах;
	for (int i = 0; i < CountGroup; i++)
	{
		group[i] = new GroupUniver(cfg.GetSizeGroup()); // Cоздаетcя группа размером, указанным в конфигах
		cfg.IdGroupUniver++;
		group[i]->SetId(cfg.IdGroupUniver);
		for (int j = 0; j < group[i]->Size(); j++)
		{
			Exam exam(namesStud[j], namesExam[j], namesSub[j], time(nullptr), 2 + rand() % (5 - 2 + 1));
			group[i]->PutExam(j, exam); // Функция заполнения массива 
		}
		cout << "\nНомер группы: " << group[i]->GetId() << endl;
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
	strcpy(newstring, "ТУСУР");
	return newstring;
}

University::~University()
{
	delete Name;
	delete[] this->group;
}

void University::Print()
{
	cout << "Наименование учреждения: " << this->Name;
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
