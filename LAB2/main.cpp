#include <Windows.h> // Для SetConsoleCP() и SetConsoleOutputCP()
#include "actions.h"

void main()
{
	SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
	SetConsoleOutputCP(1251); // Вывод на консоль в кодировке 1251.

	// Выполненные задачи согласно методическому пособию ЛР2
	actions::run_tasks();

	// Тест группы с айди
	actions::test_group_university();

	// Проверка ввода
	actions::test_input_group();

	// Тест конструкторов
	actions::test_constructors_exam();

	// Пауза в консоли для просмотра результата
	system("pause");  // NOLINT(concurrency-mt-unsafe)
}