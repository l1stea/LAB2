// ReSharper disable CommentTypo
#pragma once
#include <string>
#include <cmath>
#include <ctime>

#include "configs.h"


class exam
{
    configs cfg_;
    int name_length_ = cfg_.get_name_length();
    char* name_student_;
    char* name_examiner_;
    char* name_subject_;
    // int date; Потеря данных при использовании time_t
    long long date_;
    int grade_;
    int get_name_length() const;
public:
    // Конструктор с параметрами
    exam(const char* name_student,  // NOLINT(readability-inconsistent-declaration-parameter-name)
         const char* name_examiner,
         const char* name_subject,
         int date,
         int grade = 2); // Параметр по умолчанию
    exam(const exam& ex);
    explicit exam(const char* name_student); // Конструктор со списком инициализации
    // Конструктор без параметров
    exam();

    // Деструктор
    ~exam();
    // Метод вывода
    void print() const;
    // Метод вывода
    void input();
    // Метод вывода даты
    void print_date() const;
    // Приведение в double
    // ReSharper disable once CppNonExplicitConversionOperator
    operator double() const;
    // Метод возращения аргумента grade
    int get_grade() const;
    // Перегрузка операнда +
    friend double operator+(const exam& ex1, const exam& ex2);

    configs get_cfg() const;
    void set_cfg(const configs& cfg);

    void set_name_length(int name_length);

    const char* get_name_student() const;
    void set_name_student(char* name_student);

    char* get_name_examiner() const;
    void set_name_examiner(char* name_examiner);

    const char* get_name_subject() const;
    void set_name_subject(char* name_subject);

    long long get_date() const;
    void set_date(long long date);

    void set_grade(int grade);
};

