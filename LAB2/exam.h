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
public:
    // Конструктор с параметрами
    exam(const char* name_student,  // NOLINT(readability-inconsistent-declaration-parameter-name)
         const char* name_examiner,
         const char* name_subject,
         int date,
         int grade = 2); // Параметр по умолчанию
    exam(exam& ex);
    exam(char* name_student); // Конструктор со списком инициализации
    // Конструктор без параметров
    exam();
    // Деструктор
    ~exam();
    // Метод вывода
    void print() const;
    bool save_name_student();
    bool save_name_examiner();
    bool save_name_subject();
    bool save_date();
    bool save_grade();
    bool check_date(int day, int month, int year) const;
    // Метод вывода
    void input();
    // Метод вывода даты
    void print_date() const;
    // Приведение в double
    // ReSharper disable once CppNonExplicitConversionOperator
    operator double();
    // Метод возращения аргумента grade
    int get_grade() const;
    // Перегрузка операнда +
    friend double operator+(exam& ex1,exam& ex2);

    configs get_cfg() const;
    void set_cfg(const configs& cfg);

    int get_name_length() const;
    void set_name_length(int name_length);

    char* get_name_student() const;
    void set_name_student(const char* name_student);

    char* get_name_examiner() const;
    void set_name_examiner(const char* name_examiner);

    char* get_name_subject() const;
    void set_name_subject(const char* name_subject);

    long long get_date() const;
    void set_date(long long date);

    void set_grade(int grade);
};

