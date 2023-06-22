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
    strcpy(nameStudent, cfg.globalNameStudent);
    strcpy(nameExaminer, cfg.globalNameExaminer);
    strcpy(nameSubject, cfg.globalNameSubject);
    time_t t = time(nullptr);
    date = t;
    grade = 2;
};


Exam::Exam(char nameSt[],
    char nameEx[],
    char nameSb[],
    int dt,
    int gd)
{
    strcpy(nameStudent, nameSt);
    strcpy(nameExaminer, nameEx);
    strcpy(nameSubject, nameSb);
    date = dt;
    grade = gd;
};


//#include <limits>
void Exam::PrintDate() {
    Configs cfg;
    time_t t = date;
    //t = LONG_MAX; // Проблема 2038 года, надо по хорошему использовать другую библиотеку, но по заданию надо использовать дату с типом int
    tm* localtm = localtime(&t);
    cout << cfg.globalPrintDate << localtm->tm_mday << '/' << (localtm->tm_mon + 1) << '/' << (localtm->tm_year + 1900) << endl;
}