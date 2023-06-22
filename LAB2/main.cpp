#include "exam.h"
#include <iostream> // cin � cout
#include <Windows.h> // ����������� ��� SetConsoleCP() � SetConsoleOutputCP()
#include "group.h"
using namespace std;


int main()
{
	SetConsoleCP(1251); // ���� � ������� � ��������� 1251
	SetConsoleOutputCP(1251); // ����� �� ������� � ��������� 1251.


	char namesStud[5][100] = { "�������� ������� ����������", "������� ����������� ���������", "������� ���� ����������",
		"���������� ������� �����������", "������ ������ ��������" };
	char namesExam[5][100] = { "����� ������� ����������", "������� ������� ���������", "������ ����� ������������",
		"�������� ������ ���������", "�������� ������ �����������" };
	char namesSub[5][100] = { "���", "�������������� ������", "������ �����������",
		"���������", "�������������� ������������" };

	Group group(5);
	srand(time(NULL));
	for (int i = 0; i < group.Size(); i++)
	{
		Exam exam(namesStud[i], namesExam[i], namesSub[i], time(nullptr),2 + rand() % (5 - 2 + 1));
		group.PutExam(i, exam);
	}

	group.Print();
}