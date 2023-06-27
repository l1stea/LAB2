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
    Exam(char* nameStudent,
        char* nameExaminer,
        char* nameSubject,
        int date,
        int grade);
    Exam();
    void Print();
    void Input();
    void PrintDate();
    operator double();
    int GetGrade();
    friend double operator+(Exam& ex1, Exam& ex2);
};



