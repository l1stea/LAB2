#pragma once
#include <cstdint>

class Configs
{
public:
	const int minGrade = 2;
	const int maxGrade = 5;
	const int minDate = 0;
	const int maxDate = INT32_MAX;

	const int stringLength = 100;
	const char* globalNullString = "�� �������";

	const char* globalNameStudent = globalNullString;
	const char* globalNameExaminer = globalNullString;


	const char* globalNameSubject = globalNullString;


	const char* globalPrintNameStudent = "��� ��������: ";
	const char* globalPrintNameExaminer = "��� ������������: ";
	const char* globalPrintNameSubject = "�������: ";
	const char* globalPrintDate = "����: ";
	const char* globalPrintGrade = "������: ";

	const char*  globalInputNameStudent = "������� ��� ��������: ";
	const char* globalInputNameExaminer = "������� ��� �������������: ";
	const char* globalInputNameSubject = "������� �������: ";
	const char* globalInputDate = "������� ����: ";
	const char* globalInputGrade = "������� ������: ";

	const char*  globalInputError = "������ �����: ";
};


