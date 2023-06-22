#pragma once
#include <string>
#include <cmath>


int nameLength = 20;


class Exam
{
private:
    char* nameStudent = new char[nameLength];
    char* nameExaminer = new char[nameLength];
    char* nameSubject = new char [nameLength];
    int date;
    int grade;
public:
    Exam(char nameStudent[],
        char nameExaminer[],
        char nameSubject[],
        int date,
        int grade);
    Exam();
    void Print();
    void Input();
    void PrintDate();
};



