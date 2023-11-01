#include <Windows.h> // ��� SetConsoleCP() � SetConsoleOutputCP()
#include "actions.h"

void main()
{
	SetConsoleCP(1251); // ���� � ������� � ��������� 1251
	SetConsoleOutputCP(1251); // ����� �� ������� � ��������� 1251.

	// ����������� ������ �������� ������������� ������� ��2
	actions::run_tasks();

	// ���� ������ � ����
	actions::test_group_university();

	// �������� �����
	actions::test_input_group();

	// ���� �������������
	actions::test_constructors_exam();

	// ����� � ������� ��� ��������� ����������
	system("pause");  // NOLINT(concurrency-mt-unsafe)
}