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
    strcpy(var_return, "�� �������");
    return var_return;
}

char* Configs::DefaultGlobalPrintNameStudent()
{
    char* var_return = new char[100];
    strcpy(var_return, "��� ��������: ");
    return var_return;
}

char* Configs::DefaultGlobalPrintNameExaminer()
{
    char* var_return = new char[100];
    strcpy(var_return, "��� ������������: ");
    return var_return;
}

char* Configs::DefaultGlobalPrintNameSubject()
{
    char* var_return = new char[100];
    strcpy(var_return, "�������: ");
    return var_return;
}

char* Configs::DefaultGlobalPrintDate()
{
    char* var_return = new char[100];
    strcpy(var_return, "����: ");
    return var_return;
}

char* Configs::DefaultGlobalPrintGrade()
{
    char* var_return = new char[100];
    strcpy(var_return, "������: ");
    return var_return;
}

char* Configs::DefaultGlobalInputNameStudent()
{
    char* var_return = new char[100];
    strcpy(var_return, "������� ��� ��������: ");
    return var_return;
}

char* Configs::DefaultGlobalInputNameExaminer()
{
    char* var_return = new char[100];
    strcpy(var_return, "������� ��� �������������: ");
    return var_return;
}

char* Configs::DefaultGlobalInputNameSubject()
{
    char* var_return = new char[100];
    strcpy(var_return, "������� �������: ");
    return var_return;
}

char* Configs::DefaultGlobalInputDate()
{
    char* var_return = new char[100];
    strcpy(var_return, "������� ����: ");
    return var_return;
}

char* Configs::DefaultGlobalInputGrade()
{
    char* var_return = new char[100];
    strcpy(var_return, "������� ������: ");
    return var_return;
}

char* Configs::DefaultGlobalInputError()
{
    char* var_return = new char[100];
    strcpy(var_return, "������ �����: ");
    return var_return;
}


