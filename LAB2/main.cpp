#include "main.h"
#include <iostream> // cin � cout
#include <Windows.h> // ����������� ��� SetConsoleCP() � SetConsoleOutputCP()
#include <stdlib.h>
#include <string.h>
using namespace std;

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

	Exam exFull(nameSt, nameEx, nameSb, dt, gd);
	Exam exEmpty;

	exFull.Print();


}

void Exam::Print()
{
    cout << "��� ��������: " << nameStudent << endl;
    cout << "��� ������������: " << nameExaminer << endl;
    cout << "�������: " << nameSubject << endl;
    time_t t = date;
    tm* now = localtime(&t);
    cout << "����: " << now->tm_mday << '/' << (now->tm_mon + 1) << '/'
        << (now->tm_year + 1900) << endl;
    cout << "������: " << grade << endl;
}


Exam::Exam()
{
    nameStudent = nullptr;
    nameExaminer = nullptr;
    nameSubject = nullptr;
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