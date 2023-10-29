// ReSharper disable CppDeprecatedEntity
#include <cstring>
#include "configs.h"
#pragma warning(disable : 4996)
using namespace std;


int configs::get_size_group()
{
    return this->size_group;
}

void configs::set_size_group(int m_size_group)
{
    this->size_group = m_size_group;
}

configs configs::operator=(configs i)  // NOLINT(misc-unconventional-assign-operator)
{
    return i;
}

int configs::get_name_length()
{
    return this->name_length;
}

void configs::set_name_length(int m_name_length)
{
    this->name_length = m_name_length;
}

int configs::get_count_group()
{
    return this->count_group;
}

void configs::set_count_group(int m_count_group)
{
    this->count_group = m_count_group;
}

int configs::get_min_grade()
{
    return this->min_grade;
}

void configs::set_min_grade(int m_min_grade)
{
    this->min_grade = m_min_grade;
}

int configs::get_max_grade()
{
    return this->max_grade;
}

void configs::set_max_grade(int m_max_grade)
{
    this->max_grade = m_max_grade;
}

int configs::get_min_date()
{
    return this->min_date;
}

void configs::set_min_date(int m_min_date)
{
    this->min_date = m_min_date;
}

int configs::get_max_date()
{
    return this->max_date;
}

void configs::set_max_date(int m_max_date)
{
    this->max_date = m_max_date;
}

int configs::get_string_length()
{
    return this->string_length;
}

void configs::set_string_length(int m_string_length)
{
    this->string_length = m_string_length;
}

char* configs::default_global_null_string()
{
	auto var_return = new char[100];
    strcpy(var_return, "Не указано");
    return var_return;
}

char* configs::default_global_print_name_student()
{
	auto var_return = new char[100];
    strcpy(var_return, "ФИО студента: ");
    return var_return;
}

char* configs::default_global_print_name_examiner()
{
	auto var_return = new char[100];
    strcpy(var_return, "ФИО экзаменатора: ");
    return var_return;
}

char* configs::default_global_print_name_subject()
{
	auto var_return = new char[100];
    strcpy(var_return, "Предмет: ");
    return var_return;
}

char* configs::default_global_print_date()
{
	auto var_return = new char[100];
    strcpy(var_return, "Дата: ");
    return var_return;
}

char* configs::default_global_print_grade()
{
	auto var_return = new char[100];
    strcpy(var_return, "Оценка: ");
    return var_return;
}

char* configs::default_global_input_name_student()
{
	auto var_return = new char[100];
    strcpy(var_return, "Введите ФИО студента: ");
    return var_return;
}

char* configs::default_global_input_name_examiner()
{
	auto var_return = new char[100];
    strcpy(var_return, "Введите ФИО преподователя: ");
    return var_return;
}

char* configs::default_global_input_name_subject()
{
	auto var_return = new char[100];
    strcpy(var_return, "Введите предмет: ");
    return var_return;
}

char* configs::default_global_input_date()
{
	auto var_return = new char[100];
    strcpy(var_return, "Введите дату: ");
    return var_return;
}

char* configs::default_global_input_grade()
{
	auto var_return = new char[100];
    strcpy(var_return, "Введите оценку: ");
    return var_return;
}

char* configs::default_global_input_error()
{
	auto var_return = new char[100];
    strcpy(var_return, "Ошибка ввода: ");
    return var_return;
}


