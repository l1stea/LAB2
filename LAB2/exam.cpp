#define _CRT_SECURE_NO_WARNINGS
#include "exam.h"
#include <iostream>
#include "configs.h"
#include "checkInput.h"
using namespace std;


void Exam::Input() {
    try
    {
        cout << cfg.globalInputNameStudent;
        cin >> nameStudent;
        cout << cfg.globalInputNameExaminer;
        cin >> nameExaminer;
        cout << cfg.globalInputNameSubject;
        cin >> nameSubject;
        date = CheckInput::Date();
        grade = CheckInput::Grade();
        cout << endl;
    }
    catch (exception ex)
    {
        cout << cfg.globalInputError << ex.what();
        cout << endl;
    }
}


void Exam::Print()
{
    cout << cfg.globalPrintNameStudent << nameStudent << endl;
    cout << cfg.globalPrintNameExaminer << nameExaminer << endl;
    cout << cfg.globalPrintNameSubject << nameSubject << endl;
    PrintDate();
    cout << cfg.globalPrintGrade << grade << endl;
    cout << endl;
}


Exam::Exam()
{
    this->nameStudent = new char[GetNameLength()];
    this->nameExaminer = new char[GetNameLength()];
    this->nameSubject = new char[GetNameLength()];
    strcpy(nameStudent, cfg.globalNameStudent);
    strcpy(nameExaminer, cfg.globalNameExaminer);
    strcpy(nameSubject, cfg.globalNameSubject);
    time_t t = time(nullptr);
    this->date = t;
    this->grade = 2;
};


Exam::Exam(char* nameSt,
    char* nameEx,
    char* nameSb,
    int dt,
    int gd)
{
    nameStudent = new char[GetNameLength()];
    nameExaminer = new char[GetNameLength()];
    nameSubject = new char[GetNameLength()];
    strcpy(nameStudent, nameSt);
    strcpy(nameExaminer, nameEx);
    strcpy(nameSubject, nameSb);
    date = dt;
    grade = gd;
};

int day(tm* localtm)
{
    return localtm->tm_mday;
}

int month(tm* localtm)
{
    return localtm->tm_mon + 1;
}

int year(tm* localtm)
{
    return localtm->tm_year + 1900;
}


//#include <limits>
void Exam::PrintDate() {
    time_t t = date;
    //t = LONG_MAX; // �������� 2038 ����, ���� �� �������� ������������ ������ ����������, �� �� ������� ���� ������������ ���� � ����� int
    tm* localtm = localtime(&t);
    cout << cfg.globalPrintDate;
    int coutday = day(localtm);
    int coutmonth = month(localtm);
    int coutyear = year(localtm);
    cout << coutday << '/' << coutmonth << '/' << coutyear << endl;
}

//  ���������� �����
Exam::operator double() { 
    return this->grade; // �������� this (��������� �� ������) -  � ������ ������ ��������� �� �������� �� ������� ������ �� ���������� ��������
}

int Exam::GetGrade()
{
    return grade;
}

int Exam::GetNameLength()
{
    return cfg.nameLength;
}

double operator+(Exam& ex1, Exam& ex2)
{
    return ex1.grade + ex2.grade;
}