// ReSharper disable CommentTypo
#include "group_university.h"
#include <iostream>

using namespace std;

group_university::group_university()
{
	cout << "GroupUniver ����������� �� ��������� ������, ������ �� ����������" << endl;
}

group_university::group_university(const int size_array) : group(size_array)
{
	cout << "GroupUniver ����������� ������, ������ �� ����������" << endl;
	//while (sizeArray < 1)
	//{
	//	cout << "������ ������ ������ ������ 1, ������� �����" << endl;
	//	cin >> sizeArray;
	//}
	//SetSize(sizeArray);
	//NewExam();
}

group_university::~group_university()
{
	cout << "GroupUniver ���������� ������, ������ �� ���������" << endl;
}

int group_university::get_id() const
{
	return id_;
}

void group_university::set_id(const int id)
{
	this->id_ = id;
}
