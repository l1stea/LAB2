#pragma once
#include <cstdint>

class Configs
{
public:
	// Количество групп в GroupUniver
	int CountGroup = 3;
	// Длина строк в Exam
	int nameLength = 100;
	// Размер группы в Unversity
	int SizeGroup = 5;
	// Минимальная оценка в Exam
	int minGrade = 2;
	// Максимальная оценка в Exam
	int maxGrade = 5;
	// Минимальаня дата в Exam
	int minDate = 0;
	// Максимальная дата в Exam
	int maxDate = INT32_MAX;

	// Дина строк вывода
	int stringLength = 100;
	// Пустая строка
	// char* globalNullString = "Не указано";
	char* globalNullString = DefaultGlobalNullString();
	char* globalNameStudent = DefaultGlobalNullString();
	char* globalNameExaminer = DefaultGlobalNullString();
	char* globalNameSubject = DefaultGlobalNullString();


	//const char* globalPrintNameStudent = "ФИО студента: ";
	//const char* globalPrintNameExaminer = "ФИО экзаменатора: ";
	//const char* globalPrintNameSubject = "Предмет: ";
	//const char* globalPrintDate = "Дата: ";
	//const char* globalPrintGrade = "Оценка: ";

	//const char* globalInputNameStudent = "Введите ФИО студента: ";
	//const char* globalInputNameExaminer = "Введите ФИО преподователя: ";
	//const char* globalInputNameSubject = "Введите предмет: ";
	//const char* globalInputDate = "Введите дату: ";
	//const char* globalInputGrade = "Введите оценку: ";

	//const char* globalInputError = "Ошибка ввода: ";
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
	// Перегрузка оператора присваивания
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


