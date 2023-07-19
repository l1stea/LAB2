#include <cstring>
#include "configs.h"

using namespace std;


int Configs::GetSizeGroup()
{
    return this->SizeGroup;
}

Configs Configs::operator=(Configs cfg)
{
    return cfg;
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


