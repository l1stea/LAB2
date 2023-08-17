// ReSharper disable CppDeprecatedEntity
#include <cstring>
#include "configs.h"
#pragma warning(disable : 4996)
using namespace std;


int configs::get_size_group() const
{
    return this->size_group;
}

void configs::set_size_group(const int m_size_group)
{
    this->size_group = m_size_group;
}

configs configs::operator=(configs i) const  // NOLINT(misc-unconventional-assign-operator)
{
    return i;
}

int configs::get_name_length() const
{
    return this->name_length;
}

void configs::set_name_length(const int m_name_length)
{
    this->name_length = m_name_length;
}

int configs::get_count_group() const
{
    return this->count_group;
}

void configs::set_count_group(const int m_count_group)
{
    this->count_group = m_count_group;
}

int configs::get_min_grade() const
{
    return this->min_grade;
}

void configs::set_min_grade(const int m_min_grade)
{
    this->min_grade = m_min_grade;
}

int configs::get_max_grade() const
{
    return this->max_grade;
}

void configs::set_max_grade(const int m_max_grade)
{
    this->max_grade = m_max_grade;
}

int configs::get_min_date() const
{
    return this->min_date;
}

void configs::set_min_date(const int m_min_date)
{
    this->min_date = m_min_date;
}

int configs::get_max_date() const
{
    return this->max_date;
}

void configs::set_max_date(const int m_max_date)
{
    this->max_date = m_max_date;
}

int configs::get_string_length() const
{
    return this->string_length;
}

void configs::set_string_length(const int m_string_length)
{
    this->string_length = m_string_length;
}

char* configs::default_global_null_string()
{
	const auto var_return = new char[100];
    strcpy(var_return, "Не указано");
    return var_return;
}

char* configs::default_global_print_name_student()
{
	const auto var_return = new char[100];
    strcpy(var_return, "ФИО студента: ");
    return var_return;
}

char* configs::default_global_print_name_examiner()
{
	const auto var_return = new char[100];
    strcpy(var_return, "ФИО экзаменатора: ");
    return var_return;
}

char* configs::default_global_print_name_subject()
{
	const auto var_return = new char[100];
    strcpy(var_return, "Предмет: ");
    return var_return;
}

char* configs::default_global_print_date()
{
	const auto var_return = new char[100];
    strcpy(var_return, "Дата: ");
    return var_return;
}

char* configs::default_global_print_grade()
{
	const auto var_return = new char[100];
    strcpy(var_return, "Оценка: ");
    return var_return;
}

char* configs::default_global_input_name_student()
{
	const auto var_return = new char[100];
    strcpy(var_return, "Введите ФИО студента: ");
    return var_return;
}

char* configs::default_global_input_name_examiner()
{
	const auto var_return = new char[100];
    strcpy(var_return, "Введите ФИО преподователя: ");
    return var_return;
}

char* configs::default_global_input_name_subject()
{
	const auto var_return = new char[100];
    strcpy(var_return, "Введите предмет: ");
    return var_return;
}

char* configs::default_global_input_date()
{
	const auto var_return = new char[100];
    strcpy(var_return, "Введите дату: ");
    return var_return;
}

char* configs::default_global_input_grade()
{
	const auto var_return = new char[100];
    strcpy(var_return, "Введите оценку: ");
    return var_return;
}

char* configs::default_global_input_error()
{
	const auto var_return = new char[100];
    strcpy(var_return, "Ошибка ввода: ");
    return var_return;
}


