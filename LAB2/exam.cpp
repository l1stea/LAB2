#define _CRT_SECURE_NO_WARNINGS
#include "exam.h"
#include <iostream>
#include "configs.h"
#include "checkInput.h"
using namespace std;


void Exam::Input() {
    try
    {
        string str;

        do
        {
            cout << cfg.globalInputNameStudent;
            cin >> str;
            if (str.length() > cfg.GetNameLength()) cout << "Введенная строка больше заданной длины: " << cfg.GetNameLength() << endl;
        } while (str.length() > cfg.GetNameLength());
        strcpy(nameStudent, str.c_str());

        do
        {
            cout << cfg.globalInputNameExaminer;
            cin >> str;
            if (str.length() > cfg.GetNameLength()) cout << "Введенная строка больше заданной длины: " << cfg.GetNameLength() << endl;
        } while (str.length() > cfg.GetNameLength());
        strcpy(nameExaminer, str.c_str());

        do
        {
            cout << cfg.globalInputNameSubject;
            cin >> str;
            if (str.length() > cfg.GetNameLength()) cout << "Введенная строка больше заданной длины: " << cfg.GetNameLength() << endl;
        } while (str.length() > cfg.GetNameLength());
        strcpy(nameSubject, str.c_str());

        date = CheckInput::Date(); // Проверка даты
        grade = CheckInput::Grade(); // Проверка оценки от 2 до 5
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
    // Оператор this (указатель на объект) - 
    //в данном случае указывает на значание из объекта класса по указанному атрибуту
    return this->grade; 
}

int Exam::GetGrade()
{
    return grade;
}

Configs Exam::GetCfg()
{
    return this->cfg;
}

void Exam::SetCfg(Configs cfg)
{
    this->cfg = cfg;
}

void Exam::SetNameLength(int nameLength)
{
    this->nameLength = nameLength;
}

char* Exam::GetNameStudent()
{
    return this->nameStudent;
}

void Exam::SetNameStudent(char* nameStudent)
{
    this->nameStudent = nameStudent;
}

char* Exam::GetNameExaminer()
{
    return this->nameExaminer;
}

void Exam::SetNameExaminer(char* nameExaminer)
{
    this->nameExaminer = nameExaminer;
}

char* Exam::GetNameSubject()
{
    return this->nameSubject;
}

void Exam::SetNameSubject(char* nameSubject)
{
    this->nameSubject = nameSubject;
}

long long Exam::GetDate()
{
    return this->date;
}

void Exam::SetDate(long long date)
{
    this->date = date;
}

void Exam::SetGrade(int grade)
{
    this->grade = grade;
}

int Exam::GetNameLength()
{
    return this->nameLength;
}

double operator+(Exam& ex1, Exam& ex2)
{
    return ex1.grade + ex2.grade;
}