#include "exam.h"
#include <iostream> // cin и cout
#include <Windows.h> // Обязательно для SetConsoleCP() и SetConsoleOutputCP()
#include "group.h"
using namespace std;


int main()
{
	SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
	SetConsoleOutputCP(1251); // Вывод на консоль в кодировке 1251.


	char namesStud[5][100] = { "Горбунов Парамон Платонович", "Морозов Максимилиан Федорович", "Тарасов Эрик Лукьянович",
		"Калашников Дмитрий Рудольфович", "Рожков Адольф Егорович" };
	char namesExam[5][100] = { "Жуков Емельян Дмитрьевич", "Сазонов Леонард Никитевич", "Жданов Архип Владимирович",
		"Зиновьев Эльдар Филатович", "Кудряшов Лазарь Геннадиевич" };
	char namesSub[5][100] = { "ООП", "Математический анализ", "Теория вероятности",
		"Философия", "Информационная безопасность" };

	Group group(5); // Конструктор объекта класса Group
	srand(time(NULL));
	for (int i = 0; i < group.Size(); i++)
	{
		Exam exam(namesStud[i], namesExam[i], namesSub[i], time(nullptr), 2 + rand() % (5 - 2 + 1));
		group.PutExam(i, exam); // Функция заполнения массива 
	}

	group.Print(); // Вывод на консоль объекта класса Group

	group(5);

	group.Print(); // Вывод на консоль объекта класса Group

	double grade = group.GetExam(3); // Неявное преобразование в double. Отдает оценку

	cout << "Неявное преобразование типа Exam в double 4-ого объекта: " << grade << endl;

	cout << "Средняя оценка в группе: " << group.Grade() << endl;

	cout << "Средняя оценка среди тех, у кого оценка не ниже 3: " << group.Grade(3) << endl;

	cout << "\nПерегрузка оператора индексирования (5-ый объект): " << endl;
	group[4].Print();

	cout << "\nПерегрузка оператора сложения: (1 и 2 объект): " << endl;
	double sum = group[0] + group[1];
	cout << sum << endl;
}