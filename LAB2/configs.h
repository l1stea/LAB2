#pragma once
#include <cstdint>
const int minGrade = 2;
const int maxGrade = 5;
const int minDate = 0;
const int maxDate = INT32_MAX;

const int stringLength = 100;
extern char globalNullString[stringLength] = "Не указано";

char* globalNameStudent = globalNullString;
char* globalNameExaminer = globalNullString;
char* globalNameSubject = globalNullString;


char globalPrintNameStudent[stringLength] = "ФИО студента: ";
char globalPrintNameExaminer[stringLength] = "ФИО экзаменатора: ";
char globalPrintNameSubject[stringLength] = "Предмет: ";
char globalPrintDate[stringLength] = "Дата: ";
char globalPrintGrade[stringLength] = "Оценка: ";

char globalInputNameStudent[stringLength] = "Введите ФИО студента: ";
char globalInputNameExaminer[stringLength] = "Введите ФИО преподователя: ";
char globalInputNameSubject[stringLength] = "Введите предмет: ";
char globalInputDate[stringLength] = "Введите дату: ";
char globalInputGrade[stringLength] = "Введите оценку: ";

char globalInputError[stringLength] = "Ошибка ввода: ";


class Configs
{

};


