#include "main.h"
#include <iostream> // ��� cin � cout
#include <Windows.h> // ����������� ��� SetConsoleCP() � SetConsoleOutputCP()
#include <stdlib.h> // ��� std
#include <string.h>
int main()
{
	SetConsoleCP(1251); // ���� � ������� � ��������� 1251
	SetConsoleOutputCP(1251); // ����� �� ������� � ��������� 1251.


	char test[] = "��������� ��";
	char test2[] = "������ ��";
	char test3[] = "���";
	time_t t = time(nullptr);
	int dt = t;
	int gd = 5;
	Exam ex(test, test2, test3, dt, gd);
	Exam exam;
	ex.Print();

	//&test - �����
	//*test - �������� ���������
	//test - �������� �� ������
	//test++ ����������� ����� � ���������
}
