#include <cstring>
#include "configs.h"
#pragma warning(disable : 4996)
using namespace std;


int Configs::GetSizeGroup()
{
    return this->SizeGroup;
}

void Configs::SetSizeGroup(int sizeGroup)
{
    this->SizeGroup = sizeGroup;
}

Configs Configs::operator=(Configs cfg)
{
    return cfg;
}

int Configs::GetNameLength()
{
    return this->nameLength;
}

void Configs::SetNameLength(int nameLength)
{
    this->nameLength = nameLength;
}

int Configs::GetCountGroup()
{
    return this->CountGroup;
}

void Configs::SetCountGroup(int CountGroup)
{
    this->CountGroup = CountGroup;
}

int Configs::GetMinGrade()
{
    return this->minGrade;
}

void Configs::SetMinGrade(int minGrade)
{
    this->minGrade = minGrade;
}

int Configs::GetMaxGrade()
{
    return this->maxGrade;
}

void Configs::SetMaxGrade(int maxGrade)
{
    this->maxGrade = maxGrade;
}

int Configs::GetMinDate()
{
    return this->minDate;
}

void Configs::SetMinDate(int minDate)
{
    this->minDate = minDate;
}

int Configs::GetMaxDate()
{
    return this->maxDate;
}

void Configs::SetMaxDate(int maxDate)
{
    this->maxDate = maxDate;
}

int Configs::GetStringLength()
{
    return this->stringLength;
}

void Configs::SetStringLength(int stringLength)
{
    this->stringLength = stringLength;
}

char* Configs::DefaultGlobalNullString()
{

    char* var_return = new char[100];
    strcpy(var_return, "Не указано");
    return var_return;
}

char* Configs::DefaultGlobalPrintNameStudent()
{
    char* var_return = new char[100];
    strcpy(var_return, "ФИО студента: ");
    return var_return;
}

char* Configs::DefaultGlobalPrintNameExaminer()
{
    char* var_return = new char[100];
    strcpy(var_return, "ФИО экзаменатора: ");
    return var_return;
}

char* Configs::DefaultGlobalPrintNameSubject()
{
    char* var_return = new char[100];
    strcpy(var_return, "Предмет: ");
    return var_return;
}

char* Configs::DefaultGlobalPrintDate()
{
    char* var_return = new char[100];
    strcpy(var_return, "Дата: ");
    return var_return;
}

char* Configs::DefaultGlobalPrintGrade()
{
    char* var_return = new char[100];
    strcpy(var_return, "Оценка: ");
    return var_return;
}

char* Configs::DefaultGlobalInputNameStudent()
{
    char* var_return = new char[100];
    strcpy(var_return, "Введите ФИО студента: ");
    return var_return;
}

char* Configs::DefaultGlobalInputNameExaminer()
{
    char* var_return = new char[100];
    strcpy(var_return, "Введите ФИО преподователя: ");
    return var_return;
}

char* Configs::DefaultGlobalInputNameSubject()
{
    char* var_return = new char[100];
    strcpy(var_return, "Введите предмет: ");
    return var_return;
}

char* Configs::DefaultGlobalInputDate()
{
    char* var_return = new char[100];
    strcpy(var_return, "Введите дату: ");
    return var_return;
}

char* Configs::DefaultGlobalInputGrade()
{
    char* var_return = new char[100];
    strcpy(var_return, "Введите оценку: ");
    return var_return;
}

char* Configs::DefaultGlobalInputError()
{
    char* var_return = new char[100];
    strcpy(var_return, "Ошибка ввода: ");
    return var_return;
}


