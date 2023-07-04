#pragma once
#include <cstdint>

class Configs
{
public:
	// Начальное id в GroupUniver
	int IdGroupUniver = 0;
	// Длина строк в Exam
	const int nameLength = 100;
	// Размер группы в Unversity
	const int SizeGroup = 5;
	// Минимальная оценка в Exam
	const int minGrade = 2;
	// Максимальная оценка в Exam
	const int maxGrade = 5;
	// Минимальаня дата в Exam
	const int minDate = 0;
	// Максимальная дата в Exam
	const int maxDate = INT32_MAX;

	// Дина строк вывода
	const int stringLength = 100;
	// Пустая строка
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

public:
	int GetSizeGroup();
	// Перегрузка оператора присваивания
	Configs operator=(Configs i);
};


