#pragma once
#include "groupUniver.h"
#include "configs.h"


class University
{
private:
	// Класс конфиги
	Configs cfg;
	// Счётчик групп
	int CountGroup = 0;
	// Наименование университета (указатель на char)
	char* Name;
	// двумерный динамический массив класса GroupUniver
	GroupUniver** group; 
	char* GetNameUniversity();
	int GetCountGroup();
	int GenerateId();
public:
	// Конструктор
	University();
	// Деструктор
	~University();
	void Print();
	// Получить наименование универститета
	char* GetName();
	// Задать количество групп
	void SetCountGroup(int countGroup);
	// Ввести группу (метод принимает псевдоним класса GroupUniver)
	void PutGroup(GroupUniver& groupUniver);
};

