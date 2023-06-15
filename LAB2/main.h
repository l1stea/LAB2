#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <ctime> // Для time_t, tm
#include <iostream>



class Exam
{
private:
    char* nameStudent;
    char* nameExaminer;
    char* nameSubject;
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
};


void Exam::Print() 
{
    std::cout << "ФИО студента: " << nameStudent << "\n";
    std::cout << "ФИО экзаменатора: " << nameExaminer << "\n";
    std::cout << "Предмет: " << nameSubject << "\n";
    std::time_t t = date;
    std::tm* now = std::localtime(&t);
    std::cout << "Дата: " << now->tm_mday << '/' << (now->tm_mon + 1) << '/'
        << (now->tm_year + 1900) << std::endl;
    std::cout << "Оценка: " << grade << "\n";
}


Exam::Exam()
{
    nameStudent = nullptr;
    nameExaminer = nullptr;
    nameSubject = nullptr;
    std::time_t t = std::time(nullptr);
    date = t;
    grade = 2;
};

Exam::Exam(char nameSt[],
    char nameEx[],
    char nameSb[],
    int dt,
    int gd)
{
    nameStudent = nameSt;
    nameExaminer = nameEx;
    nameSubject = nameSb;
    date = dt;
    grade = gd;
};
