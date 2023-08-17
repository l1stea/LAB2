// ReSharper disable CommentTypo
// ReSharper disable CppDeprecatedEntity
// ReSharper disable CppClangTidyClangDiagnosticDeprecatedDeclarations
#define _CRT_SECURE_NO_WARNINGS  // NOLINT(clang-diagnostic-unused-macros)
#include "exam.h"
#include <iostream>
#include "configs.h"
#include "checkInput.h"
using namespace std;


void exam::input() {
    try
    {
        string str;


        do
        {
            cout << cfg_.global_input_name_student;
            cin >> str;
        } while (!check_input::check_string(str, cfg_.get_name_length()));
        strcpy(name_student_, str.c_str());


        do
        {
            cout << cfg_.global_input_name_examiner;
            cin >> str;
        } while (!check_input::check_string(str, cfg_.get_name_length()));
        strcpy(name_examiner_, str.c_str());


        do
        {
            cout << cfg_.global_input_name_subject;
            cin >> str;
        } while (!check_input::check_string(str, cfg_.get_name_length()));
        strcpy(name_subject_, str.c_str());

        date_ = check_input::get_date(); // Проверка даты
        grade_ = check_input::get_grade(); // Проверка оценки от 2 до 5
        cout << endl;
    }
    catch (exception ex)  // NOLINT(misc-throw-by-value-catch-by-reference)
    {
        cout << cfg_.global_input_error << ex.what();
        cout << endl;
    }
}


void exam::print() const
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
    const time_t t = time(nullptr);
    this->date_ = t;
    this->grade_ = 2;
}
exam::~exam()
{
    cout << "Вызван Деструктор Exam.\n";
    //delete[] name_student_;
    //delete[] name_examiner_;
    //delete[] name_subject_;
}


exam::exam(const char* name_student,
           const char* name_examiner,
           const char* name_subject,
           const int date,
           const int grade)
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

exam::exam(const exam& ex)
{
    cfg_ = ex.cfg_;
    name_length_ = ex.name_length_;
    name_student_ = ex.name_student_;
    name_examiner_ = ex.name_examiner_;
    name_subject_ = ex.name_subject_;
    date_ = ex.date_;
    grade_ = ex.grade_;
}

exam::exam(const char* name_student):
exam(
    name_student, 
    "Не задан", 
    "Не задан", 
    time(nullptr), 
    2)
{}

int day(const tm* local_time)
{
    return local_time->tm_mday;
}

int month(const tm* local_time)
{
    return local_time->tm_mon + 1;
}

int year(const tm* local_time)
{
    return local_time->tm_year + 1900;
}


//#include <limits>
void exam::print_date() const
{
	const time_t t = date_;
    //t = LONG_MAX; // Проблема 2038 года, надо по хорошему использовать другую библиотеку, но по заданию надо использовать дату с типом int
	const tm* local_time = localtime(&t);  // NOLINT(concurrency-mt-unsafe)
    cout << cfg_.global_print_date;
	const int output_day = day(local_time);
	const int output_month = month(local_time);
	const int output_year = year(local_time);
    cout << output_day << '/' << output_month << '/' << output_year << endl;
}

//  Приведение типов
exam::operator double() const
{ 
    // Оператор this (указатель на объект) - 
    //в данном случае указывает на значание из объекта класса по указанному атрибуту
    return this->grade_; 
}

int exam::get_grade() const
{
    return grade_;
}

configs exam::get_cfg() const
{
    return this->cfg_;
}

void exam::set_cfg(const configs& cfg)
{
    this->cfg_ = cfg;
}

void exam::set_name_length(const int name_length)
{
    this->name_length_ = name_length;
}

const char* exam::get_name_student() const
{
    return this->name_student_;
}

void exam::set_name_student(char* name_student)
{
    this->name_student_ = name_student;
}

char* exam::get_name_examiner() const
{
    return this->name_examiner_;
}

void exam::set_name_examiner(char* name_examiner)
{
    this->name_examiner_ = name_examiner;
}

const char* exam::get_name_subject() const
{
    return this->name_subject_;
}

void exam::set_name_subject(char* name_subject)
{
    this->name_subject_ = name_subject;
}

long long exam::get_date() const
{
    return this->date_;
}

void exam::set_date(const long long date)
{
    this->date_ = date;
}

void exam::set_grade(const int grade)
{
    this->grade_ = grade;
}

int exam::get_name_length() const
{
    return this->name_length_;
}

double operator+(const exam& ex1, const exam& ex2)
{
    return ex1.grade_ + ex2.grade_;
}