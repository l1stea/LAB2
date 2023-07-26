#pragma once
#include <cstdint>

class Configs
{
public:
	// ���������� ����� � GroupUniver
	int CountGroup = 3;
	// ����� ����� � Exam
	int nameLength = 100;
	// ������ ������ � Unversity
	int SizeGroup = 5;
	// ����������� ������ � Exam
	int minGrade = 2;
	// ������������ ������ � Exam
	int maxGrade = 5;
	// ����������� ���� � Exam
	int minDate = 0;
	// ������������ ���� � Exam
	int maxDate = INT32_MAX;

	// ���� ����� ������
	int stringLength = 100;
	// ������ ������
	// char* globalNullString = "�� �������";
	char* globalNullString = DefaultGlobalNullString();
	char* globalNameStudent = DefaultGlobalNullString();
	char* globalNameExaminer = DefaultGlobalNullString();
	char* globalNameSubject = DefaultGlobalNullString();


	//const char* globalPrintNameStudent = "��� ��������: ";
	//const char* globalPrintNameExaminer = "��� ������������: ";
	//const char* globalPrintNameSubject = "�������: ";
	//const char* globalPrintDate = "����: ";
	//const char* globalPrintGrade = "������: ";

	//const char* globalInputNameStudent = "������� ��� ��������: ";
	//const char* globalInputNameExaminer = "������� ��� �������������: ";
	//const char* globalInputNameSubject = "������� �������: ";
	//const char* globalInputDate = "������� ����: ";
	//const char* globalInputGrade = "������� ������: ";

	//const char* globalInputError = "������ �����: ";
	char* globalPrintNameStudent = DefaultGlobalPrintNameStudent();
	char* globalPrintNameExaminer = DefaultGlobalPrintNameExaminer();
	char* globalPrintNameSubject = DefaultGlobalPrintNameSubject();
	char* globalPrintDate = DefaultGlobalPrintDate();
	char* globalPrintGrade = DefaultGlobalPrintGrade();

	char* globalInputNameStudent = DefaultGlobalInputNameStudent();
	char* globalInputNameExaminer = DefaultGlobalInputNameExaminer();
	char* globalInputNameSubject = DefaultGlobalInputNameSubject();
	char* globalInputDate = DefaultGlobalInputDate();
	char* globalInputGrade = DefaultGlobalInputGrade();

	char* globalInputError = DefaultGlobalInputError();

	char* DefaultGlobalNullString();
	char* DefaultGlobalPrintNameStudent();
	char* DefaultGlobalPrintNameExaminer();
	char* DefaultGlobalPrintNameSubject();
	char* DefaultGlobalPrintDate();
	char* DefaultGlobalPrintGrade();
	char* DefaultGlobalInputNameStudent();
	char* DefaultGlobalInputNameExaminer();
	char* DefaultGlobalInputNameSubject();
	char* DefaultGlobalInputDate();
	char* DefaultGlobalInputGrade();
	char* DefaultGlobalInputError();

public:

	int GetSizeGroup();
	void SetSizeGroup(int sizeGroup);
	// ���������� ��������� ������������
	Configs operator=(Configs i);

	int GetNameLength();
	void SetNameLength(int nameLength);

	int GetCountGroup();
	void SetCountGroup(int CountGroup);

	int GetMinGrade();
	void SetMinGrade(int minGrade);

	int GetMaxGrade();
	void SetMaxGrade(int maxGrade);

	int GetMinDate();
	void SetMinDate(int minDate);

	int GetMaxDate();
	void SetMaxDate(int maxDate);

	int GetStringLength();
	void SetStringLength(int stringLength);


};


