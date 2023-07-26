#pragma once
#include "groupUniver.h"
#include "configs.h"


class University
{
private:
	// Класс конфиги
	Configs cfg;
	// Счётчик групп
	int countGroup = 0;
	// Наименование университета (указатель на char)
	char* name;
	// двумерный динамический массив (указатель на указатель) класса GroupUniver нужен для того, чтобы хранить несколько групп
	GroupUniver** groups; 
	char* GetNameUniversity();
	int GetCountGroup();
	int GenerateId();
public:
	// Конструктор
	University();
	University(char* name, int countGroup);
	// Деструктор
	~University();
	void Print();
	// Получить наименование универститета
	char* GetName();
	// Задать количество групп
	void SetCountGroup(int countGroup);
	// Ввести группу (метод принимает псевдоним класса GroupUniver)
	void PutGroup(GroupUniver& groupUniver);

	// Чтение и запись полей
	Configs GetCfg();
	void SetCfg(Configs cfg);

	void SetName(char* name);

	GroupUniver** GetGroup();
	void SetGroup(GroupUniver** group);
};

