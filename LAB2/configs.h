// ReSharper disable CommentTypo
#pragma once
#include <cstdint>

class configs  // NOLINT(cppcoreguidelines-special-member-functions)
{
public:
	~configs();
	// Количество групп в GroupUniver
	int count_group = 3;
	// Длина строк в Exam
	int name_length = 100;
	// Размер группы в Unversity
	int size_group = 5;
	// Минимальная оценка в Exam
	int min_grade = 2;
	// Максимальная оценка в Exam
	int max_grade = 5;
	// Минимальаня дата в Exam
	int min_date = 0;
	// Максимальная дата в Exam
	int max_date = INT32_MAX;

	// Дина строк вывода
	int string_length = 100;
	// Пустая строка
	// char* globalNullString = "Не указано";
	char* global_null_string = default_global_null_string();
	char* global_name_student = default_global_null_string();
	char* global_name_examiner = default_global_null_string();
	char* global_name_subject = default_global_null_string();


	char* global_print_name_student = default_global_print_name_student();
	char* global_print_name_examiner = default_global_print_name_examiner();
	char* global_print_name_subject = default_global_print_name_subject();
	char* global_print_date = default_global_print_date();
	char* global_print_grade = default_global_print_grade();

	char* global_input_name_student = default_global_input_name_student();
	char* global_input_name_examiner = default_global_input_name_examiner();
	char* global_input_name_subject = default_global_input_name_subject();
	char* global_input_date = default_global_input_date();
	char* global_input_grade = default_global_input_grade();
	char* global_input_error = default_global_input_error();

	static char* default_global_null_string();
	static char* default_global_print_name_student();
	static char* default_global_print_name_examiner();
	static char* default_global_print_name_subject();
	static char* default_global_print_date();
	static char* default_global_print_grade();
	static char* default_global_input_name_student();
	static char* default_global_input_name_examiner();
	static char* default_global_input_name_subject();
	static char* default_global_input_date();
	static char* default_global_input_grade();
	static char* default_global_input_error();

	int get_size_group();
	void set_size_group(int m_size_group);
	// Перегрузка оператора присваивания
	configs operator=(configs i);  // NOLINT(misc-unconventional-assign-operator)

	int get_name_length();
	void set_name_length(int m_name_length);

	int get_count_group();
	void set_count_group(int m_count_group);

	int get_min_grade();
	void set_min_grade(int m_min_grade);

	int get_max_grade();
	void set_max_grade(int m_max_grade);

	int get_min_date();
	void set_min_date(int m_min_date);

	int get_max_date();
	void set_max_date(int m_max_date);

	int get_string_length();
	void set_string_length(int m_string_length);
};


