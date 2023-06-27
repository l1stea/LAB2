#define _CRT_SECURE_NO_WARNINGS
#include "exam.h"
#include <iostream>
#include "configs.h"
#include "checkInput.h"
using namespace std;


void Exam::Input() {
    Configs cfg;
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
    Configs cfg;
    cout << cfg.globalPrintNameStudent << nameStudent << endl;
    cout << cfg.globalPrintNameExaminer << nameExaminer << endl;
    cout << cfg.globalPrintNameSubject << nameSubject << endl;
    PrintDate();
    cout << cfg.globalPrintGrade << grade << endl;
    cout << endl;
}


Exam::Exam()
{
    Configs cfg;
    nameStudent = new char[nameLength];
    nameExaminer = new char[nameLength];
    nameSubject = new char[nameLength];
    strcpy(nameStudent, cfg.globalNameStudent);
    strcpy(nameExaminer, cfg.globalNameExaminer);
    strcpy(nameSubject, cfg.globalNameSubject);
    time_t t = time(nullptr);
    date = t;
    grade = 2;
};


Exam::Exam(char* nameSt,
    char* nameEx,
    char* nameSb,
    int dt,
    int gd)
{
    nameStudent = new char[nameLength];
    nameExaminer = new char[nameLength];
    nameSubject = new char[nameLength];
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
    Configs cfg;
    time_t t = date;
    //t = LONG_MAX; // Проблема 2038 года, надо по хорошему использовать другую библиотеку, но по заданию надо использовать дату с типом int
    tm* localtm = localtime(&t);
    cout << cfg.globalPrintDate;
    int coutday = day(localtm);
    int coutmonth = month(localtm);
    int coutyear = year(localtm);
    cout << coutday << '/' << coutmonth << '/' << coutyear << endl;
}

//  Приведение типов
Exam::operator double() { 
    return this->grade; // Оператор this (указатель на объект) -  в данном случае указывает на значание из объекта класса по указанному атрибуту
}

int Exam::GetGrade()
{
    return grade;
}

double operator+(Exam& ex1, Exam& ex2)
{
    return ex1.grade + ex2.grade;
}