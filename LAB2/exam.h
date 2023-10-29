// ReSharper disable CommentTypo
#pragma once
#include <string>
#include <cmath>
#include <ctime>

#include "configs.h"


class exam
{
private:
    configs cfg_;
    int name_length_ = cfg_.get_name_length();
    char* name_student_;
    char* name_examiner_;
    char* name_subject_;
    // int date; Потеря данных при использовании time_t
    long long date_;
    int grade_;
    int get_name_length();
public:
    // Конструктор с параметрами
    exam(char* name_student,  // NOLINT(readability-inconsistent-declaration-parameter-name)
         char* name_examiner,
         char* name_subject,
         int date,
         int grade = 2); // Параметр по умолчанию
    exam(exam& ex);
    explicit exam(char* name_student); // Конструктор со списком инициализации
    // Конструктор без параметров
    exam();
    // Деструктор
    ~exam();
    // Метод вывода
    void print();
    bool saveNameStudent();
    bool saveNameExaminer();
    bool saveNameSubject();
    bool saveDate();
    bool check_date(int day, int month, int year);
    bool saveGrade();
    // Метод вывода
    void input();
    // Метод вывода даты
    void print_date();
    // Приведение в double
    // ReSharper disable once CppNonExplicitConversionOperator
    operator double();
    // Метод возращения аргумента grade
    int get_grade();
    // Перегрузка операнда +
    friend double operator+(exam& ex1, exam& ex2);

    configs get_cfg();
    void set_cfg(configs& cfg);

    void set_name_length(int name_length);

    char* get_name_student();
    void set_name_student(char* name_student);

    char* get_name_examiner();
    void set_name_examiner(char* name_examiner);

    char* get_name_subject();
    void set_name_subject(char* name_subject);

    long long get_date();
    void set_date(long long date);

    void set_grade(int grade);
};

