#pragma once
#include <cstdint>

class Configs
{
public:
	// ��������� id � GroupUniver
	int IdGroupUniver = 0;
	// ����� ����� � Exam
	const int nameLength = 100;
	// ������ ������ � Unversity
	const int SizeGroup = 5;
	// ����������� ������ � Exam
	const int minGrade = 2;
	// ������������ ������ � Exam
	const int maxGrade = 5;
	// ����������� ���� � Exam
	const int minDate = 0;
	// ������������ ���� � Exam
	const int maxDate = INT32_MAX;

	// ���� ����� ������
	const int stringLength = 100;
	// ������ ������
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

public:
	int GetSizeGroup();
	// ���������� ��������� ������������
	Configs operator=(Configs i);
};


