#include "exam.h"
#include <iostream> // cin � cout
#include <Windows.h> // ����������� ��� SetConsoleCP() � SetConsoleOutputCP()
#include "group.h"
#include "university.h"
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

	GroupUniver group(5); // ����������� ������� ������ Group
	srand(time(NULL));
	for (int i = 0; i < group.Size(); i++)
	{
		Exam exam(namesStud[i], namesExam[i], namesSub[i], time(nullptr), 2 + rand() % (5 - 2 + 1));
		group.PutExam(i, exam); // ������� ���������� ������� 
	}

	group.Print(); // ����� �� ������� ������� ������ Group


	double grade = group.GetExam(3); // ������� �������������� � double. ������ ������

	cout << "������� �������������� ���� Exam � double 4-��� �������: " << grade << endl;

	cout << "������� ������ � ������: " << group.Grade() << endl;

	cout << "������� ������ ����� ���, � ���� ������ �� ���� 3: " << group.Grade(3) << endl;

	cout << "\n���������� ��������� �������������� (5-�� ������): " << endl;
	group[4].Print();

	cout << "\n���������� ��������� ��������: (1 � 2 ������): " << endl;
	double sum = group[0] + group[1];
	cout << sum << endl;
	// �������� ������ 2
	GroupUniver group2(5); // ����������� ������� ������ GroupUniver
	srand(time(NULL));
	for (int i = 0; i < group2.Size(); i++)
	{
		Exam exam(namesStud[rand()%5], namesExam[rand()%5], namesSub[rand()%5], time(nullptr), 2 + rand() % (5 - 2 + 1));
		group2.PutExam(i, exam); // ������� ���������� ������� 
	}
	// �������������� ����� University
	University university;
	university.PutGroup(group);
	university.PutGroup(group2);
	university.Print();
}