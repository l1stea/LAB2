#include "Actions.h"
#include <Windows.h>
#include "group.h"
#include "group_university.h"
#include <iostream>
using namespace std;


char names_stud[5][100] = { "�������� ������� ����������", "������� ����������� ���������", "������� ���� ����������",
	"���������� ������� �����������", "������ ������ ��������" };
char names_exam[5][100] = { "����� ������� ����������", "������� ������� ���������", "������ ����� ������������",
	"�������� ������ ���������", "�������� ������ �����������" };
char names_sub[5][100] = { "���", "�������������� ������", "������ �����������",
	"���������", "�������������� ������������" };


bool check_size_array(int size_array)
{
	if (size_array < 1)
		return false;
	return true;
}


int get_size_array()
{
	cout << "\n������� ���������� ��������� ������:";
	int size_array;
	cin >> size_array;
	while (!check_size_array(size_array))
	{
		if (size_array < 1 && !cin.fail()) cout << "������ ������ ������ ���� ������ 0!\n";
		if (cin.fail()) {
			cout << "�� ����� �� ����� ��� ������� ������� �����!\n";
			cin.clear();
			cin.ignore((numeric_limits<streamsize>::max)(), '\n');
		}
		cout << "\n������� ���������� ��������� ������:";
		cin >> size_array;
	}
	return size_array;
}


void actions::test_input_group()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY);

	group var_group(get_size_array());
	for (int i = 0; i < var_group.get_size(); i++)
	{
		exam exam;
		// ���� � ���������
		exam.input();
		cout << "\n�������� ������ ����� PutExam � ������������ ��������:" << endl;
		// ������� ���������� ������� 
		var_group.put_exam(i + 5, exam);
		cout << "\n�������� ��������� ��������������:" << endl;
		// �������� ������������� �������
		var_group[-1];
	}
}


void actions::run_tasks()
{


	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_GREEN);

	int index = 5;
	group group_object(index); // ����������� ������� ������ Group
	srand(time(nullptr));  // NOLINT(cert-msc51-cpp)
	for (int i = 0; i < group_object.get_size(); i++)
	{
		exam ex(names_stud[i], names_exam[i], names_sub[i], time(nullptr), 2 + rand() % (5 - 2 + 1));
		// NOLINT(bugprone-narrowing-conversions, cppcoreguidelines-narrowing-conversions)
		group_object.put_exam(i, ex); // ������� ���������� ������� 
	}

	group_object.print(); // ����� �� ������� ������� ������ Group


	cout << "������� ������ � ������: " << group_object.get_grade() << endl;
	cout << "������� ������ ����� ���, � ���� ������ �� ���� 3: " << group_object.get_grade(3) << endl;
	cout << endl;


	double grade = group_object.get_exam(3); // ������� �������������� � double. ������ ������
	cout << "������� �������������� ���� Exam � double 4-��� �������: " << grade << endl;
	cout << endl;


	cout << "\n���������� ��������� �������������� (5-�� ������): " << endl;
	group_object[4].print();


	cout << "\n���������� ��������� ��������: (1 � 2 ������): " << endl;
	double sum = group_object[0] + group_object[1];
	cout << sum << endl;
	cout << "----------------------------------------------------------------------------------------------------";
	cout << endl;
}


void actions::test_group_university()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_BLUE);

	// C������� ������ 1
	group_university group1(1); // ����������� ������� ������ GroupUniver  // NOLINT(cert-msc51-cpp)
	group1.set_id(1);
	srand(time(nullptr));  // NOLINT(cert-msc51-cpp)
	for (int i = 0; i < group1.get_size(); i++)
	{

		exam ex_test(names_stud[i], names_exam[i], names_sub[i], time(nullptr), 2 + rand() % (5 - 2 + 1));
		// NOLINT(bugprone-narrowing-conversions, concurrency-mt-unsafe, cppcoreguidelines-narrowing-conversions)
		group1.put_exam(i, ex_test); // ������� ���������� ������� 
	}

	// �������� ������ 2
	cout << endl;
	group_university group2(1); // ����������� ������� ������ GroupUniver
	group2.set_id(2);
	srand(time(nullptr));
	for (int i = 0; i < group2.get_size(); i++)
	{
		exam ex(names_stud[rand() % 5], names_exam[rand() % 5], names_sub[rand() % 5], time(nullptr),
		        2 + rand() % (5 - 2 + 1));
		// NOLINT(concurrency-mt-unsafe, concurrency-mt-unsafe, concurrency-mt-unsafe, bugprone-narrowing-conversions)
		group2.put_exam(i, ex); // ������� ���������� ������� 
	}

	cout << "----------------------------------------------------------------------------------------------------";
	cout << endl;
}

void actions::test_constructors_exam()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_GREEN);


	// C��������� �� ���������
	cout << "����������� Exam �� ���������:\n";
	exam ex1;
	ex1.print();


	// ���������� � �����������
	cout << "����������� Exam c �����������:\n";
	exam ex2 (
		names_stud[rand() % 5],
		names_exam[rand() % 5],
		names_sub[rand() % 5],
		time(nullptr),
		2 + rand() % (5 - 2 + 1));  
	ex2.print();

	// ������������ �� ���������
	cout << "����������� Exam �� ��������� � ������������ ���������� ������:\n";
	exam *ex3 = new exam();
	ex3->print();

	delete ex3;

	// ����������� � �����������
	cout << "����������� Exam � ����������� � ������������ ���������� ������:\n";
	exam *ex4 = new exam(
		names_stud[rand() % 5],
		names_exam[rand() % 5],
		names_sub[rand() % 5],
		time(nullptr),
		2 + rand() % (5 - 2 + 1));
	ex4->print();

	delete ex4;

	exam *ex5 = new exam[2];
	delete[] ex5;
}
