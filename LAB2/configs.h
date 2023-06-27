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
	const char* globalNullString = "Не указано";

	const char* globalNameStudent = globalNullString;
	const char* globalNameExaminer = globalNullString;


	const char* globalNameSubject = globalNullString;


	const char* globalPrintNameStudent = "ФИО студента: ";
	const char* globalPrintNameExaminer = "ФИО экзаменатора: ";
	const char* globalPrintNameSubject = "Предмет: ";
	const char* globalPrintDate = "Дата: ";
	const char* globalPrintGrade = "Оценка: ";

	const char*  globalInputNameStudent = "Введите ФИО студента: ";
	const char* globalInputNameExaminer = "Введите ФИО преподователя: ";
	const char* globalInputNameSubject = "Введите предмет: ";
	const char* globalInputDate = "Введите дату: ";
	const char* globalInputGrade = "Введите оценку: ";

	const char*  globalInputError = "Ошибка ввода: ";
};


