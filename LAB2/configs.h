#pragma once
#include <cstdint>
const int minGrade = 2;
const int maxGrade = 5;
const int minDate = 0;
const int maxDate = INT32_MAX;

const int stringLength = 100;
extern char globalNullString[stringLength] = "�� �������";

char* globalNameStudent = globalNullString;
char* globalNameExaminer = globalNullString;
char* globalNameSubject = globalNullString;


char globalPrintNameStudent[stringLength] = "��� ��������: ";
char globalPrintNameExaminer[stringLength] = "��� ������������: ";
char globalPrintNameSubject[stringLength] = "�������: ";
char globalPrintDate[stringLength] = "����: ";
char globalPrintGrade[stringLength] = "������: ";

char globalInputNameStudent[stringLength] = "������� ��� ��������: ";
char globalInputNameExaminer[stringLength] = "������� ��� �������������: ";
char globalInputNameSubject[stringLength] = "������� �������: ";
char globalInputDate[stringLength] = "������� ����: ";
char globalInputGrade[stringLength] = "������� ������: ";

char globalInputError[stringLength] = "������ �����: ";


class Configs
{

};


