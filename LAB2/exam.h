#pragma once
#include <string>
#include <cmath>


class Exam
{
private:
    int nameLength = 100;
    char* nameStudent;
    char* nameExaminer;
    char* nameSubject;
    // int date; Потеря данных при использовании time_t
    long long date;
    int grade;
public:
    // Конструктор с параметрами
    Exam(char* nameStudent,
        char* nameExaminer,
        char* nameSubject,
        int date,
        int grade);
    // Конструктор без параметров
    Exam();
    // Метод вывода
    void Print();
    // Метод вывода
    void Input();
    // Метод вывода даты
    void PrintDate();
    // Приведение в double
    operator double();
    // Метод возращения аргумента grade
    int GetGrade();
    // Перегрузка операнда +
    friend double operator+(Exam& ex1, Exam& ex2);
};



