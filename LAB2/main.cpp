#include "main.h"
#include <iostream> // cin и cout
#include <Windows.h> // Обязательно для SetConsoleCP() и SetConsoleOutputCP()
#include <stdlib.h>
#include <string.h>
using namespace std;

int main()
{
	SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
	SetConsoleOutputCP(1251); // Вывод на консоль в кодировке 1251.


    char nameSt[] = "Тимошенко ЕМ";
	char nameEx[] = "Косова АЕ";
	char nameSb[] = "ООП";

	time_t t = time(nullptr);
	int dt = t;
	int gd = 5;

	Exam exFull(nameSt, nameEx, nameSb, dt, gd);
	Exam exEmpty;

	exFull.Print();


}

void Exam::Print()
{
    cout << "ФИО студента: " << nameStudent << endl;
    cout << "ФИО экзаменатора: " << nameExaminer << endl;
    cout << "Предмет: " << nameSubject << endl;
    time_t t = date;
    tm* now = localtime(&t);
    cout << "Дата: " << now->tm_mday << '/' << (now->tm_mon + 1) << '/'
        << (now->tm_year + 1900) << endl;
    cout << "Оценка: " << grade << endl;
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