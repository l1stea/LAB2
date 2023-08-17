// ReSharper disable CommentTypo
#include "Actions.h"
#include <Windows.h>
#include "checkInput.h"
#include "group.h"
#include "group_university.h"
#include <iostream>
using namespace std;


constexpr char names_stud[5][100] = { "Горбунов Парамон Платонович", "Морозов Максимилиан Федорович", "Тарасов Эрик Лукьянович",
	"Калашников Дмитрий Рудольфович", "Рожков Адольф Егорович" };
constexpr char names_exam[5][100] = { "Жуков Емельян Дмитрьевич", "Сазонов Леонард Никитевич", "Жданов Архип Владимирович",
	"Зиновьев Эльдар Филатович", "Кудряшов Лазарь Геннадиевич" };
constexpr char names_sub[5][100] = { "ООП", "Математический анализ", "Теория вероятности",
	"Философия", "Информационная безопасность" };


void actions::test_input_group()
{
	const HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY);

	const group var_group(check_input::get_size_array());
	for (int i = 0; i < var_group.get_size(); i++)
	{
		exam exam;
		// Ввод с проверкой
		exam.input();
		cout << "\nПроверка метода ввода PutExam с неправильным индексом:" << endl;
		// Функция заполнения массива 
		var_group.put_exam(i + 5, exam);
		cout << "\nПроверка оператора индексирования:" << endl;
		// Проверка некорректного индекса
		var_group[-1];
	}
}


void actions::run_tasks()
{


	const HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_GREEN);

	constexpr int index = 5;
	const group group_object(index); // Конструктор объекта класса Group
	srand(time(nullptr));  // NOLINT(cert-msc51-cpp)
	for (int i = 0; i < group_object.get_size(); i++)
	{
		exam ex(names_stud[i], names_exam[i], names_sub[i], time(nullptr), 2 + rand() % (5 - 2 + 1));
		// NOLINT(bugprone-narrowing-conversions, cppcoreguidelines-narrowing-conversions)
		group_object.put_exam(i, ex); // Функция заполнения массива 
	}

	group_object.print(); // Вывод на консоль объекта класса Group


	cout << "Средняя оценка в группе: " << group_object.get_grade() << endl;
	cout << "Средняя оценка среди тех, у кого оценка не ниже 3: " << group_object.get_grade(3) << endl;
	cout << endl;


	const double grade = group_object.get_exam(3); // Неявное преобразование в double. Отдает оценку
	cout << "Неявное преобразование типа Exam в double 4-ого объекта: " << grade << endl;
	cout << endl;


	cout << "\nПерегрузка оператора индексирования (5-ый объект): " << endl;
	group_object[4].print();


	cout << "\nПерегрузка оператора сложения: (1 и 2 объект): " << endl;
	const double sum = group_object[0] + group_object[1];
	cout << sum << endl;
	cout << "----------------------------------------------------------------------------------------------------";
	cout << endl;
}


void actions::test_group_university()
{
	const HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_BLUE);

	// Cоздание группы 1
	group_university group1(1); // Конструктор объекта класса GroupUniver  // NOLINT(cert-msc51-cpp)
	group1.set_id(1);
	srand(time(nullptr));  // NOLINT(cert-msc51-cpp)
	for (int i = 0; i < group1.get_size(); i++)
	{

		exam exam(names_stud[i], names_exam[i], names_sub[i], time(nullptr), 2 + rand() % (5 - 2 + 1));
		// NOLINT(bugprone-narrowing-conversions, concurrency-mt-unsafe, cppcoreguidelines-narrowing-conversions)
		group1.put_exam(i, exam); // Функция заполнения массива 
	}

	// Создание группы 2
	cout << endl;
	group_university group2(1); // Конструктор объекта класса GroupUniver
	group2.set_id(2);
	srand(time(nullptr));
	for (int i = 0; i < group2.get_size(); i++)
	{
		exam ex(names_stud[rand() % 5], names_exam[rand() % 5], names_sub[rand() % 5], time(nullptr),
		        2 + rand() % (5 - 2 + 1));
		// NOLINT(concurrency-mt-unsafe, concurrency-mt-unsafe, concurrency-mt-unsafe, bugprone-narrowing-conversions)
		group2.put_exam(i, ex); // Функция заполнения массива 
	}

	cout << "----------------------------------------------------------------------------------------------------";
	cout << endl;
}

void actions::test_constructors_exam()
{
	const HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_GREEN);


	// Конструктор по умолчанию
	cout << "Конструктор Exam по умолчанию:\n";
	const exam ex1;
	ex1.print();


	// Конструктор с параметрами
	// NOLINT(concurrency-mt-unsafe, concurrency-mt-unsafe, concurrency-mt-unsafe, bugprone-narrowing-conversions)
	cout << "Конструктор Exam c параметрами:\n";
	const exam ex2 (
		names_stud[rand() % 5],
		names_exam[rand() % 5],
		names_sub[rand() % 5],
		time(nullptr),
		2 + rand() % (5 - 2 + 1));  
	ex2.print();

	// Конструктор со списком
	cout << "Конструктор Exam cо списком инициализации:\n";
	const exam ex3("Тимошенко ЕМ");
	ex3.print();
}
