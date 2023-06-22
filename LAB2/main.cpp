#include "main.h"
#include "configs.h"
#include <iostream> // cin � cout
#include <Windows.h> // ����������� ��� SetConsoleCP() � SetConsoleOutputCP()
#include <stdlib.h>
#include <string.h>
#include <ctime> // ��� time_t, tm
#include <iostream>
#include <string>
#include <cmath>
#include "checkInput.h"
using namespace std;
//
Configs cfg;
int main()
{
	SetConsoleCP(1251); // ���� � ������� � ��������� 1251
	SetConsoleOutputCP(1251); // ����� �� ������� � ��������� 1251.


    char nameSt[] = "��������� ��";
	char nameEx[] = "������ ��";
	char nameSb[] = "���";

	time_t t = time(nullptr);
	int dt = t;
	int gd = 5;

	Exam exFull(nameSt, nameEx, nameSb, dt, gd); // 10 �������
    exFull.Print(); // 10 �������

    
    Exam* exEmpty = new Exam(); // 11 �������, ������������ Exam c ������� ������������� 
    exEmpty->Print();
    delete[] exEmpty;

    Exam exInput; // ������� ������ ������ Exam
    exInput.Input();// 13 �������, �������� ����� ������

    exInput.Print();
}


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
    catch(exception ex)
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


#include <limits>
void Exam::PrintDate() {
    time_t t = date;
    //t = LONG_MAX; // �������� 2038 ����, ���� �� �������� ������������ ������ ����������, �� �� ������� ���� ������������ ���� � ����� int
    tm* localtm = localtime(&t);
    cout << cfg.globalPrintDate << localtm->tm_mday << '/' << (localtm->tm_mon + 1) << '/'
        << (localtm->tm_year + 1900) << endl;
}