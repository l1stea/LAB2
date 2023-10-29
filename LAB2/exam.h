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
    // int date; ������ ������ ��� ������������� time_t
    long long date_;
    int grade_;
    int get_name_length();
public:
    // ����������� � �����������
    exam(char* name_student,  // NOLINT(readability-inconsistent-declaration-parameter-name)
         char* name_examiner,
         char* name_subject,
         int date,
         int grade = 2); // �������� �� ���������
    exam(exam& ex);
    explicit exam(char* name_student); // ����������� �� ������� �������������
    // ����������� ��� ����������
    exam();
    // ����������
    ~exam();
    // ����� ������
    void print();
    bool saveNameStudent();
    bool saveNameExaminer();
    bool saveNameSubject();
    bool saveDate();
    bool check_date(int day, int month, int year);
    bool saveGrade();
    // ����� ������
    void input();
    // ����� ������ ����
    void print_date();
    // ���������� � double
    // ReSharper disable once CppNonExplicitConversionOperator
    operator double();
    // ����� ���������� ��������� grade
    int get_grade();
    // ���������� �������� +
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

