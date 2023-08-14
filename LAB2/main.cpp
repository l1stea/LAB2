#include "exam.h"
#include <iostream> // cin � cout
#include <Windows.h> // ����������� ��� SetConsoleCP() � SetConsoleOutputCP()
#include "group.h"
#include "groupUniver.h"
#include "checkInput.h"
using namespace std;


void main()
{
	SetConsoleCP(1251); // ���� � ������� � ��������� 1251
	SetConsoleOutputCP(1251); // ����� �� ������� � ��������� 1251.


	char namesStud[5][100] = { "�������� ������� ����������", "������� ����������� ���������", "������� ���� ����������",
		"���������� ������� �����������", "������ ������ ��������" };
	char namesExam[5][100] = { "����� ������� ����������", "������� ������� ���������", "������ ����� ������������",
		"�������� ������ ���������", "�������� ������ �����������" };
	char namesSub[5][100] = { "���", "�������������� ������", "������ �����������",
		"���������", "�������������� ������������" };

	int index = CheckInput::GetIndex(5);
	Group groupobject(index); // ����������� ������� ������ Group
	srand(time(NULL));
	for (int i = 0; i < groupobject.GetSize(); i++)
	{
		Exam exam(namesStud[i], namesExam[i], namesSub[i], time(nullptr), 2 + rand() % (5 - 2 + 1));
		groupobject.PutExam(i, exam); // ������� ���������� ������� 
	}
	groupobject.Print(); // ����� �� ������� ������� ������ Group

	cout << "������� ������ � ������: " << groupobject.GetGrade() << endl;
	cout << "������� ������ ����� ���, � ���� ������ �� ���� 3: " << groupobject.GetGrade(3) << endl;
	cout << endl;

	double grade = groupobject.GetExam(3); // ������� �������������� � double. ������ ������
	cout << "������� �������������� ���� Exam � double 4-��� �������: " << grade << endl;
	cout << endl;

	cout << "\n���������� ��������� �������������� (5-�� ������): " << endl;
	groupobject[4].Print();

	cout << "\n���������� ��������� ��������: (1 � 2 ������): " << endl;
	double sum = groupobject[0] + groupobject[1];
	cout << sum << endl;
	cout << "----------------------------------------------------------------------------------------------------";
	cout << endl;

	// C������� ������ 1
	GroupUniver group(1); // ����������� ������� ������ GroupUniver
	srand(time(NULL));
	for (int i = 0; i < group.GetSize(); i++)
	{
		Exam exam(namesStud[i], namesExam[i], namesSub[i], time(nullptr), 2 + rand() % (5 - 2 + 1));
		group.PutExam(i, exam); // ������� ���������� ������� 
	}

	// �������� ������ 2
	cout << endl;
	GroupUniver group2(1); // ����������� ������� ������ GroupUniver
	srand(time(NULL));
	for (int i = 0; i < group2.GetSize(); i++)
	{
		Exam exam(namesStud[rand() % 5], namesExam[rand() % 5], namesSub[rand() % 5], time(nullptr), 2 + rand() % (5 - 2 + 1));
		group2.PutExam(i, exam); // ������� ���������� ������� 
	}

	cout << "----------------------------------------------------------------------------------------------------";
	cout << endl;
	// �������� �����
	cout << "\n������� ���������� ��������� ������:";
	int count;
	cin >> count;
	Group group3(CheckInput::GetIndex(count));
	for (int i = 0; i < group3.GetSize(); i++)
	{
		Exam exam;
		exam.Input(); // ���� � ���������
		cout << "\n�������� ������ ����� PutExam � ������������ ��������:" << endl;
		group3.PutExam(i+5, exam); // ������� ���������� ������� 
		cout << "\n�������� ��������� ��������������:" << endl;
		group3[2]; // �������� ������������� �������
	}

	// ����� ������������ � ������������ �����������
	cout << endl;
	cout << "����������� � ������������ �����������" << endl;
	Group testDinGroup(CheckInput::GetIndex(2)); // ����������� ������� ������ GroupUniver
	srand(time(NULL));
	for (int i = 0; i < testDinGroup.GetSize(); i++)
	{
		Exam exam(namesStud[rand() % 5], namesExam[rand() % 5], namesSub[rand() % 5], time(nullptr), 2 + rand() % (5 - 2 + 1));
		testDinGroup.PutExam(i, exam); // ������� ���������� ������� 
	}
	testDinGroup.Print();


	// ����� ������������ ������, �������� ���������� ����������� ��������� ������ = 2
	cout << endl;
	cout << "����������� �� ����������� �����������:" << endl;
	Group testStatGroup; // ����������� ������� ������ GroupUniver
	testStatGroup.Print();


	// ����� � ������� ��� ��������� ����������
	system("pause");
}
