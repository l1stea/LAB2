#include "checkInput.h"
#include <string>
#include <iostream>
#include "configs.h"
using namespace std;
#pragma warning(disable : 4996)


int CheckInput::GetIntBetween(char* words, int min, int max)
{
    int N;
    if (max < min)
    {
        int swap = max;
        max = min;
        min = swap;
    }
    for (;;) {
        cout << words << " (целое от " << min << " до " << max << "): " << flush;
        if ((cin >> N).good() && (min <= N) && (N <= max)) return N;
        if (cin.fail()) {
            cin.clear();
            cout << "Неверный ввод, повторите.\n";
        }
        else {
            cout << "Число вне допустимого диапазона значений. Повторите ввод.\n";
        }
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');
    }
}

int CheckInput::GetGrade()
{
    Configs cfg;
    char* gradeword = new char[10];
    strcpy(gradeword, "Оценка");
    return GetIntBetween(gradeword, cfg.minGrade, cfg.maxGrade);
}



int CheckInput::GetIndex(int sizeArray)
{
    while (sizeArray < 1)
    {
        cout << "Размер группы должен быть больше 0 и меньше 2 147 483 647. Введите число:\n";
        cin >> sizeArray;
        if (cin.fail()) {
            cin.clear();
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
        }

    }
    return sizeArray;
}




int CheckInput::GetDate()
{
    int day = 0;
    int month = 0;
    int year = 0;
    cout << "Введите дату в формате День.Месяц.Год: ";
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

    } while (!GetCheckDate(day, month, year));
    time_t rawtime;
    struct tm* timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    timeinfo->tm_year = year - 1900;
    timeinfo->tm_mon = month - 1;
    timeinfo->tm_mday = day;
    return  mktime(timeinfo);
}


bool CheckInput::GetCheckDate(int day, int month, int year)
{
    bool month31[12]{ true, false, true, false, true, false, true, true, false, true, false, true };
    if (year < 1900 || year > 2037)
    {
        cout << "Некорректная дата" << endl;
        return false;
    }
    if (month < 1 || month > 12)
    {
        cout << "Месяц должен быть от 1 по 12" << endl;
        return false;
    }
    if (month == 2 && (day < 1 || day > 29))
    {
        cout << "Февряль должен быть от 1 до 29" << endl;
        return false;
    }
    if (month == 2)
    {
        if ((day >= 1 && day <= 29 && (year % 4 == 0)) || (day >= 1 && day <= 28 && (year % 4 != 0))) return true;
        cout << "Некорректный день в феврале" << endl;
        return false;
    }

    if (month31[month - 1] && day <= 31 && day >= 1) return true;
    if (!month31[month - 1] && day <= 30 && day >= 1) return true;
    cout << "Некорректная дата" << endl;
    return false;
}