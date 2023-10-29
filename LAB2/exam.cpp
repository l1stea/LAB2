// ReSharper disable CommentTypo
// ReSharper disable CppDeprecatedEntity
// ReSharper disable CppClangTidyClangDiagnosticDeprecatedDeclarations
#define _CRT_SECURE_NO_WARNINGS  // NOLINT(clang-diagnostic-unused-macros)
#include "exam.h"
#include <iostream>
#include "configs.h"
#include "checkInput.h"
using namespace std;


bool exam::saveNameStudent() {
    string str;
    cin >> str;
    if (str.length() > cfg_.get_name_length())
    {
        cout << "Введенная строка больше заданной длины: " << cfg_.get_name_length() << endl;
        return false;
    }
    strcpy(name_student_, str.c_str());
    return true;
}
bool exam::saveNameExaminer() {
    string str;
    cin >> str;
    if (str.length() > cfg_.get_name_length())
    {
        cout << "Введенная строка больше заданной длины: " << cfg_.get_name_length() << endl;
        return false;
    }
    strcpy(name_examiner_, str.c_str());
    return true;
}
bool exam::saveNameSubject() {
    string str;
    cin >> str;
    if (str.length() > cfg_.get_name_length())
    {
        cout << "Введенная строка больше заданной длины: " << cfg_.get_name_length() << endl;
        return false;
    }
    strcpy(name_subject_, str.c_str());
    return true;
}
bool exam::saveDate() {
    int day = 0;
    int month = 0;
    int year = 0;
    cin >> day;
    cin.ignore(1);
    cin >> month;
    cin.ignore(1);
    cin >> year;
    if (cin.fail()) {
        cin.clear();
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');
        cout << "Ошибка ввода!\n";
        return false;
    }
    if (!check_date(day, month, year))
        return false;

    time_t raw_time;
    time(&raw_time);
    // ReSharper disable once CppDeprecatedEntity
    tm* time_info = localtime(&raw_time);  // NOLINT(concurrency-mt-unsafe)
    time_info->tm_year = year - 1900;
    time_info->tm_mon = month - 1;
    time_info->tm_mday = day;
    date_ = mktime(time_info);  // NOLINT(bugprone-narrowing-conversions, clang-diagnostic-shorten-64-to-32, cppcoreguidelines-narrowing-conversions)
    return true;
}



bool exam::check_date(int day, int month, int year)
{
    constexpr bool month31[12]{ true, false, true, false, true, false, true, true, false, true, false, true };
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
        if (day >= 1 && day <= 29 && year % 4 == 0 || day >= 1 && day <= 28 && year % 4 != 0) return true;
        cout << "Некорректный день в феврале" << endl;
        return false;
    }

    if (month31[month - 1] && day <= 31 && day >= 1) return true;
    if (!month31[month - 1] && day <= 30 && day >= 1) return true;
    cout << "Некорректная дата" << endl;
    return false;
}

bool exam::saveGrade() {
    int min = cfg_.min_grade;
    int max = cfg_.max_grade;
    int n;
    if ((cin >> n).good() && min <= n && n <= max) {
        grade_ = n;
        return true;
    }
    if (n < 0) cout << "Оценка не может быть отрицательной\n";
    if (n >= 0 && n < 2 && !cin.fail()) cout << "Оценка должна быть больше или равна 2!\n";
    if (n > 5) cout << "Оценка должна быть меньше или равна 5!\n";
    if (cin.fail()) {
        cin.clear();
        cout << "Некорректный ввод!\n";
    }
    else {
        cout << "Число вне допустимого диапазона значений!\n";
    }
    cin.ignore((numeric_limits<streamsize>::max)(), '\n');
    return false;
}


void exam::input() {
    try
    {
        string str;
        do
        {
            cout << cfg_.global_input_name_student;
        } while (!saveNameStudent());
       
        do
        {
            cout << cfg_.global_input_name_examiner;
        } while (!saveNameExaminer());


        do
        {
            cout << cfg_.global_input_name_subject;
        } while (!saveNameSubject());

        do
        {
            cout << "Введите дату в формате День.Месяц.Год: ";
        } while (!saveDate());

        do
        {
            cout << "Введите оценку: ";
        } while (!saveGrade());

        cout << endl;
    }
    catch (exception ex)  // NOLINT(misc-throw-by-value-catch-by-reference)
    {
        cout << cfg_.global_input_error << ex.what();
        cout << endl;
    }
}


void exam::print()
{
    cout << cfg_.global_print_name_student << name_student_ << endl;
    cout << cfg_.global_print_name_examiner << name_examiner_ << endl;
    cout << cfg_.global_print_name_subject << name_subject_ << endl;
    print_date();
    cout << cfg_.global_print_grade << grade_ << endl;
    cout << endl;
}


exam::exam()
{
    this->name_student_ = new char[get_name_length()];
    this->name_examiner_ = new char[get_name_length()];
    this->name_subject_ = new char[get_name_length()];
    strcpy(name_student_, cfg_.global_name_student);
    strcpy(name_examiner_, cfg_.global_name_examiner);
    strcpy(name_subject_, cfg_.global_name_subject);
    time_t t = time(nullptr);
    this->date_ = t;
    this->grade_ = 2;
}
exam::~exam()
{
    cout << "Вызван Деструктор exam.\n";
    //delete[] name_student_;
    //delete[] name_examiner_;
    //delete[] name_subject_;
}


exam::exam(char* name_student,
           char* name_examiner,
           char* name_subject,
           int date,
           int grade)
{
    try {
        name_student_ = new char[get_name_length()];
        name_examiner_ = new char[get_name_length()];
        name_subject_ = new char[get_name_length()];
        strcpy(name_student_, name_student);
        strcpy(name_examiner_, name_examiner);
        strcpy(name_subject_, name_subject);
        date_ = date;
        if (grade < 2 || grade > 5)
        {
            cout << "Оценка должна быть от 2 до 5! Выставлена 2";
            grade_ = 2;
        }
        else grade_ = grade;
    }
    catch (exception ex)  // NOLINT(misc-throw-by-value-catch-by-reference)
    {
        cout << ex.what();
    }
}

exam::exam(exam& ex)
{
    cfg_ = ex.cfg_;
    name_length_ = ex.name_length_;
    name_student_ = ex.name_student_;
    name_examiner_ = ex.name_examiner_;
    name_subject_ = ex.name_subject_;
    date_ = ex.date_;
    grade_ = ex.grade_;
}

//Внутренняя ошибка компилятора
//exam::exam(char* name_student):
//    exam(
//    new char[name_length_](*name_student), 
//    new char[name_length_]("Не задан"),
//    new char[name_length_]("Не задан"),
//    time(nullptr), 
//    2)
//{}

int day(tm* local_time)
{
    return local_time->tm_mday;
}

int month(tm* local_time)
{
    return local_time->tm_mon + 1;
}

int year(tm* local_time)
{
    return local_time->tm_year + 1900;
}


//#include <limits>
void exam::print_date()
{
	time_t t = date_;
    //t = LONG_MAX; // Проблема 2038 года, надо по хорошему использовать другую библиотеку, но по заданию надо использовать дату с типом int
	tm* local_time = localtime(&t);  // NOLINT(concurrency-mt-unsafe)
    cout << cfg_.global_print_date;
	int output_day = day(local_time);
	int output_month = month(local_time);
	int output_year = year(local_time);
    cout << output_day << '/' << output_month << '/' << output_year << endl;
}

//  Приведение типов
exam::operator double()
{ 
    // Оператор this (указатель на объект) - 
    //в данном случае указывает на значание из объекта класса по указанному атрибуту
    return this->grade_; 
}

int exam::get_grade()
{
    return grade_;
}

configs exam::get_cfg()
{
    return this->cfg_;
}

void exam::set_cfg(configs& cfg)
{
    this->cfg_ = cfg;
}

void exam::set_name_length(int name_length)
{
    this->name_length_ = name_length;
}

char* exam::get_name_student()
{
    return this->name_student_;
}

void exam::set_name_student(char* name_student)
{
    this->name_student_ = name_student;
}

char* exam::get_name_examiner()
{
    return this->name_examiner_;
}

void exam::set_name_examiner(char* name_examiner)
{
    this->name_examiner_ = name_examiner;
}

char* exam::get_name_subject()
{
    return this->name_subject_;
}

void exam::set_name_subject(char* name_subject)
{
    this->name_subject_ = name_subject;
}

long long exam::get_date()
{
    return this->date_;
}

void exam::set_date(long long date)
{
    this->date_ = date;
}

void exam::set_grade(int grade)
{
    this->grade_ = grade;
}

int exam::get_name_length()
{
    return this->name_length_;
}

double operator+(exam& ex1, exam& ex2)
{
    return ex1.grade_ + ex2.grade_;
}