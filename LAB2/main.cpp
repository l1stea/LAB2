#include "exam.h"
#include <iostream> // cin и cout
#include <Windows.h> // Обязательно для SetConsoleCP() и SetConsoleOutputCP()
#include "group.h"
#include "groupUniver.h"
#include "checkInput.h"
using namespace std;


void main()
{
	SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
	SetConsoleOutputCP(1251); // Вывод на консоль в кодировке 1251.


	char namesStud[5][100] = { "Горбунов Парамон Платонович", "Морозов Максимилиан Федорович", "Тарасов Эрик Лукьянович",
		"Калашников Дмитрий Рудольфович", "Рожков Адольф Егорович" };
	char namesExam[5][100] = { "Жуков Емельян Дмитрьевич", "Сазонов Леонард Никитевич", "Жданов Архип Владимирович",
		"Зиновьев Эльдар Филатович", "Кудряшов Лазарь Геннадиевич" };
	char namesSub[5][100] = { "ООП", "Математический анализ", "Теория вероятности",
		"Философия", "Информационная безопасность" };

	int index = CheckInput::GetIndex(5);
	Group groupobject(index); // Конструктор объекта класса Group
	srand(time(NULL));
	for (int i = 0; i < groupobject.GetSize(); i++)
	{
		Exam exam(namesStud[i], namesExam[i], namesSub[i], time(nullptr), 2 + rand() % (5 - 2 + 1));
		groupobject.PutExam(i, exam); // Функция заполнения массива 
	}
	groupobject.Print(); // Вывод на консоль объекта класса Group

	cout << "Средняя оценка в группе: " << groupobject.GetGrade() << endl;
	cout << "Средняя оценка среди тех, у кого оценка не ниже 3: " << groupobject.GetGrade(3) << endl;
	cout << endl;

	double grade = groupobject.GetExam(3); // Неявное преобразование в double. Отдает оценку
	cout << "Неявное преобразование типа Exam в double 4-ого объекта: " << grade << endl;
	cout << endl;

	cout << "\nПерегрузка оператора индексирования (5-ый объект): " << endl;
	groupobject[4].Print();

	cout << "\nПерегрузка оператора сложения: (1 и 2 объект): " << endl;
	double sum = groupobject[0] + groupobject[1];
	cout << sum << endl;
	cout << "----------------------------------------------------------------------------------------------------";
	cout << endl;

	// Cоздание группы 1
	GroupUniver group(1); // Конструктор объекта класса GroupUniver
	srand(time(NULL));
	for (int i = 0; i < group.GetSize(); i++)
	{
		Exam exam(namesStud[i], namesExam[i], namesSub[i], time(nullptr), 2 + rand() % (5 - 2 + 1));
		group.PutExam(i, exam); // Функция заполнения массива 
	}

	// Создание группы 2
	cout << endl;
	GroupUniver group2(1); // Конструктор объекта класса GroupUniver
	srand(time(NULL));
	for (int i = 0; i < group2.GetSize(); i++)
	{
		Exam exam(namesStud[rand() % 5], namesExam[rand() % 5], namesSub[rand() % 5], time(nullptr), 2 + rand() % (5 - 2 + 1));
		group2.PutExam(i, exam); // Функция заполнения массива 
	}

	cout << "----------------------------------------------------------------------------------------------------";
	cout << endl;
	// Проверка ввода
	cout << "\nВведите количество студентов группы:";
	int count;
	cin >> count;
	Group group3(CheckInput::GetIndex(count));
	for (int i = 0; i < group3.GetSize(); i++)
	{
		Exam exam;
		exam.Input(); // Ввод с проверкой
		cout << "\nПроверка метода ввода PutExam с неправильным индексом:" << endl;
		group3.PutExam(i+5, exam); // Функция заполнения массива 
		cout << "\nПроверка оператора индексирования:" << endl;
		group3[2]; // Проверка некорректного индекса
	}

	// Вызов конструктора с динамическим заполнением
	cout << endl;
	cout << "Конструктор с динамическим заполнением" << endl;
	Group testDinGroup(CheckInput::GetIndex(2)); // Конструктор объекта класса GroupUniver
	srand(time(NULL));
	for (int i = 0; i < testDinGroup.GetSize(); i++)
	{
		Exam exam(namesStud[rand() % 5], namesExam[rand() % 5], namesSub[rand() % 5], time(nullptr), 2 + rand() % (5 - 2 + 1));
		testDinGroup.PutExam(i, exam); // Функция заполнения массива 
	}
	testDinGroup.Print();


	// Вызов конструктора внутри, которого вызывается статическое выделение памяти = 2
	cout << endl;
	cout << "Конструктор со статическим заполнением:" << endl;
	Group testStatGroup; // Конструктор объекта класса GroupUniver
	testStatGroup.Print();


	// Пауза в консоли для просмотра результата
	system("pause");
}
