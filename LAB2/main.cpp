#include "main.h"
#include <iostream> // для cin и cout
#include <Windows.h> // Обязательно для SetConsoleCP() и SetConsoleOutputCP()
#include <stdlib.h> // для std
#include <string.h>
int main()
{
	SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
	SetConsoleOutputCP(1251); // Вывод на консоль в кодировке 1251.


	char test[] = "Тимошенко ЕМ";
	char test2[] = "Косова АЕ";
	char test3[] = "ООП";
	time_t t = time(nullptr);
	int dt = t;
	int gd = 5;
	Exam ex(test, test2, test3, dt, gd);
	Exam exam;
	ex.Print();

	//&test - адрес
	//*test - значение указателя
	//test - значение по адресу
	//test++ увеличивает адрес в указателе
}
