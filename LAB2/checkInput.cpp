#include "checkInput.h"
#include <string>
#include <iostream>
#include "inputInt.h"
#include "configs.h"
using namespace std;
#pragma warning(disable : 4996)


int CheckInput::Grade()
{
    Configs cfg;
    char* gradeword = new char[10];
    strcpy(gradeword, "������");
    return inputInt::InputInt(gradeword, cfg.minGrade, cfg.maxGrade);
}


int CheckInput::Date()
{
    int day = 0;
    int month = 0;
    int year = 0;
    cout << "������� ���� � ������� ����.�����.���: ";
    do
    {
        cin >> day;
        cin.ignore(1);
        cin >> month;
        cin.ignore(1);
        cin >> year;
        if (cin.fail()) {
            cin.clear();
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
        }

    } while (!CheckInput::CheckDate(day, month, year));
    time_t rawtime;
    struct tm* timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    timeinfo->tm_year = year - 1900;
    timeinfo->tm_mon = month - 1;
    timeinfo->tm_mday = day;
    return  mktime(timeinfo);
}


bool CheckInput::CheckDate(int day, int month, int year)
{
    bool month31[12]{ true, false, true, false, true, false, true, true, false, true, false, true };
    if (year < 1900 || year > 2037)
    {
        cout << "������������ ����" << endl;
        return false;
    }
    if (month < 1 || month > 12)
    {
        cout << "����� ������ ���� �� 1 �� 12" << endl;
        return false;
    }
    if (month == 2 && (day < 1 || day > 29))
    {
        cout << "������� ������ ���� �� 1 �� 29" << endl;
        return false;
    }
    if (month == 2)
    {
        if ((day >= 1 && day <= 29 && (year % 4 == 0)) || (day >= 1 && day <= 28 && (year % 4 != 0))) return true;
        cout << "������������ ���� � �������" << endl;
        return false;
    }

    if (month31[month - 1] && day <= 31 && day >= 1) return true;
    if (!month31[month - 1] && day <= 30 && day >= 1) return true;
    cout << "������������ ����" << endl;
    return false;
}