#pragma once
#include <string>
#include <cmath>
#include "configs.h"


class Exam
{
private:
    Configs cfg;
    int nameLength = 100;
    char* nameStudent;
    char* nameExaminer;
    char* nameSubject;
    // int date; ������ ������ ��� ������������� time_t
    long long date;
    int grade;
    int GetNameLength();
public:
    // ����������� � �����������
    Exam(char* nameStudent,
        char* nameExaminer,
        char* nameSubject,
        int date,
        int grade);
    // ����������� ��� ����������
    Exam();
    // ����� ������
    void Print();
    // ����� ������
    void Input();
    // ����� ������ ����
    void PrintDate();
    // ���������� � double
    operator double();
    // ����� ���������� ��������� grade
    int GetGrade();
    // ���������� �������� +
    friend double operator+(Exam& ex1, Exam& ex2);

    Configs GetCfg();
    void SetCfg(Configs cfg);

    void SetNameLength(int nameLength);

    char* GetNameStudent();
    void SetNameStudent(char* NameStudent);

    char* GetNameExaminer();
    void SetNameExaminer(char* NameExaminer);

    char* GetNameSubject();
    void SetNameSubject(char* nameSubject);

    long long GetDate();
    void SetDate(long long date);

    void SetGrade(int grade);
};



