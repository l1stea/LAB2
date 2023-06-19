#define _CRT_SECURE_NO_WARNINGS
#include "main.h"
#include "configs.h"
#include <iostream> // cin и cout
#include <Windows.h> // Обязательно для SetConsoleCP() и SetConsoleOutputCP()
#include <stdlib.h>
#include <string.h>
#include <ctime> // Для time_t, tm
#include <iostream>
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

	Exam exFull(nameSt, nameEx, nameSb, dt, gd); // 10 задание
    exFull.Print(); // 10 задание

    
    Exam* exEmpty = new Exam(); // 11 задание, динамический Exam c обычным конструктором 
    exEmpty->Print();
    delete[] exEmpty;

    Exam exInput; // создаем объект класса Exam
    exInput.Input();// 13 задание, вызываем метод класса

    exInput.Print();
}

void Exam::Input() {
    try
    {
        cout << globalInputNameStudent;
        cin >> nameStudent;
        cout << globalInputNameExaminer;
        cin >> nameExaminer;
        cout << globalInputNameSubject;
        cin >> nameSubject;
        //cout << globalInputDate;
        date = CheckInput::Date();
        //cout << globalInputGrade;
        grade = CheckInput::Grade();
        cout << endl;
    }
    catch(exception ex)
    {
        cout << globalInputError << ex.what();
    }
}

void Exam::Print()
{
    cout << globalPrintNameStudent << nameStudent << endl;
    cout << globalPrintNameExaminer << nameExaminer << endl;
    cout << globalPrintNameSubject << nameSubject << endl;
    PrintDate();
    cout << globalPrintGrade << grade << endl;
    cout << endl;
}


Exam::Exam()
{
    strcpy(nameStudent, globalNameStudent);
    strcpy(nameExaminer, globalNameExaminer);
    strcpy(nameSubject, globalNameSubject);
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

void Exam::PrintDate() {
    time_t t = date;
    tm* localtm = localtime(&t);
    cout << globalPrintDate << localtm->tm_mday << '/' << (localtm->tm_mon + 1) << '/'
        << (localtm->tm_year + 1900) << endl;
}

int CheckInput::Grade()
{
    int grade;

    for (;;) {
        std::cout << "Оценка" << " (целое от " << minGrade << " до " << maxGrade << "): " << std::flush;
        if ((std::cin >> grade).good() && (minGrade <= grade) && (grade <= maxGrade)) return grade;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cout << "Неверный ввод, повторите.\n";
        }
        else {
            std::cout << "Число вне допустимого диапазона значений. Повторите ввод.\n";
        }
        std::cin.ignore(100, '\n');
    }
}

int CheckInput::Date()
{
    int date;

    for (;;) {
        std::cout << "Дата" << " (целое от " << minDate << " до " << maxDate << "): " << std::flush;
        if ((std::cin >> date).good() && (minDate <= date) && (date <= maxDate)) return date;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cout << "Неверный ввод, повторите.\n";
        }
        else {
            std::cout << "Число вне допустимого диапазона значений. Повторите ввод.\n";
        }
        std::cin.ignore(100, '\n');
    }
}