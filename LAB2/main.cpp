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

	Group group(5);
	srand(time(NULL));
	for (int i = 0; i < group.Size(); i++)
	{
		Exam exam(namesStud[i], namesExam[i], namesSub[i], time(nullptr),2 + rand() % (5 - 2 + 1));
		group.PutExam(i, exam);
	}

	group.Print();
}